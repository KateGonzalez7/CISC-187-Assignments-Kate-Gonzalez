# Homework 10-1: Graphs
### Part 1.
#### 1. A, B, C, D, E, and F are the vertices.
#### 2. A, C, and D are all the vertices adjacent to B.
#### 3. C, D, and F are all the vertices adjacent to E.
#### 4. A --> C --> E --> F
#### 5. The length of the path I provided is 3.
#### 6. The shortest distance from A to F is 3.
#### 7. The path length is the number of edges for any given path from one vertex to another. The distance between two vertices is the length of the shortest path between them.
### Part 2.
#### Trees are a specific type of graph that have all nodes connected via edges and do not have cycles, in which 3 or more vertices form a closed loop. Not all graphs are trees, because graphs are allowed to have cycles and contain vertices that are not connected by any edges.
#### Connected graph with no cycles: This structure could be considered a tree since there are no disconnected nodes and no cycles.
#### Connected graph containing a cycle: Any graph structures with cycles are not trees, because tree nodes cannot form any closed loops.
#### Acyclic graph with two disconnected components: Both main features of this structure violate the requirement to be considered a tree. For this structure to be a tree, the components must be connected to the rest of the vertices and none of them can be cyclic in nature.
### Part 3.
| Vertex | Adjacent Vertices |
| ------ | ----------------- |
| A      | B, C              |
| B      | A, C, D           |
| C      | A, B, E           |
| D      | B, E              |
| E      | C, D, F           |
| F      | E                 |
#### 1. Undirected edges appear twice, because the graph itself is directionless. The edge merely demonstrates that vertex A is adjacent to vertex B and vertex B is adjacent to vertex A. It does not specify in which direction the edge is pointed towards. 
#### 2. The total storage for an adjacency list is approximately $O(V + E)$ to account for both the number of vertices and number of edges. 
#### 3. Adjacency lists are useful for sparse graphs that have substantially fewer edges since it takes up much less memory than an adjacency matrix, which would store more zeros than actual data for a sparse graph.
### Part 4.
|     | A   | B   | C   | D   | E   | F   |
| --- | --- | --- | --- | --- | --- | --- |
| A   |     | 1   | 1   |     |     |     |
| B   | 1   |     | 1   | 1   |     |     |
| C   | 1   | 1   |     |     | 1   |     |
| D   |     | 1   |     |     | 1   |     |
| E   |     |     | 1   | 1   |     | 1   |
| F   |     |     |     |     | 1   |     |
#### The matrix is symmetric for this graph due to each edge appearing twice and the row and column positions being swapped. For example, the edge connecting A and C is at $(0, 2)$ and also at $(2, 0)$.
#### Determining whether two vertices are adjacent occurs in $O(1)$ time. This is because it can be represented as a 2D array with direct index accessing. The target element is checked for 0 or 1, which is a constant time operation that requires no traversing.
#### The matrix takes up $O(V^2)$ space in memory due to its representation as a 2D array with $V$ columns and $V$ rows.
#### An adjacency matrix is inefficient for a sparse graph considering that nearly all of the positions in the array will contain zeros due to the scarce number of edges. It takes up an unnecessary amount of space and provides little to no advantages when compared to the drawbacks.
### Part 5.
```C++
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjacencyList;

public:
    Graph(int vertices)
    {
        adjacencyList.resize(vertices);
    }

    void addEdge(int source, int destination)
    {
        if (adjacencyList.size() != 0 && find(adjacencyList[source].begin(), adjacencyList[source].end(), destination) != adjacencyList[source].end())
        {
            cout << "Adjacency list already contains " << destination << "\n";
        }
        else
        {
            adjacencyList[source].push_back(destination);
            adjacencyList[destination].push_back(source);
        }
    }

    void display() const
    {
        for (int i = 0; i < adjacencyList.size(); i++)
        {
            cout << i << ": ";
            if (adjacencyList[i].size() != 0)
            {
                for (int j = 0; j < adjacencyList[i].size() - 1; j++)
                {
                    cout << adjacencyList[i][j] << ", ";
                }
                cout << adjacencyList[i][adjacencyList[i].size() - 1];
            }
            cout << "\n";
        }
    }

    void bfs(int start) const;
    void dfs(int start) const;
};
```
### Part 6.
```C++
void bfs(int start) const
{
    queue<int> frontierQueue;
    unordered_set<int> discoveredSet;

    frontierQueue.push(start);
    discoveredSet.insert(start);

    while (!frontierQueue.empty())
    {
        int currentV = frontierQueue.front();
        frontierQueue.pop();

        if (adjacencyList[currentV].size() != 0)
        {
            for (int i = 0; i < adjacencyList[currentV].size(); i++)
            {
                if (!discoveredSet.contains(adjacencyList[currentV][i]))
                {
                    frontierQueue.push(adjacencyList[currentV][i]);
                    discoveredSet.insert(adjacencyList[currentV][i]);
                }
            }
        }
        

    }
}
```
| Step | Visited Vertex | Queue | Discovered Vertices |
| 1    | None           | A     | A                   |
| 2    | A              | B, D  | A, B, D             |
| 3    | B              | D, C, E | A, B, D, C, E     |
| 4    | D              | C, E  | A, B, D, C, E       |
| 5    | C              | E, F  | A, B, D, C, E, F    |
| 6    | E              | F     | A, B, D, C, E, F    |
| 7    | F              | None  | A, B, D, C, E, F    |


