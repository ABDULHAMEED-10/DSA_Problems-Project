#include <iostream>
using namespace std;
struct Person{
    int Id;
    Person *next = NULL ;
    };

Person *last = NULL;
Person *first = NULL;
Person *current;
//main
void insert();
void copyReverse(Person *start);
int opt;
int main(){
   
    do{
        cout<<"\nEnter 1 to insertion \nEnter 2 to CopyReverse linked list";
        cin>>opt;
        switch (opt)
        {
        case 1:
            cout<<"\nIn insertion:\n ";
            insert();
            break;
        case 2:
            cout<<"\nIn copyReverse method:\n ";
            copyReverse(first);
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
void copyReverse(Person *start){
    int v;
    Person *k  , *p , *dis , *temp;
    k = last;
    
    if(start == NULL){

        cout<<"No data to copy reverse";
    }

    else{
        p  = start;
        while(k!= start){
            temp = start;
            int v =  k->Id;
            k->Id = p->Id;
            p->Id = v;
            p = p->next;
            while(temp->next!=k){
                temp = temp->next;
            }
            k = temp;  
        } 
        dis = start;
        while (dis!=NULL)
        {
            cout<<"\n"<< dis->Id<<",";
            dis = dis -> next; 
        }    
    }      
}




