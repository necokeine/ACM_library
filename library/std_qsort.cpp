#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
long temp;
long num[1000000];
void qsort(int st,int ed){
  long value=num[(int)((st+ed)/2)];
  int i=st,j=ed;
  while (i<=j){
    while (num[i]<value) i++;
    while (num[j]>value) j--;
    if (i<=j){
      temp=num[i];
      num[i]=num[j];
      num[j]=temp;
      i++;j--;
    }
  }
  if (st<j) qsort(st,j);
  if (i<ed) qsort(i,ed);
}
    
int main(){
  int tot=0;
  long a,b;
  while (cin>>num[tot++]);
  qsort(0,tot-1);
  //tot=1000000;
  //for (int i=0;i<tot;i++) num[i]=rand()*rand();
  //sort(&num[0],&num[tot-1]);
  //for (int i=0;i<tot-1;i++) cout<<num[i]<<endl;
  system("pause");
  return 0;
}
