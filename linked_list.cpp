#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insertAtHead(Node* &head, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node* &head, int val){
    Node* newNode = new Node();
    newNode->data = val;
    
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;

  
}

void deleteNode(Node* &head, int val)
{
    if(head == NULL) return;
    if(head->data == val){
        Node* temp = head;
        head = head->next;  
        delete temp;
        return;
    }

    Node* curr = head;
    while (curr->next && curr->next->data != val)
        curr = curr->next;

    if (curr->next) {
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }
}

bool isNodeExists(Node* &head, int val){
    while(head != NULL){
        if(head->data == val) return true;
        head = head->next;
    }
    return false;
}

int main()
{
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();

    first->data = 12;
    first->next = second;

    second->data = 44;
    second->next = third;

    third->data = 66;
    third->next = NULL;
    insertAtHead(first, 100);   
    insertAtTail(first, 10);

   Node* temp = first;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
    while(first != NULL){
        Node* temp = first;
        cout<<first->data<<" "<<endl;
        temp=first->next;
        cout<<temp->data << endl;
    }
    cout<<endl;

    Node* temp2 = first;
    while (temp2 != NULL) {
        cout << temp2->data << " ";
        temp2 = temp2->next;
    }

    return 0;
}
