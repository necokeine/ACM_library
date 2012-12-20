#include <iostream>
using namespace std;

template <typename T_key,typename T_val>
class map{
private:
		long size;
public:
		void clear();
		T_val findbykey(T_key);
		T_val operator[](T_key now){
				return findbykey(now);
		}

};
