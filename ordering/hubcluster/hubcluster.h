#ifndef HUBCLUSTER_H
#define HUBCLUSTER_H

#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <omp.h>
#include <assert.h>

class Hubcluster {
  private:
    int vcnt_, ecnt_;
    std::map<int, std::vector<int> > edges_;
    std::unordered_map<int, int> weight_;
    std::vector<int> new_order_;
    
  public:
    Hubcluster();
    virtual void readGraph(std::string filename);
    virtual double order();
    virtual void saveGraph(std::string filename);
};

#endif