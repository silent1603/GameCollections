![Static Build](https://github.com/silent1603/GameCollections/workflows/Build-Static/badge.svg)

![Shared Build](https://github.com/silent1603/GameCollections/workflows/Build-Shared/badge.svg)

## Requirements

* a modern C++17 compiler (`gcc-8`, `clang-6.0`, `MSVC 2017` or above)
* [`cmake`](https://cmake.org) 3.15+
* [`conan`](https://conan.io) 2.0+ (optional)
* `cppcheck` (optional)
* `clang-format` (optional)

## Available CMake Options

* BUILD_TESTING     - builds the tests (requires `doctest`)
* BUILD_SHARED_LIBS - enables or disables the generation of shared libraries
* BUILD_WITH_MT     - valid only for MSVC, builds libraries as MultiThreaded DLL

If you activate the `BUILD_TESTING` flag, you need to perform in advance a `conan install` step, just to fetch the `doctest` dependency. Another dependency (OpenSSL) is used in this project as a demonstration of including a third-party library in the process, but it is totally optional and you can activate it only if you run conan in advance.

## How to build from command line

The project can be built using the following commands:

```shell
cd /path/to/this/project
mkdir -p build # md build (on Windows)
cd build
conan install .. --output-folder=. --build=missing
cmake -DBUILD_TESTING=TRUE -DBUILD_SHARED_LIBS=TRUE -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
cmake --build . --target format
cmake --build . --target package
```

## How to build the project using a Docker Environment

### Linux/gcc

`docker run --rm -it -v $(pwd):/project madduci/docker-cpp-env:latest "mkdir -p build && cd build && conan install .. && cmake -DBUILD_TESTING=TRUE -DBUILD_SHARED_LIBS=TRUE .. && cmake --build ."`

### Windows/msvc

`docker run --rm -it -v $(pwd):/home/wine/.wine/drive_c/project madduci/docker-wine-msvc:16.11-2019`

and then:

```
md project/build
cd project/build
conan install .. 
cmake -G "Ninja" -DBUILD_TESTING=TRUE  ..
cmake --build .
```