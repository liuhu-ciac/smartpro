#include "ControlDevice.h"			//�Զ����豸����ļ�
 
int buzzerInit(int pinNum)
{
	pinMode(pinNum,OUTPUT);						//��������Ϊ���ģʽ
	digitalWrite(pinNum,HIGH);					//�����øߵ�ƽ���������ر�
}
 
int buzzerOpen(int pinNum)
{
	digitalWrite(pinNum,LOW);					//�����õ͵�ƽ������������
}
 
int buzzerClose(int pinNum)
{
	digitalWrite(pinNum,HIGH);					//�����øߵ�ƽ���������ر�
}
 
struct Devices buzzer = {						//���������������
	.deviceName = "buzzer",						//����
	.pinNum = 11,								//����� 9��(wpi)����
	.Init = buzzerInit,							//ָ����ʼ������
	.open = buzzerOpen,							//ָ��������������������
	.close = buzzerClose,						//ָ�����رշ�����������
};
 
 
struct Devices* addBuzzerToDeviceLink(struct Devices *phead)		//�����������󣩼����豸������
{
	if(phead == NULL){
		return &buzzer;
	}else{
		buzzer.next = phead;
		phead = &buzzer;
		return phead;
	}
}