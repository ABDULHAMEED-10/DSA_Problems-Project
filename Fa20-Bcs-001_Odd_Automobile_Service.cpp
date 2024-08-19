#include <iostream>
using namespace std;
struct customerEntries{
    int serviceType;
    int plateNum;
    int totalCustomer = 0;
    customerEntries *next = NULL;
    
};
customerEntries *front = NULL;
customerEntries *rear = NULL;

struct tunning
{ 
    
    int customerPlateNum ;
    tunning* next=NULL;
    customerEntries* Address = NULL;
    
};


struct electric
{
    
    int customerPlateNum ;
    electric* next=NULL; 
    customerEntries* Address = NULL;  
};


struct suspension
{
    
    int customerPlateNum ;
    suspension* next=NULL;
    customerEntries* Address = NULL;
    
};
struct mechanics{
    int customerDeal = 0;
    mechanics * next = NULL;

    tunning * tunningFront = NULL;
    tunning * tunningRear = NULL;
    

    electric * electricFront = NULL;
    electric * electricRear = NULL;

    suspension * suspensionFront = NULL;
    suspension * suspensionRear = NULL;

    

};
mechanics * firstOfMechanics = NULL;
mechanics * lastOfMechanics = NULL;

customerEntries* dequeueOfCustomer();
void enqueueOfCustomer();
void Mechanics();

void InsertInPriorityQueue();
void InsertIndoubleEndQueueTunning();

void InsertInCircularQueue();

void displaySuspensionCustomer();
void displayTunningCustomer();
void displayElectricCustomer();
void totalCustomerDeal();
int main() {
    int opt;
    do{
        cout<<"\nEnter your option:\n";
        cout<<"Enter 1 to cutomerEntries: \n";
        cout<<"Enter 2 to sent to mechanics\n";
        cout<<"Enter 3 to display customer that requested tunning: \n";
        cout<<"Enter 4 to display customer that requested Electric: \n";
        cout<<"Enter 5 to display customer that requested Suspension: \n";
        cout<<"Enter 6 to display Number of dealed customers of all services: \n";
        cout<<"Enter 0 to exit \n";
        
	    cin>>opt;
        switch (opt)
        {
        case 1:
            enqueueOfCustomer();
            break;
        case 2:
            Mechanics();
            break;
        case 3:
            displayTunningCustomer();
            break;
        case 4:
            displayElectricCustomer();
            break;
        case 5:
            displaySuspensionCustomer();
            break;
        case 6:
            totalCustomerDeal();
            break;
        
        default:
            break;
        }
    }while(opt!=0);
	
}
void enqueueOfCustomer(){
    customerEntries * current , *p;
    current = new customerEntries;  
    p->totalCustomer++;
    cout<<"Enter The Customer`s car PlateNumber ONLY NUMBER:" ;
    cin>>current->plateNum;
    cout<<"Enter Car service Type ";
    cin>>current->serviceType;
	if(front == NULL || rear==NULL){
        front = rear = current;
    }
    else{
        rear->next = current;
        rear=rear->next; 
    }	
}
customerEntries* dequeueOfCustomer(){
    customerEntries* p , *q , *temp;
    
    p = front;
    if(p==NULL){
        q = NULL;
        cout<<"Nothing to delete;";
    }
    else if( front = rear){
        q = front;
        front = NULL;
        rear = NULL;
    }
    else{
        temp = q = p = front;
        p = p->next;
        delete temp;
    }
    return q; 	
}

void Mechanics(){
    mechanics *current ,*q ;
    customerEntries *p;
    
    for(int i =0; i<3;i++){
        current = new mechanics;

        if(firstOfMechanics == NULL && lastOfMechanics == NULL){
            lastOfMechanics =firstOfMechanics = current;
        }
        else{
            lastOfMechanics->next = current;
            lastOfMechanics = current;
        }  
    }
    p=dequeueOfCustomer();
    
    if(p->serviceType==1){
        InsertIndoubleEndQueueTunning();

    }
    else if(p->serviceType==2){
        InsertInCircularQueue();
    }
    else if(p->serviceType==3){
        InsertInPriorityQueue();
    }

}
void InsertIndoubleEndQueueTunning(){  
    customerEntries * k ;
    k = dequeueOfCustomer();
 
    mechanics *p;    
    p = firstOfMechanics;
    
    tunning *frnt,*reear ;
    frnt = p->tunningFront;
    reear = p->tunningRear;
   
    
    reear->customerPlateNum = k->plateNum;
    
    if(frnt == NULL || reear == NULL){
        frnt = reear = k
        
    }
    else{
        //insert at rear
        reear ->next = k;
        reear = k;  
        //insert at front
        k = dequeueOfCustomer();
        k->next = frnt;
        frnt=k;
    }  
    p->customerDeal++;  
     
    
}   

void InsertInCircularQueue(){
    customerEntries*k;
    mechanics* q;
    q = firstOfMechanics->next;
    electric* p,*frnt,*reear ;
    
    frnt = q->electricFront;
    reear = q->electricRear;

    k = dequeueOfCustomer();

    frnt->customerPlateNum = k->plateNum;

    if(frnt == NULL)
    {
        k->next = k;
        frnt = k;
    }
    else{
        k ->next = frnt ->next;
        frnt ->next = k;
        frnt = k;
    }
    q->customerDeal++;
}
void InsertInPriorityQueue(){
    customerEntries *k;
    mechanics* q;
    q = firstOfMechanics->next->next;
    suspension *frnt,*reear ,*temp;

    frnt = q->suspensionFront;
    temp = q->suspensionFront;
    reear = q->suspensionRear;

    k = dequeueOfCustomer();

    frnt->customerPlateNum = k->plateNum;

    int key = k->plateNum;
    if(frnt == NULL || key<frnt->customerPlateNum){
        k->next= frnt;
        frnt = k;
    }
    else{
        while (temp->next!=NULL && temp->next->customerPlateNum < key)
        {
            temp = temp ->next;
        }
        k ->next = temp->next;
        temp->next = k;
    }
    
    q->customerDeal++; 
    
}
void displayTunningCustomer(){
    
    mechanics* q;
    q = firstOfMechanics;
    tunning* p;
    p = q->tunningFront;
    

    while (p!=NULL)
    {
        cout<<p->customerPlateNum<<"\t";
        p=p->next;
    }

    if(p == NULL ){
        cout<<"Nothing to display\n";   
    }
                
    
}
void displayElectricCustomer(){
    mechanics* q;
    q = firstOfMechanics->next;
    
    electric* p;
    p = q->electricFront;
    

    while (p!=NULL)
    {
        cout<<p->customerPlateNum<<"\t";
        p=p->next;
    }

    if(p == NULL ){
        cout<<"Nothing to display\n";   
    }
}

void displaySuspensionCustomer(){
    mechanics* q;
    q = firstOfMechanics->next->next;
    
    suspension* p;
    p = q->suspensionFront;

    while (p!=NULL)
    {
        cout<<p->customerPlateNum<<"\t";
        p=p->next;
    }

    if(p == NULL ){
        cout<<"Nothing to display\n";   
    }
}

void totalCustomerDeal(){
    mechanics *m;
    m = firstOfMechanics;

    cout<<"Tunning customer "<<m->customerDeal<<"\n";
    cout<<"electric customer "<<m->next->customerDeal<<"\n";
    cout<<"suspension customer "<<m->next->next->customerDeal<<"\n";

}


