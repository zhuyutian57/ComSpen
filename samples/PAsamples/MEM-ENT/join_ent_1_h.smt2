(set-logic QF_SLAH)

(declare-datatypes (
	(data_t 0)
	) (
	((c_data_t (sz Int)))
	)
)


(declare-heap (Int data_t) 
)

;; heap chunk
(define-fun hck ((?x Int) (?y Int)) Bool
	(and
		(>= (- ?y ?x) 2)
		(sep
			(pto ?x (c_data_t (- ?y ?x)))
			(blk (+ ?x 1) ?y)
		)
	)
)
;; heap list
(define-fun-rec hls ((?x Int) (?y Int)) Bool
	(or
		(and (= ?x ?y) (_ emp Int data_t))
		(exists ((?w Int))
			(sep
				(hck ?x ?w)
				(hls ?w ?y)
			)
		)
	)
)

;; variables
(declare-const hst Int)
(declare-const hen Int)
(declare-const x0 Int)
(declare-const sz0 Int)
(declare-const x1 Int)
(declare-const sz1 Int)
(declare-const xnxt Int)
(declare-const szall Int)

(assert
	(and

	(= szall (+ sz0 sz1))
	(= hst x0)
	(= (+ x0 sz0) x1)
	(= (+ x1 sz1) xnxt)
	(sep
		(pto x0 (c_data_t szall))
		(blk (+ x0 1) x1)
		(hck x1 xnxt)
		(hls xnxt hen)
	)
	)	)
(assert (not
	(sep
		(hck hst xnxt)
		(hls xnxt hen)
	)
))
;; end of problem
(check-sat)
;; 0.80s unsat : the entl is true
