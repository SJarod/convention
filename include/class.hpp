#pragma once

class Class
{
private:
	bool	bMyPrivateBool;
	int		myPrivateInt;
	float	myPrivateFloat;

	void myPrivateMethod();

protected:
	bool	bMyProtectedBool;

	void myProtectedMethod();

public:
	bool	bMyPublicBool;
	int		myPublicInt;

	// if the constructor/destructor is default, no need to declare it
	Class() = default;
	~Class() = default;

	void myPublicMethod();
};