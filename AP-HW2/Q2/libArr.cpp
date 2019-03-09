#include<iostream>
#include"libArr.h"

LibArr::LibArr(){};

int LibArr::counter(int c)
{
  int result{};
  int storge[c];
  for(int j{};j<c;j++)
    storge[j]=j;
  for(int k{};k<c;k++)
    result += storge[k];
  return result;
}
