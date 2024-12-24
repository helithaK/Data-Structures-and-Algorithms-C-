#include <iostream>
using namespace std;

class Node{
    public:
        int key;
        int data;
        Node* next;
        Node* previous;

        Node()
        {
            key = 0;
            data = 0;
            next = NULL;
            previous = NULL;
        }

        Node(int k, int d)
        {
            key = k;
            data = d;
        }
};

class DoublyLinkedList{
    public:
        Node* head;

        DoublyLinkedList()
        {
            head = NULL;
        }
        DoublyLinkedList(Node *n)
        {
            head = n;
        }

        //1. chack if node exists using key value
        Node* checkIfNodeExists(int k)
        {
            Node* temp = NULL;
            Node* ptr = head;

            while(ptr !=NULL)
            {
                if (ptr->key == k)
                {
                    temp = ptr;
                }
                ptr = ptr->next;
            }

            return temp;
        }

        //2. Append a node to the list
        void appendNode(Node* n)
        {
            if(checkIfNodeExists(n->key)!=NULL)
            {
                cout << "Node already exists with key value : " << n->key << ". Append another node with different key value"<< endl;
            }
            else
            {
                if (head == NULL)
                {
                    head = n;
                    cout << "Node appended"<<endl;
                }
                else
                {
                    Node* ptr = head;
                    while (ptr->next != NULL)
                    {
                        ptr = ptr->next;
                    }
                    ptr->next = n;
                    n->previous = ptr;
                    cout << "Node appended" << endl;
                }
            }

        }

        //3. Prepend Node - Attach a node at the start
        void prependNode(Node* n)
        {
            if (checkIfNodeExists(n->key)!=NULL)
            {
                cout << "Node already exists with the key value : "<< n->key << ". Append anither node with different key value" << endl;
            }
            else
            {
                if(head == NULL)
                {
                    head = n;
                    cout << "Node prepended as Head Node" << endl;
                }
                else
                {
                    head->previous = n;
                    n->next = head;
                    head = n;
                    cout << "Node prepended" << endl;

                }
                
            }
        }

        //4. inser a Node after a particular node in the list
        void insertNodeAfter( int k, Node *n)
        {
            Node* ptr = checkIfNodeExists(k);
            if (ptr == NULL)
            {
                cout << "No node exists with key value : "<< k << endl;

            }
            else
            {
                if(checkIfNodeExists(n->key)!= NULL)
                {
                    cout << "Node already exists with key value : "<< n->key << ". Append another node with different key value"<< endl;
                }
                else
                {
                    Node *nextNode = ptr->next;

                    //inserting at the end
                    if(nextNode == NULL)
                    {
                        ptr->next = n;
                        n->previous = ptr;
                        cout << "Node inserted at the END"<< endl;
                    }

                    //inserting inbetween
                    else
                    {
                        n->next = nextNode;
                        nextNode->previous = n;
                        n->previous = ptr;
                        ptr->next = n;

                        cout << "Node Inserted in Between" << endl;
                    }

                }
            }
        }
        
        // 5. Delete node by unique key. Basically De-link not delete.
        void deleteNodeByKey(int k)
        {
            Node* ptr = checkIfNodeExists(k);
            if (ptr == NULL)
            {
                cout << "No node exists with key value: "<< k<< endl;
            }
            else
            {
                if (head->key == k)
                {
                    head = head->next;
                    cout <<"Node UNLINKED with keys value : "<<k<<endl;
                }
                else
                {
                    Node *nextNode = ptr->next;
                    Node *prevNode = ptr->previous;

                    if(nextNode == NULL)
                    {
                        prevNode->next = NULL;
                        cout << "Node deleted at the END"<<endl;
                    }
                    //deleting in between
                    else
                    {
                        prevNode->next = nextNode;
                        nextNode->previous = prevNode;
                        cout <<"Node deleted in between" <<endl;

                    }

                }
            }
        }

        void updateNodeByKey(int k, int d)
        {
            Node* ptr = checkIfNodeExists(k);
            if(ptr!=NULL)
            {
                ptr->data = d;
                cout << "Node data updated successfully"<< endl;
            }
            else
            {
                cout <<"node doesnt exist with key value :"<< k<< endl;
            }


        }

        //7th Printing 
        void printList()
        {
            if (head == NULL)
            {
                cout << "No nodes in doubly linekd list";

            }
            else
            {
                cout << endl << "Doubly linked list values : ";
                Node* temp = head;

                while (temp!=NULL)
                {
                    cout << "(" << temp->key <<"," <<temp->data << ") <-->";
                    temp = temp->next;
                }
            }
        }

};

int main()
{
    DoublyLinkedList obj;
    int option;
    int key1, k1, data1;
    
    do
    {
        cout << "/n What operation do you want to perform? Select option number. Enter 0 to exit." << endl;
        cout << "1. appendNode()"<< endl;
        cout << "2. prependNode()"<< endl;
        cout << "3. insertNodeAfter()"<< endl;
        cout << "4. deleteNodeByKey()"<< endl;
        cout << "5. updateNodeByKey()"<< endl;
        cout << "6. print()"<< endl;
        cout << "7. Clear screen"<< endl<<endl;

        cin >> option;
        Node* n1 = new Node();
        //Node n1;

        switch(option)
        {
            case 0:
                break;
            case 1:
                cout << "Append Node operation \nEnter key and data of the Node to be appended" << endl;
                cin >> key1;
                cin >> data1;
                n1->key = key1;
                n1->data = data1;   
                obj.appendNode(n1);
                //cout <<n1.key<< "="<<n1.data <<endl;
                break;

            case 2:
                cout <<"Prepend Node Operation \n Enter key and data of the Node to be prepended" << endl;
                cin >> key1;
                cin >> data1;
                n1->key = key1; 
                n1->data = data1;
                obj.prependNode(n1);
                break;

            case 3:
                cout <<"Insert Node after operation \n Enter key of existing Node after whcih you want to insert this new node: " << endl;
                cin >> k1;
                cout << "Enter key and data of the new Node first: "<< endl;
                cin >>key1;
                cin >> data1;
                n1->key = key1;
                n1->data = data1;

                obj.insertNodeAfter(k1, n1);
                break;

            case 4:
                cout << "Delete Node by key operation -/n Enter key of the node to be deleted: "<< endl;
                cin >>k1;
                obj.deleteNodeByKey(k1);

                break;

            case 5:
                cout << "update Node by key operation - \n Enter key and new data to be updated"<< endl;
                cin >>key1;
                cin >> data1;
                obj.updateNodeByKey(key1, data1);

                break;
            
            case 6:
                obj.printList();

                break;

            case 7:
                system("cls");
                break;

            default:
                cout << "Enter proper option number "<< endl;
            
        }


    } while (option != 0);
    
    return 0;
}