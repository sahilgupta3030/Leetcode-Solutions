SELECT ROUND((
    SELECT COUNT(DISTINCT a.player_id)
    FROM Activity a
    INNER JOIN (
        SELECT player_id, MIN(event_date) AS first_logged 
        FROM Activity 
        GROUP BY player_id
    ) b ON DATEDIFF(a.event_date, b.first_logged) = 1 AND a.player_id = b.player_id
) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2) AS fraction;