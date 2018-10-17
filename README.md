# WELCOME TO THE CLEAN 'EM ALL REPO!

## INTRODUCTION:
**What is this repository all about?**  
This repository is an implementation of the ten pin bowling game.
It provides abstraction layers such as a game class, frame class and a ball class.

A typical ten pin game will contain 1 instance of a game class for each player.
Within that class, will be 10 instances of the frame class and each frame
instance will consist of atleast 2 ball class instances.

This repo is an improvement of the previous 'knock_em_all' repo as it has more abstraction layers
and loose coupling between these abstraction layers.

**Why should I care about this repository?**  
Ever ran into the trouble where the original specifications of the project suddenly changed?
Such decisions involve substantial amounts of changes to the code and often these changes
are not straightforward because of the tight coupling with the specifications.

The implementation methodology contained in this repo creates several abstraction layer which
makes it super easy to make changes! Code written in this way allows for great flexibility in line with Agile philosphies.

Don't believe me? Just check out the 'knock_em_all' repo and ask yourself the following questions:
- If I wanted to change the number of balls balled in each frame, which code in which repo would I prefer to change/which one would be easier?
- For a children's version of the game - if the game is required to have 4 frames instead of 10, how easy would it be to change the code in each repo to achieve this?
- If strikes involved adding the next 3 balls instead of 2, which code base is faster to change?

### Generic Build Instructions

#### Setup

To build this project, you need to tell your build system where to find the headers
and source files not only for this project but also the Google Test framework.
The exact way to do it depends on which build system you use, and is usually straightforward.

#### Build

Simply run `make` in the root directory. Note that the compiler needs to be g++.
For more information on how to use other compilers see <https://github.com/google/googletest/tree/master/googletest>.

#### Building Google Test Framework

Suppose you put Google Test in directory `${GTEST_DIR}`. To build it, create a
library build target (or a project as called by Visual Studio and Xcode) to
compile

    ${GTEST_DIR}/src/gtest-all.cc

with `${GTEST_DIR}/include` in the system header search path and `${GTEST_DIR}`
in the normal header search path. Assuming a Linux-like system and gcc,
something like the following will do:

    g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} \
        -pthread -c ${GTEST_DIR}/src/gtest-all.cc
    ar -rv libgtest.a gtest-all.o

(We need `-pthread` as Google Test uses threads.)

Next, you should compile your test source file with `${GTEST_DIR}/include` in
the system header search path, and link it with gtest and any other necessary
libraries:

    g++ -isystem ${GTEST_DIR}/include -pthread path/to/your_test.cc libgtest.a \
        -o your_test

As an example, the make/ directory contains a Makefile that you can use to build
Google Test on systems where GNU make is available (e.g. Linux, Mac OS X, and
Cygwin). It doesn't try to build Google Test's own tests. Instead, it just
builds the Google Test library and a sample test. You can use it as a starting
point for your own build script.

If the default settings are correct for your environment, the following commands
should succeed:

    cd ${GTEST_DIR}/make
    make
    ./sample1_unittest

If you see errors, try to tweak the contents of `make/Makefile` to make them go
away. There are instructions in `make/Makefile` on how to do it.
