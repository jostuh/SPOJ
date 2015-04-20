#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
   int numTests = 0;
   string testString;
   
   cin >> numTests;
   while (numTests > 0)
   {
      vector<char> cStack;  
      cin >> testString;
      int strLen = testString.length();
      //int paren = 0;
      for (int i = 0; i < strLen; i++)
      {
         char c = testString[i];
         if (c == '(')
         {
            //paren++;
         }
         else if (c == ')')
         {
            //paren--;
            cout << cStack.back();
            cStack.pop_back();
         }
         else if (c == '/' || c == '^' || c == '*' || c == '+' || c == '-')
         {
            cStack.push_back(c);
         }
         else
         {
            cout << c;
         }        
      }
      cout << endl; 
    
      numTests--;  
   }
    //system("PAUSE");
    return EXIT_SUCCESS;
}
