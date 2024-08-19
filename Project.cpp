#include<iostream>
#include <climits>
using namespace std;
void register_new_vehicle();
void display_cars();
void display_bikes();
void display_type2_cars();
void new_booking();
void display_rides();
void find_earning();
void display_earning();
void admin_login();
void MANAGER_login();
void vehicelAndRecords();
void bookingAndCustomer();
void available_cars();
void available_bikes();
void update_status();
void all_drivers_record();
void all_cars_earnings();
void all_bikes_earnings();
void change_rates();
void MinDistance(int , bool) ;
int Dijkstra(int[6][6],int ,int ) ;
void tree(int);
bool search(int);

struct BST
{
    int num;
    BST* left = NULL;
    BST* right = NULL;
};


struct RIDE{
	string rider_name;
	int ride_charges;
	float distance_travelled;
	RIDE *next_ride;
};
struct VEHICLE{
	string vehicle_name;
	string vehicle_reg_no;
	string vehicle_type;
	string car_type;
	int per_km_rate;
	float km;

	string driver_name ;
	string driver_contact;
	string driver_address;
	string driver_id;
	
	VEHICLE *next_vehicle;
	VEHICLE *prev_vehicle;
	RIDE *first_ride;
	int total_earning;
	int no_of_rides;
	bool status;
};
VEHICLE *start_vehicle=NULL;
VEHICLE *end_vehicle=NULL;
VEHICLE *temp_vehicle=NULL;
RIDE *first_ride=NULL;
BST * root = NULL;

bool login_1=false;
bool login_2=false;

//////////////////////////////////////////////////////////////////////////////////////////
int main(){

	
	int option;
	
				cout<<"\n\t\t\t\t\t\t----------------------------------------------\n";
				cout<<"\n\t\t\t\t\t\t U B E R   M A N A G E M E N T   S Y S T E M"<<endl;	
				cout<<"\n\t\t\t\t\t\t----------------------------------------------\n";	
				admin_login();
		cout<<"\n-------------------------------------------\n";	
		cout<<"\t       MAIN MENU"<<endl;	
		cout<<"-------------------------------------------\n";	
		int login_choice = 1;
		cout<<"VEHICEL AND RECORDS.................PRESS 1 "<<endl;
		cout<<"BOOKINGS AND CUTOMERS...............PRESS 2 "<<endl;
		cout<<"EXIT................................PRESS 0 "<<endl;
		cout<<"-------------------------------------------\n";
		cin>>option;

	do{
		if(option==1){
					if(login_1==false)
					login_1=true;
					vehicelAndRecords();
				}
		
	////////////////////////////////////////////////////////////////////////////////////
			else if(option==2){
					if(login_2==false)
						//MANAGER_login();
					login_2=true;
					bookingAndCustomer();
			
			}
		
}while(option!=0);
return 0;		
}


void bookingAndCustomer(){
		cout<<"\n--------------------------------------------\n";	
				cout<<"\tB O O K I N G S AND C U S T O M E R"<<endl;	
				cout<<"--------------------------------------------\n";
					cout<<"| BOOKING.........................PRESS 1  |"<<endl;
					cout<<"| AVAILABEL VEHICLES..............PRESS 2  |"<<endl;
					cout<<"| CUSTOMER RECORD.................PRESS 3  |"<<endl;
					cout<<"| UPDATE Car/Bike STATUS..........PRESS 4  |"<<endl;
					cout<<"| GO VEHICEL AND RECORDS MENU.....PRESS 5  |"<<endl;
					cout<<"| GO MAIN AND LOGOUT..............PRESS 0  |"<<endl;
					cout<<"--------------------------------------------\n";
					int choice;
					cin>>choice;
				switch(choice){
						case 1:
							new_booking();
							break;
						
						case 2:
								int ch;
							do{
								cout<<"AVAILABLE CARS.............PRESS 1"<<endl;
								cout<<"AVAILABLE BIKES............PRESS 2"<<endl;
								cin>>ch;
							}while(ch!=1 && ch!=2);
							if(ch==1)
								available_cars();
							else	
								available_bikes();
							
							break;
						case 3:
							display_rides();
							break;	
						case 4:
							update_status();
							break;	
						case 5:
							vehicelAndRecords();
							break;	
						case 0:
							main();		
							
				}	
	
}

void vehicelAndRecords(){
			cout<<"\n-------------------------------------------\n";	
			cout<<"\tVEHICEL A N D RECORDS"<<endl;	
			cout<<"-------------------------------------------\n";
			cout<<"| REGISTER NEW VEHICLE............PRESS 1 |"<<endl;
			cout<<"| ALL REGISTERED VEHICLES.........PRESS 2 |"<<endl;
			cout<<"| AVAILABLE VEHICLES..............PRESS 3 |"<<endl;
			cout<<"| RIDES RECORD....................PRESS 4 |"<<endl;
			cout<<"| DRIVERS RECORD..................PRESS 5 |"<<endl;
			cout<<"| EARNINGS........................PRESS 6 |"<<endl;
			cout<<"| CHANGE RATE OF PER KM CHARGES...PRESS 7 |"<<endl;
			cout<<"| SEARCH A CAR WITH UNIQUE ID.....PRESS 8 |"<<endl;
			cout<<"| GO MAIN AND LOGOUT..............PRESS 9 |"<<endl;
			cout<<"| GO BOOKING AND CUSTOMER MENU...PRESS 10 |"<<endl;
			cout<<"| EXIT............................PRESS 0 |"<<endl;
			cout<<"-------------------------------------------\n";
					int choice;
					cin>>choice;
					bool chk ;
					int regNumToCheck;
					switch(choice){
						case 0:
							exit(1);
							break;
						case 10:
							bookingAndCustomer();
							break;
						case 9:
							main();
							break;
						case 8:
							
							cout<<"Enter reg Num of vehicel to search in store"<<endl;
							cin>>regNumToCheck;
							chk = search(regNumToCheck);
							if(chk){
								cout<<"Vehicel with this unique reg Num exist in store"<<endl;
							}
							else if (!chk){
								cout<<"Vehicel with this unique reg Num does not exist in store"<<endl;
							}
							
							break;
						case 1:
							register_new_vehicle();
							break;
						//////////////////////////////////////	
						case 2:
							cout<<"CARS.............PRESS 1"<<endl;
							cout<<"BIKES............PRESS 2"<<endl;
							int opt;
							cin>>opt;
							if(opt==1){
								display_cars();
							}
							if(opt==2){
								display_bikes();								
							}
								break;
						//////////////////////////////////////
						case 3:
								int ch;
							do{
								cout<<"AVAILABLE CARS.............PRESS 1"<<endl;
								cout<<"AVAILABLE BIKES............PRESS 2"<<endl;
								cin>>ch;
							}while(ch!=1 && ch!=2);
							if(ch==1)
								available_cars();
							else	
								available_bikes();
							break;
						
						////////////////////////////
						case 4:
							display_rides();
								break;
						////////////////////////////////////////
						case 5:
							all_drivers_record();
							
							break;
						case 6:
							int op;
							do{
								cout<<"EARNING OF ALL CARS.............PRESS 1"<<endl;
								cout<<"EARNING OF ALL BIKES............PRESS 2"<<endl;
								cout<<"EARNING OF SPECIFIC CAR/BIKE....PRESS 3"<<endl;
								cin>>op;
							}while(op!=1 && op!=2 && op!=3);
							if(op==1){
								all_cars_earnings();
							}
							if(op==2){
								all_bikes_earnings();								
							}	
								if(op==3){
									find_earning();								
							}
								break;
						case 7:
							change_rates();
							break;
						
					}
	}
VEHICLE *search_vehicle(string reg_no){
	VEHICLE *p=start_vehicle;
	while(p!=NULL){
		if(p->vehicle_reg_no==reg_no){
			break;
		}
		else{
			p=p->next_vehicle;
		}
	}
	return p;
}
void all_drivers_record(){
	cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t\t\tDRIVERS RECORD"<<endl;
	cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
		
	if(start_vehicle==NULL)
		cout<<"NO Any Record Of Driver Found !\n"<<endl;
	else{
		VEHICLE *p=start_vehicle;
		cout<<"\nDriver Names\tVehicle\t\tID Number\t\tContact No\t\tAddresses"<<endl;
	cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
		while(p!=NULL){
			cout<<p->driver_name<<"\t\t"<<p->vehicle_name<<"\t\t"<<p->driver_id<<"\t\t\t"<<p->driver_contact<<"\t\t\t"<<p->driver_address<<endl;
			p=p->next_vehicle;
		}	
	cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
}

}
void update_status(){
	cout<<"\n-------------------------------------------\n";	
	cout<<"\t    UPDATE CAR/BIKE STATUS"<<endl;	
	cout<<"-------------------------------------------\n";	
	cout<<"Enter CAR/BIKE Reg_No to Update Its Status:"<<endl;
	string reg_no;
	cin>>reg_no;
	VEHICLE *p=search_vehicle(reg_no);
	if(p==0){
		cout<<"No Any Vehicle Found of Reg No: "<<reg_no<<endl;
	}
	else{
		cout<<"Did The Vehicle Returned or Not (Y/N):"<<endl;
		string s;
		cin>>s;
		if(s=="y" or s=="Y"){
			p->status=true;
		}
		else if(s=="n" or s=="N"){
			cout<<"ok"<<endl;
		}
		else{
			cout<<"INVALID CHOICE !"<<endl;
		}
	}
	
}
// void MANAGER_login(){
// 		cout<<"\n-------------------------------------------\n";	
// 			cout<<"\t    MANAGER   L O G I N"<<endl;	
// 			cout<<"-------------------------------------------\n";	
// 			string userName;
// 			string password;
// 			do{
// 				cout<<"Enter Username:"<<endl;
// 				cin>>userName;
// 				cout<<"Enter Password:"<<endl;
// 				cin>>password;
// 				if(userName!="MANAGER" || password!="12345")
// 					cout<<"INCORRECT USERNAME OR PASSWORD !"<<endl;
// 		}while(userName!="MANAGER" || password!="12345");
		
// }

void admin_login(){
	cout<<"\n-------------------------------------------\n";	
		cout<<"\t      A D M I N   L O G I N"<<endl;	
		cout<<"-------------------------------------------\n";	
		string userName;
		string password;
		do{
			cout<<"Enter Username:"<<endl;
			cin>>userName;
			cout<<"Enter Password:"<<endl;
			cin>>password;
			if(userName!="admin" || password!="1234")
				cout<<"INCORRECT USERNAME OR PASSWORD !"<<endl;
	}while(userName!="admin" || password!="1234");
	
}

void register_new_vehicle(){
	int reg;
	cout<<"\t-------REGISTER NEW CAR--------"<<endl;
	temp_vehicle=new VEHICLE();
	int choice;
	do{
		cout<<"Select Vehicle Type:"<<endl;
		cout<<"CAR.........PRESS 1"<<endl;
		cout<<"BIKE........PRESS 2"<<endl;
		cin>>choice;
		if(choice==1)
			temp_vehicle->vehicle_type="car";
		else if(choice==2)
			temp_vehicle->vehicle_type="bike";
		else 
			cout<<"Invalid Choice"<<endl;
			
	}while(choice!=2 && choice!=1);
	cout<<"\nVehicle  Name:"<<endl;
	cin>>temp_vehicle->vehicle_name;

	
	bool q;
	string reg_no;
	while (true)
	{
		cout<<"Vehicel Unique Registration No:"<<endl;
		cin>>reg_no;
		for(int i =0; i<reg_no.length();i++){
			while (!(reg_no[i]>='0' && reg_no[i]<='9'))
			{
				cout<<"vehicel Unique Registration No: Only In Integer:"<<endl;
				cin>>reg_no;
			}
		}
		
		reg = stoi(reg_no) ;
		q=search(reg);
		if(q){
			cout<<"\nINVALID REG-No:"<<endl;
			cout<<"\tA Vehicle with Reg No "<<reg_no<<" Already Exists"<<endl;
		}
		else {
			break;
		}
	}
	
	temp_vehicle->vehicle_reg_no=reg_no;
	tree(reg);//storing reg numbr in bst tree
	temp_vehicle->status=true;  // it means thi scar/bike is available for booking


	int ch;
	if(choice==1){
		do{
			cout<<"Select Car Type:"<<endl;
			cout<<"Uber Go.........PRESS 1"<<endl;
			cout<<"Mini........... PRESS 2"<<endl;
			cout<<"Business........PRESS 3"<<endl;
			cin>>ch;
			if(ch==1)
				temp_vehicle->car_type="uber go";
			else if(ch==2)
				temp_vehicle->car_type="mini";
			else if(ch==3)
				temp_vehicle->car_type="business";	
			else 
				cout<<"Invalid Choice"<<endl;
	}while(ch!=2 && ch!=1 && ch!=3);
	}
	cout<<"Enter The rate of Per/km Distance Charges:Integer only"<<endl;
	cin>>temp_vehicle->per_km_rate;
	
	cout<<"--------------------Please Enter Driver's Details-------------------"<<endl;
	cout<<"Enter Driver Name:"<<endl;
	cin>>temp_vehicle->driver_name;
	
	cout<<"Enter Driver ID:"<<endl;
	cin>>temp_vehicle->driver_id;
	for(int i =0; i<temp_vehicle->driver_id.length();i++){
		while (!(temp_vehicle->driver_id[i]>='0' && temp_vehicle->driver_id[i]<='9'))
		{
			cout<<"Enter Driver ID:"<<endl;
			cin>>temp_vehicle->driver_id;
		}
	}
	cout<<"Enter Driver's' Contact No:"<<endl;
	string contact;
	cin>> contact;
	for(int i =0; i<contact.length();i++){
		while (!(contact[i]>='0' && contact[i]<='9'))
		{
			cout<<"Enter Driver's' Contact No:Integers only:"<<endl;
			cin>> contact;
		}
	}
	while (contact.length() != 11)
	{
		cout<<"Enter Driver's' Contact No: length should be 11:"<<endl;
		cin>> contact;
	}
	
	
	temp_vehicle->driver_contact = contact;
	cout<<"Enter Driver Address:"<<endl;
	cin>>temp_vehicle->driver_address;

	if(start_vehicle==NULL){
		start_vehicle=end_vehicle=temp_vehicle;
	}
	else{
		end_vehicle->next_vehicle=temp_vehicle;
		temp_vehicle->prev_vehicle=end_vehicle;
		end_vehicle=temp_vehicle;	
	}
}

void available_cars(){
		cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"\t\t\t\t\t\tAVAILABLE CARS"<<endl;
		cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
	
	bool found=false;
	if(start_vehicle==NULL)
		cout<<"No Any Car is Available!\n"<<endl;
	else{
		VEHICLE *p=start_vehicle;
		cout<<"\nCar Names\tReg No\t\tCar Type\t\tDriver Names\t\tPer/Km Rate\tKM Travelled"<<endl;
		cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
		while(p!=NULL){
			if(p->vehicle_type=="car" && p->status==true){
					cout<<p->vehicle_name<<"\t\t"<<p->vehicle_reg_no<<"\t\t"
				<<p->car_type<<"\t\t\t"<<p->driver_name<<"\t\t\t"<<p->per_km_rate<<"\t\t"<<p->km<<endl;
				found=true;
			}
			p=p->next_vehicle;
		}	
		if(found==false)
			cout<<"Sorry, No Any Car is Availabel Now !\n"<<endl;
		cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
}
}

void available_bikes(){
		cout<<"--------------------------------------------------------------------------------------------"<<endl;
		cout<<"\t\t\t\tAVAILABLE BIKES"<<endl;
		cout<<"--------------------------------------------------------------------------------------------"<<endl;
	bool found=false;
	if(start_vehicle==NULL)
		cout<<"No Any Bike is Available!\n"<<endl;
	else{
		VEHICLE *p=start_vehicle;
		cout<<"\nBike Names\tReg No\t\tDriver Names\t\tPer/Km Rate\tKM Travelled"<<endl;
		cout<<"--------------------------------------------------------------------------------------------"<<endl;
		while(p!=NULL){
			if(p->vehicle_type=="bike" && p->status==true){
				cout<<p->vehicle_name<<"\t\t"<<p->vehicle_reg_no<<"\t\t"<<p->driver_name<<"\t\t\t"<<p->per_km_rate<<"\t\t"<<p->km<<endl;	
				found=true;
			}
			p=p->next_vehicle;
		}	
		if(found==false)
			cout<<"Sorry, No Any Bike is Availabel Now !\n"<<endl;
		cout<<"--------------------------------------------------------------------------------------------"<<endl;
}
}
void display_cars(){
		cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"\t\t\t\t\t\t ALL REGISTERED CARS"<<endl;
		cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
	bool found=false;
	if(start_vehicle==NULL)
		cout<<"No Any Vehicle is Registered Yet!\n"<<endl;
	else{
		VEHICLE *p=start_vehicle;
		cout<<"\nCar Names\tReg No\t\tCar Type\t\tDriver Names\t\tPer/Km Rate\tKM Travelled"<<endl;
		cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
		while(p!=NULL){
			if(p->vehicle_type=="car"){
				cout<<p->vehicle_name<<"\t\t"<<p->vehicle_reg_no<<"\t\t"
				<<p->car_type<<"\t\t\t"<<p->driver_name<<"\t\t\t"<<p->per_km_rate<<"\t\t"<<p->km<<endl;
				found=true;
			}
			p=p->next_vehicle;
		}	
		if(found==false)
			cout<<"No any Car has registered Yet !\n"<<endl;
		cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
}
}
void display_bikes(){
		cout<<"--------------------------------------------------------------------------------------------"<<endl;
		cout<<"\t\t\t\t\tALL REGISTERED BIKES"<<endl;
		cout<<"--------------------------------------------------------------------------------------------"<<endl;
	bool found=false;
	if(start_vehicle==NULL)
		cout<<"No Any Vehicle is Registered Yet!"<<endl;
	else{
		VEHICLE *p=start_vehicle;
		cout<<"\nBike Names\tReg No\t\tDriver Names\t\tPer/Km Rate\tKM Travelled"<<endl;
		cout<<"--------------------------------------------------------------------------------------------"<<endl;
	
		while(p!=NULL){
			if(p->vehicle_type=="bike"){
				cout<<p->vehicle_name<<"\t\t"<<p->vehicle_reg_no<<"\t\t"<<p->driver_name<<"\t\t\t"<<p->per_km_rate<<"\t\t"<<p->km<<endl;	
					found=true;
			}
			p=p->next_vehicle;
		}	
		if(found==false)
			cout<<"No any Bike has registered  Yet !\n"<<endl;
		cout<<"--------------------------------------------------------------------------------------------"<<endl;
}	
}
void change_rates(){
	cout<<"\n\t\t\t\t\t----------------------------------------------\n";
	cout<<"\n\t\t\t\t\t\t\t  TRAVEL RATES"<<endl;	
	cout<<"\n\t\t\t\t\t----------------------------------------------\n";
	if(start_vehicle==NULL)
		cout<<"\n No Any Vehicle is Registered Yet,So Rates cannot be changed!\n"<<endl;
	else{
		cout<<"Enter Reg No of Car/Bike To change Its Rates:"<<endl;
		string reg_no;
		cin>>reg_no;
		for(int i =0; i<reg_no.length();i++){
			while (!(reg_no[i]>='0' && reg_no[i]<='9'))
			{
				cout<<"vehicel Unique Registration No: Only In Integer:"<<endl;
				cin>>reg_no;
			}
		}
		VEHICLE *p=search_vehicle(reg_no);
		if(p==0){
			cout<<"SORRY! VEHICLE NOT FOUND"<<endl;
		}
		else{
			cout<<"----------VEHICLE DETAILS-----------"<<endl;
			cout<<"VEHICLE NAME:\t"<<p->vehicle_name<<endl;
			cout<<"VEHICLE TYPE:\t"<<p->vehicle_type<<endl;
			if(p->vehicle_type=="car"){
				cout<<"CAR TYPE:\t"<<p->car_type<<endl;
			}
			cout<<"CURRENT PER/KM DISTANCE CHARGES:\t"<<p->per_km_rate<<endl;
			cout<<"\nENTER NEW PER/KM DISTANCE CHARGES:"<<endl;
			cin>>p->per_km_rate;
		
			
		}
	}
	
}
void new_booking(){
	cout<<"\n\t\t\t\t\t----------------------------------------------\n";
	cout<<"\n\t\t\t\t\t\t\t  B O O K I N G"<<endl;	
	cout<<"\n\t\t\t\t\t----------------------------------------------\n";	
	if(start_vehicle==NULL)
		cout<<"\n No Any Car is Registered Yet,So Ride cannot be added !\n"<<endl;
	else{
		available_cars();
		available_bikes();
		string reg_no;
		cout<<"Enter Reg No of Car/Bike to add ride details:"<<endl;
		cin>>reg_no;
		for(int i =0; i<reg_no.length();i++){
			while (!(reg_no[i]>='0' && reg_no[i]<='9'))
			{
				cout<<"vehicel Unique Registration No: Only In Integer:"<<endl;
				cin>>reg_no;
			}
		}
		VEHICLE *p=search_vehicle(reg_no);
		if(p==0){
			cout<<"Car Not Found"<<endl;
		}
		else if(p->status==false){
			cout<<"Sorry:"<<endl;
			cout<<"\n\tCurrently The Vehicle "<<reg_no<<" is on another Ride"<<endl;
		}
		else{
			p->status=false;
			p->no_of_rides+=1;  // incrementing in no of rides
			
			RIDE *temp_ride=new RIDE();
			int points[6][6] = {
			{0,11,0,0,0,4},//0
			{11,0,14,11,0,0},//1
			{0,14,0,12,0,0},//2
			{0,11,12,0,6,8},//3
			{0,0,0,6,0,0},//4
			{4,0,0,8,0,0},//5
			};
			cout<<"------------Enter Ride Details--------------"<<endl;
			cout<<"Enter Rider Name:"<<endl;
			cin>>temp_ride->rider_name;
		
			int point1;
			int point2;
			cout<<"0) Taramri \t\t 1) BaniGala \t\t 2) BlueArea \t\t 3) Faizabad \t\t 4) PirWadhai \t\t 5) BurmaTown "<<endl;
			cout<<"\n Enter The above Number Of Your Area to select your starting location \n"<<endl;
			cin>>point1;
			cout<<"\n Enter The above Number Of Your Area to select your destination location"<<endl;
			cin>>point2;
			while (point1<0 || point1>5 )
			{
				cout<<"\n Enter The above Number Of Your Area to select your starting location \n"<<endl;
				cin>>point1;
			}
			while (point2<0 || point2>5)
			{
				cout<<"\n Enter The above Number Of Your Area to select your destination location"<<endl;
				cin>>point2;
			}
			int km;
		
			km = Dijkstra(points,point1,point2);
			
			////////////////////////////////////////
			int charges=km*p->per_km_rate;  // Finding the ride charges
			temp_ride->distance_travelled=km;
			temp_ride->ride_charges=charges;
			cout<<"Total Distance To Travel :"<<km<<" Km"<<endl;
			cout<<"Total Travel Charges are :"<<charges<<" Rs"<<endl;
			cout<<"Average Time to reach destintion: "<<((km*60)/35)<<" minutes "<<endl;
			p->total_earning+=temp_ride->ride_charges; // calculating total earning of car
			p->km+=km;  // adding new travelled distance to car km travelled
			if(p->first_ride==NULL){
				p->first_ride=temp_ride;
			}
			else{
				temp_ride->next_ride=p->first_ride;
				p->first_ride=temp_ride;
			}
		}
	}
}
void display_rides(){
		cout<<"\n-------------------------------------------\n";	
		cout<<"\t       DISPLAY RIDES"<<endl;
		cout<<"-------------------------------------------\n";
	
	if(start_vehicle==NULL)
		cout<<"No Any Car is Registered Yet!"<<endl;
	else{
		string reg_no;
		cout<<"\nEnter Reg No of Car/Bike to display its all rides:"<<endl;
		cin>>reg_no;
		VEHICLE *p=search_vehicle(reg_no);
		if(p==0){
			cout<<"Car/Bike Not Found !"<<endl;
		}
		else{
			if(p->vehicle_type=="car")
				cout<<"CAR NAME: "<<p->vehicle_name<<endl;
			else
				cout<<"BIKE NAME: "<<p->vehicle_name<<endl;	
			RIDE *k;
			k=p->first_ride;
			cout<<"------------------------------------------------------------------------------------"<<endl;
			cout<<"\t\t\t\t  RIDES RECORD"<<endl;
			cout<<"------------------------------------------------------------------------------------"<<endl;
			cout<<"\nRider Names\t\tTravel Charges\t\tNo of Rides\t\tKM Travelled"<<endl;
			cout<<"------------------------------------------------------------------------------------"<<endl;
			while(k!=NULL){
				cout<<k->rider_name<<"\t\t\t"<<k->ride_charges<<"\t\t\t"<<p->no_of_rides<<"\t\t\t"<<k->distance_travelled<<endl;
				k=k->next_ride;
			}
			cout<<"------------------------------------------------------------------------------------"<<endl;
		}
}
}
void find_earning(){
		cout<<"\n-------------------------------------------\n";	
		cout<<"\t\t EARNINGS"<<endl;
	cout<<"-------------------------------------------\n";
	
	if(start_vehicle==NULL)
		cout<<"No Any Car is Registered Yet!"<<endl;
	else{
		string reg_no;
		cout<<"\nEnter Reg No of car to find its total earning:"<<endl;
		cin>>reg_no;
		VEHICLE *p=search_vehicle(reg_no);
		if(p==0){
			cout<<"Car Not Found !"<<endl;
		}
		else{
			if(p->vehicle_type=="car")
				cout<<"CAR NAME: "<<p->vehicle_name<<endl;
			else
				cout<<"BIKE NAME: "<<p->vehicle_name<<endl;
				
			cout<<"NO of RIDES:"<<p->no_of_rides<<endl;
			cout<<"TOTAL EANING OF CAR IS RS: "<<p->total_earning;
		}	
}
}
void all_cars_earnings(){
	cout<<"---------------------------------------------------------------"<<endl;
	cout<<"\t\t     ALL CARS EARNINGS "<<endl;
	cout<<"---------------------------------------------------------------"<<endl;
	bool found=false;
	if(start_vehicle==NULL)
		cout<<"No Any Vehicle is Registered Yet!"<<endl;
	else{
		VEHICLE *p=start_vehicle;
		cout<<"\nCar Names\t\t"<<"No of Rides\t\t"<<"Total Earning"<<endl;
		cout<<"---------------------------------------------------------------"<<endl;
		while(p!=NULL){
			if(p->vehicle_type=="car"){
				found=true;
				cout<<p->vehicle_name<<"\t\t\t"<<p->no_of_rides<<"\t\t\t"<<p->total_earning<<endl;
			}
			p=p->next_vehicle;
		}
		if(found==false)
			{
				cout<<"No Any Car is Registered Yet !"<<endl;
			}
		cout<<"---------------------------------------------------------------"<<endl;
	
}
}
void all_bikes_earnings(){
		cout<<"---------------------------------------------------------------"<<endl;
	cout<<"\t\t    ALL BIKES EARNINGS "<<endl;
		cout<<"---------------------------------------------------------------"<<endl;
	bool found=false;
	if(start_vehicle==NULL)
		cout<<"No Any Vehicle is Registered Yet!"<<endl;
	else{
		VEHICLE *p=start_vehicle;
		cout<<"\nCar Names\t\t"<<"No of Rides\t\t"<<"Total Earning"<<endl;
		cout<<"---------------------------------------------------------------"<<endl;
		while(p!=NULL){
			if(p->vehicle_type=="bike"){
				found=true;
				cout<<p->vehicle_name<<"\t\t\t"<<p->no_of_rides<<"\t\t\t"<<p->total_earning<<endl;
			}
			p=p->next_vehicle;
		}
		if(found==false)
			{
				cout<<"No Any Bike is Registered Yet !"<<endl;
			}
		cout<<"---------------------------------------------------------------"<<endl;
	}
}
int MinDistance(int distance[], bool Visited[]) 
{
    int min=INT_MAX;
    int index;
              
    for(int k=0;k<6;k++) 
    {
        if(Visited[k]==false && distance[k]<=min)      
        {
            min=distance[k];
            index=k;
        }
    }
    return index;
}

int Dijkstra(int graph[6][6],int source,int destination) 
{
    int distance[6];                              
    bool Visited[6];
    
    for(int k = 0; k<6; k++)
    {
        distance[k] = INT_MAX;
        Visited[k] = false;    
    }
    
    distance[source] = 0;                 
    
    for(int k = 0; k<6; k++)                           
    {
        int m=MinDistance(distance,Visited); 
        Visited[m]=true;
        for(int k = 0; k<6; k++)                  
        {
            if(!Visited[k] && graph[m][k] && distance[m]!=INT_MAX && distance[m]+graph[m][k]<distance[k]){
				
				distance[k]=distance[m]+graph[m][k];
			}
        }
		
    }
	return distance[destination];
}
void tree(int x){
    BST* current , *p , *k;
    
    current = new BST;
    current->num = x;
    if(root==NULL){
        root = current;
    }
    else{
        p = root;
        while (p!=NULL)
        {
            k=p;
            if(current->num<p->num){
                p=p->left;
            }
            else if (current->num>p->num){
                p=p->right;
            }
        }
        if(current->num<k->num){
            k->left = current;
        }
        else if(current->num>k->num){
            k->right = current;
        }  
    }
    
}

bool search(int x){
    BST* p;
    p = root;
    while (p!=NULL && p->num != x)
    {
        if(x<p->num){
            p=p->left;
        }
        else if(x>p->num){
            p=p->right;
        }
    }
    if(p!=NULL){
        return true;
    }
    else{
        return false;
    }
    
}
// string Area[6];
// for(int code=0;code<6;code++){
//     if(code==0){
//         Area[code] = "Taramri";
//     }
//     else if(code==1){
//         Area[code] = "Bani_Gala";
//     }
//     else if(code==2){
//         Area[code] = "BlueArea";
//     }
//     else if(code==3){
//         Area[code] = "Faizabad";
//     }
//     else if(code==4){
//         Area[code] = "PeerWadhai";
//     }
//     else if(code==5){
//         Area[code] = "BumraTown";
//     }
// }