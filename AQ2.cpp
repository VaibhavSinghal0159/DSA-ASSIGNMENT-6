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
    Node* fifth = new Node();

    head->data = 20;    head->next = second;
    second->data = 100; second->next = third;
    third->data = 40;   third->next = fourth;
    fourth->data = 80;  fourth->next = fifth;
    fifth->data = 60;   fifth->next = head; 

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << head->data; 
    return 0;
}
