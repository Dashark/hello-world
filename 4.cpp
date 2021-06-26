#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
struct infor{
	int b;
	int cost;
};
struct edge{
	int a,b;
	int cost;
	friend bool operator < (edge x,edge y){
		return x.cost > y.cost;
	}
};
vector<infor>map[20001];
priority_queue<edge>q;
int vis[20001];
int dist[20001];
int n,m;
const long long inf = 2147483647;

void dijkstra(int node){
	for(int i=0;i<map[node].size();i++){
		infor a = map[node][i];
		if(dist[a.b] > dist[node] + a.cost){
			dist[a.b] = dist[node] + a.cost;
			edge p;
			p.a = node;
			p.b = a.b;
			p.cost = dist[a.b];
			q.push(p); 
		}
	}
	int Min = 0x7f7f7f7f;
	int mini = -1;
	while(!q.empty()){
		edge p = q.top();
		q.pop();
		if(vis[p.a]+vis[p.b] == 1){
			if(vis[p.a]==0){
				mini = p.a;
				Min = p.cost;
			}
			else{
				mini = p.b;
				Min = p.cost;
			}
			break;
		}
	}
	if(mini == -1) return ;
	vis[mini] = 1;
	dijkstra(mini);
}

int main(){
	int begin;
	cin >> n >> m >> begin;
	memset(vis,0,sizeof(vis));
	memset(dist,0x7f7f7f7f,sizeof(dist));
	for(int i=0;i<10009;i++) map[i].clear();
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		infor node;
		node.b = b;
		node.cost = c;
		map[a].push_back(node);
	}
	vis[begin] = 1;
	dist[begin] = 0;
	dijkstra(begin);
	for(int i=1;i<=n;i++){
		if(vis[i]==0) cout << inf << " ";
		else cout << dist[i] << " ";
	}
	return 0;
}
