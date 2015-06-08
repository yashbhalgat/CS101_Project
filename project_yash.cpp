#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class element
{
	public:
	string serial,person_name,std,person_phone,person_address,city,state,profession,company_name,company_phone,company_address;
};

class node
{	
	public:
	element data;
	node *next;
	node *sortnext;

	//node()	{sortnext = 0;}
};

class list
{	
	public:
	node *head,*tail;
	
	list()	{head = 0;tail = 0;}
	
	//bool
	void open()
	{
		ifstream in("directoryinput.txt",ios::in);
		string s;
		
		getline(in,s);
		
		while(getline(in,s))
		{
			int k;
			node *tmp = new node;
			
			//add function rather than repeating
			//check for repetition
			k=s.find(';');
			tmp->data.serial = s.substr(0,k);
			s = s.substr(k+1,s.length()-k-1);
			
			k=s.find(';');
			tmp->data.person_name = s.substr(0,k);
			s = s.substr(k+1,s.length()-k-1);
			
			k=s.find(';');
			tmp->data.std = s.substr(0,k);
			s = s.substr(k+1,s.length()-k-1);
			
			k=s.find(';');
			tmp->data.person_phone = s.substr(0,k);
			s = s.substr(k+1,s.length()-k-1);
			
			k=s.find(';');
			tmp->data.person_address = s.substr(0,k);
			s = s.substr(k+1,s.length()-k-1);
			
			k=s.find(';');
			tmp->data.city = s.substr(0,k);
			s = s.substr(k+1,s.length()-k-1);
			
			k=s.find(';');
			tmp->data.state = s.substr(0,k);
			s = s.substr(k+1,s.length()-k-1);
			
			k=s.find(';');
			tmp->data.profession = s.substr(0,k);
			s = s.substr(k+1,s.length()-k-1);
			
			k=s.find(';');
			tmp->data.company_name = s.substr(0,k);
			s = s.substr(k+1,s.length()-k-1);
			
			k=s.find(';');
			tmp->data.company_phone = s.substr(0,k);
			s = s.substr(k+1,s.length()-k-1);
			
			tmp->data.company_address = s;
			
			tmp->next = 0;
			
			if(head == 0)	{	head = tmp;}	
			
			if(tail == 0)	{tail = tmp;}
			else	
			{
				tail->next = tmp;
			
				tail = tmp;
			}
			 			
		}			
	}
	
	void show()
	{
		node *tmp = head;
		while(tmp != tail->next)
		{
			cout<<"Serial no. : "<<tmp->data.serial<<endl;
			cout<<"Person name : "<<tmp->data.person_name<<endl;
			cout<<"STD code : "<<tmp->data.std<<endl;
			cout<<"Person phone no. : "<<tmp->data.person_phone<<endl;
			cout<<"Person address : "<<tmp->data.person_address<<endl;
			cout<<"City : "<<tmp->data.city<<endl;
			cout<<"State : "<<tmp->data.state<<endl;
			cout<<"Profession : "<<tmp->data.profession<<endl;
			cout<<"Company name : "<<tmp->data.company_name<<endl;
			cout<<"Company address : "<<tmp->data.company_address<<endl<<endl;
			
			tmp = tmp->next;
		}
		
		cout<<"Serial no. : "<<tail->data.serial<<endl;
			cout<<"Person's name : "<<tail->data.person_name<<endl;
			cout<<"STD code : "<<tail->data.std<<endl;
			cout<<"Person's phone no. : "<<tail->data.person_phone<<endl;
			cout<<"Person's address : "<<tail->data.person_address<<endl;
			cout<<"City : "<<tmp->data.city<<endl;
			cout<<"State : "<<tmp->data.state<<endl;
			cout<<"Person's Profession : "<<tail->data.profession<<endl;
			cout<<"Company name : "<<tail->data.company_name<<endl;
			cout<<"Company address : "<<tail->data.company_address<<endl<<endl;
	}
	
	list add()
	{
		node *tmp = new node;
		ofstream out("directoryinput.txt",ios::app);
		//tmp->data.serial = tail->data.serial + 1;
		cout<<"Enter the person's name : ";getline(cin,tmp->data.person_name);
		cout<<"Enter the std code : ";getline(cin,tmp->data.std);
		cout<<"Enter the person's phone no. : ";getline(cin,tmp->data.person_phone);
		cout<<"Enter the person's address : ";getline(cin,tmp->data.person_address);
		cout<<"Enter the person's city : ";getline(cin,tmp->data.city);
		cout<<"Enter the state : ";getline(cin,tmp->data.state);
		cout<<"Enter the person's profession : ";getline(cin,tmp->data.profession);
		cout<<"Enter the company name : ";getline(cin,tmp->data.company_name);
		cout<<"Enter the company address : ";getline(cin,tmp->data.company_address);
				
		tmp->next = 0;
		tail->next = tmp;
		out<<tail->data.serial
			<<";"<<tail->data.person_name
			<<";"<<tail->data.std
			<<";"<<tail->data.person_phone
			<<";"<<tail->data.person_address
			<<";"<<tmp->data.city
			<<";"<<tmp->data.state
			<<";"<<tail->data.profession
			<<";"<<tail->data.company_name
			<<";"<<tail->data.company_address<<endl;
		return (*this);
	}
	
	void options()
{
	int i;
	
	cout<<"Enter the number of the task you want to do : "<<endl<<"1.Show the directory"<<endl<<"2.Add a person"<<endl;
	
	cin>>i;
	
	switch(i)
	{
		case(1) :	show();
						break;
						
		case(2) :	add();
						break;
	}
}
};



int main()
{
	//welcome note
	list a;
	a.open();
	
	a.options();
	
			
}
