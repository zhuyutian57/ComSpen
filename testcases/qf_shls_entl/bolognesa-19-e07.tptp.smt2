(set-logic QF_SLID_INT)

(set-info :source |
A. Rybalchenko and J. A. Navarro Perez.
[Separation Logic + Superposition Calculus = Heap Theorem Prover]
[PLDI 2011]
http://navarroj.com/research/papers.html#pldi11
|)
(set-info :smt-lib-version 2.0)
(set-info :category "random") 
(set-info :status sat)
(set-info :version "2014-05-28")

; Sorts for locations, one by cell sort
(declare-sort RefSll_t 0)

; Types of cells in the heap

(declare-datatypes (
	(Sll_t 0)
	) (
	((c_Sll_t (next RefSll_t) ))
	)
)

; Type of heap

(declare-heap (RefSll_t Sll_t) 
)

(define-fun-rec ls ((in RefSll_t)(out RefSll_t)) Bool
	(or 
		(and 
			(= in out)
			(_ emp RefSll_t Sll_t)
		)

		(exists ((u RefSll_t))
	 
		(and 
			;;(distinct in out)
		(sep 
			(pto in (c_Sll_t u ))
			(ls u out )
		)

		)

		)

	)
)


 
;; variables
(declare-const x0 RefSll_t)
(declare-const x1 RefSll_t)
(declare-const x2 RefSll_t)
(declare-const x3 RefSll_t)
(declare-const x4 RefSll_t)
(declare-const x5 RefSll_t)
(declare-const x6 RefSll_t)
(declare-const x7 RefSll_t)
(declare-const x8 RefSll_t)
(declare-const x9 RefSll_t)
(declare-const x10 RefSll_t)
(declare-const x11 RefSll_t)
(declare-const x12 RefSll_t)
(declare-const x13 RefSll_t)
(declare-const x14 RefSll_t)
(declare-const x15 RefSll_t)
(declare-const x16 RefSll_t)
(declare-const x17 RefSll_t)
(declare-const x18 RefSll_t)
(declare-const x19 RefSll_t)
(declare-const x20 RefSll_t)
(declare-const x21 RefSll_t)
(declare-const x22 RefSll_t)
(declare-const x23 RefSll_t)

(assert 
		(and 
			(= nil nil)
		(sep 
			(pto x19 (c_Sll_t x14 ))
			(ls x12 x2 )
			(pto x15 (c_Sll_t x17 ))
			(ls x16 x11 )
			(ls x10 x1 )
			(ls x5 x10 )
			(pto x4 (c_Sll_t x8 ))
			(pto x9 (c_Sll_t x19 ))
			(ls x17 x11 )
			(pto x14 (c_Sll_t x16 ))
			(pto x7 (c_Sll_t x19 ))
			(pto x11 (c_Sll_t x8 ))
			(ls x8 x13 )
			(pto x2 (c_Sll_t x19 ))
			(ls x1 x18 )
			(pto x13 (c_Sll_t x8 ))
			(pto x6 (c_Sll_t x18 ))
			(ls x3 x1 )
			(pto x18 (c_Sll_t x8 ))
		)

		)

)

(assert (not 
		(sep 
			(ls x4 x8 )
			(ls x15 x17 )
			(ls x7 x19 )
			(ls x6 x18 )
			(ls x3 x1 )
			(ls x13 x8 )
			(ls x12 x19 )
			(ls x5 x10 )
			(ls x17 x11 )
			(ls x10 x8 )
			(ls x9 x13 )
		)

))

(check-sat)
