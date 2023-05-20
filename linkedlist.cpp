#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
         data= val;
         next = NULL;
    }

};

void insertAtEnd(node* &head , int val){
    node* n= new node(val);

    if(head==NULL){
        head=n;
        return;
    }

    node* temp = head;
    while(temp->next != NULL)
    {
        temp= temp->next;
    }
    temp->next=n;
}

void insertAtHead(node* &head, int val)
{
    node* n= new node(val);
    n->next=head;
    head=n;
}
//void Reversed(node* )
node* reverse(node* &head)
{
    node* preptr=NULL;
    node* curptr=NULL;
    node* nextptr;

    while(curptr!=NULL)
    {
        nextptr=curptr->next;
        curptr->next=preptr;

        preptr=curptr;
        curptr=nextptr;
    }
    return preptr;
}

void printNode(node* head){
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp= temp->next;
    }
    cout<<"NULL"<<endl;
}

bool searchNode(node* head, int keyV)
{
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==keyV){
            return true;
        }temp=temp->next;
    }return false;
}


int main()
{
    node* head=NULL;
    cout<<"Insert At End:"<<endl;
    insertAtEnd(head,10);
    insertAtEnd(head,100);
    insertAtEnd(head,17);
    insertAtEnd(head,1);
    printNode(head);
    cout<<"Insert At Begining:"<<endl;
    insertAtHead(head,8);
    insertAtHead(head,9);
    printNode(head);
    cout<<"Searching Node return bool value(0 or 1):"<<endl;
    cout<<searchNode(head,6)<<endl;

    node* newhead= reverse(head);
    printNode(newhead);

    return 0;
}