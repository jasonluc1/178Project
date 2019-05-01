#include "nios2_ctrl_reg_macros.h"

/* these globals are written by interrupt service routines; we have to declare 
 * these as volatile to avoid the compiler caching their values in registers */
// extern volatile char byte1, byte2, byte3;			/* modified by PS/2 interrupt service routine */
// extern volatile int timeout;							// used to synchronize with the timer

/* function prototypes */
void VGA_text (int, int, char *);
void VGA_box (int, int, int, int, short);
// void HEX_PS2(char, char, char);

/********************************************************************************
 * This program demonstrates use of the media ports in the DE2 Media Computer
 *
 * It performs the following: 
 *  	1. records audio for about 10 seconds when an interrupt is generated by
 *  	   pressing KEY[1]. LEDG[0] is lit while recording. Audio recording is 
 *  	   controlled by using interrupts
 * 	2. plays the recorded audio when an interrupt is generated by pressing
 * 	   KEY[2]. LEDG[1] is lit while playing. Audio playback is controlled by 
 * 	   using interrupts
 * 	3. Draws a blue box on the VGA display, and places a text string inside
 * 	   the box. Also, moves the word ALTERA around the display, "bouncing" off
 * 	   the blue box and screen edges
 * 	4. Shows a text message on the LCD display, and scrolls the message
 * 	5. Displays the last three bytes of data received from the PS/2 port 
 * 	   on the HEX displays on the DE2 board. The PS/2 port is handled using 
 * 	   interrupts
 * 	6. The speed of scrolling the LCD display and of refreshing the VGA screen
 * 	   are controlled by interrupts from the interval timer
********************************************************************************/
int main(void)
{
	/* Declare volatile pointers to I/O registers (volatile means that IO load
	   and store instructions will be used to access these pointer locations, 
	   instead of regular memory loads and stores) */
	volatile int * interval_timer_ptr = (int *) 0x10002000;	// interal timer base address
	volatile int * KEY_ptr = (int *) 0x10000050;					// pushbutton KEY address
	volatile int * PS2_ptr = (int *) 0x10000100;					// PS/2 port address

	/* initialize some variables */
//	byte1 = 0; byte2 = 0; byte3 = 0; 			// used to hold PS/2 data
//	timeout = 0;										// synchronize with the timer

	/* these variables are used for a blue box and a "bouncing" ALTERA on the VGA screen */
//	int ALT_x1; int ALT_x2; int ALT_y; 
//	int ALT_inc_x; int ALT_inc_y;
//	int blue_x1; int blue_y1; int blue_x2; int blue_y2; 
	int screen_x; int screen_y; int char_buffer_x; int char_buffer_y;
	short color;

	/* set the interval timer period for scrolling the HEX displays */
//	int counter = 0x960000;				// 1/(50 MHz) x (0x960000) ~= 200 msec
//	*(interval_timer_ptr + 0x2) = (counter & 0xFFFF);
//	*(interval_timer_ptr + 0x3) = (counter >> 16) & 0xFFFF;

	/* start interval timer, enable its interruts */
//	*(interval_timer_ptr + 1) = 0x7;	// STOP = 0, START = 1, CONT = 1, ITO = 1 
	
	*(KEY_ptr + 2) = 0xF; 			/* write to the pushbutton interrupt mask register, and
											 * set 3 mask bits to 1 (bit 0 is Nios II reset) */

	*(PS2_ptr) = 0xFF;				/* reset clears the data register*/


	NIOS2_WRITE_IENABLE( 0xC3 );	/* set interrupt mask bits for levels 0 (interval
											 * timer), 1 (pushbuttons), 6 (audio), and 7 (PS/2) */

	NIOS2_WRITE_STATUS( 1 );		// enable Nios II interrupts

	/* create a messages to be displayed on the VGA and LCD displays */
	char text_greet_VGA[20] = "WELCOME!\0";
	char text_one_VGA[50] = "1) KEY 3 will enable PS/2 to type on the screen\0";
	char text_two_VGA[30] = "2) KEY 2 will disable PS/2\0";
//	char text_ALTERA[10] = "ALTERA\0";
//	char text_erase[10] = "      \0";

	/* output text message to the LCD */
	/*LCD_cursor (0,0);										// set LCD cursor location to top row
	LCD_text (text_top_LCD);
	LCD_cursor_off ();									// turn off the LCD cursor  */

	/* the following variables give the size of the pixel buffer */
	screen_x = 319; screen_y = 239;
	color = 0x1863;		// a dark grey color
	VGA_box (0, 0, screen_x, screen_y, color);	// fill the screen with grey
	// draw a medium-blue box around the above text, based on the character buffer coordinates
//	blue_x1 = 28; blue_x2 = 52; blue_y1 = 26; blue_y2 = 34;
	// character coords * 4 since characters are 4 x 4 pixel buffer coords (8 x 8 VGA coords)
//	color = 0x187F;		// a medium blue color
//	VGA_box (blue_x1 * 4, blue_y1 * 4, blue_x2 * 4, blue_y2 * 4, color);
	/* output text message in the middle of the VGA monitor */
	VGA_text (2, 1 , text_greet_VGA);
	VGA_text (2 , 2, text_one_VGA);
	VGA_text (2, 3, text_two_VGA);

//	char_buffer_x = 79; char_buffer_y = 59;
//	ALT_x1 = 0; ALT_x2 = 5/* ALTERA = 6 chars */; ALT_y = 0; ALT_inc_x = 1; ALT_inc_y = 1;
//	VGA_text (ALT_x1, ALT_y, text_ALTERA);
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


/****************************************************************************************
 * Subroutine to show a string of HEX data on the HEX displays
****************************************************************************************/
//void HEX_PS2(char b1, char b2, char b3)
//{
//	volatile int * HEX3_HEX0_ptr = (int *) 0x10000020;
//	volatile int * HEX7_HEX4_ptr = (int *) 0x10000030;

	/* SEVEN_SEGMENT_DECODE_TABLE gives the on/off settings for all segments in 
	 * a single 7-seg display in the DE2 Media Computer, for the hex digits 0 - F */
//	unsigned char	seven_seg_decode_table[] = {	0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 
//		  										0x7F, 0x67, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71 };
//	unsigned char	hex_segs[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
//	unsigned int shift_buffer, nibble;
//	unsigned char code;
//	int i;
//
//	shift_buffer = (b1 << 16) | (b2 << 8) | b3;
//	for ( i = 0; i < 6; ++i )
//	{
//		nibble = shift_buffer & 0x0000000F;		// character is in rightmost nibble
//		code = seven_seg_decode_table[nibble];
//		hex_segs[i] = code;
//		shift_buffer = shift_buffer >> 4;
//	}
	/* drive the hex displays */
//	*(HEX3_HEX0_ptr) = *(int *) (hex_segs);
//	*(HEX7_HEX4_ptr) = *(int *) (hex_segs+4);
//}



/****************************************************************************************
 * Subroutine to move the LCD cursor
****************************************************************************************/
/*void LCD_cursor(int x, int y)
{
  	volatile char * LCD_display_ptr = (char *) 0x10003050;	// 16x2 character display
	char instruction;

	instruction = x;
	if (y != 0) instruction |= 0x40;				// set bit 6 for bottom row
	instruction |= 0x80;								// need to set bit 7 to set the cursor location
	*(LCD_display_ptr) = instruction;			// write to the LCD instruction register
} */

/****************************************************************************************
 * Subroutine to send a string of text to the LCD 
****************************************************************************************/
/*void LCD_text(char * text_ptr)
{
  	volatile char * LCD_display_ptr = (char *) 0x10003050;	// 16x2 character display

	while ( *(text_ptr) )
	{
		*(LCD_display_ptr + 1) = *(text_ptr);	// write to the LCD data register
		++text_ptr;
	}
}*/

/****************************************************************************************
 * Subroutine to turn off the LCD cursor
****************************************************************************************/
/*void LCD_cursor_off(void)
{
  	volatile char * LCD_display_ptr = (char *) 0x10003050;	// 16x2 character display
	*(LCD_display_ptr) = 0x0C;											// turn off the LCD cursor
}*/




