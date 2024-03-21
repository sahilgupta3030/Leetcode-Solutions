# Write your MySQL query statement below

select visited_on, amount, average_amount
from
(select visited_on,
       round(sum(sum(amount)) over(rows between 6 preceding and current row), 2) as amount,
       round(avg(sum(amount)) over(rows between 6 preceding and current row), 2) as average_amount,
       row_number() over() new
from customer
group by visited_on
order by visited_on) new_tb
where new >=7