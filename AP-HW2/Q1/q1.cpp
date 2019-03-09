/////////// 9623088 - kimia Ghodsifar//////////

#include<iostream>
#include"map.h"

int main()
{
  int n{},guide{};
  std::string answer{};
  //////////////////////////////recieving n
  std::cout<<"Enter n please:";
  std::cin>>n;
  //////////////////////////////we want to know "which part should we run?"
  std::cout<<std::endl<<"If you want to move:"<<std::endl<<std::endl;
  std::cout<<" only right & down----> enter 1(part a)"<<std::endl<<std::endl;
  std::cout<<" Right,down,diagonal---> enter 2(part b)";
  std::cin>>guide;
  //////////////////////making a map and initialize with given information
  Map map1{n,guide};
  map1.showMap(); ////showing made map
  map1.findRoute();//////find Route by part a or b
  map1.showRoute(); ///// showing found Route

  /////////////////Asking for running part c or not ?
  std::cout<<std::endl<<std::endl<<"Do you want to see the most optimied route too?(yes/no)";
  std::cin>>answer;
  if(answer == "yes")
    {
      map1.findOptimized(); ////////// processing
      map1.showRoute();     //////// showing result
   }
  return 0;
}

