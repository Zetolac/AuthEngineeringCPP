#include <iostream>
#include <Windows.h>
#include "Auth.h"

std::string AppId = ""; // REPLACE with your App ID
std::string AppToken = ""; // REPLACE with your App Token
std::string AppVersion = ""; // REPLACE with your App Version
int AppEncryption = 0; // REPLACE with your App Encryption Key

// This code is probably not enough to be protected, so please try to: encrypt your string, make your if() unrecognizable and hide the call to the authentication functions.
// It is not recommended to print info about the key being valid or not

int main()
{
    std::cout << "Welcome to auth.enginnering c++ example usage:\n Please Enter Your Key -> ";
    std::string Key;
    std::cin >> Key;

    uintptr_t LoginResult = Login(AppId, Key, AppVersion); // Verify if the Key is valid
    if (!LoginResult) 
        exit(0);

    if (std::string((char*)(LoginResult ^ AppEncryption)) != AppToken) // Verify App Token returned by the server
        exit(0);

    if (GetToken() != AppToken) // Verify Stored App Token (OPTIONAL)
       exit(0);
    
    std::cout << "[+] Login Success\n";

    std::string test = GetVariable("test"); // REPLACE with the variable name you want to fetch (OPTIONAL)
    std::cout << "My Varaible Test: " << test << "\n"; // (OPTIONAL)

    DiscordLog("Hello! This is a test Message!"); // REPLACE with the message you wish to send to your webhook discord (OPTIONAL) config: Dashboard -> AppSettings

    system("pause");
}
