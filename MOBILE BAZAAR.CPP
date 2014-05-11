//*************************************************************************************//
//			PROJECT ON "THE MOBILE BAZAAR"			            //
//				CODED BY:				           //
//			CHAITANYA KHANNA AND PARTH NARULA			   //
//************************************************************************************//


//***********************************************************************************//
//			INCLUDNG HEADER FILES				        //
//***********************************************************************************//

#include<fstream>
#include<iostream>
//#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
using namespace std;
//dos.h for sleep function & stdlib.h for random
//***********************************************************************************//
//			GLOBAL DECLARATIONS				        //
//***********************************************************************************//

struct bill{
	char brand[50];
	char model[50];
	float price;
	int qty;
	};

bill b[100];

class mobile{

	char brand[50];
	char model[50];
	float price;
	float weight;		//IN GRAMS
	char form_factor[50];
	char input_method[50];
	float talk_time;		//HRS
	float display_size;		//IN INCHES
	float camera_resolution;	//MEGA PIXELS
	char wifi;
	char bluetooth;
	char four_g;
	char smartphone;
	float rating;		//OUT OF 5

public:

void input();
void output();
void calc_rating();

char return_wifi(){
	return wifi;
	}
char return_4g(){
	return four_g;
	}
void display_model(){
	cout<<"\n"<<brand<<" "<<model;
	}
float return_price(){
	return price;
	}
char* return_brand(){
	return brand;
	}
char* return_model(){
	return model;
	}
int compare_model(char x[],char y[]){
	if(strcmp(x,model)==0&&strcmp(y,brand)==0)
		return 1;
	else
		return 0;
	}
int compare_brand(char y[]){
	if(strcmp(y,brand)==0)
		return 1;
	else
		return 0;
	}
	};
//***********************************************************************************//
//			THIS FUNCTION INPUTS RECORDS		        	        //
//***********************************************************************************//

void mobile::input(){

//system("clear");

cout<<"\nenter mobile brand:";
cin>>brand;

cout<<"enter model:";
cin>>model;

cout<<"enter price(rs):";
cin>>price;

cout<<"\nenter weight(gms):";
cin>>weight;

cout<<"\nenter form factor:";
cin>>form_factor;

cout<<"\nenter input method:";
cin>>input_method;

cout<<"\nenter talk time(hrs):";
cin>>talk_time;

cout<<"\nenter display size(inches):";
cin>>display_size;

cout<<"\nenter camera resolution(mp):";
cin>>camera_resolution;

cout<<"\nwifi(y/n):";
cin>>wifi;

cout<<"\nbluetooth(y/n):";
cin>>bluetooth;

cout<<"\n4g(y/n):";
cin>>four_g;

cout<<"\nsmartphone(y/n):";
cin>>smartphone;

}

//***********************************************************************************//
//			THIS FUNCTION DISPLAYS RECORDS			        //
//***********************************************************************************//

void mobile::output(){

system("clear");

cout<<"\nthe specifications of the phone are as follows:";
cout<<"\nmobile brand:"<<brand;
cout<<"\nmodel:"<<model;
cout<<"\nprice:rs"<<price;
cout<<"\nweigths "<<weight<<" grams";
cout<<"\nform factor:"<<form_factor;
cout<<"\ninput method:"<<input_method;
cout<<"\ntalk time:"<<talk_time<<" hours";
cout<<"\ndisplay size:"<<display_size<<" inches";
cout<<"\ncamera resolution:"<<camera_resolution<<" mega pixels";
cout<<"\nwifi:"<<wifi;
cout<<"\nbluetooth:"<<bluetooth;
cout<<"\n4g:"<<four_g;
cout<<"\nsmartphone:"<<smartphone;
cout<<"\n\nrating:";

calc_rating();
for(int i=1;i<=rating;i++)
	cout<<"* ";

getchar();
}

//********************************************************************************************************//
//			THIS FUNCTION CACULATES RATING OF THE MOBILE PHONE		             //
//********************************************************************************************************//

void mobile::calc_rating(){
int x;

if(talk_time>=10)
	x=100;
else if(talk_time>=7)
	x=75;
else if(talk_time>=4)
	x=50;
else
	x=25 ;

if(display_size>=3)
	x+=100;
else if(display_size>=2)
	x+=60;
else
	x+=30;

if(camera_resolution>=5)
	x+=100;
else if(camera_resolution>=3)
	x+=75;
else if(camera_resolution>=2)
	x+=50;
else
	x+=25;

if(wifi=='y')
	x+=100;
else
	x+=20;

if(bluetooth=='y')
	x+=100;
else
	x+=20;

if(four_g=='y')
	x+=100;
else
	x+=20;

if(smartphone=='y')
	x+=100;
else
	x+=20;

rating=x/140;
}

//***********************************************************************************************//
//			THIS FUNCTION DISPLAYS A SEARCH BAR		                             //
//***********************************************************************************************//

void searching(){
cout<<"\n\n\n\n\n\n\nsearching";
sleep(2);		//ARGUEMENT-TIME(MILLI SEC.)

for(int i=0;i<2;i++){

system("clear");
cout<<"\n\n\n\n\n\n\nsearching.";
sleep(2);

system("clear");
cout<<"\n\n\n\n\n\n\nsearching..";
sleep(2);

system("clear");
cout<<"\n\n\n\n\n\n\nsearching...";
sleep(2);

system("clear");
cout<<"\n\n\n\n\n\n\nsearching....";
sleep(2);
}
system("clear");
}

//*****************************************************************************//
//			THIS FUNCTION PROCESS BAR		             //
//*****************************************************************************//
void processing(){
system("clear");
cout<<"\n\n\n\n\n\n\nprocessing bill";
sleep(1);		//ARGUEMENT-TIME(MILLI SEC.)

for(int i=0;i<2;i++){
system("clear");
cout<<"\n\n\n\n\n\n\nprocessing bill.";
sleep(1);

system("clear");
cout<<"\n\n\n\n\n\n\nprocessing bill..";
sleep(1);

system("clear");
cout<<"\n\n\n\n\n\n\nprocessing bill...";
sleep(1);

system("clear");
cout<<"\n\n\n\n\n\n\nprocessing bill....";
sleep(1);
}
system("clear");
}

//**************************************************************************************************//
//			THIS FUNCTION WRITES RECORDS TO FILE		                                   //
//**************************************************************************************************//

void insert(){
system("clear");
ofstream fout("mobile.dat",ios::binary|ios::app);

mobile m;

cout<<"enter the details:";
m.input();

fout.write((char*)&m,sizeof(m));

fout.close();
getchar();
}

//*********************************************************************************************************************//
//			THIS FUNCTION SEARCHES FOR MOBILES ON THE BASIS OF PRICE	                                   //
//*********************************************************************************************************************//

void search_price(){
system("clear");

mobile m;

float max,min;

cout<<"\nenter price range:\nminimum:";
cin>>min;
cout<<"\nmaximum:";
cin>>max;

system("clear");
searching();

int flag=0;

ifstream fin("mobile.dat",ios::binary);

while(fin.read((char*)&m,sizeof(m))){
	if(m.return_price()>=min&&m.return_price()<=max){
		flag++;
		break;
		}
	}
if(flag==0)
	cout<<"\nno phones match the search criterion";

else{
	cout<<"\n\nthe following phones lie within the price range:";
	fin.seekg(0);
	while(fin.read((char*)&m,sizeof(m))){
		if(m.return_price()>=min&&m.return_price()<=max){
			m.display_model();
			cout<<"\n\trs "<<m.return_price();
			}
		}
	}
fin.close();

getchar();
}

//*****************************************************************************************************************************//
//			THIS FUNCTION SEARCHES FOR MOBILES ON THE BASIS OF WIFI CAPABILITIES	                                    //
//*****************************************************************************************************************************//

void search_wifi(){
system("clear");
searching();

int flag=0;

mobile m;

ifstream fin("mobile.dat",ios::binary);

while(fin.read((char*)&m,sizeof(m)))
	if(m.return_wifi()=='y'){
		flag++;
		break;
	}

if(flag==0)
	cout<<"\nno phones match the search criterion";

else{
	cout<<"\nthe following phones have wifi facility:";

	fin.seekg(0);
	while(fin.read((char*)&m,sizeof(m)))
		if(m.return_wifi()=='y')
			m.display_model();
		}

fin.close();
getchar();
}

//*****************************************************************************************************************************//
//			THIS FUNCTION SEARCHES FOR MOBILES ON THE BASIS OF 4G CAPABILITIES	                                    //
//*****************************************************************************************************************************//

void search_4g(){
system("clear");
searching();

int flag=0;

mobile m;


ifstream fin("mobile.dat",ios::binary);

while(fin.read((char*)&m,sizeof(m)))
	if(m.return_4g()=='y'){
		flag++;
		break;
	}
if(flag==0)
	cout<<"\nno phones match the search criterion";

else{
	cout<<"\nthe following phones have 4g facility:";

	fin.seekg(0);
	while(fin.read((char*)&m,sizeof(m)))
		if(m.return_4g()=='y')
			m.display_model();
		}

fin.close();
getchar();
}

//*****************************************************************************************************************************//
//			THIS FUNCTION SORTS FOR MOBILES ON THE BASIS OF PRICE	                                                                    //
//*****************************************************************************************************************************//

void sort_price(){
system("clear");


mobile m[100];

mobile t;
int n=0;

ifstream fin("mobile.dat",ios::binary);

while(fin.read((char*)&m[n],sizeof(mobile)))
n=n+1;

fin.close();

for(int i=0; i<n ; i++)
	for(int j=0; j<n-1 ; j++){
		if(m[j].return_price() > m[j+1].return_price()){
			t=m[j];
			m[j]=m[j+1];
			m[j+1]=t;
			}
		}

system("clear");

cout<<"\nSorted List of Mobile\n";

for(int i=0; i<n ; i++) {
	cout<<"\n--------------\n";
	m[i].output();
	}

}

//*****************************************************************************************************************************//
//			THIS FUNCTION DELETES RECORDS ON THE BASIS OF MODEL NAME	                                                    //
//*****************************************************************************************************************************//

void remove_rec(){
system("clear");

ifstream fin("mobile.dat",ios::binary);

ofstream fout("temp.dat",ios::binary);

cout<<"\nenter details of mobile to be deleted:";
cout<<"\n\nenter brand's name:";
char brand[50];
cin>>brand;
cout<<"\nenter model:";
char model[50];
cin>>model;

mobile m;
int k;
int flag=0;

while(fin.read((char*)&m,sizeof(m))){
	k=m.compare_model(model,brand);

	if(k==0)
		fout.write((char*)&m,sizeof(m));
	else
		flag++;
		}
if(flag==0)
	cout<<"\n\n\nthe phone model doesn't exist in database.";
else
	cout<<"\n\n\ndeletion successful!";

fin.close();
fout.close();

remove("mobile.dat");
rename("temp.dat","mobile.dat");

getchar();
}

//************************************************************************************************************//
//	THIS FUNCTION DISPLAYS FULL PHONE SPECIFICATIONS ON THE BASIS OF MODEL NAME                             //
//************************************************************************************************************//

void display_model(){
system("clear");

ifstream fin("mobile.dat",ios::binary);

cout<<"\nenter the details of mobile to display specifications:";
cout<<"\n\nenter brand's name:";
char brand[50];
cin>>brand;
cout<<"\nenter model:";
char model[50];
cin>>model;

mobile m;
int flag=0;

system("clear");
searching();

while(fin.read((char*)&m,sizeof(m))){
	if(m.compare_model(model,brand)){
		m.output();
		flag++;
		}
		}
char choice;

if(flag==0){
	cout<<"\nyour search query doesn't match any mobile phone in our database";
	cout<<"\ndo you want to enter details of this phone";
	cout<<"(y/n):";
	cin>>choice;

	if(choice=='y')
		insert();

}

fin.close();

}

//*********************************************************************************//
//			THIS FUNCTION PROCESSES THE BILL	                                    //
//*********************************************************************************//

void display_brand(){
system("clear");

ifstream fin("mobile.dat",ios::binary);

cout<<"\n\nenter brand's name:";
char brand[50];
cin>>brand;

mobile m;
int flag=0;

system("clear");
searching();

while(fin.read((char*)&m,sizeof(m))){
	if(m.compare_brand(brand)){
		m.display_model();
		flag++;
		}
		}

if(flag==0)
	cout<<"\nyour search query doesn't match any mobile phone in";
	cout<<"our database.";
fin.close();
}

void billing(int n){
system("clear");

cout<<"\t";
for(int i=0;i<50;i++)
	cout<<"*";
cout<<"\n\t";
for(int i=0;i<2;i++)
	cout<<"*";
cout<<"MOBILE BAZAAR";
for(int i=0;i<2;i++)
	cout<<"*";
cout<<"\n\t";
for(int i=0;i<50;i++)
	cout<<"*";

cout<<"\n\n\n\t";
for(int i=0;i<50;i++)
	cout<<"_";

float totalprice=0;
for(int i=0;i<n;i++){
	cout<<"\n\t"<<i+1<<".\t";
	cout<<b[i].brand<<" "<<b[i].model;
	cout<<"\t"<<b[i].price;
	cout<<"\t"<<b[i].qty;
	cout<<"\t"<<b[i].price*b[i].qty;

	totalprice+=b[i].price*b[i].qty;
	}
cout<<"\n\t";
for(int i=0;i<50;i++)
	cout<<"_";
cout<<"\n";
cout<<"\ttotal price:\t\t\t\t"<<totalprice;

cout<<"\n\n\n";
cout<<"\t";
for(int i=0;i<50;i++)
	cout<<"*";
cout<<"\n\t";
for(int i=0;i<10;i++)
	cout<<"*";
cout<<"THANK YOU FOR YOUR PURCHASE !";
for(int i=0;i<10;i++)
	cout<<"*";
cout<<"\n\t";
for(int i=0;i<50;i++)
	cout<<"*";

getchar();
exit(0);
}

void purchase(){
char ch='y';
mobile m;
int i=0;
int qty;

while(ch=='y'){
while(1){
system("clear");
cout<<"\nenter the details of phone to be purchased:";
cout<<"\nbrand:";
char brand[50];
cin>>brand;
cout<<"\nmodel:";
char model[50];
cin>>model;

int flag=0;

ifstream fin("mobile.dat",ios::binary);

while(fin.read((char*)&m,sizeof(m))){
	if(m.compare_model(model,brand)){
		flag++;
		break;
		}
		}
if(flag==0){
	cout<<"\n\nphone not found in database.";
	cout<<"\ndo you want to buy any other ?(y/n):";
	cin>>ch;
	if(ch!='y')
		return;
		}
else
	break;
		}

int k=rand()%10 + 6;
while(1){
cout<<"\n\nenter quantity:";
cin>>qty;

if(qty>k){
	cout<<"\n\nnot enough stock.\ndo you want to buy less?(y/n):";
	cin>>ch;
	if(ch!='y')
		return;
	}
else
	break;
}
strcpy(b[i].brand,m.return_brand());
strcpy(b[i].model,m.return_model());
b[i].price=m.return_price();
b[i].qty=qty;

i++;

cout<<"\n\ndo you want to buy another phone ?(y/n):";
cin>>ch;

if(ch!='y')
	break;
	}
getchar();

processing();
system("clear");
billing(i);
}

int main(){
system("clear");
cout<<"\n\n\n\t\t@@~~##WELCOME TO THE MOBILE BAZAAR##~~@@";
sleep(1);
system("clear");
char ch='y';
int choice;


while(ch=='y'){
	system("clear");
	cout<<"\nwhat do you want to do ?";
	cout<<"\nenter 1 to insert new records:";
	cout<<"\nenter 2 to search for wifi enabled devices:";
	cout<<"\nenter 3 to search for 4g capable devices:";
	cout<<"\nenter 4 to search on the basis of price range:";
	cout<<"\nenter 5 to delete an existing record:";
	cout<<"\nenter 6 to display record on the basis of model's name:";
	cout<<"\nenter 7 to display record on the basis of brand's name:";
	cout<<"\nenter 8 to display a list on the basis of price :";
	cout<<"\nenter 9 to purchase:";
	cout<<"\nenter 10 to exit:";
	cout<<"\nenter your choice:";
	cin>>choice;

	if(choice== 1)
		insert();
	else if(choice==2)
		search_wifi();
	else if(choice==3)
		search_4g();
	else if(choice==4)
		search_price();
	else if(choice==5)
		remove_rec();
	else if(choice==6)
		display_model();
	else if(choice==7)
		display_brand();
	else if(choice==8)
		sort_price();
	else if(choice==9)
		purchase();
	else if(choice==10)
		exit(1);
	else
		cout<<"\n\ninvalid choice !!";

	cout<<"\n\n\n\ndo you want to continue??";
	cout<<"\nenter 'y' for yes:";
	cin>>ch;
	}
//getchar();

return 0;
}


