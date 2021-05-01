#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <functional>
#include <climits>
#include <ctime>
#include <stdlib.h>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <chrono>

#include "Graph.h"
#include "Util.h"

using namespace std;
using namespace Gorder;

const int INPUTNUM=1;

int main(int argc, char* argv[]){
	ios::sync_with_stdio(false);
	int i;
	int W=5;
	clock_t start, end;
	string ifilename, ofilename;
	ifilename = argv[1];
	ofilename = argv[2];

	srand(time(0));

	Graph g;
	g.readGraph(ifilename);
	g.Transform();
	cout <<"Read graph data complete"<< endl;

	start=clock();
	vector<int> order;
	g.GorderGreedy(order, W);
	end=clock();
	cout << "ReOrdered Time Cost: " << (double)(end-start)/CLOCKS_PER_SEC << endl;
	cout << "Begin Output the Reordered Graph" << endl;
	g.PrintReOrderedGraph(order, ofilename);
	cout << endl;
}

