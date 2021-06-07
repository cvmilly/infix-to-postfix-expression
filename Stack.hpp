#ifndef COP4530_STACK_HPP
#define COP4530_STACK_HPP


//////////////////////////////////////////////////////////////////////
// zero argument constructor
//
template <typename T>
Stack<T>::Stack() : myS()
{
}


//////////////////////////////////////////////////////////////////////
// destructor
//
template <typename T>
Stack<T>::~Stack()
{
  if (myS.size() != 0)
    {
      myS.clear();
    }
}


//////////////////////////////////////////////////////////////////////
// copy constructor
//
template <typename T>
Stack<T>::Stack(const Stack<T> &rhs)
{
  myS.clear();
  myS = rhs.myS;
}


//////////////////////////////////////////////////////////////////////
// move constructor
//
template <typename T>
Stack<T>::Stack(Stack<T> &&rhs) : myS()
{
  myS = std::move(rhs.myS);
  rhs.clear();
}


//////////////////////////////////////////////////////////////////////
// copy assignment operator=
//
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T> &rhs)
{
  if (this != &rhs)
    {
      myS.clear();
      Stack<T> st = rhs;
      std::swap(*this, st);
    }

  return *this;
}


//////////////////////////////////////////////////////////////////////
// move assignment operator=
//
template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T> &&rhs)
{
  if (this != &rhs)
    {
      std::swap(myS, rhs.myS);
      rhs.clear();
    }

  return *this;
}


//////////////////////////////////////////////////////////////////////
// true if the Stack contains no elements, and false otherwise
//
template <typename T>
bool Stack<T>::empty() const
{
  return (myS.empty());
}


//////////////////////////////////////////////////////////////////////
// delete all elements from the stack
//
template <typename T>
void Stack<T>::clear()
{
  myS.clear();
}


//////////////////////////////////////////////////////////////////////
// adds x to the Stack. copy version.
//
template <typename T>
void Stack<T>::push(const T& x)
{
  if (myS.size() < myS.max_size())
    {
      myS.push_front(x);
    }
}


//////////////////////////////////////////////////////////////////////
// adds x to the Stack. move version
//
template <typename T>
void Stack<T>::push(T&& x)
{
  if (myS.size() < myS.max_size())
    {
      myS.push_front(x);
    }
}


//////////////////////////////////////////////////////////////////////
// removes and discards the first element in the Stack
//
template <typename T>
void Stack<T>::pop()
{
  if (myS.size() > 0)
    {
      myS.pop_front();
    }
}


//////////////////////////////////////////////////////////////////////
// mutator that returns a reference to the first element of the Stack
//
template <typename T>
T& Stack<T>::top()
{
  return myS.front();
}


//////////////////////////////////////////////////////////////////////
// accessor that returns the first element in the Stack
//
template <typename T>
const T& Stack<T>::top() const
{
  return myS.front();
}


//////////////////////////////////////////////////////////////////////
// returns the number of elements stored in the Stack
//
template <typename T>
size_t Stack<T>::size() const
{
  return myS.size();
}


//////////////////////////////////////////////////////////////////////
// print elements of Stack to ostream os. ofc is the separator between elements in the stack when they are printed out.
// prints elements in the opposite order of the Stack (that is, the oldest element should be printed first)
//
template <typename T>
void Stack<T>::print(std::ostream& os, char ofc) const
{
  for (auto it = myS.rbegin(); it != myS.rend(); ++it)
    {
      os << *it << ofc;
    }
  os << std::endl;
}


//////////////////////////////////////////////////////////////////////
// overloading output operator
// invokes the print() method to print the Stack<T> a in the specified ostream
//
template <typename T>
std::ostream& operator<< (std::ostream &os, const Stack<T> &st)
{
  st.print(os);

  return os;
}


//////////////////////////////////////////////////////////////////////
// overloading comparison operators
// returns true if the two compared Stacks have the same elements, in the same order.
//
template <typename T>
bool operator== (const Stack<T> &lhs, const Stack<T> &rhs)
{
  return (lhs.myS == rhs.myS);
}


//////////////////////////////////////////////////////////////////////
// opposite of operator==().
//
template <typename T>
bool operator!= (const Stack<T> &lhs, const Stack <T> &rhs)
{
  return !(lhs == rhs);
}


//////////////////////////////////////////////////////////////////////
// returns true if every element in Stack lhs is smaller than or equal
// to the corresponding element of Stack rhs
//
template <typename U>
bool operator<=(const Stack<U> &lhs, const Stack<U> &rhs)
{
  return (lhs.myS <= rhs.myS);
}


//////////////////////////////////////////////////////////////////////
//
// Miscellaneous Functions
//
//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
// operator precedence
//
int precedence(const string &str)
{
  int val = -1;

  if (str == "*" || str == "/")
    {
      val = 2;
    }
  else if (str == "+" || str == "-")
    {
      val = 1;
    }

  return val;
}


//////////////////////////////////////////////////////////////////////
// convert string to vector
//
vector<string> stringToVector(const string& str, char delimiter)
{
  vector<string> tokens;
  string tok;
  istringstream tokenStream(str);

  while (getline(tokenStream, tok, delimiter))
    {
      tokens.push_back(tok);
    }
  return tokens;
}


//////////////////////////////////////////////////////////////////////
// convert vector to string
//
string vectorToString(vector<string>& vect, char delimiter)
{
  string str;

  for (auto v : vect)
    {
      str = str + v + delimiter;
    }

  return str;

}


//////////////////////////////////////////////////////////////////////
// string to number value
//
template <typename T>
T stringToValue(const string& str)
{
  T val;
  stringstream ss;

  ss << str;
  ss >> val;

  if(ss.fail())
    {
      cout << "Error: unexpected data type in expression " << str << endl;
    }

  return val;
}


//////////////////////////////////////////////////////////////////////
// true if string is an arithmetic operator, false otherwise.
//
bool isOperator(string& s)
{
  bool b = false;
  int ch;

  if (s.length() == 1)
    {
      ch = s[0];
      b = (ch == '*' || ch == '/' || ch == '+' || ch == '-');
    }

  return b;
}


//////////////////////////////////////////////////////////////////////
// true if char is an arithmetic operator, false otherwise.
//
bool isOperator(char ch)
{
  return (ch == '*' || ch == '/' || ch == '+' || ch == '-');
}


//////////////////////////////////////////////////////////////////////
// true if string is an arithmetic operator, false otherwise.
//
bool isParens(string& s)
{
  bool b = false;
  int ch;

  if (s.length() == 1)
    {
      ch = s[0];
      b = (ch == '(' || ch == ')');
    }

  return b;
}


//////////////////////////////////////////////////////////////////////
// true if char is a parenthesis
//
bool isParens(char ch)
{
  return (ch == '(' || ch == ')');
}



//////////////////////////////////////////////////////////////////////
// true if digit, false otherwise.
//
bool isDigit(int c)
{
  return (c >= 48 && c <= 57) ? true : false;
}


//////////////////////////////////////////////////////////////////////
// true if digit, false otherwise.
//
bool isDigit(char ch)
{
  int c = ch;

  return (c >= 48 && c <= 57) ? true : false;
}


//////////////////////////////////////////////////////////////////////
// true if letter, false otherwise.
//
bool isLetter(int c)
{
  return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) ? true : false;
}


//////////////////////////////////////////////////////////////////////
// true if operand, false otherwise.
//
bool isOperand(const string& str)
{
  return (isDigit(str[0]) || isLetter(str[0]));
}


//////////////////////////////////////////////////////////////////////
// true if number, false otherwise.
//
bool isNumber(const string& str)
{
  int state = 0;
  int ch;

  for (size_t k = 0; k < str.length(); ++k)
    {
      ch = str[k];

      switch (state)
	{
	case 0:
	  state = isDigit(ch) ? 1 : 3;
	  break;
	case 1:
	  if (ch == 46)
	    {
	      state = 2;
	    }
	  else if (!isDigit(ch))
	    {
	      state = 3;
	    }
	  break;
	case 2:
	  if (!isDigit(ch))
	    {
	      state = 3;
	    }
	  break;
	case 3:
	  break;
	}
    }

  return (state != 3);
}


//////////////////////////////////////////////////////////////////////
// true if string is a float number, false otherwise.
//
bool foundFloat(const string& str)
{
  bool b = isNumber(str);

  if (b)
    {
      if (str.find('.') == string::npos)
	{
	  b = false;
	}
    }

  return b;
}


//////////////////////////////////////////////////////////////////////
// true if a float number is in the vector, false otherwise.
//
bool foundFloat(vector<string>& vect)
{
  string expr = vectorToString(vect);

  return (expr.find('.') != string::npos);
}


//////////////////////////////////////////////////////////////////////
// true if operator, number or parenthes. false otherwise.
//
bool validateExpression(vector<string>& vect)
{
  bool b = true;

  for (auto v : vect)
    {
      if (!isOperator(v) && !isNumber(v) && !isParens(v))
	{
	  b = false;
	  break;
	}
    }

  return b;
}


//////////////////////////////////////////////////////////////////////
// true if not variable names, false otherwise.
//
bool validateExpression(const string& expr, char delimiter)
{
  bool b = true;

  vector<string> vect = stringToVector(expr, delimiter);

  for (auto v : vect)
    {
      if (!isOperator(v) && !isOperand(v))
	{
	  b = false;
	  break;
	}
    }

  return b;
}


//////////////////////////////////////////////////////////////////////
//
//
bool validateInfixExpression(const string& expr, char delimiter, string& str_error)
{
  bool b = true;
  int num_parens = 0, num_operand = 0, num_operator = 0;

  vector<string> vect = stringToVector(expr, delimiter);

  for (auto v : vect)
    {
      if (isOperator(v))
	{
	  num_operator++;
	}
      else if (isOperand(v))
	{
	  num_operand++;
	}
      else if (isParens(v))
	{
	  num_parens++;
	}
      else if (isLetter(v[0]))
	{
	  b = false;
	  break;
	}
    }

  if (num_parens % 2 != 0)
    {
      str_error = "Error: Infix expression: " + expr + " has mismatched parens! ";
      b = false;
    }

  if (num_operator == 0 && vect.size() != 1)
    {
      str_error = "Error: Missing operators in the expression: ";
      b = false;
    }

  if (num_operand == 0  && vect.size() != 1)
    {
      str_error = "Error: Missing operands in the expression: ";
      b = false;
    }

  return b;
}


//////////////////////////////////////////////////////////////////////
// evaluate postfix expression
//
string evaluatePostfix(vector<string>& vect, char delimiter)
{
  bool          b;
  int           iVal1, iVal2, iVal3;
  float         fVal1, fVal2, fVal3;

  Stack<string> stk;
  char          oper;

  string str1, str2, str3, str4 = "ERROR";
  bool bfloat = false;

  b = validateExpression(vect);

  if (!b)
    {
      str4 = vectorToString(vect, delimiter);
    }
  else
    {
      for (auto v : vect)
	{
	  if (isOperand(v))
	    {
	      stk.push(v);
	    }
	  else if (isOperator(v))
	    {
	      if (stk.size() < 2)
		{
		  cout << "Error: Missing Operand " << endl;
		  break;
		}
	      else
		{
		  oper = v[0];
		  str1 = stk.top();
		  stk.pop();
		  str2 = stk.top();
		  stk.pop();

		  if (!bfloat)
		    {
		      bfloat = foundFloat(str1) || foundFloat(str2);
		    }

		  if (bfloat)
		    {
		      fVal1 = strtof(str1.c_str(), NULL);
		      fVal2 = strtof(str2.c_str(), NULL);
		    }
		  else
		    {
		      iVal1 = stoi(str1.c_str(), NULL);
		      iVal2 = stoi(str2.c_str(), NULL);
		    }

		  switch (oper)
		    {
		    case '*':
		      if (bfloat)
			{
			  fVal3 = fVal2 * fVal1;
			}
		      else
			{
			  iVal3 = iVal2 * iVal1;
			}
		      break;
		    case '/':
		      if (bfloat)
			{
			  fVal3 = fVal2 / fVal1;
			}
		      else
			{
			  iVal3 = iVal2 / iVal1;
			}
		      break;
		    case '+':
		      if (bfloat)
			{
			  fVal3 = fVal2 + fVal1;
			}
		      else
			{
			  iVal3 = iVal2 + iVal1;
			}
		      break;
		    case '-':
		      if (bfloat)
			{
			  fVal3 = fVal2 - fVal1;
			}
		      else
			{
			  iVal3 = iVal2 - iVal1;
			}
		      break;
		    }

		  str3 = (bfloat) ? to_string(fVal3) : to_string(iVal3);
		  stk.push(str3);
		}
	    }
	  else
	    {
	      cout << "Error: " << endl;
	      break;
	    }
	}

      if (stk.size() > 1)
	{
	  cout << "Error: Missing operator in the expression" << endl;
	}
      if (stk.size() == 1)
	{
	  str4 = stk.top();
	  stk.pop();
	}
      else
	{
	  str4 = "0";
	}
    }

  return str4;
}


//////////////////////////////////////////////////////////////////////
// convert infix expression to postfix
//
vector<string> infixToPostfix(const string &expr, char delimiter, bool &status)
{
  // To implement infix to postfix conversion with a stack,
  // one parses the expression as sequence of space-separated strings.
  // When an operand is read in the input, it is immediately output.
  // Operators (i.e., "-", "*") may have to be saved by placement in an operator stack.
  // We also stack left parentheses.

  // Start with an initially empty operator stack.
  bool             found_paren;
  string           str, str_error = "";
  expr_arithm      last_input = NONE_EXPR;
  vector<string>   vect_out;
  Stack<string>    stk;

  status = true;

  // one parses the expression as sequence of space-separated strings.
  vector<string> vect = stringToVector(expr, delimiter);

  status = validateInfixExpression(expr, delimiter, str_error);
  if (!status)
    {
      cout << str_error << endl;
      return vect;
    }
  else
    {
      if (vect.size() == 1)
	{
	  vect_out.push_back(expr);
	  return vect_out;
	}
    }

  for (auto v : vect )
    {
      // When an operand is read in the input, it is immediately output.
      if (isOperand(v))
	{
	  last_input = OPERAND_EXPR;
	  vect_out.push_back(v);
	}
      // 1. If input symbol is "(", push it into stack.
      else if ( v == "(" )
	{
	  last_input = PAREN_EXPR;
	  stk.push(v);
	}
      // 2. If input operator, repeatedly print the top of the stack
      // to the output and pop the stack until the stack is either
      // (i) empty
      // (ii) a "(" is at the top of the stack; or
      // (iii) a lower-precedence operator is at the top of the stack. Then push the input operator into the stack.
      else if (isOperator(v))
	{
	  // repeatedly print the top of the stack
	  // to the output and pop the stack until the stack is either
	  while (1)
	    {
	      if (!stk.empty())
		{
		  str = stk.top();
		}

	      // (i) empty
	      if (stk.empty())
		{
		  last_input = OPERATOR_EXPR;
		  stk.push(v);
		  break;
		}
	      // (ii) a "(" is at the top of the stack; or
	      if ( str == "(" )
		{
		  last_input = PAREN_EXPR;
		  stk.push(v);
		  break;
		}
	      // (iii) a lower-precedence operator is at the top of the stack. Then push the input operator into the stack.
	      else if (precedence(str) < precedence(v))
		{
		  last_input = OPERATOR_EXPR;
		  stk.push(v);
		  break;
		}
	      else
		{
		  last_input = OPERATOR_EXPR;
		  vect_out.push_back(str);
		  stk.pop();
		}
	    }
	}
      // 3.a If input operator is ")" and the last input processed was an operator, report an error.
      // 3.b Otherwise, repeatedly print the top of the stack to the output and
      //     pop the stack until a "(" is at the top of the stack.Then pop the stack discarding the parenthesis.
      // 3.c If the stack is emptied without a "(" being found, report error.
      else if ( v == ")" )
	{
	  // 3.a If input operator is ")" and the last input processed was an operator, report an error.
	  if (last_input == OPERATOR_EXPR)
	    {
	      cout << "ERROR: " << vectorToString(vect_out, delimiter) << endl;
	      status = false;
	      break;
	    }
	  else
	    {
	      // 3.b Otherwise, repeatedly print the top of the stack to the output and
	      // pop the stack until a "(" is at the top of the stack. Then pop the stack discarding the parenthesis.
	      while (1)
		{
		  str = stk.top();
		  if (str == "(")
		    {
		      found_paren = true;
		      stk.pop();
		      break;
		    }
		  else
		    {
		      vect_out.push_back(str);
		      stk.pop();
		    }
		}
	      // 3.c If the stack is emptied without a "(" being found, report error.
	      if (stk.empty() && !found_paren)
		{
		  cout << expr << " has mismatched parens! " << endl;
		  status = false;
		  break;
		}
	    }
	}
    }

  //4. If end of input is reached and the last input processed was an operator or "(", report an error.
  if (last_input == PAREN_EXPR || last_input == OPERATOR_EXPR )
    {
      cout << "Error: Missing Operands in the expression " << endl;
      status = false;
    }
  else
    {
      // Otherwise print the top of the stack to the output and pop the stack until the stack is empty.
      // If an "(" is found in the stack during this process, report error.
      while (!stk.empty())
	{
	  str = stk.top();
	  if (str == "(")
	    {
	      cout << expr << " has mismatched parens! " << endl;
	      status = false;
	      break;
	    }
	  else
	    {
	      vect_out.push_back(str);
	      stk.pop();
	    }
	}
    }

  return vect_out;
}


#endif
