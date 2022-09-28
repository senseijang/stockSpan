/*******************************************************
 * Filename: stackSpan.cpp
 * Author: Andy Jang
 * Creation Date: 9/27/22
 * Purpose: To solve the stock span problem using a stack.
 *******************************************************/

// Pre-processor directives
#include <iostream>
#include <stack>
#include <cstdlib>
#include <time.h>

// Function prototypes
void checkInput(int N, bool *invalidInput);
void generateStocks();
void printStockSpans();
void getSpans();

int main()
{
  // user input vars
  bool invalidInput = true;
  int N = -1;

  // Start with getting N
  while (invalidInput)
  {
    std::cout << "N: ";
    std::cin >> N;
    std::cout << "\n";
    checkInput(N, &invalidInput);
  }
  std::cout << "\n";
}

/*
 * checkInput checks if the user enters a N value that fits the program
 *
 * @param N is the number of data entries to be changed
 * @param *invalidInput is the pointer to the sentry variable for the user input
 */
void checkInput(int N, bool *invalidInput)
{
  if (N < 0)
  {
    std::cout << "Stock span is not possible with " << N << ". Please enter a different number.\n";
  }
  else
  {
    *invalidInput = false;
    std::cout << "N-value: " << N << "\n";
  }
}