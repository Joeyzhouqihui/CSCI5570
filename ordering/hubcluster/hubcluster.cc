#include "hubcluster.h"

Hubcluster::Hubcluster() : vcnt_(0), ecnt_(0) {}

void Hubcluster::readGraph(std::string filename) {
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

double Hubcluster::order() {
  double start_time = omp_get_wtime();
  int avg_degree = (ecnt_ * 2) / vcnt_;
  std::vector<int> written(vcnt_, 0);
  for (int i=0; i<vcnt_; i++) {
    if (weight_[i] > avg_degree) {
      new_order_.push_back(i);
      written[i] = 1;
    }
  }
  for (int i=0; i<vcnt_; i++) {
    if (written[i] == 0) {
      new_order_.push_back(i);
    }
  }
  start_time = omp_get_wtime() - start_time;
  assert(new_order_.size() == vcnt_);
  return start_time;
}

void Hubcluster::saveGraph(std::string filename) {
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