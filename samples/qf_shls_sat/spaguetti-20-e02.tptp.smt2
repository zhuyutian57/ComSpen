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
(declare-const x21 RefSll_t)
(declare-const x22 RefSll_t)
(declare-const x23 RefSll_t)
(declare-const x24 RefSll_t)

(assert 
		(and 
			(= nil nil)
			(distinct x6 x13)
			(distinct x11 x14)
			(distinct x3 x7)
			(distinct x7 x10)
			(distinct x7 x14)
			(distinct x9 x11)
			(distinct x17 x19)
			(distinct x12 x18)
			(distinct x12 x17)
			(distinct x2 x11)
			(distinct x2 x19)
			(distinct x2 x17)
			(distinct x14 x16)
			(distinct x1 x3)
			(distinct x4 x17)
			(distinct x10 x19)
			(distinct x10 x17)
			(distinct x10 x15)
			(distinct x13 x18)
			(distinct x13 x17)
			(distinct x5 x7)
			(distinct x5 x20)
		(sep 
			(ls x13 x10 )
			(ls x16 x10 )
			(ls x10 x19 )
			(ls x18 x14 )
			(ls x1 x20 )
			(ls x14 x3 )
			(ls x15 x14 )
			(ls x17 x10 )
			(ls x7 x10 )
			(ls x3 x20 )
			(ls x11 x2 )
			(ls x11 x8 )
			(ls x6 x2 )
		)

		)

)

(check-sat)
