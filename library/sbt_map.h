#include <iostream>
using namespace std;

template <typename T_key,typename T_val>
class map{
public:
		typedef T_key		key_type;
		typedef T_val		val_type;
		typedef _Compare	key_compare;
private:
		struct Node{
				T_key key;
				T_val val;
				long size;
				Node *lf, *rt;
		};
		long size;
		Node * root;
		Node * insert(Node*,T_key,T_val);
		void erase(T_key);
		void release(Node & * root);
		map();
public:
		void clear();
		T_val& at(T_key);		
template <typename T_key,typename T_val>
		T_val& operator[](T_key now){
				return at(now);
		}
};
