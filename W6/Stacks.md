# Homework 6 1/3: Stacks
### Part 1.
| Operation | Top Element | Stack Size |
| --------- | ----------- | ---------- |
| push(10)  | 10          | 1          |
| push(20)  | 20          | 2          |
| push(30)  | 30          | 3          | 
| pop()     | 20          | 2          |
| push(40)  | 40          | 3          |
| push(50)  | 50          | 4          |
| pop()     | 40          | 3          |
| push(60)  | 60          | 4          |
#### The final top element is $60$, and the final stack size is $4$. The order in which the remaining elements would be removed is as follows: $60$, $40$, $20$, $10$. The resulting order is missing elements $50$ and $30$ since they were the last-in before the pop() operation is executed and each were the first ones out once pop() occurs. This demonstrates that the stack ADT follows LIFO behavior.
### Part 2.

