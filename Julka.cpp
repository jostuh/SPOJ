#include <cstdlib>
#include <iostream>
#include <list>
#include <string>
using namespace std;

typedef list<short int> num;
typedef num::iterator niter;
typedef unsigned int uint;

void addTwo(num d1, num d2,
            num &rS)
{
   rS.clear();
   niter oI = d1.end(); oI--;
   niter tI = d2.end(); tI--;
   
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
      } else {
       carry = 0;
      }
      rS.push_front(number);
      oI--; tI--;
   }
   niter it;
   if (fL) {
     it = oI;
   } else { 
      it = tI;}  
      while (remainder > 0) {
        number = *it + carry;
        if (number >= 10) {
          number -=10;
          carry = 1;
        } else {
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

void subtractTwo(num digit1,num digit2, num& result)
{
   result.clear();
   list<short int>::iterator oneIter = digit1.end(); oneIter--;
   list<short int>::iterator twoIter = digit2.end(); twoIter--;

   
   unsigned int remainder = digit1.size() - digit2.size();
   int carry = 0;
   int number = 0;
   for (int i = 0; i < digit2.size(); i++)
   {
      number = *oneIter - *twoIter - carry;
      if (number < 0)
      {
         number +=10;
         carry = 1;
      }
      else
      {
         carry = 0;
      }    
      result.push_front(number);
      oneIter--; twoIter--;
   }
   while (remainder > 0)
   {
      number = *oneIter - carry;
      if (number < 0)
      {
         number +=10;
         carry = 1;
      }
      else
      {
         carry = 0;
      }
      result.push_front(number);
      oneIter--;
      remainder--;
   }
   
   // Pop leading zeros
   while (result.front() == 0)
   {
      result.pop_front();
   }
   if (result.size() == 0)
   {
      result.push_front(0);
   }
}

void convertStringToNum(string str, num &number)
{
   number.clear();
   for(string::iterator strIter = str.begin();strIter != str.end(); strIter++)
   {
      short int digit = *strIter - '0';
      number.push_back(digit);
   }
}

void divideByTwo(num number, num& result)
{
   result.clear();
   int carry = 0;
   for (niter iter = number.begin(); iter != number.end(); ++iter)
   {
      short int digit = *iter;
      if (carry) {
         digit += 10;
      }
      if (digit % 2 == 1) {
         carry = 1;
      } else {
         carry = 0;
      }
      result.push_back(digit/2);
   }
   // Pop leading zeros
   while (result.front() == 0)
   {
      result.pop_front();
   }
   if (result.size() == 0)
   {
      result.push_front(0);
   }
}

void displayNum(num& result)
{
   for (niter iter = result.begin(); iter != result.end(); ++iter)
   {
      cout << *iter;
   }
   if (result.size() == 0)
     cout << 0;
   cout << endl;
}  
  

int main(int argc, char *argv[])
{
   
   for (int i = 0; i < 10; i++)
   {
      string apples;
      num numApples;
      num halfApples;
      num numMore;
      num halfMore;
      string more;
      cin >> apples;
      cin >> more;
      
      convertStringToNum(apples, numApples);
      convertStringToNum(more, numMore);

      // multiply apples by 10
      numApples.push_back(0);
      numMore.push_back(0);
      
      divideByTwo(numApples, halfApples);
      divideByTwo(numMore, halfMore);
      
      num result;
      addTwo(halfApples,halfMore,result);
      result.pop_back();
      displayNum(result);
      subtractTwo(halfApples,halfMore,result);
      result.pop_back();
      displayNum(result);
      
   }
   //system("PAUSE");
   return EXIT_SUCCESS;
}
