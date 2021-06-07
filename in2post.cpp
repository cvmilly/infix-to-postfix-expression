#include <iostream>
#include <cstdlib>
#include "Stack.h"

using namespace std;
using namespace cop4530;

int main()
{
  string input, result, result1, result2;
  bool status = true;

  cout << "Enter infix expression (\"exit\" to quit):" << endl;
  while (getline(cin, input))
    {
      if (input == "exit")
	{
	  break;
	}
      else
	{
	  vector<string> v = infixToPostfix(input, ' ', status);
	  if (status)
	    {
	      result1 = vectorToString(v);
	      result2 = evaluatePostfix(v);
	      cout << "Postfix expression: " << result1 << endl;
	      cout << "Postfix evaluation: " << result1 << " = " << result2 << endl;
	    }

	  cout << "Enter infix expression (\"exit\" to quit):" << endl;
	}
    }

  return(EXIT_SUCCESS);
}
