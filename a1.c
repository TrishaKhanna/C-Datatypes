/*
 Student Name: Trisha Khanna
 Student ID: 1123248
 Due Date: September 21st, 2021
 Course: CIS*2520
 I have exclusive control over this submission via my password.
 By including this header comment, I certify that:
 1) I have read and understood the policy on academic integrity.
 2) I have completed Moodle's module on academic integrity.
 3) I have achieved at least 80% on the academic integrity quiz
 I assert that this work is my own. I have appropriate acknowledged
 any and all material that I have used, be it directly quoted or
 paraphrased. Furthermore, I certify that this assignment was written
 by me in its entirety.
*/


#include "a1.h"
#include "get_bits.h"

/* FUNCTION 1: - This function iterates over all the characters in string until the '\0' is reached.
               - ONLY uppercase and lowercase characters are considered.
               - All letters are treated as integers equal to the letter position relative to ‘a’ or ‘A’ in the alphabet for 
                 lowercase and uppercase letters respectively
               - Finally, this function returns the sum of all values % 26.*/
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

/* FUNCTION 2: - This function processes a given string containing only UPPERCASE alphabets and or spaces, followed by the '\0'.
               - It then replaces each letter in the string by a letter that occurs rshift places further in the alphabets.
               - Once the letter 'Z' is reached, the shifting of letters continues from the letter 'A' as the starting point.
               - Spaces are left alone.*/
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

/* FUNCTION 3: - This function retrieves bits 0 to 7, from character c, by calling the get_bits8 function
                 (as supplied by the instructor) 8 times.
               - The bits received are then stored in the array, bits.*/
void char2bits(char c, unsigned char bits[8])
{
    int i = 0;

    while(i < 8) // Loop iterates 8 times to receive bits 0-7.
    {
        bits[i] = get_bits8(i, i + 1, &c);
        i++;
    }

}

/* FUNCTION 4: - This function converts the first bitno numbers stored in bits into a string in bitstr.*/
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


/* FUNCTION 5: - This function retrieves bits 0 to 15, from the unsigned short integer, s, by calling the get_bits16 function
                 (as supplied by the instructor) 16 times.
               - The bits received are then stored in the array, bits.*/
void ushort2bits(unsigned short s, unsigned char bits[16])
{
    int i = 0;

    while(i < 16) // Loop iterates 16 times to receive bits 0-15.
    {
        bits[i] = get_bits16(i, i + 1, &s);
        i++;
    }
}

/* FUNCTION 6: - This function retrieves bits 0 to 15, from the short integer, s, by calling the get_bits16 function
                 (as supplied by the instructor) 16 times.
               - The bits received are then stored in the array, bits.*/
void short2bits(short s, unsigned char bits[16] )
{
    int i = 0;

    while(i < 16) // Loop iterates 16 times to receive bits 0-15.
    {
        bits[i] = get_bits16(i, i + 1, &s);
        i++;
    }
}

/* HELPER power Function - This function calculates the power of b; b^(exp).
                         - It does so by looping and mutliplying variable b, exp times.
                         - After which it returns the final multiplied value that was obtained from the while loop.*/
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

/* FUNCTION 7: - This functions reads and iterates across all the characters from the string bits, until the '\0' is reached
                 which is not processed.
               - The characters processed are either 0 or 1.
               - The function calculates the 2s complement of the binary number it has read; from the Most-Significant Bit to
                 the Least-Significant Bit.
               - This 2s complement is then finally returned as a short, at the end of the function. */
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