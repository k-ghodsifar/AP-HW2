#include<iostream>
#include"old.h"
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
int main()
{
  std::string fileename{};
  std::cout<<"Enter name of file with its suffix."<<std::endl;
  std::cin >> fileename; /////getting file name
  std::ifstream in {fileename};
  std::string temp{},s1{},s2{},s3{},s4{}; 
  int counter{};
  std:: vector<Old> input{};
  Old oldtemp{};
  ///////////////////////////storing important information in vector of old
  while (!in.eof())
    {
      getline(in,temp);/////////receiving from file
      std::istringstream ss{temp};
      ss>> s1>> s2 >> s3 >> s4;
      oldtemp.set_day(s1);
      oldtemp.set_p_id(s3);
      oldtemp.set_c_id(s4);
      input.push_back(oldtemp);
      ++counter;
    }
   counter--;
   input.erase(input.begin() + counter);
   std::ofstream of{"dbnew.txt"}; ////////writing in new file
   int flagp{},flagc{},start{},end{},product_c{1},customer_c{1};
   while(end != counter) 
     {
       if((input[end]).day == (input[end+1]).day )///finding same days
	   ++end;
       //////process same day
       if( end == (counter-1) || (input[end]).day != (input[end+1]).day)
	 {
	   for(int i{start+1};i<(end+1);i++) //moving in same day information
	     {
	       flagp=flagc=0;
	       for(int j{i-1};j >= start ; j--)
		 {
		   /////checking different production
		   if( (input[i]).pid == (input[j]).pid)
		     ++flagp;
		   ////checking different customer
		   if( (input[i]).cid == (input[j]).cid)
		     ++flagc;
		 }
	       if(flagp == 0)
		 ++product_c; ///adding different product
	       if(flagc ==0 )
		 ++customer_c;	///adding different customer 
	     }
	   /////////printing
	   of<<(input[start]).day + "] "<<product_c<<" "<<customer_c<<std::endl;
	   end++; ////update index
	   start=end;////update index
	   customer_c = product_c =1;///updating counters
	 }
     }
   ////////////closing files
  in.close();
  of.close();
  std::cout<<"Done!"<<std::endl;
  return 0;
}
