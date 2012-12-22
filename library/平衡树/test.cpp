#include <iostream>
#include <string>
using namespace std;
#include "SBT.h"

SBT<long,long> mp1;
int main(){
		long now=10;
		mp1[now]=10;
		cout<<mp1[now]<<endl;
}
