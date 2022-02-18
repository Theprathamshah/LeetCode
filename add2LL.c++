#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void InsertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void Display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


int sizeOfLL(node* head)
{
    int itr = 0;
    while(head)
    {
        head = head->next;
        itr++;
    }
    return itr;
}

void insertAtHead(node* &head,int data)
{
    node* n = new node(data);
    if(!head)
    {
        head = n;
        return;
    }
    n->next = head;
    head = n;

}

int addTwoLinkedList(node* head1,node* head2,int pos1,int pos2,node* &ans)
{
    if(!head1 and !head2)
    {
        return 0;
    }

    int data=0;
    if(pos1>pos2)
    {
        int oc = addTwoLinkedList(head1->next,head2,pos1-1,pos2,ans);
        data = head1->data+oc;
    }
    else if(pos2>pos1)
    {
        int oc = addTwoLinkedList(head1,head2->next,pos1,pos2-1,ans);
        data = head2->data+oc;
    }
    else
    {
        int oc = addTwoLinkedList(head1->next,head2->next,pos1-1,pos2-1,ans);
        data = head1->data+head2->data+oc;
    }
    int nc = data/10;
    int ndata = data%10;
    insertAtHead(ans,ndata);
    return nc;

}

int main()
{
    node* head1 = NULL;
    node* head2 = NULL;
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin>>data;
        InsertAtTail(head1,data);
    }
    for (int i = 0; i < m; i++)
    {
        int data;
        cin>>data;
        InsertAtTail(head2,data);
    }
    Display(head1);
    Display(head2);

    int pos1 = sizeOfLL(head1);
    int pos2 = sizeOfLL(head2);
    // cout<<pos1<<endl;
    // cout<<pos2<<endl;
    // Display(head1);
    node* ans = NULL;
    // insertAtHead(ans,10);
    // insertAtHead(ans,20);
    // insertAtHead(ans,30);
    // insertAtHead(ans,40);
    // insertAtHead(ans,50);
    int oldcarry = addTwoLinkedList(head1,head2,pos1,pos2,ans);
    if(oldcarry)
    {
        insertAtHead(ans,oldcarry);
    }
    Display(ans);
    return 0;
}
