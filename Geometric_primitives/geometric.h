#ifndef MYGEOMETRICH
#define MYGEOMETRICH

#include <string>
class prim {
public:
  virtual std::string name() const = 0;
  virtual ~prim() = 0;
  int i;
};

class prim_2d : public prim{
  friend void f(prim_2d &n);
public:
  virtual double area() const = 0;
  virtual double circumference() const = 0;
};

class circle : public prim_2d{
public:
  circle() =default;
  circle(double radius) : __radius(radius) { }
  std::string name() const {return "Circle";}
  double area() const  {return __radius * __radius * pi;}
  double circumference() const  {return __radius * pi * 2;}
private:
  double __radius = 0;
  static double pi;
};

class prim_3d : public prim{
public:
  virtual double surface_area() const = 0;
  virtual double volume() const = 0;
};

class sphere : public prim_3d{
public:
  sphere() = default;
  sphere(double r) : __radius(r) { }
  std::string name() const {return "Sphere";}
  double surface_area() const ;
  double volume() const ;
private:
  double __radius;
  static double pi;
};

class cone : public prim_3d{
public:
  cone() = default;
  cone(double r, double h) : __radius(r), __height(h) { }
  std::string name() const {return "Cone";}
  double surface_area() const ;
  double volume() const ;
private:
  double __radius;
  double __height;
};

class box : public prim_3d{
public:
  box() = default;
  box(double l) : length(l) { }
  std::string name() const {return "Box";}
  double surface_area() const ;
  double volume() const ;
private:
  double length;
};

#endif
