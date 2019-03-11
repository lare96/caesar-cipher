/**
        Name: main.cpp
        Purpose: Starts the application.

        @author lare96
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <thread>
#include "cipher.h"
#include "pch.h"
using namespace std;
using namespace cipher;

int main() {
  cout << "This is a C++ application that encrypts and decrypts messages using "
          "Caesar's Cipher, for learning purposes.\n\n";
  cout << "More info on this very simple encryption algorithim can be found "
          "here: https://en.wikipedia.org/wiki/Caesar_cipher"
       << "\n";
  cout << "--------------------------------------------------------------------"
          "\n\n\n";

  for (;;) {
    for (;;) {
      char response;
      cout << "Would you like to (e) encrypt or (d) decrypt a message?\n";
      cin.clear();
      cin.ignore(cin.rdbuf()->in_avail(), '\n');
      cin >> response;
      cout << '\n';

      cin.ignore();
      if (response == 'e') {
        // Encrypt the message.
        string msg;
        cout << "Please enter the message to encrypt:\n";
        getline(cin, msg);
        cout << '\n';

        for (;;) {
          int key;
          cout << "Please enter the encryption key (1-25):\n";
          cin.clear();
          cin.ignore(cin.rdbuf()->in_avail(), '\n');
          cin >> key;
          cout << '\n';

          if (key >= 1 && key <= 25) {
            encrypt(msg, key);
            cout << '\n';
            this_thread::sleep_for(1s);
            break;
          } else {
            // Invalid input, wait one second and ask for input again.
            cout << "ERROR: Input must be between 1 and 25 inclusive.\n\n\n";
            this_thread::sleep_for(1s);
          }
        }
      } else if (response == 'd') {
        // Decrypt the message.
        string msg;
        cout << "Please enter the message to decrypt:\n";
        getline(cin, msg);
        cout << '\n';

        for (;;) {
          int key;
          cout << "Please enter the decryption key (1-25):\n";
          cin.clear();
          cin.ignore(cin.rdbuf()->in_avail(), '\n');
          cin >> key;
          cout << '\n';

          if (key >= 1 && key <= 25) {
            decrypt(msg, key);
            cout << '\n';
            this_thread::sleep_for(1s);
            break;
          } else {
            // Invalid input, wait one second and ask for input again.
            cout << "ERROR: Input must be between 1 and 25 inclusive.\n\n\n";
            this_thread::sleep_for(1s);
          }
        }
      } else {
        // Invalid input, wait one second and ask for input again.
        cout << "ERROR: Input must either be (e) for encrypt, or (d) for " cout
             << "ERROR: Input must either be (e) for encrypt, or (d) for "
                "decrypt.\n\n\n";
        this_thread::sleep_for(1s);
      }
    }
    return 0;
  }
