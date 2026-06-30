//Vehicle Rental System

#include<iostream>
#include<iomanip>
#include<fstream>
#include<conio.h>
#include<cstring>
#include<stdio.h>
#include<cstdlib>
#include<windows.h>

using namespace std;

struct VRS      // VRS=Vehicle Rental System (Structure name)
{
	char name[100];
	char type[20];
	char rent[20];
	double model;
};

//Function prototypes
void gotoxy(short , short ); 
void display(VRS[],int,int&);
void add(VRS[],int,int&);
void search(VRS[],int,int&,string);
void sort(VRS[],int,int&);
void del(VRS[],int,int&);
void modify(VRS[],int,int&);

int main()
{
	int count=0;
	const int size=100;
    VRS cars[size];
    VRS veh;
	char ch;
	string names;
	while(1)
	{
		system("cls"); // for clearing screen (refereshing screen)
//		Main Menu:
	    cout<<setw(50)<<"\n\t\t-------------* Welcome to the Vehicle Rental System *-------------\n\n";
	    cout<<"\nSelect any of the options given below:\n";
	    cout<<"-----------------------------------------\n";
	    cout<<"\n(1) Add a Record\n";
	    cout<<"\n(2) Search a Record\n";
	    cout<<"\n(3) Display All Records\n";
	    cout<<"\n(4) Sort All Records\n";
	    cout<<"\n(5) Modify a Record\n";
	    cout<<"\n(6) Delete a Record\n";
	    cout<<"\n(7) Exit Program\n";
	    cout<<"\nEnter Option: _";
	    gotoxy(14,21); // adjustment of cursor
	    ch=getche();  
	    switch(ch)
	    {
		    case '1': add(cars,size,count);break;
		    case '2': search(cars,size,count,names);break;
		    case '3': display(cars,size,count);break;
		    case '4': sort(cars,size,count);break;
	        case '5': modify(cars,size,count);break;
		    case '6': del(cars,size,count);break;
		    case '7': cout<<"\n\n\nExiting Program......";
		          exit(0);break;
	    default:
	    {
		    cout<<"\nInvalid option!";	
	    }
	    
	    }
	}

	getch();   //gets one character from keyboard
}

//1) Add Function
void add(VRS vehicle[],int size,int& count)
{
	system("cls");
	cout<<"\t-------------";
	cout<<"\n\t|ADD RECORDS|\n";
	cout<<"\t-------------";
	int carsno;
	cout<<"\n\nEnter no. of cars you want to add: ";
	cin>>carsno;
	cin.ignore();   // used for resolving buffer
	int i;
	if(carsno<size)
	{
		for(i=0;i<carsno;i++)
	    {
	    	cin.ignore();
	       cout<<"\nRecord "<<i+1<<": ";
	       cout<<"\n---------";
		   cout<<"\n\nEnter Car name: ";
		   cin.getline(vehicle[count].name,100);
		   cin.ignore();
		   cout<<"\nEnter type: ";
		   cin.getline(vehicle[count].type,20);
		   cin.ignore();
		   cout<<"\nEnter model: ";
		   cin>>vehicle[count].model;
		   cin.ignore();
		   cout<<"\nEnter rent: ";
		   cin.getline(vehicle[count].rent,20);
		   cin.ignore();
		   cout<<"\n--------------------";
		   
		   count++;
	    }
	}
	else
	{
		cout<<"\nRecord adding limit exceeded!";
	}
	
	cout<<"\n\nPress Enter to go back to menu....";
	getch();
}
 
// 2) Display Function
void display(VRS vehicle[],int size,int& count)
{
	system("cls");
	int i;
	cout<<"\t-----------------";
	cout<<"\n\t|RECORDS DISPLAY|\n";
	cout<<"\t-----------------\n";
	if(count==0)
	{
		cout<<"\nNo Record added yet!...";
	}
	else
	{
	    cout<<"\n\nDisplaying all Car's Records....\n\n";
	    cout<<"\n"<<setw(20)<<"Name"<<setw(20)<<"Type"<<setw(20)<<"Model"<<setw(20)<<"Rent(PKR)\n";
	    cout<<"\t---------------------------------------------------------------------------------------\n";
	    for(i=0;i<count;i++)
	    {
		    cout<<setw(20)<<vehicle[i].name<<setw(20)<<vehicle[i].type<<setw(20)<<vehicle[i].model<<setw(20)<<vehicle[i].rent<<"\n\n";
	    }
	}
	
	cout<<"\n\nPress Enter to go back to menu....";
	getch();	
}

// 3) Search Function
void search(VRS vehicle[],int size,int& count,string name)
{
	system("cls");
	int i,loc;
	bool found;
	cout<<"\n\t-----------------";
	cout<<"\n\t|RECORD SEARCHES|";
	cout<<"\n\t-----------------";
	cout<<"\n\n\nEnter name of car to search: ";
	cin>>name;
	cout<<"\n\nSearching record......\n\n";
	for(i=0;i<count;i++)
	{
		if(name==vehicle[i].name)
		{
			found=true;
			if(found==true)
			{
				loc=i;
				cout<<"\n"<<setw(20)<<"Name"<<setw(20)<<"Type"<<setw(20)<<"Model"<<setw(20)<<"Rent(PKR)\n";
	            cout<<"\t---------------------------------------------------------------------------------------\n";
	            cout<<setw(20)<<vehicle[loc].name<<setw(20)<<vehicle[loc].type<<setw(20)<<vehicle[loc].model<<setw(20)<<vehicle[loc].rent<<"\n";
			}
		}
	}
	if(!found)
	{
		cout<<"\n\n\nRecord not found!...";
	}
	
	cout<<"\n\n\nPress Enter to go back to menu.....";
	getch();
}

// 4) Sort Function
void sort(VRS vehicle[],int size,int& count)
{
	system("cls");
	int i,j;
	char choice;
	cout<<"\t-----------------";
	cout<<"\n\t|RECORDS SORTING|\n";
	cout<<"\t-----------------\n";
	cout<<"\n\nSort by car 'name' or 'rent' [n,r]: ";
	choice=getch();
	if(count==0)
	{
		cout<<"\n\nNo Records added yet!....";
	}
//	Sort by name
	else if(choice=='n')
	{
		cout<<"\n\n Sorting by name.....\n";
		for(i=0;i<count-1;i++)
		{
			for(j=0;j<count-i-1;j++)
			{
				if(strcmp(vehicle[j].name,vehicle[j+1].name)>0)
				{
					swap(vehicle[j].name,vehicle[j+1].name);
				}
			}
			
		}
		cout<<"\n\nSorted Records:\n";
		cout<<"-------------------\n";
		cout<<"\n"<<setw(20)<<"Name"<<setw(20)<<"Type"<<setw(20)<<"Model"<<setw(20)<<"Rent(PKR)\n";
	    cout<<"\t---------------------------------------------------------------------------------------\n";
		for(i=0;i<count;i++)
		{
	        cout<<setw(20)<<vehicle[i].name<<setw(20)<<vehicle[i].type<<setw(20)<<vehicle[i].model<<setw(20)<<vehicle[i].rent<<"\n";
		}
	}
//	Sort by rent
	else if(choice=='r')
	{
		cout<<"\n\n Sorting by Rents.....\n";
		for(i=0;i<count-1;i++)
		{
			for(j=0;j<count-i-1;j++)
			{
				if(strcmp(vehicle[j].rent,vehicle[j+1].rent)>0)
				{
					swap(vehicle[j].rent,vehicle[j+1].rent);
				}
			}
			
		}
		cout<<"\n\nSorted Records:\n";
		cout<<"-------------------\n";
		cout<<"\n"<<setw(20)<<"Name"<<setw(20)<<"Type"<<setw(20)<<"Model"<<setw(20)<<"Rent(PKR)\n";
	    cout<<"\t---------------------------------------------------------------------------------------\n";
		for(i=0;i<count;i++)
		{
	        cout<<setw(20)<<vehicle[i].name<<setw(20)<<vehicle[i].type<<setw(20)<<vehicle[i].model<<setw(20)<<vehicle[i].rent<<"\n";
		}
	}
	
	cout<<"\n\nPress Enter to go back to menu.....";
	getch();	
}

//Delete function
void del(VRS vehicle[],int size,int& count)
{
	system("cls");
	int i;
	char remove;
	cout<<"\t------------------";
	cout<<"\n\t|RECORDS DELETION|\n";
	cout<<"\t------------------\n";
	cout<<"\n\nEnter Record (index) to delete: ";
	remove=getch();
	if(count==0)
	{
		cout<<"\n\n\nNo record found to delete!...";
	}
	else
	{
	    for(i=remove;i<count-1;i++)
	    {
		    vehicle[i]=vehicle[i+1];
		    
	    }
	    cout<<"\n\nRecord deleted successfully!...";
	}
	count--;
	
	cout<<"\n\n\nPress Enter to go back to menu....";
	getch();
}

//Modify function
void modify(VRS vehicle[],int size,int& count)
{
	system("cls");
	int i;
	bool found;
	string modify;
	cout<<"\t---------------------";
	cout<<"\n\t|RECORD MODIFICATION|\n";
	cout<<"\t---------------------\n";
	cout<<"\n\nEnter Car name you want to modify: ";
	cin.ignore();
	getline(cin,modify);
	for(i=0;i<count;i++)
	{
	    if(modify==vehicle[i].name)
	    {
	    	found=true;
		    cout<<"\nEnter new rent for '"<<vehicle[i].name<<"': ";
		    cin.getline(vehicle[i].rent,30);
		    cout<<"\n\n\nRecord updated Successfully!....";
	    }
    } 
	    
    
    if(!found)
    {
		cout<<"\n\n\nRecord not found!...";
	}
	
	cout<<"\n\nPress Enter to go back to menu.....";
    getch();
}




////////////////////////////////////////
/////////////////gotoxy //////////////////////////
void gotoxy(short x, short y) 
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
