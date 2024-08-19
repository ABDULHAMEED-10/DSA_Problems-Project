#include <iostream>
using namespace std;
struct Person{
    int Id;
    Person *next = NULL ;
    Person *previous = NULL ;
    };
Person *first1 = NULL;
Person *last1 = NULL;
Person *first2 = NULL;
Person *last2 = NULL;
Person *first3 = NULL;
Person *last3 = NULL;

Person * insertionA();
Person * insertionB();
void displayC();
void displayA();
void displayB();

Person * intersection(Person * , Person *);
int opt;
int option;
int main(){
        do{
        cout<<"\nEnter 1 to insertionA\nEnter 0 to exit insertionA ";
        cin>>opt;
        switch (opt)
        {
        case 1:
            cout<<"\nIn insertionA:\n ";
            cout<<"Inputs Of Linked list 1\n";
            insertionA();
            cout<<" Inputs Of Linked list 2\n";
            insertionB();
            break;

        default:
             cout<<"\ncontinue\n: ";
            break;
        }
    }while (opt != 0);

        do{
        cout<<"\nEnter 2 to get Intersection of linked list\nEtner 3 to display intersection list \nEnter 4 to dipaly list A\nEnter 5 to dipaly list B:";
        cin>>option;
        switch (option)
        {
        case 2:
            cout<<"\nIntersection method:\n ";
            intersection(first1,first2);
            break;
        case 3:
            cout<<"\nIn intersection dispaly method:\n ";
            displayC();
            break;
        case 4:
            cout<<"\nList 1:\n ";
            displayA();
            break;
        case 5:
            cout<<"\nList 2:\n ";
            displayB();
            break;
        
        default:
            cout<<"unKnown value\n: ";
            
            break;
        }
    }while (option !=0);
}
Person * intersection(Person *start1 , Person *start2){
    Person *current , *temp1,*temp2 ;
    
    temp1 = start1;
    temp2 = start2;
    
    
    while (temp2!=NULL) 
    {
        if(temp1->Id == temp2->Id ){
            current = new Person;
            current ->Id = temp1->Id;
            if(first3 == NULL){
                first3 = last3 = current;
            }
            else{
                last3 ->next = current;
                current->previous=last3;
                last3 = current;
            }
            temp1 = start1;
            temp2 = temp2->next;      
        }
        temp1 = temp1->next; 
        if(temp1==NULL){
            temp1 = start1;
            temp2 = temp2->next;
        } 
          
    }
    return first3 ;
}
Person* insertionA(){
    Person *current ;
    current = new Person;
    cout<<"Enter Id ";
    cin>>current->Id ;
    if(first1 == NULL){
    //current will store in first and last
    first1 = last1 = current;
    }
    else{
        last1 ->next = current;
        current->previous=last1;
        last1 = current;
    }
    return first1;
}
Person * insertionB(){
    Person *current ;
    current = new Person;
    cout<<"Enter Id ";
    cin>>current->Id ;
    if(first2 == NULL){
    //current will store in first and last
    first2 = last2 = current;
    }
    else{
        last2 ->next = current;
        current->previous=last2;
        last2 = current;
    }
    return first2;
}
void displayC(){
    Person *dis;
    dis = first3;
    while (dis!=NULL)
    {
        cout<<"\n"<< dis->Id<<",";
        dis = dis ->next; 
    }
    if(first3 == NULL ){
        cout<<"Before Intersection Nothing to display\n";   
    }  
}
void displayA(){
    Person *dis;
    dis = first1;
    while (dis!=NULL)
    {
        cout<<"\n"<< dis->Id<<",";
        dis = dis ->next; 
    }
    if(first1 == NULL ){
        cout<<"Before Intersection Nothing to display\n";   
    }  
}
void displayB(){
    Person *dis;
    dis = first2;
    while (dis!=NULL)
    {
        cout<<"\n"<< dis->Id<<",";
        dis = dis ->next; 
    }
    if(first2 == NULL ){
        cout<<"Before Intersection Nothing to display\n";   
    }  
}
