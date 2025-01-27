/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include "iostream"

using namespace std;

int main(int argc, char* argv[])
{
  Node* head = new Node(1, nullptr);
  Node* evens = nullptr;
  Node* odds = nullptr;

  Node* current = head;

  for (int i = 2; i < 10; i++) {
    current->next = new Node(i, nullptr);
    current = current->next;
  }
  
  split(head, odds, evens);

  cout << evens->value << " " << odds->value;
}
