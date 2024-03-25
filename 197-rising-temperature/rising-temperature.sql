-- SELECT w1.id AS Id
-- FROM Weather w1
-- INNER JOIN Weather w2
-- ON w1.recordDate - INTERVAL 1 DAY = w2.recordDate
-- WHERE w1.temperature > w2.temperature;








SELECT w1.id AS Id
FROM weather w1
INNER JOIN weather w2 
ON DATEDIFF(w1.recordDate, w2.recordDate) = 1
WHERE w1.temperature > w2.temperature;
