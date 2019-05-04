#include "nios2_ctrl_reg_macros.h"

/*******************
function prototypes 
*******************/
void VGA_text(int, int, char *);
void VGA_box(int, int, int, int, short);

/*******************
Global declaration
*******************/
volatile int timeout = 1;
extern volatile int color_change;
extern volatile int f1;
extern volatile int f2;
extern volatile int f3;
extern volatile int f4;
extern volatile int f5;
extern volatile int f6;
extern volatile int f7;
extern volatile int f8;
extern volatile int f9;
extern volatile int f10;
extern volatile int f11;
extern volatile int f12;
extern volatile int f13;
extern volatile int f14;
extern volatile int f15;
extern volatile int f16;
extern volatile int f17;
extern volatile int f18;
extern volatile int f19;
extern volatile int f20;
extern volatile int f21;
extern volatile int f22;
extern volatile int f23;
extern volatile int f24;
extern volatile int f25;
extern volatile int f26;
extern volatile int f27;
extern volatile int f28;
extern volatile int f29;
extern volatile int f30;
extern volatile int f31;
extern volatile int f32;
extern volatile int f33;
extern volatile int f34;
extern volatile int f35;
extern volatile int f36;
extern volatile int f37;
extern volatile int f38;
extern volatile int f39;
extern volatile int f40;
extern volatile int f41;
extern volatile int f42;
extern volatile int f43;
extern volatile int f44;
extern volatile int f45;
extern volatile int f46;
extern volatile int f47;
extern volatile int f48;
extern volatile int f49;
extern volatile int f50;
extern volatile int f51;
extern volatile int f52;
extern volatile int f53;
extern volatile int f54;
extern volatile int f55;
extern volatile int f56;
extern volatile int f57;
extern volatile int f58;
extern volatile int f59;
extern volatile int f60;
extern volatile int f61;
extern volatile int f62;
extern volatile int f63;
extern volatile int f64;
extern volatile int f65;
extern volatile int f66;
extern volatile int f67;
extern volatile int f68;
extern volatile int f69;
extern volatile int f70;
extern volatile int f71;
extern volatile int f72;
extern volatile int f73;
extern volatile int f74;
extern volatile int f75;
extern volatile int f76;
extern volatile int f77;

extern volatile int fshift;
// extern volatile int fcaps;


int main(void)
{
	/* Declare volatile pointers to I/O registers (volatile means that IO load
	   and store instructions will be used to access these pointer locations, 
	   instead of regular memory loads and stores) */
	volatile int *interval_timer_ptr = (int *)0x10002000; // interal timer base address
	volatile int *KEY_ptr = (int *)0x10000050;			  // pushbutton KEY address

	*(KEY_ptr + 2) = 0xE; /* write to the pushbutton interrupt mask register, and
											 * set 3 mask bits to 1 (bit 0 is Nios II reset) */

	NIOS2_WRITE_IENABLE(0x02); /* set interrupt mask bits for levels 0 (interval
											 * timer), 1 (pushbuttons), and 7 (PS/2) */

	NIOS2_WRITE_STATUS(1); // enable Nios II interrupts

	/* create a messages to be displayed on the VGA and LCD displays */
	char text_greet_VGA[20] = "WELCOME!\0";
	char text_one_VGA[50] = "1) Press button 3 to type on the screen.\0";
	char text_two_VGA[40] = "2) Press button 2 to have fun.\0";
	char text_three_VGA[40] = "3) Press button 1 to reset.\0";
	char text_erase[100] = "                                                                                \0";

	/* the following variables give the size of the pixel buffer */
	int screen_x = 319;
	int screen_y = 239;
	short color = 0x1863;					  // a dark grey color
	VGA_box(0, 0, screen_x, screen_y, color); // fill the screen with grey

	/*Clears the screen before outputting the text on screen so char buffer is empty*/
	for (int i = 0; i < 240; i++)
	{
		VGA_text(0, i, text_erase);
	}

	/*output the menu on the screen*/
	VGA_text(2, 1, text_greet_VGA);
	VGA_text(2, 2, text_one_VGA);
	VGA_text(2, 3, text_two_VGA);
	VGA_text(2, 4, text_three_VGA);

	/*enables the bouncing string when key2 is press*/
	int blue_x1 = 28;
	int blue_x2 = 52;
	int blue_y1 = 26;
	int blue_y2 = 34;

	char text_Move_VGA[10] = "178 = fun\0";
	char text_erase_VGA[10] = "         \0";

	int char_buffer_x = 79;
	int char_buffer_y = 59;

	int ALT_x1 = 0;
	int ALT_x2 = 8; /* 178 = fun = 9 chars */
	int ALT_y = 0;
	int ALT_inc_x = 1;
	int ALT_inc_y = 1;

	while (1)
	{

		while (!timeout)
		{

			/* move the ALTERA text around on the VGA screen */
			VGA_text(ALT_x1, ALT_y, text_erase_VGA); // erase
			ALT_x1 += ALT_inc_x;
			ALT_x2 += ALT_inc_x;
			ALT_y += ALT_inc_y;

			if ((ALT_y == char_buffer_y) || (ALT_y == 0))
				ALT_inc_y = -(ALT_inc_y);
			if ((ALT_x2 == char_buffer_x) || (ALT_x1 == 0))
				ALT_inc_x = -(ALT_inc_x);

			if ((ALT_y >= blue_y1 - 1) && (ALT_y <= blue_y2 + 1))
			{
				if (((ALT_x1 >= blue_x1 - 1) && (ALT_x1 <= blue_x2 + 1)) ||
					((ALT_x2 >= blue_x1 - 1) && (ALT_x2 <= blue_x2 + 1)))
				{
					if ((ALT_y == (blue_y1 - 1)) || (ALT_y == (blue_y2 + 1)))
						ALT_inc_y = -(ALT_inc_y);
					else
						ALT_inc_x = -(ALT_inc_x);
				}
			}
			VGA_text(ALT_x1, ALT_y, text_Move_VGA);
			timeout = 1;
		}
	};
}

/****************************************************************************************
 * Subroutine to send a string of text to the VGA monitor 
****************************************************************************************/
void VGA_text(int x, int y, char *text_ptr)
{
	int offset = 0;
	volatile char *character_buffer = (char *)0x09000000; // VGA character buffer

	/* assume that the text string fits on one line */
	offset = (y << 7) + x;
	while (*(text_ptr))
	{
		*(character_buffer + offset) = *(text_ptr); // write to the character buffer
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
	volatile short *pixel_buffer = (short *)0x08000000; // VGA pixel buffer

	/* assume that the box coordinates are valid */
	for (row = y1; row <= y2; row++)
	{
		col = x1;
		while (col <= x2)
		{
			offset = (row << 9) + col;
			*(pixel_buffer + offset) = pixel_color; // compute halfword address, set pixel
			++col;
		}
	}
}
