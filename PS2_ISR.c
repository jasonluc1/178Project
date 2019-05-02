#include <stdio.h>
/***************
Function Prototype
***************/
void VGA_t(int, int, char *);


/***************
global variable declaration 
***************/
int j = 2;

/***************************************************************************************
 * Pushbutton - Interrupt Service Routine                                
 *                                                                          
 * This routine checks which KEY has been pressed. If it is KEY1 or KEY2, it writes this 
 * value to the global variable key_pressed. If it is KEY3 then it loads the SW switch 
 * values and stores in the variable pattern
****************************************************************************************/

void PS2_ISR( void )
{
  	volatile int * PS2_ptr = (int *) 0x10000100;		// PS/2 port address
	int PS2_data, RAVAIL;
	char byte_data;

	PS2_data = *(PS2_ptr);									// read the Data register in the PS/2 port
	RAVAIL = (PS2_data & 0xFFFF0000) >> 16;			// extract the RAVAIL field
	if (RAVAIL > 0)
	{
		byte_data = PS2_data & 0xFF; /*gets data and stores it onto byte_data*/
		if(byte_data!=0x5A){
			VGA_t(j, 1, &byte_data);
			j += 1;
		}

		printf(" %d", byte_data);
		//if ( (byte2 == (char) 0xAA) && (byte3 == (char) 0x00) )
			// mouse inserted; initialize sending of data
			//*(PS2_ptr) = 0xF4;
	}
	return;
}



/****************************************************************************************
 * Subroutine to send a string of text to the VGA monitor 
****************************************************************************************/
void VGA_t(int x, int y, char * text_ptr)
{
	int offset;
  	volatile char * character_buffer = (char *) 0x09000000;	// VGA character buffer

	/* assume that the text string fits on one line */
	offset = (y << 7) + x;
	while ( *(text_ptr) )
	{
		*(character_buffer + offset) = *(text_ptr);	// write to the character buffer
		++text_ptr;
		++offset;
	}
}
