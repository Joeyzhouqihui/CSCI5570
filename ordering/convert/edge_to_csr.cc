#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
  ifstream file(argv[1], ios::in);
  map<int, vector<int> > graph;
  ofstream ofile(argv[2], ios::out);
  int vid1, vid2, max_vid = -1, edge_cnt = 0;
  string graphname = "AdjacencyGraph";
  while (file>>vid1>>vid2) {
    graph[vid1].push_back(vid2);
    edge_cnt++;
    if (max_vid < vid1) {
      max_vid = vid1;
    }
    if (max_vid < vid2) {
      max_vid = vid2;
    }
  }
  ofile<<graphname<<'\n';
  ofile<<(max_vid + 1)<<'\n';
  ofile<<edge_cnt<<'\n';
  int cnt_off = 0;
  for (int i=0; i<=max_vid; i++) {
    ofile<<cnt_off<<'\n';
    cnt_off += graph[i].size();
  }
  for (int i=0; i<=max_vid; i++) {
    sort(graph[i].begin(), graph[i].end());
    for (const auto &vid : graph[i]) {
      ofile<<vid<<'\n';
    }
  }
  ofile.close();
  return 0;
}