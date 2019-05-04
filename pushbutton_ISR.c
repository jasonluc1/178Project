#include "nios2_ctrl_reg_macros.h"


/*************************************
Function prototype
*************************************/
void VGA_text2 ( int , int, char *);
void VGA_box2 (int, int, int , int, short);


/***********************************
Global values declared
**********************************/
extern volatile int j;
extern volatile int m;
extern volatile int timeout;
//int fre;

/***************************************************************************************
 * Pushbutton - Interrupt Service Routine                                
 *                                                                          
 * This routine checks which KEY has been pressed. If key3 is press then use has the ability to use the keyboard to type on the monitor
 if key 2 is press the use will see a light show and words bouncing on the screen
 if key 1 is press then the promt on the screen will go back to main menu
****************************************************************************************/
void pushbutton_ISR( void )
{
	volatile int * KEY_ptr = (int *) 0x10000050;			// Key port address
	volatile int * PS2_ptr = (int *) 0x10000100;			// PS/2 port address
	volatile int * interval_timer_ptr = (int *) 0x10002000;	// interal timer base address
	
	int KEY_value;						

	KEY_value = *(KEY_ptr + 3);			// read the pushbutton interrupt register
	*(KEY_ptr + 3) = 0; 						// Clear the interrupt

	int screen_x = 319;
	int screen_y = 239;
	short color = 0x1863;		// a dark grey color

	char text_erase[100] = "                                                                                \0";

	/*******************************************
	Type on the terminal
	*******************************************/
	if (KEY_value == 0x8)					// check KEY3
	{
		*(PS2_ptr + 1) = 1;			/*write to the PS/2 controlregister to disable interrupts */
		*(PS2_ptr) = 0x0f;		/*clears the data */ 

		NIOS2_WRITE_IENABLE( 0x82 );	/* set interrupt mask bits for levels 0 (interval
											 * timer), 1 (pushbuttons), and 7 (PS/2) */
		VGA_box2 (0, 0, screen_x, screen_y, color);	// fill the screen with grey

		j = 1;
		m = 0;
		*(PS2_ptr + 1) = 0x1; 			/* write to the PS/2 Control register to enable interrupts */
			for(int i = 0; i < 80; i++){
			VGA_text2(0, i, text_erase);
			}
	}

	/*******************************************
	show the light show with bouncing letters
	*******************************************/

	else if (KEY_value == 0x4)				// check KEY2
	{
		NIOS2_WRITE_IENABLE( 0x03 );	/* set interrupt mask bits for levels 0 (interval
											 * timer), 1 (pushbuttons), and 7 (PS/2) */

		/* set the interval timer period for scrolling the HEX displays */
		int counter = 0x960000;				// 1/(50 MHz) x (0x960000) ~= 200 msec
		*(interval_timer_ptr + 0x2) = (counter & 0xFFFF);
		*(interval_timer_ptr + 0x3) = (counter >> 16) & 0xFFFF;	

		//int fre = 0;

		/* start interval timer, enable its interrupts */
		*(interval_timer_ptr + 1) = 0x7;	// STOP = 0, START = 1, CONT = 1, ITO = 1 

		int ALT_x1 = 0;
		int  ALT_x2 = 8; /* 178=fun = 7 chars */
		int  ALT_y = 0;

		/*Clearing any characters on the screen*/
		for(int i = 0; i < 80; i++){
			VGA_text2(0, i, text_erase);
		}

		// draw a medium-blue box around the above text, based on the character buffer coordinates
		int blue_x1 = 28; 
		int blue_x2 = 52; 
		int blue_y1 = 26; 
		int blue_y2 = 34;
	// character coords * 4 since characters are 4 x 4 pixel buffer coords (8 x 8 VGA coords)
		short color = 0x187F;		// a medium blue color
		VGA_box2 (blue_x1 * 4, blue_y1 * 4, blue_x2 * 4, blue_y2 * 4, color);

		char text_Project_VGA[80] = "ECE 178 Final Project\0";
		char text_Names_VGA[20] = "By Alwin & Jason\0";

		VGA_text2 (blue_x1 + 2, blue_y1 + 2, text_Project_VGA );
		VGA_text2 (blue_x1 + 4, blue_y1 + 5, text_Names_VGA);

	}

	/*******************************************
	Reset
	*******************************************/
	else if (KEY_value == 0x2)		//checks if KEY[1] is press
	{
		timeout = 1;
		NIOS2_WRITE_IENABLE( 0x02 );	/* set interrupt mask bits for levels 0 (interval
											 * timer), 1 (pushbuttons), and 7 (PS/2) */

		*(PS2_ptr + 1) = 0;			/*write to the PS/2 controlregister to disable interrupts */
		*(interval_timer_ptr + 1) = 0xA;	// STOP = 1, START = 0, CONT = 1, ITO = 0

		VGA_box2 (0, 0, screen_x, screen_y, color);	// fill the screen with grey


		char text_greet_VGA[20] = "WELCOME!\0";
		char text_one_VGA[50] = "1) Press button 3 to type on the screen.\0";
		char text_two_VGA[40] = "2) Press button 2 to have fun.\0";
		char text_three_VGA[40] = "3) Press button 1 to reset.\0";

		/*Clears the screen before outputting the text on screen so char buffer is empty*/
		for(int i = 0; i <240; i++){
		VGA_text2(0, i, text_erase);
		}

		int m = 0;
		//int fre = 0;

		/*output the menu on the screen*/
		VGA_text2 (2, 1 , text_greet_VGA);
		VGA_text2 (2 , 2, text_one_VGA);
		VGA_text2 (2, 3, text_two_VGA);
		VGA_text2 (2, 4, text_three_VGA);
	}

	return;
}



/****************************************************************************************
 * Subroutine to send a string of text to the VGA monitor 
****************************************************************************************/
void VGA_text2(int x, int y, char * text_ptr)
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

/****************************************************************************************
 * Draw a filled rectangle on the VGA monitor 
****************************************************************************************/
void VGA_box2(int x1, int y1, int x2, int y2, short pixel_color)
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
