/*******************************************************
 * Filename: bruteSpan.cpp
 * Author: Andy Jang
 * Creation Date: 9/27/22
 * Purpose: To solve the stock span problem using a brute force approach (w/o stack)
 *******************************************************/

// Pre-processor directives
#include <iostream>

// Function prototypes
void checkInput(int N, bool *invalidInput);

int main()
{
  // Start with getting N
  bool invalidInput = true;
  int N = -1;

  while (invalidInput)
  {
    std::cout << "N: ";
    std::cin >> N;
    std::cout << "\n";
    checkInput(N, &invalidInput);
  }

  return 0;
}

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