# Write your MySQL query statement below

# Table: Employees
# Table: Salaries

# employee_id is the primary key for this table.

# Report the IDs of all the employees with missing information.
# * The employee's name is missing, or
# * The employee's salary is missing.

# Return the result table ordered by employee_id in ascending order.

SELECT
        employee_id
    FROM
        # create a union of both sided joins
        (
                SELECT
                        # on left join, Salary may be NULL
                        Employees.employee_id,
                        Employees.name,
                        Salaries.salary
                    FROM
                        Employees
                        LEFT JOIN Salaries
                        ON Employees.employee_id = Salaries.employee_id
            # merge duplicates
            UNION
                SELECT
                        # on right join, Employee may be NULL
                        Salaries.employee_id,
                        Employees.name,
                        Salaries.salary
                    FROM
                        Employees
                        RIGHT JOIN Salaries
                        ON Employees.employee_id = Salaries.employee_id
        ) As EmployeesWithSalaries
    # report any employees with missing information
    WHERE
        (name IS NULL)
        OR (salary IS NULL)
    # Return the result table ordered by employee_id in ascending order.
    ORDER BY employee_id
;