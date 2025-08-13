#include<iostream>
using namespace std;

// Node class to represent each element in the linked list
class Node {
public:
    int data;       // Stores value
    Node * next;    // Pointer to next node

    // Constructor to initialize a node
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

// Singly Linked List class
class SinglyLinkedList {
private:
    Node * head; // Pointer to the first node in the list

public:
    // Constructor for empty list
    SinglyLinkedList() { head = nullptr; }

    // Constructor for list with one initial node
    SinglyLinkedList(int data) { head = new Node(data); }

    // Insert a node at the beginning of the list
    void insertAtHead(int val) {
        Node * newNode = new Node(val);
        newNode->next = head; // New node points to old head
        head = newNode;       // Head now becomes new node
    }

    // Helper function to find last node
    Node * findLastNode() {
        Node * itr = head;
        while (itr->next != NULL) {
            itr = itr->next;
        }
        return itr;
    }

    // Insert a node at the end of the list
    void insertAtTail(int val) {
        Node * newNode = new Node(val);
        // If list is empty, new node becomes head
        if (!head) {
            head = newNode;
            return;
        }
        // Otherwise, attach to the end
        Node * itr = findLastNode();
        itr->next = newNode;
    }

    // Insert a node at a specific position (1-based index)
    void insertAtPosition(int val, int pos) {
        if (pos <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }
        // If inserting at first position
        if (pos == 1) {
            insertAtHead(val);
            return;
        }
        // Traverse to the node before the desired position
        Node * itr = head;
        for (int i = 1; itr != nullptr && i < pos - 1; i++) {
            itr = itr->next;
        }
        if (!itr) {
            cout << "Position out of range!" << endl;
            return;
        }
        // Create and link new node
        Node * newNode = new Node(val);
        newNode->next = itr->next;
        itr->next = newNode;
    }

    // Delete the first node
    void deleteAtHead() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        Node * temp = head;
        head = head->next; // Move head forward
        delete temp;       // Free old head memory
    }

    // Delete the last node
    void deleteAtTail() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        // If list has only one node
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        // Traverse to second-last node
        Node * itr = head;
        while (itr->next->next != nullptr) {
            itr = itr->next;
        }
        delete itr->next; // Delete last node
        itr->next = nullptr;
    }

    // Delete a node at a specific position
    void deleteAtPosition(int pos) {
        if (pos <= 0 || !head) {
            cout << "Invalid position or empty list" << endl;
            return;
        }
        if (pos == 1) {
            deleteAtHead();
            return;
        }
        Node * itr = head;
        for (int i = 1; itr != nullptr && i < pos - 1; i++) {
            itr = itr->next;
        }
        if (!itr || !itr->next) {
            cout << "Invalid position" << endl;
            return;
        }
        Node * nodeToDelete = itr->next;
        itr->next = itr->next->next;
        delete nodeToDelete;
    }

    // Search for a value in the list
    bool search(int val) {
        Node * itr = head;
        while (itr) {
            if (itr->data == val) return true;
            itr = itr->next;
        }
        return false;
    }

    // Return the length of the list
    int size() {
        int count = 0;
        Node * itr = head;
        while (itr) {
            count++;
            itr = itr->next;
        }
        return count;
    }

    // Print the list
    void print() {
        Node * itr = head;
        while (itr) {
            cout << itr->data << " -> ";
            itr = itr->next;
        }
        cout << "NULL" << endl;
    }

    // Reverse the linked list (iterative method)
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr != nullptr) {
            next = curr->next; // Store next node
            curr->next = prev; // Reverse pointer
            prev = curr;       // Move prev one step
            curr = next;       // Move curr one step
        }
        head = prev; // Update head
    }

    // Destructor to free all memory
    ~SinglyLinkedList() {
        Node * itr = head;
        while (head) {
            Node * nextNode = itr->next;
            delete itr;
            itr = nextNode;
            head = itr;
        }
    }
};


int main() {
    SinglyLinkedList list;

    // Insert at head
    cout << "Inserting at head: 10, 20" << endl;
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.print();

    // Insert at tail
    cout << "Inserting at tail: 30, 40" << endl;
    list.insertAtTail(30);
    list.insertAtTail(40);
    list.print();

    // Insert at position
    cout << "Inserting 25 at position 3" << endl;
    list.insertAtPosition(25, 3);
    list.print();

    // Size of list
    cout << "Size of list: " << list.size() << endl;

    // Search elements
    cout << "Searching for 30: " << (list.search(30) ? "Found" : "Not Found") << endl;
    cout << "Searching for 99: " << (list.search(99) ? "Found" : "Not Found") << endl;

    // Delete at head
    cout << "Deleting at head" << endl;
    list.deleteAtHead();
    list.print();

    // Delete at tail
    cout << "Deleting at tail" << endl;
    list.deleteAtTail();
    list.print();

    // Delete at specific position
    cout << "Deleting at position 2" << endl;
    list.deleteAtPosition(2);
    list.print();

    // Reverse list
    cout << "Reversing the list" << endl;
    list.reverse();
    list.print();

    return 0;
}
