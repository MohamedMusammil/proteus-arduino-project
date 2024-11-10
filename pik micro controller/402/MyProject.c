void main() {
     TRISC.F0 = 0;    //configure rco as output
     TRISD.F3 = 0;
     
     while(1){
     PORTC.F0 = 1;        //turn on led at rco
     Delay_ms(500);       //  wait for 500 milliseconds
     PORTC.F0 = 0;         //set rco low
     Delay_ms(500);         //wait for 500 milliseconds
     
     PORTD.F3 = 1;        //turn on led at rco
     Delay_ms(500);       //  wait for 500 milliseconds
     PORTD.F3 = 0;         //set rco low
     Delay_ms(500);         //wait for 500 milliseconds
}
}