// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: vignereCipher.cpp
// Program Description : Vignere Cipher
// Author1 and ID : Abdulrahman Ibrahim 20210193
// Last Modification : 23 Mar 2022
// Purpose: To cipher and decipher messages using vignere cipher technique.

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

string convertStrToUppercase(string msg);

string cipherMsg(string msg, string cipherKey);

string deCipherMsg(string cipheredMsg, string cipherKey);

string cipheredMsgLength(int limit); // to check if message that user want to cipher it isn't more than 80 character.

string decipheredMsgLength(int limit);// to check if message that user want to decipher it isn't more than 80 character.

string keyLength(int limit); // to check if message that key isn't more than 80 character.

int main()
{
    string msg, key;
    int choice;

    while (true){
        cout << "Choose what you want." << endl << "1- Cipher a message"
      << endl  << "2- Decipher a message"<< endl << "3- End" << endl;
        cin >> choice;

        if (choice == 1){
            msg = cipheredMsgLength(80);
            key = keyLength(8);
            cout << "Ciphered message is " <<cipherMsg(convertStrToUppercase(msg),convertStrToUppercase(key));
            break;
        }
        else if ( choice == 2){
            msg = decipheredMsgLength(80);
            key = keyLength(8);
            cout << "Deciphered message is " << endl << deCipherMsg(msg,key);
            break;
        }
        else if (choice == 3)
            break;
        else{
            cout << "Please check that you entered one of these choices";
            continue;
        }
    }
}

string convertStrToUppercase(string msg)
{

    transform(msg.begin(), msg.end(), msg.begin(), ::toupper); // to make all charaters uppercase.
    return msg;
}

string cipherMsg(string msg, string cipherKey)
{
    string cipheredMsg;
    int charKeyIndex = 0;

    for (int charMsgIndex = 0; charMsgIndex < msg.length(); charMsgIndex++)
    {

        if (charKeyIndex == cipherKey.length() ) // rephrase it::check if char index of key has passed the end of string.
            charKeyIndex = 0; // To make the key start from first char again
        if (!isalpha(msg[charMsgIndex])) // To check if it's not character for example space program will store it without ciphering it.
        {
            cipheredMsg.push_back(msg[charMsgIndex]);
            charKeyIndex++;
            continue;
        }

        cipheredMsg.push_back(((msg[charMsgIndex] + cipherKey[charKeyIndex]) % 26) + 65); // store cipherd msg to variable cipheredMsg.
        // We add 65 because first char => 'A' it's value in ascii = 65.

        charKeyIndex++;
    }
    return cipheredMsg;
}

string deCipherMsg(string cipheredMsg, string cipherKey)
{
    string deCipheredMsg;
    int charKeyIndex = 0;

    for (int charMsgIndex = 0; charMsgIndex < cipheredMsg.length(); charMsgIndex++) //loop on Msg
    {

        if (charKeyIndex == cipherKey.length()) 
            charKeyIndex = 0; // To make the key start from first char again.

        if (!isalpha(cipheredMsg[charMsgIndex])) // To check if it's not character for example space program will store it without deciphering it.
        {
            deCipheredMsg.push_back(cipheredMsg[charMsgIndex]);
            charKeyIndex++;
            continue;
        }

        if (cipheredMsg[charMsgIndex] - cipherKey[charKeyIndex] < 0)
            deCipheredMsg.push_back((cipheredMsg[charMsgIndex] - cipherKey[charKeyIndex]) % 26 + 65 + 26);
        // We add 65 because first char => 'A' it's value in ascii = 65.
        // we add 26 in case negative values to get the correct character.
        else
        deCipheredMsg.push_back((((cipheredMsg[charMsgIndex] - cipherKey[charKeyIndex])) % 26) + 65);

        charKeyIndex++;
    }
    return deCipheredMsg;

}

string cipheredMsgLength(int limit)
{
    string msg;
    while (true)
    {
        cout << "Enter the message you want to cipher it : ";
        getline(cin >> ws, msg);
        cout << endl;
        if (msg.length() <= limit)
            return msg;
        else{
            cout << "Message must be less than or equal " << limit << endl;
            continue;
            }
    }


}
string decipheredMsgLength(int limit){
    string msg;
    while (true)
    {
        cout << "Enter the message that you want to decipher it : ";
        getline(cin >> ws,msg);
        cout << endl;
        if (msg.length() <= limit)
            return msg;
        else
        {
            cout << "Message must be less than or equal " << limit << endl;
            continue;
        }

    }


}
string keyLength(int limit)
{
    string key;
    while (true)
    {
        cout << "Enter the key of message : ";
        getline(cin >> ws,key);
        cout << endl;
        if (key.length() <= limit)
            return key;
        else
        {
            cout << "Key must be less than or equal " << limit << endl;
            continue;
        }
    }


}
