#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char **argv) {
  vector<pair<int, int> > vec;
  for (int i=0; i<10; i++) {
    vec.push_back(pair<int, int>(i, i));
  }
  auto lambda = [](pair<int, int> &p1, pair<int, int> &p2) {
    return p1.second > p2.second;
  };
  sort(vec.begin(), vec.end(), lambda);
  for (const auto &pair : vec) {
    cout<<pair.first<<" : "<<pair.second<<endl;
  }
  return 0;
}