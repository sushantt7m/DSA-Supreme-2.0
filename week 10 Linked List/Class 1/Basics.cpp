#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Default Constructor
    Node()
    {
        // cout << "I am Inside Default Constructor" << endl;
        this->next = NULL;
    }

    // PARAMETRIZED
    Node(int data)
    {
        // cout << "I am inside Parameterised CONSTRUCTOR" << endl;
        this->data = data;
        this->next = NULL;
    }
};

void PrintLL(Node *head)
{
    // Hm original Pointer se cher char nhi krenge isiliye temp pointer create kr rhe hain
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

int Nodeslen(Node *head)
{
    Node *temp = head;
    int nodeslen = 0;
    while (temp != 0)
    {
        nodeslen++;
        temp = temp->next;
    }
    return nodeslen;
}



int main()
{
    // Creation Node
    // Node a;
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);

    (*first).next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // fifth->next = NULL already coz fifth is last node
    // Linked list create ho chuki hai

    Node *head = first;
    cout << "Printing the entire Linked list : " << endl;
    PrintLL(first);
    int len = Nodeslen(head);
    cout << "The Length of Linked list is : " << len  << " nodes" << endl;

    return 0;
}

// Jab bhi linked list, function me pass hogi  using head ka pointer ya tail ka pointer , hm kabhi bhi original pointer ka use nhi krenge
// Linked list ko traverse krne ke liye hm temporary(temp) pointer create krenge
// Node*temp=head;
