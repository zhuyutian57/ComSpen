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
(declare-const v6 Int)
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
(declare-const v28 Int)
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
(declare-const v54 Int)
(declare-const x56 Int)
(declare-const x57 Int)
(declare-const v56 Int)
(declare-const x58 Int)
(declare-const x59 Int)
(declare-const v58 Int)
(declare-const x60 Int)
(declare-const x61 Int)
(declare-const v60 Int)
(declare-const x62 Int)
(declare-const x63 Int)
(declare-const v62 Int)
(declare-const x64 Int)
(declare-const x65 Int)
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
(declare-const v120 Int)
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
(declare-const x134 Int)
(declare-const x135 Int)
(declare-const v134 Int)
(declare-const x136 Int)
(declare-const x137 Int)
(declare-const x138 Int)
(declare-const x139 Int)
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
(declare-const x150 Int)
(declare-const x151 Int)
(declare-const x152 Int)
(declare-const x153 Int)
(declare-const v152 Int)
(declare-const x154 Int)
(declare-const x155 Int)
(declare-const v154 Int)
(declare-const x156 Int)
(declare-const x157 Int)
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
(declare-const v166 Int)
(declare-const x168 Int)
(declare-const x169 Int)
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
(declare-const x180 Int)
(declare-const x181 Int)
(declare-const v180 Int)
(declare-const x182 Int)
(declare-const x183 Int)
(declare-const x184 Int)
(declare-const x185 Int)
(declare-const v184 Int)
(declare-const x186 Int)
(declare-const x187 Int)
(declare-const v186 Int)
(declare-const x188 Int)
(declare-const x189 Int)
(declare-const x190 Int)
(declare-const x191 Int)
(declare-const v190 Int)
(declare-const x192 Int)
(declare-const x193 Int)
(declare-const x194 Int)
(declare-const x195 Int)
(declare-const x196 Int)
(declare-const x197 Int)
(declare-const x198 Int)
(declare-const x199 Int)

(assert(and
(< x34 x4) 
(sep
(blk x0 x1)
(hls x2 x3 v2)
(blk x4 x5)
(hls x6 x7 v6)
(blk x8 x9)
(pto x10 (c_data_t x11))
(hls x12 x13 v12)
(blk x14 x15)
(blk x16 x17)
(pto x18 (c_data_t x19))
(hls x20 x21 v20)
(blk x22 x23)
(hls x24 x25 v24)
(pto x26 (c_data_t x27))
(hls x28 x29 v28)
(hls x30 x31 v30)
(blk x32 x33)
(pto x34 (c_data_t x35))
(hls x36 x37 v36)
(hls x38 x39 v38)
(blk x40 x41)
(pto x42 (c_data_t x43))
(hls x44 x45 v44)
(pto x46 (c_data_t x47))
(pto x48 (c_data_t x49))
(blk x50 x51)
(blk x52 x53)
(hls x54 x55 v54)
(hls x56 x57 v56)
(hls x58 x59 v58)
(hls x60 x61 v60)
(hls x62 x63 v62)
(blk x64 x65)
(blk x66 x67)
(blk x68 x69)
(hls x70 x71 v70)
(pto x72 (c_data_t x73))
(pto x74 (c_data_t x75))
(pto x76 (c_data_t x77))
(blk x78 x79)
(blk x80 x81)
(blk x82 x83)
(blk x84 x85)
(hls x86 x87 v86)
(pto x88 (c_data_t x89))
(pto x90 (c_data_t x91))
(pto x92 (c_data_t x93))
(hls x94 x95 v94)
(pto x96 (c_data_t x97))
(blk x98 x99)
(hls x100 x101 v100)
(hls x102 x103 v102)
(hls x104 x105 v104)
(blk x106 x107)
(blk x108 x109)
(blk x110 x111)
(blk x112 x113)
(pto x114 (c_data_t x115))
(blk x116 x117)
(hls x118 x119 v118)
(hls x120 x121 v120)
(blk x122 x123)
(hls x124 x125 v124)
(pto x126 (c_data_t x127))
(blk x128 x129)
(blk x130 x131)
(blk x132 x133)
(hls x134 x135 v134)
(blk x136 x137)
(blk x138 x139)
(hls x140 x141 v140)
(blk x142 x143)
(blk x144 x145)
(blk x146 x147)
(hls x148 x149 v148)
(pto x150 (c_data_t x151))
(hls x152 x153 v152)
(hls x154 x155 v154)
(pto x156 (c_data_t x157))
(blk x158 x159)
(pto x160 (c_data_t x161))
(blk x162 x163)
(hls x164 x165 v164)
(hls x166 x167 v166)
(pto x168 (c_data_t x169))
(pto x170 (c_data_t x171))
(hls x172 x173 v172)
(blk x174 x175)
(hls x176 x177 v176)
(blk x178 x179)
(hls x180 x181 v180)
(pto x182 (c_data_t x183))
(hls x184 x185 v184)
(hls x186 x187 v186)
(pto x188 (c_data_t x189))
(hls x190 x191 v190)
(pto x192 (c_data_t x193))
(pto x194 (c_data_t x195))
(pto x196 (c_data_t x197))
(pto x198 (c_data_t x199))
)))

(check-sat)