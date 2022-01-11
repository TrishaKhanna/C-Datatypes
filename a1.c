#include "a1.h"
#include "get_bits.h"

/* FUNCTION 1: */
unsigned char checksum(char *string)
{
    int lowerCase = 0;
    int upperCase = 0;
    int total = 0;
    int i = 0;

    while(i < strlen(string))
    {
        if(islower(string[i])) // Check to see whether the character is of lower case so that base ASCII value of 'a' can be subtracted from it.
        {
            lowerCase = string[i] - 97;
            total = total + lowerCase;
        }

        if(isupper(string[i])) // Check to see whether the character is of upper case so that base ASCII value of 'A' can be subtracted from it.
        {
            upperCase = string[i] - 65;
            total = total + upperCase;
        }

        i++;
    }

    total = total % 26; // Calculates the modulo of the final sum from the above if statements.
    return total;
}

/* FUNCTION 2: */
void caesar( char *string, int rshift )
{
    int i = 0;

    while(string[i] != '\0') // Processes the string only up until the '\0'.
    {
        if(isalpha(string[i])) // Checks to see if the characters being processed are alphabets or whitespaces so that the character shift is performed accordingly.
        {
            string[i] = string[i] - 'A' + rshift % 26 + 'A';

            if(string[i] > 'Z') // Takes care of positions wrapping around the character 'Z'.
            {
                string[i] = string[i] - 'Z' + 'A' - 1;
            }
        }

        i++;

    }

}

/* FUNCTION 3: */
void char2bits(char c, unsigned char bits[8])
{
    int i = 0;

    while(i < 8) // Loop iterates 8 times to receive bits 0-7.
    {
        bits[i] = get_bits8(i, i + 1, &c);
        i++;
    }

}

/* FUNCTION 4: */
void bits2str( int bitno, unsigned char *bits, char *bitstr )
{
    int i = 0;

    for(i = 0; i <= bitno; i++)
    {
        bitstr[i] = bits[i] + '0'; // Populate the array bitstr, with the bitno stored in *bits

        if(i == bitno)
        {
            bitstr[i] = '\0'; // Place the '\0' in the final position at the index bitno in bitstr so that the string is null terminated.
        }
    }
}


/* FUNCTION 5: */
void ushort2bits(unsigned short s, unsigned char bits[16])
{
    int i = 0;

    while(i < 16) // Loop iterates 16 times to receive bits 0-15.
    {
        bits[i] = get_bits16(i, i + 1, &s);
        i++;
    }
}

/* FUNCTION 6: */
void short2bits(short s, unsigned char bits[16] )
{
    int i = 0;

    while(i < 16) // Loop iterates 16 times to receive bits 0-15.
    {
        bits[i] = get_bits16(i, i + 1, &s);
        i++;
    }
}

/* HELPER power Function */
int power(int b, int exp)
{
    int final = 1;
    int i = 0;

    while(i < exp)
    {
        final = final * b;
        ++i;
    }

    return final;
}

/* FUNCTION 7: */
short bits2short( char *bits )
{
    int length = strlen(bits);
    int i = 0;
    int total = 0;

    for(i = 0; i < length; i++)
    {
        if(i == 0) // Checks to make sure the character at index 0 is being looked at
        {
            if(bits[i] == '1') // If the 1st bit is 1, this indicates a negative number and hence power is multiplied by a (-)
            {
                total = -power(2, (length - 1));
            }
        }

        else
        {
            if(bits[i] == '1')
            {
                total = total + power(2, length - i - 1);
            }
        }
    }

    return (short) total; // Return a short of the total as mentioned in the assignment specifications.
}
