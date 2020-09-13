#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
using namespace std;
class Rectangle {
public:
   Rectangle(int, int, int, int);  // constructor
   ~Rectangle(); // destructor
   void Print();
   int Area();
   bool LessThan(Rectangle&);
   bool Equal(Rectangle&);
   int GetHeight();
   int GetWidth();
   bool operator<(Rectangle&);
   bool operator==(Rectangle&);
   friend ostream& operator<<(ostream&, Rectangle&);

private:
   int xLow, yLow, height, width;
  
};
#endif