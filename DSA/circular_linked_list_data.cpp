#include <iostream>
using namespace std;

class Node{
    public:
        int key;
        int data;
        Node* next;

        Node()
        {
            key = 0;
            data = 0;
            next = NULL;
        }

        Node(int k, int d)
        {
            key = k;
            data = d;
        }
};

class CircularLinkedList
{
    public:
        Node* head;

        CircularLinkedList()
        {
            head = NULL;
        }

        Node* nodeExists(int k)
        {
            Node* temp = NULL;
            Node* ptr = head;

            if (ptr == NULL)
            {
                return temp;
            }
            else
            {
                do
                {
                    if(ptr->key == k)
                    {
                        temp = ptr;
                    }
                    ptr = ptr->next;
                } while (ptr != head);
                return temp;


                // while (ptr != head)
                // {
                //     if (ptr->key == k)
                //     {
                //         temp = ptr;
                //     }
                //     ptr = ptr->next;
                // }
                // return temp;
                
            }

            //return temp;
        }

        void appendNode(Node *new_node)
        {
            if(nodeExists(new_node -> key)!= NULL)
            {
                cout << "Node already exists with key value : "
                <<new_node->key
                <<". Append another node with different key value"
                <<endl;
            }
            else
            {
                if(head == NULL)
                {
                    head =new_node;
                    new_node->next = head;
                    cout <<"Node appended at first head position"<<endl;
                }
                else
                {
                    Node* ptr = head;
                    while (ptr->next != head)
                    {
                        ptr = ptr->next;
                    }
                    ptr->next = new_node;
                    new_node->next = head;
                    cout <<"Node appended"<< endl;
                }
            }
        }

        //3. Prepend Node - Attach a node at the start
        void prependNode(Node* new_node)
        {
            if(nodeExists(new_node->key)!= NULL)
            {
                cout <<"Node Already exists with key value : "
                <<new_node->key
                <<". Append another node with different key value"
                << endl;
            }
            else
            {

                if(head == NULL)
                {
                    head =new_node;
                    new_node->next = head;
                    cout <<"Node prepended at first head position"<<endl;
                }
                else
                {
                    Node* ptr = head;
                    while (ptr->next!=head)
                    {
                        ptr = ptr->next;
                    }

                    ptr->next = new_node;
                    new_node->next = head;
                    head = new_node;
                    cout <<"Node prepended" << endl;

                }

                
            }
        }

        void insertNodeAfter (int k, Node *new_node)
        {
            Node* ptr = nodeExists(k);
            if (ptr == NULL)
            {
                cout << "No node exists with key value of " << k<< endl;
            }
            else
            {
                if(nodeExists(new_node -> key)!=NULL)
                {
                    cout << "Node already exists with key value : "
                    << new_node->key
                    <<". Append another node with different key value"
                    <<endl;
                }
                else
                {
                    if (ptr->next == head)
                    {
                        new_node->next = head;
                        ptr->next = new_node;
                        cout << "Node inserted at the end"<< endl;
                    }
                    else
                    {
                        new_node->next = ptr->next;
                        ptr->next = new_node;
                        cout << "Node inserted in between"<< endl;
                    }
                }
            }

        }

        //5. Delete node by unique key 
        void deleteNodeByKey (int k)
        {
            Node* ptr = nodeExists(k);
            if (ptr == NULL)
            {
                cout << "No node exists with key value of  : "<< k
                <<endl;
            }
            else
            {
                
                if (ptr == head)
                {
                    if(head->next == NULL)
                    {
                        head = NULL;
                        cout <<"Head node unlinked.. List empty";
                    }
                    else
                    {
                        Node* ptr = head;
                        while (ptr->next != head)
                        {
                            ptr = ptr->next;
                        }
                        ptr->next = head->next;
                        head = head->next;
                        cout << "Node UNLINKED with keys value : "<<k<< endl;
                    }
                }
                else
                {
                    Node* temp = NULL;
                    Node* prevptr = head;
                    Node* currentptr = head->next;

                    while (currentptr != NULL)
                    {
                        if(currentptr->key == k)
                        {
                            temp = currentptr;
                            currentptr = NULL;
                        }
                        else
                        {
                            prevptr = prevptr->next;
                            currentptr = currentptr->next;
                        }

                    }
                    prevptr->next = temp->next;
                    cout << "Node UNLINKED with keys value : "<< k<< endl;
                }
            }

        }

        //6th update node
        void updateNodeByKey(int k, int new_data)
        {
            Node* ptr = nodeExists(k);
            if(ptr != NULL)
            {
                ptr->data = new_data;
                cout << "Node data updated successfully"<< endl;
            }
            else
            {
                cout << "Node doesnt exist with key value : "<< k<< endl;
            }
        }

        //7th pricing 
        void pintList()
        {
            if(head == NULL)
            {
                cout << "No Nodes in singly linked list";
            }
            else
            {
                cout <<endl<< "head address : "<< head << endl;
                cout <<"Singly linked list values : "<< endl;

                Node* temp = head;

                do{
                    cout << "(" << temp->key<<","<<temp->data<<","<<temp->next<<") -->";
                    temp = temp->next;

                }while (temp != head);
            }
        }

};

int main()
{
    //Will be same as before linked lists.
};