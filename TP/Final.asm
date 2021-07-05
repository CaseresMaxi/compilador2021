include macros2.asm
include number.asm
.MODEL LARGE
.386
.STACK 200h

.DATA
;variables de la tabla de simbolos

_1_esddfloat	dd	1.0	;esddfloat
_15_esddfloat	dd	15.0	;esddfloat
_2_esddfloat	dd	2.0	;esddfloat
_20_esddfloat	dd	20.0	;esddfloat
_25_esddfloat	dd	25.0	;esddfloat
_3_esddfloat	dd	3.0	;esddfloat
_5_esddfloat	dd	5.0	;esddfloat
_65534_50_esddfloat	dd	65534.50	;esddfloat
_7_esddfloat	dd	7.0	;esddfloat
_8_esddfloat	dd	8.0	;esddfloat
_Ingresevalorvalordeid2	db	"Ingrese valor valor de id2"	, '$' , 26 dup	(?)
_Ingresevalorvalorid1	db	"Ingrese valor valor id1"	, '$' , 23 dup	(?)
_Valordeid2	db	"Valor de id2:"	, '$' , 13 dup	(?)
_id1esmayora20	db	"id1 es mayor a 20"	, '$' , 17 dup	(?)
_id1esmayora20oa25	db	"id1 es mayor a 20 o a 25"	, '$' , 24 dup	(?)
_id1esmayora25	db	"id1 es mayor a 25"	, '$' , 17 dup	(?)
_id1esmenora20	db	"id1 es menor a 20"	, '$' , 17 dup	(?)
_id1estaentre10y15	db	"id1 esta entre 10 y 15"	, '$' , 22 dup	(?)
_id1_esddfloat	dd	?	;esddfloat
_id2_esddfloat	dd	?	;esddfloat
_id3_esddfloat	dd	?	;esddfloat
_id4_esddfloat	dd	?	;esddfloat
_str	db	?	, '$' , 200 dup	(?)
_@varAux1_esddfloat	dd	?	;esddfloat
_@varAux2_esddfloat	dd	?	;esddfloat
_@varAux3_esddfloat	dd	?	;esddfloat
_@varAux4_esddfloat	dd	?	;esddfloat
_@varAux5_esddfloat	dd	?	;esddfloat
_@varAux6_esddfloat	dd	?	;esddfloat
_@varAux7_esddfloat	dd	?	;esddfloat
_@varAux8_esddfloat	dd	?	;esddfloat
_@varAux9_esddfloat	dd	?	;esddfloat
_@varAux10_esddfloat	dd	?	;esddfloat




.CODE
;comienzo de la zona de codigo


start:
MOV EAX,@DATA
MOV DS,EAX
MOV ES,EAX


	FLD _65534_50_esddfloat
	FSTP _id4_esddfloat
	displayString _Ingresevalorvalorid1 
	newline 1
	getFloat _id1_esddfloat
	FLD _5_esddfloat
	FLD _5_esddfloat
	FADD
	FSTP _@varAux1_esddfloat
	FLD _@varAux1_esddfloat
	FLD _id1_esddfloat
	FCOM
	FSTSW AX
	SAHF
	JB  ET22
	FLD _15_esddfloat
	FLD _id1_esddfloat
	FCOM
	FSTSW AX
	SAHF
	JA  ET22
	displayString _id1estaentre10y15 
	newline 1
ET22:
	FLD _20_esddfloat
	FLD _id1_esddfloat
	FCOM
	FSTSW AX
	SAHF
	JA  ET33
	FLD _25_esddfloat
	FLD _id1_esddfloat
	FCOM
	FSTSW AX
	SAHF
	JNA  ET51
ET33:
	displayString _id1esmayora20oa25 
	newline 1
	FLD _25_esddfloat
	FLD _id1_esddfloat
	FCOM
	FSTSW AX
	SAHF
	JNA  ET45
	displayString _id1esmayora25 
	newline 1
	JMP  ET48
ET45:
	displayString _id1esmayora20 
	newline 1
ET48:
	JMP  ET54
ET51:
	displayString _id1esmenora20 
	newline 1
ET54:
	displayString _Ingresevalorvalordeid2 
	newline 1
	getFloat _id2_esddfloat
	DisplayFloat _id2_esddfloat,2
	newline 1
ET61:
	FLD _5_esddfloat
	FLD _id2_esddfloat
	FCOM
	FSTSW AX
	SAHF
	JAE  ET78
	displayString _Valordeid2 
	newline 1
	DisplayFloat _id2_esddfloat,2
	newline 1
	FLD _id2_esddfloat
	FLD _1_esddfloat
	FADD
	FSTP _@varAux1_esddfloat
	FLD _@varAux1_esddfloat
	FSTP _id2_esddfloat
	JMP  ET61
ET78:
	FLD _5_esddfloat
	FLD _id2_esddfloat
	FCOM
	FSTSW AX
	SAHF
	JNE  ET88
	displayString _Valordeid2 
	newline 1
	DisplayFloat _id2_esddfloat,2
	newline 1
ET88:
	FLD _3_esddfloat
	FLD _2_esddfloat
	FMUL
	FSTP _@varAux1_esddfloat
	FLD _1_esddfloat
	FLD _@varAux1_esddfloat
	FADD
	FSTP _@varAux2_esddfloat
	FLD _@varAux2_esddfloat
	FSTP _id3_esddfloat
ET96:
	FLD _7_esddfloat
	FLD _id3_esddfloat
	FCOM
	FSTSW AX
	SAHF
	JE  ET109
	FLD _15_esddfloat
	FLD _id3_esddfloat
	FCOM
	FSTSW AX
	SAHF
	JE  ET109
	JMP  ET131
ET109:
	FLD _3_esddfloat
	FLD _id3_esddfloat
	FPREM
	FSTP _@varAux1_esddfloat
	FLD _@varAux1_esddfloat
	FSTP _id4_esddfloat
	DisplayFloat _id4_esddfloat,2
	newline 1
	FLD _2_esddfloat
	FLD _id3_esddfloat
	FPREM
	FSTP _@varAux1_esddfloat
	FLD _id3_esddfloat
	FLD _@varAux1_esddfloat
	FSUB
	FSTP _@varAux2_esddfloat
	FLD _@varAux2_esddfloat
	FLD _2_esddfloat
	FDIV
	FSTP _@varAux3_esddfloat
	FLD _@varAux3_esddfloat
	FSTP _id4_esddfloat
	DisplayFloat _id4_esddfloat,2
	newline 1
	FLD _id3_esddfloat
	FLD _8_esddfloat
	FADD
	FSTP _@varAux1_esddfloat
	FLD _@varAux1_esddfloat
	FSTP _id3_esddfloat
	JMP  ET96
ET131:

MOV EAX, 4c00h  ; termina la ejecucion
INT 21h
END start;
;
