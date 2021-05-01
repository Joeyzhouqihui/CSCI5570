#include "gorder.h"

void Gorder::readGraph(std::string filename) {
  ifstream file(fullname.c_str(), ios::in);
	cout<<"open file : "<<fullname<<endl;
	int u, v;
	vsize=0;
	edgenum=0;
	vector<pair<int, int> > edges;
	edges.reserve(100000000);

	while(file>>u>>v){
		if(u>vsize)
			vsize=u;
		if(v>vsize)
			vsize=v;
		edges.push_back(make_pair(u, v));
		edgenum++;
	}
	vsize++;
	file.close();
	graph.resize(vsize+1);
	for(long long i=0; i<edges.size(); i++) {
		graph[edges[i].first].outdegree++;
		graph[edges[i].second].indegree++;
	}
	graph[0].outstart=0;
	graph[0].instart=0;
	for(int i=1; i<vsize; i++){
		graph[i].outstart=graph[i-1].outstart+graph[i-1].outdegree;
		graph[i].instart=graph[i-1].instart+graph[i-1].indegree;
	}
	sort(edges.begin(), edges.end(), [](const pair<int, int>& a, const pair<int, int>& b)->bool{
		if(a.first<b.first)
			return true;
		else if(a.first>b.first)
			return false;
		else{

			if(a.second<=b.second)
				return true;
			else
				return false;
		}

	});
	outedge.resize(edgenum);
	for(long long i=0; i<edges.size(); i++){
		outedge[i]=edges[i].second;
	}

	vector< pair<int, int> >().swap(edges);
#ifndef Release	
	vector<int> inpos(vsize);
	for(int i=0; i<vsize; i++){
		inpos[i]=graph[i].instart;
	}
	inedge.resize(edgenum);
	for(int u=0; u<vsize; u++){
		for(int j=graph[u].outstart; j<graph[u].outstart+graph[u].outdegree; j++){
			inedge[inpos[outedge[j]]]=u;
			inpos[outedge[j]]++;
		}
	}
#endif

	cout << "vsize: " << vsize << endl;
	cout << "edgenum: " << edgenum << endl;
	graph[vsize].outstart=edgenum;
	graph[vsize].instart=edgenum;
}
