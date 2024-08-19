#include <iostream>
using namespace std;
int count = 1;

struct Car{
    string driverName;
    string carName;
    int regNum = count ;
    int carType;
    float kilometer ;
    Car *Cnext = NULL ;
    Car *Cprevious = NULL ;

    struct Ride *rideListFirsts = NULL;

    };
struct Ride{
    float km;
    float charges;
    string riderName ;
    Ride *Rnext = NULL ;
    Ride *Rprevious = NULL ;
    };


Car *firstOfCar = NULL;
Car *lastOfCar = NULL;



void registerCar();
void addRider();
void display();
void displayTypeIICar();
void displayRide();

int menu ;
int main(){

    do{
        cout<<"\nEnter your option:\nEnter 1 to register a new car:\nEnter 2 to get all details of car:\nEnter 3 to display type 2 cars:\nEnter 4 to add a new Rider:\nEnter 5 to display rider details:";
        cin>>menu;
        switch (menu)
        {
        case 1:
        cout<<"\nRegister a new Car\n";
            registerCar();
            break;
        case 2:
        cout<<"\nAll details of Car\n";
            display();
            break;
        case 3:
        cout<<"\nDisplay type II car\n";
            displayTypeIICar;
            break;
        case 4:
        cout<<"\nAdd a new Rider\n";
            addRider();
            break;
        case 5:
        cout<<"\nRiders with details\n";
            displayRide();
            break;
        default:
            break;
        }
    }while(menu!=0);


}
void registerCar(){
    Car *current;
    current = new Car;
    count++;
    cout<<"Enter Driver name: ";
    cin>>current->driverName;

    cout<<"Enter Car name: ";
    cin>>current->carName;

    cout<<"Enter Reg number: ";
    cin>>current->regNum  ;

    cout<<"Enter car type: ";
    cin>>current->carType;

    cout<<"Enter Km: ";
    cin>>current->kilometer;

    if(firstOfCar == NULL){
        firstOfCar = lastOfCar = current;
    }
    else{
        lastOfCar ->Cnext = current;
        current->Cprevious=lastOfCar;
        lastOfCar = current;
    }


}
void addRider(){
    Car * current ,*p;
    Ride * l;
    current = new Car;
    cout<<"Enter rider Name: ";
    cin>>l->riderName;
    cout<<"Enter Distance to cover in Km: ";
    cin>>l->km;
    cout<<"Enter Charges: ";
    cin>>l->charges;

    if( p->rideListFirsts == NULL){
        p->rideListFirsts  = p->rideListLasts = current;
        
    }
    else{
        p->rideListLasts ->Cnext = current;
        current->Cprevious=p->rideListLasts;
        p->rideListLasts = current;
    }
}
void display(){
    Car *dis;
    dis = firstOfCar;
    while (dis!=NULL)
    {
        
        cout<<"\nCar Name:"<< dis->carName <<"\n";
        cout<<"Driver Name:"<< dis->driverName <<"\n";
        cout<<"Car Type"<< dis->carType<<"\n";
        cout<<"Meter In KM"<< dis->kilometer<<"\n";
        cout<<"Registeration Number"<< dis->regNum<<"\n";

        dis = dis ->Cnext; 
    }
    if(firstOfCar == NULL ){
        cout<<"Nothing to display\n";   
    }  
}
void displayTypeIICar(){
    Car *dis , *p;
    dis = firstOfCar;
    p = firstOfCar;
    
    while (dis!=NULL)
    {
        if(dis->carType == 2 ){
            cout<<"\nCar Name:"<< dis->carName <<"\n";
            cout<<"\nDriver Name:"<< dis->driverName <<"\n";
            cout<<"\nCar Type:"<< dis->carType<<"\n";
            cout<<"\nMeter In KM:"<< dis->kilometer<<"\n";
            cout<<"\nRegisteration Number:"<< dis->regNum<<"\n";

            dis = dis ->Cnext;      
        } 
        else{
            dis = dis ->Cnext;
        } 
    }
    
    if(firstOfCar == NULL ){
        cout<<"Nothing to display\n";   
    }  
}
void displayRide(){
    Car *dis , *k;
    Ride * l;
    dis = k->rideListFirsts;
    while (dis!=NULL)
    {
        cout<<"\nRider Name:"<< l->riderName <<"\n";
        cout<<"\nMeter In KM:"<< l->km<<"\n";
        cout<<"\nCharges:"<< l->charges<<"\n";

        dis = dis ->Cnext; 
        
        
    }
    if(k->rideListFirsts == NULL ){
        cout<<"Nothing to display\n";   
    } 
}