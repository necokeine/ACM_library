//«Î≈‰∫œstd_spfaπ€ø¥
long dis[MAXN];

struct Node{
		long dis,num;
		Node(long d,long n):dis(d),num(n){}
		bool operator<(const Node & b){return dis<b.dis;}
};

void shortest_rode(){
		priority_queue<Node> p;
		memset(dis,26,sizeof(dis));
		dis[1]=0;
		p.push(Node(dis[1],1));
		while (!p.empty()){
				Node now=p.top();p.pop();
				if (now.dis>dis[now.num]) continue;
				for (int i=first[now.num];i;i=next[i])
						if (dis[b[i]]>dis[a[i]]+c[i]){
								dis[b[i]]=dis[a[i]]+c[i];
								q.push(dis[b[i]],b[i]);
						}
		}
}
