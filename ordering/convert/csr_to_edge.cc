#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
  ifstream file(argv[1], ios::in);
  int vcnt, ecnt, vid1, vid2;
  file>>vcnt>>ecnt;
  vector<int> offsets(vcnt + 1, 0);
  vector<int> edges(ecnt, 0);
  for (int i=0; i<vcnt; i++) {
    file>>offsets[i];
  }
  offsets[vcnt] = ecnt;
  for (int i=0; i<ecnt; i++) {
    file>>edges[i];
  }
  ofstream ofile(argv[2], ios::out);
  for (int i=0; i<vcnt; i++) {
    for (int j=offsets[i]; j<offsets[i+1]; j++) {
      ofile<<i<<" "<<edges[j]<<"\n";
    }
  }
  ofile.close();
  return 0;
}