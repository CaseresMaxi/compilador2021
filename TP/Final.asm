include macros2.asm
include number.asm
.MODEL LARGE
.386
.STACK 200h

.DATA
;variables de la tabla de simbolos

_2_esddfloat	dd	2.0	;esddfloat
_5_esddfloat	dd	5.0	;esddfloat
_Inicio	db	"Inicio"	, '$' , 6 dup	(?)
_cont_esddfloat	dd	?	;esddfloat
_id_esddfloat	dd	?	;esddfloat
_id2_esddfloat	dd	?	;esddfloat
_id3_esddfloat	dd	?	;esddfloat
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


	displayString _Inicio 
	newline 1
	FLD _5_esddfloat
	FLD _2_esddfloat
	FDIV
	FSTP _@varAux1_esddfloat
	FLD _@varAux1_esddfloat
	FSTP _id2_esddfloat
	DisplayFloat _id2_esddfloat,2
	newline 1

MOV EAX, 4c00h  ; termina la ejecucion
INT 21h
END start;
;
