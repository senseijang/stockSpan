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
void generateStocks(std::stack<int> *stocks, int N);
void printStockSpans(std::stack<int> stocks);
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

  // stock span variables and generation
  std::stack<int> stocks;
  int spans[N] = {0};
  generateStocks(&stocks, N);
  printStockSpans(stocks);

  return 0;
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

void generateStocks(std::stack<int> *stock, int N)
{
  srand(time(0));

  for (int i = 0; i < N; i++)
  {
    stock->push(rand() % 9 + 1);
  }
}

void printStockSpans(std::stack<int> stocks)
{
  if (stocks.empty())
    return;
  int x = stocks.top();
  stocks.pop();

  printStockSpans(stocks);

  std::cout << x << " ";
  stocks.push(x);
}