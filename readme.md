# Proposal for Project - CUHKSZ C++ Library

## Background & Problems

We used Stanford C++ library in this semester, however, this library has several shortcomings:

1. This library is not precompiled, so the user needs to re-compile the whole library for each new project.
2. This library requires qmake for Makefile generating, and qmake requires the whole Qt package (for size around 1GB). But in fact, the library has nothing to do with the Qt library; the only thing it needs is qmake tool.
    - This 'requirement problem' is even more severe on macOS - Qt package requires Xcode on mac, so that we need to install Xcode + Qt (totally about 8GB) to use this small library.
    - The .pro file it provides seems to have some problems as many students encounters weird error messages when they try to use it with Qt Creator.
3. This library does not support Windows x64, as it is written for the gcc compatible toolchain. (Not exactly, but there is some code in the library which can only compile on 32bit Windows with mingw32).
4. This library is not stand-alone, i.e. it needs an extra jdk environment to run the program.

## Solution

We want to design and implement a C++ library that overcome those shortcomings and make some other improvements.

## Benefits

1. The library will be able to statically or dynamically link to the executable files.
2. The library  will have a minimized requirement. We will try to limit the use of external libraries especially the big ones.
3. The library  will use `cmake` to support as many platforms as possible. The code willl not target on certain platform and the library will be tested on different systems before publishing. Also, the library will not target on certain IDE, it can generate project files or makefiles for different building toolchains.
4. The library  will be written totally in C++/C, it does not need special environment (especially java or python, etc.) to run.
5. We will add some useful but simple functionalities, so this library can be used by CSC3002 students in the future.

## Implementations

1. The functionalities that the standard library has will not be included, and we will make a user friendly or simple interface for the standard library.
2. Be consistent in code style, especially the public interface (e.g. class names, free function names).
3. Eliminate the use of C++ exceptions. C++ is not java: its supports for exceptions is not as user friendly as java. So the use of exceptions should be limited inside the library; do not leak the exceptions to the user.

### Functionalities

1. Simpler interface for standard library
    1. Containers
        1. vector
        2. linked list
        3. queue and stack
        4. map and multimap (ordered and unordered)
        5. set and multiset
        6. priority_queue (heap)
    2. Utility functions
        1. Array utils
        2. IO helper
        3. string functions

2. Safer random library with simple interface ([reference](http://en.cppreference.com/w/cpp/numeric/random))
    1. distributions

3. math functions
    1. gcd/lcm
    2. pow for int

4. More Data structure
    1. math
        1. matrix
        2. 2D&3D space with Cartesian coordinates and polarcoordinates
            1. point
            2. vector
            3. polygon
            4. circle
        3. graph
            1. point
            2. edge
        4. BigNum
        5. fraction
    2. string
        1. Trie (prefix tree)
        2. *suffix array* *(postponed)*
        3. *Aho-Corasick automation* *(postponed)*
    3. others
        1. normal rooted tree
        2. binary tree
        3. segment tree
        4. binary indexed tree
        5. binary search tree
        6. Disjoint-set data structure (并查集)

5. *build autograder (postponed) (We actually don't know what's that)*
6. *threading library (postponed)*
    1. *simple threading/tasking*
    2. *thread pool*

7. Algorithms
    1. *Parallel algorithms (postponed)*
    2. KMP algorithm
    3. DFS & BFS algorithm
    4. Simpson algorithm
    5. General sort function
    6. *Hungary algorithm (postponed)*
    7. (grab common algorithms out)

8. Utils
    1. zip
    2. json
    3. Network
        1. get
        2. post
        3. urlencode / urldecode
    4. base64 encoder & decoder ([reference](http://libb64.sourceforge.net/)))

### Specs

1. Implements with C++11
2. `cmake`
3. Can be precompiled
4. Cross-platform

## Schedule

1. Learn to use git
2. Decide coding style
3. Design library (prototypes)
4. Implement library
5. Learn and use unit test (e.g. googletest)
6. Learn cmake
7. Build publish version & Generate Documents
8. Final test

###  Assignment of responsibility
#### Pengfei YU		
- Safer random library
- string
- math functions
- KMP algorithm

#### Xiaoxing YE
- Utils

#### Xianggang YU (115010273)
- Simpler interface for standard library

#### Xuan HUANG
- math
- others
- DFS & BFS algorithm

## Other mentions

This library will become open source after this semester (to be posted on Github),so everyone including students, professors and TAs can make their contribution to the library to make it better and better.

Contribution: https://github.com/cuhkshenzhen/CUHKSZLib
**Not Available Now**

1. If we do not use Qt or java backend, it may be very hard to have GUI support part in our library.
2. We cannot develop a library as the same level as theStanford one in such short time. So this project is intended to be continuously developed.
