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
(declare-const v8 Int)
(declare-const x10 Int)
(declare-const x11 Int)
(declare-const v10 Int)
(declare-const x12 Int)
(declare-const x13 Int)
(declare-const x14 Int)
(declare-const x15 Int)
(declare-const v14 Int)
(declare-const x16 Int)
(declare-const x17 Int)
(declare-const v16 Int)
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
(declare-const x46 Int)
(declare-const x47 Int)
(declare-const x48 Int)
(declare-const x49 Int)
(declare-const v48 Int)
(declare-const x50 Int)
(declare-const x51 Int)
(declare-const x52 Int)
(declare-const x53 Int)
(declare-const v52 Int)
(declare-const x54 Int)
(declare-const x55 Int)
(declare-const x56 Int)
(declare-const x57 Int)
(declare-const v56 Int)
(declare-const x58 Int)
(declare-const x59 Int)
(declare-const x60 Int)
(declare-const x61 Int)
(declare-const v60 Int)
(declare-const x62 Int)
(declare-const x63 Int)
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
(declare-const x76 Int)
(declare-const x77 Int)
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
(declare-const v86 Int)
(declare-const x88 Int)
(declare-const x89 Int)
(declare-const v88 Int)
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
(declare-const v98 Int)
(declare-const x100 Int)
(declare-const x101 Int)
(declare-const v100 Int)
(declare-const x102 Int)
(declare-const x103 Int)
(declare-const x104 Int)
(declare-const x105 Int)
(declare-const x106 Int)
(declare-const x107 Int)
(declare-const v106 Int)
(declare-const x108 Int)
(declare-const x109 Int)
(declare-const x110 Int)
(declare-const x111 Int)
(declare-const v110 Int)
(declare-const x112 Int)
(declare-const x113 Int)
(declare-const x114 Int)
(declare-const x115 Int)
(declare-const x116 Int)
(declare-const x117 Int)
(declare-const x118 Int)
(declare-const x119 Int)
(declare-const x120 Int)
(declare-const x121 Int)
(declare-const v120 Int)
(declare-const x122 Int)
(declare-const x123 Int)
(declare-const v122 Int)
(declare-const x124 Int)
(declare-const x125 Int)
(declare-const x126 Int)
(declare-const x127 Int)
(declare-const x128 Int)
(declare-const x129 Int)
(declare-const v128 Int)
(declare-const x130 Int)
(declare-const x131 Int)
(declare-const x132 Int)
(declare-const x133 Int)
(declare-const x134 Int)
(declare-const x135 Int)
(declare-const v134 Int)
(declare-const x136 Int)
(declare-const x137 Int)
(declare-const v136 Int)
(declare-const x138 Int)
(declare-const x139 Int)
(declare-const x140 Int)
(declare-const x141 Int)
(declare-const x142 Int)
(declare-const x143 Int)
(declare-const v142 Int)
(declare-const x144 Int)
(declare-const x145 Int)
(declare-const x146 Int)
(declare-const x147 Int)
(declare-const v146 Int)
(declare-const x148 Int)
(declare-const x149 Int)
(declare-const v148 Int)

(assert(and
(< x59 x109) 
(sep
(blk x0 x1)
(hls x2 x3 v2)
(blk x4 x5)
(blk x6 x7)
(hls x8 x9 v8)
(hls x10 x11 v10)
(pto x12 (c_data_t x13))
(hls x14 x15 v14)
(hls x16 x17 v16)
(hls x18 x19 v18)
(blk x20 x21)
(pto x22 (c_data_t x23))
(hls x24 x25 v24)
(blk x26 x27)
(blk x28 x29)
(pto x30 (c_data_t x31))
(pto x32 (c_data_t x33))
(hls x34 x35 v34)
(pto x36 (c_data_t x37))
(blk x38 x39)
(pto x40 (c_data_t x41))
(pto x42 (c_data_t x43))
(pto x44 (c_data_t x45))
(pto x46 (c_data_t x47))
(hls x48 x49 v48)
(pto x50 (c_data_t x51))
(hls x52 x53 v52)
(pto x54 (c_data_t x55))
(hls x56 x57 v56)
(blk x58 x59)
(hls x60 x61 v60)
(blk x62 x63)
(pto x64 (c_data_t x65))
(hls x66 x67 v66)
(hls x68 x69 v68)
(pto x70 (c_data_t x71))
(pto x72 (c_data_t x73))
(blk x74 x75)
(blk x76 x77)
(blk x78 x79)
(blk x80 x81)
(blk x82 x83)
(pto x84 (c_data_t x85))
(hls x86 x87 v86)
(hls x88 x89 v88)
(pto x90 (c_data_t x91))
(blk x92 x93)
(pto x94 (c_data_t x95))
(pto x96 (c_data_t x97))
(hls x98 x99 v98)
(hls x100 x101 v100)
(pto x102 (c_data_t x103))
(pto x104 (c_data_t x105))
(hls x106 x107 v106)
(pto x108 (c_data_t x109))
(hls x110 x111 v110)
(pto x112 (c_data_t x113))
(pto x114 (c_data_t x115))
(blk x116 x117)
(pto x118 (c_data_t x119))
(hls x120 x121 v120)
(hls x122 x123 v122)
(pto x124 (c_data_t x125))
(blk x126 x127)
(hls x128 x129 v128)
(blk x130 x131)
(blk x132 x133)
(hls x134 x135 v134)
(hls x136 x137 v136)
(pto x138 (c_data_t x139))
(blk x140 x141)
(hls x142 x143 v142)
(blk x144 x145)
(hls x146 x147 v146)
(hls x148 x149 v148)
)))

(check-sat)