#include <iostream>
#include <string>
#include <mysql/mysql.h>
class Database
{
public:
	Database();
	~Database();

	int init_db(std::string host, std::string user, std::string password, std::string db_name);
	void do_exe_sql(std::string name);
	void do_insert_sql();
	void do_delete_sql();
	void do_update_sql();
private:
	int exe_sql();
	bool exe_sql(std::string name);	
	int insert_sql();
	int delete_sql();
	int update_sql();
	MYSQL* connection;
	MYSQL_RES* result;
	MYSQL_ROW row;
};
