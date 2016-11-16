/**
    122COM - Introduction to Algorithms
    task2.cpp
    Purpose: C++ Implementation of Linear and Binary Search Algorithms 

    Author : Rithin Chalumuri
    Version: 1.3 
    Date   : 15/07/16    
*/

#include <iostream>
#include <array>
#include <vector>
using namespace std;

/** 
  Function to search a value in sequence using linear search algorithm. 
  
  Parameters:
      sequence(vector); the sequence of different values 
      value(int); the target value being searched for in seqeunce 
  Returns:
      A boolean value. True if the value is found in sequence, otherwise false.
      
*/
bool linear_search(vector<int> sequence, int value)
{
  for( int i : sequence )
  {
    if( i == value )
    {
      return true;
    }
  }
  return false;
}


/** 
  Function to search a value in sequence using binary search algorithm. 
  
  Parameters:
      sequence(vector); the sequence of different values 
      value(int); the target value being searched for in seqeunce 
  Returns:
      A boolean value. True if the value is found in sequence, otherwise false.
     
*/
bool binary_search(vector<int> sequence, int value)
{
  int start,seqLen,end;
  start = 0;
  seqLen = sequence.size();
  end = seqLen - 1;
  
  while (start <= end)
  {
    int position;
    position = (start+end)/2;
    if(sequence[position] == value)
    {
      return true;
    }
    else if (sequence[position] < value)
    {
      start = position + 1;
    }
    else if (sequence[position] > value)
    {
      end = position - 1;
    }
  }
  
  return false;  
}


/** 
  Main Function to search a value '4884' using both binary and linear search functions
  in a sequence of multiples of 3 between 0 and 10000, including 0.
*/
int main() 
{
  vector<int> sequence;
  sequence.resize(10000);
  int count = 0;
    for( int &i : sequence )
    {
        i = count;
        count += 3;
    }
  
  bool binary_searchResult = binary_search(sequence,4884);
  bool linear_searchResult = linear_search(sequence,4884);
  cout<<"Binary search result: "<<binary_searchResult<<endl;
  cout<<"Linear search result: "<<linear_searchResult<<endl;
}

