#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* prev;
    Node* next;
};

int main() {
    Node* n1 = new Node();
    Node* n2 = new Node();
    Node* n3 = new Node();
    Node* n4 = new Node();
    Node* n5 = new Node();

    n1->data = 'r'; n1->prev = NULL; n1->next = n2;
    n2->data = 'a'; n2->prev = n1;   n2->next = n3;
    n3->data = 'd'; n3->prev = n2;   n3->next = n4;
    n4->data = 'a'; n4->prev = n3;   n4->next = n5;
    n5->data = 'r'; n5->prev = n4;   n5->next = NULL;

    Node* head = n1;
    Node* tail = n5;

    bool palindrome = true;

    while (head != tail && tail->next != head) {
        if (head->data != tail->data) {
            palindrome = false;
            break;
        }
        head = head->next;
        tail = tail->prev;
    }

    if (palindrome)
        cout << "List is palindrome";
    else
        cout << "List is not palindrome";

    return 0;
}
