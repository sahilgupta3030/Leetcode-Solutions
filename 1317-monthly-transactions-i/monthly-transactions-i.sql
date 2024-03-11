# Write your MySQL query statement below

SELECT 
    left(trans_date,7) month,
    country,
    count(1) trans_count,
    sum(state='approved') approved_count,
    sum(amount) trans_total_amount,
    sum(if(state='approved',amount,0)) approved_total_amount
FROM Transactions
group by 1,2



