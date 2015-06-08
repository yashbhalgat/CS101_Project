#include<simplecpp>
#include<fstream>

main_program{
	ofstream out("pd",ios::out);
	string s;
	unsigned int i;
	while(getline(cin,s)){
		for(i=0;i<s.length();i++){
			if(s[i]==' ' && s[i+1]==' ') s[i]='`';
		}
		out<<s<<endl;
	}
}
