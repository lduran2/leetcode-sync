# Write your MySQL query statement below

# Table: Views

# Find all the authors that viewed at least one of their own articles.
SELECT DISTINCT author_id AS id
    FROM
        Views
    WHERE author_id = viewer_id
    ORDER BY author_id
;