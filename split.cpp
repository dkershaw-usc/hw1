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
Node* initNewNodeWith(Node*& in);

void split(Node*& in, Node*& odds, Node*& evens)
{
    // base case
    if(in == nullptr) return;

    // evaluate odd or even
    if(in->value % 2 == 0)
    { 
      if(evens == nullptr)
      {
        evens = initNewNodeWith(in);
      }
      else
      {
        evens->next = in;
      }
    }
    else
    {
      if(odds == nullptr)
      {
        odds = initNewNodeWith(in);
      }
      else
      {
        odds->next = in;
      }
    }

    // recursive step
    in = in->next;
    split(in, odds, evens);
}

/* If you need a helper function, write it here */
Node* initNewNodeWith(Node*& in)
{
  Node* out = new Node(0,nullptr);
  out->value = in->value;
  return out;
}