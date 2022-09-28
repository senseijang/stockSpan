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
void generateStocks(int stocks[], int N);
void getSpans(int spans[], int stocks[], int N, int topIndex[]);
void printArr(std::string name, int arr[], int N);

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
  int stocks[N] = {0};
  int spans[N] = {0};
  int topIndex[N] = {0};

  generateStocks(stocks, N);
  getSpans(spans, stocks, N, topIndex);
  printArr("Stock", stocks, N);
  printArr("Spans", spans, N);
  printArr("Index", topIndex, N);

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

/*
 * generateStocks generates random stock values using a random generator
 *
 * @param stocks is the array of stocks to be set
 * @param N is the number of data entries
 */
void generateStocks(int stocks[], int N)
{
  // seed for random variables
  srand(13);

  // generates a random value from 1-9 and assigns it
  for (int i = 0; i < N; i++)
  {
    stocks[i] = rand() % 9 + 1;
  }
}

void getSpans(int spans[], int stocks[], int N, int topIndex[])
{
  std::stack<int> cmp;
  int atopIndex = 0;
  bool keepGoing = true;

  cmp.push(stocks[0]);
  spans[0] = 1;
  int i = 1;

  while (keepGoing)
  {
    // new number is biggest on the stack
    if (cmp.empty())
    {
      cmp.push(stocks[i]);
      spans[i] = i + 1;
      atopIndex = i;
      topIndex[i] = atopIndex;
      i++;
    }
    // new number is less than the top
    else if (stocks[i] <= cmp.top())
    {
      cmp.push(stocks[i]);
      spans[i] = i - atopIndex;
      i++;
    }
    else
    {
      cmp.pop();
    }
    if (i == N)
    {
      keepGoing = false;
    }
  }
}

void printArr(std::string name, int arr[], int N)
{
  std::cout << name << ": [ ";
  for (int i = 0; i < N; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << "]\n";
}