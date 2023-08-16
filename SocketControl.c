#include "InputCommand.h"
 
int socketInit(struct InputCommand *socketMsg)
{
 
    int s_fd;                                       //�׽���������
	struct sockaddr_in s_addr;
	memset(&s_addr,0,sizeof(struct sockaddr_in));   //�������
 
    //1.socket
	s_fd=socket(AF_INET,SOCK_STREAM,0);             //�����׽���,ipv4 tcpЭ��
	if(s_fd == -1){                                 //�������׽���ʧ��
		perror("socket:");
		exit(-1);
	}
 
    s_addr.sin_family = AF_INET;                        //ipv4
	s_addr.sin_port = htons(atoi(socketMsg->port));     //�˿ںţ�ѡ��5000���ϡ�honts���������ֽ���,atoi(argv[2])��ֹ�˿ڱ�ռ��
	inet_aton(socketMsg->ipAdress,&s_addr.sin_addr);    //ת��Ϊ������ʶ��ĸ�ʽ
 
    //2.bind
	bind(s_fd,(struct sockaddr *)&s_addr,sizeof(struct sockaddr_in));
 
    //3.listen
	listen(s_fd,10);//����10������
    printf("socket Server listening ...\n");
 
    socketMsg->s_fd = s_fd;						    //�����׽���������
    return s_fd;
}
 
struct InputCommand socketControl = {
    .commandName = "socket",
    .command = '\0',
    .port = "8080",
    .ipAdress = "192.168.31.111",
    .Init = socketInit,
    .log = {'\0'},
    .next = NULL
};
 
struct InputCommand* addSocketControlToInputCommandLink(struct InputCommand *phead)
{
	if(phead == NULL){
		return &socketControl;
	}else{
		socketControl.next = phead;
		phead = &socketControl;
		return phead;
	}
}