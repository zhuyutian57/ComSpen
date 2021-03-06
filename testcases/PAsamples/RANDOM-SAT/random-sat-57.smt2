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
(declare-const x26 Int)
(declare-const x27 Int)
(declare-const v26 Int)
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
(declare-const v80 Int)
(declare-const x82 Int)
(declare-const x83 Int)
(declare-const v82 Int)
(declare-const x84 Int)
(declare-const x85 Int)
(declare-const v84 Int)
(declare-const x86 Int)
(declare-const x87 Int)
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
(declare-const x102 Int)
(declare-const x103 Int)
(declare-const v102 Int)
(declare-const x104 Int)
(declare-const x105 Int)
(declare-const v104 Int)
(declare-const x106 Int)
(declare-const x107 Int)
(declare-const x108 Int)
(declare-const x109 Int)
(declare-const x110 Int)
(declare-const x111 Int)
(declare-const x112 Int)
(declare-const x113 Int)
(declare-const x114 Int)
(declare-const x115 Int)
(declare-const x116 Int)
(declare-const x117 Int)
(declare-const x118 Int)
(declare-const x119 Int)
(declare-const v118 Int)
(declare-const x120 Int)
(declare-const x121 Int)
(declare-const x122 Int)
(declare-const x123 Int)
(declare-const x124 Int)
(declare-const x125 Int)
(declare-const v124 Int)
(declare-const x126 Int)
(declare-const x127 Int)
(declare-const v126 Int)
(declare-const x128 Int)
(declare-const x129 Int)
(declare-const v128 Int)
(declare-const x130 Int)
(declare-const x131 Int)
(declare-const v130 Int)
(declare-const x132 Int)
(declare-const x133 Int)
(declare-const x134 Int)
(declare-const x135 Int)
(declare-const v134 Int)
(declare-const x136 Int)
(declare-const x137 Int)
(declare-const x138 Int)
(declare-const x139 Int)
(declare-const v138 Int)
(declare-const x140 Int)
(declare-const x141 Int)
(declare-const v140 Int)
(declare-const x142 Int)
(declare-const x143 Int)
(declare-const x144 Int)
(declare-const x145 Int)
(declare-const x146 Int)
(declare-const x147 Int)
(declare-const x148 Int)
(declare-const x149 Int)
(declare-const v148 Int)

(assert(and
(distinct x75 x60) (distinct x34 x134) (distinct x143 x16) (= x21 x21) (< x39 x29) (= x67 x135) (= x80 x89) (< x65 x135) (distinct x130 x132) (distinct x37 x126) (distinct x44 x68) (< x138 x29) (distinct x1 x79) (< x39 x110) (< x129 x49) (< x73 x114) 
(sep
(blk x0 x1)
(hls x2 x3 v2)
(pto x4 (c_data_t x5))
(blk x6 x7)
(hls x8 x9 v8)
(hls x10 x11 v10)
(blk x12 x13)
(pto x14 (c_data_t x15))
(blk x16 x17)
(hls x18 x19 v18)
(blk x20 x21)
(blk x22 x23)
(pto x24 (c_data_t x25))
(hls x26 x27 v26)
(blk x28 x29)
(pto x30 (c_data_t x31))
(hls x32 x33 v32)
(hls x34 x35 v34)
(pto x36 (c_data_t x37))
(pto x38 (c_data_t x39))
(pto x40 (c_data_t x41))
(pto x42 (c_data_t x43))
(hls x44 x45 v44)
(blk x46 x47)
(blk x48 x49)
(pto x50 (c_data_t x51))
(pto x52 (c_data_t x53))
(blk x54 x55)
(pto x56 (c_data_t x57))
(pto x58 (c_data_t x59))
(pto x60 (c_data_t x61))
(blk x62 x63)
(blk x64 x65)
(hls x66 x67 v66)
(blk x68 x69)
(blk x70 x71)
(pto x72 (c_data_t x73))
(pto x74 (c_data_t x75))
(blk x76 x77)
(pto x78 (c_data_t x79))
(hls x80 x81 v80)
(hls x82 x83 v82)
(hls x84 x85 v84)
(pto x86 (c_data_t x87))
(hls x88 x89 v88)
(blk x90 x91)
(blk x92 x93)
(pto x94 (c_data_t x95))
(blk x96 x97)
(hls x98 x99 v98)
(pto x100 (c_data_t x101))
(hls x102 x103 v102)
(hls x104 x105 v104)
(blk x106 x107)
(pto x108 (c_data_t x109))
(pto x110 (c_data_t x111))
(pto x112 (c_data_t x113))
(blk x114 x115)
(blk x116 x117)
(hls x118 x119 v118)
(pto x120 (c_data_t x121))
(blk x122 x123)
(hls x124 x125 v124)
(hls x126 x127 v126)
(hls x128 x129 v128)
(hls x130 x131 v130)
(blk x132 x133)
(hls x134 x135 v134)
(blk x136 x137)
(hls x138 x139 v138)
(hls x140 x141 v140)
(blk x142 x143)
(blk x144 x145)
(blk x146 x147)
(hls x148 x149 v148)
)))

(check-sat)