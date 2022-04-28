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
(declare-const x2 Int)
(declare-const x3 Int)
(declare-const v2 Int)
(declare-const x4 Int)
(declare-const x5 Int)
(declare-const x6 Int)
(declare-const x7 Int)
(declare-const x8 Int)
(declare-const x9 Int)
(declare-const x10 Int)
(declare-const x11 Int)
(declare-const v10 Int)
(declare-const x12 Int)
(declare-const x13 Int)
(declare-const x14 Int)
(declare-const x15 Int)
(declare-const x16 Int)
(declare-const x17 Int)
(declare-const x18 Int)
(declare-const x19 Int)
(declare-const v18 Int)
(declare-const x20 Int)
(declare-const x21 Int)
(declare-const x22 Int)
(declare-const x23 Int)
(declare-const x24 Int)
(declare-const x25 Int)
(declare-const v24 Int)
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
(declare-const x46 Int)
(declare-const x47 Int)
(declare-const v46 Int)
(declare-const x48 Int)
(declare-const x49 Int)
(declare-const x50 Int)
(declare-const x51 Int)
(declare-const x52 Int)
(declare-const x53 Int)
(declare-const v52 Int)
(declare-const x54 Int)
(declare-const x55 Int)
(declare-const x56 Int)
(declare-const x57 Int)
(declare-const x58 Int)
(declare-const x59 Int)
(declare-const v58 Int)
(declare-const x60 Int)
(declare-const x61 Int)
(declare-const x62 Int)
(declare-const x63 Int)
(declare-const x64 Int)
(declare-const x65 Int)
(declare-const x66 Int)
(declare-const x67 Int)
(declare-const v66 Int)
(declare-const x68 Int)
(declare-const x69 Int)
(declare-const x70 Int)
(declare-const x71 Int)
(declare-const v70 Int)
(declare-const x72 Int)
(declare-const x73 Int)
(declare-const v72 Int)
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
(declare-const x98 Int)
(declare-const x99 Int)
(declare-const x100 Int)
(declare-const x101 Int)
(declare-const x102 Int)
(declare-const x103 Int)
(declare-const x104 Int)
(declare-const x105 Int)
(declare-const x106 Int)
(declare-const x107 Int)
(declare-const x108 Int)
(declare-const x109 Int)

(assert(and
(< x86 x41) (distinct x74 x9) (< x96 x87) (< x53 x84) (< x104 x79) (distinct x8 x39) (< x20 x80) (distinct x40 x58) 
(sep
(blk x0 x1)
(hls x2 x3 v2)
(pto x4 (c_data_t x5))
(blk x6 x7)
(pto x8 (c_data_t x9))
(hls x10 x11 v10)
(pto x12 (c_data_t x13))
(blk x14 x15)
(blk x16 x17)
(hls x18 x19 v18)
(pto x20 (c_data_t x21))
(pto x22 (c_data_t x23))
(hls x24 x25 v24)
(hls x26 x27 v26)
(blk x28 x29)
(blk x30 x31)
(blk x32 x33)
(blk x34 x35)
(pto x36 (c_data_t x37))
(blk x38 x39)
(pto x40 (c_data_t x41))
(blk x42 x43)
(pto x44 (c_data_t x45))
(hls x46 x47 v46)
(pto x48 (c_data_t x49))
(pto x50 (c_data_t x51))
(hls x52 x53 v52)
(blk x54 x55)
(blk x56 x57)
(hls x58 x59 v58)
(blk x60 x61)
(pto x62 (c_data_t x63))
(pto x64 (c_data_t x65))
(hls x66 x67 v66)
(pto x68 (c_data_t x69))
(hls x70 x71 v70)
(hls x72 x73 v72)
(blk x74 x75)
(hls x76 x77 v76)
(pto x78 (c_data_t x79))
(pto x80 (c_data_t x81))
(pto x82 (c_data_t x83))
(blk x84 x85)
(blk x86 x87)
(blk x88 x89)
(pto x90 (c_data_t x91))
(blk x92 x93)
(pto x94 (c_data_t x95))
(pto x96 (c_data_t x97))
(pto x98 (c_data_t x99))
(pto x100 (c_data_t x101))
(pto x102 (c_data_t x103))
(pto x104 (c_data_t x105))
(pto x106 (c_data_t x107))
(blk x108 x109)
)))

(check-sat)