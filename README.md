# C++ Nanodegree 

## Introduction to C++

* Standard Library
    * "The C++ Standard Library is a collection of classes and functions, which are written in the core language and part of the C++ ISO Standard itself." Wikipedia

    * Learning how to use the Standard Library is an important part of becoming a proficient C++ software engineer. In almost all cases, it is preferable to utilize functionality that already exists in the Standard Library, instead of implementing functionality from scratch. This is both because using the Standard Library is faster (it is well-documented) and because many expert software engineers have worked on the Standard Library. The performance of Standard Library facilities is optimized, robust, and almost always as fast or faster than an initial re-implementation of the same functionality.

    * In fact, guideline SL.1 of the [C++ Core Guidelines](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines) is:
        * Use libraries wherever possible

        * Reason Save time. Don’t re-invent the wheel. Don’t replicate the work of others. Benefit from other people’s work when they make improvements. Help other people when you make improvements.
    
    * And guideline SL.2 is:
        * Prefer the standard library to other libraries

        * Reason More people know the standard library. It is more likely to be stable, well-maintained, and widely available than your own code or most other libraries.

* Namespace
    * Standard Library functions and classes exist in the `std::` namespace. `std::vector`, for example, refers to the vector class within the Standard Library. Typically, in order to use a Standard Library feature we must both include the necessary header file (e.g. #include <vector>) and also namespace the class with `std::` (e.g. `std::vector`).

* Compilers

    * C++ is a compiled programming language, which means that programmers use a program to compile their human-readable source code into machine-readable object and executable files. The program that performs this task is called a compiler.

    * C++ does not have an "official" compiler. Instead, there are many different compilers that a programmer can use.

    * GNU Compiler Collection (GCC)

        * In this program we primarily use the GNU Compiler Collection, which is a popular, open-source, cross-platform compiler from the larger GNU Project. In particular, we use the `g++` program, which is a command line executable that compiles C++ source code and **automatically links the C++ Standard Library**.
    
    * LLVM (low level virtual machine)
        
        * This is a new infrastructure of compilers, read more [here](https://llvm.org/)

        * The LLVM Project is a collection of modular and reusable compiler and toolchain technologies. Despite its name, LLVM has little to do with traditional virtual machines. The name "LLVM" itself is not an acronym; it is the full name of the project.

        * LLVM began as a research project at the University of Illinois, with the goal of providing a modern, SSA-based compilation strategy capable of supporting both static and dynamic compilation of arbitrary programming languages. Since then, LLVM has grown to be an umbrella project consisting of a number of subprojects, many of which are being used in production by a wide variety of commercial and open source projects as well as being widely used in academic research. Code in the LLVM project is licensed under the "Apache 2.0 License with LLVM exceptions"
    
    * Linking
        * ![linker](images/linker.png)

        * In order to use classes and functions from the C++ Standard Library, the compiler must have access to a compiled version of the standard library, stored in object files. Most compiler implementations, including GCC, **include those object files as part of the installation process**. In order to use the Standard Library facilities, the compiler must "link" the standard library object files to the object files created from the programmer's source code.

        * Once the compiler links together the necessary object files, it is able to generate a standalone executable file that can run on the operating system.

* Build Tools

    * Make and CMake are two separate and similar build tools that both serve to help simplify the process of building software.

    * In particular, build tools automate the process of compiling multiple source code files into object files, linking those object files together, and generating an executable. Build tools also often automate the process of determining which files have changed since the last build and thus need to be recompiled.

    * Make
        * [GNU Make](https://www.gnu.org/software/make/manual/html_node/index.html#Top) is a widely-used build tool that relies on `Makefiles` to automate the process of building a project.

        * A `Makefile` typically includes one or more "targets". Each target performs a different action.

        * `build` is a common **target** name that is configured in the `Makefile` to compile all of the project's source code into an executable file. `clean`, on the other hand, is a common target to delete all object files and other artifacts of the build process, resulting in a clean, unbuilt project state.

        * Running either `make build` or `make clean` (or any other target) on the command line would cause `Make` to search for a local `Makefile`, search for a matching target within that Makefile, and then execute the target.
    
    * CMake

        * [CMake](https://cmake.org/) is a built tool that facilitates **cross-platform** builds, so that it is straightforward to build the same source code on Linux, macOS, Windows, or any other operating system. `CMake` relies on a CMakeLists.txt file, which configures appropriate cross-platform targets.

        * Building a `CMakeLists.txt` file can be a bit daunting, but `CMake` provides a helpful tutorial.

        * In this Nanodegree program, you will not need to build your own `Makefiles` or `CMakeLists.txt` files. We provide the appropriate configuration files for each project and instruct you as to their usage.

* Installation

    * You are welcome to write all of your code in Udacity's web-based Workspaces. If, however, you prefer to work locally on your machine, you will need to install certain software.

    * llvm and clang (this tutorial uses this compiler)
        * [Download and instal](https://releases.llvm.org/download.html)

    * g++, gdb, make

        * MacOS

            * macOS includes g++ as part of Command Line Tools.

            * Launch Terminal, which can be found in the Utilities folder in Applications.
            * Type `xcode-select --install` into the Terminal window and press "Enter"
            * If you don't already have Xcode or Command Line Tools installed, a window will pop up. Press the Install button.
            * Verify: Type `g++` into Terminal and press enter. If the output is `clang: error: no input files`, then the installation was successful.    

        * Linux

            * These programs are typically available through the default package manager for each Linux distribution. For example, we can use APT on Ubuntu systems.

                * `sudo apt update`
                * `sudo apt install build-essential`
                * `sudo apt install gdb`
        
        * Windows

            * MinGW provides the necessary software.
                * Proceed from [Section 3.2](https://www.cs.odu.edu/~zeil/cs250PreTest/latest/Public/installingACompiler/#installing-the-mingw-compiler) of these linked instructions.

* Style

    * A consistent style (hopefully) helps improve and make your code more readable.

    * There are many different C++ styles, none of which is authoritative.

        * [C++ Core Guidlines: Naming and layout rules](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#nl-naming-and-layout-rules)
        * [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
        * [Mozilla Coding Style: C/C++ practices](https://developer.mozilla.org/en-US/docs/Mozilla/Developer_guide/Coding_Style#CC_practices)
    
    * ClangFormat

        * `clang-format` is a command line text formatter that automatically reformats source code according to configurable set of policies. The tool includes several pre-configured styles, or you can create your own.

        * `clang-format` is an open-source application that you can install on your system, or it is straightforward to install as a Visual Studio Code extension.  
            * `brew install clang-format`
        
* Debugging

    * Debugging is an important part of software development! Therefore, learning how to use a debugger is an important part of becoming a software developer 😬

    * Debuggers

        * Debuggers are tools that allow you to pause the execution of your code in various locations, inspect the state of the program, and step through your code line-by-line.

        * [GDB](https://www.gnu.org/software/gdb/) and [LLDB](https://lldb.llvm.org/) are two popular, open-source debuggers for C++. Integrating them into a code editor often makes debugging easier.

        * In order to use Visual Studio Code's debugger with C++ files, you must install the free C/C++ extension.
            * Remember to compile your code with Symbols `-g` flag
                * `clang++ -std=c++20 -g hello.cpp -o a.out`

## Foundations / Introduction to the C++ Language

* `#include <iostream>`

    * The `#include` is a preprocessor command which is executed before the code is compiled. It searches for the `iostream` header file and pastes its contents into the program. `iostream` contains the declarations for the input/output stream objects.


* `using std::cout;`

    * Namespaces are a way in C++ to group identifiers (names) together. They provide context for identifiers to avoid naming collisions. The `std` namespace is the namespace used for the standard library.
    * The `using` command adds `std::cout` to the global scope of the program. This way you can use `cout` in your code instead of having to write `std::cout`.
    * `cout` is an output stream you will use to send output to the notebook or to a terminal, if you are using one.
    * Note that the second two lines in the example end with a semicolon `;`. Coding statements end with a semicolon in C++. The `#include` statement is a preprocessor command, so it doesn't need one.

* `cout << "Hello!" << "\n";`

    * In this line, the code is using cout to send output to the notebook. The `<<` operator is the **stream insertion operator**, and it writes what's on the right side of the operator to the left side. So in this case, `"Message here"` is written to the output stream `cout`.

### Primitive Variable Types

C++ has several "primitive" variable types, which are things like `int`s (integers), `string`s, `float`s, and others. These should be similar to variable types in other programming languages you have used. 

* In the previous concept, you learned about some of the primitive types that C++ offers, including strings and ints, and you learned how to store these types in your program. In this concept, you will learn about one of the most common data structures in C++: the vector.

    * C++ also has several container types that can be used for storing data. We will start with `vector`s, as these will be used throughout this lesson, but we will also introduce other container types as needed.

    * Vectors are a sequence of elements of a single type, and have useful methods for getting the size, testing if the vector is empty, and adding elements to the vector.

    * Check `1-Foundations/2-vector`

    * Unfortunately, there isn't a built-in way to print vectors in C++ using `cout`. You will learn how to access vector elements and you will write your own function to print vectors later. For now, you can see how vectors are created and stored. Below, you can see how to nest vectors to create 2D containers.

    * Check `1-Foundations/2-vector`

    * You may have noticed comments in some of the code up until this point. C++ provides two kinds of comments:

        * ```
            // You can use two forward slashes for single line comments.

            /*
            For longer comments, you can enclose the text with an opening
            slash-star and closing star-slash.
            */ 
            ```
    
    * You have now seen how to store basic types and vectors containing those types. As you practiced declaring variables, in each case you indicated the type of the variable. It is possible for C++ to do automatic type inference, using the `auto` keyword.

        * Check `1-Foundations/3-auto`
    
    * It is helpful to manually declare the type of a variable if you want the variable type to be clear for reader of your code, or if you want to be explicit about the number precision being used; C++ has several number types with different levels of precision, and this precision might not be clear from the value being assigned.

### Store a Grid in Your Program

* In order to write the A* search algorithm, you will need a grid or "board" to search through. We'll be working with this board throughout the remaining exercises, and we'll start by storing a hard-coded board in the main function. In later exercises, you will write code to read the board from a file.

    * Note: you will need to include the vector library, just as iostream is included. You will also need to use the namespace std::vector if you want to write vector rather than std::vector in your code.

    * This exercise will be ungraded, but if you get stuck, you can find the solution in solution.cpp. Finally, if you feel a little crowded in the editor below and need more space to work, you can click the "Expand" button in the lower left corner.

    * Check `1-Foundations/4-grid`

### Loops

* Just as in other languages you've worked with, C++ has both for loops and while loops. You will learn about for loops in the notebook below, and you will see while loops later in the course.

* `Check 1-Foundations/5-loops`

### The Increment Operator

If you haven't seen the `++` operator before, this is the *post-increment operator*, and it is where the `++` in the name "C++" comes from. The operator increments the value of `i`. 

There is also a *pre-increment operator* which is used before a variable, as well as *pre* and *post decrement* operators: `--`. The difference between *pre* and *post* lies in what value is returned by the operator when it is used.

You will only use the *post-increment operator* `i++` for now, but if you are curious, click below for an explanation of the code:

* `Check 1-Foundations/5-loops`

## For Loop with a Container

C++ offers several ways to iterate over containers. One way is to use an index-based loop as above. Another way is using a "range-based loop", which you will see frequently in the rest of this course. See the following code for an example of how this works:

* ```cpp
    #include <iostream>
    #include <vector>
    using std::cout;
    using std::vector;

    int main() {
        // Add your code here.
        vector<int> a {1, 2, 3, 4, 5};
        for (int i: a) {
            cout << i << "\n";
        }
    }
    ```

### Functions

In the cell below, there is a simple function to add two numbers and return the result. Test the code below, and click the button for a more in-depth explanation.

* ```cpp
    #include <iostream>
    using std::cout;

    // Function declared and defined here.
    int AdditionFunction(int i, int j) 
    {
        return i + j;
    }

    int main() 
    {
        auto d = 3;
        auto f = 7;
        cout << AdditionFunction(d, f) << "\n";
    }
    ```


### File Input Streams

### Creating an Input Stream Object

* In C++, you can use the `std::ifstream` object to handle input file streams. To do this, you will need to include the header file that provides the file streaming classes: `<fstream>`. 

* Once the `<fstream>` header is included, a new input stream object can be declared and initialized using a file path `path`:
```cpp
std::ifstream my_file;
my_file.open(path);
```

* Alternatively, the declaration and initialization can be done in a single line as follows:
```
std::ifstream my_file(path);
```
* C++ `ifstream` objects can also be used as a boolean to check if the stream has been created successfully. If the stream were to initialize successfully, then the `ifstream` object would evaluate to `true`. If there were to be an error opening the file or some other error creating the stream, then the `ifstream` object would evaluate to `false`.

* The following cell creates an input stream from the file `"files/1.board"`:

* ```cpp
    #include <fstream>
    #include <iostream>
    #include <string>

    int main()
    {
        std::ifstream my_file;
        my_file.open("files/1.board");
        if (my_file) {
        std::cout << "The file stream has been created!" << "\n";
        }    
    }
    ```

### Reading Data from the Stream

* If the input file stream object has been successfully created, the lines of the input stream can be read using the `getline` method. In the cell below, a while loop has been added to the previous example to get each line from the stream and print it to the console.

* ```cpp
    #include <fstream>
    #include <iostream>
    #include <string>

    int main() {
        std::ifstream my_file;
        my_file.open("files/1.board");
        if (my_file) {
            std::cout << "The file stream has been created!" << "\n";
            std::string line;
            while (getline(my_file, line)) {
                std::cout << line << "\n";
            }
        }
    }
    ```


## Streaming `int`s from a `string` with istringstream

* In C++ strings can be streamed into temporary variables, similarly to how files can be streamed into strings. 
Streaming a string allows us to work with each character individually.

* One way to stream a string is to use an input string stream object `istringstream` from the `<sstream>` header. 

* Once an `istringstream` object has been created, parts of the string can be streamed and stored using the 
"extraction operator": `>>`. The extraction operator will read until whitespace is reached or until the stream 
fails. Execute the following code to see how this works:

```cpp
#include <iostream>
#include <sstream>
#include <string>

using std::istringstream;
using std::string;
using std::cout;

int main () 
{
    string a("j 2 3");

    istringstream my_stream(a);

    char n;
    my_stream >> n;
    cout << n << "\n";
}
```

* The `istringstream` object can also be used as a boolean to determine if the last extraction operation failed - this happens if there wasn't any more of the string to stream, for example. If the stream still has more characters, you are able to stream again. See the following code for an example of using the `istringstream` this way:

```cpp
#include <iostream>
#include <sstream>
#include <string>

using std::istringstream;
using std::string;
using std::cout;

int main() 
{
    string a("1 2 3");

    istringstream my_stream(a);

    int n;
    
    // Testing to see if the stream was successful and printing results.
    while (my_stream) {
        my_stream >> n;
        if (my_stream) {
            cout << "That stream was successful: " << n << "\n";
        }
        else {
            cout << "That stream was NOT successful!" << "\n";            
        }
    }
}
```

### Adding Data to a Vector

* In the previous exercises, you have declared and initialized vectors, and you have also accessed vector elements. In order to make full use of vectors in your code though, you will need to be able to add additional elements to them. Have a look at the following notebook for examples of how to do this.

## Vector push_back

* Now that you are able to process a string, you may want to store the results of the processing in a convenient container for later use. In the next exercise, you will store the streamed `int`s from each line of the board in a `vector<int>`. To do this, you will add the `int`s to the back of the vector, using the `vector` method `push_back`:

```cpp
#include <vector>
#include <iostream>
using std::vector;
using std::cout;

int main() {
    // Initial Vector
    vector v {1, 2, 3};
    
    // Print the contents of the vector
    for (int i=0; i < v.size(); i++) {
      cout << v[i] << "\n";
    }
    
    // Push 4 to the back of the vector
    v.push_back(4);

    // Print the contents again
    for (int i=0; i < v.size(); i++) {
      cout << v[i] << "\n";
    }
    
}
```

* In the previous exercises, you stored and printed the board as a vector<vector<int>>, where only two states were used for each cell: 0 and 1. This is a great way to get started, but as the program becomes more complicated, there will be more than two possible states for each cell. Additionally, it would be nice to print the board in a way that clearly indicates open areas and obstacles, just as the board is printed above.

* To do this clearly in your code, you will learn about and use something called an enum. An enum, short for enumerator, is a way to define a type in C++ with values that are restricted to a fixed range. For an explanation and examples, see the notebook below.

* ```cpp
    #include <iostream>
    using std::cout;

    int main()
    {
        enum class Direction {kUp, kDown, kLeft, kRight};

        Direction a = Direction::kUp;

        switch (a) {
        case Direction::kUp : cout << "Going up!" << "\n";
            break;
        case Direction::kDown : cout << "Going down!" << "\n";
            break;
        case Direction::kLeft : cout << "Going left!" << "\n";
            break;
        case Direction::kRight : cout << "Going right!" << "\n";
            break;
        }
    }
    ```

## Foundations / A* Search


* Motion Planning
    * The next videos and quizzes are taught by Sebastian Thrun (Udacity's former CEO) and they come from one of Udacity's first courses. The production style is a little different from what you will see in the rest of the course, but the content is very good. In these videos, Sebastian will discuss motion planning in robotics and provide the conceptual foundation for the project that you will build.


* Pass by Reference
    * In the previous exercises, you've written functions that accept and return various kinds of objects. However, in all of the functions you've written so far, the objects returned by the function are different from the objects provided to the function. In other words, when the function is called on some data, a copy of that data is made, and the function operates on a copy of the data instead of the original data. This is referred to as pass by value, since only a copy of the values of an object are passed to the function, and not the actual objects itself.

    * In the following example, the _value_ of `int i` is passed to the function `MultiplyByTwo`. Look carefully at the code and try to guess what the output will be before you execute it. When you are finished executing, click the button for an explanation.

    * ```cpp
        #include <iostream>
        using std::cout;


        int MultiplyByTwo(int i) {
            i = 2*i;
            return i;
        }

        int main() {
            int a = 5;
            cout << "The int a equals: " << a << "\n";
            int b = MultiplyByTwo(a);
            cout << "The int b equals: " << b << "\n";
            cout << "The int a still equals: " << a << "\n";
        }
        ```
    * In the code above, `a` is passed by value to the function, so the variable `a` is not affected by what happens inside the function.

    * But what if we wanted to change the value of `a` itself? For example, it might be that the variable you are passing into a function maintains some state in the program, and you want to write the function to update that state. 

    * It turns out, it is possible to modify `a` from within the function. To do this, you must pass a _reference_ to the variable `a`, instead of the _value_ of `a`. In C++, _a reference is just an alternative name for the same variable_.

    * To pass by reference, you simply need to add an ampersand `&` before the variable in the function declaration. Try the code below to see how this works:

    * ```cpp
        #include <iostream>
        using std::cout;


        int MultiplyByTwo(int &i) {
            i = 2*i;
            return i;
        }

        int main() {
            int a = 5;
            cout << "The int a equals: " << a << "\n";
            int b = MultiplyByTwo(a);
            cout << "The int b equals: " << b << "\n";
            cout << "The int a now equals: " << a << "\n";
        }
        ```
    
    * In the code above, `a` is passed by reference to the function `MultiplyByTwo` since the argument to `MultiplyByTwo` is a reference: `&i`. This means that `i` is becomes another name for whatever variable that is passed into the function. When the function changes the value of `i`, then the value of `a` is changed as well.

    * ```cpp
        #include <iostream>
        #include <string>
        using std::cout;
        using std::string;


        void DoubleString(string value) {
            // Concatentate the string with a space and itself.
            value = value + " " + value;
        }

        int main() {
            string s = "Hello";
            cout << "The string s is: " << s << "\n";
            DoubleString(s);
            cout << "The string s is now: " << s << "\n";
        }
        ```

### Constants 

* C++ supports two notions of immutability:

* `const`: meaning roughly " I promise not to change this value."...The compiler enforces the promise made by `const`....
* `constexpr`: meaning roughly "to be evaluated at compile time." This is used primarily to specify constants...

* ```cpp
    #include <iostream>

    int main()
    {
        int i;
        std::cout << "Enter an integer value for i: ";
        std::cin >> i;
        const int j = i * 2;  // "j can only be evaluated at run time."
                            // "But I promise not to change it after it is initialized."
        
        constexpr int k = 3;  // "k, in contrast, can be evaluated at compile time."
        
        std::cout << "j = " << j << "\n";
        std::cout << "k = " << k << "\n";
    }
    ```

* The major difference between `const` and `constexpr`, though, is that `constexpr` must be evaluated at compile time.

* The compiler will catch a `constexpr` variable that cannot be evaluated at compile time.

* ```cpp
    #include <iostream>

    int main()
    {
        int i;
        std::cout << "Enter an integer value for i: ";
        std::cin >> i;
        constexpr int j = i * 2;  // "j can only be evaluated at run time."
                                // "constexpr must be evaluated at compile time."
                                // "So this code will produce a compilation error."
    }
    ```

* A common usage of `const` is to guard against accidentally changing a variable, especially when it is passed-by-reference as a function argument.

* ```cpp
    #include <iostream>
    #include <vector>

    int sum(const std::vector<int> &v)
    {
        int sum = 0;
        for(int i : v)
            sum += i;
        return sum;
    }

    int main()
    {
        std::vector<int> v {0, 1, 2, 3, 4};
        std::cout << sum(v) << "\n";
    }
    ```

### Arrays

* In the previous exercise, we included an array of directional deltas for convenience:

```cpp
// directional deltas
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
```
* Arrays are a lower level data structure than vectors, and can be slightly more efficient, in terms of memory and element access. However, this efficiency comes with a price. Unlike vectors, which can be extended with more elements, arrays have a fixed length. Additionally, arrays may require careful memory management, depending how they are used.

* The example in the project code is a good use case for an array, as it was not intended to be changed during the execution of the program. However, a vector would have worked there as well.

## Foundations / Writing Multiple Files

* Header files, or `.h` files, allow related function, method, and class **declarations** to be collected in one place. The corresponding **definitions** can then be placed in `.cpp` files. The compiler considers a header declaration a "promise" that the definition will be found later in the code, so if the compiler reaches a function that hasn't been defined yet, it can continue on compiling until the definition is found. This allows functions to be defined (and declared) in arbitrary order.

* In the following code example, the functions are out of order, and the code will not compile. Try to fix this by rearranging the functions to be in the correct order.

* ```cpp
    #include <iostream>
    using std::cout;

    void OuterFunction(int i) 
    {
        InnerFunction(i);
    }

    void InnerFunction(int i) 
    {
        cout << "The value of the integer is: " << i << "\n";
    }

    int main() 
    {
        int a = 5;
        OuterFunction(a);
    }
    ```

* In the mini-project for the first half of the course, the instructions were very careful to indicate where each function should be placed, so you didn't run into the problem of functions being out of order.

* Using a Header

* One other way to solve the code problem above (without rearranging the functions) would have been to declare each function at the top of the file. A function **declaration** is much like the first line of a function **definition** - it contains the return type, function name, and input variable types. The details of the function definition are not needed for the declaration though.

To avoid a single file from becomming cluttered with declarations and definitions for every function, it is customary to declare the functions in another file, called the header file. In C++, the header file will have filetype `.h`, and the contents of the header file must be included at the top of the `.cpp` file. See the following example for a refactoring of the code above into a header and a cpp file.

* ```cpp
    // The header file with just the function declarations.
    // When you click the "Run Code" button, this file will
    // be saved as header_example.h.
    #ifndef HEADER_EXAMPLE_H
    #define HEADER_EXAMPLE_H

    void OuterFunction(int);
    void InnerFunction(int);

    #endif
    ```
* ```cpp
    // The contents of header_example.h are included in 
    // the corresponding .cpp file using quotes:
    #include "header_example.h"

    #include <iostream>
    using std::cout;

    void OuterFunction(int i) 
    {
        InnerFunction(i);
    }

    void InnerFunction(int i) 
    {
        cout << "The value of the integer is: " << i << "\n";
    }

    int main() 
    {
        int a = 5;
        OuterFunction(a);
    }
    ```

* Notice that the code from the first example was fixed without having to rearrange the functions! In the code above, you might also have noticed several other things:

    * The function declarations in the header file don't need variable names, just variable types. You can put names in the declaration, however, and doing this often makes the code easier to read.

    * The `#include` statement for the header used quotes " " around the file name, and not angle brackets <>. We have stored the header in the same directory as the .cpp file, and the quotes tell the preprocessor to look for the file in the same directory as the current file - not in the usual set of directories where libraries are typically stored.

    Finally, there is a preprocessor directive:
    ```cpp
        #ifndef HEADER_EXAMPLE_H
        #define HEADER_EXAMPLE_H
    ```
    
    * at the top of the header, along with an #endif at the end. This is called an **"include guard"**. Since the header will be included into another file, and #include just pastes contents into a file, the include guard prevents the same file from being pasted multiple times into another file. This might happen if multiple files include the same header, and then are all included into the same main.cpp, for example. The ifndef checks if HEADER_EXAMPLE_H has not been defined in the file already. If it has not been defined yet, then it is defined with #define HEADER_EXAMPLE_H, and the rest of the header is used. If HEADER_EXAMPLE_H has already been defined, then the preprocessor does not enter the ifndef block. Note: There are other ways to do this. Another common way is to use an **#pragma** oncepreprocessor directive, but we won't cover that in detail here. See this Wikipedia article for examples.

    * The addition of #include guards to a header file is one way to make that file idempotent. Another construct to combat double inclusion is #pragma once, which is non-standard but nearly universally supported among C and C++ compilers.

### CMake and Make

* In the previous notebook, you saw how example code could be split into multiple .h and .cpp files, and you used g++ to build all of the files together. For small projects with a handful of files, this works well. But what would happen if there were hundreds, or even thousands, of files in the project? You could type the names of the files at the command line each time, but there tools to make this easier.

* Many larger C++ projects use a build system to manage all the files during the build process. The build system allows for large projects to be compiled with a few commands, and build systems are able to do this in an efficient way by only recompiling files that have been changed.

* In this workspace you will learn about

    * Object files: what actually happens when you run g++.
    * How to use object files to compile only a single file at a time. If you have many files in a project, this will allow you can compile only files that have changed and need to be re-compiled.
    * How to use cmake (and make), a build system which is popular in large C++ projects.CMake will simplify the process of building project and re-compiling only the changed files.

* Object Files
    * When you compile a project with g++, g++ actually performs several distinct tasks:

    * The preprocessor runs and executes any statement beginning with a hash symbol: #, such as #include statements. This ensures all code is in the correct location and ready to compile.

    * Each file in the source code is compiled into an "object file" (a .o file). Object files are platform-specific machine code that will be used to create an executable.

    * The object files are "linked" together to make a single executable. In the examples you have seen so far, this executable is a.out, but you can specify whatever name you want.

    * It is possible to have g++ perform each of the steps separately by using the -c flag. For example,

        * `g++ -c main.cpp`
    
    * will produce a `main.o` file, and that file can be converted to an executable with

        * `g++ main.o`
    
    * Generate all object files `g++ -c *.cpp` and the link them `g++ *.o`

    * But what if you make changes to your code and you need to re-compile? In that case, you can compile only the file that you changed, and you can use the existing object files from the unchanged source files for linking.


    * Compiling just the file you have changed saves time if there are many files and compilation takes a long time. However, the process above is tedious when using many files, especially if you don't remember which ones you have modified.

    * For larger projects, it is helpful to use a build system which can compile exactly the right files for you and take care of linking.

* CMake and Make

    * CMake is an open-source, platform-independent build system. CMake uses text documents, denoted as CMakeLists.txt files, to manage build environments, like make. A comprehensive tutorial on CMake would require an entire course, but you can learn the basics of CMake here, so you'll be ready to use it in the upcoming projects.

    * CMakeLists.txt

        * CMakeList.txt files are simple text configuration files that tell CMake how to build your project. There can be multiple CMakeLists.txt files in a project. In fact, one CMakeList.txt file can be included in each directory of the project, indicating how the files in that directory should be built.

        * These files can be used to specify the locations of necessary packages, set build flags and environment variables, specify build target names and locations, and other actions.

    
    * The first lines that you'll want in your CMakeLists.txt are lines that specifies the minimum versions of cmake and C++ required to build the project. Add the following lines to your CMakeLists.txt and save the file:


        * ```
            cmake_minimum_required(VERSION 3.5.1)
            set(CMAKE_CXX_STANDARD 14)
            ```
        
        * These lines set the minimum cmake version required to 3.5.1 and set the environment variable CMAKE_CXX_STANDARD so CMake uses C++ 14. On your own computer, if you have a recent g++ compiler, you could use C++ 17 instead.
    
    * CMake requires that we name the project, so you should choose a name for the project and then add the following line to CMakeLists.txt:

        * `project(<your_project_name>)`
    
    * Next, we want to add an executable to this project. You can do that with the add_executable command by specifying the executable name, along with the locations of all the source files that you will need. CMake has the ability to automatically find source files in a directory, but for now, you can just specify each file needed:

        * `add_executable(your_executable_name  path_to_file_1  path_to_file_2 ...)`
    
    * A typical CMake project will have a build directory in the same place as the top-level CMakeLists.txt. Make a build directory in the /home/workspace/cmake_example folder:

    * ```bash
        root@abc123defg:/home/workspace/cmake_example# mkdir build
        root@abc123defg:/home/workspace/cmake_example# cd build
        root@abc123defg:/home/workspace/cmake_example/build# cmake ..
        root@abc123defg:/home/workspace/cmake_example/build# make
        root@abc123defg:/home/workspace/cmake_example/build# ./your_executable_name
        ```
        * The first line directs the cmake command at the top-level CMakeLists.txt file with ... This command uses the CMakeLists.txt to configure the project and create a Makefile in the build directory.

        * In the second line, make finds the Makefile and uses the instructions in the Makefile to build the project.

        * Now that your project builds correctly, try modifying one of the files. When you are ready to run the project again, you'll only need to run the make command from the build folder, and only that file will be compiled again. Try it now!

        * In general, CMake only needs to be run once for a project, unless you are changing build options (e.g. using different build flags or changing where you store your files).

        * Make will be able to keep track of which files have changed and compile only those that need to be compiled before building.

### References

* You have seen references used previously, in both pass-by-reference for functions, and in a range-basedfor loop example that used references to modify a vector. As you write larger C++ programs, you will find references useful in a variety of situations. In this short notebook, you will see a few more examples of references to solidify your knowledge.

* As mentioned previously, a reference is another name given to an existing variable. On the left hand side of any variable declaration, the & operator can be used to declare a reference.

* ```cpp
    #include <iostream>
    using std::cout;

    int main() 
    {
        int i = 1;
        
        // Declare a reference to i.
        int& j = i;
        cout << "The value of j is: " << j << "\n";
        
        // Change the value of i.
        i = 5;
        cout << "The value of i is changed to: " << i << "\n";
        cout << "The value of j is now: " << j << "\n";
        
        // Change the value of the reference.
        // Since reference is just another name for the variable,
        // th
        j = 7;
        cout << "The value of j is now: " << j << "\n";
        cout << "The value of i is changed to: " << i << "\n";
    }
    ```

### Pointers

* Pointers have traditionally been a stumbling block for many students learning C++, but they do not need to be!

* A C++ pointer is just a variable that stores the memory address of an object in your program.

* That is the most important thing to understand and remember about pointers - they essentially keep track of where a variable is stored in the computer's memory.

* In the previous lessons, you implemented A* search in a single file without using C++ pointers, except in `CellSort` code that was provided for you; a C++ program can be written without using pointers extensively (or at all). However, pointers give you better control over how your program uses memory. However, much like the pass-by-reference example that you saw previously, it can often be far more efficient to perform an operation with a pointer to an object than performing the same operation using the object itself.

* Pointers are an extremely important part of the C++ language, and as you are exposed to more C++ code, you will certainly encounter them. 

* Each variable in a program stores its contents in the computer's memory, and each chunk of the memory has an address number. For a given variable, the memory address can be accessed using an ampersand in front of the variable. To see an example of this, execute the following code which displays the hexadecimal memory addresses of the variables i and j:

    * ```cpp
        #include <iostream>
        using std::cout;

        int main() {
            int i = 5;
            int j = 6;
            
            // Print the memory addresses of i and j
            cout << "The address of i is: " << &i << "\n";
            cout << "The address of j is: " << &j << "\n";
        }
        ```
* At this point, you might be wondering why the same symbol & can be used to both access memory addresses and, as you've seen before, pass references into a function. This is a great thing to wonder about. The overloading of the ampersand symbol & and the * symbol probably contribute to much of the confusion around pointers.

    * The symbols & and * have a different meaning, depending on which side of an equation they appear.

    * This is extremely important to remember. For the & symbol, if it appears on the left side of an equation (e.g. when declaring a variable), it means that the variable is declared as a reference. If the & appears on the right side of an equation, or before a previously defined variable, it is used to return a memory address, as in the example above.

    * ```cpp
        #include <iostream>
        using std::cout;

        int main() 
        {
            int i = 5;
            // A pointer pointer_to_i is declared and initialized to the address of i.
            int* pointer_to_i = &i;
            
            // Print the memory addresses of i and j
            cout << "The address of i is:          " << &i << "\n";
            cout << "The variable pointer_to_i is: " << pointer_to_i << "\n";
        }
        ```
    
    * As you can see from the code, the variable pointer_to_i is declared as a pointer to an int using the * symbol, and pointer_to_i is set to the address of i. From the printout, it can be seen that pointer_to_i holds the same value as the address of i.

    * Once you have a pointer, you may want to retrieve the object it is pointing to. In this case, the * symbol can be used again. This time, however, it will appear on the right hand side of an equation or in front of an already-defined variable, so the meaning is different. In this case, it is called the "dereferencing operator", and it returns the object being pointed to. You can see how this works with the code below:

    * ```cpp
        #include <iostream>
        using std::cout;

        int main() 
        {
            int i = 5;
            // A pointer pointer_to_i is declared and initialized to the address of i.
            int* pointer_to_i = &i;
            
            // Print the memory addresses of i and j
            cout << "The address of i is:          " << &i << "\n";
            cout << "The variable pointer_to_i is: " << pointer_to_i << "\n";
            cout << "The value of the variable pointed to by pointer_to_i is: " << *pointer_to_i << "\n";
        }
        ```
    
    * In the following example, the code is similar to above, except that the object that is being pointed to is changed before the pointer is dereferenced. Before executing the following code, guess what you think will happen to the value of the dereferenced pointer.

        * ```cpp
            #include <iostream>
            using std::cout;

            int main() {
                int i = 5;
                // A pointer pointer_to_i is declared and initialized to the address of i.
                int* pointer_to_i = &i;
                
                // Print the memory addresses of i and j
                cout << "The address of i is:          " << &i << "\n";
                cout << "The variable pointer_to_i is: " << pointer_to_i << "\n";
                
                // The value of i is changed.
                i = 7;
                cout << "The new value of the variable i is                     : " << i << "\n";
                cout << "The value of the variable pointed to by pointer_to_i is: " << *pointer_to_i << "\n";
            }
            ```
    
    * In the previous concept, you were introduced to int pointers, and you learned the syntax for creating a pointer and retrieving an object from a pointer.

    * Although the type of object being pointed to must be included in a pointer declaration, pointers hold the same kind of value for every type of object: just a memory address to where the object is stored. In the following code, a vector is declared. Write your own code to create a pointer to the address of that vector. Then, dereference your pointer and print the value of the first item in the vector.

        * ```cpp
            #include <iostream>
            #include <vector>
            using std::cout;
            using std::vector;

            int main() {
                // Vector v is declared and initialized to {1, 2, 3}
                vector<int> v {1, 2, 3};
                
                // Declare and initialize a pointer to the address of v here:
                vector<int> *pointer_to_v = &v;

                // The following loops over each int a in the vector v and prints.
                // Note that this uses a "range-based" for loop: https://www.geeksforgeeks.org/range-based-loop-c/
                for (int a: v) {
                    cout << a << "\n";
                }
                
                // Dereference your pointer to v and print the int at index 0 here (note: you should print 1):
                cout << "The first element of v is: " << (*pointer_to_v)[0] << "\n";
            }
            ```
    
    * Pointers can be used in another form of pass-by-reference when working with functions. When used in this context, they work much like the references that you used for pass-by reference previously. If the pointer is pointing to a large object, it can be much more efficient to pass the pointer to a function than to pass a copy of the object as with pass-by-value.

        * In the following code, a pointer to an int is created, and that pointer is passed to a function. The object pointed to is then modified in the function.

        * ```cpp
            #include <iostream>
            using std::cout;

            void AddOne(int* j)
            {
                // Dereference the pointer and increment the int being pointed to.
                (*j)++;
            }

            int main() 
            {
                int i = 1;
                cout << "The value of i is: " << i << "\n";
                
                // Declare a pointer to i:
                int* pi = &i;
                AddOne(pi);
                cout << "The value of i is now: " << i << "\n";
            }
            ```

    * You can also return a pointer from a function. As mentioned just above, if you do this, you must be careful that the object being pointed to doesn't go out of scope when the function finishes executing. If the object goes out of scope, the memory address being pointed to might then be used for something else.

    * In the example below, a reference is passed into a function and a pointer is returned. This is safe since the pointer being returned points to a reference - a variable that exists outside of the function and will not go out of scope in the function.

    * ```cpp
        #include <iostream>
        using std::cout;

        int* AddOne(int& j) 
        {
            // Increment the referenced int and return the
            // address of j.
            j++;
            return &j;
        }

        int main() 
        {
            int i = 1;
            cout << "The value of i is: " << i << "\n";
            
            // Declare a pointer and initialize to the value
            // returned by AddOne:
            int* my_pointer = AddOne(i);
            cout << "The value of i is now: " << i << "\n";
            cout << "The value of the int pointed to by my_pointer is: " << *my_pointer << "\n";
        }
        ```

### References vs Pointers

* Pointers and references can have similar use cases in C++. As seen previously both references and pointers can be used in pass-by-reference to a function. Additionally, they both provide an alternative way to access an existing variable: pointers through the variable's address, and references through another name for that variable. But what are the differences between the two, and when should each be used? The following list summarizes some of the differences between pointers and references, as well as when each should be used:

| References                                                                                                                                            | Pointers                                                                                                                                                                                                                                                                                                |
|-------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| References must be initialized when they are declared.  This means that a reference will always point to data  that was intentionally assigned to it. | Pointers can be declared without being  initialized, which is dangerous. If this  happens mistakenly, the pointer could be  pointing to an arbitrary address in memory,  and the data associated with that address  could be meaningless, leading to undefined  behavior and difficult-to-resolve bugs. |
| References can not be null. This means that a reference should  point to meaningful data in the program.                                              | Pointers can be null. In fact, if a pointer is  not initialized immediately, it is often best practice  to initialize to nullptr, a special type which  indicates that the pointer is null.                                                                                                             |
| When used in a function for pass-by-reference,  the reference can be used just as a variable of  the same type would be.                              | When used in a function for pass-by-reference,  a pointer must be dereferenced in order to access  the underlying object.                                                                                                                                                                               |

* References are generally easier and safer than pointers. As a decent rule of thumb, references should be used in place of pointers when possible.

* However, there are times when it is not possible to use references. One example is object initialization. You might like one object to store a reference to another object. However, if the other object is not yet available when the first object is created, then the first object will need to use a pointer, not a reference, since a reference cannot be null. The reference could only be initialized once the other object is created.

### Maps

* So far in this course you have seen container data structures, like the vector and the array. Additionally, you have used classes in your code for this project. Container data structures are fantastic for storing ordered data, and classes are useful for grouping related data and functions together, but neither of these data structures is optimal for storing associated data.

* A map (alternatively hash table, hash map, or dictionary) is a data structure that uses key/value pairs to store data, and provides efficient lookup and insertion of the data. The name "dictionary" should provide an excellent idea of how these work, since a dictionary is a real life example of a map. Here is a slightly edited entry from www.dictionary.com defining the word "word":

    * word

        * a unit of language, consisting of one or more spoken sounds or their written representation, that functions as a principal carrier of meaning.
        * speech or talk: to express one's emotion in words.
        * a short talk or conversation: "Marston, I'd like a word with you."
        * an expression or utterance: a word of warning.

* In the following notebook, you will learn how to use an unordered_map, which is the C++ standard library implementation of a map. Although C++ has several different implementations of map data structures which are similar, unordered_map is the structure that you will use in your project.

* In the cell below, we have created a hash table (unordered_map) to store the data from the example above. To create an unordered_map in C++, you must include the <unordered_map> header, and the sytnax for declaring an unordered_map is as follows:

*  `unordered_map <key_type, value_type> variable_name;`

* In the code below, we check if the key is in the unordered_map using the `.find()` method. If the key does not exist in the map, then `.find()` returns an `unordered_map::end()` type. Otherwise, .find() returns a C++ iterator, which is a pointer that points to the beginning of the iterable key-value pair.

* We haven't covered iterators in this course, and you won't need them for this project, but they are a lot like pointers that can "iterate" forward or backward through a range.

* ```cpp
    #include <iostream>
    #include <vector>
    #include <unordered_map>
    #include <string>
    using std::vector;
    using std::cout;
    using std::unordered_map;
    using std::string;


    int main() {
        // Create strings to use in the hash table.
        string key = "word";
        string def_1 = "a unit of language, consisting of one or more spoken sounds or their written representation, that functions as a principal carrier of meaning";
        string def_2 = "speech or talk: to express one's emotion in words";
        string def_3 = "a short talk or conversation: 'Marston, I'd like a word with you.'";
        string def_4 = "an expression or utterance: a word of warning";
        unordered_map <string, vector<string>> my_dictionary;

        // Check if key is in the hash table.
        if (my_dictionary.find(key) == my_dictionary.end()) {
            cout << "The key 'word' is not in the dictionary." << "\n";
            cout << "Inserting a key-value pair into the dictionary." << "\n\n";
            // Set the value for the key.
            my_dictionary[key] = vector<string> {def_1, def_2, def_3, def_4};
        }

        // The key should now be in the hash table. You can access the
        // value corresponding to the key with square brackets [].
        // Here, the value my_dictionary[key] is a vector of strings.
        // We iterate over the vector and print the strings.
        cout << key << ": \n";
        auto definitions = my_dictionary[key];
        for (string definition : definitions) {
            cout << definition << "\n";
        }
    }
    ```

    * ```cpp
        #include<unordered_map>
        #include<string>
        #include<iostream>
        #include<vector>
        using std::unordered_map;
        using std::string;
        using std::cout;
        using std::vector;

        // Write your program here.
        int main()
        {
            unordered_map<int, string> IDD_codes {{972, "Israel"}, {93, "Afghanistan"}, {355, "Albania"}, {213, "Algeria"}, {376, "Andorra"}, {244, "Angola"}, {54, "Argentina"}, {374, "Armenia"}, {297, "Aruba"}, {61, "Australia"}, {43, "Austria"}, {994, "Azerbaijan"}, {973, "Bahrain"}, {880, "Bangladesh"}, {375, "Belarus"}, {32, "Belgium"}, {501, "Belize"}, {229, "Benin"}, {975, "Bhutan"}, {387, "Bosnia and Herzegovina"}, {267, "Botswana"}, {55, "Brazil"}, {246, "British Indian Ocean Territory"}, {359, "Bulgaria"}, {226, "Burkina Faso"}, {257, "Burundi"}, {855, "Cambodia"}, {237, "Cameroon"}, {1, "Canada"}, {238, "Cape Verde"}, {236, "Central African Republic"}, {235, "Chad"}, {56, "Chile"}, {86, "China"}, {61, "Christmas Island"}, {57, "Colombia"}, {269, "Comoros"}, {242, "Congo"}, {682, "Cook Islands"}, {506, "Costa Rica"}, {385, "Croatia"}, {53, "Cuba"}, {537, "Cyprus"}, {420, "Czech Republic"}, {45, "Denmark"}, {253, "Djibouti"}, {593, "Ecuador"}, {20, "Egypt"}, {503, "El Salvador"}, {240, "Equatorial Guinea"}, {291, "Eritrea"}, {372, "Estonia"}, {251, "Ethiopia"}, {298, "Faroe Islands"}, {679, "Fiji"}, {358, "Finland"}, {33, "France"}, {594, "French Guiana"}, {689, "French Polynesia"}, {241, "Gabon"}, {220, "Gambia"}, {995, "Georgia"}, {49, "Germany"}, {233, "Ghana"}, {350, "Gibraltar"}, {30, "Greece"}, {299, "Greenland"}, {590, "Guadeloupe"}, {502, "Guatemala"}, {224, "Guinea"}, {245, "Guinea-Bissau"}, {595, "Guyana"}, {509, "Haiti"}, {504, "Honduras"}, {36, "Hungary"}, {354, "Iceland"}, {91, "India"}, {62, "Indonesia"}, {964, "Iraq"}, {353, "Ireland"}, {972, "Israel"}, {39, "Italy"}, {81, "Japan"}, {962, "Jordan"}, {254, "Kenya"}, {686, "Kiribati"}, {965, "Kuwait"}, {996, "Kyrgyzstan"}, {371, "Latvia"}, {961, "Lebanon"}, {266, "Lesotho"}, {231, "Liberia"}, {423, "Liechtenstein"}, {370, "Lithuania"}, {352, "Luxembourg"}, {261, "Madagascar"}, {265, "Malawi"}, {60, "Malaysia"}, {223, "Mali"}, {356, "Malta"}, {692, "Marshall Islands"}, {596, "Martinique"}, {222, "Mauritania"}, {230, "Mauritius"}, {262, "Mayotte"}, {52, "Mexico"}, {377, "Monaco"}, {976, "Mongolia"}, {382, "Montenegro"}, {212, "Morocco"}, {95, "Myanmar"}, {264, "Namibia"}, {674, "Nauru"}, {977, "Nepal"}, {31, "Netherlands"}, {599, "Netherlands Antilles"}, {687, "New Caledonia"}, {64, "New Zealand"}, {505, "Nicaragua"}, {227, "Niger"}, {234, "Nigeria"}, {683, "Niue"}, {672, "Norfolk Island"}, {47, "Norway"}, {968, "Oman"}, {92, "Pakistan"}, {680, "Palau"}, {507, "Panama"}, {675, "Papua New Guinea"}, {595, "Paraguay"}, {51, "Peru"}, {63, "Philippines"}, {48, "Poland"}, {351, "Portugal"}, {974, "Qatar"}, {40, "Romania"}, {250, "Rwanda"}, {685, "Samoa"}, {378, "San Marino"}, {966, "Saudi Arabia"}, {221, "Senegal"}, {381, "Serbia"}, {248, "Seychelles"}, {232, "Sierra Leone"}, {65, "Singapore"}, {421, "Slovakia"}, {386, "Slovenia"}, {677, "Solomon Islands"}, {27, "South Africa"}, {500, "South Georgia and the South Sandwich Islands"}, {34, "Spain"}, {94, "Sri Lanka"}, {249, "Sudan"}, {597, "Suriname"}, {268, "Swaziland"}, {46, "Sweden"}, {41, "Switzerland"}, {992, "Tajikistan"}, {66, "Thailand"}, {228, "Togo"}, {690, "Tokelau"}, {676, "Tonga"}, {216, "Tunisia"}, {90, "Turkey"}, {993, "Turkmenistan"}, {688, "Tuvalu"}, {256, "Uganda"}, {380, "Ukraine"}, {971, "United Arab Emirates"}, {44, "United Kingdom"}, {1, "United States"}, {598, "Uruguay"}, {998, "Uzbekistan"}, {678, "Vanuatu"}, {681, "Wallis and Futuna"}, {967, "Yemen"}, {260, "Zambia"}, {263, "Zimbabwe"}, {591, "Bolivia, Plurinational State of"}, {673, "Brunei Darussalam"}, {61, "Cocos (Keeling) Islands"}, {243, "Congo, The Democratic Republic of the"}, {225, "Cote dIvoire"}, {500, "Falkland Islands (Malvinas)"}, {44, "Guernsey"}, {379, "Holy See (Vatican City State)"}, {852, "Hong Kong"}, {98, "Iran, Islamic Republic of"}, {44, "Isle of Man"}, {44, "Jersey"}, {850, "Korea, Democratic People's Republic of"}, {82, "Korea, Republic of"}, {856, "Lao People's Democratic Republic"}, {218, "Libyan Arab Jamahiriya"}, {853, "Macao"}, {389, "Macedonia, The Former Yugoslav Republic of"}, {691, "Micronesia, Federated States of"}, {373, "Moldova, Republic of"}, {258, "Mozambique"}, {970, "Palestinian Territory, Occupied"}, {872, "Pitcairn"}, {262, "Réunion"}, {7, "Russia"}, {590, "Saint Barthélemy"}, {290, "Saint Helena, Ascension and Tristan Da Cunha"}, {590, "Saint Martin"}, {508, "Saint Pierre and Miquelon"}, {239, "Sao Tome and Principe"}, {252, "Somalia"}, {47, "Svalbard and Jan Mayen"}, {963, "Syrian Arab Republic"}, {886, "Taiwan, Province of China"}, {255, "Tanzania, United Republic of"}, {670, "Timor-Leste"}, {58, "Venezuela, Bolivarian Republic of"}, {84, "Viet Nam"}};
            if (IDD_codes.find(960) == IDD_codes.end()) {
                IDD_codes[960] = "Maldives";
            }
            
            vector<int> my_codes {1, 55, 960};
            for (int code : my_codes) {
                cout << code << ": " << IDD_codes[code] << "\n";
            }
        }
        ```

### Classes and Object-Oriented Programming

* If you are taking this course, you have probably used object-oriented programming (OOP) previously in another language. If it's been a while since you've used OOP, OOP is a style of coding that collects related data (object attributes) and functions (object methods) together to form a single data structure, called an object. This allows that collection of attributes and methods to be used repeatedly in your program without code repetition.

* In C++ the attributes and methods that make up an object are specified in a code class, and each object in the program is an instance of that class.

* This concept is intended to provide you with the basic syntax for writing classes in C++. In this Foundations course, you will not need to write your own classes for the project, but you will be modifying existing classes in the code. You will be writing your own classes in the next course of this Nanodegree: Object-Oriented Programming.

* In the next cell, the code above has been rewritten with a `Car` class.

* ```cpp
    #include <iostream>
    #include <string>
    using std::string;
    using std::cout;

    // The Car class
    class Car {
    public:
        // Method to print data.
        void PrintCarData() 
        {
            cout << "The distance that the " << color << " car " << number << " has traveled is: " << distance << "\n";
        }
        
        // Method to increment the distance travelled.
        void IncrementDistance() 
        {
            distance++;
        }
        
        // Class/object attributes
        string color;
        int distance = 0;
        int number;
    };

    int main() 
    {
        // Create class instances for each car.
        Car car_1, car_2, car_3;

        // Set each instance's color.
        car_1.color = "green";
        car_2.color = "red";
        car_3.color = "blue";

        // Set each instance's number.
        car_1.number = 1;
        car_2.number = 2;
        car_3.number = 3;

        // Increment car_1's position by 1.
        car_1.IncrementDistance();

        // Print out the position and color of each car.
        car_1.PrintCarData();
        car_2.PrintCarData();
        car_3.PrintCarData();

    }
    ```

* This looks ok, and you have reduced the number of variables in main, so you might see how this could be more organized going forward. However, there is now a lot more code than you started with, and the main doesn't seem much more organzied. The code above still sets the attributes for each car after the car has been created.

* The best way to fix this is to add a constructor to the Car class. The constructor allows you to instantiate new objects with the data that you want. In the next code cell, we have added a constructor for Car that allows the number and color to be passed in. This means that each Car object can be created with those variables.

* ```cpp
    #include <iostream>
    #include <string>
    using std::string;
    using std::cout;

    class Car {
    public:
        void PrintCarData() 
        {
            cout << "The distance that the " << color << " car " << number << " has traveled is: " << distance << "\n";
        }

        void IncrementDistance() 
        {
            distance++;
        }
        
        // Adding a constructor here:
        Car(string c, int n) 
        {
            // Setting the class attributes with
            // The values passed into the constructor.
            color = c;
            number = n;
        }
        
        string color;
        int distance = 0;
        int number;
    };

    int main() 
    {
        // Create class instances for each car.
        Car car_1 = Car("green", 1);
        Car car_2 = Car("red", 2);
        Car car_3 = Car("blue", 3);

        // Increment car_1's position by 1.
        car_1.IncrementDistance();

        // Print out the position and color of each car.
        car_1.PrintCarData();
        car_2.PrintCarData();
        car_3.PrintCarData();
    }
    ```

* This is now beginning to look better. The main is more organized than when we first started, although there is a little more code overall to accomodate the class definition. At this point, you might want to separate your class definition into it's own .h and .cpp files. We'll do that in the next concept!

### Inheritance

* It is possible for a class to use methods and attributes from another class using class inheritance. For example, if you wanted to make a Sedan class with additional attributes or methods not found in the generic Car class, you could create a Sedan class that inherited from the Car by using the colon notation:

* ```cpp
    class Sedan : public Car {
        // Sedan class declarations/definitions here.
    };
    ```

* By doing this, each Sedan class instance will have access to any of the public methods and attributes of Car. In the code above, these areIncrementDistance() and PrintCarData(). You can add additional features to the Sedan class as well. In the example above, Car is often referred to as the parent class, and Sedan as the child or derived class.

* A full discussion of inheritance is beyond the scope of this course, but you will encounter it briefly in the project code later. In the project code, the classes are set up to inherit from existing classes of an open source code project. You won't need to use inheritance otherwise, but keep in mind that your classes can use all of the public methods and attributes of their parent class.

### Putting the Class Definitions into Separate Files

* In the previous concept, you saw how to create a `Car` classs and use a constructor. At the end of that concept, your code looked like this:

* ```cpp
    #include <iostream>
    #include <string>
    using std::string;
    using std::cout;

    class Car {
    public:
        void PrintCarData() 
        {
            cout << "The distance that the " << color << " car " << number << " has traveled is: " << distance << "\n";
        }

        void IncrementDistance() 
        {
            distance++;
        }
        
        // Adding a constructor here:
        Car(string c, int n) 
        {
            // Setting the class attributes with
            // The values passed into the constructor.
            color = c;
            number = n;
        }
        
        string color;
        int distance = 0;
        int number;
    };

    int main() 
    {
        // Create class instances for each car.
        Car car_1 = Car("green", 1);
        Car car_2 = Car("red", 2);
        Car car_3 = Car("blue", 3);

        // Increment car_1's position by 1.
        car_1.IncrementDistance();

        // Print out the position and color of each car.
        car_1.PrintCarData();
        car_2.PrintCarData();
        car_3.PrintCarData();

    }
    ```

* If you were planning to build a larger program, at this point it might be good to put your class definition and function declarations into a separate file. Just as when we discussed header files before, putting the class definition into a separate header helps to organize your code, and prevents problems with trying to use class objects before the class is defined.

* There are two things to note in the code below. 

1. When the class methods are defined outside the class, the _scope resolution operator_ `::` must be used to indicate which class the method belongs to. For example, in the definition of the `PrintCarData` method you see:
  
* ```cpp
    void Car::PrintCarData()
    ```
* This prevents any compiler issues if there are are two classes with methods that have the same name.

2. We have changed how the constructor initializes the variables. Instead of the previous constructor:
    * ```cpp
        Car(string c, int n) {
            color = c; 
            number = n;
        }
        ```
* the constructor now uses an [_initializer list_](https://en.cppreference.com/w/cpp/language/initializer_list):
    * ```cpp
        Car(string c, int n) : color(c), number(n) {}
        ```

* Here, the class members are initialized before the body of the constructor (which is now empty). Initializer lists are a quick way to initialize many class attributes in the constructor. Additionally, the compiler treats attributes initialized in the list slightly differently than if they are initialized in the constructor body. For reasons beyond the scope of this course, if a class attribute is a reference, it must be initialized using an initializer list.
  
3. Variables that don't need to be visible outside of the class are set as `private`. This means that they can not be accessed outside of the class, which [prevents them from being accidentally changed](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rc-private).

Check out the cells below to see this code in practice. In this code, we have separated the class into declarations and definitions, with declarations being in the `.h` file and definitions being in `.cpp`. Note that only the `.h` file needs to be included in any other file where the definitions are used.

* `car.h`
* ```cpp
    #ifndef CAR_H
    #define CAR_H

    #include <string>
    using std::string;
    using std::cout;

    class Car {
    public:
        void PrintCarData();
        void IncrementDistance();
        
        // Using a constructor list in the constructor:
        Car(string c, int n) : color(c), number(n) {}
    
    // The variables do not need to be accessed outside of
    // functions from this class, so we can set them to private.
    private:
        string color;
        int distance = 0;
        int number;
    };

    #endif
    ```

* `car.cpp`
* ```cpp
    #include <iostream>
    #include "car.h"

    // Method definitions for the Car class.
    void Car::PrintCarData() 
    {
        cout << "The distance that the " << color << " car " << number << " has traveled is: " << distance << "\n";
    }

    void Car::IncrementDistance() 
    {
        distance++;
    }
    ```

* `main.cpp`
* ```cpp
    #include <iostream>
    #include <string>
    #include "car.h"
    using std::string;
    using std::cout;

    int main() 
    {
        // Create class instances for each car.
        Car car_1 = Car("green", 1);
        Car car_2 = Car("red", 2);
        Car car_3 = Car("blue", 3);

        // Increment car_1's position by 1.
        car_1.IncrementDistance();

        // Print out the position and color of each car.
        car_1.PrintCarData();
        car_2.PrintCarData();
        car_3.PrintCarData();

    }
    ```

* There is a lot going on in the code to unpack, including the `new` keyword and the `->` operator. The arrow operator `->` is used to simultaneously

    * dereference a pointer to an object and
    * access an attribute or method.

* For example, in the code below, cp is a pointer to a Car object, and the following two are equivalent:

* ```cpp
        // Simultaneously dereference the pointer and 
        // access IncrementDistance().
        cp->IncrementDistance();

        // Dereference the pointer using *, then 
        // access IncrementDistance() with traditional 
        // dot notation.
        (*cp).IncrementDistance();
    ```

* The new operator allocates memory on the "heap" for a new Car. In general, this memory must be manually managed (deallocated) to avoid memory leaks in your program. Memory management is the primary focus of one of the later courses in this Nanodegree program, so we won't go into greater depth about the difference between `stack` and `heap` in this lesson.

* ```cpp
    #include <iostream>
    #include <string>
    #include <vector>
    #include "car.h"
    using std::string;
    using std::cout;
    using std::vector;

    int main() {
        // Create an empty vector of pointers to Cars 
        // and a null pointer to a car.
        vector<Car*> car_vect;
        Car* cp = nullptr;
        
        // The vector of colors for the cars:
        vector<string> colors {"red", "blue", "green"};

        // Create 100 cars with different colors and 
        // push pointers to each of those cars into the vector.
        for (int i=0; i < 100; i++) {;
            cp = new Car(colors[i%3], i+1);
            car_vect.push_back(cp);
        }

        // Move each car forward by 1.
        for (Car* cp: car_vect) {
            cp->IncrementDistance();
        }

        // Print data about each car.
        for (Car* cp: car_vect) {
            cp->PrintCarData();
        }
    }
    ```

### This Pointer

When working with classes it is often helpful to be able to refer to the current class instance or object. For example, given the following Car class from a previous lesson, the IncrementDistance() method implicitly refers to the current Car instance's distance attribute:

* ```cpp
    // The Car class
    class Car {
    public:
        // Method to print data.
        void PrintCarData() {
            cout << "The distance that the " << color << " car " << number << " has traveled is: " << distance << "\n";
        }

        // Method to increment the distance travelled.
        void IncrementDistance() {
            distance++;
        }

        // Class/object attributes
        string color;
        int distance = 0;
        int number;
    };
    ```

* It is possible to make this explicit in C++ by using the this pointer, which points to the current class instance. Using this can sometimes be helpful to add clarity to more complicated code:

* ```cpp
    // The Car class
    class Car {
    public:
        // Method to print data.
        void PrintCarData() {
            cout << "The distance that the " << this->color << " car " << this->number << " has traveled is: " << this->distance << "\n";
        }

        // Method to increment the distance travelled.
        void IncrementDistance() {
            this->distance++;
        }

        // Class/object attributes
        string color;
        int distance = 0;
        int number;
    };
    ```

* Note: you may see this used in some code in the remainder of the course.

## Object-Oriented Programming / Intro to OOP

* Structures

    * Structures allow developers to create their own types ("user-defined" types) to aggregate data relevant to their needs.

    * For example, a user might define a Rectangle structure to hold data about rectangles used in a program.

    * ```cpp
        struct Rectangle {
            float length;
            float width;
        };
        ```
        * `length` and `width` are member variables
    
    * Types

        * Every C++ variable is defined with a type.

        * ```cpp
            int value;
            Rectangle rectangle;
            Sphere earth;
            ```
        
        * In this example, the "type" of `value` is `int`. Furthermore, `rectangle` is "of type" `Rectangle`, and `earth` has type `Sphere`.
    
    * Fundamental Types
        
        * C++ includes fundamental types, such as `int` and `float`. These fundamental types are sometimes called "primitives".

        * The Standard Library [includes additional types](, such as `std::size_t` and `std::string`.
    
    * User-Defined Types

        * Structures are "user-defined" types. Structures are a way for programmers to create types that aggregate and store data in way that makes sense in the context of a program.

        * For example, C++ does not have a fundamental type for storing a date. (The Standard Library does include types related to time, which can be converted to dates.)

        * A programmer might desire to create a type to store a date.

        * Consider the following example:

        * ```cpp
            struct Date {
                int day;
                int month;
                int year;
            };
            ```
        
        * The code above creates a structure containing three "member variables" of type int: day, month and year.

        * If you then create an "instance" of this structure, you can initialize these member variables:

        * ```cpp
            // Create an instance of the Date structure
            Date date;
            // Initialize the attributes of Date
            date.day = 1;
            date.month = 10;
            date.year = 2019;
            ```

    * Generally, we want to avoid instantiating an object with undefined members. Ideally, we would like all members of an object to be in a valid state once the object is instantiated. We can change the values of the members later, but we want to avoid any situation in which the members are ever in an invalid state or undefined.

    * In order to ensure that objects of our Date structure always start in a valid state, we can initialize the members from within the structure definition.

    * ```cpp
        struct Date {
            int day{1};
            int month{1};
            int year{0};    
        };
        ```
    
    * There are also several other approaches to either initialize or assign member variables when the object is instantiated. For now, however, this approach ensures that every object of Date begins its life in a defined and valid state.

    * Members of a structure can be specified as `public` or `private`.

    * By default, all members of a structure are `public`, unless they are specifically marked `private`.

    * Public members can be changed directly, by any user of the object, whereas private members can only be changed by the object itself.

    * Private Members

        * This is an implementation of the `Date` structure, with all members marked as private.

        * ```cpp
            struct Date {
                private:
                int day{1};
                int month{1};
                int year{0};
            };
            ```
        
        * Private members of a class are accessible only from within other member functions of the same class (or from their "friends", which we’ll talk about later).

        * There is a third access modifier called `protected`, which implies that members are accessible from other member functions of the same class (or from their "friends"), and also from members of their derived classes. We'll also discuss about derived classes later, when we learn about inheritance.

    * Accessors And Mutators

        * To access private members, we typically define public "accessor" and "mutator" member functions (sometimes called "getter" and "setter" functions).

        * ```cpp
            struct Date {
                public:
                    int Day() { return day; }
                    void Day(int day) { this.day = day; }
                    int Month() { return month; }
                    void Month(int month) { this.month = month; }
                    int Year() { return year; }
                    void Year(int year) { this.year = year; }

                private:
                    int day{1};
                    int month{1};
                    int year{0};
            };
            ```
    
    * Avoid Trivial Getters And Setters

        * Sometimes accessors are not necessary, or even advisable. The C++ Core Guidelines recommend, "A trivial getter or setter adds no semantic value; the data item could just as well be public."

        * ```cpp
            class Point {
                    int x;
                    int y;
                public:
                    Point(int xx, int yy) : x{xx}, y{yy} { }
                    int get_x() const { return x; }  // const here promises not to modify the object
                    void set_x(int xx) { x = xx; }
                    int get_y() const { return y; }  // const here promises not to modify the object
                    void set_y(int yy) { y = yy; }
                    // no behavioral member functions
            };
            ```
        
        * This `class` could be made into a `struct`, with no logic or "invariants", just passive data. The member variables could both be public, with no accessor functions:

        * ```cpp
            struct Point {   // Good: concise
                int x {0};   // public member variable with a default initializer of 0
                int y {0};   // public member variable with a default initializer of 0
            };
            ```
* Classes

    * Classes, like structures, provide a way for C++ programmers to aggregate data together in a way that makes sense in the context of a specific program. By convention, programmers use structures when member variables are independent of each other, and use classes when member variables are related by an "invariant".

    * Invariants

        * An "invariant" is a rule that limits the values of member variables.

        * For example, in a `Date` class, an invariant would specify that the member variable `day` cannot be less than 0. Another invariant would specify that the value of day cannot exceed 28, 29, 30, or 31, depending on the month and year. Yet another invariant would limit the value of month to the range of 1 to 12.

        * `Date` Class

        * Let's define a `Date` class:

        * ```cpp
            // Use the keyword “class” to define a Date class:
            class Date {
                int day{1};
                int month{1};
                int year{0};
            };
            ```
        
        * So far, this class definition provides no invariants. The data members can vary independently of each other.

        * There is one subtle but important change that takes place when we change `struct` Date to `class` Date. By default, **all members of a struct default to public, whereas all members of a class default to private**. Since we have not specified access for the members of class Date, all of the members are private. In fact, we are not able to assign value to them at all!

        * `Date` Accessors And Mutators

        * As the first step to adding the appropriate invariants, let's specify that the member variable `day` is private. In order to access this member, we'll provide accessor and mutatot functions. Then we can add the appropriate invariants to the mutators.

        * ```cpp
            class Date {
                public:
                    int Day() { return day_; }
                    void Day(int d) { day_ = d; }

                private:
                    int day_{1};
                    int month_{1};
                    int year_{0};
                };
            ```
        
        * `Date` Invariants

        * Now we can add the invariants whitin the mutators

        * ```cpp
            class Date {
                public:
                    int Day() { return day; }
                    void Day(int d) {
                        if (d >= 1 && d <= 31) day_ = d;
            }

            private:
                int day_{1};
                int month_{1};
                int year_{0};
            };
            ```

        * Now we have a set of invariants for the the class members!

        * As a general rule, member data subject to an invariant should be specified private, in order to enforce the invariant before updating the member's value.

* Constructors

    * Constructors are member functions of a class or struct that initialize an object. The Core Guidelines define a constructor) as:

        * constructor: an operation that initializes (“constructs”) an object. Typically a constructor establishes an invariant and often acquires resources needed for an object to be used (which are then typically released by a destructor).
    
    * A constructor can take arguments, which can be used to assign values to member variables.

        * ```cpp
            class Date {
            public:
                Date(int d, int m, int y) {  // This is a constructor.
                    Day(d);
                }
                int Day() { return day; }
                void Day(int d) {
                    if (d >= 1 && d <= 31) day = d;
                }
                int Month() { return month; }
                void Month(int m) {
                    if (m >= 1 && m <= 12) month = m;
                }
                int Year() { return year_; }
                void Year(int y) { year = y; }

            private:
                int day{1};
                int month{1};
                int year{0};
            };
            ```
        
        * As you can see, a constructor is also able to call other member functions of the object it is constructing. In the example above, `Date(int d, int m, int y)` assigns a member variable by calling `Day(int d)`.

    * Default Constructor

        * A class object is always initialized by calling a constructor. That might lead you to wonder how it is possible to initialize a class or structure that does not define any constructor at all.

        * For example:

            * ```cpp    
                class Date { 
                    int day{1};
                    int month{1};
                    int year{0};
                };
                ```
        
        * We can initialize an object of this class, even though this class does not explicitly define a constructor.

        * This is possible because of the default constructor. The compiler will define a default constructor, which accepts no arguments, for any class or structure that does not contain an explicitly-defined constructor.

* Scope Resolution

    *  C++ allows different identifiers (variable and function names) to have the same name, as long as they have different scope. For example, two different functions can each declare the variable int i, because each variable only exists within the scope of its parent function.

    * In some cases, scopes can overlap, in which case the compiler may need assistance in determining which identifier the programmer means to use. The process of determining which identifier to use is called "scope resolution".

    * Scope Resultion Operator

        * `::` is the scope resolution operator. We can use this operator to specify which namespace or class to search in order to resolve an identifier.

        * ```cpp
            Person::move(); \\ Call the move the function that is a member of the Person class.
            std::map m; \\ Initialize the map container from the C++ Standard Library.  
            ```
    
    * Class
        * Each class provides its own scope. We can use the scope resolution operator to specify identifiers from a class.

        * This becomes particularly useful if we want to separate class declaration from class definition.

        * ```cpp
            class Date {
                public:
                    int Day() const { return day; }
                    void Day(int day);  // Declare member function Date::Day().
                    int Month() const { return month; }
                    void Month(int month) {
                        if (month >= 1 && month <= 12) Date::month = month;
                    }
                    int Year() const { return year; }
                    void Year(int year) { Date::year = year; }

                private:
                    int day{1};
                    int month{1};
                    int year{0};
            };

            // Define member function Date::Day().
            void Date::Day(int day) {
            if (day >= 1 && day <= 31) Date::day = day;
            }
            ```
    
    * Namespaces

        * Namespaces allow programmers to group logically related variables and functions together. Namespaces also help to avoid conflicts between to variables that have the same name in different parts of a program.

        * ```cpp
            namespace English {
                void Hello() { std::cout << "Hello, World!\n"; }
            }  // namespace English

            namespace Spanish {
                void Hello() { std::cout << "Hola, Mundo!\n"; }
            }  // namespace Spanish

            int main() {
            English::Hello();
            Spanish::Hello();
            }
            ```
        
        * In this example, we have two different `void Hello()` functions. If we put both of these functions in the same namespace, they would conflict and the program would not compile. However, by declaring each of these functions in a separate namespace, they are able to co-exist. Furthermore, we can specify which function to call by prefixing Hello() with the appropriate namespace, followed by the :: operator.

        * ```cpp
            #include <cassert>

            class Date {
                public:
                    int Day() { return day; }
                    void Day(int day);
                    int Month() { return month; }
                    void Month(int month);
                    int Year() { return year; }
                    void Year(int year);

                private:
                    int day{1};
                    int month{1};
                    int year{0};
            };

            // TODO: Define Date::Day(int day)
            void Date::Day(int day) {
                if(day >= 1 && day <= 31)
                    Date::day = day;
            }

            // TODO: Define Date::Month(int month)
            void Date::Month(int month) {
                if(month >= 1 && month <= 12)
                    Date::month = month;
            }

            // TODO: Define Date::Year(int year)
            void Date::Year(int year) { Date::year = year; }

            // Test in main
            int main() {
            Date date;
            date.Day(29);
            date.Month(8);
            date.Year(1981);
            assert(date.Day() == 29);
            assert(date.Month() == 8);
            assert(date.Year() == 1981);
            }
            ```

* Initializer List

    * Initializer lists initialize member variables to specific values, just before the class constructor runs. This initialization ensures that class members are automatically initialized when an instance of the class is created.

    * ```cpp
        Date::Date(int day, int month, int year) : year_(y) {
            Day(day);
            Month(month);
        }
        ```
    
    * In this example, the member value year is initialized through the initializer list, while day and month are assigned from within the constructor. Assigning day and month allows us to apply the invariants set in the mutator.

    * In general, prefer initialization to assignment. Initialization sets the value as soon as the object exists, whereas assignment sets the value only after the object comes into being. This means that assignment creates and opportunity to accidentally use a variable before its value is set.

    * In fact, initialization lists ensure that member variables are initialized before the object is created. **This is why class member variables can be declared const**, but only if the member variable is initialized through an initialization list. Trying to initialize a const class member within the body of the constructor will not work.

    * ```cpp
        #include <assert.h>
        #include <string>

        // TODO: Define class Person
        struct Person {
            // TODO: Define a public constructor with an initialization list
            Person(std::string name) : name(name) {}
            // TODO: Define a public member variable: name
            std::string name;  
        };

        // Test
        int main() {
            Person alice("Alice");
            Person bob("Bob");
            assert(alice.name != bob.name);
        }
        ```

    * Initializer lists exist for a number of reasons. First, the compiler can optimize initialization faster from an initialization list than from within the constructor.

    * A second reason is a bit of a technical paradox. If you have a const class attribute, you can only initialize it using an initialization list. Otherwise, you would violate the const keyword simply by initializing the member in the constructor!

    * The third reason is that attributes defined as references must use initialization lists.

    * ```cpp
        #include <assert.h>
        #include <string>

        struct Person {
            public:
            // TODO: Add an initialization list
            Person(std::string const & n) : name(n) {}
            std::string const name;
        };

        // Test
        int main() {
            Person alice("Alice");
            Person bob("Bob");
            assert(alice.name != bob.name);
        }
        ```
    
* Encapsulation

    * Encapsulation is the grouping together of data and logic into a single unit. In object-oriented programming, classes encapsulate data and functions that operate on that data.

    * This can be a delicate balance, because on the one hand we want to group together relevant data and functions, but on the hand we want to limit member functions to only those functions that need direct access to the representation of a class.

    * In the context of a Date class, a function Date Tomorrow(Date const & date) probably does not need to be encapsulated as a class member. It can exist outside the Date class.

    * However, a function that calculates the number of days in a month probably should be encapsulated with the class, because the class needs this function in order to operate correctly.

    * ```cpp
        #include <cassert>

        class Date {
        public:
            Date(int day, int month, int year);
            int Day() const { return day_; }
            void Day(int day);
            int Month() const { return month_; }
            void Month(int month);
            int Year() const { return year_; }
            void Year(int year);

        private:
            bool LeapYear(int year) const;
            int DaysInMonth(int month, int year) const;
            int day_{1};
            int month_{1};
            int year_{0};
        };

        Date::Date(int day, int month, int year) {
            Year(year);
            Month(month);
            Day(day);
        }

        bool Date::LeapYear(int year) const {
            if(year % 4 != 0)
                return false;
            else if(year % 100 != 0)
                return true;
            else if(year % 400 != 0)
                return false;
            else
                return true;
        }

        int Date::DaysInMonth(int month, int year) const {
            if(month == 2)
                return LeapYear(year) ? 29 : 28;
            else if(month == 4 || month == 6 || month == 9 || month == 11)
                return 30;
            else
                return 31;
        }

        void Date::Day(int day) {
            if (day >= 1 && day <= DaysInMonth(Month(), Year()))
                day_ = day;
        }

        void Date::Month(int month) {
            if (month >= 1 && month <= 12)
                month_ = month; 
        }

        void Date::Year(int year) { year_ = year; }

        // Test
        int main() {
            Date date(29, 2, 2016);
            assert(date.Day() == 29);
            assert(date.Month() == 2);
            assert(date.Year() == 2016);
                
            Date date2(29, 2, 2019);
            assert(date2.Day() != 29);
            assert(date2.Month() == 2);
            assert(date2.Year() == 2019);
        }
        ```

* Accessor Functions

    * Accessor functions are public member functions that allow users to access an object's data, albeit indirectly.

    * `const`

    * Accessors should only retrieve data. They should not change the data stored in the object.

    * The main role of the const specifier in accessor methods is to protect member data. When you specify a member function as const, the compiler will prohibit that function from changing any of the object's member data.

    * ```cpp
        #include <iostream>
        #include <string>

        class BankAccount
        {
        public:
            int number;
            std::string owner;
            double funds;
        };

        int main(){
            // TODO: instantiate and output a bank account
            BankAccount account;
            account.number = 123456789;
            account.owner = "David Silver";
            account.funds   = 1,000,000.01
                
            std::cout << "Account Information\n";
            std::cout << "-------------------\n";
            std::cout << "ID: " << account.number << "\n";
            std::cout << "Owner: " << account.owner << "\n";
            std::cout << "Funds: $" << account.funds << "\n";
        }
        ```

* Mutator Functions

    * ```cpp
        #include <string>
        #include <cstring>
        #include <iostream>

        class Car {
            // TODO: Declare private attributes
            private:
                std::string _brand;
                
            // TODO: Declare getter and setter for brand
            public:
                void brand(char*);
                std::string brand() const;
                
        };

        // Define setters
        void Car::brand(char* brand)
        {
            Car::_brand = brand;
        }

        // Define getters
        std::string Car::brand() const
        {
            return _brand;
        }

        // Test in main()
        int main() 
        {
            Car car;
            char brand[] = "Peugeot";
            car.brand(brand);
            std::cout << car.brand() << "\n";   
        }
        ```

* Abstraction

    * Abstraction refers to the separation of a class's interface from the details of its implementation. The interface provides a way to interact with an object, while hiding the details and implementation of how the class works.

    * Example

        * The String() function within this Date class is an example of abstraction.

        * ```cpp
            class Date {
                public:
                ...
                std::string String() const;
                ...
            };
            ```

        * The user is able to interact with the Date class through the String() function, but the user does not need to know about the implementation of either Date or String().

        * For example, the user does not know, or need to know, that this object internally contains three int member variables. The user can just call the String() method to get data.

        * If the designer of this class ever decides to change how the data is stored internally -- using a vector of ints instead of three separate ints, for example -- the user of the Date class will not need to know.

* Static Members

    * Class members can be declared `static`, which means that the member belongs to the entire class, instead of to a specific instance of the class. More specifically, a `static` member is created only once and then shared by all instances (i.e. objects) of the class. That means that if the static member gets changed, either by a user of the class or within a member function of the class itself, then all members of the class will see that change the next time they access the static member.

    * Implementation

        * `static` members are declared within their class (often in a header file) but in most cases they must be defined within the global scope. That's because memory is allocated for static variables immediately when the program begins, at the same time any global variables are initialized.

        * Here is an example:

        * ```cpp
            #include <cassert>

            class Foo {
                public:
                static int count;
                Foo() { Foo::count += 1; }
            };

            int Foo::count{0};

            int main() {
                Foo f{};
                assert(Foo::count == 1);
            }
            ```

        * An exception to the global definition of `static` members is if such members can be marked as `constexpr`. In that case, the `static` member variable can be both declared and defined within the class definition:

        * ```cpp
            struct Kilometer {
                static constexpr int meters{1000};
            };
            ```

## Object-Oriented Programming / Advanced OOP

* Inheritence

    * In our everyday life, we tend to divide things into groups, based on their shared characteristics. Here are some groups that you have probably used yourself: electronics, tools, vehicles, or plants.

    * Sometimes these groups have hierarchies. For example, computers and smartphones are both types of electronics, but computers and smartphones are also groups in and of themselves. You can imagine a tree with "electronics" at the top, and "computers" and "smartphones" each as children of the "electronics" node.

    * Object-oriented programming uses the same principles! For instance, imagine a Vehicle class:

        * ```cpp
            class Vehicle {
            public:
                int wheels = 0;
                string color = "blue";

                void Print() const
                {
                    std::cout << "This " << color << " vehicle has " << wheels << " wheels!\n";
                }
            };
            ```
    
    * We can derive other classes from Vehicle, such as Car or Bicycle. One advantage is that this saves us from having to re-define all of the common member variables - in this case, wheels and color - in each derived class.

    * Another benefit is that derived classes, for example Car and Bicycle, can have distinct member variables, such as sunroof or kickstand. Different derived classes will have different member variables:

        * ```cpp
            class Car : public Vehicle {
                public:
                    bool sunroof = false;
            };

            class Bicycle : public Vehicle {
                public:
                    bool kickstand = true;
            };
            ```
    
    * Another example:

        * ```cpp
            #include <iostream>
            #include <string>
            using std::string;

            class Vehicle {
            public:
                int wheels = 0;
                string color = "blue";
                string make  = "generic";
                
                void Print() const
                {
                    std::cout << "This " << color << " " << make << " vehicle has " << wheels << " wheels!\n";
                }
            };

            class Car : public Vehicle {
                public:
                    bool sunroof = false;
            };

            class Bicycle : public Vehicle {
                public:
                    bool kickstand = true;
            };

            class Scooter : public Vehicle {
                public:
                    bool electric = false;
            };

            int main() 
            {
                Scooter scooter;
                scooter.wheels = 2;
                scooter.Print();
            };
            ```

* Inherited Access Specifiers

    * Just as access specifiers (i.e. public, protected, and private) define which class members users can access, the same access modifiers also define which class members users of a derived classes can access.

    * Public inheritance: the public and protected members of the base class listed after the specifier keep their member access in the derived class

    * Protected inheritance: the public and protected members of the base class listed after the specifier are protected members of the derived class

    * Private inheritance: the public and protected members of the base class listed after the specifier are private members of the derived class

    * ```cpp
        // This example demonstrates the privacy levels
        // between parent and child classes
        #include <iostream>
        #include <string>
        using std::string;

        class Vehicle {
            public:
                int wheels = 0;
                string color = "blue";
                
                void Print() const
                {
                    std::cout << "This " << color << " vehicle has " << wheels << " wheels!\n";
                }
        };

        class Car : public Vehicle {
            public:
                bool sunroof = false;
        };

        class Bicycle : protected Vehicle {
            public:
                bool kickstand = true;
                void Wheels(int w)
                {
                    wheels = w;
                }
        };

        class Scooter : private Vehicle {
            public:
                bool electric = false;
                void Wheels(int w)
                {
                    wheels = w;
                }
        };

        int main() 
        {
            Car car;
            car.wheels = 4;
            Bicycle bicycle;
            bicycle.Wheels(2);
            Scooter scooter;
            scooter.Wheels(1);
        };
        ```

    * Another example

        * ```cpp
            // Example solution for Animal class
            #include <iostream>
            #include <string>

            // Define base class Animal
            class Animal {
            public:
                std::string color;
                std::string name;
                int age;
            };

            // Declare derived class Snake
            class Snake : public Animal {
            public:
                int length;
                
                void MakeSound() const
                {
                    std::cout << "Hiss\n";
                }
            };

            // Declare derived class Cat
            class Cat : public Animal {
            public:
                int height;

                void MakeSound() const
                {
                    std::cout << "Meow\n";
                }
            };

            // Test in main()
            int main() {

                Cat cat;
                Snake snake;

                cat.age = 10;
                cat.name = "Lucy";
                cat.MakeSound();
                snake.MakeSound();

                std::cout << cat.age << " " << cat.name << "\n";
            }
            ```

* Composition

    * Composition is a closely related alternative to inheritance. Composition involves constructing ("composing") classes from other classes, instead of inheriting traits from a parent class.

    * A common way to distinguish "composition" from "inheritance" is to think about what an object can do, rather than what it is. This is often expressed as "has a" versus "is a".

    * From the standpoint of composition, a cat "has a" head and "has a" set of paws and "has a" tail.

    * From the standpoint of inheritance, a cat "is a" mammal.

    * There is no hard and fast rule about when to prefer composition over inheritance. In general, if a class needs only extend a small amount of functionality beyond what is already offered by another class, it makes sense to inherit from that other class. However, if a class needs to contain functionality from a variety of otherwise unrelated classes, it makes sense to compose the class from those other classes.

    * In this example, you'll practice working with composition in C++.
        
        * ```cpp
            // Example solution for Circle class
            #include <iostream>
            #include <cmath>
            #include <assert.h>
            // Define PI
            #define PI 3.14159;

            // Define LineSegment struct
            struct LineSegment {
                // Define protected attribute length
                public:
                    double length;
            };

            // Define Circle class
            class Circle {
                public:
                    Circle(LineSegment& radius);
                    double Area();

                private:
                    LineSegment& radius_;
            };

            // Declare Circle class
            Circle::Circle(LineSegment& radius) : radius_(radius) {}

            double Circle::Area() 
            {
                return pow(Circle::radius_.length, 2) * PI;
            }

            // Test in main()
            int main() 
            {
                LineSegment radius {3};
                Circle circle(radius);
                assert(int(circle.Area()) == 28);
            }
            ```
    
    * Class Hierarchy

        * ```cpp
            #include <cassert>

            // TODO: Declare Vehicle as the base class
            class Vehicle {};

            // TODO: Derive Car from Vehicle
            class Car : public Vehicle {
                public:
                    int wheels{4};
            };

            // TODO: Derive Sedan from Car
            class Sedan : public Car {
                public:
                    bool trunk{true};
                    int seats{4};
            };

            // TODO: Update main to pass the tests
            int main() {
                Sedan sedan;
                assert(sedan.trunk == true);
                assert(sedan.seats == 4);
                assert(sedan.wheels == 4);
            }
            ```

* Friends

    * In C++, `friend` classes provide an alternative inheritance mechanism to derived classes. The main difference between classical inheritance and friend inheritance is that a `friend` class **can access private members of the base class**, which isn't the case for classical inheritance. In classical inheritance, a derived class can only access public and protected members of the base class.

    * ```cpp
        // Example solution for Rectangle and Square friend classes
        #include <assert.h>

        // Declare class Rectangle
        class Rectangle;

        // Define class Square as friend of Rectangle
        class Square {
        // Add public constructor to Square, initialize side
        public:
            Square(int s) : side(s) {}

        private:
            // Add friend class Rectangle
            friend class Rectangle;
            // Add private attribute side to Square
            int side;
        };

        // Define class Rectangle
        class Rectangle {
        // Add public functions to Rectangle: area() and convert()
        public:
            Rectangle(const Square& a);
            int Area() const;

        private:
            // Add private attributes width, height
            int width {0};
            int height {0};
        };

        // Define a Rectangle constructor that takes a Square
        Rectangle::Rectangle(const Square& a) : width(a.side), height(a.side) {}

        // Define Area() to compute area of Rectangle
        int Rectangle::Area() const
        {
            return width * height;
        }

        // Update main() to pass the tests
        int main()
        {
            Square square(4);
            Rectangle rectangle(square);
            assert(rectangle.Area() == 16); 
        }
        ```

* Polymorphism

    * Polymorphism is means "assuming many forms".

    * In the context of object-oriented programming, polymorphism) describes a paradigm in which a function may behave differently depending on how it is called. In particular, the function will perform differently based on its inputs.

    * Polymorphism can be achieved in two ways in C++: overloading and overriding. In this exercise we will focus on overloading.

    * Overloading

        * In C++, you can write two (or more) versions of a function with the same name. This is called "overloading". Overloading requires that we leave the function name the same, but we modify the function signature. For example, we might define the same function name with multiple different configurations of input arguments.

        * This example of class Date overloads:

            * ```cpp
                #include <ctime>

                class Date {
                public:
                    Date(int day, int month, int year) : day_(day), month_(month), year_(year) {}
                    Date(int day, int month) : day_(day), month_(month)  // automatically sets the Date to the current year
                    {
                        time_t t = time(NULL);
                        tm* timePtr = localtime(&t);
                        year_ = timePtr->tm_year;
                    }

                private:
                    int day_;
                    int month_;
                    int year_;
                };
                ```
        
        * ```cpp
            #include <iostream>

            class Human {};
            class Dog {};
            class Cat {};

            // TODO: Write hello() function
            void hello() { std::cout << "Hello, World!\n"; }

            // TODO: Overload hello() three times
            void hello(Human human) { std::cout << "Hello, Human!\n"; }
            void hello(Dog dog) { std::cout << "Hello, Dog!\n"; }
            void hello(Cat cat) { std::cout << "Hello, Cat!\n"; }

            // TODO: Call hello() from main()
            int main()
            {
                hello();
                hello(Human());
                hello(Dog());
                hello(Cat());
            }
            ```

* Operator Overloading

    * n this exercise you'll see how to achieve polymorphism with operator overloading. You can choose any operator from the ASCII table and give it your own set of rules!

    * Operator overloading can be useful for many things. Consider the + operator. We can use it to add ints, doubles, floats, or even std::strings.

    * In order to overload an operator, use the operator keyword in the function signature:   

        * ```cpp
            Complex operator+(const Complex& addend) {
                //...logic to add complex numbers
            }
            ```
    
    * Imagine vector addition. You might want to perform vector addition on a pair of points to add their x and y components. The compiler won't recognize this type of operation on its own, because this data is user defined. However, you can overload the + operator so it performs the action that you want to implement.

        * ```cpp
            #include <assert.h>

            // TODO: Define Point class
            class Point {
                public:
                    // TODO: Define public constructor
                    Point(int x = 0, int y = 0) : x(x), y(y) {}

                    // TODO: Define + operator overload
                    Point operator+(const Point& addend) {
                        Point sum;
                        sum.x = x + addend.x;
                        sum.y = y + addend.y;
                        return sum;
                    }

                    // TODO: Declare attributes x and y
                    int x, y;
            };

            // Test in main()
            int main() {
                Point p1(10, 5), p2(2, 4);
                Point p3 = p1 + p2; // An example call to "operator +";
                assert(p3.x == p1.x + p2.x);
                assert(p3.y == p1.y + p2.y);
            }
            ```

* Virtual Functions

    * Virtual functions are a polymorphic feature. These functions are declared (and possibly defined) in a base class, and can be overridden by derived classes.

    * This approach declares an interface at the base level, but delegates the implementation of the interface to the derived classes.

    * In this exercise, class Shape is the base class. Geometrical shapes possess both an area and a perimeter. Area() and Perimeter() should be virtual functions of the base class interface. Append `= 0` to each of these functions in order to declare them to be "pure" virtual functions.

    * **A pure virtual function is a virtual function that the base class declares but does not define.**

    * A pure virtual function has the side effect of **making its class abstract**. This means that the class cannot be instantiated. Instead, only classes that derive from the abstract class and override the pure virtual function can be instantiated.

    * ```cpp
        class Shape {
            public:
                Shape() {}
                virtual double Area() const = 0;
                virtual double Perimeter() const = 0;
        };
        ```
    
    * **Virtual functions can be defined by derived classes, but this is not required**. However, if we mark the virtual function with `= 0` in the base class, then we are declaring the function to be a pure virtual function. This means that the **base class does not define this function. A derived class must define this function, or else the derived class will be abstract**.

    * ```cpp
        // Example solution for Shape inheritance
        #include <assert.h>
        #include <cmath>

        // TODO: Define pi
        #define PI 3.14159;

        // TODO: Define the abstract class Shape
        class Shape {
            public:
            // TODO: Define public virtual functions Area() and Perimeter()
            // TODO: Append the declarations with = 0 to specify pure virtual functions
            virtual double Area() const = 0;
            virtual double Perimeter() const = 0;
        };

        // TODO: Define Rectangle to inherit publicly from Shape
        class Rectangle : public Shape {
            public:
                // TODO: Declare public constructor
                Rectangle(double width, double height) : width_(width), height_(height) {}
                // TODO: Override virtual base class functions Area() and Perimeter()
                double Area() const override { return width_ * height_; }
                double Perimeter() const override { return 2 * (width_ + height_); }

            private:
                // TODO: Declare private attributes width and height
                double width_;
                double height_;
        };

        // TODO: Define Circle to inherit from Shape
        class Circle : public Shape {
            public:
                // TODO: Declare public constructor
                Circle(double radius) : radius_(radius) {}
                // TODO: Override virtual base class functions Area() and Perimeter()
                double Area() const override { return pow(radius_, 2) * PI; }
                double Perimeter() const override { return 2 * radius_ * PI; }

            private:
                // TODO: Declare private member variable radius
                double radius_;
        };

        // Test in main()
        int main() {
            double epsilon = 0.1; // useful for floating point equality

            // Test circle
            Circle circle(12.31);
            assert(abs(circle.Perimeter() - 77.35) < epsilon);
            assert(abs(circle.Area() - 476.06) < epsilon);

            // Test rectangle
            Rectangle rectangle(10, 6);
            assert(rectangle.Perimeter() == 32);
            assert(rectangle.Area() == 60);
        }
        ```
    * Polymorphism: Overriding

        * "Overriding" a function occurs when:

            * A base class declares a virtual function.
            
            * A derived class overrides that virtual function by defining its own implementation with an identical function signature (i.e. the same function name and argument types).
        
        * ```cpp
            class Animal {
                public:
                    virtual std::string Talk() const = 0;
            };

            class Cat {
                public:
                    std::string Talk() const { return std::string("Meow"); }
            };
            ```
        
        * ```cpp
            #include <assert.h>
            #include <string>

            class Animal {
                public:
                    virtual std::string Talk() const = 0;
            };

            // TODO: Declare a class Dog that inherits from Animal
            class Dog : Animal {
                public:  
                    std::string Talk() const;
            };

            std::string Dog::Talk() const {
                return "Woof";
            }

            int main() {
                Dog dog;
                assert(dog.Talk() == "Woof");
            }
            ```

    * Override  

        * "Overriding" a function occurs when a derived class defines the implementation of a `virtual` function that it inherits from a base class.

        * It is possible, but not required, to specify a function declaration as `override`.

        * ```cpp
            class Shape {
                public:
                    virtual double Area() const = 0;
                    virtual double Perimeter() const = 0;
            };

            class Circle : public Shape {
                public:
                    Circle(double radius) : radius_(radius) {}
                    double Area() const override { return pow(radius_, 2) * PI; } // specified as an override function
                    double Perimeter() const override { return 2 * radius_ * PI; } // specified as an override function

                private:
                    double radius_;
            };
            ```

        * This specification tells both the compiler and the human programmer that the purpose of this function is to override a virtual function. The compiler will verify that a function specified as `override` does indeed override some other virtual function, or otherwise the compiler will generate an error.

        * Specifying a function as `override` is good practice, as it empowers the compiler to verify the code, and communicates the intention of the code to future users.

        * ```cpp
            #include <assert.h>
            #include <cmath>

            // TODO: Define PI
            #define PI 3.14159

            // TODO: Declare abstract class VehicleModel
            class VehicleModel {
                // TODO: Declare virtual function Move()
                virtual void Move(double v, double phi) = 0;
            };

            // TODO: Derive class ParticleModel from VehicleModel
            class ParticleModel : public VehicleModel {
                public:
                    // TODO: Override the Move() function
                    void Move(double v, double phi) override {
                        theta += phi;
                        x += v * cos(theta);
                        y += v * sin(theta);
                    }
                    // TODO: Define x, y, and theta
                    double x = 0;
                    double y = 0;
                    double theta = 0;
            };

            // TODO: Derive class BicycleModel from ParticleModel
            class BicycleModel : public ParticleModel {
                public:
                    // TODO: Override the Move() function
                    void Move(double v, double phi) override {
                        theta += v / L * tan(phi);
                        x += v * cos(theta);
                        y += v * sin(theta);
                    }
                    // TODO: Define L
                    double L = 1;
            };

            // TODO: Pass the tests
            int main() {
                // Test function overriding
                ParticleModel particle;
                BicycleModel bicycle;
                particle.Move(10, PI / 9);
                bicycle.Move(10, PI / 9);
                assert(particle.x != bicycle.x);
                assert(particle.y != bicycle.y);
                assert(particle.theta != bicycle.theta);
            }
            ```

    * Multiple Inheritance
        * In this exercise, you'll get some practical experience with multiple inheritance. If you have class Animal and another class Pet, then you can construct a class Dog, which inherits from both of these base classes. In doing this, you are able to incorporate attributes of multiple base classes.

        * The Core Guidelines have some worthwhile recommendations about how and when to use multiple inheritance:
            * ["Use multiple inheritance to represent multiple distinct interfaces"](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c135-use-multiple-inheritance-to-represent-multiple-distinct-interfaces)
            * ["Use multiple inheritance to represent the union of implementation attributes"](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c136-use-multiple-inheritance-to-represent-the-union-of-implementation-attributes)
        
        * ```cpp
            #include <iostream>
            #include <string>
            #include <assert.h>

            class Animal {
                public:
                    double age;
            };

            class Pet {
                public:
                    std::string name;
            };

            // Dog derives from *both* Animal and Pet
            class Dog : public Animal, public Pet {
                public:
                    std::string breed;
            };

            class Cat : public Animal, public Pet {
                public:
                    std::string color;
            };

            int main()
            {
                /*
                Cat cat;
                cat.color = "black";
                cat.age = 10;
                cat.name = "Max";
                */
                assert(cat.color == "black");
                assert(cat.age == 10);
                assert(cat.name == "Max");
            }
            ```

* Generic Programming / Templates

    * Templates

        * Templates enable generic programming by generalizing a function to apply to any class. Specifically, templates use types as parameters so that the same implementation can operate on different data types.

        * For example, you might need a function to accept many different data types. The function acts on those arguments, perhaps dividing them or sorting them or something else. Rather than writing and maintaining the multiple function declarations, each accepting slightly different arguments, you can write one function and pass the argument types as parameters. At compile time, the compiler then expands the code using the types that are passed as parameters.

        * ```cpp
            template <typename Type> Type Sum(Type a, Type b) { return a + b; }

            int main() { std::cout << Sum<double>(20.0, 13.7) << "\n"; }    
            ```
        
        * Because Sum() is defined with a template, when the program calls Sum() with doubles as parameters, the function expands to become:
            
            * ```cpp
                double Sum(double a, double b) {
                    return a+b;
                }
                ```
        
        * Or in this case:

            * ```cpp
                std::cout << Sum<char>(‘Z’, ’j’) << "\n";
                ```
        
        * The program expands to become:

            * ```cpp
                char Sum(char a, char b) {
                    return a+b;
                }
                ```
    
    * We use the keyword `template` to specify which function is generic. Generic code is the term for code that is independent of types. It is mandatory to put the `template<>` tag before the function signature, to specify and mark that the declaration is generic.

    * Besides `template`, the keyword `typename` (or, alternatively, `class`) specifies the generic type in the function prototype. The parameters that follow typename (or class) represent generic types in the function declaration.

    * In order to instantiate a templatized class, use a templatized constructor, for example: ```Sum<double>(20.0, 13.7)```. You might recognize this form as the same form used to construct a vector. That's because vectors are indeed a generic class!

    * ```cpp
        #include <assert.h>

        // TODO: Create a generic function Product that multiplies two parameters
        template <typename T>
        T Product(T a, T b) {
            return a * b;
        }

        int main() { 
            assert(Product<int>(10, 2) == 20); 
        }
        ```
    
    * C++ 20 has a new feature for generic programming called `concept`. Class templates, function templates, and non-template functions (typically members of class templates) may be associated with a constraint, which specifies the requirements on template arguments, which can be used to select the most appropriate function overloads and template specializations.

    * Named sets of such requirements are called concepts. Each concept is a predicate, evaluated at compile time, and becomes a part of the interface of a template where it is used as a constraint:

    * ```cpp
        #include <string>
        #include <cstddef>
        #include <concepts>
        
        // Declaration of the concept "Hashable", which is satisfied by any type 'T'
        // such that for values 'a' of type 'T', the expression std::hash<T>{}(a)
        // compiles and its result is convertible to std::size_t
        template<typename T>
        concept Hashable = requires(T a) {
            { std::hash<T>{}(a) } -> std::convertible_to<std::size_t>;
        };
        
        struct meow {};
        
        // Constrained C++20 function template:
        template<Hashable T>
        void f(T) {}
        //
        // Alternative ways to apply the same constraint:
        // template<typename T>
        //    requires Hashable<T>
        // void f(T) {}
        //
        // template<typename T>
        // void f(T) requires Hashable<T> {}
        
        int main() {
        using std::operator""s;
        f("abc"s); // OK, std::string satisfies Hashable
        //f(meow{}); // Error: meow does not satisfy Hashable
        }

        ```
    
    * ```cpp
        #include <assert.h>

        // TODO: Declare a generic, templatized function Max()
        template <typename T> T Max(T a, T b) {
            return a > b ? a : b;
        }

        int main() { 
            assert(Max(10, 50) == 50);
            assert(Max(5.7, 1.436246) == 5.7);
        }
        ```

* Deduction

    * In this example, you will see the difference between total and partial deduction.

    * Deduction occurs when you instantiate an object without explicitly identifying the types. Instead, the compiler "deduces" the types. This can be helpful for writing code that is generic and can handle a variety of inputs.

    * ```cpp
        #include <assert.h>

        // TODO: Declare a generic, templatized average function
        template <typename T> T average(T a, T b) { return (a+b)/2; }

        int main() { assert(average(2.0,5.0) == 3.5); }
        ```
    
* Exercise

    * ```cpp
        #include <assert.h>
        #include <string>
        #include <sstream>

        // TODO: Add the correct template specification
        template <typename KeyType, typename ValueType>
        class Mapping {
            public:
                Mapping(KeyType key, ValueType value) : key(key), value(value) {}
                std::string Print() const {
                    std::ostringstream stream;
                    stream << key << ": " << value;
                    return stream.str();
                }
                KeyType key;
                ValueType value;
        };

        // Test
        int main() {
            Mapping<std::string, int> mapping("age", 20);
            assert(mapping.Print() == "age: 20");
        }
        ```