//Detect loop in a linked list

#include <map>
#include <iostream>

using namespace std;

class List{

    public: 
    int data;
    List* next; 

};


//Function for detecting loop in a linked list
bool loop_detector(List* node){

    map<List*, bool> hash_map;
    bool cont = false;

    while(node != NULL && cont == false){

        if(hash_map.contains(node->next)){
            return true;
        }
        else{
            hash_map.insert({node, true});
        }
        node = node->next;
    }
    
    return false;
}


int main(){



    List* head = new List();
    List* second = new List();
    List* third = new List();
    List* fourth = new List();
    List* fifth = new List();
    List* tail = new List();

    head->data = 4;
    head->next = second;

    second->data = 1;
    second->next = third;

    third->data = 2;
    third->next = fourth;

    fourth->data = 1;
    fourth->next = fifth;

    fifth->data = 1;
    fifth->next = tail;

    tail->data = 5;
    tail->next = third;



    bool includes_loop = loop_detector(head);

    cout << "Loop: " << includes_loop << endl;


    delete head, second, third, fourth, fifth, tail;
}


void push(struct Node** head_ref, int new_data) 
{ 
    /* allocate node */
    struct Node* new_node = new Node; 
  
    /* put in the data */
    new_node->data = new_data; 
  
    new_node->flag = 0; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref) = new_node; 
} 