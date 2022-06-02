# Write your MySQL query statement below

# Table: SalesPerson
# Table: Company
# Table: Orders

# Write an SQL query to report the names of all the salespersons who
# did not have any orders related to the company with the name "RED".

# find name of each SalesPerson that does not order from RED
SELECT
        name
    FROM
        SalesPerson
    WHERE
        (
            sales_id NOT IN
                (
                    # find sales_id for each orders from RED
                    SELECT
                            sales_id
                        FROM
                            Orders
                        WHERE
                            (com_id IN
                                (
                                    # find all IDs for companies named RED
                                    SELECT
                                            com_id
                                        FROM Company
                                        WHERE
                                            (name = 'RED')
                                )
                            )
                )
        )
;
