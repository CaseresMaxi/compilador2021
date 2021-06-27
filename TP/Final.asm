include macros2.asm
include number.asm
.MODEL LARGE
.386
.STACK 200h

.DATA
;variables de la tabla de simbolos

_1_esddfloat	dd	1.0	;esddfloat
_10_esddfloat	dd	10.0	;esddfloat
_2_esddfloat	dd	2.0	;esddfloat
_23_esddfloat	dd	23.0	;esddfloat
_3_esddfloat	dd	3.0	;esddfloat
_4_esddfloat	dd	4.0	;esddfloat
_45_esddfloat	dd	45.0	;esddfloat
_56_esddfloat	dd	56.0	;esddfloat
_85_esddfloat	dd	85.0	;esddfloat
_a1	db	?	, '$' , 0 dup	(?)
_entero1_esddfloat	dd	?	;esddfloat
_h1_esddfloat	dd	?	;esddfloat
_h67_esddfloat	dd	?	;esddfloat
_h70_esddfloat	dd	?	;esddfloat
_h80_esddfloat	dd	?	;esddfloat
_h90_esddfloat	dd	?	;esddfloat
_id_esddfloat	dd	?	;esddfloat
_variable1	db	?	, '$' , 0 dup	(?)
_@varAuxResultado	dd	?	;esddfloat




.CODE
;comienzo de la zona de codigo


start:
MOV EAX,@DATA
MOV DS,EAX
MOV ES,EAX


FLD 3
FSTP h67
FLD 4
FSTP h80
FLD 45
FLD 56
FADD
FSTP _@varAuxResultado
FLD _@varAuxResultado
FSTP id
FLD 23
FLD 85
FSUB
FSTP _@varAuxResultado
FLD _@varAuxResultado
FSTP h1
FLD h67
FLD 10
FMUL
FSTP _@varAuxResultado
FLD 1
FLD _@varAuxResultado
FADD
FSTP _@varAuxResultado
FLD 4
FLD 23
FMUL
FSTP _@varAuxResultado
FLD _@varAuxResultado
FLD _@varAuxResultado
FSUB
FSTP _@varAuxResultado
FLD _@varAuxResultado
FSTP h70
FLD 2
FLD h80
FDIV
FSTP _@varAuxResultado
FLD 3
FLD _@varAuxResultado
FADD
FSTP _@varAuxResultado
FLD _@varAuxResultado
FSTP h90
