#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

int main() {
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();

    first->data = 10;
    second->data = 20;
    third->data = 30;

    
    first->next = second;
    second->next = third;
    third->next = first;   

    Node* head = first;
    Node* temp = head->next;

    bool isCircular = false;

    while (temp != NULL) {
        if (temp == head) {   
            isCircular = true;
            break;
        }
        temp = temp->next;
    }

    if (isCircular)
        cout << "Linked List is Circular";
    else
        cout << "Linked List is not Circular";

    return 0;
}
