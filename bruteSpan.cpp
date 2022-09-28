/*******************************************************
 * Filename: bruteSpan.cpp
 * Author: Andy Jang
 * Creation Date: 9/27/22
 * Purpose: To solve the stock span problem using a brute force approach (w/o stack)
 *******************************************************/

// Pre-processor directives
#include <iostream>
#include <time.h>
#include <cstdlib>

// Function prototypes
void checkInput(int N, bool *invalidInput);
void generateStocks(int stocks[], int N);
void printStocks(int stocks[], int N);
void getSpans(int stocks[], int spans[], int N);

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

  // stock span variable & generation
  int stocks[N] = {0};
  int spans[N] = {0};
  generateStocks(stocks, N);
  printStocks(stocks, N);

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

void generateStocks(int stocks[], int N)
{
  // seed for random variables
  srand(time(0));

  // generates a random value from 1-10 and assigns it
  for (int i = 0; i < N; i++)
  {
    stocks[i] = rand() % 10 + 1;
  }
}

void printStocks(int stocks[], int N)
{
  for (int i = 0; i < N; i++)
  {
    std::cout << stocks[i] << "\n";
  }
}

void getSpans(int stocks[], int spans[], int N)
{
}