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
### Part 3 & 4.
```C++
#include <iostream>
#include <stdexcept>

using namespace std;

class Queue 
{
    private:
        static const int CAPACITY = 10;

        int data[CAPACITY] = {};
        int frontIndex;
        int rearIndex;
        int count;

    public:
        Queue()
        {
            data;
            frontIndex = 0;
            rearIndex = 0;
            count = 0;
        }

        bool empty() const
        {
            if (count == 0)
            {
                return true;
            }
            return false;
        }

        bool full() const
        {
            if (count == CAPACITY)
            {
                return true;
            }
            return false;
        }

        int size() const
        {
            return count;
        }

        void enqueue(int value);
        int dequeue();
        int front() const;
};
```
#### Analysis: Count is a variable that represents the number of elements currently stored in the queue. If $count = 0$, this indicates that no elements have been stores, hence an empty queue. When $count == CAPACITY$ is true, the number of elements in the queue has reached the maximum capacity initialized in the program. It means that the queue is full and can no longer store additional elements. $frontIndex == rearIndex$ may have one of two meanings. The circular queue is either empty or full. In the first case, the circular queue is empty because both variables are $0$. In the second case, the circular queue is full once rearIndex wraps around and meets frontIndex Using mathematical terms, this is represented as $(rear + 1) mod N = front$. To avoid any misinterpretations, the variable count is used. This allows the size of the queue to be tracked as frequently as needed with minimal operations.
### Part 5.
```C++
void enqueue(int value)
{
    if (count != CAPACITY)
    {
        data[rearIndex] = value;

        rearIndex = (rearIndex + 1) % CAPACITY;

        count++;
    }
    else if (count == CAPACITY)
    {
        throw overflow_error("Queue overflow");
    }
}
```
#### Analysis: Using $rearIndex++$ will cause an out-of-bounds exception when the program attempts to access $data[rearIndex]$ when $rearIndex > CAPACITY$. In addition, it treats the queue as linear rather than circular.
### Part 6.
```C++
int dequeue()
{
    if (count != 0)
    {
        int tempVal = data[frontIndex];

        frontIndex = (frontIndex + 1) % CAPACITY;

        count--;

        return tempVal;
    }
    else if (count == 0)
    {
        throw underflow_error("Queue underflow");
    }
}
```
#### Analysis: dequeue() should advance frontIndex rather than shifting all remaining elements to maintain a constant time complexity, $O(1)$, and increase the efficiency of memory usage. It removes the redundancy of shifting elements in a circular queue that does not have a logically definitive end point as a linear queue does.
### Part 7.
```C++
int front() const
{
    if (frontIndex == -1)
    {
        throw underflow_error("Queue underflow");
    }
    else
    {
        return data[frontIndex];
    }
}
```
#### Analysis: front() does not change anything in the array as it only returns the first value stored in the queue. However, dequeue() removes that first value, shifts the frontIndex, and reduces the size of the circular queue.
