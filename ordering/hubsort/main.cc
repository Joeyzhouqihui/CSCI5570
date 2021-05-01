#include "hubsort.h"
#include <iostream>

int main(int argc, char **argv) {
  std::string ifile, ofile;
  ifile = argv[1];
  ofile = argv[2];
  Hubsort hubsort;
  hubsort.readGraph(ifile);
  double cost = hubsort.order();
  hubsort.saveGraph(ofile);
  std::cout<<"hub sort cost : "<<cost<<std::endl;
  return 0;
}