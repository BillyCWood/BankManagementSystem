#include <iostream>
#include <stdio.h>
#include <sqlite3.h>



//globals
int logged_in = 0;
const char* dir = "C:\\Users\\Billy Wood\\Coding\\cpp_projs\\BankManagementSystem\\BANK.db";


/*
// -----------------database------------------

static int execSQLStmt(const char* s, std::string sql) {

	sqlite3* DB;

	try
	{
		int exit = sqlite3_open(s, &DB);

		char* messageError;
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

		if (exit != SQLITE_OK)
		{
			std::cerr << "Error Create Table: " << messageError << std::endl;
			sqlite3_free(messageError);
		}
		else std::cout << "Table Created Successfully" << std::endl;

		sqlite3_close(DB);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}

	return 0;
}



static int createDB(const char* s)
{
	sqlite3* DB;

	int exit = sqlite3_open(s, &DB);
	sqlite3_close(DB);

	return 0;
}


static int createTable(const char* s)
{

	// Customer Personal Info
	std::string sql = "CREATE TABLE IF NOT EXISTS CUSTOMER_PERSONAL_INFO("
		"CUSTOMER_ID	INTEGER PRIMARY KEY AUTOINCREMENT, "
		"ACC_NO			INTEGER(12), "
		"FIRST_NAME		TEXT NOT NULL, "
		"LAST_NAME		TEXT NOT NULL, "
		"DATE_OF_BIRTH	DATE, "
		"GENDER			CHAR(1), "
		"EMAIL			VARCHAR(30), "
		"PHONE			INT(10), "
		"ADDRESS		VARCHAR(50), "
		"PASSWORD		TEXT NOT NULL);";


	// Account Info
	sql.append("CREATE TABLE IF NOT EXISTS ACCOUNT_INFO("
		"ACC_NO				INTEGER(12) PRIMARY KEY, "
		"CUSTOMER_ID		INTEGER, "
		"ACCOUNT_TYPE		VARCHAR(15), "
		"BALANCE			MONEY, "
		"IFSC				VARCHAR(11), "
		"CONSTRAINT FK_CUST_ID FOREIGN KEY  (CUSTOMER_ID) REFERENCES CUSTOMER_PERSONAL_INFO(CUSTOMER_ID)); "
	);


	execSQLStmt(s, sql);


	// Bank Info
	//ifsc code
	//bank name
	//branch name
	//constraint [pk -> ifsc code]



	return 0;


}



static int insertData(const char* s)
{
	sqlite3* DB;
	char* messageError;

	int exit = sqlite3_open(s, &DB);

	std::string sql(";");

	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		std::cerr << "Error Insert" << std::endl;
		sqlite3_free(messageError);
	}
	else std::cout << "Records created Successfully!" << std::endl;

	return 0;
}

// -------------------------------------------
*/

static int callback(void* NotUsed, int argc, char** argv, char** azColName)
{

	for (int i = 0; i < argc; i++)
	{
		//col name and value
		std::cout << azColName[i] << ": " << argv[i] << std::endl;
	}


	return 0;
}

int login()
{
	// open and connect to DB
	sqlite3* DB;
	char* err_msg = 0;
	sqlite3_stmt* res;
	int rc = sqlite3_open(dir, &DB);

	if (rc != SQLITE_OK) {
		std::cout << "Cannot open database: " << sqlite3_errmsg(DB) << std::endl;
		sqlite3_close(DB);

		return 1;
	}

	const char* sql = "SELECT EMAIL FROM CUSTOMER_PERSONAL_INFO WHERE EMAIL=@email";


	std::string email;
	std::string password;
	std::cout << "email: ";
	std::cin >> email;
	std::cout << "password: ";
	std::cin >> password;
	std::cout << std::endl;
	

	rc = sqlite3_prepare_v2(DB, sql, -1, &res, 0);


	if (rc == SQLITE_OK) {
		int index = sqlite3_bind_parameter_index(res, "@email");
		sqlite3_bind_text(res, index, email.c_str(), sizeof(email), SQLITE_STATIC);
	}
	else {
		std::cerr << "Unable to create statement '" << sql << "': " << sqlite3_errmsg(DB)<< std::endl;
	}



	sqlite3_finalize(res);
	sqlite3_close(DB);
	return 0;
}
int createUser() 
{
	std::string fname, lname, email, address, password;
	char gender = 'z';
	int phoneNum;

	std::cout << "First Name: ";
	std::cin >> fname;
	std::cout << "Last Name: ";
	std::cin >> lname;

	int gender_loop = 1;
	while (gender_loop)
	{
		std::cout << "Gender(M/F): ";
		std::cin >> gender;
		gender = toupper(gender);

		switch (gender)
		{
		case 'M':
			gender_loop = 0;
			break;
		case 'F':
			gender_loop = 0;
			break;
		default:
			std::cout << "Not a valid input" << std::endl;
		}
	}
	




	// open and connect to DB
	sqlite3* DB;
	char* err_msg = 0;
	sqlite3_stmt* res;
	int rc = sqlite3_open(dir, &DB);

	if (rc != SQLITE_OK) {
		std::cout << "Cannot open database: " << sqlite3_errmsg(DB) << std::endl;
		sqlite3_close(DB);

		return 1;
	}

	const char* sql = "INSERT INTO CUSTOMER_PERSONAL_INFO (FIRST_NAME, LAST_NAME, DATE_OF_BIRTH, GENDER, EMAIL, PHONE, ADDRESS, PASSWORD) VALUES();";

	return 0;
}

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
	
	


	//createDB(dir);
	//createTable(dir);



	while (!logged_in) {
		welcome();
	}
	






	return 0;
}