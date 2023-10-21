


#ifndef SEGMENT_H_
#define SEGMENT_H_
/**********************************CONFIG 7 SEGMENT*************************************/
#define SEGMENT_PORT1  PORTA
#define SEGMENT_PORT2  PORTA


void one_segment_display(u8 n);

/***TWO 7 SEG**/
void two_segment_display(u8 n) ;//n=35

void two_segment_display_shifted(u8 n);

void two_segments_display_anode_cath(u8 n);

void one_segment_display_BCD(u8 n);

void two_segments_display_BCD_on_same_port(u8 n);

void two_segments_display_BCD_HEXA(u8 n);

void segment_MPX_two_digit_display_Proteus(u8 n); // not worked

void segment_MPX_two_digit_display_MCU(u8 n);

void traffic(void);

void seg_MPX2Dig_B1_increment_B2_decrement_1(void);

void seg_MPX2Dig_B1_increment_B2_decrement_2(void);




#endif 