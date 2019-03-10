/**
	Name: main.cpp
	Purpose: Starts the application.

	@author lare96
*/
#include "pch.h"
#include "cipher.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <thread>
using namespace std;
using namespace cipher;

int main() {
	cout << "This is a C++ application that encrypts and decrypts messages using Caesar's Cipher, for learning purposes.\n";
	cout << "More information on this very simple encryption algorithim can be found here: https://en.wikipedia.org/wiki/Caesar_cipher\n\n\n";

	for (;;) {
		char response;
		cout << "Would you like to (e) encrypt or (d) decrypt a message?\n";
		cin >> response;

		cin.ignore();
		if (response == 'e') {

			// Encrypt the message.
			string msg;
			cout << "Please enter the message to encrypt:\n";
			getline(cin, msg);
			
			for (;;) {
				int key;
				cout << "Please enter the encryption key (1-25):\n";
				cin >> key;
				if (key >= 1 && key <= 25) {
					encrypt(msg, key);
					cout << '\n';
					std::this_thread::sleep_for(1s);
					break;
				} else {
					// Invalid input, wait one second and ask for input again.
					cout << "Input must be between 1 and 25 inclusive.\n";
					std::this_thread::sleep_for(1s);
				}
			}
		} else if (response == 'd')	{

			// Decrypt the message.
			string msg;
			cout << "Please enter the message to decrypt:\n";
			getline(cin, msg);

			for (;;) {
				int key;
				cout << "Please enter the decryption key (1-25):\n";
				cin >> key;
				if (key >= 1 && key <= 25) {
					decrypt(msg, key);
					cout << '\n';
					std::this_thread::sleep_for(1s);
					break;
				} else {
					// Invalid input, wait one second and ask for input again.
					cout << "ERROR: Input must be between 1 and 25 inclusive.\n";
					std::this_thread::sleep_for(1s);
				}
			}
		} else {
			// Invalid input, wait one second and ask for input again.
			cout << "ERROR: Input must either be (e) for encrypt, or (d) for decrypt.\n";
			std::this_thread::sleep_for(1s);
		}
	}
	return 0;
}
