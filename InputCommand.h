#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>      
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <wiringPi.h>
#include <wiringSerial.h>
 
struct InputCommand
{
    char commandName[128];                              //�����Ʒ�ʽ����
    char deviceName[128];               
    char command[32];                                   //���ָ��
    int fd;                                             //����ļ�������������/���磩
    int s_fd;									        //��ŷ������׽���������
    char port[12];								        //��Ŷ˿ں�
    char ipAdress[32];							        //��� IP��ַ
    char log[1024];                                     //��־
    int (*Init)(struct InputCommand *voice);            //����ʼ��������ָ��
    int (*getCommand)(struct InputCommand *voice);      //����ȡָ�����ָ��
 
    struct InputCommand *next;
};
 
struct InputCommand* addVoiceControlToInputCommandLink(struct InputCommand *phead);		//���������ơ�����ָ������������
struct InputCommand* addSocketControlToInputCommandLink(struct InputCommand *phead);