(theory QF_SLID_TYPED

 :sorts ((Field 2) (SetRef 1))

 :funs(
   (emp Bool)
   (ssep Bool Bool :left-assoc)
   (par (X) (pto X (SetRef X) Bool :left-assoc))
   (par (X X) (blk X X Bool))
   (par (X Y) (ref (Field X Y) Y (SetRef X)))
   (par (X) (sref (SetRef X) (SetRef X) (SetRef X) :left-assoc))
 )

 :notes "The generic -- program independent -- signature for the QF_SLID_LC logic."

 :definition
  "The QF_SLID_LC theory corresponds to signature of the typed QF_SLID_LC logic in which:
  - the sort Field denotes the set of reference fields defined in the program; a reference field is typed by two sorts, thus its arity is 2;
  - the sort SetRef denotes the set of typed location variables;

  - for all sp in Space, v is a location variable, sr in SetRef, f in Field:

    - emp denotes the empty heap space constraint;

    - (ssep sp sp) denotes the strong separating space constraint;

    - (pto v sr) denotes the points-to space constraint from location v;

    - (ref f v) denotes the tuple used in a points-to constraint, where f is a reference field which value is v, type is a set;

    - (sref sr sr) denotes the union of sets of tuples used in the points-to constraint;
  "

)
