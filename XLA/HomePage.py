import streamlit as st
#import lib.common as tools

st.set_page_config(
    page_title="Đồ án cuối kỳ",
)

page_bg_img = """
<style>
[data-testid="stAppViewContainer"] {
    background-image: url("https://i.pinimg.com/564x/bc/43/27/bc43279827af63b3fdba3c93514c69a8.jpg");
    background-size: 100% 100%;
}
[data-testid="stHeader"]{
    background: rgba(0,0,0,0);
}
[data-testid="stToolbar"]{
    right:2rem;
}
[data-testid="stSidebar"] > div:first-child {
    background-image: url("");
    background-position: center;
}
</style>
"""
st.markdown(page_bg_img,unsafe_allow_html=True)


# logo_path = "./VCT.png"
# st.sidebar.image(logo_path, width=200)

st.write("# Đồ án cuối kỳ")
st.write("# 20133072 - Lê Tuấn Nghĩa")
st.write("# Mã lớp : DIPR430685_23_1_01")

st.markdown(
    """
    ## Sản phẩm
    Project cuối kỳ cho môn học xử lý ảnh số DIPR430685.
    Thuộc Trường Đại Học Sư Phạm Kỹ Thuật TP.HCM.
    ### 8 chức năng chính trong bài
    - 📖Giải phương trình bậc 2
    - 📖Nhận diện khuôn mặt
    - 📖Nhận diện chữ viết tay
    - 📖Nhận dạng đối tượng yolo4
    - 📖Phát hiện trái cây
    - 📖Xử lý ảnh số
    - 📖Nhận dạng cử chỉ tay
    - 📖Nhận diện hành vi con người
    ## Thông tin sinh viên thực hiện
    - Họ tên: Lê Tuấn Nghĩa
    - MSSV: 20133072
    """
)


