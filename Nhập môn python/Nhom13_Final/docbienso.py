#%%
import cv2
import numpy as np
from local_utils import detect_lp
from os.path import splitext, basename
from keras.models import model_from_json
from sklearn import preprocessing, model_selection
import tensorflow as tf
from tensorflow import keras
import os
from keras.preprocessing import image
import keras.applications.vgg16
#Load model đã train sẵn, model sử dụng là Keras, đây là thư viện hỗ trợ giao diện cho Tensorflow
#Keras là một open source cho Neural Network được viết bởi ngôn ngữ Python
def load_model(path):
    try:
        path = splitext(path)[0]
        with open('%s.json' % path, 'r') as json_file:
            model_json = json_file.read()
        model = model_from_json(model_json, custom_objects={})
        model.load_weights('%s.h5' % path)
        print("Loading model successfully...")
        return model
    except Exception as e:
        print(e)

def change_brightness(img):
    """
    value: độ sáng thay đổi
    """
    value = 10
    #chuyển đổi giữa các không gian màu khác nhau
    #Thông tin màu sắc không có thay đổi lớn dù trong nhà hay ngoài sáng
    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV) 
    #h: Màu sắc, s: Độ đậm đặc, v: value
    h, s, v = cv2.split(hsv)
    v = cv2.add(v, value)
    v[v > 255] = 255
    v[v < 0] = 0
    final_hsv = cv2.merge((h, s, v))
    img = cv2.cvtColor(final_hsv, cv2.COLOR_HSV2BGR)
    return img
    

#Hàm tiền xử lý
def preprocess_image(image_path,resize=False):
    img = cv2.imread(image_path)#nạp ảnh
    img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)#chuyển đổi không gian màu, chuyển về ảnh xám
    img = change_brightness(img)
    img = img / 255
    if resize:#chỉnh kích thước
        img = cv2.resize(img, (224,224))
    return img

def get_plate(image_path, wpod_net, Dmax=608, Dmin=256):
    vehicle = preprocess_image(image_path)
    #vehicle = preprocessImage(image_path)
    ratio = float(max(vehicle.shape[:2])) / min(vehicle.shape[:2])
    side = int(ratio * Dmin)
    bound_dim = min(side, Dmax)
    _ , LpImg, _, cor = detect_lp(wpod_net, vehicle, bound_dim, lp_threshold=0.5)
    return LpImg[0]

#Chuyển ảnh thành ảnh nhị phân(ảnh hai màu)
def binary_image(image):
    if (len(image)): #check if there is at least one license image - Kiểm tra xem ảnh có hợp lệ hay không
        # Scales, calculates absolute values, and converts the result to 8-bit.- Cân , tính toán các giá trị tuyệt đối và chuyển sang dạng 8 bit
        plate_image = cv2.convertScaleAbs(image, alpha=(255.0))
        # convert to grayscale and blur the image - chuyển ảnh sang thang độ sám và làm mờ ảnh
        gray = cv2.cvtColor(plate_image, cv2.COLOR_BGR2GRAY)
        blur = cv2.GaussianBlur(gray,(7,7),0)
        
        # Applied inversed thresh_binary  - áp dụng bảng mã nhị phân đảo ngược
        binary = cv2.threshold(blur, 80, 255,
                             cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU)[1]
        kernel3 = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
        thre_mor = cv2.morphologyEx(binary, cv2.MORPH_DILATE, kernel3)
        ##Change brightness
    return thre_mor

# Create sort_contours() function to grab the contour of each digit from left to right
#Tạo hàm sort_contours () để lấy đường viền của mỗi chữ số từ trái sang phải
def sort_contours(cnts,reverse = False):
    i = 0
    boundingBoxes = [cv2.boundingRect(c) for c in cnts]
    (cnts, boundingBoxes) = zip(*sorted(zip(cnts, boundingBoxes),
                                        key=lambda b: b[1][i], reverse=reverse))
    return cnts

def get_list_character(binary_image):
    cont, _  = cv2.findContours(binary_image, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    # Initialize a list which will be used to append charater image
    #Khởi tạo một danh sách sẽ được sử dụng để nối thêm hình ảnh 
    crop_characters = []

    # define standard width and height of character
    #xác định chiều cao và chiều rộng chuẩn của kí tự
    digit_w, digit_h = 30, 60

    for c in sort_contours(cont):
        (x, y, w, h) = cv2.boundingRect(c)
        ratio = h/w
        if 1<=ratio<=5: # Only select contour with defined ratio - chọn đường bao với tỷ lệ xác định
            if h/plate_image.shape[0]>=0.3: # Select contour which has the height larger than 50% of the plate - Chọn đường bao có chiều cao lớn hơn 50% của tấm

                # Sperate number and gibe prediction - Tách số và đưa ra dự đoán

                curr_num = binary_image[y:y+h,x:x+w]
                curr_num = cv2.resize(curr_num, dsize=(digit_w, digit_h))
                _, curr_num = cv2.threshold(curr_num, 220, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
                crop_characters.append(curr_num) 
    return crop_characters

def predict_from_model(image,model,labels):
    image = cv2.resize(image,(80,80))
    image = np.stack((image,)*3, axis=-1)
    prediction = labels.inverse_transform([np.argmax(model.predict(image[np.newaxis,:]))])
    return prediction

#bỏi vì biển số xe máy có đặc điểm là hai dòng, trong khi đó cách xử lý ảnh hiện tại chỉ có thể xử lý từ trái sang phải, vì vậy cần cắt hình ảnh đã xử lý ra để lấy kết quả
def get_result(crop_characters):
    final_string = ''
    for i,character in enumerate(crop_characters):
        title = np.array2string(predict_from_model(character,model,labels))
        final_string+=title.strip("'[]")
    return final_string[1::2]+"-"+final_string[0::2]
    #trả về là một chuỗi string là biển số xe
#chạy toàn bộ các hàm load model, 
json_file = open("E:\\HK2_NAM2\\LapTrinhPython\\Nhóm 1\\Code\\MobileNets_character_recognition.json", 'r')
loaded_model_json = json_file.read()
json_file.close()
model = model_from_json(loaded_model_json)
model.load_weights("E:\\HK2_NAM2\\LapTrinhPython\\Nhóm 1\\Code\\License_character_recognition_weight.h5")
print("[INFO] Model loaded successfully...")
labels = preprocessing.LabelEncoder()
labels.classes_ = np.load('E:\\HK2_NAM2\\LapTrinhPython\\Nhóm 1\\Code\\license_character_classes.npy')
print("[INFO] Labels loaded successfully...")
wpod_net_path = "E:\\HK2_NAM2\\LapTrinhPython\\Nhóm 1\\Code\\wpod-net.json"
wpod_net = load_model(wpod_net_path)
imagePath="bs5.jpg"
img = imagePath
plate_image = get_plate(img, wpod_net)
binary_plate_image = binary_image(plate_image)
list_characters = get_list_character(binary_plate_image)

def GetLicense(imagePath):
    img = imagePath
    plate_image = get_plate(img, wpod_net)
    binary_plate_image = binary_image(plate_image)
    list_characters = get_list_character(binary_plate_image)
    return get_result(list_characters)
    
if __name__ =="__main__":
    cout = 0
    inp = 1
    sl = 100
    fileDir = os.path.dirname(os.path.realpath('__file__'))


# %%
