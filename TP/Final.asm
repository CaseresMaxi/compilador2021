include macros2.asm
include number.asm
.MODEL LARGE
.386
.STACK 200h

.DATA
;variables de la tabla de simbolos

_56_esddfloat	dd	56.0	;esddfloat
_58.69_esddfloat	dd	58.69	;esddfloat
_HOLACARLOS	db	"HOLACARLOS"	, '$' , 10 dup	(?)
_a1	db	?	, '$' , 0 dup	(?)
_entero1_esddfloat	dd	?	;esddfloat
_h1_esddfloat	dd	?	;esddfloat
_h67_esddfloat	dd	?	;esddfloat
_id_esddfloat	dd	?	;esddfloat
_variable1	db	?	, '$' , 0 dup	(?)




.CODE
;comienzo de la zona de codigo


start:
MOV EAX,@DATA
MOV DS,EAX
MOV ES,EAX


