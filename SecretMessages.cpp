#include <iostream>
#include <string>
using namespace std;

string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
string key{ "XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr" }; // can be changed if desired

string encodeMessage(string userMessage) {
    string encryptedMessage{};

    for (char c : userMessage) { 
        size_t position = alphabet.find(c); //  index of letter based off alphabet string
        if (position != string::npos) { // if there is a char there, append new_char to encryptedMessage
            char new_char{ key.at(position) };
            encryptedMessage += new_char;
        } else {
            encryptedMessage += c; // maintains spaces and punctuation
        }
    }


    return encryptedMessage;
}

string decodeMessage(string userMessage) {
    string decryptedMessage{};

    for (char c : userMessage) { // basically the opposite of the encodeMessage() function
        size_t position = key.find(c); 
        if (position != string::npos) {
            char new_char{ alphabet.at(position) };
            decryptedMessage += new_char;
        }
        else {
            decryptedMessage += c;
        }
    }


    return decryptedMessage;
   
}

int main() {

    string userMessage;
    char userInput;

    cout << "Would you like to [D] decode a message, or [E] encode a message?" << endl;
    cin >> userInput;
    cin.ignore(1, '\n'); // allows for user input after the initial choice of 'd' or 'e'


    switch (tolower(userInput)) {
        case 'd':
            cout << "Please enter a message: ";
            getline(cin, userMessage);

            cout << "Your decoded message is: " << decodeMessage(userMessage) << endl;
            break;
        case 'e':
            cout << "Please enter a message: ";
            getline(cin, userMessage);

            cout << "Your encoded message is: " << encodeMessage(userMessage) << endl;
            break;
        default:
            cout << "Invalid choice. Exiting. . ." << endl;
    }
    return 0;
}
