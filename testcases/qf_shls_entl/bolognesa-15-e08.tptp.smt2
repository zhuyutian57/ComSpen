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

(assert 
		(and 
			(= nil nil)
		(sep 
			(ls x13 x11 )
			(ls x8 x10 )
			(pto x4 (c_Sll_t x9 ))
			(ls x6 x13 )
			(pto x10 (c_Sll_t x4 ))
			(pto x2 (c_Sll_t x6 ))
			(pto x14 (c_Sll_t x11 ))
			(pto x11 (c_Sll_t x9 ))
			(pto x12 (c_Sll_t x3 ))
			(ls x9 x12 )
			(ls x5 x3 )
			(pto x15 (c_Sll_t x2 ))
			(ls x7 x8 )
			(ls x1 x4 )
			(ls x3 x5 )
		)

		)

)

(assert (not 
		(sep 
			(ls x14 x11 )
			(ls x15 x6 )
			(ls x1 x4 )
			(ls x6 x9 )
			(ls x7 x5 )
			(ls x5 x3 )
		)

))

(check-sat)
