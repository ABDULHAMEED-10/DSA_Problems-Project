#include <iostream>
using namespace std;
struct Person{
    int Id;
    Person *next = NULL ;
    Person *previous = NULL ;
    
    };
Person *first = NULL;
Person *last = NULL;
Person *current;

void insertion();
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
            insertion();
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
void insertion(){
    Person *current ;
    current = new Person;
    cout<<"Enter Id ";
    cin>>current->Id ;
    if(first == NULL){
    //current will store in first and last
    first = last = current;
    }
    else{
        last ->next = current;
        current->previous=last;
        last = current;
    }
}
void swap (int a , int b){
    Person  *s,*t , *w , *k , *l ,*j ;
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
                s = s->next;
            }    
        }
        while (t != last)
        {
            if(t->Id == b){
                break;
            }
            else{
                t = t->next;
            }    
        }
        if(s == first && t == last && first->next != last){
            w = t->previous;
            t->next = s->next;
            t->previous = NULL;
            w->next = s;
            s->previous = w;
            s->next = NULL;
            first = t;
            last = s;
            
        }
        else if(s == first && t!=last && s->next != t  && first->next != last){
            k = t->previous;
            l = t->next;
            w = s->next;
            t->next = s;
            t->previous  = NULL;
            t->next = w;
            k->next = s;
            s->previous = k;
            s->next = l;
            first = t;
        }
        else if(s == first && t!=last && s->next == t  && first->next != last){
            w = t->next;
            t->next = s;
            s->next = w;
            t->previous = NULL;
            s->previous = t;
            first = t;

        }
        else if(s != first && t!=last && s!=last && t!=first && s->next == t && first->next != last ){
            w = s->previous;
            k = t->next;
            t->next = s;
            s->next = k;
            w->next = t;
            t->next =s;
            s->next = k;
            t->previous = w;
            s->previous = t;

        }
        else if( s != first && t!=last && s!=last && t!=first &&  t->next == s && first->next != last ){
            w = t->previous;
            k = s->next;
            s->next = t;
            t->next = k;
            w->next = s;
            s->next =t;
            t->next = k;
            s->previous = w;
            t->previous = s;

        }
        else if(s == last && t == first && first->next != last){
            w = s->previous;
            s->next = t->next;
            s->previous = NULL;
            w->next  = t;
            t->next = NULL;
            t->previous = w;
            first = s;
            last = t;
        }
        else if(s == last && t != first && first->next != last && s->previous!=t){
            w = t->previous;
            k = s->previous;
            l= t->next;
            k->next = t;
            t->previous= k;
            t->next =NULL;
            w->next = s;
            s->previous = w;
            s->next = l;
            last = t;
            
          
        }
        else if(t == last && s != first && first->next != last && t->previous==s){
 
            k = s->previous;
            k->next = t;
            t->next = s;
            s->previous = t;
            t->previous = s;
            s->next = NULL;
            last = s;

        }
        
        else if(s == last && t != first && first->next != last && s->previous==t){
            k = t->previous;
            k->next = s;
            s->next = t;
            t->previous = s;
            s->previous = k;
            t->next = NULL;
            last = t;
            
          
        }
        else if(t == first && s != last && first->next != last && s->previous!=t){

          w = s->next;
          l = s->previous;
          s->next = t->next;
          s->previous = NULL;
          l->next = t;
          t->next = w;
          t->previous = l;
          first = s;

        }
        else if(t == first && s != last && first->next != last && s->previous==t){
            k = s->next;
            s->next = s->previous;
            s->previous = NULL;
            t->previous = s;
            t->next = k; 
            first = s;
        }
        // x as a first  at any place y as a last at any place
        else if(s!=first && t!=last && s->next != t){
            w = s->previous;
            k = s->next;
            l = t->next;
            j = t->previous;
            j->next = s;
            s->next = l;
            s->previous = j;
            w->next = t;
            t->next = k;
            t->previous = w;
        }
        // x as a last  at any place y as a first at any place
        else if(s!=last && t!=first && t->next != s){
            w = t->previous;
            k = t->next;
            l = s->next;
            j = s->previous;
            j->next = t;
            t->next = l;
            t->previous = j;
            w->next = s;
            s->next = k;
            s->previous = w;
        }
        
        else if(first->next == last){
            t->next = s;
            s->next = NULL;
            s->previous = t;
            t->previous = NULL;
            w = first;
            k = last;
            last = w;
            first = k;
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
    dis = first;
    while (dis!=NULL)
    {
        cout<<"\n"<< dis->Id<<",";
        dis = dis ->next; 
    }
    if(first == NULL ){
        cout<<"Before Intersection Nothing to display\n";   
    }  
}