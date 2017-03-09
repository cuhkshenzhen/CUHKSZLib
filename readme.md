# Proposal for Project - CUHKSZ C++ Library

**This is a draft, may change afterwards**

## Motivation
We used Stanford C++ library in this semester, however, this library has several
shortcomings:

1. This library is not precompiled, so the user needs to recompile the whole
library for each new project.
2. This library requires `qmake` for Makefile generating, and `qmake` requires
the whole Qt package (for size around 1GB). But in fact, the library has nothing
to do with the Qt library; the only thing it needs is `qmake` tool.
  * This 'requirement problem' is even more severe on macOS - Qt package
   requires Xcode on mac, so that we need to install Xcode + Qt (totally about
   8GB) to use this small library.
  * The `.pro` file it provides seems to have some problems as many students
  encounters weird error messages when they try to use it with Qt Creator.
3. This library does not support Windows x64, as it is written for the gcc
compatible toolchain. (Not exactly, but there is some code in the library which
can only compile on 32bit Windows with mingw32).
4. This library is not stand-alone, i.e. it needs an extra jdk environment to
run the program.

## Objects
We want to design and implement a C++ library that overcome those shortcomings
and make some other improvements:
### Overcoming shortcomings
1. The library should be able to statically or dynamically link to the
executable files.
2. The library should have a minimized requirement. We should try to limit the
use of external libraries especially the big ones.
3. The library should use `cmake` or other cross-platform building tools to
support as many platforms as possible. The code should not target on certain
platform and the library should be tested on different systems before publishing.
Also, the library should not target on certain IDE, it should be able to generate
project files or makefiles for different building toolchains. The environment
that should be supported are:
  1. Linux x64 (make/gcc)
  2. macOS (make/clang and Xcode)
  3. MSVC
  4. mingw32
  5. msys64 and msys32 (make/gcc)
  6. *cygwin (scheduled)*
4. The library should be totally in C++/C, which means that it is written with
C++/C and do not need special environment (especially java or python, etc.) to
run.

### General Ideas
1. Do not include those functionalities that the standard library has. Try to
make a user friendly or simple interface for the standard library.
2. This library is supposed to be used by CSC3002 students in the future, so it
should has some useful but simple functionalities.
3. Be consistent in code style, especially the public interface (e.g. class names,
  free function names).
4. Eliminate the use of C++ exceptions. C++ is not java: its supports for
exceptions is not as user friendly as java. So the use of exceptions should be
limited inside the library; do not leak the exceptions to the user.

## Plans
1. Simpler interface for standard library:
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
2. Safer random library with simple interface
 ([reference](http://en.cppreference.com/w/cpp/numeric/random))
3. math functions (like gcd)
4. More Data structure
  1. math
	1. matrix
	2. 2D&3D space with Cartesian coordinates and polar coordinates
	  1. point
	  2. vector
	  3. polynomial
	  4. circle
	3. graph
	  1. point
	  2. edge
  2. string
	1. Trie (prefix tree)
	2. suffix array
	3. Aho-Corasick automation
  3. others
  	1. normal rooted tree
	2. binary tree
	3. segment tree
	4. binary indexed tree
	5. binary search tree
	6. Disjoint-set data structure (并查集)
5. build autograder

## Specs
1. Implements with C++11
2. Can be precompiled
3. No large dependencies
4. Cross-platform

## Schedule
1. Learn to use git
2. Decide coding style
3. Design library
4. Implement library
5. Learn and use unit test (e.g. googletest)
6. Learn cmake (or other alternatives)
7. Build publish version
8. Final test

1 and 2 should last about 1 week. And 3, 4 should last about 1 month. 5, 6 should
be done along with 4. And 7, 8 will start around May.

## Other mentions
This library will become open source after this semester (to be posted on
Github), so everyone including students, professors and TAs can make their
contribution to the library to make it better and better.

## Problems
1. If we do not use Qt or java backend, it may be very hard to have GUI support
part in our library.
2. We cannot develop a library as the same level as the Stanford one in such
short time. So this project is intended to be continuously developed.
