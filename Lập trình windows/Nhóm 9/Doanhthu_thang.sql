Create function Doanhthu_thang
(
	@year int 
)
returns table as return
select Item.item_id, item_name,tong,(item_price_out*Tong) as doanhthu
from Item,(select item_id,sum(quantity) as tong
		from Lineitem,Orders
		where year(order_date) = @year and Lineitem.order_id=Orders.order_id
		group by item_id) as dt_thang
where Item.item_id=dt_thang.item_id