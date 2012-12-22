template <typename T_key,typename T_val>
class sbt_map{
public:
		typedef T_key		key_type;
		typedef T_val		val_type;
private:
		struct Node{
				T_key key;
				T_val val;
				long size;
				Node *lf, *rt;
		};
	   	Node * root;
	void insert(Node* &root,const T_key key,const T_val val){
		if (root==NULL){
				root=new Node;
				root->key=key;
				root->val=val;
				root->size=1;
				root->lf=NULL;
				root->rt=NULL;
		}else{
				root->size++;
				if (root->key < key){
						insert(root->rt,key,val);
				}else{
						insert(root->lf,key,val);
				}
				maintain(root,root->key<key);
		}
	}


	void release(Node * &root){
		if (root->lf !=NULL){
				release(root->lf);
		}
		if (root->rt !=NULL){
				release(root->rt);
		}
		delete root;
		root=NULL;
	}

	void rotate(Node*&root,bool flag){
		if (!flag){
				Node * tmp=root->rt;
				root->rt=tmp->lf;
				tmp->lf=root;
				root->size=size(root->lf)+size(root->rt);
				root=tmp;
				root->size=size(root->lf)+size(root->rt);
		}else{
				Node * tmp=root->lf;
				root->lf=tmp->rt;
				tmp->rt=root;
				root->size=size(root->lf)+size(root->rt);
				root=tmp;
				root->size=size(root->lf)+size(root->rt);
		}
	}
	void maintain(Node*& root,bool flag){
		if (!flag && (size(root->lf)==0)) return;
		if (flag && (size(root->rt)==0)) return;
		if (!flag)
				if (size(root->lf->lf)>size(root->rt))
						rotate(root,true);
				else
						if (size(root->lf->rt)>size(root->rt)){
								rotate(root->lf,false);
								rotate(root,true);
						}
						else return;
		else
				if (size(root->rt->rt)>size(root->lf))
						rotate(root,false);
				else
						if (size(root->rt->lf)>size(root->lf)){
								rotate(root->rt,true);
								rotate(root,false);
						}
						else return;
		maintain(root->lf,false);
		maintain(root->rt,true);
		maintain(root,false);
		maintain(root,true);
	}

	long size(Node * root){
		if (root==NULL) return 0;
		else return root->size;
	}
	Node * find(Node * root,const T_key key){
		if ((root==NULL)||(root->key==key)) return root;
		else{
				if (root->key < key){
						return find(root->rt,key);
				}else{
						return find(root->lf,key);
				}
		}
	}	
public:
	sbt_map<T_key,T_val>(){
		root=NULL;
	}
	void clear(){
		release(root);
	}
	T_val& operator[](T_key key){
		if (find(root,key)==NULL){
				T_val val=0;
				insert(root,key,val);
		}
		return find(root,key)->val;
	}
};
