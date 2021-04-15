#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void Edge2Csr() {
  ifstream file(argv[1], ios::in);
  map<int, vector<int> > graph;
  ofstream ofile(argv[2], ios::out);
  int vid1, vid2, max_vid = -1, edge_cnt = 0;
  string graphname;
  file>>graphname;
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
}

int main(int argc, char **argv) {
  ifstream file(argv[1], ios::in);
  map<int, vector<int> > graph;
  int vid1, vid2;
  while (file>>vid1>>vid2) {
    graph[vid1].push_back(vid2);
  }
  int count = 0;
  for (auto &pair : graph) {
    int pre = -1;
    sort(pair.second.begin(), pair.second.end());
    for (const auto &v : pair.second) {
      if (v == pre || v == pair.first) {
        count++;
      }
      pre = v;
    }
  }
  cout<<"deplicated : "<<count<<endl;
  return 0;
}