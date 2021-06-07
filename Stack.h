#ifndef COP4530_STACK_H
#define COP4530_STACK_H


#include <string>
#include <iostream>
#include <sstream>
#include <list>
#include <vector>
using namespace std;


namespace cop4530
{
  template <typename T> class Stack;// forward declaration

  template <typename T>
    class Stack
    {
    public:
      Stack();// zero argument constructor
      ~Stack();// destructor

      Stack(const Stack<T> &rhs);// copy constructor
      Stack(Stack<T> &&rhs);// move constructor

      Stack& operator=(const Stack<T> &rhs);// copy assignment operator=
      Stack& operator=(Stack<T> &&rhs);// move assignment operator=

      bool empty() const;// true if the Stack contains no elements, and false otherwise
      void clear();// delete all elements from the stack
      void push(const T& x);// adds  x  to the Stack.   copy version.
      void push(T && x);// adds x to the Stack. move version
      void pop();// removes and discards the first element in the Stack

      T& top();// mutator that returns a reference to the first element of the Stack
      const T& top() const;// accessor that returns the first element in the Stack

      size_t size() const;// returns the number of elements stored in the Stack

      // print elements of Stack to ostream os. ofc is the separator between elements in the stack
      // when they are printed out. Prints elements in the opposite order of the Stack (that is,
      // the oldest element should be printed first)
      void print(std::ostream& os, char ofc = ' ') const;

      template <typename U> friend std::ostream& operator<< (std::ostream& os, const Stack<T>& a);
      template <typename U> friend bool operator== (const Stack<U> &lhs, const Stack<U> &rhs);
      template <typename U> friend bool operator!= (const Stack<U> &lhs, const Stack<U> &rhs);
      template <typename U> friend bool operator<=(const Stack<U> &lhs, const Stack<U> &rhs);

    private:
      std::list<T> myS;

    };  // end of class Stack


  // overloading output operator
  // invokes the print() method to print the Stack<T> a in the specified ostream
  template <typename T>
    std::ostream& operator<< (std::ostream& os, const Stack<T>& a);

  // overloading comparison operators
  // returns true if the two compared Stacks have the same elements, in the same order.
  template <typename U>
    bool operator== (const Stack<U> &lhs, const Stack<U> &rhs);

  // opposite of operator==().
  template <typename U>
    bool operator!= (const Stack<U> &lhs, const Stack<U> &rhs);

  // returns true if every element in Stack lhs is smaller than or equal to
  // the corresponding element of Stack rhs
  template <typename U>
    bool operator<=(const Stack<U> &lhs, const Stack<U> &rhs);

  //
  // misc functions
  //
  int precedence(char ch);
  vector<string> stringToVector(const string& str, char delimiter =  ' ');
  string vectorToString(vector<string>& vect, char delimiter =  ' ');
  template <typename T> T stringToValue(const string& str);
  bool isOperator(char ch);
  bool isOperator(string& s);
  bool isDigit(char ch);
  bool isDigit(int c);
  bool isParens(string& s);
  bool isParens(char ch);
  bool isLetter(int c);
  bool isOperand(const string& str);
  bool foundFloat(const string& str);
  bool validateExpression(vector<string>& vect);
  bool validateExpression(const string& expr, char delimiter = ' ');
  bool validateInfixExpression(const string& expr, char delimiter, string& str_error);
  string evaluatePostfix(vector<string>& vect, char delimiter = ' ');

  typedef enum { NONE_EXPR, OPERAND_EXPR, OPERATOR_EXPR, PAREN_EXPR } expr_arithm;

  // include the implementation file here
  #include "Stack.hpp"


}  // end of namespace COP4530

#endif
