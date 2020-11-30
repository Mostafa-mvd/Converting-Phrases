#include <stdio.h>
#include <iostream>
#include <conio.h>


using namespace std;


//for example:
	// abc*d/+


bool check_infix = true;
const int length = 7;
int top = -1, counter_a = 0, counter_b = length - 1;
char chr_stack[length], input_phrase[length];
string str_stack[length], output_phrase[length], choosenInput, choosenOutput;


void chooseInputType()
{
	cout << "choose input type with number :" << endl << "1 - infix" << endl << "2 - prefix" << endl << "3 - postfix" << endl;
	cin >> choosenInput;
}

void chooseOutputType()
{
	cout << "choose output type with number :" << endl << "1 - infix" << endl << "2 - prefix" << endl << "3 - postfix" << endl;
	cin >> choosenOutput;
}

void getInput()
{
	cout << "pls enter your input: " << endl;

	for (int i = 0; i < length; i++)
		cin >> input_phrase[i];
}

bool compareValue(char stack_op, char input_op)
{
	int x = 0, y = 0;

	if ((input_op == '+') || (input_op == '-'))
		x = 1;
	else if ((input_op == '*') || (input_op == '/'))
		x = 2;
	else if (input_op == '^')
		x = 3;

	if ((stack_op == '+') || (stack_op == '-'))
		y = 1;
	else if ((stack_op == '*') || (stack_op == '/'))
		y = 2;
	else if (stack_op == '^')
		y = 3;

	if (x > y)
		return true;

	return false;
}

bool isEmpty()
{
	if (top == -1)
		return true;
	return false;
}


bool pushCharStack(char i)
{
	if (top == length - 1)
		return false;
	top++;
	chr_stack[top] = i;
	return true;
}

char popCharStack()
{
	if (top == -1)
		return '!';

	char x = chr_stack[top];
	top--;
	return x;
}

bool pushStrStack(string i)
{
	if (top == length - 1)
		return false;
	top++;
	str_stack[top] = i;
	return true;
}

string popStrStack()
{
	if (top == -1)
		return "!";

	string x = str_stack[top];
	top--;
	return x;
}


void convertInfixToPostfix()
{
	for (int i = 0; i < length; i++)
	{
		char x = input_phrase[i];

		if (x == '(')
			pushCharStack(x);

		else if (x == ')')
		{
			while (true)
			{
				char y = popCharStack();
				if (y != '(')
				{
					output_phrase[counter_a] = y;
					counter_a++;
				}
				else
					break;
			}
		}

		else if ((x != '+') && (x != '-') && (x != '*') && (x != '^') && (x != '/'))
		{
			output_phrase[counter_a] = x;
			counter_a += 1;
		}

		else
		{
			while (true)
			{
				if (isEmpty())
				{
					pushCharStack(x);
					break;
				}

				else
				{
					if (compareValue(chr_stack[top], x))
					{
						pushCharStack(x);
						break;
					}

					else
					{
						char y = popCharStack();
						output_phrase[counter_a] = y;
						counter_a++;
					}
				}
			}
		}
	}

	while (!isEmpty())
	{
		char y = popCharStack();
		output_phrase[counter_a] = y;
		counter_a++;
	}
}

void convertInfixToPrefix()
{
	for (int i = length - 1; i >= 0; i--)
	{
		char x = input_phrase[i];

		if (x == ')')
			pushCharStack(x);

		else if (x == '(')
		{
			while (true)
			{
				char y = popCharStack();
				if (y != ')')
				{
					output_phrase[counter_b] = y;
					counter_b--;
				}
				else
					break;
			}
		}

		else if ((x != '+') && (x != '-') && (x != '*') && (x != '^') && (x != '/'))
		{
			output_phrase[counter_b] = x;
			counter_b -= 1;
		}

		else
		{
			while (true)
			{
				if (isEmpty())
				{
					pushCharStack(x);
					break;
				}

				else
				{
					if (compareValue(chr_stack[top], x))
					{
						pushCharStack(x);
						break;
					}

					else
					{
						char y = popCharStack();
						output_phrase[counter_b] = y;
						counter_b--;
					}
				}
			}
		}

	}

	while (!isEmpty())
	{
		char y = popCharStack();
		output_phrase[counter_b] = y;
		counter_b--;
	}
}


void convertPrefixToInfix()
{
	for (int i = length - 1; i >= 0; i--)
	{
		char x = input_phrase[i];
		string y;
		y += x;

		if ((y != "+") && (y != "-") && (y != "*") && (y != "^") && (y != "/"))
		{
			pushStrStack(y);
		}

		else
		{
			string z = popStrStack();
			string w = popStrStack();
			string k = w + y + z;
			pushStrStack(k);
		}

	}
}

void convertPrefixToPostfix()
{
	check_infix = false;

	for (int i = length - 1; i >= 0; i--)
	{
		char x = input_phrase[i];
		string y;
		y += x;

		if ((y != "+") && (y != "-") && (y != "*") && (y != "^") && (y != "/"))
		{
			pushStrStack(y);
		}

		else
		{
			string z = popStrStack();
			string w = popStrStack();
			string k = z + w + y;
			pushStrStack(k);
		}

	}
}

void convertPostfixToInfix()
{
	check_infix = false;

	for (int i = 0; i < length; i++)
	{
		char x = input_phrase[i];
		string y;
		y += x;

		if ((y != "+") && (y != "-") && (y != "*") && (y != "^") && (y != "/"))
		{
			pushStrStack(y);
		}

		else
		{
			string z = popStrStack();
			string w = popStrStack();
			string k = w + y + z;
			pushStrStack(k);
		}

	}
}

void convertPostfixToPerfix()
{
	check_infix = false;

	for (int i = 0; i < length; i++)
	{
		char x = input_phrase[i];
		string y;
		y += x;
		if ((y != "+") && (y != "-") && (y != "*") && (y != "^") && (y != "/"))
		{
			pushStrStack(y);
		}

		else
		{
			string z = popStrStack();
			string w = popStrStack();
			string k = y + w + z;
			pushStrStack(k);
		}

	}
}




void printOutput()
{
	cout << "Input is: ";

	for (int i = 0; i < length; i++)
		cout << input_phrase[i];

	cout << endl << endl << "Output is: ";

	if (counter_a != 0) //infixToPostfix
	{
		for (int i = 0; i < counter_a; i++)
			cout << output_phrase[i];
	}

	else if ((counter_a == 0) && (counter_b != length - 1)) //infixToPrefix
	{
		for (int i = 0; i < length; i++)
			cout << output_phrase[i];
	}

	else
	{
		string infix = str_stack[0];
		int infix_size = str_stack[0].length();

		if (check_infix == true) //prefixToinfix
			for (int i = infix_size; i >= 0; i--)
			{
				cout << infix[i];
			}
		else //prefixToPostfix or postfixToPrefix or postfixToInfix
		{
			for (int i = 0; i < infix_size; i++)
			{
				cout << infix[i];
			}
		}
	}
	cout << endl << endl;
}

bool digitCheck(char input_char)
{
	if ((input_char >= 65 && input_char <= 90) || (input_char >= 97 && input_char <= 122))
		return false;

	else if (input_char >= 48 && input_char <= 57)
		return true;

	else
		return false;
}

void convertPhrase()
{
	chooseInputType();
	chooseOutputType();

	int input_size = choosenInput.length();
	int output_size = choosenOutput.length();

	if ((input_size == 1) && (output_size == 1))
	{
		if (digitCheck(choosenInput[0]) && digitCheck(choosenOutput[0]))
		{
			if ((choosenInput == "1") && (choosenOutput == "3"))
			{
				convertInfixToPostfix();
			}

			else if ((choosenInput == "1") && (choosenOutput == "2"))
			{
				convertInfixToPrefix();
			}

			else if ((choosenInput == "2") && (choosenOutput == "1"))
			{
				convertPrefixToInfix();
			}

			else if ((choosenInput == "3") && (choosenOutput == "1"))
			{
				convertPostfixToInfix();
			}

			else if ((choosenInput == "3") && (choosenOutput == "2"))
			{
				convertPostfixToPerfix();
			}

			else if ((choosenInput == "2") && (choosenOutput == "3"))
			{
				convertPrefixToPostfix();
			}


			else if (choosenInput == choosenOutput)
			{
				cout << "your input and output shouldn't be equal" << endl << endl;
				convertPhrase();
			}

			else
			{
				cout << "1 <= your input and output <= 3" << endl << endl;
				convertPhrase();
			}
		}

		else
		{
			cout << "your input and output must be digit" << endl << endl;
			convertPhrase();
		}
	}

	else
	{
		cout << "number of your input and output must be equal with one digit" << endl << endl;;
		convertPhrase();
	}
}

bool startAgain()
{
	char answer;
	while (true)
	{
		cout << "Do you want start again (Y/N) ? ";
		cin >> answer;

		if (toupper(answer) == 'Y')
		{
			top = -1, counter_a = 0, counter_b = length - 1, check_infix = true;
			system("cls");
			return true;
		}

		else if (toupper(answer) == 'N')
			return false;

		else
			system("cls");
		cout << "choose again" << endl << endl;
	}
}

int main()
{
	while (true)
	{
		getInput();
		convertPhrase();
		printOutput();

		if (!startAgain())
			break;
	}

	return 0;
}
