# Homework 6 2/3: Queues
### Part 1.
| Operation |Value Returned|Logical Queue After | Top Element | Stack Size |
| --------- | ------------ | ------------------ | ----------- | ---------- |
|enqueue(10)|              |[10]                | 10          | 1          |
|enqueue(20)|              |[10,20]             | 10          | 2          |
|enqueue(30)|              |[10,20,30]          | 10          | 3          | 
|dequeue()  | 10           |[20,30]             | 20          | 2          |
|enqueue(40)|              |[20,30,40]          | 20          | 3          |
|enqueue(50)|              |[20,30,40,50]       | 20          | 4          |
|dequeue()  | 20           |[30,40,50]          | 30          | 3          |
|enqueue(60)|              |[30,40,50,60]       | 30          | 4          |
