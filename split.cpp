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
void append(Node*& in, Node*& out);

void split(Node*& in, Node*& odds, Node*& evens)
{
    // base case
    if(in == nullptr) return;

    // evaluate odd or even
    if(in->value % 2 == 1)
    {
      //odds = new Node(0,nullptr);
      odds = in;
      in = in->next;
      odds->next = nullptr;
      split(in, odds->next, evens);
    }
    else
    {
      //evens = new Node(0,nullptr);
      evens = in;
      in = in->next;
      evens->next = nullptr;
      split(in, odds, evens->next);
    }

}

/* If you need a helper function, write it here */
// appends node b to nodelist a.
void append(Node*& a, Node*& b)
{
  a->next = b;
}