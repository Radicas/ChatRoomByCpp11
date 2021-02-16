#include "mydb.h"
#include <cstdlib>

Database::Database()
{
	connection = mysql_init(NULL);
	if(connection == NULL)
	{
		std::cout << "mysql init error:" << mysql_error(connection);
		exit(1);
	}
}

Database::~Database()
{
	if(connection != NULL)
	{
		mysql_close(connection);
	}
}

int Database::init_db(std::string host, std::string user, std::string password, std::string db_name)
{
	char value = 1;
	mysql_options(connection, MYSQL_OPT_RECONNECT, (char*)&value);
	connection = mysql_real_connect(connection, host.c_str(), user.c_str(), password.c_str(), db_name.c_str(), 0, NULL, 0);
	if(connection == NULL)
	{
		std::cout << "real connect mysql error:" << mysql_error(connection);
		exit(1);
	}
	return 0;
}
/*
 *
 *
int Database::exe_sql()
{
	std::string sql;
	sql = "select * from user;";
	if(mysql_query(connection, sql.c_str()))
	{
		std::cout << "Query error:" << mysql_error(connection);
		exit(1);
	}else
	{
	
		result = mysql_use_result(connection);
		for(int i=0; i<mysql_field_count(connection); i++)
		{
			row = mysql_fetch_row(result);
			if(row==NULL)
			{
				break;
			}else
			{
				for(int j=0; j<mysql_num_fields(result); j++)
				{
					std::cout << row[j] << "\t";
				}
				std::cout << std::endl;	
			}
		}

	//	for(int i=0; i<mysql_field_count(connection); ++i)
	//	{
	//		row = mysql_fetch_row(result);
	//		if(row == NULL)
	//			break;
	//		for(int j=0; j<mysql_num_fields(result); ++i)
	//		{
	//			std::cout << row[j] << "\t";
	//		}
	//		std::cout << endl;
	//	}
		
		std::cout << std::endl;
		mysql_free_result(result);
	}
	return 0;
}
*/
bool Database::query_name_sql(std::string name)
{
	std::string sql = "select u_name from user where u_name='"+name+"';";
	if(mysql_query(connection, sql.c_str()))
	{
		std::cout << "exe_sql query error" << mysql_error(connection);
		exit(1);
	}else
	{
		result = mysql_use_result(connection);	
		row = mysql_fetch_row(result);
		if(row == NULL)
		{
			return false;
		}else
		{
			return true;
		}
	}
}

void Database::do_query_name_sql(std::string name)
{
	query_name_sql(name);
}

int Database::insert_sql()
{
	std::string usrname;
	std::string pwd;
	std::cout << "entter name and password" << std::endl;
	std::cin >> usrname >> pwd;
	std::string sql = "insert into user(u_id,u_name,u_pwd)values(NULL,'"+usrname+"','"+pwd+"');";
	if(mysql_query(connection, sql.c_str()))
	{
		std::cout << "Insert Error:" << mysql_error(connection);
		exit(1);
	}
	std::cout << std::endl;
	return 0;
}

int Database::delete_sql()
{
	std::string id;
	std::cout << "enter id you wanna delete" << std::endl;
	std::cin >> id;
	std::string sql = "delete from user where u_id = "+id+";";
	if(mysql_query(connection, sql.c_str()))
	{
		std::cout << "Delete Error:" << std::endl;
		exit(1);
	}
	std::cout << std::endl;
	return 0;
}

int Database::update_sql()
{
	std::string id;
	std::string thing;
	std::cout << "enter id and the thing you wanna change" << std::endl;
	std::cin >> id >> thing;
	std::string sql = "update user set"+thing+"where u_id="+id+";";
	if(mysql_query(connection, sql.c_str()))
	{
		std::cout << "Update Error:" << std::endl;
		exit(1);
	}
	std::cout << std::endl;
	return 0;
}
