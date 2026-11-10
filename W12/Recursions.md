# Homework 12-1: Recursions
### Part 1.
#### This function is recursive because it calls itself within the body. It does not have a base case, so this function will call itself infinitely. As a result, the call stack will continue to push the recursive calls until a stack overflow error is detected, which is when the computer runs out of space in short-term memory.
### Part 2.
```C++
// Iterative function
void countdown(int start)
{
  for(int i = start; i >= 0; --i)
  {
    cout << i << "\n";
  }
}
// Recursive function
void countdown(int start)
{
	cout << start << "\n";
	if (start == 0)
	{
		return;
	}
	countdown(--start);
}
```
| Question | Response |
| -------- | -------- |
| Base case? | 0 is the base case, because the recursion calls will end once this value is reached. |
| Recursive case? | countdown(--start) is the recursive case that will continue the recursion calls. |
| Method to move to base case? | Each call moves toward the base case by decrementing by 1. |
### Part 3.
| Step | Function Call | Value Printed | Next Action |
| ---- | ------------- | ------------- | ----------- |
| 1    | countdown(3)  | 3             | countdown(2)|
| 2    | countdown(2)  | 2             | countdown(1)|
| 3    | countdown(1)  | 1             | countdown(0)|
| 4    | countdown(0)  | 0             | terminate   |
#### It prevents any negative numbers from being printed, because the function will terminate via return once the base case is reached.
### Part 4.
#### 1. The base case is $1$ due to there not being any recursive calls once this value is reached.
#### 2. $n * factorial(n - 1)$ is the recursive case since it calls the function again.
#### 3. $n - 1$ brings the value closer to the base case of 1 with each recursive call.
#### 4. $factorial(1)$ returns $1$ since it immediately reaches the base case.
#### 5. $factorial(2) = n * factorial(1) = 2 * 1 = 2$
#### 6. $factorial(3) = n * factorial(2) = 3 * 2 = 6$
#### 7. $factorial(4) = n * factorial(3) = 4 * 6 = 24$
### Part 5.
#### $factorial(4) = 4 * factorial(3) = 4 * 3 * factorial(2) = 4 * 3 * 2 * factorial(1) = 4 * 3 * 2 * 1 = 24$
#### The recursive calling phase stops once $n == 1$.
### Part 6.
| Call Order | Function |
| ---------- | -------- |
| 1          | factorial(4) |
| 2          | factorial(3) |
| 3          | factorial(2) |
| 4          | factorial(1) |

| Completed Order | Function |
| --------------- | -------- |
| 1               | factorial(1) |
| 2               | factorial(2) |
| 3               | factorial(3) |
| 4               | factorial(4) |
#### There is no definitive value in the previously called functions that can determine the result. It depends entirely on the value in the base case, which returns a concrete value of $1$. Once the function with the base case is called, then the previous function called ($factorial(2)$) can return the real number $2$ and so on until $factorial(4)$ is reached.
### Part 7.
| Function | Expression | Returned Value |
| -------- | ---------- | -------------- |
| factorial(1) | 1      | 1              |
| factorial(2) | 2 * factorial(1) | 2    |
| factorial(3) | 3 * factorial(2) | 6    |
| factorial(4) | 4 * factorial(3) | 24   |
#### The value is being passed from the child invocation up to the parent invocation, which itself is a child invocation of a parent. It is being passed up through the call stack, whose order begins from the recursive call with the base case and ends at the first call in the stack.
### Part 8.
#### Example A: This function contains a base case of $0$. The base case will never be reached if the value passed to the parameter is a positive number, because that value will only increase with each recursive call. The base case can only be reached if $n <= 0$. To correct this issue requires rewriting line $6$ to be
```C++
mystery(n - 1);
```
#### Example B: This function eventually causes a stack overflow due to the lack of a base case to terminate the recursive calls. The number will decrease without end until the computer runs out of space in short-term memory.
### Part 9.
#### The base case is $1$ since the function will terminate once $n$ reaches $1$. The recursive case is $n + sumTo(n - 1)$, because it continues the recursive calls when $n > 1$. The recursive call moves by decrementing $n$ by $1$ until the base case, $1$, is reached.
```C++
int sumTo(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return n + sumTo(n - 1);
}
```
| Function | Recursive Call | Returned Value |
| -------- | -------------- | -------------- |
| sumTo(1) | None           | 1              |
| sumTo(2) | 2 + sumTo(1)   | 3              |
| sumTo(3) | 3 + sumTo(2)   | 6              |
| sumTo(4) | 4 + sumTo(3)   | 10             |
### Part 10.

