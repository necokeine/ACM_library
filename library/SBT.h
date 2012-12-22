template <typename T_key,typename T_val>
class SBT{
		public:
				typedef T_key	key_type;
				typedef T_val	val_type;
				struct Node{
						key_type key;
						val_type val;
						long size;
						Node * ch[2];
				};
		private:
				Node * root;
				void release(Node * &root);
				void rotate(Node *& root,bool flag);
				void maintain(Node *& root,bool flag);
				long size(Node * root);
				void insert(Node *& root,Node *now);
				//Node* find(Node *& root,const T_key key);
				Node* find(Node *& root,const T_key key){
					if ((root==NULL)||(root->key==key)) return root;
					else return find(root->ch[root->key<key],key);
				}
		public:
				SBT<T_key,T_val>();
				~SBT<T_key,T_val>();
				void clear();
				val_type& operator[](key_type key);
				val_type& at(key_type key);
				bool empty();
				//bool earse(const T_key &key);
};

template<typename T_key,typename T_val>
SBT<T_key,T_val>::SBT(){
		root=NULL;
}

template<typename T_key,typename T_val>
SBT<T_key,T_val>::~SBT(){
		if (root!=NULL)
				release(root);
}

template<typename T_key,typename T_val>
void SBT<T_key,T_val>::release(Node * & root){
		if (root->ch[0]!=NULL) release(root->ch[0]);
		if (root->ch[1]!=NULL) release(root->ch[1]);
		delete root;
		root=NULL;
}

template<typename T_key,typename T_val>
void SBT<T_key,T_val>::rotate(Node *& root,bool flag){
		Node * tmp=root->ch[!flag];
		root->ch[!flag]=tmp->ch[flag];
		tmp->ch[flag]=root;
		root->size=size(root->ch[0])+size(root->ch[1]);
		root=tmp;
		root->size=size(root->ch[0])+size(root->ch[1]);
}

template<typename T_key,typename T_val>
void SBT<T_key,T_val>::maintain(Node *& root,bool flag){
		if (size(root->ch[flag]->ch[flag])>size(root->ch[!flag]))
				rotate(root,!flag);
		else
				if (size(root->ch[flag]->ch[!flag])>size(root->ch[!flag])){
						rotate(root->ch[flag],flag);
						rotate(root,!flag);
				}else return;
		maintain(root->ch[0],false);
		maintain(root->ch[1],true);
		maintain(root,false);
		maintain(root,true);
}

template<typename T_key,typename T_val>
long SBT<T_key,T_val>::size(Node * root){
		return root==NULL?0:root->size;
}

/*template<typename T_key,typename T_val>
Node<T_key,T_val>* SBT<T_key,T_val>::find(Node *& root,const T_key key){
		if ((root==NULL)||(root->key==key)) return root;
		else return find(root->ch[root->key<key],key);
}*/

template<typename T_key,typename T_val>
void SBT<T_key,T_val>::insert(Node *& root,Node * now){
		if (root==NULL){
				root=now;
		}else{
				root->size++;
				insert(root->ch[root->key<now->key],now);
				maintain(root,root->key<now->key);
		}
}

template<typename T_key,typename T_val>
void SBT<T_key,T_val>::clear(){
		if (root!=NULL) release(root);
}

template<typename T_key,typename T_val>
T_val& SBT<T_key,T_val>::at(key_type key){
		Node * tmp=find(root,key);
		if (tmp==NULL){
				tmp=new Node;
				tmp->size=1;
				tmp->key=key;
				tmp->ch[0]=NULL;
				tmp->ch[1]=NULL;
				insert(root,tmp);
		}
		return tmp->val;
}

template<typename T_key,typename T_val>
T_val& SBT<T_key,T_val>::operator[](key_type key){
		return at(key);
}

template<typename T_key,typename T_val>
bool SBT<T_key,T_val>::empty(){
		return root==NULL;
}

/*template<typename T_key,typename T_val>
bool SBT<T_key,T_val>::earse(const T_key & key){
		Node * tmp=root;
		while ((tmp!=NULL) && (tmp->key!=key))
				tmp=tmp->ch[tmp->key<key];
		if (tmp==NULL) return false;
		else{
				return true;
		}
}

