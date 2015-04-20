#include <cstdlib>
#include <iostream>
using namespace std;

struct point 
{
   int x;
   int y;
};

int isGood(point pt)
{
   if (pt.x == pt.y)
     return 1;
   if (pt.x == pt.y + 2)
     return 1;
   
   return 0;
   
}

void displayPoint(point pt)
{
   if (pt.x == pt.y)
   {
      if (pt.y % 2 == 0)
      {
         cout << (pt.y * 2);
      }
      else
      {
         cout << (pt.y * 2) - 1;
      }
   } else {
      if (pt.y % 2 == 0) {
         cout << (pt.y * 2) + 2;
      } else {
         cout << (pt.y * 2) + 1;
      }
   }
   cout << endl;
}



int main(int argc, char *argv[])
{
   int numTests;
   cin >> numTests;
   
   for (int test = 0; test < numTests; test++)
   {
      point pt;
      cin >> pt.x;
      cin >> pt.y;
      
      if (isGood(pt))
      {
         displayPoint(pt);
      }
      else
      {
         cout << "No Number" << endl;
      }
   }
   
   return EXIT_SUCCESS;
}
