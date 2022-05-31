# Write your MySQL query statement below

# Table: Visits
# visit_id is the primary key for this table.

# Table: Transactions
# transaction_id is the primary key for this table.

# Find the IDs of the users who visited without making any transactions
# and the number of times they made these types of visits.


SELECT
        customer_id,
        # count every visit for this customer
        COUNT(Visits.visit_id) AS count_no_trans
    FROM
        # combine visits and transactions
        Visits
        LEFT JOIN Transactions
        ON Visits.visit_id = Transactions.visit_id
    WHERE
        # check for NULL transactions
        (transaction_id IS NULL)
    GROUP BY customer_id
;
