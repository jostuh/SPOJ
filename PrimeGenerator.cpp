#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

vector<unsigned int> primes;



int main(int argc, char *argv[])
{
    unsigned int primeNum = 2;
    
    // Build up the primes
    while (primeNum < 31623) // square root of 1,000,000,000
    {
       int isPrime = 1;
       vector<unsigned int>::iterator iter = primes.begin();
       while (iter != primes.end())
       {
          if (primeNum % *iter == 0)
          {
               isPrime = 0;
               break;
          }
          iter++;
       }
       if (isPrime)
       {
          primes.push_back(primeNum);
       }
       primeNum++;
    }
    
    unsigned int numTests, num1, num2;
    
    cin >> numTests;
    
    while (numTests > 0)
    {
       cin >> num1;
       cin >> num2;
       
       unsigned int current = num1;
       
       while (current <= num2)
       {    
         int isCurrentPrime = 1;
         
         // if current is less than 31623 check in list
         if (current < 31623)
         {
            isCurrentPrime = 0;
            vector<unsigned int>::iterator findIter = primes.begin();
            while (*findIter <= current)
            {
               if (*findIter == current)
               {
                  isCurrentPrime = 1;
                  break;
               }
               findIter++;
            }
         }     
         else {
            vector<unsigned int>::iterator iter = primes.begin();
            while (iter != primes.end())
            {
               if (current % *iter == 0)
              {
                 isCurrentPrime = 0;
                 break;   
              }
               iter++;
            }
         }
         
         if (isCurrentPrime)
         {
            cout << current << endl;
         }
         current++;
      }
       cout << endl;
       numTests--;
    }

    //system("PAUSE");
    return EXIT_SUCCESS;
}
