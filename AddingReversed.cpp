#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

unsigned int reverse(unsigned int num)
{
   vector<unsigned int> iVec;
   unsigned int revNum = 0;
   while (num > 0)
   {
      unsigned int digit = num % 10;
      iVec.push_back(digit); 
      num = num / 10;
   }
   unsigned int mult = 1;
   unsigned int leadZero = 1;
   while (iVec.size())
   {
      unsigned int number = iVec.back();
      if (leadZero && number == 0)
      {
         continue;
      }
      else 
      {
         leadZero = 0;
         revNum += mult * iVec.back();
         iVec.pop_back();
         mult *= 10;
      }
   }
   return revNum;
}     
      

int main(int argc, char *argv[])
{
   int numTests = 0;
   cin >> numTests;
   while (numTests > 0)
   {
      unsigned int num1, num2, rsum;
      cin >> num1;
      cin >> num2;
      num1 = reverse(num1);
      num2 = reverse(num2);
      rsum = num1 + num2;
      rsum = reverse(rsum);
      cout << rsum << endl;
          
      numTests--;  
   }
   //system("PAUSE");
   return EXIT_SUCCESS;
}
