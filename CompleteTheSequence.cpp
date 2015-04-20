#include <cstdlib>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef unsigned int uint;
typedef vector< vector<double> > matrix;

void outputMatrix(matrix &M)
{
   for (int row = 0; row < M.size(); row++)
   {
      for (int col = 0; col < M.size() + 1; col++)
      {
         cout << M[row][col] << " ";
      }
      cout << endl;
   }
   cout << endl;
}

double power(double a, int n)
{
   if (n == 0)
   {
      return 1;
   }
   
   double x = power(a,(n/2));
   
   if (n % 2 == 0)
   {
      return (x*x);
   }
   else
   {
      return (a*x*x);
   }
}

int sameDiff(vector<int> diffs)
{
   int prev = diffs[0];
   for (int i = 1; i < diffs.size(); i++)
   {
      if (diffs[i] != prev)
      {
         return 0;
      }
      prev = diffs[i];
   }
   
   return 1;
}

int findDegree(vector<int> &sequence, int num_to_find)
{
   if (sameDiff(sequence))
   {
      for (int i = 0; i < num_to_find; i++)
      {
        if (sequence.size())
        {
           sequence.push_back(sequence[0]);
        }
        else
        {
           sequence.push_back(0);
        }
      }
      return 0;
   }
   
   vector<int> diffs;
   
   vector<int>::iterator iter = sequence.begin();
   int prev = *iter; iter++;
   while (iter != sequence.end())
   {
      int diff = *iter - prev;
      diffs.push_back(diff);
      prev = *iter;
      iter++;
   }
     
   // return 1 + findDegree(diffs);   
   findDegree(diffs, num_to_find);
   for (int i = 0; i < num_to_find; i++)
   {
      int sequence_index = sequence.size() - 1;
      int diff_index = diffs.size() - num_to_find + i;
      sequence.push_back(sequence[sequence_index] + diffs[diff_index]);
   }
   return 1;
}

vector<double> gaussElim(matrix &M)
{
   for(uint row = 0; row < M.size(); row++)
   {
      uint maxRow = row;
      double maxVal = M[row][maxRow];
      
      // Get max column and value
      for (uint curRow = row + 1; curRow < M.size(); curRow++)
      {
         if (maxVal < M[curRow][row])
         {
            maxVal = M[curRow][row];
            maxRow = curRow;
         }
      }
      
      // Swap max row with current row
      for (uint curCol = row; curCol < M.size() + 1; curCol++)
      {
         double tmp = M[row][curCol];
         M[row][curCol] = M[maxRow][curCol];
         M[maxRow][curCol] = tmp;
      }
      
      // Make all rows below current row zero
      for (uint curRow = row + 1; curRow < M.size(); curRow++)
      {
         double c = -(M[curRow][row]/M[row][row]);
         for (uint curCol = row; curCol < M.size() + 1; curCol++)
         {
            M[curRow][curCol] = c * M[row][curCol] + M[curRow][curCol];            
         }
      }
   }
   
   // Solve it back up
   for (int row = M.size() - 1; row >= 0; row--)
   {    
      
      M[row][M.size()] = M[row][M.size()] / M[row][row];
      M[row][row] = 1;      
         
      for (int curRow = row - 1; curRow >= 0; curRow--)
      {
         double c = -((M[curRow][row])/(M[row][row]));
         for (int curCol = row; curCol < M.size() + 1; curCol++)
         {
            M[curRow][curCol] = c * M[row][curCol] + M[curRow][curCol];
         }
      }
   }
   
   outputMatrix(M);
    
   vector<double> result;
   for (int i = 0; i < M.size(); i++)
   {
      result.push_back(M[i][M.size()]);
   }
   
   return result;    
}

int main(int argc, char *argv[])
{
   
   int numTests;
   cin >> numTests;
   int firstline = 1;
   
   for (int test = 0; test < numTests; test++)
   {
      if (!firstline)
      {        
         cout << endl;
      }
      firstline = 0;
      vector<int> sequence;
      
      int numSeq;
      cin >> numSeq;
      
      int numToComplete;
      cin >> numToComplete;
      
      for (int num = 0; num < numSeq; num++)
      {
         int curNum;
         cin >> curNum;
         sequence.push_back(curNum);
      }
      
      int degree = findDegree(sequence,numToComplete);
      
      int first = 1;
      for (int x = 0; x < numToComplete; x++)
      {
         if (!first)
         {
            cout << " ";
         }
   
         first = 0;
         cout << sequence[sequence.size() - numToComplete + x];      
      }
   }

  // system("PAUSE");
   return EXIT_SUCCESS;
}
