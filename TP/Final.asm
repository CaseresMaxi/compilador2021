include macros2.asm
include number.asm
.MODEL LARGE
.386
.STACK 200h

.DATA
;variables de la tabla de simbolos

_10_esddfloat 	dd	10.0	;esddfloat
_1_esddfloat 	dd	1.0	;esddfloat
_23_esddfloat 	dd	23.0	;esddfloat
_2_esddfloat 	dd	2.0	;esddfloat
_3_esddfloat 	dd	3.0	;esddfloat
_45_esddfloat 	dd	45.0	;esddfloat
_4_esddfloat 	dd	4.0	;esddfloat
_56_esddfloat 	dd	56.0	;esddfloat
_85_esddfloat 	dd	85.0	;esddfloat
__a1_esddfloat_esddstring	db	?	, '$' , 0 dup	(?)
__entero1_esddfloat 	dd	?	;esddfloat
__h1_esddfloat 	dd	?	;esddfloat
__h67_esddfloat 	dd	?	;esddfloat
__h70_esddfloat 	dd	?	;esddfloat
__h80_esddfloat 	dd	?	;esddfloat
__h90_esddfloat 	dd	?	;esddfloat
__id_esddfloat 	dd	?	;esddfloat
__variable1_esddfloat_esddstring	db	?	, '$' , 0 dup	(?)
_@varAuxResultado	dd	?	;esddfloat




.CODE
;comienzo de la zona de codigo


start:
MOV EAX,@DATA
MOV DS,EAX
MOV ES,EAX


FLD _3_esddfloat
FSTP _h67_esddfloat
FLD _4_esddfloat
FSTP _h80_esddfloat
FLD _45_esddfloat
FLD _56_esddfloat
FADD
FSTP _@varAuxResultado
FLD _@varAuxResultado
FSTP _id_esddfloat
FLD _23_esddfloat
FLD _85_esddfloat
FSUB
FSTP _@varAuxResultado
FLD _@varAuxResultado
FSTP _h1_esddfloat
FLD _h67_esddfloat
FLD _10_esddfloat
FMUL
FSTP _@varAuxResultado
FLD _1_esddfloat
FLD _@varAuxResultado
FADD
FSTP _@varAuxResultado
FLD _4_esddfloat
FLD _23_esddfloat
FMUL
FSTP _@varAuxResultado
FLD _@varAuxResultado
FLD _@varAuxResultado
FSUB
FSTP _@varAuxResultado
FLD _@varAuxResultado
FSTP _h70_esddfloat
FLD _2_esddfloat
FLD _h80_esddfloat
FDIV
FSTP _@varAuxResultado
FLD _3_esddfloat
FLD _@varAuxResultado
FADD
FSTP _@varAuxResultado
FLD _@varAuxResultado
FSTP _h90_esddfloat

MOV EAX, 4c00h  ; termina la ejecucion
INT 21h
END start;
;
