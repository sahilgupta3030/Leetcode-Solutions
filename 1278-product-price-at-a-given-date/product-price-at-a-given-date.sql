select product_id, ifnull(max(b.new_price),10) price
from Products a left join 
(
    select *, rank() over (partition by product_id order by change_date desc) rk
    from Products
    where change_date <= '2019-08-16'
) b using(product_id) 
where rk=1 or rk is null
group by 1