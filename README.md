# ComSpen(Compositional SPEN)
A solver for the symbolic heap fragment of SL with compositional ID. It also supports linear integer arithmetics.

## Installation
Required libraries:
- [z3](https://github.com/Z3Prover/z3/blob/master/README-CMake.md)

  The tool is built using CMake, so install z3 by CMake is necessary.
- Boost

Then, you can build ComSpen by CMake, like
```sh
mkdir build
cd build
cmake ..
make
sudo make install
```
**Notes**: If z3 can be found by CMake, "-DZ3_DIR" can be ignored, otherwise you should tell cmake how to find z3 configuration. In my system, the path to configuration **folder** is "/usr/local/lib/cmake/z3/".

## Running ComSpen
The tool receive *smt* formula and return **sat** or **unsat** for the satisfiability problems and entailment problems.
- **sat**: *true* for satisfiability problems.
- **unsat**: *true* for entailment problems.

The command is
```sh
./ComSpen <input_file>
```
For example,
```sh
./ComSpen ../samples/qf_shls_sat/spaguetti-10-e01.tptp.smt2

file: ../samples/qf_shls_sat/spaguetti-10-e01.tptp.smt2
THEORY path: ../logic_def/Theories/Core.smt2
THEORY path: ../logic_def/Theories/Ints.smt2
THEORY path: ../logic_def/Theories/SepLogicTyped.smt2
logic: QF_SLID_INT
Heap: 
RefSll_t -> Sll_t
predicate: 
pars: 
in out 
base: (and (= in out))
rec: (exists ((u RefSll_t))
  (! (and (sep (pto in (c_Sll_t u)) (ls u out))) :weight 0))
pto: (pto in (c_Sll_t (:var 0)))
recursive app: (ls (:var 0) out)
data formula: and
phi: (and (= nil nil)
     (distinct x1 x6)
     (distinct x1 x7)
     (distinct x1 x10)
     (distinct x4 x8)
     (distinct x4 x7)
     (distinct x4 x9)
     (distinct x3 x8)
     (distinct x7 x10)
     (distinct x2 x6)
     (distinct x2 x3)
     (distinct x2 x7)
     (sep (ls x5 x7)
          (ls x2 x5)
          (ls x2 x10)
          (ls x2 x1)
          (ls x9 x1)
          (ls x7 x6)
          (ls x3 x10)
          (ls x6 x9)))
psi: null
result: unsat
```

## API
If you want to use our solvers, you can just include API header in you source files and use *find_package* to include *.so* file. See [examples](examples/).
