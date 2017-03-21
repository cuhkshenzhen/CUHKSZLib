# CUHKSZ C++ Library

[![Build Status](https://travis-ci.com/cuhkshenzhen/CUHKSZLib.svg?token=kxDsMLq7xgDRN8B69SQ6&branch=master)](https://travis-ci.com/cuhkshenzhen/CUHKSZLib)

## Requirements
1. cmake >= 2.8
2. make
3. gcc/clang

## Usage
### Compile
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

### Use with your code
The library file is the `build/libcuhkszlib.a`, and the include directory
is `src/include`. So add `src/include` into your inlcude path and `build/` to
your lib search path. And add `-lcuhkszlib` to your link flags.
