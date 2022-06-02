# Write your MySQL query statement below

# Table: DailySales

# For each date_id and make_name, return the number of distinct
# lead_id's and distinct partner_id's.

SELECT
        date_id,
        make_name,
        count(DISTINCT lead_id) AS unique_leads,
        count(DISTINCT partner_id) AS unique_partners
    From DailySales
    GROUP BY
        date_id,
        make_name
;