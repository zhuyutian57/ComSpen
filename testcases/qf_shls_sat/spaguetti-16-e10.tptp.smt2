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
			;(distinct in out)
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

(assert 
		(and 
			(= nil nil)
			(distinct x6 x16)
			(distinct x6 x9)
			(distinct x6 x14)
			(distinct x3 x8)
			(distinct x3 x16)
			(distinct x7 x16)
			(distinct x7 x9)
			(distinct x7 x12)
			(distinct x9 x10)
			(distinct x9 x13)
			(distinct x9 x14)
			(distinct x2 x4)
			(distinct x2 x15)
			(distinct x8 x11)
			(distinct x8 x14)
			(distinct x4 x6)
			(distinct x4 x10)
			(distinct x1 x11)
			(distinct x1 x3)
			(distinct x1 x10)
			(distinct x1 x12)
			(distinct x10 x15)
			(distinct x5 x11)
		(sep 
			(ls x5 x15 )
			(ls x5 x9 )
			(ls x4 x10 )
			(ls x1 x14 )
			(ls x1 x13 )
			(ls x8 x6 )
			(ls x12 x16 )
			(ls x12 x7 )
			(ls x7 x15 )
			(ls x7 x13 )
			(ls x3 x7 )
		)

		)

)

(check-sat)
