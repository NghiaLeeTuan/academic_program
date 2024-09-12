﻿use SMS
go

create table Customer
(
	customer_id int identity(1,1) primary key,
	customer_name nvarchar(100),
)
go

create table Employee
(
	employee_id int identity(1,1) primary key,
	employee_name nvarchar(100),
	salary float,
	supervisor_id int,
)
go

create table LineItem
(
	order_id int, 
	product_id int,
	quantity int,
	price float,
)
go

create table Product
(
	product_id int identity(1,1) primary key,
	product_name nvarchar(100),
	product_price float,
)
go

create table Orders
(
	order_id int identity(1,1) primary key,
	order_date datetime,
	customer_id int,
	employee_id int,
	total float,
)
go

CREATE PROCEDURE [dbo].[Add_Customer](@CustomerName nvarchar(100))
AS
BEGIN
	insert into Customer values (@CustomerName)
END


CREATE PROCEDURE [dbo].[Delete_Customer](@Customer_id int)
AS
Begin
	Delete from Customer where customer_id=@Customer_id
	Delete from LineItem where order_id in (select order_id from Orders where customer_id=@Customer_id)
	Delete from Orders where customer_id=@Customer_id
End

CREATE FUNCTION [dbo].[Total_price](@order_id int)
RETURNS float AS
BEGIN
	DECLARE @Total float
	SELECT @Total = sum (price * quantity)
	from LineItem
	where order_id= @order_id
	RETURN @Total
END

CREATE PROCEDURE [dbo].[Update_Customer](@cus_id int, @cus_name nvarchar(100))
AS
BEGIN
	Update Customer set customer_name = @cus_name where customer_id = @cus_id
END

insert into dbo.Employee values (N'Hoàng Trang','5500000','1')
insert into dbo.Employee values (N'Hửu Nghĩa','5000000','1')

insert into dbo.LineItem values ('1','1','1','70000')
insert into dbo.LineItem values ('1','2','1','80000')
insert into dbo.LineItem values ('1','4','2','100000')
insert into dbo.LineItem values ('2','2','4','80000')
insert into dbo.LineItem values ('2','3','2','20000')
insert into dbo.LineItem values ('3','1','7','70000')
insert into dbo.LineItem values ('3','3','10','20000')
insert into dbo.LineItem values ('3','4','5','100000')

insert into dbo.Orders values ('2021/11/24','1','1','0')
insert into dbo.Orders values ('2021/11/24','4','2','0')
insert into dbo.Orders values ('2021/11/25','5','2','0')

insert into dbo.Product values (N'áo thun','70000')
insert into dbo.Product values (N'áo khoác','80000')
insert into dbo.Product values (N'nón','20000')
insert into dbo.Product values (N'quần','100000')

insert into dbo.Customer values (N'Tuấn Nghĩa')
insert into dbo.Customer values (N'Gia Hân')
insert into dbo.Customer values (N'Văn Khánh')
insert into dbo.Customer values (N'Thạch Quang')
insert into dbo.Customer values (N'Thanh Ngân')