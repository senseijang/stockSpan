# Stock Span Problem
Andy Jang
CSCI 362: Data Structures and Algorithms

## Goal
The purpose of this program is to solve the stock span problem.
A stock span is the number of consectuve days before the current day where the price of the stock was less than or equal to the current price.
This program simulates that by generating random stock values (between 1 - 9) and calculates every associated span.

## How to Run
#### Brute Force
The brute force method is an approach without considering the use of a stack and instead uses a counter and a lot of comparisons.
The following command should run the brute force approach:
`make brute`

#### Stack
The stack method is an approach using a stack to track the indices of each stocks and calculate the spans using said stack.
The following command should run the stack approach:
`make stack`