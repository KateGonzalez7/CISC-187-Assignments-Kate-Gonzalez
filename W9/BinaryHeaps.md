# Homework 9: Binary Heaps
### Part 1. 
#### Heap A: It is a valid max-heap due to every parent node having child nodes with only smaller values than it. Another reason it is valid is the fact that it is considered complete for having no nodes to the right of any empty positions.
#### Heap B: This is not a valid max-heap. It follows the heap condition, but violates the complete tree rule due to there being two nodes to the right of an empty position.
#### Heap C: The heap is not a valid max-heap. While it is technically a complete tree, it violates the heap condition for placing a descendant (95) with a higher value than the root (90) under that node.
### Part 2.
#### 1. This is a valid max-heap as it follows both the heap condition and complete tree rule. 
#### 2. It is not a BST, because the values are not properly ordered in a way where a subtree can be excluded from the search for a particular target value. The nodes to the right on the bottom row have smaller values than the right child of the left parent node, which also happens to have a left child whose value is smaller than the rightmost values.
#### 3. If the target value is 40, there is no way to determine which subtree contains a child node with this value.
#### 4. The time complexity of a search in a heap is $O(N)$, because the nodes are not sorted in a way that can eliminate subtrees from the search as a BST can. In the example heap, 40 could easily have been in the left subtree since it is also smaller than 80.
#### 5. The root with a value of 100 can be accessed immediately. This is due to a max-heap containing the largest value at the root of the structure.
### Part 3.
| Index | Value |
| ----- | ----- |
| 0     | 90    |
| 1     | 70    |
| 2     | 80    |
| 3     | 20    |
| 4     | 40    |
| 5     | 60    |
| 6     | 50    |
#### Index 1: Parent index $= \frac{(1 - 1)}{2} = \frac{0}{2} = 0$. Left-child index $= 2 * 1 + 1 = 2 + 1 = 3$. Right-child index $= 2 * 1 + 2 = 2 + 2 = 4$.
#### Index 2: Parent index $= \frac{(2 - 1)}{2} = \frac{1}{2} = 0$. Left-child index $= 2 * 2 + 1 = 4 + 1 = 5$. Right-child index $= 2 * 2 + 2 = 4 + 2 = 6$.
#### Index 4: Parent index $= \frac{(4 - 1)}{2} = \frac{3}{2} = 1$. Does not have child nodes.
#### Index 5: Parent index $= \frac{(5 - 1)}{2} = \frac{4}{2} = 2$. Does not have child nodes.
### Part 4.
#### The array feature of direct access via index solved the heap's last node problem. This is because of the last node being stored at the last index of an array, which is easily accessible and can be done with $O(1)$ work. Before being shifted to a proper location, a newly placed value is first inserted at the very last index. The end of the array represents the bottom row of nodes which may have empty positions, or it may create a new row starting logically at the left of the heap. In either case, this insertion complies with the complete tree rule. Removing the final array element preserves this rule as well since it represents the rightmost node of a heap in the bottom row. When it is deleted, it does not leave a logical gap between nodes, which is why this works. A linked-node implementation would require a traversal that has a complexity of $O(N)$ due to the heap not being properly sorted and a lack of index access.
### Part 5.
#### 
