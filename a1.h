#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

unsigned char checksum(char *string);
void caesar( char *string, int rshift );
void char2bits(char c, unsigned char bits[8]);
void bits2str( int bitno, unsigned char *bits, char *bitstr );
void ushort2bits(unsigned short s, unsigned char bits[16]);
void short2bits(short s, unsigned char bits[16] );
int power(int base, int exponent);
short bits2short( char *bits );