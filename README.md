## C Datatypes
**Includes a small C library with a number of functions that help in better understanding the the basic data types C has to offer.**
**Created a1.c, a1.h, makefile to run smoothly with the given main.c**

##### Function Descriptions:
a) unsigned char checksum(char *string);
- This function iterates over all the characters in string until the '\0' is reached.
- ONLY uppercase and lowercase characters are considered.
- All letters are treated as integers equal to the letter position relative to ‘a’ or ‘A’ in the alphabet for lowercase and uppercase letters respectively 
- Finally, this function returns the sum of all values % 26.


b) void caesar( char *string, int rshift );
- This function processes a given string containing only UPPERCASE alphabets and or spaces, followed by the '\0'.
- It then replaces each letter in the string by a letter that occurs rshift places further in the alphabets.
- Once the letter 'Z' is reached, the shifting of letters continues from the letter 'A' as the starting point.
- Spaces are left alone.


c) void char2bits(char c, unsigned char bits[8]);
- This function retrieves bits 0 to 7, from character c, by calling the get_bits8 function 8 times.
- The bits received are then stored in the array, bits.


d) void bits2str( int bitno, unsigned char *bits, char *bitstr );
- This function converts the first bitno numbers stored in bits into a string in bitstr.


e) void ushort2bits(unsigned short s, unsigned char bits[16]);
- This function retrieves bits 0 to 15, from the unsigned short integer, s, by calling the get_bits16 function 16 times.
- The bits received are then stored in the array, bits.


f) void short2bits(short s, unsigned char bits[16] );
- This function retrieves bits 0 to 15, from the short integer, s, by calling the get_bits16 function 16 times.
- The bits received are then stored in the array, bits.


g) int power(int base, int exponent);
 - This function calculates the power of b; b^(exp).
 - It does so by looping and mutliplying variable b, exp times.
 - After which it returns the final multiplied value that was obtained from the while loop.


h) short bits2short( char *bits );
- This functions reads and iterates across all the characters from the string bits, until the '\0' is reached which is not processed.
- The characters processed are either 0 or 1.
- The function calculates the 2s complement of the binary number it has read; from the Most-Significant Bit to the Least-Significant Bit.
- This 2s complement is then finally returned as a short, at the end of the function.
