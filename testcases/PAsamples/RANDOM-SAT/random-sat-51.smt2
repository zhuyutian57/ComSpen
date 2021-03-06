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
(declare-const v10 Int)
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
(declare-const v20 Int)
(declare-const x22 Int)
(declare-const x23 Int)
(declare-const v22 Int)
(declare-const x24 Int)
(declare-const x25 Int)
(declare-const x26 Int)
(declare-const x27 Int)
(declare-const x28 Int)
(declare-const x29 Int)
(declare-const v28 Int)
(declare-const x30 Int)
(declare-const x31 Int)
(declare-const v30 Int)
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
(declare-const v42 Int)
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
(declare-const v54 Int)
(declare-const x56 Int)
(declare-const x57 Int)
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
(declare-const v72 Int)
(declare-const x74 Int)
(declare-const x75 Int)
(declare-const x76 Int)
(declare-const x77 Int)
(declare-const x78 Int)
(declare-const x79 Int)
(declare-const v78 Int)
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
(declare-const v90 Int)
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
(declare-const v106 Int)
(declare-const x108 Int)
(declare-const x109 Int)
(declare-const v108 Int)
(declare-const x110 Int)
(declare-const x111 Int)
(declare-const v110 Int)
(declare-const x112 Int)
(declare-const x113 Int)
(declare-const v112 Int)
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
(declare-const v122 Int)
(declare-const x124 Int)
(declare-const x125 Int)
(declare-const x126 Int)
(declare-const x127 Int)
(declare-const x128 Int)
(declare-const x129 Int)
(declare-const x130 Int)
(declare-const x131 Int)
(declare-const x132 Int)
(declare-const x133 Int)
(declare-const v132 Int)
(declare-const x134 Int)
(declare-const x135 Int)
(declare-const x136 Int)
(declare-const x137 Int)
(declare-const v136 Int)
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

(assert(and
(distinct x43 x61) (= x96 x47) (= x64 x99) (distinct x12 x54) (< x85 x107) (< x15 x143) (= x32 x16) (= x74 x86) (distinct x44 x114) (distinct x104 x113) (distinct x47 x46) (< x120 x98) (distinct x128 x97) (= x138 x98) (distinct x37 x111) (distinct x35 x47) (distinct x139 x97) (distinct x79 x143) (distinct x112 x65) 
(sep
(pto x0 (c_data_t x1))
(blk x2 x3)
(blk x4 x5)
(blk x6 x7)
(blk x8 x9)
(hls x10 x11 v10)
(hls x12 x13 v12)
(pto x14 (c_data_t x15))
(pto x16 (c_data_t x17))
(blk x18 x19)
(hls x20 x21 v20)
(hls x22 x23 v22)
(blk x24 x25)
(pto x26 (c_data_t x27))
(hls x28 x29 v28)
(hls x30 x31 v30)
(blk x32 x33)
(hls x34 x35 v34)
(blk x36 x37)
(blk x38 x39)
(blk x40 x41)
(hls x42 x43 v42)
(blk x44 x45)
(hls x46 x47 v46)
(pto x48 (c_data_t x49))
(blk x50 x51)
(hls x52 x53 v52)
(hls x54 x55 v54)
(blk x56 x57)
(blk x58 x59)
(pto x60 (c_data_t x61))
(hls x62 x63 v62)
(hls x64 x65 v64)
(blk x66 x67)
(pto x68 (c_data_t x69))
(hls x70 x71 v70)
(hls x72 x73 v72)
(blk x74 x75)
(blk x76 x77)
(hls x78 x79 v78)
(pto x80 (c_data_t x81))
(blk x82 x83)
(blk x84 x85)
(hls x86 x87 v86)
(hls x88 x89 v88)
(hls x90 x91 v90)
(pto x92 (c_data_t x93))
(pto x94 (c_data_t x95))
(pto x96 (c_data_t x97))
(pto x98 (c_data_t x99))
(blk x100 x101)
(blk x102 x103)
(blk x104 x105)
(hls x106 x107 v106)
(hls x108 x109 v108)
(hls x110 x111 v110)
(hls x112 x113 v112)
(pto x114 (c_data_t x115))
(blk x116 x117)
(hls x118 x119 v118)
(pto x120 (c_data_t x121))
(hls x122 x123 v122)
(pto x124 (c_data_t x125))
(blk x126 x127)
(pto x128 (c_data_t x129))
(blk x130 x131)
(hls x132 x133 v132)
(pto x134 (c_data_t x135))
(hls x136 x137 v136)
(hls x138 x139 v138)
(hls x140 x141 v140)
(blk x142 x143)
(pto x144 (c_data_t x145))
(pto x146 (c_data_t x147))
(pto x148 (c_data_t x149))
)))

(check-sat)