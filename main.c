#include "a1.h"
#include <stdio.h>

int main( int argc, char **argv )
{
  //test for function 1

  printf( "%d\n", checksum( "Hello, world!" ) );

  //test for function 2

  char pontus[15] = "VENI VIDI VICI";

  caesar( pontus, 5 );
  printf( "%s\n", pontus );

  //test for function 3

  char *alpha = "abcde";
  unsigned char bits[8];

  for (int pos=0;pos<5;pos++)
  {
    printf( "%c ", alpha[pos] );
    char2bits( alpha[pos], bits );
    for (int bit=0;bit<8;bit++)
      printf( "%d", bits[bit] );
    printf( "\n" );
  }

  //test for function 4

  char *alpha2 = "abcde";
  unsigned char bits2[8];
  char bitstr[9];

  for (int pos=0;pos<5;pos++)
  {
    char2bits( alpha2[pos], bits2 );
    bits2str( 8, bits2, bitstr );

    printf( "%c %s\n", alpha2[pos], bitstr );
  }

  //test for function 5

  unsigned short numbers[9] = {0,1,2,32767,32768,32769,65533,65534,65535};
  unsigned char bits3[16];
  char bitstr3[17];

  for (int pos3=0;pos3<9;pos3++)
  {
    ushort2bits( numbers[pos3], bits3 );
    bits2str( 16, bits3, bitstr );

    printf( "%6d %s\n", numbers[pos3], bitstr3 );
  }

  //test for function 6

  short numbers6[9] = {-32768,-32767,-32766,-1,0,1,32765,32766,32767};
  unsigned char bits6[16];
  char bitstr6[17];

  for (int pos6=0;pos6<9;pos6++)
  {
    short2bits( numbers6[pos6], bits6 );
    bits2str( 16, bits6, bitstr6 );

    printf( "%6d %s\n", numbers6[pos6], bitstr6 );
  }

  //test for function 7

  short numbers7[9] = {-32768,-32767,-32766,-1,0,1,32765,32766,32767};
  unsigned char bits7[16];
  char bitstr7[17];
  short number7;

  for (int pos7=0;pos7<9;pos7++)
  {
    short2bits( numbers7[pos7], bits7 );
    bits2str( 16, bits7, bitstr7 );
    number7 = bits2short( bitstr7 );

    printf( "%6d %s %6d\n", numbers7[pos7], bitstr7, number7 );
  }

  return 0;

}