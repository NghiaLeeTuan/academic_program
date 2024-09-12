-- tạo cở sở dữ liệu BrzShopDW để import các file CSV từ olist dataset
-- sử dụng task -> import flat file để import , chú ý kiểu dữ liệu của các trường trong file
--create database BrzShopDW
--go
--use BrzShopDW
--go


-- Dùng code này, tạo datawarehouse cho olist dataset

-- Tao data warehouse
	create database DA_DATAWH
	go
-- Use datawwh
	use DA_DATAWH
	go

-- DataWareHouse cho shopping datamart

-- Bang DimDate
create table DimDate(
	datekey int IDENTITY not null,
	-- attributes
	[Date] [datetime] NULL,
	[DayOfWeek] [tinyint] NOT NULL,
	[DayName] [varchar](9) NOT NULL,
	[DayOfMonth] [tinyint] NOT NULL,
	[DayOfYear] [smallint] NOT NULL,
	[WeekOfYear] [tinyint] NOT NULL,
	[MonthName] [varchar](9) NOT NULL,
	[MonthOfYear] [tinyint] NOT NULL,
	[Quarter] [tinyint] NOT NULL,
	[QuarterName] [varchar](9) NOT NULL,
	[Year] [smallint] NOT NULL,
	[IsAWeekday] varchar(1) NOT NULL DEFAULT (('N')),
	constraint pkDimDate PRIMARY KEY ([DateKey])
)
go

-- Bang DimLocation
create table DimGeolocation (
	geolocation_key int IDENTITY not null,
	--attributes
	geolocation_zip_code_prefix varchar(50),
	-- geolocation_lat float,
	-- geolocation_lng float,
	geolocation_city nvarchar(50),
	geolocation_state varchar(50),

	constraint pkDimGeolocation primary key (geolocation_key)
)
go

--Bang DimCustomer
create table DimCustomers (
	customer_key int IDENTITY not null,

	geolocation_key int not null,
	--attributes
	customer_id varchar(50),
	customer_unique_id varchar(50),
	--customer_zip_code_prefix varchar,
	--customer_city nvarchar,
	--customer_state varchar
	--metadata
	CONSTRAINT [pkDimCustomer] PRIMARY KEY ( customer_key ),
	constraint fkDimCustomers_geolocation_Key foreign key (geolocation_key) 
		references DimGeolocation(geolocation_key),
)
go



-- Bang DimSeller
create table DimSellers (
	seller_key int IDENTITY not null,

	geolocation_key int not null,
	--attributes
	seller_id nvarchar(50),
	--seller_zip_code_prefix nvarchar,
	--seller_city nvarchar,
	--seller_state nvarchar,
	--metadata
	CONSTRAINT [pkDimSellers] PRIMARY KEY ( seller_key ),
	constraint fkDimSellers_geolocation_Key foreign key (geolocation_key) 
		references DimGeolocation(geolocation_key),
)
go

--Bang DimProduct
create table DimProducts (
	product_key int IDENTITY not null,
	--attributes
	product_id nvarchar(50),
	product_category_name nvarchar(50),
	product_name_lenght int,
	product_description_lenght int,
	product_photos_qty int,
	product_weight_g int,
	product_length_cm int,
	product_height_cm int,
	product_width_cm int,
	--metadata
	CONSTRAINT [pkDimProducts] PRIMARY KEY ( product_key )
	)
go
 
 --Bang Fact Order
create table Fact_Orders (
	order_key int IDENTITY not null,

	customer_key int not null,
	order_purchase_timestamp_key int not null,
	order_approved_at_key int not null,
	order_delivered_carrier_date_key int not null,
 	order_delivered_customer_date_key int not null,
	order_estimated_delivery_date_key int not null,
	--attributes
	order_id varchar(50),
	--customer_id varchar,
	order_status varchar(50),
	--order_purchase_timestamp datetime,
	--order_approved_at datetime,
	--order_delivered_carrier_date datetime,
 	--order_delivered_customer_date datetime,
	--order_estimated_delivery_date datetime,

	constraint pkOrders primary key (order_key),
	constraint fkFact_Orders_Customer_Key foreign key (customer_key) 
		references DimCustomers(customer_key),
	constraint fkFact_Orders_order_purchase_timestamp_key foreign key (order_purchase_timestamp_key) 
		references DimDate(datekey),
	constraint fkFact_Orders_order_approved_at_key foreign key (order_approved_at_key) 
		references DimDate(datekey),
	constraint fkFact_Orders_order_delivered_carrier_date_key foreign key (order_delivered_carrier_date_key) 
		references DimDate(datekey),
	constraint fkFact_Orders_order_delivered_customer_date_key foreign key (order_delivered_customer_date_key) 
		references DimDate(datekey),
	constraint fkFact_Orders_order_estimated_delivery_date_key foreign key (order_estimated_delivery_date_key) 
		references DimDate(datekey)
)
go

 -- Bang Fact Order Payments
create table Fact_Order_payments (
	order_payment_key int IDENTITY not null,
	
	order_key int not null,
	--order_id nvarchar primary key,
	payment_sequential int,
	payment_type nvarchar(50),
	payment_installments int,
	payment_value float

	constraint pkOrder_payments primary key (order_payment_key),
	constraint fkFact_Order_payments_Fact_Orders foreign key (order_key) 
		references Fact_Orders(order_key)
)
go

-- Bang Fact Order Review

create table Fact_Order_reviews (
	review_key int IDENTITY not null,

	order_key int not null,
	--attributes
	review_id varchar(50),
	--order_id nvarchar,
	review_score tinyint,
	review_comment_title nvarchar(255),
	review_comment_message nvarchar(255),
	review_creation_date_key int not null,
	review_answer_timestamp_key int not null,

	constraint pkOrder_reviews primary key (review_key),
	constraint fkFact_Order_reviews_order_key foreign key (order_key) 
		references Fact_Orders(order_key),
	constraint fkFact_Order_reviews_review_creation_date_key foreign key (review_creation_date_key) 
		references DimDate(datekey),
	constraint fkFact_Order_reviews_order_review_answer_timestamp_key foreign key (review_answer_timestamp_key) 
		references DimDate(datekey)
)
go



-- Bang Fact Order Items
create table Fact_Order_items (
	order_item_key int IDENTITY not null, 

	product_key int not null,
	seller_key int not null,
	shipping_limit_date_key int not null,
	--attributes
	order_id varchar(50),
	order_item_id int,
	--product_id varchar,
	--seller_id varchar,
	--shipping_limit_date datetime, 
	price float,
	freight_value float,

	constraint pkOrder_items primary key (order_item_key),
	constraint fkFact_Order_items_product_key foreign key (product_key) 
		references DimProducts(product_key),
	constraint fkFact_Order_items_seller_key foreign key (seller_key) 
		references DimSellers(seller_key),
	constraint fkFact_Order_items_shipping_limit_date_key foreign key (shipping_limit_date_key) 
		references DimDate(datekey)
)
go

-- Chèn các giá trị Unknown vào các bảng Dim để không xung đột Khóa Ngoại

-- Unknown Date Value
SET IDENTITY_INSERT [DimDate] ON
go
INSERT INTO [DimDate]
           ([DateKey]
           ,[Date]
           ,[DayOfWeek]
           ,[DayName]
           ,[DayOfMonth]
           ,[DayOfYear]
           ,[WeekOfYear]
           ,[MonthName]
           ,[MonthOfYear]
           ,[Quarter]
		   ,[QuarterName]
           ,[Year]
           ,[IsAWeekday])
     VALUES
           (-1
           ,null
           ,0
           ,'Unknown'
           ,0
           ,0
           ,0
           ,'Unknown'
           ,0
           ,0
		   ,'Unknown'
           ,0
           ,'?')
GO
SET IDENTITY_INSERT [DimDate] OFF
go
-- Unknown Location
SET IDENTITY_INSERT [DimGeolocation] ON
go

Insert into DimGeolocation
	(geolocation_key,
	geolocation_zip_code_prefix,
	--geolocation_lat,
	--geolocation_lng,
	geolocation_city,
	geolocation_state)
	values
		(-1
		,'Unknown'
		-- ,-1
		-- ,-1
		,'Unknown'
		,'Unknown'
		)
SET IDENTITY_INSERT [DimGeolocation] OFF
go

-- Unknown Customer
SET IDENTITY_INSERT [DimCustomers] ON
go
INSERT INTO [DimCustomers]
           (customer_key,
			geolocation_key,
			customer_id,
			customer_unique_id)
     VALUES
           (-1
		   ,-1
           ,'Unknown Customer'
           ,'Unknown Customer'
           )
GO
SET IDENTITY_INSERT [DimCustomers] OFF
go

-- Unknown Product
SET IDENTITY_INSERT [DimProducts] ON
GO
INSERT INTO [DimProducts]
           (product_key
		   ,product_id
		   ,product_category_name
		   ,product_name_lenght
		   ,product_height_cm
		   ,product_length_cm
		   ,product_weight_g
		   ,product_photos_qty
		   ,product_description_lenght)
     VALUES
           (-1
		   ,'Unknown'
           ,'Unknown'
           ,-1
           ,-1
           ,-1
		   ,-1
		   ,-1
		   ,-1)
GO
SET IDENTITY_INSERT [DimProducts] OFF
GO

-- Unknown Sellers
SET IDENTITY_INSERT [DimSellers] ON
GO
insert into DimSellers
	(seller_key,
	geolocation_key,
	seller_id
	)
	values (
		-1,
		-1,
		'Unknown'
		)

SET IDENTITY_INSERT [DimSellers] OFF
GO