Two-digit decimal counter using two seven-segment
displays and push-buttons.

```assembly
void setup()
{
  asm(
"		JMP start				\n"
"delay: LDI	 r23,  81			\n"	//Delay 1 sec
"w1:	LDI	 r24,  127 			\n"
"w2:	LDI  r25,  127 			\n"
"w3:	DEC  r25  				\n"
"		BRNE w3					\n"
"		DEC  r24				\n"
"		BRNE w2					\n"
"		DEC  r23				\n"
"       BRNE w1					\n"
"		RET						\n"
";Your Functions Code Begin		\n" //Write your code   
"								\n"	
";Your Functions Code End		\n" 
"								\n"    
"start:							\n" //Write your code
";Your Setup Code Begin			\n"    
"		IN 	 r16,  0x0A ;		\n" //r16 <- DDRD
"		IN	 r17,  0x04 ;       \n" //r17 <- DDRB
"		ORI	 r16,  0b11111111	\n"	//r16 for output "1", input "0"
"		ORI	 r17,  0b11001111	\n"	//r17 for output "1", input "0"
"		LDI  r20,  0x00;		\n" //r20 <- 0
"		LDI  r21,  0x00;		\n" //r21 <- 0
"		OUT  0x0A, r16			\n" //DDRD <- r16
"		OUT  0x04, r17			\n" //DDRB <- r17
";Your Setup Code End			\n" 
  );

}

void loop()
{
  asm(
"LOOP:							\n"//Write your code
";Your LOOP Code Begin			\n" // Our LOOP    
"		IN 	 r16,  0x0B ;		\n" // r16 <- PORTD
"		IN   r17,  0x03 ;		\n" // r17 <- PINB
"		CPI   r17, 32;  		\n" // comparing r17 and DEC32
"		BRGE  if				\n" // if they are equal to go elif
"		CPI   r17, 16;  		\n" // comparing r17 and DEC16
"		BRGE  elif				\n" // if they are equal to go if
"		JMP part				\n" // go to label part
"if:							\n" // if label for line 42
"		LDI	 r19,  0x20;		\n" // load r19 <- DEC32
"		LDI	 r18,  0x00;		\n" // load r18 <- 0
"		JMP  part				\n" // go to label part
"elif:    						\n" // if label for line 44
"		LDI	 r18,  0x10;		\n" // load r18 <- DEC16
"		LDI	 r19,  0x00;		\n" // load r19 <- 0
"part:							\n" // part label for lines 45,49
"		CPI   r18, 16;	 		\n" //  comparing r18 and DEC16
"		BREQ  if2				\n" // if they are equal to go if2
"		CPI   r19, 32;			\n" //  comparing r19 and DEC32
"		BREQ  elif2				\n" // if they are equal to go elif2
"		JMP part2				\n" // go to label part2      
"if2:    						\n" // label if2 for line 55
"		INC	 r16				\n" // increase r16 by 1
"		JMP part2				\n" // go to label part2      
"elif2:    						\n" // label elif2 for line 57
"       DEC  r16				\n" // decrease r16 by 1
"part2:							\n" // label part2 for lines 58,61
"		MOV	 r20, r16			\n" // r20 <- r16
"		CPI  r20, 10;			\n" //  comparing r20 and DEC10
"		BREQ decimal2			\n"// if they are equal to go decimal2
"		BRGE decimal			\n"// if r20 > 10 go to decimal
"		JMP part3				\n"// go to part3 label
"decimal:						\n"// label decimal for line 68
"		SUBI r20, 0x0A			\n" // Making r20 <- r20 - DEC10
"		CPI  r20, 10;			\n" //  comparing r20 and DEC10
"		BREQ decimal2			\n"// if they are equal to go decimal2
"		BRGE decimal			\n"// if r20 > 10 go to decimal
"		JMP part3				\n"// go to part3 label
"decimal2:						\n"// label decimal2 for line 67
"		CPI   r18, 16;	 		\n" //  comparing r18 and DEC16
"		BREQ  breq1				\n" // if they are equal to go breq1
"		CPI   r19, 32;			\n" //  comparing r19 and DEC32
"		BREQ  breq2				\n" // if they are equal to go breq2
"breq1:							\n"	// label breq1 for line 78
"		INC  r21    			\n"// increase r21 by 1
"		SUBI r20, 0x0A			\n" // Making r20 <- r20 - DEC10
"		JMP part3				\n" // go to part3 label
"breq2:							\n" // label breq2 for line 80
"		DEC  r21    			\n"// decrease r21 by 1
"		SUBI r20, 0x0A			\n" // Making r20 <- r20 - DEC10
"part3:							\n"// label part 3 for lines 69,75
"		ANDI r17,  0xF0			\n" // Making r17's rightmost 4 bits 0
"		EOR  r17,  r20			\n" // Making r17's rightmost 4 bits to r20's rightmost 4 bits
"		OUT  0x0B, r16			\n" // PORTD <- r16
"		OUT  0x08, r21			\n" // PORTC <- r21
"		OUT  0x05, r17			\n" // PORTB <- r17 
"		CALL delay				\n"	// Call delay function      
";Your LOOP Code End			\n" // LOOP end
"		JMP  LOOP				\n"
  );
  
}

```
