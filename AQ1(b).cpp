//  CIRCULAR LIST

#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at end
void insertEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* currentNode = head;
    while (currentNode->next != head)
        currentNode = currentNode->next;

    currentNode->next = newNode;
    newNode->next = head;
}

// Insert after a specific node
void insertAfter(int key, int value) {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }

    Node* currentNode = head;
    do {
        if (currentNode->data == key) {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = currentNode->next;
            currentNode->next = newNode;
            return;
        }
        currentNode = currentNode->next;
    } while (currentNode != head);

    cout << "Node not found\n";
}

// Delete a node
void deleteNode(int key) {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }

    Node* currentNode = head;
    Node* previousNode = NULL;

    while (currentNode->data != key) {
        if (currentNode->next == head) {
            cout << "Node not found\n";
            return;
        }
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    // Only one node
    if (currentNode == head && currentNode->next == head) {
        head = NULL;
        delete currentNode;
        return;
    }

    // Deleting head node
    if (currentNode == head) {
        previousNode = head;
        while (previousNode->next != head)
            previousNode = previousNode->next;
        head = head->next;
        previousNode->next = head;
        delete currentNode;
    } 
    // Deleting last or middle node
    else {
        previousNode->next = currentNode->next;
        delete currentNode;
    }
}

// Search for a node
void searchNode(int key) {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }

    Node* currentNode = head;
    do {
        if (currentNode->data == key) {
            cout << "Node found\n";
            return;
        }
        currentNode = currentNode->next;
    } while (currentNode != head);

    cout << "Node not found\n";
}

// Display list (repeat head value at end)
void displayList() {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }

    Node* currentNode = head;
    do {
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    } while (currentNode != head);

    cout << head->data << endl;  // repeat head value
}

int main() {
    insertEnd(20);
    insertEnd(40);
    insertEnd(60);
    insertAfter(40, 50);

    cout << "Circular list after insertions: ";
    displayList();

    deleteNode(20);
    cout << "After deleting 20: ";
    displayList();

    searchNode(50);
    searchNode(100);

    return 0;
}
