#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>
#include "mydb.h"
#define BUF_SIZE 100


void error_handling(const char message[]);
int main(int argc, char* argv[])
{
	int serv_sock, clnt_sock;	//服务端、客户端套接字
	struct sockaddr_in serv_adr, clnt_adr;	//套接字结构体
	struct timeval timeout;	//设置超时
	fd_set reads, cpy_reads;	//fd变量	
	Database db;
	db.init_db("127.0.0.1","zhupeng","00000000","chatroom");

	socklen_t adr_sz;	//结构体长度
	int fd_max, str_len, fd_num, i;
	char buf[BUF_SIZE];
	if(argc!=2)
	{
		printf("Usage: %s <port>", argv[0]);
		exit(1);
	}
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	if(serv_sock == -1)
		error_handling("socket error");
	
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(atoi(argv[1]));
	
	if(bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)
		error_handling("bind error");
	if(listen(serv_sock, 5)==-1)
		error_handling("listen error");

	FD_ZERO(&reads);	//fd_set变量初始化
	FD_SET(serv_sock, &reads);	//将serv_sock信息注册到reads变量中
	fd_max = serv_sock;	//最大文件描述符
	
	while(1)
	{
		cpy_reads = reads;	//拷贝reads变量，因为用完清零
		timeout.tv_sec = 2;	//超时5秒
		timeout.tv_usec = 2000;
		/*
		 *select函数
		 *第一个参数:注册的文件描述符的个数
		 *第二个参数:传递注册了套接字信息的fd_set变量地址，read_set
		 *第三个参数:传递注册了套接字信息的变量地址，write_set，没有则为0
		 *第四个参数:注册异常套接字的变量
		 *第五个参数:超时时间
		 *成功返回正整数，失败返回-1，超时返回0
		 * */
		if((fd_num = select(fd_max+1, &cpy_reads, 0, 0, &timeout))==-1)	//调用select函数
		{
			error_handling("select error");
			break;
		}
		if(fd_num == 0)
		{
			continue;
		}
		for(i=0; i<fd_max+1; i++)
		{
			if(FD_ISSET(i, &cpy_reads))	//fd_set变量中第i个位置是否包含目标文件描述符
			{
				if(i==serv_sock)
				{
					adr_sz = sizeof(clnt_adr);
					clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &adr_sz);
					if(clnt_sock == -1)
						error_handling("accept error");
					FD_SET(clnt_sock, &reads);
					if(fd_max<clnt_sock)
						fd_max = clnt_sock;
					printf("connected client: %d \n", clnt_sock);
				}else
				{
					str_len = read(i, buf, BUF_SIZE);
					if(str_len == 0)
					{
						FD_CLR(i, &reads);	
						close(i);
						printf("closed client: %d \n", i);
					}else if(str_len == -1)
					{
						error_handling("read error");
					}else
					{
						//处理来自客户端的消息
						std::string buf_head(buf, 5);
						if(buf_head == "<sql>")
						{
							//登录注册信息处理
							std::string sql_msg = buf;
							int pos_right_ab = sql_msg.find('>');
							int pos_comma = sql_msg.find(',');
							std::string name = sql_msg.substr(pos_right_ab+1, pos_comma-pos_right_ab-1);
							std::string pwd = sql_msg.substr(++pos_comma);
						
							printf("sql message \n");
						}

						if(buf_head == "<msg>")
						{
							printf("chat message \n");
						}
					}
				}
			}
		}
	}
	close(serv_sock);
	return 0;
}

void error_handling(const char message[])
{
	std::cout << message << std::endl;
	exit(1);
}
