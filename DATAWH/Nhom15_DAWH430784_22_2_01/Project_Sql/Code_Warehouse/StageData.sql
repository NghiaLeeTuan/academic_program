-- Cơ sở dữ liệu StageData chứ dữ liệu Stage
create database StageData
go
use StageData
go

-- Stage Geolocation

	--code này bỏ
	--select 
	--	geolocation_zip_code_prefix,
	--	geolocation_lat,
	--	geolocation_lng,
	--	geolocation_city,
	--	geolocation_state
	--into dbo.DA_StageGeolocation
	--from BrzShopDW.dbo.olist_geolocation_dataset
	--go

create or alter function laChuoiThuong(@chuoi nvarchar(50)) returns int
	begin
		declare @flag int
		set @chuoi = REPLACE(@chuoi,' ','') 
		while (Unicode(@chuoi) BETWEEN 97 and 122)
			set @chuoi = SUBSTRING(@chuoi,2,LEN(@chuoi)-1)
		if LEN(@chuoi) = 0
			set @flag = 0
		else 
			set @flag = 1
		return @flag
	end;
go

select 
	distinct geolocation_zip_code_prefix, geolocation_city, geolocation_state 
into dbo.DA_StageGeolocation
	from BrzShopDW.dbo.olist_geolocation_dataset
	where dbo.laChuoiThuong(geolocation_city) = 0
order by geolocation_zip_code_prefix
go

-- Stage Date
select *
into [dbo].[DA_StageDate]
from [Temp].[dbo].[Date_Dimension]
where year between 2016 and 2020
go
	
-- Stage Customer
select
	customer_id,
	customer_unique_id,
	customer_zip_code_prefix
into dbo.DA_StageCustomer
from BrzShopDW.dbo.olist_customers_dataset
go

-- Stage Seller
select 
	seller_id,
	seller_zip_code_prefix
into dbo.DA_StageSeller
from BrzShopDW.dbo.olist_sellers_dataset
go

-- Stage Product
select 
	product_id, 
	product_category_name,

	product_name_lenght,
	product_description_lenght,
	product_photos_qty,
	product_weight_g,
	product_length_cm,
	product_height_cm,
	product_width_cm
	
into dbo.DA_StageProduct
from BrzShopDW.dbo.olist_products_dataset
go

--select * 
--	from BrzShopDW.dbo.olist_products_dataset, BrzShopDW.dbo.product_category_name_translation 
--	where BrzShopDW.dbo.olist_products_dataset.product_category_name = BrzShopDW.dbo.product_category_name_translation

-- Stage order_payment 
select 
	order_id,
	payment_sequential,
	payment_type,
	payment_installments,
	payment_value
into dbo.DA_StageOrder_payment
from BrzShopDW.dbo.olist_order_payments_dataset
go

-- Stage Order_review
select
	review_id, 
	order_id,
	review_score,
	review_comment_title,
	review_comment_message,
	review_creation_date,
	review_answer_timestamp
into dbo.DA_StageOrder_review
from BrzShopDW.dbo.olist_order_reviews_dataset
go


-- Stage Orders
select 
	order_id,
	customer_id,
	order_status,
	order_purchase_timestamp,
	order_approved_at,
	order_delivered_carrier_date,
	order_delivered_customer_date,
	order_estimated_delivery_date
into dbo.DA_StageOrders
from BrzShopDW.dbo.olist_orders_dataset
go

-- Stage order_items
select 
	order_id,
	order_item_id,
	product_id,
	seller_id,
	shipping_limit_date,
	price,
	freight_value
into dbo.DA_StageOrder_items
from BrzShopDW.dbo.olist_order_items_dataset
go

-- Load Data to DataWareHouse

	use DA_DATAWH
	go

-- Load DimDate
SET IDENTITY_INSERT [DimDate] ON
go

	insert into DA_DATAWH.dbo.DimDate
	(datekey, Date, DayOfWeek, DayName, DayOfMonth, DayOfYear,
	WeekOfYear, MonthName, MonthOfYear, Quarter, QuarterName, Year, IsAWeekday)
	select
	date_key, full_date, day_of_week, day_name, day_num_in_month,
	day_num_overall, week_num_in_year, month_name, month, quarter,
	case 
		when month >= 1 and month <= 3 then 'First'
		when month >= 4 and month <= 6 then 'Second'
		when month >= 7 and month <= 9 then 'Third'
		when month >= 10 and month <= 12 then 'Fourth'
	end,
		year, weekday_flag
	from StageData.dbo.DA_StageDate
go

SET IDENTITY_INSERT [DimDate] OFF
go

-- Load Location
	--SET IDENTITY_INSERT [DimGeolocation] ON
	--go

insert into DA_DATAWH.dbo.DimGeolocation
	(geolocation_zip_code_prefix, geolocation_city, geolocation_state)
select
	geolocation_zip_code_prefix, geolocation_city, geolocation_state
from StageData.dbo.DA_StageGeolocation
go

	--SET IDENTITY_INSERT [DimGeolocation] OFF
	--go
-- Load DimProducts
	--SET IDENTITY_INSERT [DimProducts] ON
	--go

insert into DA_DATAWH.dbo.DimProducts
	(product_id, product_category_name, product_name_lenght, product_description_lenght, product_photos_qty, 
	product_weight_g, product_length_cm,product_height_cm,product_width_cm)
select
	product_id, product_category_name, product_name_lenght,product_description_lenght,product_photos_qty, product_weight_g,
	product_length_cm,product_height_cm,product_width_cm
from StageData.dbo.DA_StageProduct

	--SET IDENTITY_INSERT [DimProducts] OFF
	--go

-- Load Dim Seller
	--SET IDENTITY_INSERT [DimSellers] ON
	--go

	--DBCC CHECKIDENT ('DimSellers',RESEED,0)

insert into DA_DATAWH.dbo.DimSellers
	(geolocation_key,seller_id)
select geolocation_key, seller_id
	from StageData.dbo.DA_StageSeller a join DA_DATAWH.dbo.DimGeolocation b 
	on a.seller_zip_code_prefix = b.geolocation_zip_code_prefix  

	--SET IDENTITY_INSERT [DimSellers] OFF
	--go

--delete from DimSellers

-- Load Customers

	--SET IDENTITY_INSERT [DimCustomers] ON
	--go

	-- các câu lệnh để test ko chạy
	--delete from DimCustomers
	--DBCC CHECKIDENT ('DimCustomers',RESEED,0)

	insert into DA_DATAWH.dbo.DimCustomers
		(geolocation_key,customer_id,customer_unique_id)
	select geolocation_key, customer_id, customer_unique_id
		from StageData.dbo.DA_StageCustomer a join DA_DATAWH.dbo.DimGeolocation b
		on a.customer_zip_code_prefix = b.geolocation_zip_code_prefix
	go
	--SET IDENTITY_INSERT [DimCustomers] OFF
	--go



-- Load Facts Orders
	-- xem dữ liệu
	select 
		MIN(a.order_purchase_timestamp) as order_purchase_timestamp_mindate,
		MAX(a.order_purchase_timestamp) as order_purchase_timestamp_maxdate,
		MIN(a.order_approved_at) as order_approved_at_mindate,
		MAX(a.order_approved_at) as order_approved_at_maxdate,
		MIN(a.order_delivered_carrier_date) as order_delivered_carrier_date_mindate,
		MAX(a.order_delivered_carrier_date) as order_delivered_carrier_date_maxdate,
		MIN(a.order_delivered_customer_date) as order_delivered_customer_date_mindate,
		MAX(a.order_delivered_customer_date) as order_delivered_customer_date_maxdate,
		MIN(a.order_estimated_delivery_date) as order_estimated_delivery_date_mindate,
		MAX(a.order_estimated_delivery_date) as order_estimated_delivery_date_maxdate		
	from BrzShopDW.dbo.olist_orders_dataset a
	go

insert into DA_DATAWH.dbo.Fact_Orders
	(customer_key, order_purchase_timestamp_key, order_approved_at_key, order_delivered_carrier_date_key, order_delivered_customer_date_key,
	order_estimated_delivery_date_key,order_id,order_status)
	select a.customer_key,
	case when s.order_purchase_timestamp is null then -1
	else Day(s.order_purchase_timestamp) + MONTH(s.order_purchase_timestamp) * 100 + YEAR(s.order_purchase_timestamp) * 10000 
	end As order_purchase_timestamp_key,
	case when s.order_approved_at is null then -1
	else Day(s.order_approved_at) + MONTH(s.order_approved_at) * 100 + YEAR(s.order_approved_at) * 10000 
	end As order_approved_at_key,
	case when s.order_delivered_carrier_date is null then -1
	else Day(s.order_delivered_carrier_date) + MONTH(s.order_delivered_carrier_date) * 100 + YEAR(s.order_delivered_carrier_date) * 10000 
	end As order_delivered_carrier_date_key,
	case when s.order_delivered_customer_date is null then -1
	else Day(s.order_delivered_customer_date) + MONTH(s.order_delivered_customer_date) * 100 + YEAR(s.order_delivered_customer_date) * 10000 
	end As order_delivered_customer_date_key,
	case when s.order_estimated_delivery_date is null then -1
	else Day(s.order_estimated_delivery_date) + MONTH(s.order_estimated_delivery_date) * 100 + YEAR(s.order_estimated_delivery_date) * 10000 
	end As order_estimated_delivery_date_key,
	s.order_id,
	s.order_status
from StageData.dbo.DA_StageOrders s
	join DA_DATAWH.dbo.DimCustomers a
	on s.customer_id = a.customer_id
go
	
-- Load Facts Orders Items
	select 
		min(a.shipping_limit_date) as mindate,
		max(a.shipping_limit_date) as maxdate
	from BrzShopDW.dbo.olist_order_items_dataset a
	go

insert into DA_DATAWH.dbo.Fact_Order_items
	(product_key, seller_key, shipping_limit_date_key, order_id, order_item_id, price, freight_value)
select
	a.product_key,
	b.seller_key,
	case when s.shipping_limit_date is null then -1
	else Day(s.shipping_limit_date) + MONTH(s.shipping_limit_date) * 100 + YEAR(s.shipping_limit_date) * 10000 
	end As shipping_limit_date_key,
	s.order_id,
	s.order_item_id,
	s.price,
	s.freight_value
from StageData.dbo.DA_StageOrder_items s
	join DA_DATAWH.dbo.DimProducts a
		on s.product_id = a.product_id
	join DA_DATAWH.dbo.DimSellers b
		on s.seller_id = b.seller_id 
go

-- Load Facts Orders Review
	select 
		min(a.review_creation_date) as review_creation_date_min,
		max(a.review_creation_date) as review_creation_date_max,
		min(a.review_answer_timestamp) as review_answer_timestamp_min ,
		max(a.review_answer_timestamp) as review_answer_timestamp_max
	from BrzShopDW.dbo.olist_order_reviews_dataset a
	go

insert into DA_DATAWH.dbo.Fact_Order_reviews
	(order_key,review_id,review_score,review_comment_title,review_comment_message,review_creation_date_key,review_answer_timestamp_key)
select
	a.order_key,
	s.review_id,
	s.review_score,
	s.review_comment_title,
	s.review_comment_message,
	case when s.review_creation_date is null then -1
	else Day(s.review_creation_date) + MONTH(s.review_creation_date) * 100 + YEAR(s.review_creation_date) * 10000 
	end As review_creation_date_key,
	case when s.review_answer_timestamp is null then -1
	else Day(s.review_answer_timestamp) + MONTH(s.review_answer_timestamp) * 100 + YEAR(s.review_answer_timestamp) * 10000 
	end As review_answer_timestamp_key
from StageData.dbo.DA_StageOrder_review s
	join DA_DATAWH.dbo.Fact_Orders a
		on s.order_id = a.order_id
	

go	

-- Load Facts Orders Payments
insert into DA_DATAWH.dbo.Fact_Order_payments
	(order_key, payment_sequential, payment_type, payment_installments, payment_value)
select 
	a.order_key,
	s.payment_sequential,
	s.payment_type,
	s.payment_installments,
	s.payment_value
from StageData.dbo.DA_StageOrder_payment s
	join DA_DATAWH.dbo.Fact_Orders a
	on s.order_id = a.order_id
go

--
--
-- Test Data

-- các code sql để test dữ liệu thì code ở đây
--select distinct geolocation_zip_code_prefix , geolocation_city, geolocation_state from BrzShopDW.dbo.olist_geolocation_dataset
--select * from BrzShopDW.dbo.olist_geolocation_dataset
--select * from BrzShopDW.dbo.olist_geolocation_dataset
--go

--use StageData
--go

--select distinct customer_zip_code_prefix, customer_city 
--from BrzShopDW.dbo.olist_customers_dataset
--order by customer_zip_code_prefix
--go
--select distinct seller_zip_code_prefix, seller_city
--from BrzShopDW.dbo.olist_sellers_dataset
--go