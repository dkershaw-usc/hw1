/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Prototype for helper function goes here if needed */
void splitHelp(Node*& in, Node*& out);

void split(Node*& in, Node*& odds, Node*& evens)
{
    // base case
    if(in == nullptr) return;

    // evaluate odd or even
    if(in->value % 2 == 0)
    { 
      if(evens == nullptr)
      {
        // `evens` gets current idx
        evens = in;
        // `in` moves forward 1
        in = in->next;
        // detach `in->next` from current `evens` tail
        evens->next = nullptr;
      }
      else
      {
        splitHelp(in, evens);
      }

      split(in, evens->next, odds);
    }
    else
    {
      if(odds == nullptr)
      {
        odds = in;
        in = in->next;
        evens->next = nullptr;
      }
      else
      {
        splitHelp(in, odds);
      }

      split(in, evens, odds->next);
    }
}

/* If you need a helper function, write it here */
void splitHelp(Node*& in, Node*& out)
{
  out->next = in;
  in = in->next;
  out->next->next = nullptr;
}