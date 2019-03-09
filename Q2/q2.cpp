#include<iostream>
#include"libVec.h"
#include"libArr.h"
#include<ctime>
#include<cmath>

template <typename T>
void runTime(int(T::*V)(int),T* object,int n);
int main()
{
  ////////////////////making object
  LibVec a{};
  LibArr b{};
  /////////////////////pointer to object
  LibVec* ptrV=&a;
  LibArr* ptrA=&b;
  int n{};
  ////////////////////pointer to function of class
  int (LibVec::*V)(int)= & LibVec::counter;
  int (LibArr::*A)(int)=& LibArr::counter;
  ////////////////////calculating for 1,10,....,10^6
  for(int i{};i<7;i++)
    {
      n=static_cast<int>(pow(10,i));
      std::cout<<"*For n = "<<n<<" :"<<std::endl;
      std::cout<<"Run time for Vector: ";
      runTime <LibVec>  (V,ptrV,n);/////////calling function
      std::cout<<"Run time for Array: ";
      runTime <LibArr>  (A,ptrA,n);/////////calling function
      std::cout<<std::endl;
    }
  
  return 0;
}
template <typename T> //////////function for calculating run time
void runTime(int(T::*V)(int) ,T* object,int n)
{
  clock_t t{};
  t=clock();//////measuring time
  ((*object).*V)(n);//////calling function
  t=clock()-t;//////founding time
  std::cout<<std::endl<<(((float)t/CLOCKS_PER_SEC)/1000)<<" Microsecond"<<std::endl;////////displaying time
  }
