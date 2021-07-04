#include <iostream>
#include <fstream f("rec",ios::in |ios::app | ios::binary)>
#include <stdio.h>
using namespace std;

class hospital
{
    int id;
    char name[20];
    int totalcases;
    int cases_recover;
    int cases_active;
public:
    void input();
    void display();
    void addRecord();
    void displayRecord();
    void del();
    void modify();
    void search();
    void menu();
};
void student::menu()
{
    int ch;
    cout << "1. addRecord " << endl;
    cout << "2. search " << endl;
    cout << "3. delete " << endl;
    cout << "4. modify " << endl;
    cout << "5. display record " << endl;
    cout << "6. exit " << endl;

    cout << "enter choice " << endl;
    cin >> ch;
    switch (ch)
    {
     case 1: 
          addRecord();
     case 2:
          search();
     case 3:
         del();
     case 4:
         modify();
     case 5:
         displayRecord();
     case 6:
         exit();
    }                  
    
}

void hospital::input()
{
    cout<< "Enter the name of the patient" <<endl;
    gets(name);
    cout<< "Enter Id " <<endl;
    cin>>id;
    cout<< "Enter total cases of covid positive";
    cin>>totalcases;
    cout<< "Enter the recovered cases";
    cin>> cases_recover;
    cout<< "Enter the active cases";
    cin>> cases_active;
}

void hospital::display()
{
    cout<<name <<id <<totalcases <<cases_active <<cases_recover;
}

void hospital::addRecord()
{
    input();
    f.write((char *)&hosp, size of(hosp));
    cout<< "one record added " <<endl;
    cout<< "Press any key to continue";
    getch();
    menu();
}
void hospital:: search()
{
    int s, flag=0;
    cout<<"Input id to be searched";
    cin>>s;
    f.seekg(0);
    while(f)
    {
        f.read((char*)&hosp,sizeof(hosp));
        if(id==s)
        {
            cout<<"Record Found";
            display();
            flag=1;
            break;
        }
    }
    if(flag==0)
        {cout<<"Record not found"}
    cout<<"Press any key to continue";
    getch();
    menu();    
}
void hospital::del()
{
    ofstream o("test");
    int s, flag=0;
    cout<<"Enter record to be deleted";
    cin>>s;
    f.seekg(0);
    while(f)
    {
        f.read((char*)&hosp,sizeof(hosp));
        if(id==s)
        {
            cout<<"Record Found & Deleted"
            flag=1;
        }
        else
        {
         o.write((char*)&hosp,sizeof(hosp));
        }
   }
   if(flag==0)
   {
       cout<<"Record not Found";
   }
   f.close();
   o.close();
   remove("rec");
   rename("test","rec");
   f.open("rec",ios::in | ios::out | ios::app | ios::binary);
   cout<<"Press any key to continue";
   getch();
   menu();
}
void hospital::modify()
{
    ofstream o("test", ios::binary);
    int s, flag=0;
    cout<<"Input id to be modified";
    cin>>s;
    f.seekg(0);
    while(f)
    {
         f.read((char*)&hosp,sizeof(hosp));
        if(id==s)
        {
            cout<<"Record Found";
            cout<<"Input new name";
            gets(name);
            o.write((char*)&hosp,sizeof(hosp));
            flag=1;
        }
        else
        {
         o.write((char*)&hosp,sizeof(hosp));
        }
   }
   if(flag==0)
   {
       cout<<"Record not Found";
   }
   f.close();
   o.close();
   remove("rec");
   rename("test","rec");
   f.open("rec",ios::in | ios::out | ios::app | ios::binary);
   cout<<"Press any key to continue";
   getch();
   menu(); 
}
void hospital::displayRecord()
{
    f.seekg(0);
    while(f)
    {
        f.read((char*)&hosp,sizeof(hosp));
        display();
        cout<<"Press any key to continue";
        getch();
    }
    menu();
}
void main()
{
    hospital hosp;
    ofstream o("rec", ios::app | ios::binary)
    hosp.input();
    o.write((char*)&hosp,sizeof(hosp));
    o.close();
    ifstream i("rec",ios::binary);
    i.seekg(0);
    while(i)
    {
        i.read((char*)&hosp,sizeof(hosp));
        hosp.display();
    }
    i.close();
}