#ifndef PERSONH
#define PERSONH

#include <string>
#include <iostream>

class person {
  friend std::istream &read(std::istream&,  person&);
  friend std::ostream &print(std::ostream&, const  person&);
public:
  //conors
  person() = default;
  person(const std::string &name, const std::string &address ="")
    : p_name(name), p_address(address) { }
  person(std::istream &is) {is >> p_name >> p_address;}
  //member functions
  const std::string& name() const {return p_name;}
  const std::string& address() const {return p_address;}
private:
  // data members
  std::string p_name;
  std::string p_address;
};
std::istream &read(std::istream&,  person&);
std::ostream &print(std::ostream&, const  person&);
#endif
