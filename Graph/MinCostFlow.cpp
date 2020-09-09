#pragma once
#include "../template/template.cpp"

struct PrimalDual{
	struct edge{
		int to,cap,cost,rev;
	};
	vector<vector<edge>>graph;
	void add_edge(int from,int to,int cap,int cost){
		graph[from].push_back({to,cap,cost,len(graph[to])});
		graph[to].push_back({from,0ll,-cost,len(graph[from])-1});
	}
	int minCostFlow(int s,int t,int f){
		int V=len(graph);
		vector<int>potential(V),minCost,prevv(V,-1),preve(V,-1);
		vector<bool>used(V);
		int res=0;
		while(f>0){
			minCost.assign(V,inf);
			used.assign(V,0);
			minCost[s]=0;
			rep(_,V-1){
				int mn=inf,idx;
				rep(i,V)if(!used[i]&&chmin(mn,minCost[i]))idx=i;
				used[idx]=true;
				rep(i,len(graph[idx])){
					edge &e=graph[idx][i];
					int nextcost=mn+e.cost+potential[idx]-potential[e.to];
					if(e.cap>0&&minCost[e.to]>nextcost){
						minCost[e.to]=nextcost;
						prevv[e.to]=idx;preve[e.to]=i;
					}
				}
			}
			if(minCost[t]==inf)return -1;
			rep(i,V)potential[i]+=minCost[i];
			int addflow=f;
			for(int i=t;i!=s;i=prevv[i])chmin(addflow,graph[prevv[i]][preve[i]].cap);
			f-=addflow;
			res+=addflow*potential[t];
			for(int i=t;i!=s;i=prevv[i]){
				edge &e=graph[prevv[i]][preve[i]];
				e.cap-=addflow;
				graph[i][e.rev].cap+=addflow;
			}
		}
		return res;
	}
	PrimalDual(int V):graph(V){};
};
