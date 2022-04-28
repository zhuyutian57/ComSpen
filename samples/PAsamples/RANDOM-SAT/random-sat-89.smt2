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
(declare-const v10 Int)
(declare-const x12 Int)
(declare-const x13 Int)
(declare-const v12 Int)
(declare-const x14 Int)
(declare-const x15 Int)
(declare-const v14 Int)
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
(declare-const x36 Int)
(declare-const x37 Int)
(declare-const v36 Int)
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
(declare-const v50 Int)
(declare-const x52 Int)
(declare-const x53 Int)
(declare-const v52 Int)
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
(declare-const v70 Int)
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
(declare-const x100 Int)
(declare-const x101 Int)
(declare-const v100 Int)
(declare-const x102 Int)
(declare-const x103 Int)
(declare-const x104 Int)
(declare-const x105 Int)
(declare-const x106 Int)
(declare-const x107 Int)
(declare-const x108 Int)
(declare-const x109 Int)
(declare-const v108 Int)
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
(declare-const x138 Int)
(declare-const x139 Int)
(declare-const x140 Int)
(declare-const x141 Int)
(declare-const v140 Int)
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
(declare-const x150 Int)
(declare-const x151 Int)
(declare-const v150 Int)
(declare-const x152 Int)
(declare-const x153 Int)
(declare-const x154 Int)
(declare-const x155 Int)
(declare-const v154 Int)
(declare-const x156 Int)
(declare-const x157 Int)
(declare-const x158 Int)
(declare-const x159 Int)
(declare-const x160 Int)
(declare-const x161 Int)
(declare-const v160 Int)
(declare-const x162 Int)
(declare-const x163 Int)
(declare-const x164 Int)
(declare-const x165 Int)
(declare-const x166 Int)
(declare-const x167 Int)
(declare-const x168 Int)
(declare-const x169 Int)
(declare-const v168 Int)
(declare-const x170 Int)
(declare-const x171 Int)
(declare-const x172 Int)
(declare-const x173 Int)
(declare-const v172 Int)
(declare-const x174 Int)
(declare-const x175 Int)
(declare-const x176 Int)
(declare-const x177 Int)
(declare-const v176 Int)
(declare-const x178 Int)
(declare-const x179 Int)

(assert(and
(= x45 x31) (distinct x79 x101) (distinct x60 x148) (= x54 x47) (distinct x21 x59) (= x48 x145) (distinct x56 x0) (< x75 x27) (distinct x115 x58) (distinct x81 x147) (< x137 x86) (= x73 x74) (= x54 x37) (< x123 x59) (distinct x75 x87) 
(sep
(hls x0 x1 v0)
(pto x2 (c_data_t x3))
(blk x4 x5)
(pto x6 (c_data_t x7))
(blk x8 x9)
(hls x10 x11 v10)
(hls x12 x13 v12)
(hls x14 x15 v14)
(pto x16 (c_data_t x17))
(blk x18 x19)
(hls x20 x21 v20)
(blk x22 x23)
(pto x24 (c_data_t x25))
(pto x26 (c_data_t x27))
(blk x28 x29)
(blk x30 x31)
(hls x32 x33 v32)
(blk x34 x35)
(hls x36 x37 v36)
(blk x38 x39)
(blk x40 x41)
(hls x42 x43 v42)
(blk x44 x45)
(hls x46 x47 v46)
(pto x48 (c_data_t x49))
(hls x50 x51 v50)
(hls x52 x53 v52)
(pto x54 (c_data_t x55))
(blk x56 x57)
(pto x58 (c_data_t x59))
(pto x60 (c_data_t x61))
(blk x62 x63)
(pto x64 (c_data_t x65))
(hls x66 x67 v66)
(pto x68 (c_data_t x69))
(hls x70 x71 v70)
(pto x72 (c_data_t x73))
(pto x74 (c_data_t x75))
(pto x76 (c_data_t x77))
(pto x78 (c_data_t x79))
(hls x80 x81 v80)
(hls x82 x83 v82)
(hls x84 x85 v84)
(blk x86 x87)
(pto x88 (c_data_t x89))
(blk x90 x91)
(blk x92 x93)
(hls x94 x95 v94)
(pto x96 (c_data_t x97))
(blk x98 x99)
(hls x100 x101 v100)
(pto x102 (c_data_t x103))
(pto x104 (c_data_t x105))
(pto x106 (c_data_t x107))
(hls x108 x109 v108)
(blk x110 x111)
(hls x112 x113 v112)
(hls x114 x115 v114)
(pto x116 (c_data_t x117))
(hls x118 x119 v118)
(pto x120 (c_data_t x121))
(pto x122 (c_data_t x123))
(hls x124 x125 v124)
(blk x126 x127)
(blk x128 x129)
(blk x130 x131)
(hls x132 x133 v132)
(blk x134 x135)
(pto x136 (c_data_t x137))
(blk x138 x139)
(hls x140 x141 v140)
(hls x142 x143 v142)
(pto x144 (c_data_t x145))
(hls x146 x147 v146)
(hls x148 x149 v148)
(hls x150 x151 v150)
(blk x152 x153)
(hls x154 x155 v154)
(blk x156 x157)
(pto x158 (c_data_t x159))
(hls x160 x161 v160)
(pto x162 (c_data_t x163))
(pto x164 (c_data_t x165))
(pto x166 (c_data_t x167))
(hls x168 x169 v168)
(blk x170 x171)
(hls x172 x173 v172)
(pto x174 (c_data_t x175))
(hls x176 x177 v176)
(blk x178 x179)
)))

(check-sat)