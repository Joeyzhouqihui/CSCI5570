#include "hubsort.h"

Hubsort::Hubsort() : vcnt_(0), ecnt_(0) {}

void Hubsort::readGraph(std::string filename) {
  std::ifstream ifile(filename.c_str(), std::ios::in);
  int vid1, vid2;
  int max_id = -1;
  while (ifile>>vid1>>vid2) {
    edges_[vid1].push_back(vid2);
    if (vid1 >= max_id) {
      max_id = vid1;
    }
    if (vid2 >= max_id) {
      max_id = vid2;
    }
    ecnt_++;
    weight_[vid1]++;
    weight_[vid2]++;
  }
  vcnt_ = max_id + 1;
  ifile.close();
  return;
}

double Hubsort::order() {
  std::vector<std::pair<int, int> > vertices;
  vertices.resize(vcnt_);
  for (int i=0; i<vcnt_; i++) {
    vertices[i].first = i;
    vertices[i].second = weight_[i];
  }
  auto lambda = [](std::pair<int, int> &p1, std::pair<int, int> &p2) {
    return p1.second > p2.second;
  };
  double start_time = omp_get_wtime();
  std::sort(vertices.begin(), vertices.end(), lambda);
  int avg_degree = (ecnt_ * 2) / vcnt_;
  std::unordered_set<int> written;
  for (int i=0; i<vcnt_; i++) {
    if (vertices[i].second > avg_degree) {
      new_order_.push_back(vertices[i].first);
      written.insert(vertices[i].first);
    }
  }
  for (int i=0; i<vcnt_; i++) {
    if (written.find(i) == written.end()) {
      new_order_.push_back(i);
    }
  }
  start_time = omp_get_wtime() - start_time;
  assert(new_order_.size() == vcnt_);
  return start_time;
}

void Hubsort::saveGraph(std::string filename) {
  std::unordered_map<int, int> id_remap;
  for (int i=0; i<vcnt_; i++) {
    id_remap[new_order_[i]] = i;
  }
  std::ofstream ofile(filename.c_str(), std::ios::out);
  ofile<<"AdjacencyGraph\n";
  ofile<<vcnt_<<'\n';
  ofile<<ecnt_<<'\n';
  int off = 0;
  for (const auto &vid : new_order_) {
    ofile<<off<<'\n';
    off += edges_[vid].size();
  }
  for (const auto &vid : new_order_) {
    for (const auto &adj : edges_[vid]) {
      ofile<<id_remap[adj]<<'\n';
    }
  }
  ofile.close();
  return;
}