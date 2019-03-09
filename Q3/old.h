#ifndef OLD_H
#define OLD_H
#include<iostream>
#include<string>
class Old
{
 public:
  
  Old();
  Old(const Old& old);
  void set_day(std::string);
  void set_p_id(std::string);
  void set_c_id(std::string);
  // private:
  std::string day{};
  std::string pid{};
  std::string cid{};   
};
#endif
