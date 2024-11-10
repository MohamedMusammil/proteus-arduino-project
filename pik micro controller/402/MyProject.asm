
_main:

;MyProject.c,1 :: 		void main() {
;MyProject.c,2 :: 		TRISC.F0 = 0;    //configure rco as output
	BCF        TRISC+0, 0
;MyProject.c,3 :: 		TRISD.F3 = 0;
	BCF        TRISD+0, 3
;MyProject.c,5 :: 		while(1){
L_main0:
;MyProject.c,6 :: 		PORTC.F0 = 1;        //turn on led at rco
	BSF        PORTC+0, 0
;MyProject.c,7 :: 		Delay_ms(500);       //  wait for 500 milliseconds
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main2:
	DECFSZ     R13+0, 1
	GOTO       L_main2
	DECFSZ     R12+0, 1
	GOTO       L_main2
	DECFSZ     R11+0, 1
	GOTO       L_main2
	NOP
	NOP
;MyProject.c,8 :: 		PORTC.F0 = 0;         //set rco low
	BCF        PORTC+0, 0
;MyProject.c,9 :: 		Delay_ms(500);         //wait for 500 milliseconds
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main3:
	DECFSZ     R13+0, 1
	GOTO       L_main3
	DECFSZ     R12+0, 1
	GOTO       L_main3
	DECFSZ     R11+0, 1
	GOTO       L_main3
	NOP
	NOP
;MyProject.c,11 :: 		PORTD.F3 = 1;        //turn on led at rco
	BSF        PORTD+0, 3
;MyProject.c,12 :: 		Delay_ms(500);       //  wait for 500 milliseconds
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main4:
	DECFSZ     R13+0, 1
	GOTO       L_main4
	DECFSZ     R12+0, 1
	GOTO       L_main4
	DECFSZ     R11+0, 1
	GOTO       L_main4
	NOP
	NOP
;MyProject.c,13 :: 		PORTD.F3 = 0;         //set rco low
	BCF        PORTD+0, 3
;MyProject.c,14 :: 		Delay_ms(500);         //wait for 500 milliseconds
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main5:
	DECFSZ     R13+0, 1
	GOTO       L_main5
	DECFSZ     R12+0, 1
	GOTO       L_main5
	DECFSZ     R11+0, 1
	GOTO       L_main5
	NOP
	NOP
;MyProject.c,15 :: 		}
	GOTO       L_main0
;MyProject.c,16 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
