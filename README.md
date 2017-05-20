**Under Development**

**Pull requests other from the maintainers will be closed**

# CUHKSZ C++ Library

[![Build Status](https://travis-ci.org/cuhkshenzhen/CUHKSZLib.svg?branch=master)](https://travis-ci.org/cuhkshenzhen/CUHKSZLib)
[![Build status](https://ci.appveyor.com/api/projects/status/634a6wrw9xheiu0e/branch/master?svg=true)](https://ci.appveyor.com/project/alesiong/cuhkszlib-cmxvy/branch/master)
[![codecov](https://codecov.io/gh/cuhkshenzhen/CUHKSZLib/branch/master/graph/badge.svg)](https://codecov.io/gh/cuhkshenzhen/CUHKSZLib)

## Requirements
### macOS and Linux
1. cmake (>= 2.8)
2. make
3. gcc/clang (need to have full C++11 support)

### Windows
1. cmake (>= 2.8)
2. Visual Studio (>= 2015) with C++ component OR
3. MSYS2

## Usage
### Build

#### macOS and Linux
1. Clone the repository:
```
git clone --recursive https://github.com/cuhkshenzhen/CUHKSZLib.git
```
2. Configure and compile:
```
cd CUHKSZLib
mkdir build && cd build
cmake ..
make -j4
```
Add `-DCMAKE_BUILD_TYPE=Debug` or `-DCMAKE_BUILD_TYPE=Release` flags to `cmake` to specify the build type, `-DSAMPLES=0` to disable building samples, `-DTESTING=1` to enable building tests.
3. `libcuhkszlib.a` in the `build` directory is the library file

#### Windows (MSVC)
1. Download and install `cmake` from https://cmake.org/download/, make sure to choose the windows installer.
2. Make sure you have installed the Visual Studio with C++ component and it works.
3. Download and install `git` from https://git-scm.com/downloads/, make sure to choose "Use Git from the Windows Command Prompt" during installation.
4. Clone the repository in command prompt with
```
git clone --recursive https://github.com/cuhkshenzhen/CUHKSZLib.git
```
5. Open Cmake GUI, choose this repository as source and `CUHKSZLib/build` as build. (TODO: details and pics to be added)
6. Click `Configure`, and then click `Open Project`
7. Build with Visual Studio.
8. Get the library file in the `build/Debug` or `build/Release` directory.

#### Windows (MSYS2)
1. Open "MSYS2 MinGW 64-bit" shell
2. Install the dependencies with
```
pacman -S mingw-w64-x86_64-toolchain mingw-w64-x86_64-cmake git
```
3. Clone the repository
```
git clone --recursive https://github.com/cuhkshenzhen/CUHKSZLib.git
```
4. Configure and compile:
```
cd CUHKSZLib
mkdir build && cd build
cmake .. -G "MSYS Makefiles" -DCMAKE_MAKE_PROGRAM=mingw32-make
mingw32-make -j4
```
Add `-DCMAKE_BUILD_TYPE=Debug` or `-DCMAKE_BUILD_TYPE=Release` flags to `cmake` to specify the build type, `-DSAMPLES=0` to disable building samples, `-DTESTING=1` to enable building tests.
5. `libcuhkszlib.a` in the `build` directory is the library file

### Generate Documentation with Doxygen
#### macOS
1. Install brew
2. Run `brew install doxygen`
3. Clone the repository
4. Run `doxygen Doxyfile` in the repository root.
5. Open `docs/index.html` with browser.

### Use with your code
The library file is `cuhkszlib.lib` if you use MSVC or `libcuhkszlib.a` otherwise, and the include directory is `src/include`.

You can also download our prebuilt library in the Release section on Github. The prebuilt package inclues library file in the `lib` directory and headers in the `include` directory. The MSVC versions are also shipped with a Visual Studio solution file.

If you are using IDEs other than Visual Studio, you can find the project file in `ide-project-files` directory. Currently we support CLion and Qt Creator. You need to copy the `ide-project-files/src` to your project directory.

For example, you are using Qt Creator with MinGW32 on Windows. You copy the contents of `ide-project-files/qt` directory to anywhere you like, say `my-project`. Then you also need to copy `ide-project-files/src` to `myproject` directory, so that `my-project` now has a `.pro` file and a `src` directory. Now you can download the prebuilt library: `windows-x86-mingw.zip` and unzip the contents to `my-project`.

## FAQ
1. Which prebuilt library should I choose?
> The release files are named as `os-(platform)-compiler`. So you need first to choose according to your operating system. Then if you are using windows, choose the platform(x86 for 32 bit and x64 for 64 bit) according to the **compiler** you use (not the system). (By the way, for macOS and Linux, all are for 64 bit) Finally of course, choose the compiler according to your compiler. A simple list:

| Environment                 | Package to use        |
|-----------------------------|-----------------------|
| Linux (default)             | linux-gcc             |
| macOS (default)             | macos-clang           |
| Visual Studio 2015 on win32 | windows-x86-msvc-2015 |
| Visual Studio 2015 on win64 | windows-x64-msvc-2015 |
| Qt Creator with MinGW32     | windows-x86-mingw     |
