#include <iostream>
#include <stdio.h>
#include <sqlite3.h>



//globals
int logged_in = 0;



// -----------------database------------------

static int createDB(const char* s);
static int createTable(const char* s);

// -------------------------------------------


int login() {
	return 0;
}
void createUser() {}

void welcome()
{
	int user_input;
	int valid_input = 0;

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "|Welcome to United Bank of Some Country|" << std::endl;
	std::cout << "----------------------------------------\n\nPlease choose an option:\n" << std::endl;
	std::cout << "1. Sign in" << std::endl;
	std::cout << "2. Sign up" << std::endl;
	std::cout << "3. Exit\n" << std::endl;

	while (!valid_input) {

		std::cout << ">> ";
		std::cin >> user_input;

		switch (user_input) {
		case 1:
			valid_input = 1;
			login();
			break;
		case 2:
			valid_input = 1;
			createUser();
			break;
		case 3:
			exit(3);
			break;
		default:
			std::cout << "Not a valid option. Please try again.\n" << std::endl;
			break;
		}
	}


}

int main()
{
	
	
	while (!logged_in) {
		welcome();
	}
	






	return 0;
}