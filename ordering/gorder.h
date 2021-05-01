#ifndef GORDER_H

#include "order.h"
#include "Util.h"
#include "UnitHeap.h"
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

class Vertex{
  public:
	  int outstart;
	  int outdegree;
	  int instart;
	  int indegree;

	  Vertex() {
		  outdegree=indegree=0;
		  outstart=instart=-1;
	  }
};

class Gorder : public Order{
  private:
    int vcnt_, ecnt_;
    std::vector<Vertex> graph_;
		std::vector<int> outedge_;
		std::vector<int> inedge_;

  public:
    virtual void readGraph(std::string filename);
    virtual void order();
    virtual void saveGraph(std::string filename);

};

#define GORDER_H