#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

long randkey(){
		return rand()*rand();
}
struct Node{
		int Tkey,Hkey;
		long size;
		Node * ch[2];
		Node(int key){
				Tkey=key;
				Hkey=randkey();
				size=1;
				ch[0]=NULL;
				ch[1]=NULL;
		}
}node[maxn],*root;

Node* insert(Node *& root,const Node* now){
		if (root==NULL) root=now;
		else{
				root->size++;
				insert(root->ch[root->key<now->key],now);
				if (root->Hkey<root->ch[root->key<now->key]->Hkey)
						rotate(root,!(root->key<now->key));
		}
}
int main(){
		srand(time(0));
}





void split(node* o, node* &a, node* &b, int n) {
	if(n == 0) {
		a = NULL, b = o; return;
	}else if( n == SIZE(o)) {
		a = o, b = NULL; return;
	}
	o->pushdown();
	int L = SIZE(o->ch[0]);
	if( L >= n ) {
		b = o;
		split(o->ch[0], a, b->ch[0], n);
		b->update();
	} else {
		a = o;
		split(o->ch[1], a->ch[1], b, n - L - 1);
		a->update();
	}
}
void merge(node* &o, node* a, node* b) {
	if(!a || !b){
		o = (a? a : b);
		return;
	}
	if(a->r > b->r) {
		a->pushdown();
		merge(a->ch[1], a->ch[1], b);
		a->update();
		o = a;
	}else {
		b->pushdown();
		merge(b->ch[0], a, b->ch[0]);
		b->update();
		o = b;
	}
}

