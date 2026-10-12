# Homework 7 1/1: Linked Lists
### Part 1.
<img width="512" height="104" alt="LinkedList" src="https://github.com/user-attachments/assets/bf025093-c241-49b8-bdcd-fbf462395cb1" />

#### Analysis: The head pointer does not contain any data as it merely stores the memory location to the first node. first->next contains the memory location to the subsequent node, which is the second node. third->next contains a null pointer since there is no node that comes after the third, which is the termination of the linked list. If the head pointer was lost, the list becomes inaccessible since there is no longer a reference to the location of the first node.
### Part 2.
| Iteration | temp->data | Where temp->next leads |
| ----------| ---------- | ---------------------- |
| 1         | 10         | Memory of next node    |
| 2         | 20         | Memory of next node    |
| 3         | 30         | Memory of next node    |
| 4         |            | Null pointer           |
#### Analysis: The traversal stops after the fourth iteration because temp becomes nullptr. When the condition in the while loop compares temp again, the condition evaluates to false since temp is now a null pointer and the loop ends. If the list contains $N$ nodes, the time complexity to traverse the entire linked list becomes $O(N)$ since there is no way to directly access a node within a linked list. Each node points to nothing more than the subsequent node and has no method with which to reference any other node. For this reason, the linked list must be traversed $N$ times to access data of a node near or at the end.
### Part 3 & 4.
```C++
#include <iostream>

using namespace std;

struct Node 
{
    int data;
    Node* next;
};

class LinkedList 
{
    private:
        Node* head;

    public:
        LinkedList()
        {
            head = nullptr;
        }

        bool empty() const
        {
            if (head == nullptr)
            {
                return true;
            }
            return false;
        }

        void display() const;
        bool search(int value) const;

        void insertFront(int value);
        void insertBack(int value);
        bool insertAfter(int target, int value);

        bool remove(int value);

        ~LinkedList();
};
```
#### Analysis: A nullptr is an appropriate representation of an empty linked list since it indicates that there are no nodes in memory containing any form of data.
### Part 5.
```C++
#include <iostream>

using namespace std;

struct Node 
{
    int data;
    Node* next;
};

class LinkedList 
{
    private:
        Node* head;

    public:
        LinkedList()
        {
            head = nullptr;
        }

        bool empty() const
        {
            if (head == nullptr)
            {
                return true;
            }
            return false;
        }

        void setHead(Node* newNode)
        {
            head = newNode;
        }

        Node* getHead()
        {
            return head;
        }

        void display() const;
        bool search(int value) const;

        void insertFront(int value)
        {
            Node* front = new Node{ value, head };
            head = front;
        }

        void insertBack(int value);
        bool insertAfter(int target, int value);

        bool remove(int value);

        ~LinkedList();
};

void traverse(Node* head)
{
    Node* temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

int main()
{
    LinkedList l;

    Node* first = new Node{ 2, nullptr };
    Node* second = new Node{ 4, nullptr };
    Node* third = new Node{ 6, nullptr };
    Node* fourth = new Node{ 8, nullptr };
    Node* head = first;

    l.setHead(head);

    first->next = second;
    second->next = third;
    third->next = fourth;

    traverse(l.getHead());

    l.insertFront(1);

    traverse(l.getHead());
    
    return 0;
}
```
#### Pointer Analysis: Updating head before preserving the connection to the list will cause the nodes to become inaccessible as there is no longer a pointer referencing where they lie in memory. It is possible to accidentally create an incorrect implementation where the front node next pointer is initialized as nullptr, the head node mistakenly points to the front node, and then the front node next pointer points to the head node. This causes an infinite loop where the front node's next pointer and the head pointer are continuously pointing to one another.
#### Complexity: The Big-O complexity of insertFront() is constant time, O(1), since all it does is update the new node's pointer to the head and reassigns the head pointer to the new node. This operation does not require traversing the linked list.
### Part 6.
