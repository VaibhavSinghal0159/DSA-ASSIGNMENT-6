//  DOUBLE LINKED LIST

#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertFirst(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

// Insert at end
void insertLast(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* currentNode = head;
    while (currentNode->next != NULL)
        currentNode = currentNode->next;

    currentNode->next = newNode;
    newNode->prev = currentNode;
}

// Insert after a given node
void insertAfter(int key, int value) {
    Node* currentNode = head;
    while (currentNode != NULL && currentNode->data != key)
        currentNode = currentNode->next;

    if (currentNode == NULL) {
        cout << "Node not found\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = currentNode->next;
    newNode->prev = currentNode;

    if (currentNode->next != NULL)
        currentNode->next->prev = newNode;

    currentNode->next = newNode;
}

// Delete a specific node
void deleteNode(int key) {
    Node* currentNode = head;
    while (currentNode != NULL && currentNode->data != key)
        currentNode = currentNode->next;

    if (currentNode == NULL) {
        cout << "Node not found\n";
        return;
    }

    if (currentNode->prev != NULL)
        currentNode->prev->next = currentNode->next;
    else
        head = currentNode->next;

    if (currentNode->next != NULL)
        currentNode->next->prev = currentNode->prev;

    delete currentNode;
}

// Search for a node
void searchNode(int key) {
    Node* currentNode = head;
    while (currentNode != NULL) {
        if (currentNode->data == key) {
            cout << "Node found\n";
            return;
        }
        currentNode = currentNode->next;
    }
    cout << "Node not found\n";
}

// Display list
void displayList() {
    Node* currentNode = head;
    while (currentNode != NULL) {
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
}


int main() {
    insertFirst(30);
    insertFirst(10);
    insertLast(50);
    insertAfter(30, 40);

    cout << "List after insertions: ";
    displayList();

    deleteNode(10);
    cout << "List after deleting 10: ";
    displayList();

    searchNode(40);
    searchNode(100);

    return 0;
}
