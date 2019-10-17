#ifndef EMPLOYEEH
#define EMPLOYEEH

#include <string>

class Employee
{
public:
  Employee(std::string name = "") :name_(name), id_(++s_incre){}
  const int id() const {return id_;}
private:
  std::string name_;
  int id_;
  static int s_incre;

};

int Employee::s_incre = 0;

#endif
