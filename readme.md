**Under Development**

**Pull requests other from the maintainers will be closed**

# CUHKSZ C++ Library

[![Build Status](https://travis-ci.org/cuhkshenzhen/CUHKSZLib.svg?branch=master)](https://travis-ci.org/cuhkshenzhen/CUHKSZLib)
[![Build status](https://ci.appveyor.com/api/projects/status/634a6wrw9xheiu0e/branch/master?svg=true)](https://ci.appveyor.com/project/alesiong/cuhkszlib-cmxvy/branch/master)

## Requirements
1. cmake >= 2.8
2. make
3. gcc/clang/msvc(2015+)

## Usage
### Compile
#### macOS and Linux
First clone the repository:
```
git clone --recursive https://github.com/cuhkshenzhen/CUHKSZLib.git
```
Then configure and compile:
```
mkdir build && cd build
cmake ..
make -j4
```
#### Windows (MSVC)
1. Download and install `cmake` from https://cmake.org/download/, make sure to choose the windows installer.
2. Make sure you have installed the Visual Studio with C++ component and it works.
3. Clone or download this repository 
4. Open Cmake GUI, choose this repository as source and `CUHKSZLib/build` as build. (TODO: details and pics to be added)
5. Click `Configure`, and then click `Open Project`
6. Build with Visual Studio.

### Generate Documentation with Doxygen
#### macOS
1. Install brew
2. Run `brew install doxygen`
3. Make a directory called `build`
4. Run `doxygen Doxyfile` in the repository root.
5. Open `build/doc-build/html/index.html` with browser.

### Use with your code
The library file is the `build/libcuhkszlib.a`, and the include directory
is `src/include`. So add `src/include` into your inlcude path and `build/` to
your lib search path. And add `-lcuhkszlib` to your link flags.
