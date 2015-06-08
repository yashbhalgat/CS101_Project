#include<simplecpp>
main_program{
	string s;
	int i=0,count1=0,count2;
	while(getline(cin,s)){
		count1++;
		count2=0;
		for(i=0;i<s.length();i++){
			if(s[i]==';') count2++;
		}
		if(count2!=5) cout<<"Line number : "<<count1<<endl;
	}
}
			
