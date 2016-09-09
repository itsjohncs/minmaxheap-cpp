# Min-Max Heap
This is a Min-Max Heap implementation written in C++. I give no
guarentees of correctness. Check out the
[issue tracker](https://github.com/brownhead/minmaxheap-cpp/issues)
for any known problems.

See my blog post for an explanation of this project:
http://forestofcode.blogspot.com/2010/12/c-min-max-heap-implementation.html

## Using
Just copy or link MinMaxHeap.hpp into your source tree and include
MinMaxHeap.hpp in your code to use. There are no dependencies beyond the
standard library.

## Testing
The test cases depend on google-test. You will have to install and build this
yourself (sorry!). Make sure to create a directory or link in this directory
named gtest/ that includes the files libgtest.a, libgtest_main.a and an include/
directory containing another directory gtest/ that contains all of the gtest
header files. Once you've built google-test this should make more sense. It's
not too difficult.

Once the dependencies are taken care of, run scons in this directory and the
test cases will be built to test. Then just run ./test. If any of the tests
fail something is wrong, if you track it down please submit an issue on github.

## Building Docs
If you have doxygen installed, run scons doc/ in this directory to build the
documentation.

