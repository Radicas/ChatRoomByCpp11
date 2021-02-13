#include <iostream>
#include "database.h"

int main()
{
	Database db;
	db.init_db("127.0.0.1", "root", "00000000", "chatroom");
	db.run();
	return 0;
}
