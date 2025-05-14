# Week 7: SQL and Databases

This document provides a comprehensive overview of Week 7 topics in CS50, covering SQL databases, queries, and database management.

## Table of Contents
1. [Introduction to Databases](#introduction-to-databases)
2. [SQL Basics](#sql-basics)
3. [Database Design](#database-design)
4. [Advanced Queries](#advanced-queries)
5. [SQL with Python](#sql-with-python)
6. [Best Practices](#best-practices)

## Introduction to Databases

### Why Databases?
- Structured data storage
- Data integrity
- Concurrent access
- Data relationships
- Efficient querying

### Types of Databases
- Relational (SQL)
- NoSQL
- Object-oriented
- Graph databases

## SQL Basics

### Creating Tables
```sql
CREATE TABLE students (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    house TEXT NOT NULL,
    year INTEGER NOT NULL
);
```

### Basic Operations (CRUD)

#### Create (INSERT)
```sql
INSERT INTO students (name, house, year)
VALUES ('Harry Potter', 'Gryffindor', 1);
```

#### Read (SELECT)
```sql
-- Basic select
SELECT * FROM students;

-- With conditions
SELECT name, house 
FROM students 
WHERE year = 1;
```

#### Update
```sql
UPDATE students 
SET year = 2 
WHERE name = 'Harry Potter';
```

#### Delete
```sql
DELETE FROM students 
WHERE name = 'Draco Malfoy';
```

## Database Design

### Primary Keys
- Unique identifier for each row
- Often auto-incrementing integer
- Can be composite (multiple columns)

### Foreign Keys
```sql
CREATE TABLE assignments (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    student_id INTEGER,
    assignment TEXT NOT NULL,
    grade INTEGER,
    FOREIGN KEY(student_id) REFERENCES students(id)
);
```

### Relationships
1. One-to-One
2. One-to-Many
3. Many-to-Many

Example of Many-to-Many:
```sql
CREATE TABLE students_courses (
    student_id INTEGER,
    course_id INTEGER,
    PRIMARY KEY(student_id, course_id),
    FOREIGN KEY(student_id) REFERENCES students(id),
    FOREIGN KEY(course_id) REFERENCES courses(id)
);
```

## Advanced Queries

### Joins
```sql
-- Inner Join
SELECT students.name, assignments.grade
FROM students
JOIN assignments ON students.id = assignments.student_id;

-- Left Join
SELECT students.name, houses.head
FROM students
LEFT JOIN houses ON students.house = houses.name;
```

### Aggregation
```sql
-- Count students per house
SELECT house, COUNT(*) as count
FROM students
GROUP BY house;

-- Average grades
SELECT students.name, AVG(assignments.grade) as average
FROM students
JOIN assignments ON students.id = assignments.student_id
GROUP BY students.id;
```

### Subqueries
```sql
-- Students with above average grades
SELECT name
FROM students
WHERE id IN (
    SELECT student_id
    FROM assignments
    GROUP BY student_id
    HAVING AVG(grade) > (
        SELECT AVG(grade) FROM assignments
    )
);
```

## SQL with Python

### Using SQLite3
```python
import sqlite3

def main():
    # Connect to database
    db = sqlite3.connect("hogwarts.db")
    cursor = db.cursor()
    
    # Query database
    cursor.execute("SELECT * FROM students WHERE house = ?", ("Gryffindor",))
    
    # Fetch results
    students = cursor.fetchall()
    
    # Print results
    for student in students:
        print(f"{student[1]} is in year {student[3]}")
    
    # Close database
    db.close()

if __name__ == "__main__":
    main()
```

### Using SQL Alchemy
```python
from sqlalchemy import create_engine, text

engine = create_engine('sqlite:///hogwarts.db')

with engine.connect() as conn:
    result = conn.execute(text("SELECT * FROM students"))
    for row in result:
        print(row)
```

## Best Practices

### Database Design
1. Normalize your data
2. Use appropriate data types
3. Include proper constraints
4. Document your schema
5. Plan for scaling

### Query Optimization
1. Use indexes appropriately
2. Avoid SELECT *
3. Use prepared statements
4. Optimize JOINs
5. Use EXPLAIN to analyze queries

### Security
1. Use parameterized queries
2. Implement proper access control
3. Regular backups
4. Input validation
5. Avoid SQL injection vulnerabilities

## Common SQL Commands

### Table Operations
```sql
-- Create table
CREATE TABLE table_name (
    column1 datatype,
    column2 datatype,
    ...
);

-- Modify table
ALTER TABLE table_name
ADD column_name datatype;

-- Delete table
DROP TABLE table_name;
```

### Data Operations
```sql
-- Insert multiple rows
INSERT INTO table_name (column1, column2)
VALUES 
    (value1, value2),
    (value3, value4);

-- Update with conditions
UPDATE table_name
SET column1 = value1
WHERE condition;

-- Delete with conditions
DELETE FROM table_name
WHERE condition;
```

## Additional Resources

- [CS50 SQL Notes](https://cs50.harvard.edu/x/2024/notes/7/)
- [SQLite Documentation](https://sqlite.org/docs.html)
- [SQL Style Guide](https://www.sqlstyle.guide/)
- [Database Design Tutorial](https://www.lucidchart.com/pages/database-diagram/database-design)
- [SQL Injection Prevention](https://cheatsheetseries.owasp.org/cheatsheets/SQL_Injection_Prevention_Cheat_Sheet.html) 