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
(declare-const v6 Int)
(declare-const x8 Int)
(declare-const x9 Int)
(declare-const x10 Int)
(declare-const x11 Int)
(declare-const x12 Int)
(declare-const x13 Int)
(declare-const x14 Int)
(declare-const x15 Int)
(declare-const x16 Int)
(declare-const x17 Int)
(declare-const x18 Int)
(declare-const x19 Int)
(declare-const x20 Int)
(declare-const x21 Int)
(declare-const v20 Int)
(declare-const x22 Int)
(declare-const x23 Int)
(declare-const x24 Int)
(declare-const x25 Int)
(declare-const v24 Int)
(declare-const x26 Int)
(declare-const x27 Int)
(declare-const x28 Int)
(declare-const x29 Int)
(declare-const x30 Int)
(declare-const x31 Int)
(declare-const x32 Int)
(declare-const x33 Int)
(declare-const v32 Int)
(declare-const x34 Int)
(declare-const x35 Int)
(declare-const v34 Int)
(declare-const x36 Int)
(declare-const x37 Int)
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
(declare-const x48 Int)
(declare-const x49 Int)
(declare-const v48 Int)
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
(declare-const x66 Int)
(declare-const x67 Int)
(declare-const v66 Int)
(declare-const x68 Int)
(declare-const x69 Int)
(declare-const v68 Int)
(declare-const x70 Int)
(declare-const x71 Int)
(declare-const x72 Int)
(declare-const x73 Int)
(declare-const x74 Int)
(declare-const x75 Int)
(declare-const v74 Int)
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
(declare-const x98 Int)
(declare-const x99 Int)
(declare-const x100 Int)
(declare-const x101 Int)
(declare-const x102 Int)
(declare-const x103 Int)
(declare-const v102 Int)
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
(declare-const v114 Int)
(declare-const x116 Int)
(declare-const x117 Int)
(declare-const x118 Int)
(declare-const x119 Int)

(assert(and
(distinct x45 x97) (distinct x105 x98) (distinct x26 x7) (< x47 x3) (distinct x2 x58) (< x39 x64) (< x64 x54) (distinct x46 x11) (= x16 x112) 
(sep
(hls x0 x1 v0)
(pto x2 (c_data_t x3))
(pto x4 (c_data_t x5))
(hls x6 x7 v6)
(blk x8 x9)
(blk x10 x11)
(blk x12 x13)
(pto x14 (c_data_t x15))
(pto x16 (c_data_t x17))
(pto x18 (c_data_t x19))
(hls x20 x21 v20)
(blk x22 x23)
(hls x24 x25 v24)
(blk x26 x27)
(blk x28 x29)
(blk x30 x31)
(hls x32 x33 v32)
(hls x34 x35 v34)
(pto x36 (c_data_t x37))
(hls x38 x39 v38)
(blk x40 x41)
(pto x42 (c_data_t x43))
(blk x44 x45)
(pto x46 (c_data_t x47))
(hls x48 x49 v48)
(hls x50 x51 v50)
(pto x52 (c_data_t x53))
(blk x54 x55)
(hls x56 x57 v56)
(pto x58 (c_data_t x59))
(pto x60 (c_data_t x61))
(hls x62 x63 v62)
(pto x64 (c_data_t x65))
(hls x66 x67 v66)
(hls x68 x69 v68)
(pto x70 (c_data_t x71))
(blk x72 x73)
(hls x74 x75 v74)
(hls x76 x77 v76)
(pto x78 (c_data_t x79))
(blk x80 x81)
(pto x82 (c_data_t x83))
(hls x84 x85 v84)
(pto x86 (c_data_t x87))
(blk x88 x89)
(pto x90 (c_data_t x91))
(pto x92 (c_data_t x93))
(pto x94 (c_data_t x95))
(pto x96 (c_data_t x97))
(blk x98 x99)
(pto x100 (c_data_t x101))
(hls x102 x103 v102)
(blk x104 x105)
(pto x106 (c_data_t x107))
(pto x108 (c_data_t x109))
(pto x110 (c_data_t x111))
(hls x112 x113 v112)
(hls x114 x115 v114)
(blk x116 x117)
(pto x118 (c_data_t x119))
)))

(check-sat)