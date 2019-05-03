/**********************************
Function Prototype
**********************************/
void VGA_text3(int, int, char *);
void VGA_box3(int, int, int, int, short);

/**********************************
Global variable declaration
**********************************/
extern volatile int timeout;
int color_change = 0;

/*****************************************************************************
 * Interval timer interrupt service routine
 *                                                                          
 * Makes the 178 = fun bounce and also change the box in the middle to change colors
 * 
******************************************************************************/
void interval_timer_ISR()
{
	volatile int *interval_timer_ptr = (int *)0x10002000;

	*(interval_timer_ptr) = 0; // clear the interrupt
	timeout = 0;			   // set global variable

	color_change += 1;																			//a counter to access the array of colors
	short colors[9] = {0x187f, 0xf800, 0x07e0, 0x001f, 0x0000, 0xffff, 0xffe0, 0xf81f, 0x07ff}; //and array which hold values of color blue, red, greeen

	/*counter which will make sure the counter to access the array never pass 2*/
	if (color_change > 9)
	{
		color_change = 0;
	}

	/*refreshing the box in the middle*/
	int blue_x1 = 28;
	int blue_x2 = 52;
	int blue_y1 = 26;
	int blue_y2 = 34;
	short colorchoose = colors[color_change]; //chooses which color is up next

	VGA_box3(blue_x1 * 4, blue_y1 * 4, blue_x2 * 4, blue_y2 * 4, colorchoose);

	char text_Project_VGA[80] = "ECE 178 Final Project\0";
	char text_Names_VGA[20] = "By Alwin & Jason\0";

	VGA_text3(blue_x1 + 2, blue_y1 + 2, text_Project_VGA);
	VGA_text3(blue_x1 + 4, blue_y1 + 5, text_Names_VGA);

	timeout = 0;
	return;
}

/****************************************************************************************
 * Subroutine to send a string of text to the VGA monitor 
****************************************************************************************/
void VGA_text3(int x, int y, char *text_ptr)
{
	int offset;
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
void VGA_box3(int x1, int y1, int x2, int y2, short pixel_color)
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
