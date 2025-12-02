**Dependency architecture**

https://plantuml.com/class-diagram

composition :

```c++
class B{};

class A{
    B b;
    B& b;
};
// A *-- B
```

aggregation :

```c++
class B{};

class A{
    B* b = nullptr;
    std::optional<B> bb;
};
// A o-- B
```

inheritance :

```c++
class A{};

class B : public A {};
// B --|> A
```

dependency injection :

```c++
// interface
class I{};

class B : public I {};

class A{
    // mandatory dependency
    B& b;
    // optional dependency
    B* bb = nullptr;
};
// A *-- B --|> I
// A o-- B --|> I

// Class A uses features of Class B
```
