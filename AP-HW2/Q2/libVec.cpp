#include"libVec.h"
#include<vector>
#include<iostream>

LibVec::LibVec(){};
int LibVec::counter(int c)
{
  int result{};
  std::vector<int>storge;
  for(int j{};j<c;j++)
    storge.push_back(j);
  for(int i{};i<c;i++)
    result += storge[i];
  return result;
    
}
