#include "ControlDevice.h"			//�Զ����豸����ļ�
 
int livingroomLightInit(int pinNum)         //C���Ա���Ҫ���Σ�JAVA���ã���ֱ�ӷ��ʱ�����ֵ
{
	pinMode(pinNum,OUTPUT);					//��������Ϊ���ģʽ
	digitalWrite(pinNum,HIGH);				//�����øߵ�ƽ���Ͽ��̵���
}
 
int livingroomLightOpen(int pinNum)
{
	digitalWrite(pinNum,LOW);				//�����õ͵�ƽ���պϼ̵���
}
 
int livingroomLightClose(int pinNum)
{
	digitalWrite(pinNum,HIGH);				//�����øߵ�ƽ���Ͽ��̵���
}
 
int livingroomLightStatus(int status)
{
	
}
 
struct Devices livingroomLight = {			//��������ƣ�����
	.deviceName = "livingroomLight",		//����
	.pinNum = 8,							//����� 16��(wPi)����
	.Init = livingroomLightInit,			//ָ����ʼ������
	.open = livingroomLightOpen,			//ָ�����򿪵ơ�����
	.close = livingroomLightClose,			//ָ�����رյơ�����
    .changeStatus = livingroomLightStatus
};
 
struct Devices* addLivingroomLightToDeviceLink(struct Devices *phead)		//�����ƣ����󣩼����豸������
{
	if(phead == NULL){
		return &livingroomLight;
	}else{
		livingroomLight.next = phead;  //��ǰ��ͷ���.next
		phead = &livingroomLight;      //����ͷ
		return phead;
	}
}