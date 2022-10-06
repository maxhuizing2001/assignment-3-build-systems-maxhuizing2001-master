# Assignment

Your assignment is to write a *CMakeLists.txt* file that will build the *lift simulation* application. You'll also have to clean-up the directory structure a bit. 

You can see the application running by doing the following (either using `g++` or `clang++`)

```shell
clang++ -std=c++20 *.cpp -o lift_sim.a
```

Or on a Windows machine:

```shell
clang++ -std=c++20 *.cpp -o lift_sim.exe
```

And running the created executable.

Command-line compilation with `msvc` is bit more involved.

## Clean up project

Structure your project so that there are two extra folders in it:

* *src*, all the *\*.cpp* files besides *main.cpp* must be placed in it

* *inc*, all the header files must be placed in it

*main.cpp* can stay in the project's directory.

**Commit your changes with a descriptive message.**

You'll need to change the `#include` links in almost all the files if you want to compile the program using the command line at this stage.

## *CMakeLists.txt*

**You must commit your changes with a descriptive message after each step, starting with step 2.**

1. Add *CMakeLists.txt* to your main project's folder. In the next points you'll fill it with content.

2. Start with the simple:

    * define the minimum *CMake* version required

    * define the project's name and its version

    * add an executable target named `lift_sim`

    * add sources to the `lift_sim` target

    * instruct the compiler where to look for header with `include_directories` function

3. Require a specific language standard

    * add function calls that will set the required languages standard to at least C++17

    * disable compiler-specific language extensions

4. Detect the compiler, if it's `GNU`, `Clang` or `AppleClang` set a variable `GNU_COMPATIBLE` to `TRUE`, otherwise set it to `FALSE`

5. If the detected compiler is `GNU_COMPATIBLE` detect the *build type* and

    * if the *build type* is defined but it is neither *Debug* nor *Release* stop processing and signal a `FATAL_ERROR`
  
    * if there is no *build type* defined (the variable is an empty string), set it to `Debug`

6. If the detected compiler is `GNU_COMPATIBLE`, without using *generator expressions*, just with a simple `if()` statement:
    
    * enable maximum warning level possible and *pedantic* mode for all *build types*

    * enable maximum optimizations for the *Release* *build type*

    * enable debug optimizations and debug symbol generations for the *Debug* *build type*

7. If the detected compiler is `MSVC`, using *generator expressions*:

    * enable maximum warning level possible for all *configurations*

    * enable maximum optimizations for the *Release* *configurations*

    * enable debug optimizations and debug symbol generations for the *Debug* *configuration*


That's all, good luck!