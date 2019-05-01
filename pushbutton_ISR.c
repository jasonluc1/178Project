
/***************************************************************************************
 * Pushbutton - Interrupt Service Routine                                
 *                                                                          
 * This routine checks which KEY has been pressed. If it is KEY1 or KEY2, it writes this 
 * value to the global variable key_pressed. If it is KEY3 then it loads the SW switch 
 * values and stores in the variable pattern
****************************************************************************************/
void pushbutton_ISR( void )
{
	volatile int * KEY_ptr = (int *) 0x10000050;
	volatile int * PS2_ptr = (int *) 0x10000100;			// PS/2 port address
	
	int KEY_value;

	KEY_value = *(KEY_ptr + 3);			// read the pushbutton interrupt register
	*(KEY_ptr + 3) = 0; 						// Clear the interrupt

	if (KEY_value == 0x8)					// check KEY1
	{
		*(PS2_ptr + 1) = 0x1; 			/* write to the PS/2 Control register to enable interrupts */
	}
	else if (KEY_value == 0x1)				// check KEY2
	{
		*(PS2_ptr + 1) = 0;			/*write to the PS/2 controlregister to disable interrupts */
		/* the following variables give the size of the pixel buffer */
		screen_x = 319; screen_y = 239;
		color = 0x1863;		// a dark grey color
		VGA_box (0, 0, screen_x, screen_y, color);	// fill the screen with grey
		char text_greet_VGA[20] = "WELCOME!\0";
		char text_one_VGA[50] = "1) KEY 3 will enable PS/2 to type on the screen\0";
		char text_two_VGA[30] = "2) KEY 2 will disable PS/2\0";
	}
	//else if (KEY_value == 0x8)		//checks if KEY[3] is press
	//{
		/*add another function to when the KEY[3] is press*/
	//}
	return;
}



/****************************************************************************************
 * Subroutine to send a string of text to the VGA monitor 
****************************************************************************************/
void VGA_text(int x, int y, char * text_ptr)
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
