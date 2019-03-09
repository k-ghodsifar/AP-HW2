#include"old.h"
#include<iostream>
#include<string>

Old::Old()
{}

Old::Old(const Old& old)
{
  day=old.day;
  pid=old.pid;
  cid=old.cid;
}


void Old::set_day(std::string day){
  this->day=day;
}

void Old::set_p_id(std::string pid){
  this->pid=pid;
}

void Old::set_c_id(std::string cid){
  this-> cid= cid;
}

