# Homework 6 1/3: Stacks
### Part 1.
| Operation |Value Returned|Stack After Op.| Top Element | Stack Size |
| --------- | ------------ | ------------- | ----------- | ---------- |
| push(10)  |              |[10]           | 10          | 1          |
| push(20)  |              |[10,20]        | 20          | 2          |
| push(30)  |              |[10,20,30]     | 30          | 3          | 
| pop()     | 30           |[10,20]        | 20          | 2          |
| push(40)  |              |[10,20,40]     | 40          | 3          |
| push(50)  |              |[10,20,40,50]  | 50          | 4          |
| pop()     | 50           |[10,20,40]     | 40          | 3          |
| push(60)  |              |[10,20,40,60]  | 60          | 4          |
#### The final top element is $60$, and the final stack size is $4$. The order in which the remaining elements would be removed is as follows: $60$, $40$, $20$, $10$. The resulting order is missing elements $50$ and $30$ since they were the last-in before the pop() operation is executed and each were the first ones out once pop() occurs. This demonstrates that the stack ADT follows LIFO behavior.
### Part 2 & 3.
```C++
#include <iostream>
#include <stdexcept>

using namespace std;

class Stack {
    private:
        static const int CAPACITY = 10;

        int data[CAPACITY] = {};
        int topIndex;

    public:
        Stack()
        {
            topIndex = -1;
            data;
        }

        bool empty() const
        {
            if (topIndex == -1)
            {
                return true;
            }
            return false;
        }

        bool full() const
        {
            if (topIndex + 1 == CAPACITY)
            {
                return true;
            }
            return false;
        }

        int size() const
        {
            return topIndex + 2;
        }

        void push(int value);

        int pop();

        int top() const;
};
```
#### Analysis: Top index needs to be initialized as $-1$ since initializing it as $0$ indicates that there must be an element at index $0$. For this reason, $-1$ can be used to signify an empty stack. The stack size is $topIndex + 1$ due to indices starting at $0$ rather than $1$. The plus one accounts for this convention. A stack is full when top index is equal to $size - 1$ for the aforementioned reason involving the standard for array indices.
