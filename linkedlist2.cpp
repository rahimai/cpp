//Detect loop in a linked list

class List{

    public: 
    int data;
    List* next; 

};


//Function for detecting loop in a linked list
bool loop_detector(List* node){
    
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






    delete head, second, third, fourth, fifth, tail;
}