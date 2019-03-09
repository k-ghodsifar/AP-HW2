#include"map.h"
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

///////////////////////////constructor
Map::Map(int n,int guide)
{
  this->n=n;
  this->guide=guide;
  x=y=Distance=0;
  num=new int*[n];
  show=new char*[n];
  for(int i{};i<n ; i++)
    {
    num[i]=new int[n];
    show[i]=new char[n];
    }

   srand(time(nullptr));
   /////////////////////"num" is showing altitude and "show" is showing map
   for(int i{};i<n;i++)
       for(int j{};j<n;j++)
	 {
	   num[i][j]=(rand())%101;  /////random value for altitudes
	   show[i][j]='-';          /////showing everywhere by "-"
	 }
   show[0][0]='+';                  ///// the point that starts moving
}

////////////////distructor
Map:: ~Map()      
{
  for(int i{n-1};i>=0;i--)
    {
      delete [] num[i];
      delete [] show[i];
    }
  delete [] num;
  delete [] show;
}

////////////////////////showing map by numbers
void Map::showMap()
{
      for(int i{};i<n;i++)
      {
	for(int j{};j<n;j++)
	    std::cout<<num[i][j]<<"\t";
	std::cout<<std::endl;
	}    
}
////////////////////////showing map by signs

void Map:: showRoute()
{
   for(int i{};i<n;i++)
      {
	for(int j{};j<n;j++)
	    std::cout<<show[i][j]<<"\t";
	std::cout<<std::endl;
	}    
}


////////////////////////////finding route (part a or part b)
void Map::findRoute()
{
  /////////////////////////////////part a
  if(guide == 1)
    {
      ////////////////////////////////we are not in the wall :)
          while(y!=(n-1) && x!=(n-1))
             { 
               if(abs(num[y][x] - num[y][x+1]) <= abs(num[y][x]-num[y+1][x]))
                 {
                    Distance += abs(num[y][x] - num[y][x+1]);
                    ++x; //////moving right
                 }
               else
                {
                  Distance += abs(num[y][x] - num[y+1][x]);
                  ++y;//////////moving down
                 }
                show[y][x]='+';
              }
  
          if( y==(n-1) && x!=(n-1) ) //////you arrive to wall?
             {
	       for(int j{x+1};j<n;j++) ////////going right
                   {
        	     show[y][j]='+';
        	     Distance += abs(num[y][j]-num[y][j-1]);
                   }
	
              }

          if( x==(n-1) && y!=(n-1) )  /////////you arrive a wall?
             {
               for(int j{y+1};j<n;j++) ////////going down
        	{ 
        	  show[j][x]='+';
	          Distance += abs(num[j][x]-num[j-1][x]);
        	}
	
              }
    }
  if(guide==2)////////////////////part b
    {
      while(x!=(n-1) && y!=(n-1))////////////are you arriving a wall?
	{
	  //////////////////////finding where to go
	        if(abs(num[y][x] - num[y][x+1]) <= abs(num[y][x]-num[y+1][x]))
              	{
	          if(abs(num[y][x+1]-num[y][x]) <= abs(num[y][x]-num[y+1][x+1]))
		    {
		      Distance += abs(num[y][x]-num[y][x+1]);
	              ++x;////////////going right
		    }
	          else
	           {
		     Distance += abs(num[y][x]-num[y+1][x+1]);
	             x++;
	             y++;/////////////going right and down
	            }
          	}
             else
         	{
        	  if(abs(num[y+1][x]-num[y][x]) <= abs(num[y][x]-num[y+1][x+1]))
		    {
		      Distance += abs(num[y][x]-num[y+1][x]);
		      ++y;//////////going down
		    }
         	  else
        	    {
		      Distance += abs(num[y][x]-num[y+1][x+1]);
	              ++x;
	              ++y;////////////going right and down
	             }
        	}
		show[y][x]='+';//////////sign route
	}
      if( x==(n-1) && y!=(n-1) )///////////arriving a wall?
          {
            for(int j{y+1};j<n;j++)
              { 
                show[j][x]='+';
	        Distance += abs(num[j][x]-num[j-1][x]);
              }
	
          }
      if( y==(n-1) && x!=(n-1) )  ///////////arriving a wall?
          {
            for(int j{x+1};j<n;j++)
              {
               show[y][j]='+';
               Distance += abs(num[y][j]-num[y][j-1]);
              }
	 }
      
    }
  std::cout<<"Distance:"<<Distance<<std::endl; ///////showing distance
}
///////////////////////////////part c
void Map::findOptimized()
{
  int c{factorial(2*(n-1))/(factorial(n-1)*factorial(n-1))};
  int count{},distance[c]{};
  std::vector<int> permute;
  for(int j{};j<(2*(n-1));j++)//////defining permute
    {
      if( j< (n-1) )
          permute.push_back(0);
      else
 	  permute.push_back(1);
    }
  /////////////////////////////calculating distance for every permute
  for(int i{};i<c;i++)
    {
      std::next_permutation(permute.begin(),permute.end());
      distance[i]=comp(permute);//////calling function for calculate distance
      if(distance[i]<distance[count])
	count=i;
    }
  /////////////////////////////////we make that permute with least distance
  for(int k{};k<(count+1);k++)
    std::next_permutation(permute.begin(),permute.end());
  ///////////////////////////////printing distances
  std::cout<<std::endl<<"We calculate these distances:"<<std::endl;
  for(int j{};j<c;j++)
    std::cout<<distance[j]<<"  "; //////////going of least distance 
  std::cout<<std::endl<<"So we offer this route that its distance is: "<<go(permute)<<std::endl;
}
////////////function for going of every permute 
int Map::comp(std::vector<int> permute)
{
  int x{},y{},distance{},flag{};
  for(int i{};i<(2*(n-1));i++)
   {
     if(flag == 0)
       {
         if(permute[i]==0)
	  {		
	    distance += abs(num[y][x]-num[y][x+1]);
	    x++;
	    if(x==(n-1))
	     {
	      for(int k{y};k<(n-1);k++)
	      distance += abs(num[k][x]-num[k+1][x]);
	      flag++;
	      }
	   }

   	   else
	     {
	       distance += abs(num[y][x]-num[y+1][x]);
	       y++;
	       if(y==(n-1))
	        {
		 for(int k{x};k<(n-1);k++)
		 distance += abs(num[y][k]-num[y][k+1]);
		 flag++;
		 }
	      }
        }
      else
	break;	  
   }
  return distance;
}
////////////////////////////////going from least distance
int Map::go(std::vector<int>permute)
{
  int x{},y{},distance{},flag{};
  ////////////////////////////////making map clean
  for(int k{};k<n;k++)
    for(int j{};j<n;j++)
      show[k][j]='-';
  show[y][x]='+';
  //////////////////////////////going
  for(int i{};i<(2*(n-1));i++)
   {
     if(flag == 0)
       {
         if(permute[i]==0)
	  {		
	    distance += abs(num[y][x]-num[y][x+1]);
	    x++;
	    show[y][x]='+';
	    if(x==(n-1))
	     {
	      for(int k{y};k<(n-1);k++)
		{
	          distance += abs(num[k][x]-num[k+1][x]);
		   show[k+1][x]='+';
		} 
	      flag++;
	      }
	   }

   	   else
	     {
	       distance += abs(num[y][x]-num[y+1][x]);
	       y++;
	       show[y][x]='+';
	       if(y==(n-1))
	        {
		 for(int k{x};k<(n-1);k++)
		   {
		     distance += abs(num[y][k]-num[y][k+1]);
		     show[y][k+1]='+';
		   }
		 flag++;
		 }
	      }
        }
      else
	break;	  
   }
  return distance;
}

////////////////calculating factorial
int factorial(int c)
{
  int result{1};
  for(int j{0};j<c;j++)
    {
      result *= (j+1);
    }
  return result;
}
