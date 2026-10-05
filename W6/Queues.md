# Homework 6 2/3: Queues
### Part 1.
| Operation |Value Returned|Logical Queue After |    Front    | Queue Size |
| --------- | ------------ | ------------------ | ----------- | ---------- |
|enqueue(10)|              |[10]                | 10          | 1          |
|enqueue(20)|              |[10,20]             | 10          | 2          |
|enqueue(30)|              |[10,20,30]          | 10          | 3          | 
|dequeue()  | 10           |[20,30]             | 20          | 2          |
|enqueue(40)|              |[20,30,40]          | 20          | 3          |
|enqueue(50)|              |[20,30,40,50]       | 20          | 4          |
|dequeue()  | 20           |[30,40,50]          | 30          | 3          |
|enqueue(60)|              |[30,40,50,60]       | 30          | 4          |
#### The final front element is $30$, and the final queue size is $4$. The elements in the final iteration of the queue would be removed starting with $30$, then $40$, $50$, and finally $60$. By the end of all operations, $10$ and $20$ are removed in that order from the queue. This means queues follow a first-in, first-out policy, especially considering that the elements in the rear remained untouched.
### Part 2.
#### If the queue contains $N$ elements, then a dequeue() operation with this approach will require $N - 1$ shifts to the left. Performing this method has a time complexity of $O(N)$ due to the number of shifts for a dequeue() being approximately $N$. Repeating this process for $N$ elements means that $N$ elements multiplied by the number of shifts per dequeue(), $~N$, results in $N * N = N^2$ work. As a result, the time complexity becomes $O(N^2)$.
