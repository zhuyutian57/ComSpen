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
(declare-const v14 Int)
(declare-const x16 Int)
(declare-const x17 Int)
(declare-const v16 Int)
(declare-const x18 Int)
(declare-const x19 Int)
(declare-const x20 Int)
(declare-const x21 Int)
(declare-const x22 Int)
(declare-const x23 Int)
(declare-const x24 Int)
(declare-const x25 Int)
(declare-const x26 Int)
(declare-const x27 Int)
(declare-const v26 Int)
(declare-const x28 Int)
(declare-const x29 Int)
(declare-const x30 Int)
(declare-const x31 Int)
(declare-const v30 Int)
(declare-const x32 Int)
(declare-const x33 Int)
(declare-const x34 Int)
(declare-const x35 Int)
(declare-const x36 Int)
(declare-const x37 Int)
(declare-const v36 Int)
(declare-const x38 Int)
(declare-const x39 Int)
(declare-const v38 Int)
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
(declare-const x54 Int)
(declare-const x55 Int)
(declare-const x56 Int)
(declare-const x57 Int)
(declare-const x58 Int)
(declare-const x59 Int)
(declare-const x60 Int)
(declare-const x61 Int)
(declare-const v60 Int)
(declare-const x62 Int)
(declare-const x63 Int)
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
(declare-const x78 Int)
(declare-const x79 Int)
(declare-const v78 Int)
(declare-const x80 Int)
(declare-const x81 Int)
(declare-const v80 Int)
(declare-const x82 Int)
(declare-const x83 Int)
(declare-const x84 Int)
(declare-const x85 Int)
(declare-const v84 Int)
(declare-const x86 Int)
(declare-const x87 Int)
(declare-const v86 Int)
(declare-const x88 Int)
(declare-const x89 Int)
(declare-const x90 Int)
(declare-const x91 Int)
(declare-const x92 Int)
(declare-const x93 Int)
(declare-const x94 Int)
(declare-const x95 Int)
(declare-const v94 Int)
(declare-const x96 Int)
(declare-const x97 Int)
(declare-const x98 Int)
(declare-const x99 Int)
(declare-const v98 Int)
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
(declare-const x110 Int)
(declare-const x111 Int)
(declare-const x112 Int)
(declare-const x113 Int)
(declare-const v112 Int)
(declare-const x114 Int)
(declare-const x115 Int)
(declare-const x116 Int)
(declare-const x117 Int)
(declare-const x118 Int)
(declare-const x119 Int)

(assert(and
(distinct x87 x19) (< x27 x46) (distinct x29 x2) (< x1 x72) (= x85 x30) (distinct x104 x69) (distinct x86 x117) (< x1 x55) (= x36 x112) (< x48 x11) (distinct x65 x89) (= x103 x76) (distinct x55 x21) (< x61 x95) 
(sep
(blk x0 x1)
(pto x2 (c_data_t x3))
(pto x4 (c_data_t x5))
(pto x6 (c_data_t x7))
(blk x8 x9)
(blk x10 x11)
(hls x12 x13 v12)
(hls x14 x15 v14)
(hls x16 x17 v16)
(blk x18 x19)
(blk x20 x21)
(pto x22 (c_data_t x23))
(blk x24 x25)
(hls x26 x27 v26)
(pto x28 (c_data_t x29))
(hls x30 x31 v30)
(pto x32 (c_data_t x33))
(pto x34 (c_data_t x35))
(hls x36 x37 v36)
(hls x38 x39 v38)
(pto x40 (c_data_t x41))
(pto x42 (c_data_t x43))
(pto x44 (c_data_t x45))
(hls x46 x47 v46)
(pto x48 (c_data_t x49))
(pto x50 (c_data_t x51))
(pto x52 (c_data_t x53))
(blk x54 x55)
(blk x56 x57)
(blk x58 x59)
(hls x60 x61 v60)
(pto x62 (c_data_t x63))
(hls x64 x65 v64)
(blk x66 x67)
(pto x68 (c_data_t x69))
(hls x70 x71 v70)
(blk x72 x73)
(blk x74 x75)
(blk x76 x77)
(hls x78 x79 v78)
(hls x80 x81 v80)
(blk x82 x83)
(hls x84 x85 v84)
(hls x86 x87 v86)
(blk x88 x89)
(pto x90 (c_data_t x91))
(blk x92 x93)
(hls x94 x95 v94)
(blk x96 x97)
(hls x98 x99 v98)
(pto x100 (c_data_t x101))
(pto x102 (c_data_t x103))
(blk x104 x105)
(blk x106 x107)
(pto x108 (c_data_t x109))
(blk x110 x111)
(hls x112 x113 v112)
(blk x114 x115)
(blk x116 x117)
(blk x118 x119)
)))

(check-sat)