# Homework 3-4 2/3: Sorting-II
### 1. Average-Case Analysis of Insertion Sort
#### Insertion Sort sorts the elements by ascending order. This is demonstrated in the diagram I created, in which the elements at index 0 and 1 are marked as sorted while the other elements remain unsorted. The left side ends up sorted since the smaller elements are shifted towards that end. An unsorted element is compared against a sorted element to determine if it is the smaller one of the two. If it is, then the elements are swapped. Otherwise, the next unsorted element is inspected and the process repeats. 
#### In each iteration of an average-case scenario, the number of swaps and comparisons is approximately equal to $\frac{N^2}{2}$. Regarding the diagram example with $N = 5$ elements, the resulting number of swaps and comparisons comes out to $11$. Substituting $N$ for the array size gives us: $\frac{5^2}{2} = \frac{25}{2} = 12.5$. It may not be the exact match but it is a close estimate, especially when one considers the countless variations of average-case scenarios. 
#### In terms of Big O Notation, the behavior of the algorithm is notated as $O(N^2)$. The quadratic growth of the number of operations is due to the fact that, the inspected elements can be compared against and swapped with nearly all other elements for each iteration. For one iteration, this is approximately $N$. So, $N$ elements multiplied by $N$ swaps and comparisons per iteration leads to a behavior represented as $N^2$.
<img width="511" height="1010" alt="InsertionSort" src="https://github.com/user-attachments/assets/68c8e94a-417f-4b25-8c48-8c64f2b345e2" />

### 2. Changing the Starting Position of Insertion Sort
#### Part A.
<img width="1451" height="3143" alt="1000055945" src="https://github.com/user-attachments/assets/818b1dde-8055-469f-8566-dc4e10115fe0" />

#### Part B.
<img width="1352" height="3116" alt="1000055946" src="https://github.com/user-attachments/assets/2576d892-d31c-4424-900b-a0c06293474b" />

#### Part C. 
<img width="1516" height="2772" alt="1000055947" src="https://github.com/user-attachments/assets/2c1c7baf-28b2-409f-9494-6e7b3473cc28" />

#### Part D.
#### Insertion Sort begins at $i = 1$ to account for all elements in the array. As seen by changing it to $i = 2$ or $i = 3$, the array is not sorted properly due to the larger elements being placed near the beginning of the array. Starting at $i = 2$ resulted in the largest and second-largest elements swapping places. Using the algorithm when $i = 3$ caused only the first two elements to be sorted. The final version of the array appeared to have shifted twice to the right and wrapped back around. Changing the initial value of $i$ would require the values before it to already be sorted. Insertion sort performs under the assumption that the first element is sorted since there is no element that precedes it. Reducing the number of iterations requires a change in structure for insertion sort. The algorithm was created for a scenario in which the first two elements must be compared at the start. If that is not occurring, then it must be changed to account for the discrepancy.
### 3. Improving a Search Algorithm
#### Part A. Complexity Analysis
#### When "X" is the first character, this is the best-case scenario and the Big O time complexity is expressed as $O(1)$ since there is only one operation. However, if "X" is placed near the middle of the string, the behavior is described as $\frac{N}{2}$. Portrayed in Big O Notation, the algorithm's time complexity in an average-case scenario is $O(N)$. The time complexity for the worst-case scenario is likewise $O(N)$ when "X" is at the end of the string given that it will require $N$ operations to find it. Even if "X" is not present in the string, the algorithm will search through all of the characters and exhibit $O(N)$ behavior. It does not know whether or not "X" is a character within the string to begin with, which is why it must inspect every index.

