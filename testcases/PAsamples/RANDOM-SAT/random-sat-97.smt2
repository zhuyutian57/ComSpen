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
(declare-const v4 Int)
(declare-const x6 Int)
(declare-const x7 Int)
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
(declare-const v42 Int)
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
(declare-const x70 Int)
(declare-const x71 Int)
(declare-const x72 Int)
(declare-const x73 Int)
(declare-const x74 Int)
(declare-const x75 Int)
(declare-const x76 Int)
(declare-const x77 Int)
(declare-const v76 Int)
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
(declare-const v96 Int)
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
(declare-const v118 Int)
(declare-const x120 Int)
(declare-const x121 Int)
(declare-const v120 Int)
(declare-const x122 Int)
(declare-const x123 Int)
(declare-const x124 Int)
(declare-const x125 Int)
(declare-const x126 Int)
(declare-const x127 Int)
(declare-const x128 Int)
(declare-const x129 Int)
(declare-const x130 Int)
(declare-const x131 Int)
(declare-const v130 Int)
(declare-const x132 Int)
(declare-const x133 Int)
(declare-const v132 Int)
(declare-const x134 Int)
(declare-const x135 Int)
(declare-const x136 Int)
(declare-const x137 Int)
(declare-const x138 Int)
(declare-const x139 Int)
(declare-const v138 Int)
(declare-const x140 Int)
(declare-const x141 Int)
(declare-const x142 Int)
(declare-const x143 Int)
(declare-const x144 Int)
(declare-const x145 Int)
(declare-const x146 Int)
(declare-const x147 Int)
(declare-const x148 Int)
(declare-const x149 Int)
(declare-const x150 Int)
(declare-const x151 Int)
(declare-const x152 Int)
(declare-const x153 Int)
(declare-const x154 Int)
(declare-const x155 Int)
(declare-const x156 Int)
(declare-const x157 Int)
(declare-const v156 Int)
(declare-const x158 Int)
(declare-const x159 Int)
(declare-const x160 Int)
(declare-const x161 Int)
(declare-const x162 Int)
(declare-const x163 Int)
(declare-const x164 Int)
(declare-const x165 Int)
(declare-const v164 Int)
(declare-const x166 Int)
(declare-const x167 Int)
(declare-const x168 Int)
(declare-const x169 Int)
(declare-const x170 Int)
(declare-const x171 Int)
(declare-const x172 Int)
(declare-const x173 Int)
(declare-const x174 Int)
(declare-const x175 Int)
(declare-const x176 Int)
(declare-const x177 Int)
(declare-const x178 Int)
(declare-const x179 Int)
(declare-const x180 Int)
(declare-const x181 Int)
(declare-const v180 Int)
(declare-const x182 Int)
(declare-const x183 Int)
(declare-const x184 Int)
(declare-const x185 Int)
(declare-const x186 Int)
(declare-const x187 Int)
(declare-const x188 Int)
(declare-const x189 Int)

(assert(and
(= x124 x88) (distinct x34 x66) (distinct x128 x157) (< x14 x157) (< x50 x185) (distinct x116 x14) (= x174 x183) (= x185 x185) (< x46 x170) (< x166 x25) 
(sep
(pto x0 (c_data_t x1))
(pto x2 (c_data_t x3))
(hls x4 x5 v4)
(pto x6 (c_data_t x7))
(pto x8 (c_data_t x9))
(blk x10 x11)
(pto x12 (c_data_t x13))
(pto x14 (c_data_t x15))
(pto x16 (c_data_t x17))
(blk x18 x19)
(pto x20 (c_data_t x21))
(pto x22 (c_data_t x23))
(pto x24 (c_data_t x25))
(hls x26 x27 v26)
(blk x28 x29)
(hls x30 x31 v30)
(hls x32 x33 v32)
(hls x34 x35 v34)
(blk x36 x37)
(pto x38 (c_data_t x39))
(pto x40 (c_data_t x41))
(hls x42 x43 v42)
(pto x44 (c_data_t x45))
(pto x46 (c_data_t x47))
(hls x48 x49 v48)
(hls x50 x51 v50)
(hls x52 x53 v52)
(pto x54 (c_data_t x55))
(hls x56 x57 v56)
(blk x58 x59)
(hls x60 x61 v60)
(blk x62 x63)
(pto x64 (c_data_t x65))
(hls x66 x67 v66)
(blk x68 x69)
(pto x70 (c_data_t x71))
(pto x72 (c_data_t x73))
(pto x74 (c_data_t x75))
(hls x76 x77 v76)
(hls x78 x79 v78)
(blk x80 x81)
(blk x82 x83)
(pto x84 (c_data_t x85))
(blk x86 x87)
(hls x88 x89 v88)
(hls x90 x91 v90)
(blk x92 x93)
(pto x94 (c_data_t x95))
(hls x96 x97 v96)
(blk x98 x99)
(pto x100 (c_data_t x101))
(pto x102 (c_data_t x103))
(pto x104 (c_data_t x105))
(pto x106 (c_data_t x107))
(blk x108 x109)
(hls x110 x111 v110)
(blk x112 x113)
(pto x114 (c_data_t x115))
(pto x116 (c_data_t x117))
(hls x118 x119 v118)
(hls x120 x121 v120)
(pto x122 (c_data_t x123))
(blk x124 x125)
(blk x126 x127)
(pto x128 (c_data_t x129))
(hls x130 x131 v130)
(hls x132 x133 v132)
(blk x134 x135)
(pto x136 (c_data_t x137))
(hls x138 x139 v138)
(blk x140 x141)
(pto x142 (c_data_t x143))
(pto x144 (c_data_t x145))
(pto x146 (c_data_t x147))
(blk x148 x149)
(pto x150 (c_data_t x151))
(pto x152 (c_data_t x153))
(blk x154 x155)
(hls x156 x157 v156)
(pto x158 (c_data_t x159))
(blk x160 x161)
(pto x162 (c_data_t x163))
(hls x164 x165 v164)
(blk x166 x167)
(pto x168 (c_data_t x169))
(pto x170 (c_data_t x171))
(pto x172 (c_data_t x173))
(pto x174 (c_data_t x175))
(pto x176 (c_data_t x177))
(blk x178 x179)
(hls x180 x181 v180)
(pto x182 (c_data_t x183))
(pto x184 (c_data_t x185))
(blk x186 x187)
(pto x188 (c_data_t x189))
)))

(check-sat)