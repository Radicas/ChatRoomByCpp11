#include <iostream>
#include <string>
#include "/usr/local/mysql-8.0.22-macos10.15-x86_64/include/mysql.h"
using namespace std;
class Database
{
public:
	Database();
	~Database();

	int init_db(std::string host, std::string user, std::string password, std::string db_name);
	void run();
private:
	int exe_sql();
	int insert_sql();
	int delete_sql();
	int update_sql();
	MYSQL* connection;
	MYSQL_RES* result;
	MYSQL_ROW row;
};
