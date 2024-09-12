--câu 1: Thống kê doanh thu theo khu vực
select a.geolocation_state, sum(p.price) as Total_Price,d.Year 
  from [Dim_Geolocation] as a
  join [Dim_Customer] as c on a.geolocation_key = c.geolocation_key
  join [Fact_Order] as o on o.customer_key = c.customer_key
  join [Fact_Order_Items] as p on o.order_key = p.order_key
  join [Dim_Date] as d on d.datekey = o.order_purchase_timestamp_key 
  group by a.geolocation_state, d.Year
  order by a.geolocation_state asc, d.Year asc

-- câu 2: Thống kê doanh thu theo ngày, tháng
select sum(a.price) as Total_price, d.MonthOfYear,d.Year
	from [Fact_Order_Items] as a
	join [Fact_Order] as o on a.order_id=o.order_id
	join [Dim_Date] as d on d.datekey = o.order_purchase_timestamp_key
	group by d.Year, d.MonthOfYear
	order by d.Year asc, d.MonthOfYear asc
-- câu 3: Thống kê số điểm đánh giá thông qua các order
select review_score, count(review_score) as number_of_votes 
	from [Fact_Review]
	group by review_score
	order by review_score
-- câu 4: Thống kê sản phẩm bán chạy
select top(10) p.product_category_name, count(i.product_key) as Quantity
	from [Dim_Product] as p
	join [Fact_Order_Items] as i on p.product_key=i.product_key
	group by p.product_category_name
	order by count(i.product_key) desc
-- câu 5: Thống kê tổng tiền thông qua các hình thức thanh toán
select distinct(payment_type),sum(payment_value) as payment_value
	from Fact_Payment 
	group by payment_type
