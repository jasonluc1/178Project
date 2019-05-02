#include "nios2_ctrl_reg_macros.h"

/* function prototypes */
void VGA_text (int, int, char *);
void VGA_box (int, int, int, int, short);


int main(void)
{
	/* Declare volatile pointers to I/O registers (volatile means that IO load
	   and store instructions will be used to access these pointer locations, 
	   instead of regular memory loads and stores) */
	volatile int * interval_timer_ptr = (int *) 0x10002000;	// interal timer base address
	volatile int * KEY_ptr = (int *) 0x10000050;					// pushbutton KEY address
//	volatile int * PS2_ptr = (int *) 0x10000100;					// PS/2 port address


	int screen_x; int screen_y; int char_buffer_x; int char_buffer_y;
	short color;
	
	*(KEY_ptr + 2) = 0xE; 			/* write to the pushbutton interrupt mask register, and
											 * set 3 mask bits to 1 (bit 0 is Nios II reset) */

//	*(PS2_ptr) = 0xFF;				/* reset clears the data register*/


	NIOS2_WRITE_IENABLE( 0xC3 );	/* set interrupt mask bits for levels 0 (interval
											 * timer), 1 (pushbuttons), 6 (audio), and 7 (PS/2) */

	NIOS2_WRITE_STATUS( 1 );		// enable Nios II interrupts

	/* create a messages to be displayed on the VGA and LCD displays */
	char text_greet_VGA[20] = "Welcome!!\0";
	char text_one_VGA[50] = "1) KEY 3 will enable PS/2 to type on the screen\0";
	char text_two_VGA[30] = "2) KEY 2 will disable PS/2\0";
	char text_erase[50] = "                                            \0";


	/* the following variables give the size of the pixel buffer */
	screen_x = 319; screen_y = 239;
	color = 0x1863;		// a dark grey color
	VGA_box (0, 0, screen_x, screen_y, color);	// fill the screen with grey


	/*Clears the screen before outputting the text on screen so char buffer is empty*/
	VGA_text(2, 1, text_erase);
	VGA_text(2, 2, text_erase);
	VGA_text(2, 3, text_erase);


	/*output the menu on the screen*/
	VGA_text (2, 1 , text_greet_VGA);
	VGA_text (2 , 2, text_one_VGA);
	VGA_text (2, 3, text_two_VGA);


	while (1);
}

/****************************************************************************************
 * Subroutine to send a string of text to the VGA monitor 
****************************************************************************************/
void VGA_text(int x, int y, char * text_ptr)
{
	int offset = 0;
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

/****************************************************************************************
 * Draw a filled rectangle on the VGA monitor 
****************************************************************************************/
void VGA_box(int x1, int y1, int x2, int y2, short pixel_color)
{
	int offset, row, col;
  	volatile short * pixel_buffer = (short *) 0x08000000;	// VGA pixel buffer

	/* assume that the box coordinates are valid */
	for (row = y1; row <= y2; row++)
	{
		col = x1;
		while (col <= x2)
		{
			offset = (row << 9) + col;
			*(pixel_buffer + offset) = pixel_color;	// compute halfword address, set pixel
			++col;
		}
	}
}

