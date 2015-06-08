#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class element
{
	public:
	string person_name,person_phone,address,city,state,profession,company_name,company_phone;
};

class node
{	
	public:
	element data;
	node *next;
	node *sortnext;
};

class list
{	
	public:
	node *head,*tail,*sorthead;
	
	list()	{head = 0;tail = 0;}
	

	void feed()
	{
		ifstream in("telephone_directory",ios::in);
		string s;
		
		getline(in,s);
		
		while(getline(in,s))
		{
			int k;
			node *tmp = new node;
			
			k=s.find(';');
			tmp->data.profession = s.substr(0,k);
			s = s.substr(k+1,s.length()-k-1);

			k=s.find(';');
			tmp->data.person_name = s.substr(0,k);
			s = s.substr(k+1,s.length()-k-1);
			
			k=s.find(';');
			tmp->data.company_name = s.substr(0,k);
			s = s.substr(k+1,s.length()-k-1);
			
			k=s.find(';');
			tmp->data.company_phone = s.substr(0,k);
			s = s.substr(k+1,s.length()-k-1);
			
			k=s.find(';');
			tmp->data.person_phone = s.substr(0,k);
			s = s.substr(k+1,s.length()-k-1);
			
			k=s.find(';');
			tmp->data.address = s.substr(0,k);
			s = s.substr(k+1,s.length()-k-1);
			
			k=s.find(';');
			tmp->data.city = s.substr(0,k);
			s = s.substr(k+1,s.length()-k-1);
			
			tmp->data.state = s;
			
			tmp->next = 0;
			
			if(head == 0)	{head = tmp;}	
			
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
		while(tmp != 0)
		{
			cout<<"Profession : "<<tmp->data.profession<<endl;
			cout<<"Person name : "<<tmp->data.person_name<<endl;
			cout<<"Company name : "<<tmp->data.company_name<<endl;
			cout<<"Compnay phone no. : "<<tmp->data.company_phone<<endl;
			cout<<"Person phone no. : "<<tmp->data.person_phone<<endl;
			cout<<"Address : "<<tmp->data.address<<endl;
			cout<<"City : "<<tmp->data.city<<endl;
			cout<<"State : "<<tmp->data.state<<endl<<endl;
				
			tmp = tmp->next;
		}
	}
	
		void sortshow()
	{
		node *tmp = sorthead;
		while(tmp != 0)
		{
			cout<<"Profession : "<<tmp->data.profession<<endl;
			cout<<"Person name : "<<tmp->data.person_name<<endl;
			cout<<"Company name : "<<tmp->data.company_name<<endl;
			cout<<"Compnay phone no. : "<<tmp->data.company_phone<<endl;
			cout<<"Person phone no. : "<<tmp->data.person_phone<<endl;
			cout<<"Address : "<<tmp->data.address<<endl;
			cout<<"City : "<<tmp->data.city<<endl;
			cout<<"State : "<<tmp->data.state<<endl<<endl;
			
			tmp = tmp->sortnext;
		}
		
	}
	
	void add()
	{
		node *tmp = new node;
		
		cout<<"Enter the person's profession : ";cin.ignore();getline(cin,tmp->data.profession);
		cout<<"Enter the person's name : ";getline(cin,tmp->data.person_name);
		cout<<"Enter the company name : ";getline(cin,tmp->data.company_name);
		cout<<"Enter the company's phone no. : ";getline(cin,tmp->data.company_phone);
		cout<<"Enter the person's phone no. : ";getline(cin,tmp->data.person_phone);
		cout<<"Enter the person's address : ";getline(cin,tmp->data.address);
		cout<<"Enter the person's city : ";getline(cin,tmp->data.city);
		cout<<"Enter the state : ";getline(cin,tmp->data.state);
		
		tmp->next = 0;
		tail->next = tmp;
		
		sortbyprofession();
		
		node *p = sorthead;
		ofstream out("telephone_directory",ios::out);
		
		cout<<"Changed details added to the file \"telephone_directory\""<<endl; 
		out<<"Profession;Person name;Comapny name;Company phone;Person phone;Address;City;State"<<endl;
		
		while(p!=0)
		{
				out<<p->data.profession<<";"<<p->data.person_name<<";"<<p->data.company_name<<";"<<p->data.company_phone<<";"<<p->data.person_phone<<";"<<p->data.address<<";"<<p->data.city<<";"<<p->data.state<<endl;
				
				p= p->sortnext;
		}
	}
	
	node* searchbypersonname(bool &notfound,node* & prev)
	{
		string s;
		notfound = true;
		node *p = head;
		prev = head;
		cout<<"Enter the name of the person : "<<endl;
		cin.ignore();
		getline(cin,s);
		
		while(p!=0)
		{
			if(p->data.person_name == s)
			{
				notfound = false;
				break;
			}
			prev = p;
			p=p->next;
		}
		
		if(notfound)	cerr<<"Person not in the directory!!"<<endl;
		else
		{
			cout<<"\nShowing the details of the person : "<<endl;
			cout<<"1.Profession : "<<p->data.profession<<endl;
			cout<<"2.Person name : "<<p->data.person_name<<endl;
			cout<<"3.Company name : "<<p->data.company_name<<endl;
			cout<<"4.Compnay phone no. : "<<p->data.company_phone<<endl;
			cout<<"5.Person phone no. : "<<p->data.person_phone<<endl;
			cout<<"6.Address : "<<p->data.address<<endl;
			cout<<"7.City : "<<p->data.city<<endl;
			cout<<"8.State : "<<p->data.state<<endl;
			
			return p;
			
		}	
	}
	

   node* searchbycompanyname(bool &notfound,node* & prev)
	{
		string s;
		notfound = true;
		node *p = head;
		prev = head;
		cout<<"Enter the company name : "<<endl;
		cin.ignore();
		getline(cin,s);
		
		while(p!=0)
		{
			if(p->data.company_name == s)
			{
				notfound = false;
				break;
			}
			prev = p;
			p=p->next;
		}
		
		if(notfound)	cerr<<"Company name not in the directory!!"<<endl;
		else
		{
			cout<<"\nShowing the details of the company : "<<endl;
			cout<<"1.Profession : "<<p->data.profession<<endl;
			cout<<"2.Person name : "<<p->data.person_name<<endl;
			cout<<"3.Company name : "<<p->data.company_name<<endl;
			cout<<"4.Compnay phone no. : "<<p->data.company_phone<<endl;
			cout<<"5.Person phone no. : "<<p->data.person_phone<<endl;
			cout<<"6.Address : "<<p->data.address<<endl;
			cout<<"7.City : "<<p->data.city<<endl;
			cout<<"8.State : "<<p->data.state<<endl;
			
			return p;
			
		}	
	}
	
	node* searchbypersonphone(bool &notfound)
	{
		string s;
		notfound = true;
		node *p = head;
		cout<<"Enter the person's phone number : "<<endl;
		cin.ignore();
		getline(cin,s);
		
		while(p!=0)
		{
			if(p->data.person_phone == s)
			{
				notfound = false;
				break;
			}
			p=p->next;
		}
		
		if(notfound)	cerr<<"Phone number not in the directory!!"<<endl;
		else
		{
			cout<<"\nShowing the details of the person/company : "<<endl;
			cout<<"1.Profession : "<<p->data.profession<<endl;
			cout<<"2.Person name : "<<p->data.person_name<<endl;
			cout<<"3.Company name : "<<p->data.company_name<<endl;
			cout<<"4.Compnay phone no. : "<<p->data.company_phone<<endl;
			cout<<"5.Person phone no. : "<<p->data.person_phone<<endl;
			cout<<"6.Address : "<<p->data.address<<endl;
			cout<<"7.City : "<<p->data.city<<endl;
			cout<<"8.State : "<<p->data.state<<endl;
			
			return p;
		}
	}
	
	node* searchbycompanyphone(bool &notfound)
	{
		string s;
		notfound = true;
		node *p = head;
		cout<<"Enter the company's phone number : "<<endl;
		cin.ignore();
		getline(cin,s);
		
		while(p!=0)
		{
			if(p->data.company_phone == s)
			{
				notfound = false;
				break;
			}
			p=p->next;
		}
		
		if(notfound)	cerr<<"Phone number not in the directory!!"<<endl;
		else
		{
			cout<<"\nShowing the details of the person/company : "<<endl;
			cout<<"1.Profession : "<<p->data.profession<<endl;
			cout<<"2.Person name : "<<p->data.person_name<<endl;
			cout<<"3.Company name : "<<p->data.company_name<<endl;
			cout<<"4.Compnay phone no. : "<<p->data.company_phone<<endl;
			cout<<"5.Person phone no. : "<<p->data.person_phone<<endl;
			cout<<"6.Address : "<<p->data.address<<endl;
			cout<<"7.City : "<<p->data.city<<endl;
			cout<<"8.State : "<<p->data.state<<endl;
			
			return p;
		}
	}


	void modify()
	{
		char n,m;
		
		bool notfound = true;
		cout<<"Enter 1 for searching by person name or 2 for searching by company name : "<<endl;
		cin>>n;
		node *p,*prev;
		
		switch(n)
		{
			case('1') : 	{p = searchbypersonname(notfound,prev);
							if(!notfound)
							{	cout<<"Enter the number of the detail you want to change : "<<endl;
								cin>>m;
							
								switch(m)
								{
									
									case('1')	: cout<<"Enter the person's new profession : ";cin.ignore();getline(cin,p->data.profession);
													break;
									
									case('2')  : cout<<"Enter the new person name : ";cin.ignore();getline(cin,p->data.person_name);
													break;
													
									case('3')	: cout<<"Enter the new company name : ";cin.ignore();getline(cin,p->data.company_name);
													break;
																	
									case('4')  : cout<<"Enter the company's new phone no. : ";cin.ignore();getline(cin,p->data.company_phone);
									 				break;
									
									case('5')  : cout<<"Enter the person's new phone no. : ";cin.ignore();getline(cin,p->data.person_phone);
									 				break;
									 				
									case('6')	: cout<<"Enter the new address : ";cin.ignore();getline(cin,p->data.address);
													break;
													
									case('7')	: cout<<"Enter the person's new city : ";cin.ignore();getline(cin,p->data.city);
													break;
													
									case('8')	: cout<<"Enter the new state : ";cin.ignore();getline(cin,p->data.state);
													break;
									
									default	:	cerr<<"Wrong input!! "<<endl;
												modify();			
								}
							
								cout<<"\nShowing the modified details of the person : "<<endl;
								cout<<"1.Profession : "<<p->data.profession<<endl;
								cout<<"2.Person name : "<<p->data.person_name<<endl;
								cout<<"3.Company name : "<<p->data.company_name<<endl;
								cout<<"4.Compnay phone no. : "<<p->data.company_phone<<endl;
								cout<<"5.Person phone no. : "<<p->data.person_phone<<endl;
								cout<<"6.Address : "<<p->data.address<<endl;
								cout<<"7.City : "<<p->data.city<<endl;
								cout<<"8.State : "<<p->data.state<<endl;
								
								sortbyprofession();
		
								node *p = sorthead;
								ofstream out("telephone_directory",ios::out);
								
								cout<<"Changed details modified to the file \"telephone_directory\""<<endl;
								out<<"Profession;Person name;Comapny name;Company phone;Person phone;Address;City;State"<<endl;
								
								while(p!=0)
								{
										out<<p->data.profession<<";"<<p->data.person_name<<";"<<p->data.company_name<<";"<<p->data.company_phone<<";"<<p->data.person_phone<<";"<<p->data.address<<";"<<p->data.city<<";"<<p->data.state<<endl;
										
										p= p->sortnext;
								}

							
							}}
							break;
							
			case('2')  : 	{p = searchbycompanyname(notfound,prev);
							if(!notfound)
							{	cout<<"Enter the number of the detail you want to change : "<<endl;
								cin>>m;
							
								switch(m)
								{
									
									case('1')	: cout<<"Enter the person's new profession : ";cin.ignore();getline(cin,p->data.profession);
													break;
									
									case('2')  : cout<<"Enter the new person name : ";cin.ignore();getline(cin,p->data.person_name);
													break;
													
									case('3')	: cout<<"Enter the new company name : ";cin.ignore();getline(cin,p->data.company_name);
													break;
																	
									case('4')  : cout<<"Enter the company's new phone no. : ";cin.ignore();getline(cin,p->data.company_phone);
									 				break;
									
									case('5')  : cout<<"Enter the person's new phone no. : ";cin.ignore();getline(cin,p->data.person_phone);
									 				break;
									 				
									case('6')	: cout<<"Enter the new address : ";cin.ignore();getline(cin,p->data.address);
													break;
													
									case('7')	: cout<<"Enter the person's new city : ";cin.ignore();getline(cin,p->data.city);
													break;
													
									case('8')	: cout<<"Enter the new state : ";cin.ignore();getline(cin,p->data.state);
													break;
									
									default	:	cerr<<"Wrong input!! Please enter a Valid Input. "<<endl;
												modify();			
								}
							
								cout<<"\nShowing the modified details of the company : "<<endl;
								cout<<"1.Profession : "<<p->data.profession<<endl;
								cout<<"2.Person name : "<<p->data.person_name<<endl;
								cout<<"3.Company name : "<<p->data.company_name<<endl;
								cout<<"4.Compnay phone no. : "<<p->data.company_phone<<endl;
								cout<<"5.Person phone no. : "<<p->data.person_phone<<endl;
								cout<<"6.Address : "<<p->data.address<<endl;
								cout<<"7.City : "<<p->data.city<<endl;
								cout<<"8.State : "<<p->data.state<<endl;
								
								sortbyprofession();
		
								node *p = sorthead;
								ofstream out("telephone_directory",ios::out);
								
								cout<<"Changed details modified to the file \"telephone_directory\""<<endl;
								out<<"Profession;Person name;Comapny name;Company phone;Person phone;Address;City;State"<<endl;
								
								while(p!=0)
								{
										out<<p->data.profession<<";"<<p->data.person_name<<";"<<p->data.company_name<<";"<<p->data.company_phone<<";"<<p->data.person_phone<<";"<<p->data.address<<";"<<p->data.city<<";"<<p->data.state<<endl;
										
										p= p->sortnext;
							
								}
							}}
							break;	
							
			default	:	cerr<<"Wrong input!! Please enter a Valid Input. "<<endl;
						modify();
		}
		
	}
	
	void sortbypersonname()
	{
		sorthead = head;
		node *t = head;
		while(t != 0)
		{
			t->sortnext = t->next;
			t = t->next;
		}
		
		bool xchange = true;
		while(xchange == true)
		{	node *p= sorthead,*prev= sorthead,*tmp;
			xchange = false;
			while((p->sortnext)!=0)
			{
				if(p->data.person_name > (p->sortnext)->data.person_name)
				{
					if(p == sorthead)
					{
						sorthead = p->sortnext;
						tmp = (p->sortnext)->sortnext;
						(p->sortnext)->sortnext = p;
						p->sortnext = tmp;
						p = sorthead;
						xchange = true;
					}
					else
					{	
						prev->sortnext = p->sortnext;
						tmp = (p->sortnext)->sortnext;
						(p->sortnext)->sortnext = p;
						p->sortnext = tmp;
						p = prev->sortnext;
						xchange = true;
					}
					
				}
				prev = p;
				p = p->sortnext;
			}
		}
	
		sortshow();
		
		node *p = sorthead;
		ofstream out("personname_sorted_directory",ios::out);
		
		cout<<"Sorted directory saved in the file \"personname_sorted_directory\""<<endl;
		out<<"Profession;Person name;Comapny name;Company phone;Person phone;Address;City;State"<<endl;
		
		while(p!=0)
		{
				out<<p->data.profession<<";"<<p->data.person_name<<";"<<p->data.company_name<<";"<<p->data.company_phone<<";"<<p->data.person_phone<<";"<<p->data.address<<";"<<p->data.city<<";"<<p->data.state<<endl;
				
				p= p->sortnext;
	
		}
		
		
	}
	
		void sortbycompanyname()
	{
		sorthead = head;
		node *t = head;
		while(t != 0)
		{
			t->sortnext = t->next;
			t = t->next;
		}
		
		bool xchange = true;
		while(xchange == true)
		{	node *p= sorthead,*prev= sorthead,*tmp;
			xchange = false;
			while((p->sortnext)!=0)
			{
				if(p->data.company_name > (p->sortnext)->data.company_name)
				{
					if(p == sorthead)
					{
						sorthead = p->sortnext;
						tmp = (p->sortnext)->sortnext;
						(p->sortnext)->sortnext = p;
						p->sortnext = tmp;
						p = sorthead;
						xchange = true;
					}
					else
					{	
						prev->sortnext = p->sortnext;
						tmp = (p->sortnext)->sortnext;
						(p->sortnext)->sortnext = p;
						p->sortnext = tmp;
						p = prev->sortnext;
						xchange = true;
					}
					
				}
				prev = p;
				p = p->sortnext;
			}
		}
	
		sortshow();
		
		node *p = sorthead;
		ofstream out("companyname_sorted_direcory",ios::out);
		
		cout<<"Sorted directory saved in the file \"personname_sorted_directory\""<<endl;
		out<<"Profession;Person name;Comapny name;Company phone;Person phone;Address;City;State"<<endl;
		
		while(p!=0)
		{
				out<<p->data.profession<<";"<<p->data.person_name<<";"<<p->data.company_name<<";"<<p->data.company_phone<<";"<<p->data.person_phone<<";"<<p->data.address<<";"<<p->data.city<<";"<<p->data.state<<endl;
				
				p= p->sortnext;
	
		}
		
		
	}
	
	void sortbyprofession()
	{
		sorthead = head;
		node *t = head;
		while(t != 0)
		{
			t->sortnext = t->next;
			t = t->next;
		}
		
		bool xchange = true;
		while(xchange == true)
		{	node *p= sorthead,*prev= sorthead,*tmp;
			xchange = false;
			while((p->sortnext)!=0)
			{
				if(p->data.profession > (p->sortnext)->data.profession)
				{
					if(p == sorthead)
					{
						sorthead = p->sortnext;
						tmp = (p->sortnext)->sortnext;
						(p->sortnext)->sortnext = p;
						p->sortnext = tmp;
						p = sorthead;
						xchange = true;
					}
					else
					{	
						prev->sortnext = p->sortnext;
						tmp = (p->sortnext)->sortnext;
						(p->sortnext)->sortnext = p;
						p->sortnext = tmp;
						p = prev->sortnext;
						xchange = true;
					}
					
				}
				prev = p;
				p = p->sortnext;
			}
		}
	
		
	}
	
	void listbyprofession()
	{
			string s;
			cout<<"Enter the profession whose people you want to list : ";
			cin>>s;
			bool found = false;
			
			node *tmp = head;
		while(tmp != 0)
		{
			if(tmp->data.profession == s)
			{
				found = true;
				cout<<"Profession : "<<tmp->data.profession<<endl;
				cout<<"Person name : "<<tmp->data.person_name<<endl;
				cout<<"Company name : "<<tmp->data.company_name<<endl;
				cout<<"Compnay phone no. : "<<tmp->data.company_phone<<endl;
				cout<<"Person phone no. : "<<tmp->data.person_phone<<endl;
				cout<<"Address : "<<tmp->data.address<<endl;
				cout<<"City : "<<tmp->data.city<<endl;
				cout<<"State : "<<tmp->data.state<<endl<<endl;
			}
			tmp = tmp->next;
		}
		
		if(!found)	cerr<<"Entered profession not present in directory!!"<<endl;
			
	}
	
	void listbycity()
	{
			string s;
			cout<<"Enter the city whose people you want to list : ";
			cin>>s;
			bool found = false;
			
			node *tmp = head;
		while(tmp != 0)
		{
			if(tmp->data.city == s)
			{
				found = true;
				cout<<"Profession : "<<tmp->data.profession<<endl;
				cout<<"Person name : "<<tmp->data.person_name<<endl;
				cout<<"Company name : "<<tmp->data.company_name<<endl;
				cout<<"Compnay phone no. : "<<tmp->data.company_phone<<endl;
				cout<<"Person phone no. : "<<tmp->data.person_phone<<endl;
				cout<<"Address : "<<tmp->data.address<<endl;
				cout<<"City : "<<tmp->data.city<<endl;
				cout<<"State : "<<tmp->data.state<<endl<<endl;
			}
			tmp = tmp->next;
		}
		if(!found)	cerr<<"Entered city not present in directory!!"<<endl;
			
			
	}
	
	void remove()
	{
		char n;
		char ch;
		node *prev,*q;
		bool notfound = true;
		cout<<"Enter 1 for searching by person name and 2 for searching by company name : "<<endl;
		cin>>n;
		
		switch(n)
		{
			case('1')	: {q = searchbypersonname(notfound,prev);
							if(!notfound)
							{
									cout<<"Do you want to remove the above person?(y/n)"<<endl;
									cin>>ch;
									
									switch(ch)
									{
										case('y')	:	{prev->next  = q->next;
														delete(q);
														
														sortbyprofession();
		
														node *p = sorthead;
														ofstream out("telephone_directory",ios::out);
														
														cout<<"The person has been removed from the file \"telephone_directory\""<<endl;
														out<<"Profession;Person name;Comapny name;Company phone;Person phone;Address;City;State"<<endl;
														
														while(p!=0)
														{
																out<<p->data.profession<<";"<<p->data.person_name<<";"<<p->data.company_name<<";"<<p->data.company_phone<<";"<<p->data.person_phone<<";"<<p->data.address<<";"<<p->data.city<<";"<<p->data.state<<endl;
																
																p= p->sortnext;
														}
													}
														break;
														
										case('n')	:	{cout<<"Not removing person"<<endl;}
														break;
										
										default		:	{cerr<<"Wrong input!! Please enter a Valid Input."<<endl;}
									}
									
							}
						}	break;
							
				case('2')	:{ q = searchbycompanyname(notfound,prev);
							if(!notfound)
							{
									cout<<"Do you want to remove the above company?(y/n)"<<endl;
									cin>>ch;
									
									switch(ch)
									{
										case('y')	:	{prev->next  = q->next;
														delete(q);
														
														sortbyprofession();
		
														node *p = sorthead;
														ofstream out("telephone_directory",ios::out);
														
														cout<<"The company has been removed from the file \"telephone_directory\""<<endl;
														out<<"Profession;Person name;Comapny name;Company phone;Person phone;Address;City;State"<<endl;
														
														while(p!=0)
														{
																out<<p->data.profession<<";"<<p->data.person_name<<";"<<p->data.company_name<<";"<<p->data.company_phone<<";"<<p->data.person_phone<<";"<<p->data.address<<";"<<p->data.city<<";"<<p->data.state<<endl;
																
																p= p->sortnext;
														}
													}
														break;
														
										case('n')	:	{cout<<"Not removing company"<<endl;}
														break;
										
										default		:	{cerr<<"Wrong input!! Please enter a Valid Input."<<endl;}
									}
									
							}
						}
							break;
						
				default	: {cerr<<"Wrong input!! Please enter a Valid Input."<<endl;
							}
							break;
		}
	}
	void options()
{
	int i;
	bool notfound;
	node *prev;
	cout<<"\n----------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\n\nEnter the number of the task you want to do : "<<endl<<"1.Show the directory"<<endl<<"2.Add member to the directory"<<endl<<"3.Modify details "<<endl<<"4.Search the directory by person's name"<<endl<<"5.Search the directory by company's name"<<endl<<"6.Search the directory by person's phone number"<<endl<<"7.Search the directory by company's phone number"<<endl<<"8.Sort by person's name and show"<<endl<<"9.Sort by company's name and show"<<endl<<"10.List the persons of a particular profession"<<endl<<"11.List the persons of a particular city"<<endl<<"12.Remove a person or a comopany"<<endl<<"13.Exit"<<endl;
	
	cin>>i;
	
	if(i == 0){cerr<<"Wrong input!! Please enter a Valid Input."<<endl;	}
	else{
	switch(i)
	{
		case(1) :	show();
					options();
						break;
						
		case(2) :	add();
					options();
						break;
						
		case(3) :	modify();
					options();	
						break;
					
		case(4) :   searchbypersonname(notfound,prev);
					options();
						break;
		
		case(5) :   searchbycompanyname(notfound,prev);
					options();
						break;
						
		case(6)	:	searchbypersonphone(notfound);
					options();
						break;
						
		case(7)	:	searchbycompanyphone(notfound);
					options();
						break;
						
		case(8)	:  	sortbypersonname();
					options();
						break;
						
		case(9)	: 	sortbycompanyname();
					options();
						break;
				
		case(10):	listbyprofession();
					options();
						break;
						
		case(11):	listbycity();
					options();
						break;
						
		case(12):	remove();
					options();
						break;
						
		case(13):	break;	
						
		default	:	cerr<<"Wrong input!! Please enter a Valid Input."<<endl;
					options();
					break;
	}
}
}
};

void open()
{
	char n;
	cout<<"Enter 1 for opening the directory or 0 for exit"<<endl;
	cin>>n;
	
	switch(n)
	{
		case('1')	:	{list a;
					a.feed();
					a.options();}
					break;
					
		case('0')	:	break;
		
		default	:	{cerr<<"Wrong input!! Please enter a Valid Input."<<endl;
						open();
						}
					break;
	}
}

int main()
{
	cout<<"*************************************************Welcome to Our Telephone Directory!**************************************************"<<endl;	
	open();
}
