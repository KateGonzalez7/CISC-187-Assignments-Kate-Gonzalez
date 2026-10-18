# Design
### Primary Package Collection
#### The primary collection of package records is stored in a vector. The vector is of type Package, which is a struct that contains the information of a single package. This information includes the package's tracking number, recipient, destination, weight, and status.
### Processing Queue Behavior
#### The queue represents FIFO work by processing the packages in the order they arrive. The first package is processed first, the second package is processed second and so on. This is done by invoking the .front() function to store the package as a local variable copy and invoking the .pop() function to remove the package from the waiting queue.
### Hashtable Implementation
#### The unordered_map data structure is a hashtable that stores the tracking number and the package information as a key-value pair. When a search is performed on the hashtable, the package information is located based on the tracking number provided.
### Prevention of Duplicate Tracking Numbers
#### Considering that the input of the tracking number by the user is taken as a string, there is the possibility for spaces to be present in the entered tracking number. For this reason, within the function I created to check for duplicates, all spaces are removed from the user input beforehand. This prevents "1234 5678" and "12345678" from being entered as separate tracking numbers. Then, the altered input is entered as the argument for hashtable.contains(). The function returns true if the tracking number is already present, meaning it is a duplicate, or false if it is not. Within the main method, the tracking number is entered if the function returns false.
### Consistency Among Data Structures
#### 

### Major Functions of Program
####

### Sorting & Report Strategy
#### Using copy of data structure to prevent alterations to stored data

### Importance of Each Data Structure
#### Vector: This data structure is best used for calculations, because it prevents any inconsistencies that may occur when iterating. These discrepancies involve the hash collisions that may occur when conducting a search on the hashtable, a search that is crucial for determining which packages have a particular status.
#### Queue: Using a queue to process packages allows for an efficient  kjoj
#### Hashtable: The hashtable saves time and resources with an $O(1)$ search in average cases. Traversing the vector has a time complexity of $O(N)$ in average cases. Therefore, in the long run, a linear search performed on the vector will require much more work than performing the search on the hashtable.
