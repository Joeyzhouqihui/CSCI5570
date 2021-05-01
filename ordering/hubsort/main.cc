#include "hubsort.h"
#include <iostream>

int main(int argc, char **argv) {
  std::string ifile, ofile;
  ifile = argv[1];
  ofile = argv[2];
  Hubsort hubsort;
  hubsort.readGraph(ifile);
  std::cout<<"finish read graph"<<std::endl;
  double cost = hubsort.order();
  std::cout<<"hub sort cost : "<<cost<<std::endl;
  hubsort.saveGraph(ofile);
  std::cout<<"finish save graph"<<std::endl;
  return 0;
}