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
void PrintRR(Person *first);
int opt;
int main(){
   
    do{
        cout<<"\nEnter 1 to insertion \nEnter 2 to PrintRR linked list\nEtner 3 to display list"";
        cin>>opt;
        switch (opt)
        {
        case 1:
            cout<<"\nIn insertion:\n ";
            insert();
            break;
        case 2:
            cout<<"\nIn PrintRR method:\n ";
            PrintRR(first);
            break;
        case 3:
            cout<<"\nIn dispaly method:\n ";
            display();
            break;
        default:
             cout<<"\nUnknown value\n: ";
            break;
        }
    }while (opt != 0);
    
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


void PrintRR(Person *p){
    if(p!=NULL){
       PrintRR(p->next) ;
       cout<<p->Id<<",";
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