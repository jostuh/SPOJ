#include <cstdlib>
#include <iostream>
#include <list>
#include <cstdio>

using namespace std;

void findPalindrome1(list<short int> &digits)
{
   list<short int>::iterator frontIter = digits.begin();
   list<short int>::iterator backIter = digits.end(); backIter--;
   while (frontIter != backIter)
   {
      if (*backIter > *frontIter)
      {
         *backIter = *frontIter;
         list<short int>::iterator iter = backIter;
         iter--;
         *iter = *iter + 1;
         while (*iter == 10)
         {
            *iter = 0;
            iter--;
            *iter = *iter + 1;
         }
      }

      frontIter++;
      if (frontIter == backIter)
      {
         break;
      }
      backIter--;
   }
   frontIter = digits.begin();
   backIter = digits.end(); backIter--;
   while (frontIter != backIter)
   {
      *backIter = *frontIter;
      frontIter++;
      if (frontIter == backIter)
      {
         break;
      }
      backIter--;
   }      
   
}    

int main(int argc, char *argv[])
{
   unsigned int numTests, number;
   short int shortNum;
   char digit;
   const char zero = '0';
  
   cin >> numTests;
   
   while (numTests > 0)
   {
      list<short int> digits;
      digit = getchar();
      while (digit == ' ' || digit == '\n')
      {
         digit = getchar();
      }
      while(digit != '\n' && digit != ' ')
      {
         shortNum = digit - zero;
         digits.push_back(shortNum);
         digit = getchar();
         if (digit == ' ' || digit == '\n' || digit == '\t' || digit == EOF)
            break;
      }
      
      list<short int>::iterator backIter = digits.end(); backIter--;
      *backIter = *backIter+1;
      while (*backIter == 10)
      { 
         
         *backIter = 0;
         if (backIter == digits.begin())
         {
            digits.push_front(1);
            break;
         }
         backIter--;
         *backIter = *backIter + 1;
      }
      
      findPalindrome1(digits);
      list<short int>::iterator iter = digits.begin();
      while (iter != digits.end())
      {
         cout << *iter;
         iter++;
      }
      cout << endl;

      numTests--;  
   }
   //system("PAUSE");
   return EXIT_SUCCESS;
}
