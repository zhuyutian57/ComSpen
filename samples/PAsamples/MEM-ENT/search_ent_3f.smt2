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
(declare-const rsz Int)
(declare-const x0 Int)
(declare-const sz0 Int)
(declare-const x1 Int)
(declare-const sz1 Int)
(declare-const x2 Int)
(declare-const sz2 Int)
(declare-const x3 Int)
(declare-const sz3 Int)
(declare-const xnxt Int)

(assert
	(and
	(distinct hst hen)
	(= hst x0)
	(= (+ x0 sz0) x1)
	(< sz0 rsz)
	(= (+ x1 sz1) x2)
	(< sz1 rsz)
	(= (+ x2 sz2) x3)
	(< sz2 rsz)
	(= (+ x3 sz3) xnxt)
	(>= sz3 rsz)
	(sep
		(pto x0 (c_data_t sz0))
		(blk (+ x0 1) x1)
		(pto x1 (c_data_t sz1))
		(blk (+ x1 1) x2)
		(pto x2 (c_data_t sz2))
		(blk (+ x2 1) x3)
		(pto x3 (c_data_t sz3))
		(blk (+ x3 1) xnxt)
		(hls xnxt hen)
	)
	)	)
(assert (not
	(sep
		(hls hst xnxt)
		(hls xnxt hen)
	)
))
;; end of problem
(check-sat)
;; 2.08s unsat : the entl is true
