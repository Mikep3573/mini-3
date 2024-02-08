/**
 * This file is for Mini-Programming Assignment #3
 * This was written by Michael Piscione
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/**
 * convertString takes in a string and a pointer to a string as input. It then confirms that both are not NULL, if-so, 
 * it returns the value -1. Once this has been validated, a new string is made with the same size in memory as inString
 * (the string being passed in). For every character in the inString, if it is an alphabetic character or a space,
 * it is placed in the same spot in the new string as it is in the inString. If it is not an alphabetic character or a space,
 * it is replaced with '-' in the new string. The new string is passed-by-reference through outString. If all goes well,
 * the function will return the number of characters in the input string.
 * Parameters: char *, the string being handed in, char **, the pointer to a string to be used to pass the new string through.
 * Return: -1 if either inString or outString is NULL, number of characters in the input string otherwise.
*/
int convertString(char *inString, char **outString) {

    // Check if either inString or outString is NULL
    if (inString == NULL || outString == NULL) {
        return -1;  // Return -1 if either is
    }

    // Copy the string from inString to outString
    // Allocate space for the new string
    char *newString = malloc(sizeof(*inString));

    // Copy each character individually
    for (int i = 0; i < strlen(inString); i++) {

        // If the character is alphabetic, place the lowercase version of it in the same location in newString
        if (isalpha(inString[i])) {
            newString[i] = tolower(inString[i]);
        }
        // If the character is a space, place it in the same location in newString
        else if (isspace(inString[i])) {
            newString[i] = inString[i];
        }
        // Otherwise, replace the character with '-' in newString
        else {
            newString[i] = '-';
        }

        // Pass newString out of the function via reference
        *outString = newString;
    }

    // Return the number of characters in the input string if all goes well
    return strlen(inString);

}

int main() {
    char *inString = "Hello World";
    char *outString;
    int retrn = convertString(inString, NULL);
    printf("old string: %s, new string: %s, return is: %d\n", inString, outString, retrn);
}
