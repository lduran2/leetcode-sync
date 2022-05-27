# Write your MySQL query statement below

SELECT name AS Customers
    FROM Customers
        # join from customers to catch customers with no orders
        LEFT JOIN Orders
            ON (Customers.id = Orders.customerId)
    # no orders when orders.id == NULL
    WHERE (Orders.id IS NULL)
;