# Homework 2-1: Linear and Binary Search
## 1. Linear Search
### Using this algorithm, it will take $4$ comparisons to find the number $8$ in the sorted array. It must loop through indices $0$ to $3$ and stop at $3$, which is the fourth index of the array.
## 2. Binary Search
### It will require no more than $1$ step to find $8$ in this array. $L = 0$ and $R = 7 - 1 = 6$. This means m = $floor(\frac{(0 + 6)}{2}) = 3$. $A[3]$ is the target value $8$, so only the $1$ comparison is needed.
## 3. Binary Search on a Large Dataset
### The time complexity $O(log_2N)$, where $N = 100,000$, states that the maximum number of comparisons required for a binary search on a sorted array is $17$. The actual value is approximately $16.61$, but $17$ will account for the remainder. Although it seems low, the algorithm is constantly dividing the remaining number of elements by half after each comparison. Therefore, the maximum number of comparisons is equal to the number of times the sorted space can be divided in half. A more intuitive way to look at it mathematically would be $\frac{100,000}{2^{17}} \approx 0.76$, in which $1$ represents the target value having been found. In this expression, $100,000$ is being divided in half $17$ times to reach the target value in a worst-case scenario. 
## 4. Linear vs. Binary Search
```C++
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> elements(100000);
	int target;
	int value = 1;
	int linearComparisons = 0;
	int binaryComparisons = 1;
	int L = 0;
	int R = elements.size() - 1;
	int m = 0;

	cout << "Enter a target value: ";
	cin >> target;

	for (int i = 0; i < elements.size(); i++)
	{
		elements.at(i) = value;
		value++;
	}

	for (int j = 0; j < elements.size(); j++)
	{
		if (elements.at(j) == target)
		{
			cout << "Target was found at index: " << j << "\n";
			cout << "Number of linear comparisons for target (" << target << ") : " << linearComparisons << "\n";
			break;
		}
		else if (j == elements.size() - 1 && elements.at(j) != target)
		{
			cout << "Target was not found.";
		}
		else
		{
			linearComparisons++;
		}
	}

	while (L <= R)
	{
		m = floor((L + R) / 2);

		if (elements.at(m) < target)
		{
			L = m + 1;
			binaryComparisons++;
		}
		else if (elements.at(m) > target)
		{
			R = m - 1;
			binaryComparisons++;
		}
		else
		{
			cout << "Target was found at index: " << m << "\n";
			cout << "Number of binary comparisons for target (" << target << ") : " << binaryComparisons << "\n";
			return m;
		}
	}

	return 0;
}
```
### The worst-case time complexity for a linear search on a sorted array is $O(N)$, because if the target value is at $N - 1$ then the array must be looped from the beginning at index $0$ up until $N - 1$.
### A binary search has a worst-case time complexity of $O(log_2N)$ to account for the maximum number of times the remaining sorted space must be divided by 2 to reach a target value.
### A linear search does not require that an array be sorted since it checks each value on an individual basis, regardless of what any of the other values might be. Binary searches are not at all efficient for unsorted arrays since the very nature of the conditions within its algorithm is based on a sorted array. This is demonstrated in the comparisons between $A[m]$ and $T$: $A[m] < T$ and $A[m] > T$. If it is used on an unsorted array, the binary search may mistakenly skip over the target value multiple times and declare that it does not exist within the array.
## 5. Randomized Search
