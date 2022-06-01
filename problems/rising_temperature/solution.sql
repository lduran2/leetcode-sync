# Write your MySQL query statement below

# Table: Weather

# Find all dates' Id with higher temperatures compared to its previous
# dates (yesterday).

# In the demo, it's the case that
#   forall a, b in Weather,
#       (a.recordDate > b.recordDate) <=> (a.id > b.id).
# However, that is not always the case.

SELECT
        Today.id
    FROM
        # join with current and previous dates' temperature
        Weather AS Today
        LEFT JOIN Weather AS Yesterday
        # using recordDate to compare dates
        ON DATEDIFF(Today.recordDate, Yesterday.recordDate) = 1
    # choose when today's temperature is higher than yesterday's
    WHERE
        (Today.temperature > Yesterday.temperature)
;