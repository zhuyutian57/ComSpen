(logic QF_SLID_TYPED

 :theories (Ints QF_SLID_TYPED)

 :language
 "Closed quantifier-free formulas built over the SepLogicTyped signature,
  with the following restrictions:
  - formulas are only conjunction of pure or spatial atoms, i.e., 
    they belong to the symbolic heap fragment,
  - 'wand' is not used, and
  - the inductively defined predicates are `well formed` like in SMT-LIB standard,
  - integers may apear as content of the heap and parameters of predicates,
  - only linear constraints are allowed on integers.
 "

 :extensions 
 "Possible extensions are:
 
  - boolean combination of atoms,
  
  - magic wand.
  "
)

