#line 1 "D:/402/MyProject.c"
void main() {
 TRISC.F0 = 0;
 TRISD.F3 = 0;

 while(1){
 PORTC.F0 = 1;
 Delay_ms(500);
 PORTC.F0 = 0;
 Delay_ms(500);

 PORTD.F3 = 1;
 Delay_ms(500);
 PORTD.F3 = 0;
 Delay_ms(500);
}
}
