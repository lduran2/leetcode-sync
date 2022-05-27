# Write your MySQL query statement below

SELECT name
    FROM Customer
    WHERE (coalesce(referee_id, -1) <> 2)
;