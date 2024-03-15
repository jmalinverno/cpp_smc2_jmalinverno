#include "cypher.h"

#include <iostream>
#include <string>
#include <cctype>

// This function will encrypt the file input by substituting cypher
// cypher refers to the substitution alphabet 
// input refers to the string to be encrypted
// output refers to the result of the encrypted string

void substitutionCypherEncrypt(const std::string& cypher, const std::string& input, std::string& output)
{
    output.clear(); // Clears the entire string in the output string before starting
    for (int i = 0; i < input.length(); i++) {
        char currentChar = input[i];

        // Encodes uppercase
        if (currentChar >= 'A' && currentChar <= 'Z') {
            int position = currentChar - 'A';  // Position in the plain alphabet
            output += cypher[position];        // Replaces with the cypher character
        }
        // Encodes lowercase
        else if (currentChar >= 'a' && currentChar <= 'z') {
            int position = currentChar - 'a';           // Position in the plain alphabet
            output += std::tolower(cypher[position]);   // Replaces with the lowercase cypher character
        }
        // Deals with numbers, whitespaces, punctuation
        else {
            output += currentChar;
        }
    }
}

// This function will decrypt the file input by substituting cypher
// cypher refers to the substitution alphabet 
// input refers to the encrypted file to be decrypted
// output refers to the result of the decrypted string

void substitutionCypherDecrypt(const std::string& cypher, const std::string& input, std::string& output)
{
    output.clear(); // Clears the entire string in the output string before starting
    for (int i = 0; i < input.length(); i++) {
        char currentChar = input[i];
        int position = cypher.find(std::toupper(currentChar)); // Find the position of the currentChar in the cypher

        if (position != std::string::npos) { // Look for the character in the cypher
            // Checks if uppercase letter and converts the position back to the standard alphabet
            if (currentChar >= 'A' && currentChar <= 'Z') {
                output += 'A' + position;
            } 
            // Checks if lowercase letter and converts the position back to the standard alphabet
            else if (currentChar >= 'a' && currentChar <= 'z') {
                output += 'a' + position;
            }
        }
        else {
            output += currentChar; // Deals with cases with numbers, whitespaces, punctuation by keeping them as they are
        }
    }
}