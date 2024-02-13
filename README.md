# **Convention**

This repository is meant to describe a coding convention.

## Summary
- [Organizing the files](#organizing-the-files)
    - [Naming files](#naming-files)
    - [CMake](#cmake)
    - [Adding a README.md file](#adding-a-readmemd-file)
- [C++](#c)
    - [Writing](#writing)
    - [General coding](#general-coding)
- [Versionning with Git](#versionning-with-git)
    - [Branches](#branches)
    - [Commits](#commits)
    - [Tags](#tags)
    - [.gitignore](#gitignore)

# Organizing the files

## Naming files
The file names must only contain lowercase letters, underscores and no spaces. Some files can have inline definitions, they must be written in a .inl file. The header files must have the .hpp extension (for C++). If the file name contains at least 2 words, they must be seperated by an underscore character.
```
engine.hpp
graphics_pipeline.hpp
graphics_pipeline.inl
graphics_pipeline.cpp
```
Files containing the definition of an interface implementation may be named following their specialization (seperated with an under score).
```
graphics_pipeline_vk.hpp
graphics_pipeline_gl.hpp
```
Header files can either be defined with the #pragma once operation or the include guards.
```c++
#pragma once
```
```c++
#ifndef __GRAPHICS_PIPELINE_HPP__
#define __GRAPHICS_PIPELINE_HPP__

#endif
```

## CMake
The project's CMakeLists must respect modern CMake. The variables must be named using snake case and upper case letters.
```CMake
set(MY_VARIABLE)
```
Some CMakeLists template are provided in this repository.

## Adding a README.md file
Every project must contain a README.md file to describe its objectives.
```md
# **Project**

Description of the project

## Summary
- [Getting started](#getting-started)
    - [Installation](#installation)
    - [Controls](#controls)
- [Features](#features)
- [Problems and bugs](#problems-and-bugs)
- [Updates](#updates)
- [Third-parties](#third-parties)
- [References](#references)
- [Credit](#credit)

# Getting started

## Installation
How to install the project

## Controls
How to use the software

# Features
What is implemented

# Problems and bugs
Known bugs

# Updates
Next releases

# Third-parties
External libraries used

# References
Used websites and links

# Credit
Collaborators or thanks
```

# C++

## Writing
Naming cases
- PascalCase
- camelCase
- snake_case
- lowercase
- UPPERCASE

Function pairs
- Creation
    - Create/Destroy
    - Initialize/Terminate
    - Commence/Finish
    - Launch/Kill
- Processing
    - Start/Stop
    - Begin/End
    - Open/Close
    - Enter/Exit

## General coding

### Variables
Variables must be named using camelCase.
```c++
int myInteger;
```
Booleans must be named using camelCase and being "tagged" with a letter lower case letter B.
```c++
bool bMyBoolean;
```

### Functions
Functions must be named using snake_case.
```c++
void my_function_doing_something();
```
Methods must be named using camelCase.
```c++
class MyClass
{
public:
    void myMethodDoingSomething();
};
```

### Namespaces
Namespaces must be declared using pascal case.
```c++
namespace MyNamespace
{

}
```
"using namespace" should not be used except readability issues.
```c++
using namespace MyNamespace;
```

### Comments
Ambiguous code must be commented to provide precision. The comment must be a short sentence starting with a lower case letter. A space must separate the "//" and the comment.
```c++
// this is a comment
```
Every function must be documented using Doxygen syntax.
- https://www.doxygen.nl/manual/docblocks.html
- https://www.doxygen.nl/manual/commands.html
```c++
/**
 * This is a documentation.
 *
 * @param int a
 * @param int b
 */
void my_function(const int a, const int b);
```
Classes, structs, methods and variables as well.
`ˋ`
class MyClass
{
};
ˋˋˋ

### Conditions
The if-else statement must not use any curly brackets if the scopes are only one line.
```c++
if ()
    doSomething();
else
    doSomething();
```
The if-else statement must use curly brackets if either if or else statement's scope is multiple lines.
```c++
if ()
{
    doSomething();
    doSomethingElse();
}
else
{
    doSomething();
}
```

### Incrementation and decrementation
Incrementation or decrementation, if not case specific, must be placed before the name of the variable.
```c++
++incrementation;
++i;
--decrementation;
--j;
```

### Arguments
Function arguments must have a prefix describing their use.

Input only argument must always be "tagged" const. If the variable size exceeds a float's size, it must be passed by reference.
```c++
void do_something(const int i_input);
```
Output only argument must be passed by reference.
```c++
void do_something(int& o_output);
```
Input and output argument must be passed by reference.
```c++
void do_something(int& io_inputOutput);
```

### Classes

#### Declaration
Classes must be declared using PascalCase. The members must be declared in this order : private, protected, public.
```c++
class MyClass
{
private:

protected:

public:
};
```

#### Member variables
The member variables must respect default variables convention.

#### Methods
Class' methods must be "const" by default.
```c++
void doSomethingMethod() const;
```
Inline methods must be defined in a .inl file.

### Structures
Structures must be declared using PascalCase and be finished with the upper case letter T for typedef. Even if structures can contain methods and private members, it is advised only to use public variables (without precising "public:" for readability).
```c++
struct MyStructT
{

};
```
Plain old data structures may be declared using lowercase snake_case and be finished with "_t" to follow standard convention.
```c++
struct my_pod_struct_t
{

};
```

### Enums
Enums must be declared using pascal case and be finished with the upper case letter E. The members must be named using all upper case and snake_case. Count member is optional but recommended.
```c++
enum MyEnumE
{
    MY_FIRST_MEMBER = 0,
    MY_SECOND_MEMBER = 1,
    MY_THIRD_MEMBER = 2,
    COUNT = 3
};
```

### Template
The template's typename must start with the upper case letter T and a quick word describing the template use.
```c++
template<typename TType>
```

### Interfaces
Interfaces must be declared with the upper case letter I as last letter. It must use PascalCase. It should then respect the class's rules. The methods should be pure virtual functions. The interfaces should not contain any data.
```c++
class MyInterfaceI
{
protected:

public:
    virtual void myMethod() = 0;
};
```
If needed, interface's derived classes may be named with their specialization and upper case first letter (such as their file name, [see file name convention](#naming-files)).
```c++
class MyInterfaceImpl_Vk : public MyInterfaceI
{
protected:

public:
    virtual void myMethod() override;
};

class MyInterfaceImpl_Gl : public MyInterfaceI
{
protected:

public:
    virtual void myMethod() override;
};
```
If an interface contains any data, it then becomes an abstract class and should be declared as such :
```c++
class MyAbstractClassABC
{
protected:
    int a;
    int b;

public:
    virtual void notAbstractMethod();
    virtual void pureVirtualMethod() = 0;
};
```

### Macros
Macros must be defined with upper case snake case.
```c++
#define MY_MACRO
```

### Forward declaration
User should always try to use forward declaration to decrease compilation time and avoid double inclusion and circular dependencies. Forward declaration is advised in header files.
```c++
class MyForwardedClass;
MyForwardedClass* myObjPtr;
MyForwardedClass& myObjRef;
```
```c++
class MyForwardedClass* myObjPtr;
class MyForwardedClass& myObjRef;
```

# Versionning with Git

## Branches
The branches must be named with no upper case letters. If the name uses multiple words, they must be separated with dashes.

The main branch must be master and the remote must be origin. A second main branch can be added to keep the milestones to be on master, it shall be named dev.

Each feature must be developped on specifically named branches.
These features can then be merged into dev when stable. Then the stable version that appear to be a milestone can be merged to master
```
origin/master
origin/dev
origin/graphics-pipeline
```
If working on other branches, the feature branches must be rebased before being merged to the main branch to avoid strange versionning tree.

## Commits
Commits must be a quick description of the work with no upper case letters. A deeper description can be given as a list.
```bash
git commit -m "quick modification" -m "- modification 1
- modification 2"
```
```bash
"quick modification"

"- modification 1
 - modification 2"
 ```

## Tags
Tags must represent a stable version. It must be described with 3 digits (major, minor, patch).
```
1.0.0
1.2.0
0.0.4
```

## .gitignore
The ignore file can be based on the template file in this repository or on the site https://gitignore.io.
