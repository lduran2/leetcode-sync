# Write your MySQL query statement below

# Table: Activities
# There is no primary key for this table, it may contain duplicates.

# Write an SQL query to find for each date the number of different
# products sold and their names.

# The sold products names for each date should be sorted
# lexicographically.

# Return the result table ordered by sell_date.

SELECT
        sell_date,
        # count the number of DISTINCT products sold that day
        count(DISTINCT product) AS num_sold,
        # group DISTINCT products, concatenate and order by product
        group_concat(DISTINCT product ORDER BY product) AS products
    FROM
        Activities
    # group all entries of same sell date
    GROUP BY sell_date
    ORDER BY sell_date
;