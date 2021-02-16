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
		std::cout << "query user error" << mysql_error(connection);
		exit(1);
	}else
	{
		result = mysql_use_result(connection);	
		row = mysql_fetch_row(result);
		if(row == NULL)
		{
			mysql_free_result(result);
			return false;
		}else
		{
			mysql_free_result(result);
			return true;
		}
	}
}

bool Database::do_query_name_sql(std::string name)
{
	return query_name_sql(name);
}

bool Database::query_login_sql(std::string name, std::string password)
{
	std::string sql = "select * from user where u_name='"+name+"' and u_pwd='"+password+"';";	
	if(mysql_query(connection, sql.c_str()))
	{
		std::cout << "query_login_sql error" << mysql_error(connection);
		exit(1);
	}else
	{
		result = mysql_use_result(connection);
		row = mysql_fetch_row(result);
		if(row == NULL)
		{
			mysql_free_result(result);
			return false;
		}else
		{
			mysql_free_result(result);
			return true;
		}
	}
}

bool Database::do_query_login_sql(std::string name, std::string password)
{
	return query_login_sql(name, password);	
}

bool Database::insert_sql(std::string name, std::string password)
{
	std::string sql = "insert into user(u_id,u_name,u_pwd)values(NULL,'"+name+"','"+password+"');";
	if(mysql_query(connection, sql.c_str()))
	{
		std::cout << "Insert Error:" << mysql_error(connection);
		exit(1);
	}
	if(query_name_sql(name))
	{
		return true;
	}else
	{
		return false;
	}
	return 0;
}

bool Database::do_insert_sql(std::string name, std::string password)
{
	return insert_sql(name, password);
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
