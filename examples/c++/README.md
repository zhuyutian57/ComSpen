A small example for each solver in C++.
To build the example, please install ComSpen for your system first.
```sh
mkdir build
cd build
cmake -DZ3_DIR=<path_to_Z3Config.cmake> ..
make
```
Please note that the cmake configuration of *z3* is also required here for cmake command, unless the configuration can be found by cmake *find_package*.