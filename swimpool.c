#include "ControlDevice.h"			//�Զ����豸����ļ�
 
int swimpoolLightInit(int pinNum)         //C���Ա���Ҫ���Σ�JAVA���ã���ֱ�ӷ��ʱ�����ֵ
{
	pinMode(pinNum,OUTPUT);					//��������Ϊ���ģʽ
	digitalWrite(pinNum,HIGH);				//�����øߵ�ƽ���Ͽ��̵���
}
 
int swimpoolLightOpen(int pinNum)
{
	digitalWrite(pinNum,LOW);				//�����õ͵�ƽ���պϼ̵���
}
 
int swimpoolLightClose(int pinNum)
{
	digitalWrite(pinNum,HIGH);				//�����øߵ�ƽ���Ͽ��̵���
}
 
int swimpoolLightStatus(int status)
{
	
}
 
struct Devices swimpoolLight = {			//��������ƣ�����
	.deviceName = "swimpoolLight",		//����
	.pinNum = 9,							//����� 16��(wPi)����
	.Init = swimpoolLightInit,			//ָ����ʼ������
	.open = swimpoolLightOpen,			//ָ�����򿪵ơ�����
	.close = swimpoolLightClose,			//ָ�����رյơ�����
    .changeStatus = swimpoolLightStatus
};
 
struct Devices* addSwimpoolLightToDeviceLink(struct Devices *phead)		//�����ƣ����󣩼����豸������
{
	if(phead == NULL){
		return &swimpoolLight;
	}else{
		swimpoolLight.next = phead;  //��ǰ��ͷ���.next
		phead = &swimpoolLight;      //����ͷ
		return phead;
	}
}