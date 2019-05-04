#include <stdio.h>
/***************
Function Prototype
***************/
void VGA_t(int, int, char *);


/***************
global variable declaration 
***************/
int j = 1;
int m = 0;
int f1 = 0;
int f2 = 0;
int f3 = 0;
int f4 = 0;
int f5 = 0;
int f6 = 0;
int f7 = 0;
int f8 = 0;
int f9 = 0;
int f10 = 0;
int f11 = 0;
int f12 = 0;
int f13 = 0;
int f14 = 0;
int f15 = 0;
int f16 = 0;
int f17 = 0;
int f18 = 0;
int f19 = 0;
int f20 = 0;
int f21 = 0;
int f22 = 0;
int f23 = 0;
int f24 = 0;
int f25 = 0;
int f26 = 0;
int f27 = 0;
int f28 = 0;
int f29 = 0;
int f30 = 0;
int f31 = 0;
int f32 = 0;
int f33 = 0;
int f34 = 0;
int f35 = 0;
int f36 = 0;
int f37 = 0;
int f38 = 0;
int f39 = 0;
int f40 = 0;
int f41 = 0;
int f42 = 0;
int f43 = 0;
int f44 = 0;
int f45 = 0;
int f46 = 0;
int f47 = 0;
int f48 = 0;
int f49 = 0;
int f50 = 0;
int f51 = 0;
int f52 = 0;
int f53 = 0;
int f54 = 0;
int f55 = 0;
int f56 = 0;
int f57 = 0;
int f58 = 0;
int f59 = 0;
int f60 = 0;
int f61 = 0;
int f62 = 0;
int f63 = 0;
int f64 = 0;
int f65 = 0;
int f66 = 0;
int f67 = 0;
int f68 = 0;
int f69 = 0;
int f70 = 0;
int f71 = 0;
int f72 = 0;
int f73 = 0;
int f74 = 0;
int f75 = 0;
int f76 = 0;
int f77 = 0;

int fshift = 0;
// int fcaps = 0;


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
	int PS2_data, PS2_data2, RAVAIL;
	char byte_data;

	PS2_data = *(PS2_ptr);									// read the Data register in the PS/2 port

	RAVAIL = (PS2_data & 0xFFFF0000) >> 16;			// extract the RAVAIL field
	if (RAVAIL > 0)
	{
		byte_data = PS2_data & 0xFF; /*gets data and stores it onto byte_data*/
		if(j>78){
			j = 2;
			m+=1;
		}
		if(fshift==1){
			switch(byte_data){
				case 0x1C: //A
					if(f1==0){
						byte_data = 0x41;
						f1=1;
						break;
					}
					else{
						j -= 1;
						f1=0;
						fshift=0;
						return;
					}
				case 0x32:	//B
					if(f2==0){
						byte_data = 0x42;
						f2=1;
						break;
					}
					else{
						j -= 1;
						f2=0;
						fshift=0;
						return;
					}
				case 0x21:	//C
					if(f3==0){
						byte_data = 0x43;
						f3=1;
						break;
					}
					else{
						j -= 1;
						f3=0;
						fshift=0;
						return;
					}
				case 0x23:	//D
					if(f4==0){
						byte_data = 0x44;
						f4=1;
						break;
					}
					else{
						j -= 1;
						f4=0;
						fshift=0;
						return;
					}
				case 0x24:	//E
					if(f5==0){
						byte_data = 0x45;
						f5=1;
						break;
					}
					else{
						j -= 1;
						f5=0;
						fshift=0;
						return;
					}
				case 0x2B:	//F
					if(f6==0){
						byte_data = 0x46;
						f6=1;
						break;
					}
					else{
						j -= 1;
						f6=0;
						fshift=0;
						return;
					}
				case 0x34:	//G
					if(f7==0){
						byte_data = 0x47;
						f7=1;
						break;
					}
					else{
						j -= 1;
						f7=0;
						fshift=0;
						return;
					}
				case 0x33:	//H
					if(f8==0){
						byte_data = 0x48;
						f8=1;
						break;
					}
					else{
						j -= 1;
						f8=0;
						fshift=0;
						return;
					}
				case 0x43:	//I
					if(f9==0){
						byte_data = 0x49;
						f9=1;
						break;
					}
					else{
						j -= 1;
						f9=0;
						fshift=0;
						return;
					}
				case 0x3B:	//J
					if(f10==0){
						byte_data = 0x4A;
						f10=1;
						break;
					}
					else{
						j -= 1;
						f10=0;
						fshift=0;
						return;
					}
				case 0x42:	//K
					if(f11==0){
						byte_data = 0x4B;
						f11=1;
						break;
					}
					else{
						j -= 1;
						f11=0;
						fshift=0;
						return;
					}
				case 0x4B:	//L
					if(f12==0){
						byte_data = 0x4C;
						f12=1;
						break;
					}
					else{
						j -= 1;
						f12=0;
						fshift=0;
						return;
					}
				case 0x3A:	//M
					if(f13==0){
						byte_data = 0x4D;
						f13=1;
						break;
					}
					else{
						j -= 1;
						f13=0;
						fshift=0;
						return;
					}
				case 0x31:	//N
					if(f14==0){
						byte_data = 0x4E;
						f14=1;
						break;
					}
					else{
						j -= 1;
						f14=0;
						fshift=0;
						return;
					}
				case 0x44:	//O
					if(f15==0){
						byte_data = 0x4F;
						f15=1;
						break;
					}
					else{
						j -= 1;
						f15=0;
						fshift=0;
						return;
					}
				case 0x4D:	//P
					if(f16==0){
						byte_data = 0x50;
						f16=1;
						break;
					}
					else{
						j -= 1;
						f16=0;
						fshift=0;
						return;
					}
				case 0x15:	//Q
					if(f17==0){
						byte_data = 0x51;
						f17=1;
						break;
					}
					else{
						j -= 1;
						f17=0;
						fshift=0;
						return;
					}
				case 0x2D:	//R
					if(f18==0){
						byte_data = 0x52;
						f18=1;
						break;
					}
					else{
						j -= 1;
						f18=0;
						fshift=0;
						return;
					}
				case 0x1B:	//S
					if(f19==0){
						byte_data = 0x53;
						f19=1;
						break;
					}
					else{
						j -= 1;
						f19=0;
						fshift=0;
						return;
					}
				case 0x2C:	//T
					if(f20==0){
						byte_data = 0x54;
						f20=1;
						break;
					}
					else{
						j -= 1;
						f20=0;
						fshift=0;
						return;
					}
				case 0x3C:	//U
					if(f21==0){
						byte_data = 0x55;
						f21=1;
						break;
					}
					else{
						j -= 1;
						f21=0;
						fshift=0;
						return;
					}
				case 0x2A:	//V
					if(f22==0){
						byte_data = 0x56;
						f22=1;
						break;
					}
					else{
						j -= 1;
						f22=0;
						fshift=0;
						return;
					}
				case 0x1D:	//W
					if(f23==0){
						byte_data = 0x57;
						f23=1;
						break;
					}
					else{
						j -= 1;
						f23=0;
						fshift=0;
						return;
					}
				case 0x22:	//X
					if(f24==0){
						byte_data = 0x58;
						f24=1;
						break;
					}
					else{
						j -= 1;
						f24=0;
						fshift=0;
						return;
					}
				case 0x35:	//Y
					if(f25==0){
						byte_data = 0x59;
						f25=1;
						break;
					}
					else{
						j -= 1;
						f25=0;
						fshift=0;
						return;
					}
				case 0x1a:	//Z
					if(f26==0){
						byte_data = 0x5A;
						f26=1;
						break;
					}
					else{
						j -= 1;
						f26=0;
						fshift=0;
						return;
					}
				case 0x45:	//)
					if(f27==0){
						byte_data = 0x29;
						f27=1;
						break;
					}
					else{
						j -= 1;
						f27=0;
						fshift=0;
						return;
					}
				case 0x16:	//!
					if(f28==0){
						byte_data = 0x21;
						f28=1;
						break;
					}
					else{
						j -= 1;
						f28=0;
						fshift=0;
						return;
					}
				case 0x1E:	//@
						if(f29==0){
						byte_data = 0x40;
						f29=1;
						break;
					}
					else{
						j -= 1;
						f29=0;
						fshift=0;
						return;
					}
				case 0x26:	//#
					if(f30==0){
						byte_data = 0x23;
						f30=1;
						break;
					}
					else{
						j -= 1;
						f30=0;
						fshift=0;
						return;
					}
				case 0x25:	//$
					if(f31==0){
						byte_data = 0x24;
						f31=1;
						break;
					}
					else{
						j -= 1;
						f31=0;
						fshift=0;
						return;
					}
				case 0x2E:	//%
					if(f32==0){
						byte_data = 0x25;
						f32=1;
						break;
					}
					else{
						j -= 1;
						f32=0;
						fshift=0;
						return;
					}
				case 0x36:	//^
					if(f33==0){
						byte_data = 0x5E;
						f33=1;
						break;
					}
					else{
						j -= 1;
						f33=0;
						fshift=0;
						return;
					}
				case 0x3D:	//&
					if(f34==0){
						byte_data = 0x26;
						f34=1;
						break;
					}
					else{
						j -= 1;
						f34=0;
						fshift=0;
						return;
					}
				case 0x3E:	//*
					if(f35==0){
						byte_data = 0x2A;
						f35=1;
						break;
					}
					else{
						j -= 1;
						f35=0;
						fshift=0;
						return;
					}
				case 0x46:	//(
					if(f36==0){
						byte_data = 0x28;
						f36=1;
						break;
					}
					else{
						j -= 1;
						f36=0;
						fshift=0;
						return;
					}
				case 0x0E:	//~
					if(f37==0){
						byte_data = 0x7E;
						f37=1;
						break;
					}
					else{
						j -= 1;
						f37=0;
						fshift=0;
						return;
					}
				case 0x4E:	//_
					if(f38==0){
						byte_data = 0x5F;
						f38=1;
						break;
					}
					else{
						j -= 1;
						f38=0;
						fshift=0;
						return;
					}
				case 0x55:	//+
					if(f39==0){
						byte_data = 0x2B;
						f39=1;
						break;
					}
					else{
						j -= 1;
						f39=0;
						fshift=0;
						return;
					}
				case 0x54:	//{
					if(f40==0){
						byte_data = 0x7B;
						f40=1;
						break;
					}
					else{
						j -= 1;
						f40=0;
						fshift=0;
						return;
					}
				case 0x5B:	//}
					if(f41==0){
						byte_data = 0x7D;
						f41=1;
						break;
					}
					else{
						j -= 1;
						f41=0;
						fshift=0;
						return;
					}
				case 0x4C:	//:
					if(f42==0){
						byte_data = 0x3A;
						f42=1;
						break;
					}
					else{
						j -= 1;
						f42=0;
						fshift=0;
						return;
					}
				case 0x52:	//""
					if(f43==0){
						byte_data = 0x22;
						f43=1;
						break;
					}
					else{
						j -= 1;
						f43=0;
						fshift=0;
						return;
					}
				case 0x41:	//<
					if(f44==0){
						byte_data = 0x3C;
						f44=1;
						break;
					}
					else{
						j -= 1;
						f44=0;
						fshift=0;
						return;
					}
				case 0x49:	//>
					if(f45==0){
						byte_data = 0x3E;
						f45=1;
						break;
					}
					else{
						j -= 1;
						f45=0;
						fshift=0;
						return;
					}
				case 0x5D:	//|
					if(f46==0){
						byte_data = 0x5C;
						f46=1;
						break;
					}
					else{
						j -= 1;
						f46=0;
						fshift=0;
						return;
					}
				case 0x66:	//backspace
					if(f47==0){
						byte_data = 0x20;
						j -= 1;
						VGA_t(j, m, &byte_data);
						if(j <= 0){
							j=1;
						}
						if(j <= 1 && m > 0){
							j=78;
							m-=1;
						}
						f47=1;
						return;
					}
					else{
						j -= 1;
						if(j <= 1 && m > 0){
							j=78;
							m-=1;
						}
						f47=0;
						fshift=0;
						return;
					}
				case 0x29:	//space
					if(f48==0){
						byte_data = 0x20;
						f48=1;
						break;
					}
					else{
						j -= 1;
						f48=0;
						fshift=0;
						return;
					}
				// case 0x0D:	//tab //4 spaces?
				// 	if(f1==0){
				// 		byte_data = 0x20;
				// 		break;
				// 	}
				// 	else{
				// 		return;
				// 	}
				// 	byte_data = 0x20;
				//     break;
				// case 0x58:	//caps
				// 	byte_data = 0x36;
				//     break;
				// case 0x12:	//L shift
				// 	byte_data = 0x36;
				//     break;
				// case 0x59:	//R shift
				// 	byte_data = 0x36;
				//     break;
				case 0x4A:	//?
					if(f49==0){
						byte_data = 0x3F;
						f49=1;
						break;
					}
					else{
						j -= 1;
						f49=0;
						fshift=0;
						return;
					}
				case 0x7C:	//*
					if(f50==0){
						byte_data = 0x2A;
						f50=1;
						break;
					}
					else{
						j -= 1;
						f50=0;
						fshift=0;
						return;
					}
				case 0x7B:	//-
					if(f51==0){
						byte_data = 0x2D;
						f51=1;
						break;
					}
					else{
						j -= 1;
						f51=0;
						fshift=0;
						return;
					}
				case 0x79:	//+
					if(f52==0){
						byte_data = 0x2B;
						f52=1;
						break;
					}
					else{
						j -= 1;
						f52=0;
						fshift=0;
						return;
					}
				case 0x7D:	//9
					if(f53==0){
						byte_data = 0x39;
						f53=1;
						break;
					}
					else{
						j -= 1;
						f53=0;
						fshift=0;
						return;
					}
				case 0x75:	//8
					if(f54==0){
						byte_data = 0x38;
						f54=1;
						break;
					}
					else{
						j -= 1;
						f54=0;
						fshift=0;
						return;
					}
				case 0x6C:	//7
					if(f55==0){
						byte_data = 0x37;
						f55=1;
						break;
					}
					else{
						j -= 1;
						f55=0;
						fshift=0;
						return;
					}
				case 0x74:	//6
					if(f56==0){
						byte_data = 0x36;
						f56=1;
						break;
					}
					else{
						j -= 1;
						f56=0;
						fshift=0;
						return;
					}
				case 0x73:	//5
					if(f57==0){
						byte_data = 0x35;
						f57=1;
						break;
					}
					else{
						j -= 1;
						f57=0;
						fshift=0;
						return;
					}
				case 0x6B:	//4
					if(f58==0){
						byte_data = 0x34;
						f58=1;
						break;
					}
					else{
						j -= 1;
						f58=0;
						fshift=0;
						return;
					}
				case 0x7A:	//3
					if(f59==0){
						byte_data = 0x33;
						f59=1;
						break;
					}
					else{
						j -= 1;
						f59=0;
						fshift=0;
						return;
					}
				case 0x72:	//2
					if(f60==0){
						byte_data = 0x32;
						f60=1;
						break;
					}
					else{
						j -= 1;
						f60=0;
						fshift=0;
						return;
					}
				case 0x69:	//1
					if(f61==0){
						byte_data = 0x31;
						f61=1;
						break;
					}
					else{
						j -= 1;
						f61=0;
						fshift=0;
						return;
					}
				case 0x70:	//0
					if(f62==0){
						byte_data = 0x30;
						f62=1;
						break;
					}
					else{
						j -= 1;
						f62=0;
						fshift=0;
						return;
					}
				case 0x71:	//.
					if(f63==0){
						byte_data = 0x2E;
						f63=1;
						break;
					}
					else{
						j -= 1;
						f63=0;
						fshift=0;
						return;
					}
				case 0x05:	//f1
					if(f64==0){
						byte_data = 0x01;
						f64=1;
						break;
					}
					else{
						j -= 1;
						f64=0;
						fshift=0;
						return;
					}
				case 0x06:	//f2
					if(f65==0){
						byte_data = 0x02;
						f65=1;
						break;
					}
					else{
						j -= 1;
						f65=0;
						fshift=0;
						return;
					}
				case 0x04:	//f3
					if(f66==0){
						byte_data = 0x03;
						f66=1;
						break;
					}
					else{
						j -= 1;
						f66=0;
						fshift=0;
						return;
					}
				case 0x0C:	//f4
					if(f67==0){
						byte_data = 0x0B;
						f67=1;
						break;
					}
					else{
						j -= 1;
						f67=0;
						fshift=0;
						return;
					}
				case 0x03:	//f5
					if(f68==0){
						byte_data = 0x0C;
						f68=1;
						break;
					}
					else{
						j -= 1;
						f68=0;
						fshift=0;
						return;
					}
				case 0x0B:	//f6
					if(f69==0){
						byte_data = 0x0F;
						f69=1;
						break;
					}
					else{
						j -= 1;
						f69=0;
						fshift=0;
						return;
					}
				case 0x83:	//f7
					if(f70==0){
						byte_data = 0x21;
						f70=1;
						break;
					}
					else{
						j -= 1;
						f70=0;
						fshift=0;
						return;
					}
				case 0x0A:	//f8
					if(f71==0){
						byte_data = 0x24;
						f71=1;
						break;
					}
					else{
						j -= 1;
						f71=0;
						fshift=0;
						return;
					}
				case 0x01:	//f9
					if(f72==0){
						byte_data = 0x40;
						f72=1;
						break;
					}
					else{
						j -= 1;
						f72=0;
						fshift=0;
						return;
					}
				case 0x09:	//f10
					if(f73==0){
						byte_data = 0x09;
						f73=1;
						break;
					}
					else{
						j -= 1;
						f73=0;
						fshift=0;
						return;
					}
				case 0x78:	//f11
					if(f74==0){
						byte_data = 0x3F;
						f74=1;
						break;
					}
					else{
						j -= 1;
						f74=0;
						fshift=0;
						return;
					}
				case 0x07:	//f12
					if(f75==0){
						byte_data = 0x13;
						f75=1;
						break;
					}
					else{
						j -= 1;
						f75=0;
						fshift=0;
						return;
					}
				case 0x12:	//fshift
					if(f76==0){
						byte_data = 0x00;
						f76=1;
						j-=1;
						break;
					}
					else{
						j -= 1;
						f76=0;
						fshift=0;
						return;
					}
				case 0x59:	//fshift
					if(f77==0){
						byte_data = 0x00;
						f77=1;

						j-=1;
						break;
					}
					else{
						j -= 1;
						f77=0;
						fshift=0;
						return;
					}
				default:
					byte_data = 0x00;
					fshift=0;
					break;
				}
			}
	
		if(fshift==0){
			switch(byte_data){
				case 0x1C: //a
					if(f1==0){
						byte_data = 0x61;
						f1=1;
						break;
					}
					else{
						j -= 1;
						f1=0;
						return;
					}
				case 0x32:	//b
					if(f2==0){
						byte_data = 0x62;
						f2=1;
						break;
					}
					else{
						j -= 1;
						f2=0;
						return;
					}
				case 0x21:	//c
					if(f3==0){
						byte_data = 0x63;
						f3=1;
						break;
					}
					else{
						j -= 1;
						f3=0;
						return;
					}
				case 0x23:	//d
					if(f4==0){
						byte_data = 0x64;
						f4=1;
						break;
					}
					else{
						j -= 1;
						f4=0;
						return;
					}
				case 0x24:	//e
					if(f5==0){
						byte_data = 0x65;
						f5=1;
						break;
					}
					else{
						j -= 1;
						f5=0;
						return;
					}
				case 0x2B:	//f
					if(f6==0){
						byte_data = 0x66;
						f6=1;
						break;
					}
					else{
						j -= 1;
						f6=0;
						return;
					}
				case 0x34:	//g
					if(f7==0){
						byte_data = 0x67;
						f7=1;
						break;
					}
					else{
						j -= 1;
						f7=0;
						return;
					}
				case 0x33:	//h
					if(f8==0){
						byte_data = 0x68;
						f8=1;
						break;
					}
					else{
						j -= 1;
						f8=0;
						return;
					}
				case 0x43:	//i
					if(f9==0){
						byte_data = 0x69;
						f9=1;
						break;
					}
					else{
						j -= 1;
						f9=0;
						return;
					}
				case 0x3B:	//j
					if(f10==0){
						byte_data = 0x6A;
						f10=1;
						break;
					}
					else{
						j -= 1;
						f10=0;
						return;
					}
				case 0x42:	//k
					if(f11==0){
						byte_data = 0x6B;
						f11=1;
						break;
					}
					else{
						j -= 1;
						f11=0;
						return;
					}
				case 0x4B:	//l
					if(f12==0){
						byte_data = 0x6C;
						f12=1;
						break;
					}
					else{
						j -= 1;
						f12=0;
						return;
					}
				case 0x3A:	//m
					if(f13==0){
						byte_data = 0x6D;
						f13=1;
						break;
					}
					else{
						j -= 1;
						f13=0;
						return;
					}
				case 0x31:	//n
					if(f14==0){
						byte_data = 0x6E;
						f14=1;
						break;
					}
					else{
						j -= 1;
						f14=0;
						return;
					}
				case 0x44:	//o
					if(f15==0){
						byte_data = 0x6F;
						f15=1;
						break;
					}
					else{
						j -= 1;
						f15=0;
						return;
					}
				case 0x4D:	//p
					if(f16==0){
						byte_data = 0x70;
						f16=1;
						break;
					}
					else{
						j -= 1;
						f16=0;
						return;
					}
				case 0x15:	//q
					if(f17==0){
						byte_data = 0x71;
						f17=1;
						break;
					}
					else{
						j -= 1;
						f17=0;
						return;
					}
				case 0x2D:	//r
					if(f18==0){
						byte_data = 0x72;
						f18=1;
						break;
					}
					else{
						j -= 1;
						f18=0;
						return;
					}
				case 0x1B:	//s
					if(f19==0){
						byte_data = 0x73;
						f19=1;
						break;
					}
					else{
						j -= 1;
						f19=0;
						return;
					}
				case 0x2C:	//t
					if(f20==0){
						byte_data = 0x74;
						f20=1;
						break;
					}
					else{
						j -= 1;
						f20=0;
						return;
					}
				case 0x3C:	//u
					if(f21==0){
						byte_data = 0x75;
						f21=1;
						break;
					}
					else{
						j -= 1;
						f21=0;
						return;
					}
				case 0x2A:	//v
					if(f22==0){
						byte_data = 0x76;
						f22=1;
						break;
					}
					else{
						j -= 1;
						f22=0;
						return;
					}
				case 0x1D:	//w
					if(f23==0){
						byte_data = 0x77;
						f23=1;
						break;
					}
					else{
						j -= 1;
						f23=0;
						return;
					}
				case 0x22:	//x
					if(f24==0){
						byte_data = 0x78;
						f24=1;
						break;
					}
					else{
						j -= 1;
						f24=0;
						return;
					}
				case 0x35:	//y
					if(f25==0){
						byte_data = 0x79;
						f25=1;
						break;
					}
					else{
						j -= 1;
						f25=0;
						return;
					}
				case 0x1a:	//z
					if(f26==0){
						byte_data = 0x7A;
						f26=1;
						break;
					}
					else{
						j -= 1;
						f26=0;
						return;
					}
				case 0x45:	//0
					if(f27==0){
						byte_data = 0x30;
						f27=1;
						break;
					}
					else{
						j -= 1;
						f27=0;
						return;
					}
				case 0x16:	//1
					if(f28==0){
						byte_data = 0x31;
						f28=1;
						break;
					}
					else{
						j -= 1;
						f28=0;
						return;
					}
				case 0x1E:	//2
						if(f29==0){
						byte_data = 0x32;
						f29=1;
						break;
					}
					else{
						j -= 1;
						f29=0;
						return;
					}
				case 0x26:	//3
					if(f30==0){
						byte_data = 0x33;
						f30=1;
						break;
					}
					else{
						j -= 1;
						f30=0;
						return;
					}
				case 0x25:	//4
					if(f31==0){
						byte_data = 0x34;
						f31=1;
						break;
					}
					else{
						j -= 1;
						f31=0;
						return;
					}
				case 0x2E:	//5
					if(f32==0){
						byte_data = 0x35;
						f32=1;
						break;
					}
					else{
						j -= 1;
						f32=0;
						return;
					}
				case 0x36:	//6
					if(f33==0){
						byte_data = 0x36;
						f33=1;
						break;
					}
					else{
						j -= 1;
						f33=0;
						return;
					}
				case 0x3D:	//7
					if(f34==0){
						byte_data = 0x37;
						f34=1;
						break;
					}
					else{
						j -= 1;
						f34=0;
						return;
					}
				case 0x3E:	//8
					if(f35==0){
						byte_data = 0x38;
						f35=1;
						break;
					}
					else{
						j -= 1;
						f35=0;
						return;
					}
				case 0x46:	//9
					if(f36==0){
						byte_data = 0x39;
						f36=1;
						break;
					}
					else{
						j -= 1;
						f36=0;
						return;
					}
				case 0x0E:	//`
					if(f37==0){
						byte_data = 0x60;
						f37=1;
						break;
					}
					else{
						j -= 1;
						f37=0;
						return;
					}
				case 0x4E:	//-
					if(f38==0){
						byte_data = 0x2D;
						f38=1;
						break;
					}
					else{
						j -= 1;
						f38=0;
						return;
					}
				case 0x55:	//=
					if(f39==0){
						byte_data = 0x55;
						f39=1;
						break;
					}
					else{
						j -= 1;
						f39=0;
						return;
					}
				case 0x54:	//[
					if(f40==0){
						byte_data = 0x5B;
						f40=1;
						break;
					}
					else{
						j -= 1;
						f40=0;
						return;
					}
				case 0x5B:	//]
					if(f41==0){
						byte_data = 0x5D;
						f41=1;
						break;
					}
					else{
						j -= 1;
						f41=0;
						return;
					}
				case 0x4C:	//;
					if(f42==0){
						byte_data = 0x3B;
						f42=1;
						break;
					}
					else{
						j -= 1;
						f42=0;
						return;
					}
				case 0x52:	//'
					if(f43==0){
						byte_data = 0x27;
						f43=1;
						break;
					}
					else{
						j -= 1;
						f43=0;
						return;
					}
				case 0x41:	//,
					if(f44==0){
						byte_data = 0x2C;
						f44=1;
						break;
					}
					else{
						j -= 1;
						f44=0;
						return;
					}
				case 0x49:	//.
					if(f45==0){
						byte_data = 0x2E;
						f45=1;
						break;
					}
					else{
						j -= 1;
						f45=0;
						return;
					}
				case 0x5D:	//b slash
					if(f46==0){
						byte_data = 0x2F;
						f46=1;
						break;
					}
					else{
						j -= 1;
						f46=0;
						return;
					}
				case 0x66:	//backspace
					if(f47==0){
						byte_data = 0x20;
						j -= 1;
						VGA_t(j, m, &byte_data);
						if(j <= 0){
							j=1;
						}
						if(j <= 1 && m > 0){
							j=78;
							m-=1;
						}
						f47=1;
						return;
					}
					else{
						j -= 1;
						if(j <= 1 && m > 0){
							j=78;
							m-=1;
						}
						f47=0;
						return;
					}
				case 0x29:	//space
					if(f48==0){
						byte_data = 0x20;
						f48=1;
						break;
					}
					else{
						j -= 1;
						f48=0;
						return;
					}
				// case 0x0D:	//tab //4 spaces?
				// 	if(f1==0){
				// 		byte_data = 0x20;
				// 		break;
				// 	}
				// 	else{
				// 		return;
				// 	}
				// 	byte_data = 0x20;
				//     break;
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
					if(f49==0){
						byte_data = 0x5C;
						f49=1;
						break;
					}
					else{
						j -= 1;
						f49=0;
						return;
					}
				case 0x7C:	//*
					if(f50==0){
						byte_data = 0x2A;
						f50=1;
						break;
					}
					else{
						j -= 1;
						f50=0;
						return;
					}
				case 0x7B:	//-
					if(f51==0){
						byte_data = 0x2D;
						f51=1;
						break;
					}
					else{
						j -= 1;
						f51=0;
						return;
					}
				case 0x79:	//+
					if(f52==0){
						byte_data = 0x2B;
						f52=1;
						break;
					}
					else{
						j -= 1;
						f52=0;
						return;
					}
				case 0x7D:	//9
					if(f53==0){
						byte_data = 0x39;
						f53=1;
						break;
					}
					else{
						j -= 1;
						f53=0;
						return;
					}
				case 0x75:	//8
					if(f54==0){
						byte_data = 0x38;
						f54=1;
						break;
					}
					else{
						j -= 1;
						f54=0;
						return;
					}
				case 0x6C:	//7
					if(f55==0){
						byte_data = 0x37;
						f55=1;
						break;
					}
					else{
						j -= 1;
						f55=0;
						return;
					}
				case 0x74:	//6
					if(f56==0){
						byte_data = 0x36;
						f56=1;
						break;
					}
					else{
						j -= 1;
						f56=0;
						return;
					}
				case 0x73:	//5
					if(f57==0){
						byte_data = 0x35;
						f57=1;
						break;
					}
					else{
						j -= 1;
						f57=0;
						return;
					}
				case 0x6B:	//4
					if(f58==0){
						byte_data = 0x34;
						f58=1;
						break;
					}
					else{
						j -= 1;
						f58=0;
						return;
					}
				case 0x7A:	//3
					if(f59==0){
						byte_data = 0x33;
						f59=1;
						break;
					}
					else{
						j -= 1;
						f59=0;
						return;
					}
				case 0x72:	//2
					if(f60==0){
						byte_data = 0x32;
						f60=1;
						break;
					}
					else{
						j -= 1;
						f60=0;
						return;
					}
				case 0x69:	//1
					if(f61==0){
						byte_data = 0x31;
						f61=1;
						break;
					}
					else{
						j -= 1;
						f61=0;
						return;
					}
				case 0x70:	//0
					if(f62==0){
						byte_data = 0x30;
						f62=1;
						break;
					}
					else{
						j -= 1;
						f62=0;
						return;
					}
				case 0x71:	//.
					if(f63==0){
						byte_data = 0x2E;
						f63=1;
						break;
					}
					else{
						j -= 1;
						f63=0;
						return;
					}
				case 0x05:	//f1
					if(f64==0){
						byte_data = 0x01;
						f64=1;
						break;
					}
					else{
						j -= 1;
						f64=0;
						return;
					}
				case 0x06:	//f2
					if(f65==0){
						byte_data = 0x02;
						f65=1;
						break;
					}
					else{
						j -= 1;
						f65=0;
						return;
					}
				case 0x04:	//f3
					if(f66==0){
						byte_data = 0x03;
						f66=1;
						break;
					}
					else{
						j -= 1;
						f66=0;
						return;
					}
				case 0x0C:	//f4
					if(f67==0){
						byte_data = 0x0B;
						f67=1;
						break;
					}
					else{
						j -= 1;
						f67=0;
						return;
					}
				case 0x03:	//f5
					if(f68==0){
						byte_data = 0x0C;
						f68=1;
						break;
					}
					else{
						j -= 1;
						f68=0;
						return;
					}
				case 0x0B:	//f6
					if(f69==0){
						byte_data = 0x0F;
						f69=1;
						break;
					}
					else{
						j -= 1;
						f69=0;
						return;
					}
				case 0x83:	//f7
					if(f70==0){
						byte_data = 0x21;
						f70=1;
						break;
					}
					else{
						j -= 1;
						f70=0;
						return;
					}
				case 0x0A:	//f8
					if(f71==0){
						byte_data = 0x24;
						f71=1;
						break;
					}
					else{
						j -= 1;
						f71=0;
						return;
					}
				case 0x01:	//f9
					if(f72==0){
						byte_data = 0x40;
						f72=1;
						break;
					}
					else{
						j -= 1;
						f72=0;
						return;
					}
				case 0x09:	//f10
					if(f73==0){
						byte_data = 0x09;
						f73=1;
						break;
					}
					else{
						j -= 1;
						f73=0;
						return;
					}
				case 0x78:	//f11
					if(f74==0){
						byte_data = 0x3F;
						f74=1;
						break;
					}
					else{
						j -= 1;
						f74=0;
						return;
					}
				case 0x07:	//f12
					if(f75==0){
						byte_data = 0x13;
						f75=1;
						break;
					}
					else{
						j -= 1;
						f75=0;
						return;
					}
				case 0x12:	//Lshift
					if(f76==0){
						byte_data = 0x00;
						f76=1;
						j-=1;
						break;
					}
					else{
						j -= 1;
						fshift=1;
						f76=0;
						return;
					}
				case 0x59:	//Rshift
					if(f77==0){
						byte_data = 0x00;
						f77=1;
						j-=1;
						break;
					}
					else{
						j -= 1;
						fshift=1;
						f77=0;
						return;
					}
				default:
					byte_data = 0x00;
					break;
			}
	}
		if(byte_data!=0x5A){
			VGA_t(j, m, &byte_data);
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
