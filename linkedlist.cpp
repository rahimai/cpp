//Write a function that counts the number of times a given int occurs in a Linked List 
#include <iostream>

using namespace std;

class List{

    public: 
    int data;
    List* next; 

};

int search_key(List* node, int key_value){

    int count = 0;
    while(node != NULL){

        if(node->data = key_value){
            count++;
        };
        node = node->next;
    };
};


int main(){

    int i_key;

    cout << "Enter integer to be searched for: " << endl;
    cin >> i_key;

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





}