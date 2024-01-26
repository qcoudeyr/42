#ifndef MYCLASS_HPP
#define MYCLASS_HPP

class MyClass {
public:
    // Default constructor
    MyClass();

    // Parameterized constructor (not required by the orthodox canonical form, but often useful)
    explicit MyClass(int value);

    // Destructor
    ~MyClass();

    // Copy constructor
    MyClass(const MyClass& other);

    // Copy assignment operator
    MyClass& operator=(const MyClass& other);

    // If using C++11 or later, you might also consider the move constructor and move assignment operator:
    // Move constructor
    MyClass(MyClass&& other) noexcept;

    // Move assignment operator
    MyClass& operator=(MyClass&& other) noexcept;

    // Other member functions and data as needed
    void doSomething();

private:
    int data;
};

#endif // MYCLASS_HPP
