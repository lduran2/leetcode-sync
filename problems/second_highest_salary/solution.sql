# Write your MySQL query statement below

# Table: Employee

# Report the second highest salary from the Employee table
SELECT
    # if empty, return NULL
    IFNULL((
        # ignore duplicates
        SELECT DISTINCT salary
            FROM Employee
            # order the salaries in descending order
            ORDER BY -salary
            # starting with 2nd row, select 1 row
            LIMIT 1,1
    ), NULL) AS SecondHighestSalary
;