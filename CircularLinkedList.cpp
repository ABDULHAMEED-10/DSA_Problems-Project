#include <iostream>
using namespace std;
struct List{
    int num;
    List *next = NULL ;
    
};


List *headOfList1 = NULL;
List *headOfList2 = NULL;
List *headOfList3 = NULL;
List *insertionA();
List *insertionB();
void displayA();
void displayB();
void display();
List * sortion(List *);


List * maxNum();
int opt;
int main(){
    do{
        cout<<"\nEnter 1 to start insertion:\nEnter 0 to exit:";
        cin>>opt;
        switch(opt)
        {
            case 1:
                cout<<"\nIn insertion:\n ";
                cout<<"Inputs Of Linked list 1\n";
                insertionA();
                cout<<" Inputs Of Linked list 2\n";
                insertionB();
                break;
            default:
                cout<<"\ncontinue\n: ";
                break;
        }
        

    }while(opt!=0);
    
    do{
    cout<<"\nEnter 1 to get maximum Numbers list:\nEnter 2 to Display list 1:\nEnter 3 to display list 2:\nEnter 4 to display list 3\nEnter 0 to exit::";
    cin>>opt;
    switch(opt)
    {
        case 1:
            cout<<"In maximum Number method";
            maxNum();
            break;
        case 2:
        cout<<"In display List1:";
            displayA();
            break;
        case 3:
        cout<<"In display List2:";
            displayB();
            break;
        case 4:
        cout<<"In display final result list:";
            display();
            break;
        
        default:
            cout<<"\ncontinue\n: ";
            break;
    } 

    }while(opt!=0);
}

List * maxNum(){
    List * p , *current ,*q ;
    int temp;
    p = sortion(headOfList1);
    while (p->next!=headOfList1)
    {
        current = new List;
        current->num = p->num ;
        if(headOfList3 == NULL)
        {
            current->next = current;
            headOfList3 = current;
        }
        else{
            current ->next = headOfList3 ->next;
            headOfList3 ->next = current;
            headOfList3 = current;
        }  
    }
    q = sortion(headOfList2);
    while (q->next!=headOfList2)
    {
        current = new List;
        current->num = q->num ;
        if(headOfList3 == NULL)
        {
            current->next = current;
            headOfList3 = current;
        }
        else{
            current ->next = headOfList3 ->next;
            headOfList3 ->next = current;
            headOfList3 = current;
        }  
    }
    return headOfList3;
            
}
List* sortion (List * start){
    List *p, *c;
    p = start->next;
    int tem;
    while (p!= start)
    {
        c = p->next;
        while (c!=start)
        {
            
            if(p->num > c->num){
                tem = p->num;
                p->num = c->num;
                c->num = p->num;
            }
        
            c=c->next;
        }
        p = p->next;  
    }
    return p;
}

List* insertionA(){
    List *current  ;
    current = new List;
    cout<<"Enter Num ";
    cin>>current->num ;
    if(headOfList1 == NULL)
    
    {
        current->next = current;
        headOfList1 = current;
    }
    else{
        current ->next = headOfList1 ->next;
        headOfList1 ->next = current;
        headOfList1 = current;
    }
    return headOfList1;
}
List* insertionB(){
    List *current;
    current = new List;
    cout<<"Enter Num ";
    cin>>current->num ;
    if(headOfList2 == NULL)
    
    {
        current->next = current;
        headOfList2 = current;
    }
    else{
        current ->next = headOfList2 ->next;
        headOfList2 ->next = current;
        headOfList2 = current;
    }
    return headOfList2;

}


void display(){
    List *temp;
    temp = headOfList3->next;
    if(headOfList3 == NULL ){
        cout<<"Before Intersection Nothing to display\n";   
    } 
    else{
        
        while (temp!= headOfList3 )
        {
            cout<<"\n"<< temp->num<<",";
            temp = temp ->next; 
        }
        cout<<"\n"<< headOfList3->num<<",";
    }
     
}
void displayA(){
    List *temp;
    temp = headOfList1->next;
    if(headOfList1== NULL ){
        cout<<"Before Intersection Nothing to display\n";   
    }
    else{
        while (temp != headOfList1 )
        {
            cout<<"\n"<< temp->num<<",";
            temp = temp ->next; 
        }
        cout<<"\n"<< headOfList1->num<<",";
    }
}
void displayB(){
    List *temp;
    temp = headOfList2->next;
    if(headOfList2 == NULL ){
        cout<<"Before Intersection Nothing to display\n";   
    } 
    else{
        while (temp!= headOfList2 )
        {
            cout<<"\n"<< temp->num<<",";
            temp = temp ->next; 
        }
        cout<<"\n"<< headOfList2->num<<",";
            
    }
}


