#include<simplecpp>
main_program{
	string s,s1,s2,s3;
	int i=0,count1=0,count2,k;
	while(getline(cin,s)){
		count1++;
		count2=0;
		for(i=0;i<s.length();i++){
			if(s[i]==';') count2++;
		}
		if(count2!=5){
			k=s.find(';');
			s1=s.substr(0,k);
			s=s.substr(k+1,s.length()-k-1);
			
			k=s.find(';');
			s2=s.substr(0,k);
			s=s.substr(k+1,s.length()-k-1);
			
			k=s.find(';');
			s3=s.substr(0,k);
			s=s.substr(k+1,s.length()-k-1);
			
			cout<<s1+";"+s2+";"+s3+";"+" none;"+s<<endl;
		}
		else cout<<s<<endl;
	}
}
			
