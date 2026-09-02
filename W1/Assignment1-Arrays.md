# Homework 1-2: Arrays
### 1. Creating arrays
#### Creating an array of 100 elements requires declaring it as a particular data type and entering that number of elements in the square bracket.
```C++
int array[100];
```
### 2. Size of array elements
#### The size of each element in an array depends entirely on the data type. For instance, the size of an integer array element is 4 bytes and the size of a character array element is 1 byte. However, the size of a string array element does not contain a set number of bytes due to the varying number of characters it may contain. 
#### The size is dependent upon the amount of information stored in the data type. Each character array element can only hold a single character whereas integers may have several numerals. A string array element may differ in size considerably from the other two data types, because each character in a string is being stored in a different memory address. 
#### In the example below, each call to sizeof will output a different size to the console.
```C++
char array1[50];
string array2[50];
int array3[50];

cout << "Char array element size is " << sizeof(array1[0]);
cout << "String array element size is " << sizeof(array2[0]);
cout << "Int array element size is " << sizeof(array3[0]);
```
### 3. Array operations
#### Reading: It takes only 1 step since the data is accessed directly from the referenced index.
#### Searching for a value the array lacks: In this situation, it will take 100 steps to complete the operation. The program will need to run through every single element in the array, index 0 to index 99, because it will not stop as none of the elements match the desired value.
#### Insertion at beginning of array: Counting the insertion itself, this scenario will require 101 steps. An element added at the beginning of the array will entail a shift to every single subsequent element considering each index may only hold one element. There will be 100 element shifts plus the 1 operation to insert the new element.
#### Insertion at end of array: As this requires none of the elements to shift, the operation will be 1 step.
#### Deletion at beginning of array: This operation involves 100 steps for the deletion of the first element as well as the 99 shifts for the remaining elements. An array index cannot be left empty when the rest of the array is filled with values. This prevents users from accessing a non-existent element.
#### Deletion at end of array: Deleting the last element of the array is simply 1 step as it does not require any shifts.
### 4. Searching for particular value
#### Regardless of how many times the word "apple" appears, the program continues to run with the assumption that there may possibly be the word "apple" at the last index of the array. It does not know until it checks every element. Therefore, it will take N steps to find all the "apples."
### 5. Array memory address
#### The memory address of an array is found using the address-of operator: &. When run in Microsoft Visual Studio, it will provide the base memory address in hexidecimal. This only partially represents where the array is stored in memory. The entire array is actually stored in one continuous block of memory, the size of which is determined by the number of elements it contains.
#### In the following example, the console will output the base memory address and the memory address of the last element. The addresses are almost identical but vary slightly.
```C++
int myArray[5] = {7, 213, 89, 5, 7000};
cout << "The base memory address is " &myArray << endl;
cout << "The memory address of the last element is " &myArray[4];
```
