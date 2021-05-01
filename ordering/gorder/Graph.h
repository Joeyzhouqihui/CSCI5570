#ifndef _GRAPH_H
#define _GRAPH_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdint>
#include <chrono>

#include "Util.h"
#include "UnitHeap.h"

namespace Gorder
{

using namespace std;

class Vertex{
public:
	int outstart;
	int outdegree;
	int instart;
	int indegree;

	Vertex(){
		outdegree=indegree=0;
		outstart=instart=-1;
	}
};

class Graph{
	public:
		int vsize;
		long long edgenum;
		string name;
		
		vector<Vertex> graph;
		vector<int> outedge;
		vector<int> inedge;
	
		string getFilename();
		void setFilename(string name);

		Graph();
		~Graph();
		void clear();
		void readGraph(const string& fullname);
		void PrintReOrderedGraph(const vector<int>& order, string filename);
		void Transform();
		void GorderGreedy(vector<int>& order, int window);
		void RCMOrder(vector<int>& order);
};

}

#endif

