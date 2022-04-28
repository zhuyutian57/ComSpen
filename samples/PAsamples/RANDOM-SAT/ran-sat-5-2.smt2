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
(define-fun hck ((?x Int) (?y Int) (?v Int)) Bool
	(and
		(>= (- ?y ?x) 2) (<= (- ?y ?x) ?v)
		(sep
			(pto ?x (c_data_t (- ?y ?x)))
			(blk (+ ?x 1) ?y)
		)
	)
)
;; heap list
(define-fun-rec hls ((?x Int) (?y Int) (?v Int)) Bool
	(or
		(and (= ?x ?y) (_ emp Int data_t))
		(exists ((?w Int))
			(sep
				(hck ?x ?w ?v)
				(hls ?w ?y ?v)
			)
		)
	)
)

;; variables
(declare-const x0 Int)
(declare-const sz0 Int)
(declare-const x1 Int)
(declare-const sz1 Int)
(declare-const x2 Int)
(declare-const x3 Int)
(declare-const sz2 Int)
(declare-const x4 Int)
(declare-const x5 Int)
(declare-const x6 Int)
(declare-const x7 Int)
(declare-const x8 Int)
(declare-const x9 Int)
(declare-const x10 Int)
(declare-const sz3 Int)
(declare-const sz4 Int)
(declare-const sz5 Int)
(declare-const x11 Int)
(declare-const x12 Int)
(declare-const x13 Int)
(declare-const x14 Int)

(declare-const y0 Int)
(declare-const y1 Int)
(declare-const y2 Int)
(declare-const y3 Int)
(declare-const y4 Int)
(declare-const y5 Int)
(declare-const y6 Int)
(declare-const y7 Int)
(declare-const y8 Int)
(declare-const y9 Int)
(declare-const y10 Int)


(declare-const z0 Int)
(declare-const z1 Int)
(declare-const z2 Int)
(declare-const z3 Int)
(declare-const z4 Int)
(declare-const z5 Int)
(declare-const z6 Int)
(declare-const z7 Int)
(declare-const z8 Int)

(declare-const v0 Int)
(declare-const v1 Int)
(declare-const v2 Int)
(declare-const v3 Int)
(declare-const v4 Int)
(declare-const v5 Int)
(declare-const v6 Int)
(declare-const v7 Int)

(assert
	(and
	(= v0 5)
	(= v1 8)
	(<= v1 v2)
	(<= v2 v3)
	(<= (+ z1 3) z2)
	(<= (+ z3 3) z4)
	(= x1 z1)
	(= x2 z2)
	(< z4 x3)
	(= x5 x4)
	(< z4 y2)
	(< y3 x3)
	(= v2 (- y6 y5))
	(= sz1 (- z4 x1))
	(= v4 2)
	(= (- z7 z6) 6)
	(= (+ x7 1) z5)
	(>= sz3 10)
	(> x10 z8)
	(< y8 x9)
	(< v6 v7)
	(= v7 4)
	(= sz4 (- x9 x8))
	(= sz5 100)
	(= x11 (+ x10 1))
	(> (- x12 x11) 100)
	(sep
		(pto x0 (c_data_t sz0))
		(blk (+ x0 1) x1)
		(hck y0 y1 v0)
		(hls z0 z1 v1)
		(pto x1 (c_data_t sz1))
		(blk (+ x1 1) x2)
		(hls z2 z3 v2)
		(hls z3 z4 v3)
		(hck y2 y3 v0)
		(pto y3 (c_data_t sz2))
		(blk x3 x4)
		(blk x5 x6)
		(pto x6 (c_data_t sz2))
		(blk (+ x6 1) x7)
		(pto x7 (c_data_t sz3))
		(hls z5 z6 v3)
		(hck y4 y5 v0)
		(hck y5 y6 v2)
		(hls z6 z7 v4)
		(hls z7 z8 v5)
		(hck y7 y8 v6)
		(hck y8 y9 v6)
		(hck y9 y10 v7)
		(pto x8 (c_data_t sz4))
		(blk (+ x8 1) x9)
		(blk x9 x10)
		(pto x10 (c_data_t sz5))
		(blk x11 x12)
		(blk x12 x13)
		(blk x13 x14)
	)
))

(check-sat)
;;sat 0.193251
