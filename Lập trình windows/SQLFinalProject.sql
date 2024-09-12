create database Win_Final 
go

use Win_Final
go


create table Account
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
	product_id int,
	item_name nvarchar(100),
	item_price_in float,
	item_price_out float,
	quantity_in_stock int,
	expiry date
)
go


create table Product
(
	product_id int identity(1,1) primary key,
	product_name nvarchar(50)
)
go

create table Orders
(
	order_id int identity(1,1) primary key,
	order_date datetime,
	customer_name nvarchar(50) null,
	employee_id int,
	total float null,
)
go

create table Lineitem
(
	order_id int,
	item_id int,
	quantity int
)


ALTER TABLE Employee ADD FOREIGN KEY(employee_account) REFERENCES Account(Account)
ALTER TABLE Item ADD FOREIGN KEY(product_id) REFERENCES Product(product_id)
ALTER TABLE Orders ADD FOREIGN KEY(employee_id) REFERENCES Employee(employee_id)
Alter TABLE Lineitem ADD FOREIGN KEY(order_id) REFERENCES Orders(order_id)
ALTER TABLE Lineitem ADD FOREIGN KEY(item_id) REFERENCES Item(item_id)



insert into dbo.Account values (N'Thành Đồng','NTD','1','Admin')
insert into dbo.Account values (N'Tuấn Nghĩa','LTN','1','Admin')
insert into dbo.Account values (N'Minh Đức','TMD','1','Admin')
insert into dbo.Account values (N'Văn Khánh','NVK','1','Employee')
insert into dbo.Account values (N'Quế My','HQM','1','Employee')

insert into dbo.Employee values ('NVK',N'Ngô Văn Khánh','0912312412',N'Số 1 Võ Văn Ngân','3/3/2020','7h-11h',30000)
insert into dbo.Employee values ('HQM',N'Hồ Quế My','0900100101',N'Số 2 Võ Văn Ngân','4/2/2020','7h-11h',30000)

insert into dbo.Product values (N'Công Ty Cp Chế Biến Thực Phẩm Thủ Đức')
insert into dbo.Product values (N'Công ty cổ phần lương thực phảm safoco')
insert into dbo.Product values (N'Công Ty TNHH Thực Phẩm Ana')

insert into dbo.Item values (1,'Trứng gà',55000,60000,30,'2/9/2022')
insert into dbo.Item values (2,'Thịt heo',70000,80000,60,'8/9/2022')
insert into dbo.Item values (3,'Cá',60000,90000,7,'6/8/2022')

insert into dbo.Orders values ('7/5/2022',N'Lệ Xuân',2,0)

insert into dbo.Lineitem values (1,1,2)
insert into dbo.Lineitem values (1,2,3)

update dbo.Orders Set total = (select sum(Item.item_price_out*Lineitem.quantity) from Item,Lineitem,Orders Where Lineitem.order_id = Orders.order_id And Lineitem.item_id=Item.item_id)

select * from dbo.Orders