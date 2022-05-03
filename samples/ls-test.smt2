(set-logic QF_SLID_LC)

; Sorts for locations, one by cell sort
(declare-sort Loc 0)

; Types of cells in the heap
(declare-heap (Loc SetRef))

(declare-fun next () (Field Loc Loc))
(declare-fun data () (Field Loc Int))

(define-fun-rec lseg ((?x Loc) (?y Loc)) Bool
	(or
		(and
			(= ?x ?y)
			(tobool emp)
		)
		(exists ((?z Loc))
			(tobool
				(ssep
					(pto ?x (ref next ?z))
					(tospace (lseg ?z ?y))
				)
			)
		)
	)
)
 
;; variables
(declare-const x Loc)
(declare-const y Loc)
(declare-const z Loc)
(declare-const n Loc)
(declare-const w Int)

(assert
(tobool
	(ssep
		(tospace (lseg x y))
		(pto y (sref (ref data w) (ref next z)))
		(tospace (lseg z n))
	)
)
)

(check-sat)