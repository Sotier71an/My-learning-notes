# MySQL介绍
---
## 关系型数据库RDBMS
---
RDBMS 即关系数据库管理系统(Relational Database Management System)的特点：
- 1.数据以表格的形式出现
- 2.每行为各种记录名称
- 3.每列为记录名称所对应的数据域
- 4.许多的行和列组成一张表单
- 5.若干的表单组成database


## RDBMS术语
---
- 数据库: 数据库是一些关联表的集合。
- 数据表: 表是数据的矩阵。在一个数据库中的表看起来像一个简单的电子表格。
- 列: 一列(数据元素) 包含了相同类型的数据, 例如邮政编码的数据。
- 行：一行（元组，或记录）是一组相关的数据，例如一条用户订阅的数据。
- 冗余：存储两倍数据，冗余降低了性能，但提高了数据的安全性。
- 主键：主键是唯一的。一个数据表中只能包含一个主键。你可以使用主键来查询数据。
- 外键：外键用于关联两个表。
- 复合键：复合键（组合键）将多个列作为一个索引键，一般用于复合索引。
- 索引：使用索引可快速访问数据库表中的特定信息。索引是对数据库表中一列或多列的值进行排序的一种结构。类似于书籍的目录。
- 参照完整性: 参照的完整性要求关系中不允许引用不存在的实体。与实体完整性是关系模型必须满足的完整性约束条件，目的是保证数据的一致性。



# MySQL数据库语法
---
## 创建数据库
```mysql
CREATE DATABASE IF NOT EXISTS <database_name>
  CHARACTER SET utf8mb4
  COLLATE ut8mb4_general_ci;
```

## 删除数据库
```mysql
DROP DATABASE IF EXITS <database_name>
```

## 选择数据库
```mysql
USE <database_name>
```
选择了数据库后，后续的SQL查询和操作就在这个数据库上执行。

# MySql数据类型
---
## 数值类型
MySQL 支持所有标准 SQL 数值数据类型。
这些类型包括严格数值数据类型(INTEGER、SMALLINT、DECIMAL 和 NUMERIC)，以及近似数值数据类型(FLOAT、REAL 和 DOUBLE PRECISION)。
关键字INT是INTEGER的同义词，关键字DEC是DECIMAL的同义词。
BIT数据类型保存位字段值，并且支持 MyISAM、MEMORY、InnoDB 和 BDB表。
作为 SQL 标准的扩展，MySQL 也支持整数类型 TINYINT、MEDIUMINT 和 BIGINT。下面的表显示了需要的每个整数类型的存储和范围。

| 类型          | 大小                              | 范围（有符号）                                                                                                                         | 范围（无符号）                                                         | 用途            |
| ----------- | ------------------------------- | ------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------- | ------------- |
| TINYINT     | 1 Bytes                         | (-128，127)                                                                                                                      | (0，255)                                                         | 小整数值          |
| SMALLINT    | 2 Bytes                         | (-32 768，32 767)                                                                                                                | (0，65 535)                                                      | 大整数值          |
| MEDIUMINT   | 3 Bytes                         | (-8 388 608，8 388 607)                                                                                                          | (0，16 777 215)                                                  | 大整数值          |
| INT或INTEGER | 4 Bytes                         | (-2 147 483 648，2 147 483 647)                                                                                                  | (0，4 294 967 295)                                               | 大整数值          |
| BIGINT      | 8 Bytes                         | (-9,223,372,036,854,775,808，9 223 372 036 854 775 807)                                                                          | (0，18 446 744 073 709 551 615)                                  | 极大整数值         |
| FLOAT       | 4 Bytes                         | (-3.402 823 466 E+38，-1.175 494 351 E-38)，0，(1.175 494 351 E-38，3.402 823 466 351 E+38)                                         | 0，(1.175 494 351 E-38，3.402 823 466 E+38)                       | 单精度  <br>浮点数值 |
| DOUBLE      | 8 Bytes                         | (-1.797 693 134 862 315 7 E+308，-2.225 073 858 507 201 4 E-308)，0，(2.225 073 858 507 201 4 E-308，1.797 693 134 862 315 7 E+308) | 0，(2.225 073 858 507 201 4 E-308，1.797 693 134 862 315 7 E+308) | 双精度  <br>浮点数值 |
| DECIMAL     | 对DECIMAL(M,D) ，如果M>D，为M+2否则为D+2 | 依赖于M和D的值                                                                                                                        | 依赖于M和D的值                                                        | 小数值           |

## 日期和时间类型
表示时间值的日期和时间类型为DATETIME、DATE、TIMESTAMP、TIME和YEAR。
每个时间类型有一个有效值范围和一个"零"值，当指定不合法的MySQL不能表示的值时使用"零"值。
TIMESTAMP类型有专有的自动更新特性，将在后面描述。

| 类型        | 大小  <br>( bytes) | 范围                                                                                                                                             | 格式                  | 用途           |
| --------- | ---------------- | ---------------------------------------------------------------------------------------------------------------------------------------------- | ------------------- | ------------ |
| DATE      | 3                | 1000-01-01/9999-12-31                                                                                                                          | YYYY-MM-DD          | 日期值          |
| TIME      | 3                | '-838:59:59'/'838:59:59'                                                                                                                       | HH:MM:SS            | 时间值或持续时间     |
| YEAR      | 1                | 1901/2155                                                                                                                                      | YYYY                | 年份值          |
| DATETIME  | 8                | '1000-01-01 00:00:00' 到 '9999-12-31 23:59:59'                                                                                                  | YYYY-MM-DD hh:mm:ss | 混合日期和时间值     |
| TIMESTAMP | 4                | '1970-01-01 00:00:01' UTC 到 '2038-01-19 03:14:07' UTC<br><br>结束时间是第 **2147483647** 秒，北京时间 **2038-1-19 11:14:07**，格林尼治时间 2038年1月19日 凌晨 03:14:07 | YYYY-MM-DD hh:mm:ss | 混合日期和时间值，时间戳 |
|           |                  |                                                                                                                                                |                     |              |

## 字符串类型
字符串类型指CHAR、VARCHAR、BINARY、VARBINARY、BLOB、TEXT、ENUM和SET。该节描述了这些类型如何工作以及如何在查询中使用这些类型。

| 类型         | 大小                    | 用途                 |
| ---------- | --------------------- | ------------------ |
| CHAR       | 0-255 bytes           | 定长字符串              |
| VARCHAR    | 0-65535 bytes         | 变长字符串              |
| TINYBLOB   | 0-255 bytes           | 不超过 255 个字符的二进制字符串 |
| TINYTEXT   | 0-255 bytes           | 短文本字符串             |
| BLOB       | 0-65 535 bytes        | 二进制形式的长文本数据        |
| TEXT       | 0-65 535 bytes        | 长文本数据              |
| MEDIUMBLOB | 0-16 777 215 bytes    | 二进制形式的中等长度文本数据     |
| MEDIUMTEXT | 0-16 777 215 bytes    | 中等长度文本数据           |
| LONGBLOB   | 0-4 294 967 295 bytes | 二进制形式的极大文本数据       |
| LONGTEXT   | 0-4 294 967 295 bytes | 极大文本数据             |

注意：char(n) 和 varchar(n) 中括号中 n 代表字符的个数，并不代表字节个数，比如 CHAR(30) 就可以存储 30 个字符。
CHAR 和 VARCHAR 类型类似，但它们保存和检索的方式不同。它们的最大长度和是否尾部空格被保留等方面也不同。在存储或检索过程中不进行大小写转换。
BINARY 和 VARBINARY 类似于 CHAR 和 VARCHAR，不同的是它们包含二进制字符串而不要非二进制字符串。也就是说，它们包含字节字符串而不是字符字符串。这说明它们没有字符集，并且排序和比较基于列值字节的数值值。
BLOB 是一个二进制大对象，可以容纳可变数量的数据。有 4 种 BLOB 类型：TINYBLOB、BLOB、MEDIUMBLOB 和 LONGBLOB。它们区别在于可容纳存储范围不同。
有 4 种 TEXT 类型：TINYTEXT、TEXT、MEDIUMTEXT 和 LONGTEXT。对应的这 4 种 BLOB 类型，可存储的最大长度不同，可根据实际情况选择。

## 枚举与集合类型
- ENUM: 枚举类型，用于存储单一值，可以选择一个预定义的集合。
- SET: 集合类型，用于存储多个值，可以选择多个预定义的集合。

## 空间数据类型
GEOMETRY, POINT, LINESTRING, POLYGON, MULTIPOINT, MULTILINESTRING, MULTIPOLYGON, GEOMETRYCOLLECTION: 用于存储空间数据（地理信息、几何图形等）。



# MySQL数据表语法
---
## 创建数据库表
```mysql
CREATE TABLE users (
	id INT AUTO_INCREMENT PRIMARY KEY,
	username VARCHAR(50) NOT NULL,
	email VARCHAR(10) NOT NULL,
	birthdate DATE,
	is_active BOOLEAN DEFAULT TRUE
);
```

## 删除数据库表
```mysql
DROP TABLE table_name
```

## 插入数据
```mysql
INSERT INTO users (username, email, birthdate, is_active)
VALUES
	('test1', 'test1@runoob.com', '1985-07-10', true),
    ('test2', 'test2@runoob.com', '1988-11-25', false),
    ('test3', 'test3@runoob.com', '1993-05-03', true);
```

## 查询数据
```mysql
-- 基本 --
SELECT column1_name, column2_name,...
FROM table_name
[WHERE condition]
[ORDER BY column_name [ASC | DESC]]
[LIMIT number]

-- 筛选查询 --
SELECT * FROM users;
SELECT username, email FROM users;
SELECT * FROM users WHERE is_active = TRUE;
SELECT * FROM users ORDER BY birthdate;
SELECT * FROM users ORDER BY birthdate DESC;
SELECT * FROM users LIMIT 10;

-- 进阶查询 --
SELECT * FROM users WHERE username LIKE 'j%' AND is_active = TRUE
SELECT * FROM users WHERE is_active = TRUE OR birthdate < '1990-01-01'
SELECT * FROM users WHERE birthdate IN ('1990-01-01', '1992-03-15', '1993-05-03')
```

## WHERE 子句
```mysql
1. 等于条件：
SELECT * FROM users WHERE username = 'test';

2. 不等于条件：
SELECT * FROM users WHERE username != 'runoob';

3. 大于条件:
SELECT * FROM products WHERE price > 50.00;

4. 小于条件:
SELECT * FROM orders WHERE order_date < '2023-01-01';

5. 大于等于条件:
SELECT * FROM employees WHERE salary >= 50000;

6. 小于等于条件:
SELECT * FROM students WHERE age <= 21;

7. 组合条件（AND、OR）:
SELECT * FROM products WHERE category = 'Electronics' AND price > 100.00;
SELECT * FROM orders WHERE order_date >= '2023-01-01' OR total_amount > 1000.00;

8. 模糊匹配条件（LIKE）:
SELECT * FROM customers WHERE first_name LIKE 'J%';

9. IN 条件:
SELECT * FROM countries WHERE country_code IN ('US', 'CA', 'MX');

10. NOT 条件:
SELECT * FROM products WHERE NOT category = 'Clothing';

11. BETWEEN 条件:
SELECT * FROM orders WHERE order_date BETWEEN '2023-01-01' AND '2023-12-31';

12. IS NULL 条件
SELECT * FROM employees WHERE department IS NULL;

13. IS NOT NULL 条件:
SELECT * FROM customers WHERE email IS NOT NULL;
```

## UPDATE 修改数据表中的内容
```mysql
UPDATE table_name
SET column1 = value1, column2 = value2, ...
WHERE condition

1.更新单个列的值
UPDATE employees
SET salary = 60000
WHERE employee_id = 101;

2.更新多个列的值
UPDATE orders
SET status = 'Shipped', ship_date = '2023-03-01'
WHERE order_id = 1001;

3.使用表达式更新值
UPDATE products
SET price = price * 1.1
WHERE category = 'Electronics';

4.更新符合条件的所有行
UPDATE students
SET status = 'Graduated';

5.更新使用子查询的值
UPDATE customers
SET total_purchases = (
	SELECT SUM(amount)
	FROM orders
	WHERE orders.customer_id = custormers.custormers_id
)
WHERE custormer_type = 'Premiun';
```

## DELETE语句 删除数据表中的记录
```mysql
DELETE FROM table_name
WHERE condition;

1.删除符合条件的行
DELETE FROM students
WHERE graduation_year = 2021;

2.删除所有行
DELETE FROM orders;

3.使用子查询删除符合条件的行
DELETE FROM customers
WHERE customer_id IN (
	SELECT customer_id
	FROM orders
	WHERE order_date < '2023-01-01'
);
```

## LIKE 字句
进行模糊匹配，通常与通配符一起使用
```mysql
SELECT column1, column2, ...
FROM table_name
WHERE column_name LIKE pattern;

1.百分号通配符% 表示零个或多个字符
SELECT * FROM customers WHERE last_name LIKE '%S';

2.下划线通配符_ 表示一个字符
SELECT * FROM products WHERE product_name LIKE '_a%'

3.组合使用%和_
SELECT * FROM users WHERE username LIKE 'a%o_'

4.不区分大小写的匹配
SELECT * FROM employees WHERE last_name LIKE 'smi%' COLLATE utf8mb4_general_ci;
```

## UNION 操作符
UNION语句用于连接两个以上的SELECT语句的结果组合到一个结果组合，并去除对应的行。
UNION操作符必须由两个或多个SELECT语句组成，每个SELECT语句的列数和对应位置的数据类型必须相同。
```mysql
SELECT column1, column2, ...
FROM table1
WHERE condition1
UNION
SELECT column1, column2, ...
FROM table2
WHERE condition2
[ORDER BY column1, column2, ...];

1.基本的UNION操作
SELECT city FROM customers
UNION
SELECT city FROM suppliers
ORDER BY city

2.使用过滤条件的UNION
SELECT product_name FROM products WHERE category = 'Electronics'
UNION
SELECT product_name FROM products WHERE category = 'Clothing'
ORDER BY product_name;

3.UNION操作中的列数和数据类型必须相同
SELECT first_name, last_name FROM employees
UNION
SELECT depart_name, NULL FROM departments
ORDER BY first_name;

4.使用UNION ALL不去除重复行
SELECT city FROM customers
UNION ALL
SELECT city FROM suppliers
ORDER BY city;
```

## ORDER BY 语句
```mysql
SELECT column1, column2, ...
FROM table_name
ORDER BY column1 [ASC | DESC], column2 [ASC | DESC], ...;

1.单列排序
SELECT * FROM products
ORDER BY product_name ASC;

2.多列排序
SELECT * FROM employees
ORDER BY department_id ASC, hire_date DESC;

3.使用数字表示列的位置
SELECT first_name, last_name, salary
FROM employees
ORDER BY 3 DESC, 1 ASC;

4.使用表达式排序
SELECT product_name, price * discount_rate AS discounted_price
FROM products
ORDER BY discounted_price DESC;

5.从MySQL 8.0.16 版本开始，可以使用NULLS FIRST 或 NULLS LAST 处理NULL值
SELECT product_name, price
FROM products
ORDER BY price DESC NULLS LAST;
```

## GROUP BY 语句
GROUP BY 语句根据一个或多个列对结果集进行分组。
在分组的列上我们可以使用 COUNT, SUM, AVG,等函数。
GROUP BY 语句是 SQL 查询中用于汇总和分析数据的重要工具，尤其在处理大量数据时，它能够提供有用的汇总信息。
- `GROUP BY` 子句通常与聚合函数一起使用，因为分组后需要对每个组进行聚合操作。
- `SELECT` 子句中的列通常要么是分组列，要么是聚合函数的参数。
- 可以使用多个列进行分组，只需在 `GROUP BY` 子句中用逗号分隔列名即可。
```mysql
SELECT column1, aggregate_function(column2)
FROM table_name
WHERE condition
GROUP BY column1;

SELECT customer_id, SUM(order_amount) AS total_amount
FROM orders
GROUP BY customer_id;

SELECT column1, column2, aggregate_function(column3)
FROM table_name
WHERE condition
GROUP BY column1, column2;

-- 实例 --
-- 实例表结构 --
SET NAMES utf8;
SET FOREIGN_KEY_CHECKS = 0;

DROP TABLE IF EXISTS `employee_tbl`
CREATE TABLE `employee__tbl` (
  `id` INT(11) NOT NULL,
  `name` CHAR(10) NOR NULL DEFAULT '',
  `date` datetime NOT NULL,
  `signin` tinyint(4) NOT NULL DEFAULT '0' COMMENT '登录次数'
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

BEGIN;  
INSERT INTO `employee_tbl` VALUES 
('1', '小明', '2016-04-22 15:25:33', '1'), 
('2', '小王', '2016-04-20 15:25:47', '3'), 
('3', '小丽', '2016-04-19 15:26:02', '2'), 
('4', '小王', '2016-04-07 15:26:14', '4'), 
('5', '小明', '2016-04-11 15:26:40', '4'), 
('6', '小明', '2016-04-04 15:26:54', '2');  
COMMIT;  
  
SET FOREIGN_KEY_CHECKS = 1;

mysql> set names utf8;
mysql> SELECT * FROM employee_tbl;
+----+--------+---------------------+--------+
| id | name   | date                | signin |
+----+--------+---------------------+--------+
|  1 | 小明 | 2016-04-22 15:25:33 |      1 |
|  2 | 小王 | 2016-04-20 15:25:47 |      3 |
|  3 | 小丽 | 2016-04-19 15:26:02 |      2 |
|  4 | 小王 | 2016-04-07 15:26:14 |      4 |
|  5 | 小明 | 2016-04-11 15:26:40 |      4 |
|  6 | 小明 | 2016-04-04 15:26:54 |      2 |
+----+--------+---------------------+--------+
6 rows in set (0.00 sec)

mysql> SELECT name, COUNT(*) FROM   employee_tbl GROUP BY name;
+--------+----------+
| name   | COUNT(*) |
+--------+----------+
| 小丽 |        1 |
| 小明 |        3 |
| 小王 |        2 |
+--------+----------+
3 rows in set (0.01 sec)
```


## JOIN的使用——在多个表中中查询数据
使用MySQL JOIN在两个或多个表中查询数据。
JOIN的功能大致分为三类：
- **INNER JOIN（内连接,或等值连接）**：获取两个表中字段匹配关系的记录。
- **LEFT JOIN（左连接）**：获取左表所有记录，即使右表没有对应匹配的记录。
- **RIGHT JOIN（右连接）：** 与 LEFT JOIN 相反，用于获取右表所有记录，即使左表没有对应匹配的记录。
```mysql
-- INNER JOIN --

SELECT column1, column2, ...
FROM table1
INNER JOIN table2 ON table1.column_name = table2.column_name;

1.简单的 INNER JOIN
SELECT orders.order_id, customers.customer_name
FROM orders
INNER JOIN customers ON orders.customer_id = customers.customer_id;

2.使用表别名
SELECT o.order_id, c.customer_name
FROM orders AS o
INNER JOIN customers AS c ON o.customer_id = c.customer_id;

3.多表INNER JOIN
SELECT orders.order_id, customers.customer_name, products.product_name
FROM orders
INNER JOIN customer ON orders.customer_id = customer.customer_id
INNER JOIN order_items ON orders.order_id = order_items.order_id
INNER JOIN products ON order_items.product_id = products.product_id;
涉及四个表，选择了订单ID、客户名称和产品名称，连接了这些表的关联列。

4.使用WHERE子句进行过滤
SELECT orders.order_id, customers.customer_name
FROM orders
INNER JOIN customer ON orders.customer_id = customers.customer_id
WHERE orders.order_date >= '2023-01-01';

-- LEFT JOIN --

SELECT column1, column2, ...
FROM table1
LEFT JOIN table2 ON table1.column_name = table2.column_name;

1. 简单的 LEFT JOIN：
SELECT customers.customer_id, customers.customer_name, orders.order_id
FROM customers
LEFT JOIN orders ON customers.customer_id = orders.customer_id;

2. 使用表别名：
SELECT c.customer_id, c.customer_name, o.order_id
FROM customers AS c
LEFT JOIN orders AS o ON c.customer_id = o.customer_id;

3. 多表 LEFT JOIN：
SELECT customers.customer_id, customers.customer_name, orders.order_id, products.product_name
FROM customers
LEFT JOIN orders ON customers.customer_id = orders.customer_id
LEFT JOIN order_items ON orders.order_id = order_items.order_id
LEFT JOIN products ON order_items.product_id = products.product_id;

4. 使用 WHERE 子句进行过滤：
SELECT customers.customer_id, customers.customer_name, orders.order_id
FROM customers
LEFT JOIN orders ON customers.customer_id = orders.customer_id
WHERE orders.order_date >= '2023-01-01' OR orders.order_id IS NULL;

-- RIGHT JOIN --

SELECT column1, column2, ...
FROM table1
RIGHT JOIN table2 ON table1.column_name = table2.column_name;

SELECT customers.customer_id, orders.order_id
FROM customers
RIGHT JOIN orders ON customers.customer_id = orders.customer_id;

在开发过程中中，RIGHT JOIN 并不经常使用，因为它可以用 LEFT JOIN 和表的顺序交换来实现相同的效果。例如，上面的查询可以通过使用 LEFT JOIN 改写为：

SELECT customers.customer_id, orders.order_id
FROM orders
LEFT JOIN customers ON orders.customer_id = customers.customer_id;
```


## NULL值处理
MySQL使用SELECT和WHERE来读取数据表中的数据，但是当提供的查询条件字段为NULL时，该命令就无法正常工作。
在MySQL中，NULL表示缺失或未知的数据，处理NULL时要小心，因为在数据库中它可能导致不同于预期的结果。
为了处理这种情况，MySQL提供了三大运算符：
- **IS NULL:** 当列的值是 NULL,此运算符返回 true。
- **IS NOT NULL:** 当列的值不为 NULL, 运算符返回 true。
- **<=>:** 比较操作符（不同于 = 运算符），当比较的的两个值相等或者都为 NULL 时返回 true。
不能使用 = NULL 或 != NULL 在列中查找 NULL 值 。
在 MySQL 中，NULL 值与任何其它值的比较（即使是 NULL）永远返回 NULL，即 NULL = NULL 返回 NULL 。
MySQL 中处理 NULL 使用 IS NULL 和 IS NOT NULL 运算符。
```mysql
1.检查是否为NULL
SELECT * FROM employees WHERE department_id IS NULL;
SELECT * FROM employees WHERE department_id IS NOT NULL;

2.使用COALESCE函数处理NULL，COALESCE函数用于替换NULL的值
SELECT product_name, COALESCE(stock_quantity, 0) AS actual_quantity
FROM products;

3.使用IFNULL函数处理NULL，IFNULL 函数是COALESCE的MySQL特定版本，它接受两个参数，如果第一个参数为 NULL，则返回第二个参数。
SELECT product_name, IFNULL(stock_quantity, 0) AS actual_quantity
FROM products;

4.NULL排序，在使用ORDERBY子句进行排序时，NULL值默认会被放在排序的最后。如果希望将NULL值放在最前面，可以使用 ORDER BY column_name ASC NULLS FIRST，反之使用 ORDER BY column_name DESC NULLS LAST。
SELECT product_name, price
FROM products
ORDER BY price ASC NULLS FIRST;

5.使用<=>操作符进行NULL比较
SELECT AVG(COALEESCE(salary, 0)) AS avg_salary
FROM emplyees;

6.注意聚合函数对NULL的处理，在使用聚合函数（如 COUNT, SUM, AVG）时，它们会忽略 NULL 值，因此可能会得到不同于预期的结果。如果希望将 NULL 视为 0，可以使用 COALESCE 或 IFNULL。
SELECT AVG(COALESCE(salary, 0)) AS avg_salary
FROM emplyees;

```



















