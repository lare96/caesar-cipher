/**
        Name: cipher.h
        Purpose: cipher.cpp header file.

        @author lare96
*/

#include <string>
#include <vector>

namespace cipher {
void encrypt(std::string msg, int key);
void decrypt(std::string msg, int key);
char encrypt_letter(char letter, int key);
char decrypt_letter(char letter, int key);
}