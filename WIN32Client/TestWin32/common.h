#pragma once



//�����,��ʾ�������崦������
#define PACKET_REQ_CMD 10001 //��ʾ CMD������������ �ͻ���-->�����
#define PACKET_RLY_CMD 10002 //��ʾ CMD���ͻظ����� �����-->�ͻ���

#define PACKET_REQ_KEYBOARD 20001 //��ʾ KEYBOARD������������ �ͻ���-->�����
#define PACKET_RLY_KEYBOARD 20002 //��ʾ KEYBOARD���ͻظ����� �����-->�ͻ���

#pragma pack(push) //��ʾԭ�е��ṹ���Сѹջ
#pragma pack(1)
struct MyPacket
{
	unsigned int type; //����
	unsigned int Length; //����
	char data[1]; //����һ�� 1�ֽڵ�����
}; 
#pragma pack(pop)//��ʾԭ�е��ṹ���С��ջ