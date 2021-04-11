#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int main(int argc, char **argv) {
  unordered_set<int> written;
  vector<int> offsets, neworder;
  vector<int> edges;
  vector<pair<int, int> > vertices;
  string graph_name;
  ifstream ifile(argv[1], ios::in);
  ifile>>graph_name;
  int vcnt, ecnt;
  ifile>>vcnt>>ecnt;
  offsets.resize(vcnt + 1);
  edges.resize(ecnt);
  vertices.resize(vcnt, pair<int, int>(0, 0));
  for (int i=0; i<vcnt; i++) {
    ifile>>offsets[i];
  }
  offsets[vcnt] = ecnt;
  for (int i=1; i<=vcnt; i++) {
    vertices[i-1].first = i-1;
    vertices[i-1].second = offsets[i] - offsets[i-1];
  }
  for (int i=0; i<ecnt; i++) {
    ifile>>edges[i];
    vertices[edges[i]].second++;
  }
  ifile.close();
  int avg_degree = (ecnt * 2) / vcnt;
  ofstream ofile("csr_hub_cluster", ios::out);
  ofile<<"AdjacencyGraph\n";
  ofile<<vcnt<<'\n';
  ofile<<ecnt<<'\n';
  for (int i=0; i<vcnt; i++) {
    if (vertices[i].second < avg_degree) {
      break;
    }
    neworder.push_back(vertices[i].first);
    written.insert(vertices[i].first);
  }
  for (int i=0; i<vcnt; i++) {
    if (written.find(i) == written.end()) {
      neworder.push_back(i);
    }
  }
  int off = 0;
  for (const auto &vid : neworder) {
    ofile<<off<<'\n';
    off += offsets[vid+1] - offsets[vid];
  }
  for (const auto &vid : neworder) {
    for (int j=offsets[vid]; j<offsets[vid+1]; j++) {
      ofile<<edges[j]<<'\n';
    }
  }
  ofile.close();
  return 0;
}