#include <iostream>

void do_something()
{
	// do something
}

// pass variables as reference if the size is bigger than a float
void input_argument(const int i_input)
{
}

// pass unset variable as output value
void output_argument(int& o_output)
{
}

void intput_and_output_argument(int& io_output)
{
}

int main()
{
	// if/else model
	if (true)
		do_something();
	else
		do_something();

	if (true)
	{
		do_something();
		do_something();
	}
	else
	{
		do_something();
	}

	// for model
	for (int i = 0; i < 10; ++i)
	{
		// do something
	}

	return EXIT_SUCCESS;
}
