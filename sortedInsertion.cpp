#include <iostream>
using namespace std;
struct Person{
    int Id;
    Person *next = NULL ;
    };
Person *first = NULL;
Person *last = NULL;
Person *current;
//main
void insert();
void display();
void sortedInsertion();
int opt;
int option;
int main(){
   
    do{
        cout<<"\nEnter 1 to insertion\nEnter 0 to exit insertion ";
        cin>>opt;
        switch (opt)
        {
        case 1:
            cout<<"\nIn insertion:\n ";
            insert();
            break;

        default:
             cout<<"\ncontinue\n: ";
            break;
        }
    }while (opt != 0);
    
    do{
        cout<<"\nEnter 2 to sorted Insertion linked list\nEtner 3 to display list";
        cin>>option;
        switch (option)
        {
        case 2:
            sortedInsertion();
            break;
        case 3:
            cout<<"\nIn dispaly method:\n ";
            display();
            break;
        
        default:
            cout<<"unKnown value\n: ";
            
            break;
        }
    }while (option !=0);
    
}
void insert(){
    
    Person *current;
    current = new Person;  

    cout<<"Enter Id ";
    cin>>current->Id ;
    
    if(first == NULL){
    //current will store in first and last
    first = last = current;
    }
    else{
        //the newly created object will store in next of last
        last->next = current;
        //newly object will become current
        last = current;
    }
       
}


void sortedInsertion (){
    Person *Newcurrent , *temp;
    Newcurrent = new Person; 
    cout<<"Enter new Id to insert ";
    cin>>Newcurrent->Id ;
    temp = first;
    int key = Newcurrent->Id;
    
    if(first == NULL || key<first->Id){
        Newcurrent->next= first;
        first = Newcurrent;
    }
    else{
        while (temp->next!=NULL && temp->next->Id < key)
        {
            temp = temp ->next;
        }
        Newcurrent ->next = temp->next;
        temp->next = Newcurrent;
    }
      
}
void display(){
    Person *dis;
    //taking the first object of linked list
    
    dis = first;
    while (dis!=NULL)
    {
        cout<<"\n"<< dis->Id<<",";
        dis = dis -> next; 
    }
    if(first == NULL ){
        cout<<"Nothing to display\n";
        
    }  
}