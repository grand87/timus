#include <iostream>
#include <list>
#include <map>
#include <algorithm>

const char *cReg = "register";
const char *cLogin = "login";
const char *cLogout = "logout";


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	unsigned int operationsCount = 0;
	std::cin >> operationsCount;

	std::map<std::string, std::string> registeredUsers;
	std::map<std::string, bool> loginedUsers;

	char command[20];
	char user[31];
	char password[31];

	for (unsigned int operation = 0; operation < operationsCount; ++operation)
	{
		std::cin >> command;
		std::cin >> user;

		if (strcmp(command, cReg) == 0)
		{
			std::cin >> password;
			if (registeredUsers.find(user) == registeredUsers.end())
			{
				registeredUsers[user] = password;
				std::cout << "success: new user added";
				loginedUsers[user] == 0;
			}
			else
			{
				std::cout << "fail: user already exists";
			}	
		}
		else
		if (strcmp(command, cLogin) == 0)
		{
			std::cin >> password;
			if (registeredUsers.find(user) != registeredUsers.end())
			{
				if (registeredUsers[user].compare(password) == 0)
				{
					if (loginedUsers[user] == 1)
						std::cout << "fail: already logged in";
					else
					{
						std::cout << "success: user logged in";
						loginedUsers[user] = 1;
					}
				}
				else
					std::cout << "fail: incorrect password";
			}
			else
			{
				std::cout << "fail: no such user";
			}
		}
		else
		if (strcmp(command, cLogout) == 0)
		{
			if (registeredUsers.find(user) != registeredUsers.end())
			{
				if (loginedUsers[user] == 0)
				{
					std::cout << "fail: already logged out";
				}
				else
				{
					std::cout << "success: user logged out";
					loginedUsers[user] = 0;
				}
			}
			else
			{
				std::cout << "fail: no such user";
			}
		}
		std::cout << std::endl;
	}
	
	return 0;
}
