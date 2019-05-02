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
switch(byte_data){
	case 0x1C: //a
		byte_data = 0x61;
        break;
	case 0x32:	//b
		byte_data = 0x62;
        break;
	case 0x21:	//c
		byte_data = 0x63;
        break;
	case 0x23:	//d
		byte_data = 0x64;
        break;
	case 0x24:	//e
		byte_data = 0x65;
        break;
	case 0x2B:	//f
		byte_data = 0x66;
        break;
	case 0x34:	//g
		byte_data = 0x67;
        break;
	case 0x33:	//h
		byte_data = 0x68;
        break;
	case 0x43:	//i
		byte_data = 0x69;
        break;
	case 0x3B:	//j
		byte_data = 0x6A;
        break;
	case 0x42:	//k
		byte_data = 0x6B;
        break;
	case 0x4B:	//l
		byte_data = 0x6C;
        break;
	case 0x3A:	//m
		byte_data = 0x6D;
        break;
	case 0x31:	//n
		byte_data = 0x6E;
        break;
	case 0x44:	//o
		byte_data = 0x6F;
        break;
	case 0x4D:	//p
		byte_data = 0x70;
        break;
	case 0x15:	//q
		byte_data = 0x71;
        break;
	case 0x2D:	//r
		byte_data = 0x72;
        break;
	case 0x1B:	//s
		byte_data = 0x73;
        break;
	case 0x2C:	//t
		byte_data = 0x74;
        break;
	case 0x3C:	//u
		byte_data = 0x75;
        break;
	case 0x2A:	//v
		byte_data = 0x76;
        break;
	case 0x1D:	//w
		byte_data = 0x77;
        break;
	case 0x22:	//x
		byte_data = 0x78;
        break;
	case 0x35:	//y
		byte_data = 0x79;
        break;
	case 0x1a:	//z
		byte_data = 0x7A;
        break;
	case 0x45:	//0
    	byte_data = 0x30;
        break;
	case 0x16:	//1
    	byte_data = 0x31;
        break;
	case 0x1E:	//2
    	byte_data = 0x32;
        break;
	case 0x26:	//3
    	byte_data = 0x33;
        break;
	case 0x25:	//4
    	byte_data = 0x34;
        break;
	case 0x2E:	//5
		byte_data = 0x35;
        break;
	case 0x36:	//6
		byte_data = 0x36;
        break;
	case 0x3D:	//7
		byte_data = 0x37;
        break;
	case 0x3E:	//
		byte_data = 0x38;
        break;
	case 0x46:	//9
		byte_data = 0x39;
        break;
	case 0x0E:	//`
		byte_data = 0x60;
        break;
	case 0x4E:	//-
    	byte_data = 0x2D; 
        break;
	case 0x55:	//=
    	byte_data = 0x3D;
        break;
	case 0x54:	//[
        byte_data = 0x5B;
        break;
	case 0x5B:	//]
		byte_data = 0x5D;
        break;
	case 0x4C:	//;
		byte_data = 0x3B;
        break;
	case 0x52:	//'
		byte_data = 0x27;
        break;
	case 0x41:	//,
		byte_data = 0x2C;
        break;
	case 0x49:	//.
		byte_data = 0x2E;
        break;
	case 0x5D:	//b slash
		byte_data = 0x2F;
        break;
	case 0x66:	//backspace //move cursor back
		byte_data = 0x00;
        break;
	case 0x29:	//space
		byte_data = 0x20;
        break;
	case 0x0D:	//tab //4 spaces?
		byte_data = 0x20;
        break;
	// case 0x58:	//caps
	// 	byte_data = 0x36;
    //     break;
	// case 0x12:	//L shift
	// 	byte_data = 0x36;
    //     break;
	// case 0x59:	//R shift
	// 	byte_data = 0x36;
    //     break;
	case 0x4A:	//f slash
		byte_data = 0x5C;
        break;
	case 0x7C:	//*
		byte_data = 0x2A;
        break;
	case 0x7B:	//-
		byte_data = 0x2D;
        break;
	case 0x79:	//+
		byte_data = 0x2B;
        break;
	case 0x7D:	//9
		byte_data = 0x39;
        break;
	case 0x75:	//8
		byte_data = 0x38;
        break;
	case 0x6C:	//7
		byte_data = 0x37;
        break;
	case 0x74:	//6
		byte_data = 0x36;
        break;
	case 0x73:	//5
		byte_data = 0x35;
        break;
	case 0x6B:	//4
		byte_data = 0x34;
        break;
	case 0x7A:	//3
		byte_data = 0x33;
        break;
	case 0x72:	//2
		byte_data = 0x32;
        break;
	case 0x69:	//1
		byte_data = 0x31;
        break;
	case 0x70:	//0
		byte_data = 0x30;
        break;
	case 0x71:	//.
		byte_data = 0x2E;
        break;
	case 0x05:	//f1
		byte_data = 0x01;
        break;
	case 0x06:	//f2
		byte_data = 0x02;
        break;
	case 0x04:	//f3
		byte_data = 0x03;
        break;
	case 0x0C:	//f4
		byte_data = 0x0B;
        break;
	case 0x03:	//f5
		byte_data = 0x0C;
        break;
	case 0x0B:	//f6
		byte_data = 0x0F;
        break;
	case 0x83:	//f7
		byte_data = 0x21;
        break;
	case 0x0A:	//f8
		byte_data = 0x24;
        break;
	case 0x01:	//f9
		byte_data = 0x40;
        break;
	case 0x09:	//f10
		byte_data = 0x09;
        break;
	case 0x78:	//f11
		byte_data = 0x3F;
        break;
	case 0x07:	//f12
		byte_data = 0x13;
        break;
	default:
		byte_data = 0x00;
        break;
}
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
