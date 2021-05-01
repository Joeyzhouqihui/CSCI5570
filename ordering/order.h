#ifndef ORDER_H

#include <string>

class Order{
  public:
    virtual void readGraph(std::string filename);
    virtual void order();
    virtual void saveGraph(std::string filename);
    virtual void ~Order();
};

#define ORDER_H