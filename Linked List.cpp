///lab Assignment 
#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node* next;

    Node(int data_)
    {
        data = data_;
        next = NULL;
    }
};
struct List
{
    Node *head;
    Node *temp;
    bool isEmpty()
    {
        return head==NULL;
    }
    List()
    {
        head=NULL;
    }
    ///1
    void insert(int value)
    {
        Node *n=new Node(value);

        if(isEmpty())
        {
            head=n;
        }
        else
        {
            for(temp=head; temp->next!=NULL; temp=temp->next)
                ;
            temp->next=n;
        }
    }
    ///2.Insert Node at the end
    void insertAtEnd(int data)
    {
        Node* n = new Node(data);
        if(isEmpty())
        {
            head = n;
        }
        else
        {
            Node* temp;
            for(temp=head; temp->next!=NULL; temp=temp->next)
                ;

            temp->next = n;
        }
    }
    ///3.Insertion of a Node after a given Node
    void insertAfter(int value,int pos)
    {
        Node *n=new Node(value);
        Node *ptr=head;
        Node *preptr;

        if(!isEmpty())
        {
            while(preptr->data != pos)
            {
                preptr=ptr;
                ptr=ptr->next;
            }
            preptr->next=n;
            n->next=ptr;
        }
    }
    ///4.Insertion of a Node before a given Node
    void insert_before(int value,int pos)
    {
        Node *n=new Node(value);
        Node *ptr=head;
        Node *preptr;

        if(isEmpty())
        {
            cout<<"Not possible \n";
        }
        else if(head->data == pos)
        {
            n->next=head;
            head=n;
        }
        else if(!isEmpty())
        {
            while(ptr->data !=pos)
            {
                preptr=ptr;
                ptr=ptr->next;
            }

            preptr->next=n;
            n->next=ptr;
        }
    }
    ///5.Find the given value
    void find(int x)
    {
        int i;
        for(i=1, temp = head;temp->next != NULL && temp->data != x;temp = temp->next, i++);
        if(temp->data == x)
        {
            cout << x <<" Found at position:" << i << endl;
        }
        else if(temp->next == NULL)
        {
            cout << "Error: Number Not found..." << endl;
        }
    }
    ///6.Deletion of given item
    void remove(int item)
    {
        temp=head;
        Node *prev;
        if(!isEmpty())
        {
            if(head->data==item)
            {
                head=head->next;
                delete head;
            }
            else if(head->data !=item)
            {
                while(temp->next !=NULL && temp->data!= item)
                {
                    prev=temp;
                    temp=temp->next;
                }
                if(temp->data==item)
                {
                    prev->next=temp->next;
                    delete temp;
                }
            }
            else if(temp==NULL)
            {
                cout << "Error: Number Not found..." << endl;
            }
        }
    }
    ///7.Deletion at the  End
    void remove_last_Node()
    {
        Node *ptr=head;
        Node *preptr=ptr;
        while(ptr->next != NULL)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        if(ptr->next==NULL)
        {
            preptr->next=NULL;
            delete ptr;
        }
    }
    ///8.Deletion after a given a Node
    void remove_after(int item)
    {
        Node *ptr=head;
        Node *preptr;

        while(preptr->data !=item)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
            temp=ptr;
            preptr->next=ptr->next;
            delete temp;

    }
    ///9.Deletion first Node
    void remove_first_Node()
    {
        Node *ptr;
        ptr=head;
        head=head->next;
        delete head;

    }

    ///10.Travesting Linked List
    void display()
    {
        if(!isEmpty())
        {
            for(temp = head; temp != NULL; temp=temp->next)
                cout << temp->data << "\t ";
            cout << endl;
        }
        else
        {
            cout << "List is Empty!" << endl;
        }
    }
};
int main()
{
    List l1;
    l1.display();
    l1.insert(2);
    l1.insert(3);
    l1.insert(5);
    l1.insert(7);
    l1.insert(9);

    l1.display();
    l1.insertAfter(4,2);
    l1.display();
    l1.insert_before(1,2);
    l1.display();
    l1.find(7);

    l1.remove(7);
    l1.display();
    l1.remove_last_Node();
    l1.display();
    l1.remove_after(1);
    l1.display();
    l1.remove_first_Node();
    l1.display();


    return 0;
}
