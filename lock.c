#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <signal.h>
#include <wiringPi.h>
#include "ControlDevice.h"

static int count = 0;
int angle;
int lockInit(int pinNum)         //C���Ա���Ҫ���Σ�JAVA���ã���ֱ�ӷ��ʱ�����ֵ
{
	pinMode(pinNum,OUTPUT);					//��������Ϊ���ģʽ
	digitalWrite(pinNum,HIGH);				//�����øߵ�ƽ���Ͽ��̵���
 system("sudo ./sg90/a.out 3");
}
 
int lockOpen(int pinNum)
{
   system("sudo ./sg90/a.out 1");
}
 
int lockClose(int pinNum)
{
   system("sudo ./sg90/a.out 3");

} 
int lockStatus(int status)
{
	
}
 
struct Devices lock = {			//��������ƣ�����
	.deviceName = "lock",		//����
	.pinNum = 10,							//����� 16��(wPi)����
	.Init = lockInit,			//ָ����ʼ������
	.open = lockOpen,			//ָ�����򿪵ơ�����
	.close = lockClose,			//ָ�����رյơ�����
  .changeStatus = lockStatus
};
 
struct Devices* addLockToDeviceLink(struct Devices *phead)		//�����ƣ����󣩼����豸������
{
	if(phead == NULL){
		return &lock;
	}else{
		lock.next = phead;  //��ǰ��ͷ���.next
		phead = &lock;      //����ͷ
		return phead;
	}
}
