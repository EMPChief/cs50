# CS50x 2024 - Lecture 7 - SQL

## Introduction

- Overview of the lecture on SQL (Structured Query Language)
- Importance of databases in modern computing
- Brief history of SQL and its role in data management

## Flat-file Databases

- Definition of flat-file databases
- Characteristics of flat-file databases:
  - Single table structure
  - No relationships between data elements
  - Often stored as text files (e.g., CSV, TSV)
- Advantages of flat-file databases:
  - Simplicity
  - Easy to understand and create
  - Suitable for small datasets
- Limitations of flat-file databases:
  - Data redundancy
  - Difficulty in representing complex relationships
  - Limited scalability
- Examples of flat-file database usage
- Transition from flat-file to more complex database systems

## Relational Databases

- Introduction to relational database management systems (RDBMS)
- Key concepts of relational databases:
  - Tables (relations)
  - Rows (tuples or records)
  - Columns (attributes or fields)
- Advantages of relational databases:
  - Efficient data storage and retrieval
  - Support for complex queries
  - Data integrity and consistency
  - Scalability
- Popular relational database management systems:
  - MySQL
  - PostgreSQL
  - SQLite
  - Oracle
  - Microsoft SQL Server
- Basic principles of database design:
  - Normalization
  - Relationships between tables (one-to-one, one-to-many, many-to-many)

## Halloween Costume Contest

- Brief interlude or example related to a Halloween costume contest
- Possible demonstration of using a database to store contest information

## Shows

- Example database scenario using TV shows or movies
- Demonstration of how to structure data about shows in a relational database

## Schema

- Definition of database schema
- Components of a schema:
  - Table definitions
  - Column specifications
  - Constraints
  - Relationships between tables
- Importance of proper schema design
- Examples of schema creation in SQL:
  - CREATE TABLE statements
  - ALTER TABLE for modifying existing schemas
- Best practices for schema design:
  - Choosing appropriate names for tables and columns
  - Defining relationships clearly
  - Planning for future scalability

## Data Types and Constraints

- Common SQL data types:
  - INTEGER, BIGINT
  - FLOAT, DOUBLE, DECIMAL
  - CHAR, VARCHAR, TEXT
  - DATE, TIME, DATETIME, TIMESTAMP
  - BOOLEAN
  - BLOB (Binary Large Object)
- Constraints in SQL:
  - NOT NULL
  - UNIQUE
  - CHECK
  - DEFAULT
- Importance of choosing appropriate data types and constraints
- Examples of defining data types and constraints in CREATE TABLE statements

## Primary and Foreign Keys

- Definition and purpose of primary keys
  - Uniquely identifying records in a table
  - Ensuring data integrity
- Characteristics of good primary keys
- Auto-incrementing primary keys
- Foreign keys and their role in establishing relationships between tables
- Referential integrity and its importance
- Examples of defining primary and foreign keys in SQL

## Querying

- Introduction to SQL queries
- Basic query structure: SELECT, FROM, WHERE
- Retrieving data from single tables
- Joining tables:
  - INNER JOIN
  - LEFT JOIN
  - RIGHT JOIN
  - FULL OUTER JOIN
- Filtering data with WHERE clause
- Sorting results with ORDER BY
- Grouping data with GROUP BY
- Aggregate functions:
  - COUNT()
  - SUM()
  - AVG()
  - MIN()
  - MAX()
- Subqueries and nested queries
- Complex query examples and best practices

## Indexes

- Purpose and benefits of database indexes
- How indexes improve query performance
- Types of indexes:
  - B-tree indexes
  - Hash indexes
  - Full-text indexes
- Creating indexes in SQL:
  - CREATE INDEX statement
- When to use indexes (and when not to)
- Impact of indexes on insert, update, and delete operations
- Best practices for index design and management

## Python and SQL

- Integrating SQL databases with Python applications
- Popular Python libraries for database interaction:
  - sqlite3 for SQLite databases
  - mysql-connector-python for MySQL
  - psycopg2 for PostgreSQL
- Basic steps for connecting to a database from Python
- Executing SQL queries in Python
- Handling query results
- Using parameterized queries to prevent SQL injection
- Example Python script demonstrating database operations

## Race Conditions

- Definition of race conditions in database operations
- Scenarios where race conditions can occur
- Consequences of race conditions:
  - Data inconsistency
  - Lost updates
- Preventing race conditions:
  - Transactions
  - Locking mechanisms (pessimistic vs. optimistic locking)
  - ACID properties (Atomicity, Consistency, Isolation, Durability)
- Examples of implementing safeguards against race conditions in SQL and application code

## SQL injection attacks

- Definition and explanation of SQL injection attacks
- How SQL injection vulnerabilities occur
- Examples of SQL injection attacks
- Consequences of successful SQL injection attacks:
  - Unauthorized data access
  - Data manipulation or destruction
  - Bypassing authentication
- Preventing SQL injection:
  - Use of parameterized queries
  - Input validation and sanitization
  - Principle of least privilege for database users
  - Regular security audits and updates
- Best practices for writing secure SQL code
- Importance of ongoing education and awareness about security threats