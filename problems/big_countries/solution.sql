# Write your MySQL query statement below

# search for big countries
SELECT name, population, area
    FROM World
    WHERE (area >= 3000000)
        OR (population >= 25000000)
;