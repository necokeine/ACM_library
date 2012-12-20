#include "sbt_map.h"

map::map(){
		root=NULL;
}

void map::clear(){
		release(root);
}

void map::release(Node & * root){
		if (root->lf !=NULL){
				release(root->lf);
		}
		if (root->rt !=NULL){
				release(root->rt);
		}
		delete root;
		root=NULL;
}

template <typename T_key,typename T_val>
void insert(Node* root,T_key key,T_val val){
		if (root==NULL){
				root=new Node;
				root->key=key;
				root->val=val;
				root->size=1;
				root->lf=NULL;
				root->rt=NULL;
		}else{
		}
}
