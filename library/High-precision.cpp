#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;

class Num{
  long dight[10000];
  long len;
public:
  Num(string s="0"){
	len=s.length();
	for (int i=len-1;i>=0;i--)
      dight[len-i-1]=s[i]-48;
  }
  Num(char s[]){
	len=strlen(s);
	for (int i=len-1;i>=0;i--)
	  dight[len-i-1]=s[i]-48;
  }
  Num& operator=(Num now);
  Num& operator=(char line[]);
  Num operator+(Num b);
  Num operator-(Num b);
  Num operator*(Num b);
  Num operator/(long b);
  friend ostream& operator<<(ostream &print,Num a);
};


Num& Num::operator=(char line[]){
	len=strlen(line);
	for (int i=len-1;i>=0;i--)
	  dight[len-i-1]=line[i]-48;
	return *this;
}


Num& Num::operator=(Num now){
	len=now.len;
	for (int i=0;i<len;i++)
	  dight[i]=now.dight[i];
	return *this;
}
Num Num::operator+(Num b){
	Num tmp;
	memset(tmp.dight,0,sizeof(tmp.dight));
	for (int i=0;i<len;i++) tmp.dight[i]=dight[i];
	for (int i=0;i<b.len;i++){
		tmp.dight[i]+=b.dight[i];
		if (tmp.dight[i]>9){
			tmp.dight[i]-=9;
			tmp.dight[i+1]+=1;
		}
	}
	tmp.len=max(len,b.len);
	while (tmp.dight[tmp.len]) tmp.len++;
	return tmp;
}
Num Num::operator-(Num b){
	Num tmp;
	memset(tmp.dight,0,sizeof(tmp.dight));
	for (int i=0;i<len;i++) tmp.dight[i]=dight[i];
	for (int i=0;i<b.len;i++){
		tmp.dight[i]-=b.dight[i];
		if (tmp.dight[i]<0){
			tmp.dight[i]+=10;
			tmp.dight[i+1]-=1;
		}
	}
	tmp.len=max(len,b.len);
	while (!tmp.dight[tmp.len-1]) tmp.len--;
	return tmp;
}
Num Num::operator*(Num b){
	Num tmp;
	memset(tmp.dight,0,sizeof(tmp.dight));
	for (int i=0;i<len;i++)
		for (int j=0;j<b.len;j++)
			tmp.dight[i+j]+=dight[i]*b.dight[j];
	tmp.len=len+b.len;
	for (int i=0;i<tmp.len;i++)
		if (tmp.dight[i]>9){
			tmp.dight[i+1]+=tmp.dight[i] / 10;
			tmp.dight[i]%=10;
		}
	while (!tmp.dight[tmp.len-1]) tmp.len--;
	return tmp;
}
Num Num::operator/(long b){
	Num tmp;long a=0;
	memset(tmp.dight,0,sizeof(tmp.dight));
	for (int i=len-1;i>=0;i--){
		a=a*10+dight[i];
		tmp.dight[i]=a / b;
		a%=b;
	}
	tmp.len=len;
	while (!tmp.dight[tmp.len-1]) tmp.len--;
	return tmp;
}
ostream& operator<<(ostream& print,Num a){
	for (int i=a.len-1;i>=0;i--) print<<a.dight[i];
	return print;
}
int main(){
	Num a("2"),b("10");
	char line[1000];
	char opera;
	while (1){
		cout<<"Input a =";
		gets(line);a=line;
		cout<<"Input the operator (+,-,*,/):";
		cin>>opera;gets(line);
		cout<<"Input b =";
		if (opera!='/'){
			gets(line);b=line;
			switch (opera){
			case '+':cout<<a+b<<endl;break;
			case '-':cout<<a-b<<endl;break;
			case '*':cout<<a*b<<endl;break;
			}
		}else{
			long bb;
			cin>>bb;gets(line);
			cout<<a/bb<<endl;
		}
	}
}