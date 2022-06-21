# cpp-fmt-proxy

Experimental third party proxy of fmt.

## Usage

Generate build files:

```console
❯ cmake -S . -B build
# ...
```

Build (in parallel):

```console
❯ cmake --build build --parallel 2
[ 28%] Building CXX object examples/CMakeFiles/basic.dir/basic.cpp.o
[ 28%] Building CXX object _deps/fmt-build/CMakeFiles/fmt.dir/src/format.cc.o
[ 42%] Linking CXX executable basic
[ 42%] Built target basic
[ 57%] Building CXX object _deps/fmt-build/CMakeFiles/fmt.dir/src/os.cc.o
[ 71%] Linking CXX static library libfmt.a
[ 71%] Built target fmt
[ 85%] Building CXX object CMakeFiles/fmt_test.dir/main.cpp.o
[100%] Linking CXX executable fmt_test
[100%] Built target fmt_test
```

Execute tests:

```console
❯ build/fmt_test
[doctest] doctest version is "2.4.4"
[doctest] run with "--help" for options
===============================================================================
[doctest] test cases: 1 | 1 passed | 0 failed | 0 skipped
[doctest] assertions: 1 | 1 passed | 0 failed |
[doctest] Status: SUCCESS!
```

Execute basic example:

```console
❯ build/examples/basic
Hello, 42!
```
## Status

Experimental.

**Note**: The default branch is `default`.
