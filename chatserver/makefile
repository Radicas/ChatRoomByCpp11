db:server.cpp mydb.cpp
	g++ -o server server.cpp mydb.cpp `mysql_config --cflags --libs` 
	
clean:
	rm -r -f server *.o dbtest
