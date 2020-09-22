#pragma once
#include "../template/template.cpp"

struct Dinic{
	struct Edge{int to,cap,rev;};
	vector<vector<Edge>>G;
	vector<int>level,iter;
	void addEdge(int from,int to,int cap){
		G[from].push_back({to,cap,len(G[to])});
		G[to].push_back({from,0,len(G[from])-1});
	}
	void bfs(int s){
		fill(all(level),-1);
		level[s]=0;
		queue<int>que;que.push(s);
		while(len(que)){
			int p=que.front();que.pop();
			for(Edge e:G[p]){
				if(e.cap>0&&level[e.to]==-1){
					level[e.to]=level[p]+1;
					que.push(e.to);
				}
			}
		}
	}
	int dfs(int v,int t,int f){
		if(v==t)return f;
		for(int &i=iter[v];i<len(G[v]);i++){
			Edge &e=G[v][i];
			if(e.cap>0&&level[e.to]>level[v]){
				int d=dfs(e.to,t,min(f,e.cap));
				if(d>0){
					e.cap-=d;
					G[e.to][e.rev].cap+=d;
					return d;
				}
			}
		}
		return 0;
	}
	int maxFlow(int s,int t){
		int flow=0;
		while(1){
			bfs(s);
			if(level[t]<0)return flow;
			fill(all(iter),0);
			int f=0;
			while((f=dfs(s,t,inf))>0){
				flow+=f;
			}
		}
	}
	Dinic(int N):G(N),level(N),iter(N){}
};
