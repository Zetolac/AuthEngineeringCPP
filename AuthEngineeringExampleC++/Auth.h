#pragma once
#include <string>
#pragma comment(lib, "Auth.lib")

#define AUTH_API __declspec(dllimport)
extern "C" AUTH_API __int64 Login(std::string AppId, std::string Key, std::string AppVersion);
extern "C" AUTH_API std::string GetToken();
extern "C" AUTH_API std::string GetVariable(std::string Name);
extern "C" AUTH_API void DiscordLog(std::string Message);
