#include <vector>
#include <iostream>
#include <unordered_map>


using namespace std; 

bool exist(vector<int> array, 
         int         target) 
{
    // write your solution here
    unordered_map<int, int> table; 
    for (int j = 1; j < array.size(); ++j)
    {
      for (int i = 0; i < j; ++i)
      {
        int candidate = target - array[i] - array[j]; 
        if (table.count(candidate) != 0)
        {
          if (i > table[candidate])
          {
              cout << "Liang " << endl; 
            return true; 
          
          }
        } 
        if (table.count(array[i]+array[j]) == 0)
        {
            table[array[i]+array[j]] = j; 
        }
      }
    }
    return false;
}

int main()
{
    vector<int> input{2,1,1,1,0}; 
    exist(input, 3); 
}