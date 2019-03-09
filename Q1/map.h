#ifndef MAP_H
#define MAP_H
#include<vector>
#include<iostream>
class Map
{
 public:
  
  Map(int,int);
  ~Map();
  
  void showMap();
  void showRoute();
  void findRoute();
  void findOptimized();
  int comp(std::vector<int>);
  int go(std::vector<int>p);
 private:
  
  int n,x,y,Distance,guide;
  int** num;
  char** show;
};

int factorial(int);

#endif
