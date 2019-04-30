extern volatile int buffer_index;

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

	if (KEY_value == 0x2)					// check KEY1
	{
		*(PS2_ptr + 1) = 0x1; 			/* write to the PS/2 Control register to enable interrupts */
	}
	else if (KEY_value == 0x4)				// check KEY2
	{
		*(PS2_ptr + 1) = 0;			/*write to the PS/2 controlregister to disable interrupts */
	}
	//else if (KEY_value == 0x8)		//checks if KEY[3] is press
	//{
		/*add another function to when the KEY[3] is press*/
	//}
	return;
}
