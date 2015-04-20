#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
using namespace std;
typedef list<short int> num;
typedef num::iterator iter;
typedef unsigned int uint;
typedef map<uint,num> nmap;
typedef nmap::iterator miter;
void addTwo(num d1, num d2,
            num &rS)
{
      iter oI = d1.end(); oI--;
      iter tI = d2.end(); tI--;
      
      uint size = d1.size();
      int fL = 0;
      uint remainder = d2.size() - d1.size();
   
      if (d2.size() < size)
      {
         fL = 1;
         remainder = d1.size() - d2.size();
         size = d2.size();
      }
      int carry = 0;
      int number = 0;
      for (int i = 0; i < size; i++)
      {
         number = *oI + *tI + carry;
         if (number >= 10)
         {
            number -=10;
            carry = 1;
         }
else
{
carry = 0;
}
rS.push_front(number);
oI--; tI--;
}
iter it;
if (fL)
{
it = oI;
}
else
{it = tI;}  
while (remainder > 0)
{ number = *it + carry;
if (number >= 10)
{
number -=10;
carry = 1;
}
else
{
carry = 0;
}
rS.push_front(number);
it--;
remainder--;
}
   if (carry)
   {
   rS.push_front(1);
   }   
}
int main(int argc, char *argv[])
{
   int numTests;
   cin >> numTests;
   nmap M;
   
   for (int test = 0; test < numTests; test++)
   {
     num second;
     num rS;
   
     int factorial;
     cin >> factorial;
   
     rS.push_back(1);
   
     for (uint i = 1; i < factorial; i++)
     {
      miter i1 = M.find(i);
      if (i1 == M.end()) {
        num first = rS;
        num tmp = rS;
        for (int x = 0; x < i; x++)
        {
            rS.clear();
            addTwo(first,tmp,rS);
            tmp = rS;          
        }
        M[i] =rS;
      } else {
         rS = M[i];
      }
     }
iter rSIter = rS.begin();
for(int i = 0; i < rS.size(); i++)
{
cout << *rSIter;
rSIter++;
}
cout << endl;
}
return 0;
}
