# Write your MySQL query statement below
select 
    sell_date, COUNT(DISTINCT product) num_sold, 
    group_concat(DISTINCT product) products 
from Activities
group by sell_date
order by sell_date