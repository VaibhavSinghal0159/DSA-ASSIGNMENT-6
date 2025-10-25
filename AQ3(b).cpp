//    SIZE  OF  CIRCULAR  LINKED LIST 

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

int main() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();

    head->data = 5;    head->next = second;
    second->data = 10; second->next = third;
    third->data = 15;  third->next = fourth;
    fourth->data = 20; fourth->next = head; 

    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    cout << "Size of Circular Linked List: " << count;
    return 0;
}
