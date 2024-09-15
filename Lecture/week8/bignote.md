# CS50x 2024 - Lecture 7 - SQL

## Introduction
- **Overview**: Introduction to SQL (Structured Query Language), essential for managing and manipulating databases.
- **Importance**: Databases are crucial for storing, retrieving, and managing data in modern computing environments.
- **Brief History**: SQL has evolved from early data management systems to become the standard language for relational databases.

## Flat-file Databases
- **Definition**: Databases with a single table structure, lacking relationships between data elements.
- **Characteristics**:
  - Often stored as text files, such as CSV (Comma-Separated Values) or TSV (Tab-Separated Values).
  - Simplicity and ease of use for small-scale data management.
- **Advantages**:
  - Straightforward setup and understanding.
  - Ideal for small datasets where complex queries and relationships are unnecessary.
- **Limitations**:
  - Data redundancy: Duplication of data leads to inefficiency.
  - Limited ability to represent complex relationships.
  - Scalability issues as data grows.
- **Examples**: Used in simple applications where relational databases are not required.
- **Transition**: Moving to relational databases allows for better management of complex relationships and larger datasets.

## Relational Databases
- **Introduction**: Relational Database Management Systems (RDBMS) use tables to represent data and relationships.
- **Key Concepts**:
  - **Tables (Relations)**: Structures that hold data in rows and columns.
  - **Rows (Tuples or Records)**: Individual entries within a table.
  - **Columns (Attributes or Fields)**: Define the type of data stored in each column of a table.
- **Advantages**:
  - **Efficient Data Storage and Retrieval**: Optimized for querying and managing data.
  - **Complex Queries**: Support for joining tables and querying across multiple tables.
  - **Data Integrity and Consistency**: Enforced through constraints and relationships.
  - **Scalability**: Can handle large volumes of data and complex queries.
- **Popular RDBMS**:
  - **MySQL**: Widely used open-source database.
  - **PostgreSQL**: Advanced open-source database with extensive features.
  - **SQLite**: Lightweight, serverless database.
  - **Oracle**: Enterprise-level database with robust features.
  - **Microsoft SQL Server**: A comprehensive database system from Microsoft.
- **Basic Principles of Database Design**:
  - **Normalization**: Process of organizing data to reduce redundancy and improve data integrity.
  - **Relationships**: Defines how tables interact (one-to-one, one-to-many, many-to-many).

## Shows
- **Example Database Scenario**: Structure of a database for managing TV shows or movies.
- **Data Structuring**: Includes tables for shows, episodes, actors, and genres with appropriate relationships.

## Schema
- **Definition**: Blueprint of a database that outlines how data is organized.
- **Components**:
  - **Table Definitions**: Specifications of each table's structure.
  - **Column Specifications**: Details of each column, including data types and constraints.
  - **Constraints**: Rules to maintain data integrity (e.g., primary keys, foreign keys).
  - **Relationships**: How tables are connected.
- **Importance**: A well-designed schema is crucial for efficient data management and integrity.
- **Examples**:
  - **CREATE TABLE Statements**: Defines new tables.
  - **ALTER TABLE**: Modifies existing tables (e.g., adding new columns).
- **Best Practices**:
  - Use clear and descriptive names for tables and columns.
  - Define relationships clearly to maintain data integrity.
  - Plan for scalability to accommodate future growth.

## Data Types and Constraints
- **Common SQL Data Types**:
  - **INTEGER, BIGINT**: Numeric types for whole numbers.
  - **FLOAT, DOUBLE, DECIMAL**: Numeric types for floating-point numbers.
  - **CHAR, VARCHAR, TEXT**: Types for text data of varying lengths.
  - **DATE, TIME, DATETIME, TIMESTAMP**: Types for date and time data.
  - **BOOLEAN**: Type for true/false values.
  - **BLOB**: Binary Large Object for storing binary data.
- **Constraints**:
  - **NOT NULL**: Ensures a column cannot have NULL values.
  - **UNIQUE**: Ensures all values in a column are unique.
  - **CHECK**: Defines a condition that must be met for data validity.
  - **DEFAULT**: Provides a default value for a column when no value is specified.
- **Importance**: Selecting appropriate data types and constraints is essential for accurate data representation and integrity.
- **Examples**: Defining data types and constraints in CREATE TABLE statements.

## Primary and Foreign Keys
- **Primary Keys**:
  - **Definition**: A unique identifier for each record in a table.
  - **Purpose**: Ensures each record is unique and facilitates efficient querying.
- **Characteristics**:
  - Should be unique and not NULL.
  - Auto-incrementing primary keys are often used for simplicity.
- **Foreign Keys**:
  - **Role**: Establishes relationships between tables.
  - **Referential Integrity**: Ensures that relationships between tables are maintained correctly.
- **Examples**: Defining primary and foreign keys in SQL to establish and enforce relationships.

## Querying
- **Introduction**: Using SQL to retrieve and manipulate data in a database.
- **Basic Query Structure**:
  - **SELECT**: Specifies the columns to retrieve.
  - **FROM**: Indicates the table(s) from which to retrieve data.
  - **WHERE**: Filters results based on specified conditions.
- **Retrieving Data**: Basic SELECT queries from single tables.
- **Joining Tables**:
  - **INNER JOIN**: Retrieves records with matching values in both tables.
  - **LEFT JOIN**: Retrieves all records from the left table, and matched records from the right table.
  - **RIGHT JOIN**: Retrieves all records from the right table, and matched records from the left table.
  - **FULL OUTER JOIN**: Retrieves all records when there is a match in one of the tables.
- **Filtering Data**: Using the WHERE clause to specify conditions.
- **Sorting Results**: Using ORDER BY to sort data.
- **Grouping Data**: Using GROUP BY to aggregate data based on specified columns.
- **Aggregate Functions**:
  - **COUNT()**: Counts the number of rows.
  - **SUM()**: Calculates the total sum of a numeric column.
  - **AVG()**: Calculates the average value of a numeric column.
  - **MIN()**: Finds the minimum value in a column.
  - **MAX()**: Finds the maximum value in a column.
- **Subqueries and Nested Queries**: Queries within queries for more complex data retrieval.
- **Complex Query Examples**: Advanced SQL queries and best practices for efficient data manipulation.

## Indexes
- **Purpose and Benefits**: Improve performance of data retrieval operations.
- **Types of Indexes**:
  - **B-tree Indexes**: Balanced tree structures for efficient querying.
  - **Hash Indexes**: Fast lookups using hash tables.
  - **Full-text Indexes**: Optimized for searching large text fields.
- **Creating Indexes**: Using the CREATE INDEX statement to define indexes.
- **When to Use Indexes**: Benefits and considerations for choosing when to index.
- **Impact**: On insert, update, and delete operations.
- **Best Practices**:
  - Design indexes to support common query patterns.
  - Avoid over-indexing, which can impact performance.

## Python and SQL
- **Integrating SQL with Python**:
  - **Libraries**:
    - **sqlite3**: For SQLite databases.
    - **mysql-connector-python**: For MySQL databases.
    - **psycopg2**: For PostgreSQL databases.
- **Basic Steps**:
  - **Connecting**: Establishing a connection to the database.
  - **Executing Queries**: Running SQL commands from Python.
  - **Handling Results**: Processing query results.
  - **Parameterized Queries**: Using placeholders to prevent SQL injection.
- **Example**: Python script for basic database operations.

## Race Conditions
- **Definition**: Occur when multiple database operations conflict, leading to unpredictable results.
- **Scenarios**: Where race conditions might occur, such as concurrent transactions.
- **Consequences**:
  - **Data Inconsistency**: Conflicting changes lead to inconsistent data.
  - **Lost Updates**: Some updates may be overwritten.
- **Preventing Race Conditions**:
  - **Transactions**: Grouping operations to ensure atomicity.
  - **Locking Mechanisms**: Using locks to manage concurrent access (pessimistic vs. optimistic).
  - **ACID Properties**: Ensuring transactions are Atomic, Consistent, Isolated, and Durable.
- **Examples**: Implementing safeguards against race conditions.

## SQL Injection Attacks
- **Definition**: SQL injection is a vulnerability where attackers manipulate a query by injecting malicious SQL code.
  
### How SQL Injection Vulnerabilities Occur:
- **Unsanitized Input**: Allowing user inputs in queries without validation or escaping.
- **Dynamic SQL Queries**: Constructing queries by concatenating strings, leading to code injection.

### Consequences of SQL Injection:
- **Unauthorized Access**: Attackers can gain access to sensitive data.
- **Data Manipulation**: Inserting, updating, or deleting records.
- **Authentication Bypass**: Gaining access without proper credentials.
- **Destruction of Data**: Deleting or corrupting important data.

### Preventing SQL Injection:
- **Parameterized Queries**: Using placeholders for input values.
- **Stored Procedures**: Predefined SQL code with fixed structure.
- **Input Validation and Sanitization**: Ensuring all input data is clean.
- **Principle of Least Privilege**: Minimizing access rights for database users.
- **Security Audits and Updates**: Regularly checking for vulnerabilities and updating software.

### Best Practices for Secure SQL Code:
- Avoid constructing SQL queries using string concatenation.
- Use prepared statements and parameterized queries in all cases.
- Implement thorough input validation for all user data.
- Conduct regular penetration testing to identify potential injection points.
- Continuously educate developers on secure coding practices and threats.

## Begin Transactions, Rollback, Commit
- **Transactions in SQL**: A transaction is a sequence of database operations that are executed as a single unit, ensuring data integrity and consistency.

### Key Commands:
- **BEGIN TRANSACTION**: Initiates a new transaction. All subsequent operations are part of this transaction until it is either committed or rolled back.
- **ROLLBACK**: Reverts the database to the state before the transaction started, discarding all operations within the transaction.
- **COMMIT**: Permanently applies all changes made during the transaction to the database.

### Benefits of Transactions:
- **Atomicity**: Ensures that all operations within a transaction are completed successfully or none at all.
- **Consistency**: Ensures the database remains in a valid state before and after the transaction.
- **Isolation**: Prevents other operations from seeing intermediate states during the transaction.
- **Durability**: Guarantees that committed changes are saved even if the system crashes.

### Use Cases:
- **Data Integrity**: For operations involving multiple tables, a transaction ensures that all related changes are applied consistently.
- **Error Recovery**: If an error occurs during a transaction, rolling back undoes all changes, avoiding partial updates.
- **Multi-Step Operations**: For complex operations like transferring funds between bank accounts, transactions ensure that both debit and credit operations are applied or neither.

### Best Practices:
- **Keep Transactions Short**: Minimize the time a transaction is open to reduce the likelihood of contention and deadlocks.
- **Error Handling**: Always include error handling mechanisms to manage potential rollback scenarios.
- **Use for Critical Operations**: Employ transactions when operations must be completed together, such as financial transfers or inventory updates.
