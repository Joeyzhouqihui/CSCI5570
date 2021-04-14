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
  int vid1, vid2;
  while (file>>vid1>>vid2) {
    graph[vid1].push_back(vid2);
  }
  int count = 0;
  for (auto &pair : graph) {
    int pre = -1;
    sort(pair.second.begin(), pair.second.end());
    for (const auto &v : pair.second) {
      if (v == pre) {
        count++;
      }
      pre = v;
    }
  }
  cout<<"deplicated : "<<count<<endl;
  return 0;
}