# Homework 2-1: Linear and Binary Search
## 1. Linear Search
### Using this algorithm, it will take $4$ comparisons to find the number $8$ in the sorted array. It must loop through indices $0$ to $3$ and stop at $3$, which is the fourth index of the array.
## 2. Binary Search
### It will require no more than $1$ step to find $8$ in this array. $L = 0$ and $R = 7 - 1 = 6$. This means m = $floor(\frac{(0 + 6)}{2}) = 3$. $A[3]$ is the target value $8$, so only the $1$ comparison is needed.
## 3. Binary Search on a Large Dataset
### The time complexity $O(log_2N)$, where $N = 100,000$, states that the maximum number of comparisons required for a binary search on a sorted array is $17$. The actual value is approximately $16.61$, but $17$ will account for the remainder. Although it seems low, the algorithm is constantly dividing the remaining number of elements by half after each comparison. Therefore, the maximum number of comparisons is equal to the number of times the remaining sorted space can be divided in half. A more intuitive way to look at it mathematically would be $\frac{100,000}{2^{17}} \approx 0.76$, in which $1$ represents the target value having been found. In this expression, $100,000$ is being divided in half $17$ times to reach the target value. 
## 4. Linear vs. Binary Search
## 5. Randomized Search
