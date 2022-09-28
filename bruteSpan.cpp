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
void printStockSpans(int stocks[], int spans[], int N);
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
  std::cout << "\n";

  // stock span variable & generation
  int stocks[N] = {0};
  int spans[N] = {0};
  generateStocks(stocks, N);
  getSpans(stocks, spans, N);

  // display spans
  printStockSpans(stocks, spans, N);

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
 * printStockSpans prints the stocks and their spans.
 *
 * @param stocks is the array of randomly generated stocks
 * @param spans is the array of spans given by getSpans()
 * @param N is the number of data entries
 */
void printStockSpans(int stocks[], int spans[], int N)
{
  // Will leave if we want to do a fancy print again.
  /*
  int day = 0;
  std::cout << "        Price Span\n";
  for (int i = 0; i < N; i++)
  {
    day = i + 1;
    std::cout << "Day #" << day << ": " << stocks[i] << "     " << spans[i] << "\n";
  }
  std::cout << "\n";
  */

  // print arrays
  std::cout << "Stock Array: [ ";
  for (int a = 0; a < N; a++)
  {
    std::cout << stocks[a] << " ";
  }
  std::cout << "]\n";

  std::cout << "Spans Array: [ ";
  for (int b = 0; b < N; b++)
  {
    std::cout << spans[b] << " ";
  }
  std::cout << "]\n";
}

/*
 * getSpans calculates the spans of each stock value in a given array
 *
 * @param stocks is the array of randomly generated stocks
 * @param spans is the array of spans to be set
 * @param N is the number of data entries
 */
void getSpans(int stocks[], int spans[], int N)
{
  int currentStock = -1;
  int currentSpan = 1;
  // Start at the back of the array
  for (int i = N - 1; i >= 0; i--)
  {
    currentStock = stocks[i];
    // Iterate through the array, check if previous day is lower, if so add 1 to counter
    if (i != 0)
    {
      for (int j = i - 1; j >= -1; j--)
      {
        // ran out of comparisons, save span, go next
        if (j == -1)
        {
          spans[i] = currentSpan;
          currentSpan = 1;
          break;
        }
        // if currentStock is higher, then add to span
        if (currentStock > stocks[j])
        {
          currentSpan++;
        }
        else
        {
          // else span is finished, save span, and reset
          spans[i] = currentSpan;
          currentSpan = 1;
          break;
        }
      }
    }
    else
    {
      spans[0] = currentSpan;
    }
  }
}