create database Win_Final
go

use Win_Final
go


create table Accounts
(
	Name nvarchar(50),
	Account nvarchar(50) primary key,
	Password nvarchar(50),
	Position nvarchar(20)
)

create table Employee
(
	employee_id int identity(1,1) primary key,
	employee_account nvarchar(50),
	employee_name nvarchar(100),
	phone nvarchar(15),
	address nvarchar(30),
	birth date,
	shift nvarchar(20),
	salary float
)
go

create table Item
(
	item_id int identity(1,1) primary key,
	item_name nvarchar(100),
	item_price_in float,
	item_price_out float,
	quantity_in_stock int,
	expiry date
)
go


create table Orders
(
	order_id int identity(1,1) primary key,
	order_date datetime,
	customer_id int null,
	employee_id int,
	total float null,
)
go

create table Lineitem
(
	order_id int,
	item_id int,
	quantity int

	Primary key(order_id,item_id)
)

create table Customers
(
	customer_id int identity (1,1) primary key,
	customer_name nvarchar(50),
	customer_address nvarchar(50),
	tolal float
)

create table Voucher
(
	ma_voucher int identity(1,1) primary key,
	gia_voucher float
)


ALTER TABLE Orders ADD FOREIGN KEY (customer_id) REFERENCES Customers(customer_id) 
ALTER TABLE Employee ADD FOREIGN KEY(employee_account) REFERENCES Accounts(Account)
ALTER TABLE Orders ADD FOREIGN KEY(employee_id) REFERENCES Employee(employee_id)
Alter TABLE Lineitem ADD FOREIGN KEY(order_id) REFERENCES Orders(order_id)
ALTER TABLE Lineitem ADD FOREIGN KEY(item_id) REFERENCES Item(item_id)

insert into dbo.Accounts values (N'Thành Đồng','NTD','1','Admin')
insert into dbo.Accounts values (N'Tuấn Nghĩa','LTN','1','Admin')
insert into dbo.Accounts values (N'Minh Đức','TMD','1','Admin')
insert into dbo.Accounts values (N'Văn Khánh','NVK','1','Employee')
insert into dbo.Accounts values (N'Quế My','HQM','1','Employee')
insert into dbo.Accounts values (N'Đức Sáng','NDS','1','Employee')
insert into dbo.Accounts values (N'Quốc Việt','DQV','1','Employee')
insert into dbo.Accounts values (N'Phúc Hậu','LPH','1','Employee')
insert into dbo.Accounts values (N'Huy Hoàng','LHH','1','Employee')
insert into dbo.Accounts values (N'Trung Kiên','TTK','1','Employee')
insert into dbo.Accounts values (N'Quốc Bảo','NQB','1','Employee')
insert into dbo.Accounts values (N'Trung Hậu','TTH','1','Employee')
insert into dbo.Accounts values (N'Quốc Trung','LQT','1','Employee')

insert into dbo.Employee values ('NVK',N'Văn Khánh','0912312412',N'Số 1 Võ Văn Ngân','3/3/2002','7h-13h T2,T3,T4',30000)
insert into dbo.Employee values ('HQM',N'Quế My','0914146890',N'Số 2 Võ Văn Ngân','1/5/2002','7h-13h T2,T3,T4',30000)
insert into dbo.Employee values ('NDS',N'Đức Sáng','0944115167',N'Số 3 Võ Văn Ngân','2/9/2002','7h-13h T5,T6,T7',30000)
insert into dbo.Employee values ('DQV',N'Quốc Việt','0902461838',N'Số 4 Võ Văn Ngân','2/4/2001','7h-13h T5,T6,T7',30000)
insert into dbo.Employee values ('LPH',N'Phúc Hậu','0124473792',N'Số 5 Võ Văn Ngân','5/6/2001','13h-19h T2,T3,T4',30000)
insert into dbo.Employee values ('LHH',N'Huy Hoàng','0901525615',N'Số 6 Võ Văn Ngân','5/11/2002','13h-19h T2,T3,T4',30000)
insert into dbo.Employee values ('TTK',N'Trung Kiên','0125365783',N'Số 7 Võ Văn Ngân','1/10/2002','13h-19h T5,T6,T7',30000)
insert into dbo.Employee values ('NQB',N'Quốc Bảo','0141215789',N'Số 8 Võ Văn Ngân','1/12/2002','13h-19h T5,T6,T7',30000)
insert into dbo.Employee values ('TTH',N'Trung Hậu','0113117891',N'Số 9 Võ Văn Ngân','5/7/2002','7h-13h CN',30000)
insert into dbo.Employee values ('NQB',N'Quốc Bảo','0134537919',N'Số 10 Võ Văn Ngân','3/8/2002','13h-19h CN',30000)

Insert into dbo.Customers values(N'Nguyễn Quốc Vinh',N'1 Tô Ngọc Vân',900000)
Insert into dbo.Customers values(N'Trần Lê Ngọc Gia Hân',N'2 Tô Ngọc Vân',100000)
Insert into dbo.Customers values(N'Lê Gia Hân',N'3 Tô Ngọc Vân',80000)
Insert into dbo.Customers values(N'Nguyễn Thị Lan Anh',N'4 Tô Ngọc Vân',170000)
Insert into dbo.Customers values(N'Nguyễn Thị Phương Anh',N'5 Tô Ngọc Vân',2090000)
Insert into dbo.Customers values(N'Diệp Tấn Luân',N'6 Tô Ngọc Vân',1000000)
Insert into dbo.Customers values(N'Bùi Quốc Tĩnh',N'7 Tô Ngọc Vân',800000)
Insert into dbo.Customers values(N'Đỗ Thị Mỹ Lan',N'8 Tô Ngọc Vân',203000)
Insert into dbo.Customers values(N'Bùi Tấn Đạt',N'9 Tô Ngọc Vân',256000)
Insert into dbo.Customers values(N'Nguyễn Ý',N'10 Tô Ngọc Vân',1516000)
Insert into dbo.Customers values(N'Trần Thị Mỹ Huyền',N'11 Tô Ngọc Vân',915000)
Insert into dbo.Customers values(N'Nguyễn Hải Quốc Bảo',N'12 Tô Ngọc Vân',812000)
Insert into dbo.Customers values(N'Lê Thành Nhân',N'13 Tô Ngọc Vân',941000)
Insert into dbo.Customers values(N'Lê Thanh Sang',N'14 Tô Ngọc Vân',661000)
Insert into dbo.Customers values(N'Lê Thị Phượng',N'15 Tô Ngọc Vân',612000)
Insert into dbo.Customers values(N'Lê Văn Săm',N'16 Tô Ngọc Vân',735000)
Insert into dbo.Customers values(N'Văn Thị Mười Ngọc',N'17 Tô Ngọc Vân',373000)
Insert into dbo.Customers values(N'Nguyễn Kim Ngân',N'18 Tô Ngọc Vân',241000)
Insert into dbo.Customers values(N'Nguyễn Thị Thùy Trang',N'19 Tô Ngọc Vân',345000)
Insert into dbo.Customers values(N'Phùng Thị Thùy Trang',N'20 Tô Ngọc Vân',823000)
Insert into dbo.Customers values(N'Huỳnh Ngọc Trâm',N'21 Tô Ngọc Vân',612000)
Insert into dbo.Customers values(N'Nguyễn Hồng Điệp',N'22 Tô Ngọc Vân',843000)
Insert into dbo.Customers values(N'Trần Ngọc Phước',N'23 Tô Ngọc Vân',1562000)
Insert into dbo.Customers values(N'Nguyễn Hải Bích Phượng',N'24 Tô Ngọc Vân',512000)
Insert into dbo.Customers values(N'Nguyễn Bảo Yến',N'25 Tô Ngọc Vân',671000)
Insert into dbo.Customers values(N'Võ Như Ý',N'26 Tô Ngọc Vân',612000)
Insert into dbo.Customers values(N'Nguyễn Chí Dũng',N'27 Tô Ngọc Vân',685000)
Insert into dbo.Customers values(N'Hải Triều Châu',N'28 Tô Ngọc Vân',832000)
Insert into dbo.Customers values(N'Trương Võ Song Toàn',N'29 Tô Ngọc Vân',645000)
Insert into dbo.Customers values(N'Lê Gia Huy',N'30 Tô Ngọc Vân',582000)

Insert into dbo.Voucher values (10000)
Insert into dbo.Voucher values (15000)
Insert into dbo.Voucher values (20000)
Insert into dbo.Voucher values (30000)
Insert into dbo.Voucher values (50000)
Insert into dbo.Voucher values (55000)
Insert into dbo.Voucher values (100000)
Insert into dbo.Voucher values (150000)
Insert into dbo.Voucher values (200000)
Insert into dbo.Voucher values (500000)

insert into dbo.Item values (N'Sting', 6000, 9000, 5000, '12/12/2022')
insert into dbo.Item values (N'CocaCola', 5800, 8000, 4000, '12/30/2022')
insert into dbo.Item values (N'Nước suối',3200, 5000, 5000, '12/30/2022')
insert into dbo.Item values (N'Cafe nestle',5900, 10000, 1500, '9/30/2022')
insert into dbo.Item values (N'Sữa Milo', 5800, 8000, 2000 ,'10/20/2022')
insert into dbo.Item values (N'Mirinda Soda kem', 6700, 10000, 1500, '3/20/2023')
insert into dbo.Item values (N'Mirinda việt quất', 6700, 10000, 1500, '3/20/2023')
insert into dbo.Item values (N'Kem Socola', 5800, 9000,1500, '6/30/2022')
insert into dbo.Item values (N'Kem Vani', 5800, 9000,1500, '6/30/2022')
insert into dbo.Item values (N'Kem Matcha', 5800, 9000, 1500, '6/30/2022')
insert into dbo.Item values (N'Trứng gà',2200, 3200, 5000,'7/30/2022')
insert into dbo.Item values (N'Trứng vịt',2200, 3000, 5000,'7/30/2022')
insert into dbo.Item values (N'Sữa',16900, 19000, 5000,'9/30/2022')
insert into dbo.Item values (N'Nước mắm', 5900, 8000, 5000,'12/30/2022')
insert into dbo.Item values (N'Nước tương',7000, 12000, 5000,'12/30/2022')
insert into dbo.Item values (N'Dầu ăn',6000, 10000, 5000,'12/30/2022')
insert into dbo.Item values (N'Đường',6000, 10000, 5000,'12/30/2023')
insert into dbo.Item values (N'Muối',6000, 10000, 5000,'12/30/2023')
insert into dbo.Item values (N'Bột ngọt',6000, 9000, 5000,'12/30/2023')
insert into dbo.Item values (N'Bột nêm',6000, 10000, 5000,'12/30/2023')
insert into dbo.Item values (N'Bột chiên giòn',6000, 10000, 5000,'12/30/2023')
insert into dbo.Item values (N'Bột giặt',2300,5000,2000,'12/30/2023')
insert into dbo.Item values (N'Nước giặt xả',2300,5000,2000,'12/30/2023')
insert into dbo.Item values (N'Giấy ăn',1300,4000,2000,'12/30/2023')
insert into dbo.Item values (N'Bánh Snack khoai tây',6900,12000,1500,'12/30/2022')
insert into dbo.Item values (N'Bánh Snack rong biển',6900,12000,1500,'12/30/2022')
insert into dbo.Item values (N'Bánh Snack vị gà quay',6900,12000,1500,'12/30/2022')
insert into dbo.Item values (N'Bột Matcha 500g',43600,52000,1000,'9/30/2022')
insert into dbo.Item values (N'Bột Cacao 500g',43600,52000,1000,'9/30/2022')
insert into dbo.Item values (N'Bột Cafe 500g',43600,52000,1000,'9/30/2022')
insert into dbo.Item values (N'Lipton dạng gói 2gx10',13600,19000,1000,'9/30/2023')
insert into dbo.Item values (N'Cafe dạng gói 2gx15',15600,24000,1000,'9/30/2023')
insert into dbo.Item values (N'Thẻ điện thoại 20k',19000,20000,1000,'12/30/2022')
insert into dbo.Item values (N'Thẻ điện thoại 50k',48000,50000,1000,'12/30/2022')
insert into dbo.Item values (N'Thẻ điện thoại 100k',97000,100000,1000,'12/30/2022')
insert into dbo.Item values (N'Mì 3 miền',2100,3500,2000,'10/30/2022')
insert into dbo.Item values (N'Mì Kokomi',2500,4000,2000,'10/30/2022')
insert into dbo.Item values (N'Mì Mihamex',2500,4000,2000,'10/30/2022')
insert into dbo.Item values (N'Mì Đệ nhất',3000,5000,2000,'10/30/2022')
insert into dbo.Item values (N'Mì Gấu đỏ',2100,3500,2000,'10/30/2022')
insert into dbo.Item values (N'Kẹo Bạc hà',5200,9000,2000,'12/30/2022')
insert into dbo.Item values (N'Kẹo Singum Xylitol',6000,10000,20000,'12/30/2022')
insert into dbo.Item values (N'Kẹo dẻo',5200,9000,2000,'12/30/2022')
insert into dbo.Item values (N'Kẹo Trái cây 4 mùa',6200,13000,2000,'12/30/2022')
insert into dbo.Item values (N'Kitkat socola',7200,14000,2000,'12/30/2022')
insert into dbo.Item values (N'Kitkat matcha',7200,14000,2000,'12/30/2022')
insert into dbo.Item values (N'Bánh Solite',2200,3000,2000,'12/30/2022')
insert into dbo.Item values (N'Bánh mì ngọt',5200,10000,2000,'12/30/2022')
insert into dbo.Item values (N'Bánh bao chỉ',5200,9000,2000,'12/30/2022')
insert into dbo.Item values (N'Bánh trung thu',12500,20000,2000,'12/30/2022')


insert into dbo.Orders values('4/30/2022 16:02:32',1,2,0)
insert into dbo.Lineitem values(1,3,5)
insert into dbo.Lineitem values(1,2,4)
insert into dbo.Lineitem values(1,4,3)
update dbo.Orders Set total = (select sum(Item.item_price_out*Lineitem.quantity) 
	from Item,Lineitem,Orders 
	Where Lineitem.order_id = Orders.order_id And Lineitem.item_id=Item.item_id and Orders.order_id =1) where order_id =1

insert into dbo.Orders values('5/1/2022 7:18:21',2,3,0)
insert into dbo.Lineitem values(2,29,3)
insert into dbo.Lineitem values(2,19,4)
insert into dbo.Lineitem values(2,13,2)
insert into dbo.Lineitem values(2,18,6)
update dbo.Orders Set total = (select sum(Item.item_price_out*Lineitem.quantity) 
	from Item,Lineitem,Orders 
	Where Lineitem.order_id = Orders.order_id And Lineitem.item_id=Item.item_id and Orders.order_id =2) where order_id =2

insert into dbo.Orders values('6/1/2022 9:54:31',3,3,0)
insert into dbo.Lineitem values(3,16,4)
insert into dbo.Lineitem values(3,20,2)
insert into dbo.Lineitem values(3,10,1)
insert into dbo.Lineitem values(3,22,2)
insert into dbo.Lineitem values(3,17,2)
insert into dbo.Lineitem values(3,44,1)
update dbo.Orders Set total = (select sum(Item.item_price_out*Lineitem.quantity) 
	from Item,Lineitem,Orders 
	Where Lineitem.order_id = Orders.order_id And Lineitem.item_id=Item.item_id and Orders.order_id =3) where order_id =3

insert into dbo.Orders values('6/2/2022 18:02:11',4,5,0)
insert into dbo.Lineitem values(4,8,2)
insert into dbo.Lineitem values(4,5,3)
insert into dbo.Lineitem values(4,33,2)
insert into dbo.Lineitem values(4,46,1)
update dbo.Orders Set total = (select sum(Item.item_price_out*Lineitem.quantity) 
	from Item,Lineitem,Orders 
	Where Lineitem.order_id = Orders.order_id And Lineitem.item_id=Item.item_id and Orders.order_id =4) where order_id =4

insert into dbo.Orders values('6/1/2022 14:23:02',5,8,0)
insert into dbo.Lineitem values(5,11,3)
insert into dbo.Lineitem values(5,47,2)
insert into dbo.Lineitem values(5,50,4)
insert into dbo.Lineitem values(5,41,5)
update dbo.Orders Set total = (select sum(Item.item_price_out*Lineitem.quantity) 
	from Item,Lineitem,Orders 
	Where Lineitem.order_id = Orders.order_id And Lineitem.item_id=Item.item_id and Orders.order_id =5) where order_id =5

insert into dbo.Orders values('5/30/2022 13:25:54',6,7,0)
insert into dbo.Lineitem values(6,7,3)
insert into dbo.Lineitem values(6,6,2)
insert into dbo.Lineitem values(6,28,4)
insert into dbo.Lineitem values(6,44,1)
update dbo.Orders Set total = (select sum(Item.item_price_out*Lineitem.quantity) 
	from Item,Lineitem,Orders 
	Where Lineitem.order_id = Orders.order_id And Lineitem.item_id=Item.item_id and Orders.order_id =6) where order_id =6

insert into dbo.Orders values('5/29/2022 13:25:54',7,5,0)
insert into dbo.Lineitem values(7,2,3)
insert into dbo.Lineitem values(7,29,2)
insert into dbo.Lineitem values(7,37,1)
update dbo.Orders Set total = (select sum(Item.item_price_out*Lineitem.quantity) 
	from Item,Lineitem,Orders 
	Where Lineitem.order_id = Orders.order_id And Lineitem.item_id=Item.item_id and Orders.order_id =7) where order_id =7

insert into dbo.Orders values('5/28/2022 13:25:54',8,4,0)
insert into dbo.Lineitem values(8,46,3)
insert into dbo.Lineitem values(8,47,3)
update dbo.Orders Set total = (select sum(Item.item_price_out*Lineitem.quantity) 
	from Item,Lineitem,Orders 
	Where Lineitem.order_id = Orders.order_id And Lineitem.item_id=Item.item_id and Orders.order_id =8) where order_id =8

insert into dbo.Orders values('5/27/2022 13:25:54',9,2,0)
insert into dbo.Lineitem values(9,38,3)
insert into dbo.Lineitem values(9,11,2)
insert into dbo.Lineitem values(9,14,5)
update dbo.Orders Set total = (select sum(Item.item_price_out*Lineitem.quantity) 
	from Item,Lineitem,Orders 
	Where Lineitem.order_id = Orders.order_id And Lineitem.item_id=Item.item_id and Orders.order_id =9) where order_id =9

insert into dbo.Orders values('5/28/2022 13:25:54',10,6,0)
insert into dbo.Lineitem values(10,38,3)
insert into dbo.Lineitem values(10,12,4)
insert into dbo.Lineitem values(10,25,2)
update dbo.Orders Set total = (select sum(Item.item_price_out*Lineitem.quantity) 
	from Item,Lineitem,Orders 
	Where Lineitem.order_id = Orders.order_id And Lineitem.item_id=Item.item_id and Orders.order_id =10) where order_id =10

insert into dbo.Orders values('5/27/2022 13:25:54',11,5,0)
insert into dbo.Lineitem values(11,8,3)
insert into dbo.Lineitem values(11,29,1)
insert into dbo.Lineitem values(11,21,5)
insert into dbo.Lineitem values(11,47,2)
update dbo.Orders Set total = (select sum(Item.item_price_out*Lineitem.quantity) 
	from Item,Lineitem,Orders 
	Where Lineitem.order_id = Orders.order_id And Lineitem.item_id=Item.item_id and Orders.order_id =11) where order_id =11

insert into dbo.Orders values('5/27/2022 13:25:54',12,7,0)
insert into dbo.Lineitem values(12,6,3)
insert into dbo.Lineitem values(12,36,5)
insert into dbo.Lineitem values(12,24,2)
insert into dbo.Lineitem values(12,16,1)
insert into dbo.Lineitem values(12,49,3)
update dbo.Orders Set total = (select sum(Item.item_price_out*Lineitem.quantity) 
	from Item,Lineitem,Orders 
	Where Lineitem.order_id = Orders.order_id And Lineitem.item_id=Item.item_id and Orders.order_id =12) where order_id =12

insert into dbo.Orders values('5/27/2022 13:25:54',13,2,0)
insert into dbo.Lineitem values(13,48,2)
insert into dbo.Lineitem values(13,39,5)
insert into dbo.Lineitem values(13,40,1)
update dbo.Orders Set total = (select sum(Item.item_price_out*Lineitem.quantity) 
	from Item,Lineitem,Orders 
	Where Lineitem.order_id = Orders.order_id And Lineitem.item_id=Item.item_id and Orders.order_id =13) where order_id =13

insert into dbo.Orders values('5/26/2022 13:25:54',14,4,0)
insert into dbo.Lineitem values(14,47,4)
insert into dbo.Lineitem values(14,16,3)
update dbo.Orders Set total = (select sum(Item.item_price_out*Lineitem.quantity) 
	from Item,Lineitem,Orders 
	Where Lineitem.order_id = Orders.order_id And Lineitem.item_id=Item.item_id and Orders.order_id =14) where order_id =14

insert into dbo.Orders values('5/28/2022 13:25:54',15,6,0)
insert into dbo.Lineitem values(15,15,4)
insert into dbo.Lineitem values(15,36,2)
insert into dbo.Lineitem values(15,42,5)
insert into dbo.Lineitem values(15,41,1)
update dbo.Orders Set total = (select sum(Item.item_price_out*Lineitem.quantity) 
	from Item,Lineitem,Orders 
	Where Lineitem.order_id = Orders.order_id And Lineitem.item_id=Item.item_id and Orders.order_id =15) where order_id =15


