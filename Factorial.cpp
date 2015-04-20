#include <cstdlib>
#include <iostream>
#include <map>
#include <cstdio>
#include <string>

using namespace std;

typedef unsigned int uint;
typedef map<uint,uint> factorial;


uint numberZerosAdded(uint arg)
{
   uint rZeros = 0;
   uint divisor = 5;
   while (arg / divisor > 0)
   {
      rZeros += (arg / divisor);
      divisor = divisor * 5;
   }
   return rZeros;
}

uint updateMap(factorial &map, uint number)
{
   uint rZeros = 0;

   rZeros = numberZerosAdded(number);
   map[number] = rZeros;
      
   return rZeros;
}

int main(int argc, char *argv[])
{
   uint numTests;
   cin >> numTests;
   
   factorial fmap;
   fmap[1] = 0;
   
   
   for (int x = 0; x < numTests; x++)
   {
      uint number;
      cin >> number;
      
      uint zeros = 0;
      factorial::iterator fIter = fmap.find(number);
      
      if (fIter != fmap.end())
      {
         zeros = fIter->second;
      }
      else
      {
         zeros = updateMap(fmap,number);
      }
      
      cout << zeros << endl;
      
   }
      
   
   //system("PAUSE");
   return EXIT_SUCCESS;
}
