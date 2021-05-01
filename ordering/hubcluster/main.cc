#include "hubcluster.h"
#include <iostream>

int main(int argc, char **argv) {
  std::string ifile, ofile;
  ifile = argv[1];
  ofile = argv[2];
  Hubcluster hubcluster;
  hubcluster.readGraph(ifile);
  double cost = hubcluster.order();
  hubcluster.saveGraph(ofile);
  std::cout<<"hub sort cost : "<<cost<<std::endl;
  return 0;
}