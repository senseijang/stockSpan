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
/*
 * Parameter keys:
 * - if we need read-write, pass pointer to stack
 * - if only read, pass stack
 */
void checkInput(int N, bool *invalidInput);
void generateStocks(std::stack<int> *stocks, int N);        // r-w
void getSpans(std::stack<int> *stocks, int spans[], int N); // r-w
void printStockSpans(std::stack<int> stocks);               // r
void printSpanArray(int spans[], int N);

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
  getSpans(&stocks, spans, N);
  std::cout << "stocks: ";
  printStockSpans(stocks);
  std::cout << "\n";
  printSpanArray(spans, N);

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

void generateStocks(std::stack<int> *stocks, int N)
{
  srand(time(0));

  for (int i = 0; i < N; i++)
  {
    stocks->push(rand() % 9 + 1);
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

void printSpanArray(int spans[], int N)
{
  std::cout << "spans: ";
  for (int i = 0; i < N; i++)
  {
    std::cout << spans[i] << " ";
  }
  std::cout << "\n";
}

void getSpans(std::stack<int> *stocks, int spans[], int N)
{
  if (stocks->empty())
    return;

  std::stack<int> usedStocks;
  std::stack<int> currentSpan;

  int currentVal = stocks->top();
  stocks->pop();

  for (int a = N - 1; a >= 0; a--)
  {
    if (!(stocks->empty()))
    {
      for (int i = N - 1; i >= 0; i--)
      {
        if (!(stocks->empty()) && (currentVal > stocks->top()))
        {
          currentSpan.push(stocks->top());
          stocks->pop();
        }
        else
        {
          // store span
          spans[a] = currentSpan.size() + 1;

          // restore stocks from current span
          if (!currentSpan.empty())
          {
            int M = currentSpan.size();
            for (int j = 0; j < M; j++)
            {
              stocks->push(currentSpan.top());
              currentSpan.pop();
            }
          }

          // add currentVal to usedStocks
          usedStocks.push(currentVal);

          // change currentVal to next top
          currentVal = stocks->top();
          stocks->pop();

          // If we are at the end
          if (stocks->empty())
          {
            usedStocks.push(currentVal);
            spans[0] = 1;
            break;
          }
        }
      }
    }
  }

  // once done, stocks should be empty, time to rebuild
  for (int k = 0; k < N; k++)
  {
    stocks->push(usedStocks.top());
    usedStocks.pop();
  }
}