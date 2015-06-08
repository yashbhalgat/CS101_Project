#include<simplecpp>
main_program{
	string s;
	int count=0;
	while(getline(cin,s)){
		count++;
		if(count%15==1) cout<<s+"; "+"PUNE; MAHARASHTRA"<<endl;
		if(count%15==2) cout<<s+"; "+"BHOPAL; MADHYA PRADESH"<<endl;
		if(count%15==3) cout<<s+"; "+"RANCHI; JHARKHAND"<<endl;
		if(count%15==4) cout<<s+"; "+"JAIPUR; RAJASTHAN"<<endl;
		if(count%15==5) cout<<s+"; "+"LUCKNOW; UTTAR PRADESH"<<endl;
		if(count%15==6) cout<<s+"; "+"SRINAGAR; JAMMU KASHMIR"<<endl;
		if(count%15==7) cout<<s+"; "+"MUMBAI; MAHARASHTRA"<<endl;
		if(count%15==8) cout<<s+"; "+"AHMEDNAGAR; MAHARASHTRA"<<endl;
		if(count%15==9) cout<<s+"; "+"UDAIPUR; RAJASTHAN"<<endl;
		if(count%15==10) cout<<s+"; "+"PATNA; BIHAR"<<endl;
		if(count%15==11) cout<<s+"; "+"HYDERABAD; ANDHRA PRADESH"<<endl;
		if(count%15==12) cout<<s+"; "+"GANDHINAGAR; GUJARAT"<<endl;
		if(count%15==13) cout<<s+"; "+"CHENNAI; TAMIL NADU"<<endl;
		if(count%15==14) cout<<s+"; "+"AHMEDABAD; GUJARAT"<<endl;
		if(count%15==0) cout<<s+"; "+"BANGALORE; KARNATAKA"<<endl;
		
	}
}
			
