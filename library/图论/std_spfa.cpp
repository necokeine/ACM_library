#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const long MAXM=10000,MAXN=10000;
long a[MAXM];//start point
long b[MAXM];//end point
long c[MAXM];//cost;
long next[MAXM];
long first[MAXN];
bool indui[MAXN];
long dis[MAXN];

void spfa(){
		memset(indui,false,sizeof(indui));
		memset(dis,26,sizeof(dis));
		indui[1]=true;
		queue<long> q;
		q.push(1);dis[1]=0;
		while (!q.empty()){
				long now=q.front();
				indui[now]=false;
				q.pop();
				for (int i=first[now];i;i=next[i])
						if (dis[b[i]]>dis[a[i]]+c[i]){
								dis[b[i]]=dis[a[i]]+c[i];
								if (!indui[b[i]]){
										indui[b[i]]=true;
										q.push(b[i]);
								}
						}
		}
}
int main(){
		long n,m;
		while (cin>>n>>m){
				memset(first,0,sizeof(first));
				for (int i=1;i<=m;i++){
						cin>>a[i]>>b[i]>>c[i];
						next[i]=first[a[i]];
						first[a[i]]=i;
				}
				spfa();
		}
}
