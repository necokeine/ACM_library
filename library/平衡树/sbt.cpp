#include <iostream>
using namespace std;

const int MAXN = 100000;
struct Node{
	int key,size;
	Node* ch[2];
	friend int SZ(Node* p){return p==NULL?0:p->size;}
	void init(int _key=0){key=_key;size=1;ch[0]=ch[1]=NULL;}
	void update(){size=1+SZ(ch[0])+SZ(ch[1]);}
}t[MAXN];

int e=0;
Node* _alloc(int val=0){t[e].init(val); return &t[e++];}

void rot(Node *& p, int f){
	Node * tmp=p->ch[!f];
	p->ch[!f]=tmp->ch[f];
	tmp->ch[f]=p;
	p->update(); tmp->update();
	p=tmp;
}

void maintain(Node *& p,int f){
	if (!p || !p->ch[!f]) return ;
	if (SZ(p->ch[f])< SZ(p->ch[!f]->ch[!f])){
		rot(p,f);
		maintain(p->ch[f],0);maintain(p->ch[f],1);
	}else if (SZ(p->ch[f]) < SZ(p->ch[!f]->ch[f])){
		rot(p->ch[!f],!f);rot(p,f);
		maintain(p->ch[!f],f);maintain(p->ch[f],!f);
	}else return;
	maintain(p,0);maintain(p,1);
}


void insert(Node *& p, int v){
	if (p==NULL){ p = _alloc(v); return;}
	bool f = (v>p->key);
	insert(p->ch[f],v);
	p->size++;
	maintain(p,!f);
}

int _rev(Node *& p){
	if (p->ch[0]){
		int tmp = _rev(p->ch[0]);
		p->update();
		maintain(p,0);
	}else{
		int tmp=p->key;
		p=p->ch[1];
	}
	return tmp;
}

void remove(Node *& p, int v){
	if( p == NULL) return;
	if(v < p->key){
		remove(p->ch[0], v);
		p->update();
		maintain(p,0);
	}else if (v>p->key){
		remove(p->ch[1], v);
		p->update();
		maintain(p,1);
	}else{
		if (p->ch[0]==NULL) p=p->ch[1];
		else if (p->ch[1]==NULL) p=p->ch[0];
		else{
			p->key=_rev(p->ch[1]);
			p->update();
			maintain(p,1);
		}
	}
}

Node * merge(Node * p, Node * q){
	if (p==NULL) return q;
	else if (q==NULL) return p;
	else if (SZ(p)>SZ(q)){
		p->ch[1]=merge(p->ch[1],q);
		p->update();
		return p;
	}else{
		q->ch[0]=merge(p,q->ch[0]);
		q->update();
		return q;
	}
}

void split(Node *& p, Node *& q, int v){
	q=NULL;
	if (p ==NULL) return;
	else if (p->key <= v) split(p->ch[1],q,v);
	else{
		q=p;p=q->ch[0];
		split(p,q->ch[0],v);
	}
	if (p!=NULL) p->update();
	if (q!=NULL) q->update();
}

int main(){
	Node * root=NULL;
	Node * root2;
	char op[100];
	long num;
	e=0;
	while (cin>>op>>num){
		if (op[0]=='I') insert(root,num);
		if (op[0]=='D') remove(root,num);
		if (op[0]=='S') split(root,root2,num);
		if (op[0]=='M'){
			root=merge(root,root2);
			root2 = NULL;
		}
		if (op[0]=='P'){
			cout<<SZ(root)<<" "<<SZ(root2)<<endl;
		}
	}
}
