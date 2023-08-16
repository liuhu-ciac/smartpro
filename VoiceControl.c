#include "InputCommand.h"
 
int voiceInit(struct InputCommand *voice)
{
    int fd;
    if ((fd = serialOpen (voice->deviceName, 115200)) < 0) { 
        fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ; 
        return 1 ; 
    }
    voice->fd = fd;
    return fd;
}
 
int voiceGetCommand(struct InputCommand *voice)
{
    int nread = 0;
    nread = read(voice->fd, voice->command, sizeof(voice->command));    //��ȡ����
    return nread;            //���ض�ȡ�����ݵ��ֽ���,ʵ�ʶ�ȡ��ָ��ŵ���command��
}

 
struct InputCommand voiceControl = {
    .commandName = "voice",
    .deviceName = "/dev/ttyS5",
    .command = '\0',
    .Init = voiceInit,
    .getCommand = voiceGetCommand,
    .log = {'\0'},
    .next = NULL
};
 
struct InputCommand* addVoiceControlToInputCommandLink(struct InputCommand *phead)	//���������ơ������󣩼���ָ�ʽ������
{
	if(phead == NULL){
		return &voiceControl;
	}else{
		voiceControl.next = phead;
		phead = &voiceControl;
		return phead;
	}
}
