# Write your MySQL query statement below

# Table: Products
# product_id is the primary key for this table.

# Rearrange the Products table so that each row has
# (product_id, store, price). If a product is not available in a store,
# do not include a row with that product_id and store combination in
# the result table.

# select only rows with prices for that product and store
SELECT
        *
    FROM
    (
        # create a row for each product-store pair with its price
        SELECT
            product_id,
            store,
            # depending on the store, use that price
            (
                CASE
                    WHEN (store = 'store1') THEN store1
                    WHEN (store = 'store2') THEN store2
                    WHEN (store = 'store3') THEN store3
                    ELSE NULL
                END
            ) AS price
        FROM
            # for each product create a row for each store, by calculating the
            # cross product with set { 'store': {'store1', 'store2', 'store3'} }
            # this creates the store column
            Products
            CROSS JOIN
            (
                    SELECT 'store1' AS store
                        FROM DUAL
                UNION
                    SELECT 'store2'
                        FROM DUAL
                UNION
                    SELECT 'store3'
                        FROM DUAL
            ) AS StoreFactor
    ) AS ProductCrossStores
    # if no price if that store, skip it
    WHERE
        price IS NOT NULL
;