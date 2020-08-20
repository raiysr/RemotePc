#pragma once



//定义宏,表示包到具体处理类型
#define PACKET_REQ_CMD 10001 //表示 CMD类型请求数据 客户端-->服务端
#define PACKET_RLY_CMD 10002 //表示 CMD类型回复数据 服务端-->客户端

#define PACKET_REQ_KEYBOARD 20001 //表示 KEYBOARD类型请求数据 客户端-->服务端
#define PACKET_RLY_KEYBOARD 20002 //表示 KEYBOARD类型回复数据 服务端-->客户端

#pragma pack(push) //表示原有到结构体大小压栈
#pragma pack(1)
struct MyPacket
{
	unsigned int type; //类型
	unsigned int Length; //长度
	char data[1]; //定义一个 1字节的数组
}; 
#pragma pack(pop)//表示原有到结构体大小出栈