(set-logic QF_SLAH)

(declare-datatypes ((data_t 0)) (((c_data_t (sz Int)))))

(declare-heap (Int data_t))

(define-fun hck ((?x Int) (?y Int) (?v Int)) Bool
	(and
		(>= (- ?y ?x) 2) (<= (- ?y ?x) ?v)
		(sep (pto ?x (c_data_t (- ?y ?x))) (blk (+ ?x 1) ?y))
))

(define-fun-rec hls ((?x Int) (?y Int) (?v Int)) Bool
	(or
		(and (= ?x ?y) (_ emp Int data_t))
		(exists ((?w Int)) (sep (hck ?x ?w ?v) (hls ?w ?y ?v)))
))

(declare-const x0 Int)
(declare-const x1 Int)
(declare-const v0 Int)
(declare-const x2 Int)
(declare-const x3 Int)
(declare-const x4 Int)
(declare-const x5 Int)
(declare-const x6 Int)
(declare-const x7 Int)
(declare-const x8 Int)
(declare-const x9 Int)
(declare-const x10 Int)
(declare-const x11 Int)
(declare-const x12 Int)
(declare-const x13 Int)
(declare-const v12 Int)
(declare-const x14 Int)
(declare-const x15 Int)
(declare-const x16 Int)
(declare-const x17 Int)
(declare-const x18 Int)
(declare-const x19 Int)
(declare-const x20 Int)
(declare-const x21 Int)
(declare-const x22 Int)
(declare-const x23 Int)
(declare-const v22 Int)
(declare-const x24 Int)
(declare-const x25 Int)
(declare-const x26 Int)
(declare-const x27 Int)
(declare-const v26 Int)
(declare-const x28 Int)
(declare-const x29 Int)
(declare-const x30 Int)
(declare-const x31 Int)
(declare-const x32 Int)
(declare-const x33 Int)
(declare-const x34 Int)
(declare-const x35 Int)
(declare-const v34 Int)
(declare-const x36 Int)
(declare-const x37 Int)
(declare-const x38 Int)
(declare-const x39 Int)
(declare-const x40 Int)
(declare-const x41 Int)
(declare-const x42 Int)
(declare-const x43 Int)
(declare-const x44 Int)
(declare-const x45 Int)
(declare-const v44 Int)
(declare-const x46 Int)
(declare-const x47 Int)
(declare-const x48 Int)
(declare-const x49 Int)
(declare-const x50 Int)
(declare-const x51 Int)
(declare-const v50 Int)
(declare-const x52 Int)
(declare-const x53 Int)
(declare-const x54 Int)
(declare-const x55 Int)
(declare-const x56 Int)
(declare-const x57 Int)
(declare-const v56 Int)
(declare-const x58 Int)
(declare-const x59 Int)
(declare-const x60 Int)
(declare-const x61 Int)
(declare-const x62 Int)
(declare-const x63 Int)
(declare-const v62 Int)
(declare-const x64 Int)
(declare-const x65 Int)
(declare-const v64 Int)
(declare-const x66 Int)
(declare-const x67 Int)
(declare-const x68 Int)
(declare-const x69 Int)
(declare-const x70 Int)
(declare-const x71 Int)
(declare-const v70 Int)
(declare-const x72 Int)
(declare-const x73 Int)
(declare-const x74 Int)
(declare-const x75 Int)
(declare-const x76 Int)
(declare-const x77 Int)
(declare-const v76 Int)
(declare-const x78 Int)
(declare-const x79 Int)
(declare-const x80 Int)
(declare-const x81 Int)
(declare-const x82 Int)
(declare-const x83 Int)
(declare-const x84 Int)
(declare-const x85 Int)
(declare-const v84 Int)
(declare-const x86 Int)
(declare-const x87 Int)
(declare-const x88 Int)
(declare-const x89 Int)
(declare-const x90 Int)
(declare-const x91 Int)
(declare-const x92 Int)
(declare-const x93 Int)
(declare-const x94 Int)
(declare-const x95 Int)
(declare-const x96 Int)
(declare-const x97 Int)
(declare-const v96 Int)
(declare-const x98 Int)
(declare-const x99 Int)
(declare-const v98 Int)

(assert(and
(< x59 x55) (= x65 x85) (distinct x12 x70) (= x75 x56) (distinct x49 x65) (distinct x65 x15) (= x66 x62) (= x96 x59) 
(sep
(hls x0 x1 v0)
(pto x2 (c_data_t x3))
(pto x4 (c_data_t x5))
(blk x6 x7)
(blk x8 x9)
(pto x10 (c_data_t x11))
(hls x12 x13 v12)
(pto x14 (c_data_t x15))
(pto x16 (c_data_t x17))
(blk x18 x19)
(pto x20 (c_data_t x21))
(hls x22 x23 v22)
(blk x24 x25)
(hls x26 x27 v26)
(pto x28 (c_data_t x29))
(blk x30 x31)
(pto x32 (c_data_t x33))
(hls x34 x35 v34)
(pto x36 (c_data_t x37))
(blk x38 x39)
(blk x40 x41)
(pto x42 (c_data_t x43))
(hls x44 x45 v44)
(pto x46 (c_data_t x47))
(blk x48 x49)
(hls x50 x51 v50)
(pto x52 (c_data_t x53))
(blk x54 x55)
(hls x56 x57 v56)
(blk x58 x59)
(blk x60 x61)
(hls x62 x63 v62)
(hls x64 x65 v64)
(pto x66 (c_data_t x67))
(blk x68 x69)
(hls x70 x71 v70)
(blk x72 x73)
(pto x74 (c_data_t x75))
(hls x76 x77 v76)
(blk x78 x79)
(blk x80 x81)
(blk x82 x83)
(hls x84 x85 v84)
(pto x86 (c_data_t x87))
(blk x88 x89)
(blk x90 x91)
(blk x92 x93)
(pto x94 (c_data_t x95))
(hls x96 x97 v96)
(hls x98 x99 v98)
)))

(check-sat)