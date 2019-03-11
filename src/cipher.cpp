/**
        Name: cipher.cpp
        Purpose: Encodes and decodes strings according to the Caesar Cipher
   algorithim.

        @author lare96
*/
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

namespace cipher {

std::vector<char> letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                             'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                             's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

char encrypt_letter(char letter, int key) {
  int encode_index = 0;
  bool upper = std::isupper(letter);

  // Perform lookup for encoded letter.
  for (size_t i = 0; i < letters.size(); i++) {
    if (letters[i] == std::tolower(letter)) {
      encode_index = i + key;
      if (encode_index > 25) {
        // Handle overflows (jump back to index 0);.
        int old_index = encode_index;
        encode_index = 0;
        encode_index += (old_index - 26);
      }
      break;
    }
  }
  char encoded = letters[encode_index];
  return upper ? std::toupper(encoded) : encoded;
}

char decrypt_letter(char letter, int key) {
  int decode_index = 0;
  bool upper = std::isupper(letter);

  // Perform lookup for decoded letter.
  for (size_t i = 0; i < letters.size(); i++) {
    if (letters[i] == std::tolower(letter)) {
      decode_index = (i - key);
      if (decode_index < 0) {
        // Handle underflows (jump back to index 25).
        int old_index = decode_index;
        decode_index = 25;
        decode_index += (old_index + 1);
      }
      break;
    }
  }
  char decoded = letters[decode_index];
  return upper ? std::toupper(decoded) : decoded;
}

void encrypt(std::string msg, int key) {
  // Copy immutable string into mutable vector.
  std::vector<char> msg_copy(msg.length());
  for (size_t i = 0; i < msg.length(); i++) {
    msg_copy[i] = msg[i];
  }

  // Encode all alphabetic characters.
  for (size_t i = 0; i < msg_copy.size(); i++) {
    char c = msg_copy[i];
    if (std::isalpha(c)) {
      msg_copy[i] = encrypt_letter(c, key);
    }
  }

  // Display encoded message.
  std::string encoded(msg_copy.begin(), msg_copy.end());
  std::cout << encoded << "\n\n";
}

void decrypt(std::string msg, int key) {
  // Copy immutable string into mutable char[].
  std::vector<char> msg_copy(msg.length());
  for (size_t i = 0; i < msg.length(); i++) {
    msg_copy[i] = msg[i];
  }

  // Decode all alphabetic characters.
  for (size_t i = 0; i < msg_copy.size(); i++) {
    char c = msg[i];
    if (std::isalpha(c)) {
      msg_copy[i] = decrypt_letter(c, key);
    }
  }

  // Display decoded message.
  std::string decoded(msg_copy.begin(), msg_copy.end());
  std::cout << decoded << "\n\n";
}
}  // namespace cipher