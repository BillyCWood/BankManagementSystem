#pragma once
#include<iostream>
class Customer
{
public:
	void displayPersonalInfo();
	void changeFName(std::string fname);
	void changeLname(std::string lname);
	void changeEmail(std::string email);
	void changePhone(int num);
	void changeAddress(std::string address);
	void changePassword(std::string password);
	void deleteAccount();
};

