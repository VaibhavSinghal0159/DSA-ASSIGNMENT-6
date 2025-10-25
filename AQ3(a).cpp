//   SIZE  OF  DOUBLY  LINKED LIST

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

int main() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();

    head->data = 10;   head->prev = NULL;   head->next = second;
    second->data = 20; second->prev = head; second->next = third;
    third->data = 30;  third->prev = second; third->next = fourth;
    fourth->data = 40; fourth->prev = third; fourth->next = NULL;

    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    cout << "Size of Doubly Linked List: " << count;
    return 0;
}
