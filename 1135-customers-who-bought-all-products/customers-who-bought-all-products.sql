# Write your MySQL query statement below


SELECT customer_id
FROM   customer
GROUP  BY customer_id
HAVING Count(DISTINCT product_key) = (SELECT
       Count(DISTINCT product_key) AS totl_prdct
                                      FROM   product) 