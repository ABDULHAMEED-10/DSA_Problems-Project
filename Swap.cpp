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
void swap(int , int);
int opt;
int option;
bool search(int);
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
        cout<<"\nEnter 2 to swap linked list\nEtner 3 to display list";
        cin>>option;
        switch (option)
        {
        case 2:
            int a ;
            int b ;
            cout<<"\nEnter values to swap them:\n ";
            cout<<"Enter number 1:";
            cin>>a;
            cout<<"Enter number 2:";
            cin>>b;
            swap(a , b);
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


void swap (int a , int b){
    Person  *s,*t,*prevA , *prevB , *x , *w , *l ;
    s = first;
    t = first;

    if((search(a) == true) && (search(b)==true)){
        cout<<"Values found";
        //taking address
        while (s != last)
        {
            if(s->Id == a){
                break;
            }
            else{
                prevA = s;
                s = s->next;
            }    
        }
        while (t != last)
        {
            if(t->Id == b){
                break;
            }
            else{
                prevB = t;
                t = t->next;
            }    
        } 
        if(s == first && t == last && first->next != last){
            Person *temp1;
            temp1 = s->next;
            last->next = temp1;
            prevB->next = s;
            s->next = NULL;
            last = s;
            first = t;
            
        }
        
        else if(s == first && t!=last && s->next != t  && first->next != last){
            x = first->next;
            w = t->next;
            prevB->next = first;
            first->next =w;
            t->next =x;
            first = t;
        }
        else if(s == first && t!=last && s->next == t  && first->next != last){
            w = t->next;
            s->next  = w;
            t->next = s; 
            first = t; 
        }
       
        else if(s!=first && t!=last && s!=last && t!=first && s->next == t && first->next != last ){
            w = t->next;
            prevA->next = t;
            t->next = s;
            s->next = w;
        }
        else if(s!=first && t!=last && s!=last && t!=first && t->next == s && first->next != last ){
            w = s->next;
            s->next = t;
            t->next = w;
            prevB->next =s;

        }
        else if(s == last && t == first && first->next != last){
            Person *j;
            j = t->next;
            prevA ->next = t;
            t->next = NULL;
            s->next = j;
            last = t;
            first = s;
                  
        }
        

        else if(s == last && t != first && first->next != last && prevA!=t){
 
            w= t->next;
            prevB->next = s;
            s->next = w;
            prevA->next=t;
            t->next = NULL;
            last = t;

          
        }
        else if(s == last && t != first && first->next != last && prevA==t){
 
            
            s->next = t;
            prevB->next = s;
            t->next = NULL;
            last = t;

          
        }
        else if(t == last && s != first && first->next != last && prevB==s){
 
            prevA->next = t;
            t->next = s;
            s->next = NULL;
            last = s;

          
        }
        else if(t == first && s != last && first->next != last && prevA!=t){
 
            w= t->next;
            l=s->next;
            prevA->next =t;
            t->next=l;
            s->next=w;
            first = s;
          
        }
        else if(t == first && s != last && first->next != last && prevA==t){
 
            w =  s->next;
            s->next= t;
            t->next = w;
            first = s;
          
        }
        else if(s != first && t==last  && first->next != last){
            prevA->next = last;
            t->next = s->next; 
            prevB->next = s;
            s->next = NULL;
            last = s;
           
        }
        // two nodes only
        else if(first->next == last){
            
            x = first;
            l = last;
            l ->next = x;
            x ->next =NULL;
            last = x;
            first = l;
        }
        // x at any place y at any place
        else if(s!=first && t!=last && s->next != t){
            w = s->next;
            l = t->next;
            prevA->next = t;
            t->next = w;
            prevB->next = s;
            s->next = l;

        }
        // x at any place y at any place
        else if(t!=first && s!=last && t->next != s){
            w = t->next;
            l = s->next;
            prevB->next = s;
            s->next = w;
            prevA->next = t;
            t->next = l;

        }
        //one node only
        else if(first == last){
            last = first;
        }
  
    }
    else{
        cout<<"continue";
    }
}
bool search(int key){
    Person *p = first;
    bool temp = false;
    while (p!=NULL)
    {
        if(p->Id == key){
            temp = true;
            break;
        }  
        else{
            p = p->next;
        }  
    }
    return temp;
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