#include <cstdlib>
#include <iostream>
#include <map>

using namespace std;

typedef map<int,int> nmap;
typedef nmap::iterator niter;

int main(int argc, char *argv[])
{
   int input;
   cin >> input;
   nmap M;
   M[0] = 0;
   
   while (input != 0)
   {
     niter iter = M.find(input);
     if (iter == M.end())
     {
       for (int i = M.size(); i <= input; i++)
       {
          int number = i * i;
          number += M[i-1];
          M[i] = number;
       }
     }
     cout << M[input] << endl;
    
     cin >> input;  
   }
   
   //system("PAUSE");
   return EXIT_SUCCESS;
}
