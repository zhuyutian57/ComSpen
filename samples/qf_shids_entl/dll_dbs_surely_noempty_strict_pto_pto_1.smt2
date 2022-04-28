(set-logic QF_SLID_SET)

; Sorts for locations, one by cell sort
(declare-sort RefDll_t 0)

; Types of cells in the heap

(declare-datatypes (
	(Dll_t 0)
	) (
	((c_Dll_t (next RefDll_t) (prev RefDll_t) (data Int) ))
	)
)

; Type of heap

(declare-heap (RefDll_t Dll_t) 
)
; User defined predicate
(define-fun-rec sdll ((?E RefDll_t)(?P RefDll_t)(?S SetInt)(?F RefDll_t)(?L RefDll_t)(?S1 SetInt)) Bool
	(or 
		(and 
			(= ?E ?F)
			(= ?P ?L)
			(= ?S ?S1)
			(_ emp RefDll_t Dll_t)
		)

	(exists ((?u RefDll_t)(?S2 SetInt))
	 
		(and 
			(= ?S (setunion ?S2 (set (min ?S))))
			(= (min ?S2) (+ (min ?S) 1))
		(sep 
			(pto ?E (c_Dll_t ?u ?P  (min ?S)))
			(sdll ?u ?E ?S2 ?F ?L ?S1 )
		)

		)

		)

	)
	)

;; variables
(declare-const S1 SetInt)
(declare-const S2 SetInt)
(declare-const S3 SetInt)
(declare-const S4 SetInt)
(declare-const S SetInt)

(declare-const E RefDll_t)
(declare-const E1 RefDll_t)
(declare-const E2 RefDll_t)
(declare-const F RefDll_t)
(declare-const F1 RefDll_t)

(assert 
		(and 
			(= E2 F1)
			(= S3 (setunion S4 (set (min S3))))
			(= S1 (setunion S3 (set (min S1))))
			(= (min S3) (+ (min S1) 1))
			(= (min S4) (+ (min S3) 1))
		(sep 
			(pto E (c_Dll_t E2 E1 (min S2)))
			(pto E2 (c_Dll_t F E (min S3)))
		)
		)

)

(assert (not
	(and
		(distinct E F)	
		(sep 
			(sdll E E1 S1 F F1 S4)
		)
	)
))

(check-sat)
