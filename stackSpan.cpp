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
void getSpans(int spans[], int stocks[], int N);
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
  int spans[N] = {1};

  generateStocks(stocks, N);
  getSpans(spans, stocks, N);
  printArr("Stock", stocks, N);
  printArr("Spans", spans, N);

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
  srand(time(0));

  // generates a random value from 1-9 and assigns it
  for (int i = 0; i < N; i++)
  {
    stocks[i] = rand() % 9 + 1;
  }
}

/*
 * getSpans gets the span values for each stock in a given stock array
 *
 * @param spans is the array of spans to be set
 * @param stocks is the array of randomly generated stocks to be used in calculations
 * @param N is the number of data entires
 */
void getSpans(int spans[], int stocks[], int N)
{
  std::stack<int> cmp;
  bool keepGoing = true;

  cmp.push(0);
  spans[0] = 1;
  int i = 1;

  while (keepGoing)
  {
    if (cmp.empty())
    {
      spans[i] = i + 1;
      cmp.push(i);
      i++;
    }
    else if (stocks[i] > stocks[cmp.top()])
    {
      spans[i] = spans[i] + spans[cmp.top()];
      cmp.pop();
    }
    else if (stocks[i] <= stocks[cmp.top()])
    {
      spans[i] = spans[i] + 1;
      cmp.push(i);
      i++;
    }
    else
    {
      std::cout << "Error in span calculation!\n";
    }
    if (i == N)
    {
      keepGoing = false;
    }
  }
}

/*
 * printArr prints any given array
 *
 * @param name is the name of the array
 * @param arr is the array to be printed
 * @param N is the size of the array
 */
void printArr(std::string name, int arr[], int N)
{
  std::cout << name << " Array: [ ";
  for (int i = 0; i < N; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << "]\n";
}