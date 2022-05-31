# Write your MySQL query statement below

# Table: Tree

# id is the primary key column for this table.
# Each row of this table contains information about the id of a node
# and the id of its parent node in a tree.

# Each node in the tree can be one of three types:
    # "Leaf": if the node is a leaf node.
    # "Root": if the node is the root of the tree.
    # "Inner": If the node is neither a leaf node nor a root node.

# Write an SQL query to report the type of each node in the tree.

# Return the result table ordered by id in ascending order.

SELECT
        id,
        (
            CASE
                # Root will nave NULL parent
                WHEN p_id IS NULL
                    THEN "Root"
                # any remaining node that is a parent is Inner
                WHEN (id IN
                    (SELECT p_id FROM Tree)
                ) THEN "Inner"
                # if the node is not a parent, then it is a Leaf
                ELSE "Leaf"
            END
        ) AS type
    FROM Tree
    ORDER BY id
;