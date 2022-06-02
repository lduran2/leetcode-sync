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
            # sales ID must not match any Orders from Company RED
            sales_id NOT IN
                (
                    # find sales_id for each Orders from Company RED
                    SELECT
                            sales_id
                        FROM
                            Orders
                            LEFT JOIN
                                Company
                                # match Company ID to corresponding orders
                                ON Orders.com_id = Company.com_id
                        # for each Company named RED
                        WHERE
                            (name = 'RED')
                )
        )
;
