(set-logic QF_SLID_TYPED)

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
			(_ emp Loc SetRef)
		)
		(exists ((?z Loc))
			(ssep
				(pto ?x (ref next ?z))
				(lseg ?z ?y)
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
(declare-const a Loc)
(declare-const b Loc)
(declare-const c Loc)
(declare-const d Loc)
(declare-const e Loc)

(assert
  (and
    (not (or (<= a b) (< c d) (>= e a) (> b c)))
    (distinct x y)
    (ssep
      (blk x y)
      (pto y (ref data w))
      (blk z n)
    )
  )
)

(check-sat)