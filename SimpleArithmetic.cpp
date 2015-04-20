#include <cstdlib>
#include <iostream>
#include <list>
#include <iomanip>
#include <cstdio>

using namespace std;
    

void outputSpace(list<short int> digit, int spaces)
{
   for (int i = 0; i < spaces; i++)
   {
      cout << ' ';
   }
   list<short int>::iterator iter = digit.begin();

   while (iter != digit.end())
   {
      cout << *iter;
      iter++;
   }   
}
void outputSpacePlus(list<short int> digit, int spaces)
{
   for (int i = 0; i < spaces; i++)
   {
      cout << ' ';
   }
   cout << '+';
   list<short int>::iterator iter = digit.begin();

   while (iter != digit.end())
   {
      cout << *iter;
      iter++;
   }   
}
void outputSpaceMinus(list<short int> digit, int spaces)
{
   for (int i = 0; i < spaces; i++)
   {
      cout << ' ';
   }
   cout << '-';
   list<short int>::iterator iter = digit.begin();

   while (iter != digit.end())
   {
      cout << *iter;
      iter++;
   }   
}

void outputSpaceTimes(list<short int> digit, int spaces)
{
   for (int i = 0; i < spaces; i++)
   {
      cout << ' ';
   }
   cout << '*';
   list<short int>::iterator iter = digit.begin();

   while (iter != digit.end())
   {
      cout << *iter;
      iter++;
   }
}   

void addTwo(list<short int> digit1, list<short int> digit2,
            list<short int> &result)
{
      list<short int>::iterator oneIter = digit1.end(); oneIter--;
      list<short int>::iterator twoIter = digit2.end(); twoIter--;
      
      unsigned int size = digit1.size();
      int firstLarger = 0;
      unsigned int remainder = digit2.size() - digit1.size();
   
      if (digit2.size() < size)
      {
         firstLarger = 1;
         remainder = digit1.size() - digit2.size();
         size = digit2.size();
      }
      int carry = 0;
      int number = 0;
      for (int i = 0; i < size; i++)
      {
         number = *oneIter + *twoIter + carry;
         if (number >= 10)
         {
            number -=10;
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
         if (firstLarger)
         {
            number = *oneIter + carry;
            if (number >= 10)
            {
               number -=10;
               carry = 1;
            }
            else
            {
               carry = 0;
            }

            result.push_front(number);
            oneIter--;
         }
         else
         {
            number = *twoIter + carry;
            if (number >= 10)
            {
               number -=10;
               carry = 1;
            }
            else
            {
               carry = 0;
            }
   
            result.push_front(number);
            twoIter--;
         }
         remainder--;
      }
      
      if (carry)
      {
         result.push_front(1);
      }

   
}
   

void formatAdd(list<short int> digit1, list<short int> digit2)
{
      list<short int>::iterator oneIter = digit1.end(); oneIter--;
      list<short int>::iterator twoIter = digit2.end(); twoIter--;
      list<short int> result;
      
      unsigned int size = digit1.size();
      int firstLarger = 0;
      unsigned int remainder = digit2.size() - digit1.size();
   
      if (digit2.size() < size)
      {
         firstLarger = 1;
         remainder = digit1.size() - digit2.size();
         size = digit2.size();
      }
      int carry = 0;
      int number = 0;
      for (int i = 0; i < size; i++)
      {
         number = *oneIter + *twoIter + carry;
         if (number >= 10)
         {
            number -=10;
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
         if (firstLarger)
         {
            number = *oneIter + carry;
            if (number >= 10)
            {
               number -=10;
               carry = 1;
            }
            else
            {
               carry = 0;
            }
            result.push_front(number);
            oneIter--;
         }
         else
         {
            number = *twoIter + carry;
            if (number >= 10)
            {
               number -=10;
               carry = 1;
            }
            else
            {
               carry = 0;
            }
            result.push_front(number);
            twoIter--;
         }
         remainder--;
      }
      
      if (carry)
      {
         result.push_front(1);
      }
      
      int maxSize = 0;
      if (digit1.size() > digit2.size()+1)
      {
         maxSize = digit1.size();
      }
      else
      {
         maxSize = digit2.size() + 1;
      }
      if (result.size() > maxSize)
      {
         maxSize = result.size();
      }
      
      int dashSize = digit2.size() + 1;
      if (result.size() > dashSize)
      {
         dashSize = result.size();
      }
      
      outputSpace(digit1, maxSize - digit1.size());
      cout << endl;      
      outputSpacePlus(digit2, maxSize - digit2.size()-1);
      cout << endl;
      for (int x = 0; x < (maxSize - dashSize); x++)
      {
         cout << ' ';
      }
      cout<<setfill('-')<<setw(dashSize)<<"-"<<endl;
      outputSpace(result,maxSize-result.size());
      cout << endl;
   }
   
   void formatSubtract(list<short int> digit1, list<short int> digit2)
   {
      list<short int>::iterator oneIter = digit1.end(); oneIter--;
      list<short int>::iterator twoIter = digit2.end(); twoIter--;
      list<short int> result;
      
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
      
      unsigned int maxSize = digit1.size();
      if (digit1.size() == digit2.size())
      {
         maxSize++;
      }
      
      int dashSize = digit2.size() + 1;
      if (result.size() > dashSize)
      {
         dashSize = result.size();
      }
      
      outputSpace(digit1, maxSize - digit1.size());
      cout << endl;      
      outputSpaceMinus(digit2, maxSize - digit2.size()-1);
      cout << endl;
      for (int x = 0; x < (maxSize - dashSize); x++)
      {
         cout << ' ';
      }
      cout<<setfill('-')<<setw(dashSize)<<"-"<<endl;
      outputSpace(result,maxSize-result.size());
      cout << endl;     
      
   }
   
   void formatMultiply(list<short int> digit1, list<short int> digit2)
   {
      list<list<short int> > steps;
      list<short int>::iterator oneIter = digit1.end(); oneIter--;
      list<short int>::iterator twoIter = digit2.end(); twoIter--;
      list<short int> result;
      
      for (int i = 0; i < digit2.size(); i++)
      {
         list<short int> currentStep;
         for (int x = 0; x < *twoIter; x++)
         {
            list<short int> xStep = currentStep;
            currentStep.clear();
            addTwo(digit1,xStep,currentStep);
         }
         
               // Pop leading zeros
         while (currentStep.front() == 0)
         {
            currentStep.pop_front();
         }
         if (currentStep.size() == 0)
         {
            currentStep.push_front(0);
         }
         
         steps.push_back(currentStep);
         twoIter--;
      }
      
      // Get final result
      list<list<short int> >::iterator stepIter = steps.begin();
      int counter = 0;
      int maxSize = digit1.size();
      
      if ((digit2.size() + 1) > digit1.size())
      {
         maxSize = digit2.size() + 1;
      }
      int upperMax = digit2.size() + 1;
          
      
      while (stepIter != steps.end())
      {
         list<short int> currentStep = *stepIter;
         for (int x = 0; x < counter; x++)
         {
            currentStep.push_back(0);
         }
         if (currentStep.size() > maxSize)
         {
            maxSize = currentStep.size();
         }
         list<short int> xStep = result;
         result.clear();
         addTwo(currentStep, xStep, result);
         stepIter++;
         counter++;
      }
      
      while (result.front() == 0)
      {
         result.pop_front();
      }
      if (result.size() == 0)
      {
         result.push_front(0);
      }
      
      if (result.size() > maxSize)
      {
         maxSize = result.size();
      }
      
      // Output everything
      outputSpace(digit1,maxSize - digit1.size());
      cout << endl;
      outputSpaceTimes(digit2,maxSize - digit2.size() - 1);
      cout << endl;

      int dashSize = 0;
      if (steps.size() > 1)
      {
         if (steps.front().size() > upperMax)
         {
            upperMax = steps.front().size();
         }
         for (int x = 0; x < (maxSize - upperMax); x++)
         {
            cout << ' ';
         }         
         
         cout<<setfill('-')<<setw(upperMax)<<"-"<<endl;
      
         // output steps
         stepIter = steps.begin();
         counter = 0;
         while (stepIter != steps.end())
         {
            outputSpace(*stepIter,maxSize - (*stepIter).size() - counter);
            for (int x = 0; x < counter; x++)
            {
               cout << ' ';
            }
            cout << endl;
            counter++;         
            stepIter++;
         }
         dashSize = result.size();
      }
      else
      {
         dashSize = digit2.size() + 1;
      }
      
      if (result.size() > dashSize)
      {
         dashSize = result.size();
      }    
      for (int x = 0; x < (maxSize - dashSize); x++)
      {
         cout << ' ';
      }  
      
      
      cout<<setfill('-')<<setw(dashSize)<<"-"<<endl;     
      outputSpace(result,maxSize-result.size());
      cout << endl;
             
      
   }    
        
   

enum operand {PLUS, MINUS, TIMES};
   
   
   

int main(int argc, char *argv[])
{
   unsigned int numTests, number;
   short int shortNum;
   char digit;
   operand oper;
   const char zero = '0';
  
   cin >> numTests;
   
   while (numTests > 0)
   {
      list<short int> digit1;
      list<short int> digit2;
      int first = 1;
      
      digit = getchar();
      while (digit == ' ' || digit == '\n')
      {
         digit = getchar();
      }
      while(digit != '\n' && digit != ' ')
      {
         shortNum = digit - zero;
         if (digit == '+')
         {
            oper = PLUS;
            first = 0;
         }
         else if (digit == '-')
         {
            oper = MINUS;
            first = 0;
         }
         else if (digit == '*')
         {
            oper = TIMES;
            first = 0;
         }
         else
         {
            if (first)
            {
                digit1.push_back(shortNum);
            }
            else
            {
                digit2.push_back(shortNum);
            }
         }
         digit = getchar();
         if (digit == ' ' || digit == '\n' || digit == '\t' || digit == EOF)
            break;
         
      }

      if (oper == PLUS)
      {
         formatAdd(digit1,digit2);
      }
      else if (oper == MINUS)
      {
         formatSubtract(digit1,digit2);
      }
      else if (oper == TIMES)
      {
         formatMultiply(digit1,digit2);
      }
      cout << endl;
      
   

      numTests--;
   }

    //system("PAUSE");
    return EXIT_SUCCESS;
}
