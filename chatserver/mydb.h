#include <iostream>
#include <string>
#include <mysql/mysql.h>
class Database
{
public:
	Database();
	~Database();

	int init_db(std::string host, std::string user, std::string password, std::string db_name);
	bool do_query_name_sql(std::string name);
	bool do_insert_sql(std::string name, std::string password);
	void do_delete_sql();
	void do_update_sql();
private:
	bool query_name_sql(std::string name);	
	bool insert_sql();
	int delete_sql();
	int update_sql();
	MYSQL* connection;
	MYSQL_RES* result;
	MYSQL_ROW row;
};
