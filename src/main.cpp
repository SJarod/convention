#include <iostream>

void doSomething()
{
	// do something
}

// pass variables as reference if the size is bigger than a float
void inputArgument(const int i_input)
{
}

// pass unset variable as output value
void outputArgument(int& o_output)
{
}

void intputAndOutputArgument(int& io_output)
{
}

int main()
{
	// if/else model
	if (true)
		doSomething();
	else
		doSomething();

	if (true)
	{
		doSomething();
		doSomething();
	}
	else
	{
		doSomething();
	}

	// for model
	for (int i = 0; i < 10; ++i)
	{
		// do something
	}

	return EXIT_SUCCESS;
}