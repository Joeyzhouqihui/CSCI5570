#include "hubcluster.h"
#include <iostream>

int main(int argc, char **argv) {
  std::string ifile, ofile;
  ifile = argv[1];
  ofile = argv[2];
  Hubcluster hubcluster;
  hubcluster.readGraph(ifile);
  std::cout<<"finish read graph"<<std::endl;
  double cost = hubcluster.order();
  std::cout<<"hub cluster cost : "<<cost<<std::endl;
  hubcluster.saveGraph(ofile);
  std::cout<<"finish save graph"<<std::endl;
  return 0;
}