# Write your MySQL query statement below

SELECT tweet_id
FROM Tweets
WHERE CHAR_LENGTH(content) > 15;

-- LENGTH 
-- that counts actual length including symbols and spaces