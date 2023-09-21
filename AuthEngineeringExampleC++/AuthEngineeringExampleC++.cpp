#include <iostream>
#include <Windows.h>
#include "Auth.h"

std::string AppId = "1"; // REPLACE with your App ID
std::string AppToken = "2ad593c28c414117bd16b5a49fcc3b1787c3078cf991ae5830458d283357"; // REPLACE with your App Token
std::string AppVersion = "1"; // REPLACE with your App Version
int AppEncryption = 471508791; // REPLACE with your App Encryption Key

bool AdvancedChecks = true; // Continue to check if the key is valid after login (If the key expires, the application closes automatically)

// This code is probably not enough to be protected, so please try to: encrypt your string, make your if() unrecognizable and hide the call to the authentication functions.
// It is not recommended to print info about the key being valid or not

int main()
{
    std::cout << "Welcome to auth.enginnering c++ example usage:\n Please Enter Your Key -> ";
    std::string Key; 
    std::cin >> Key;

    uintptr_t LoginResult = Login(AppId, Key, AppVersion, AdvancedChecks); // Verify if the Key is valid
    if (!LoginResult)  {
        std::cout << "[-] Key is not Valid//Outdated Version/Key is now registered please retry in 15seconds\n"; 
        Sleep(1000); 
        exit(0);
    }

    if (std::string((char*)(LoginResult ^ AppEncryption)) != AppToken) { // Verify App Token returned by the server
        std::cout << "[-] Key is not Valid\n";
        Sleep(1000);
        exit(0);
    }

    if (GetToken() != AppToken) { // Verify Stored App Token (OPTIONAL)
        std::cout << "[-] Token is not Valid\n"; 
        Sleep(1000); 
        exit(0);
    }

    std::cout << "[+] Login Success\n";

    std::string test = GetVariable("test"); // REPLACE with the variable name you want to fetch (OPTIONAL)
    std::cout << test << "\n";

    system("pause");
}
