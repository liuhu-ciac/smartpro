#include "ControlDevice.h"			//�Զ����豸����ļ�
 
int bathroomLightInit(int pinNum)           //C���Ա���Ҫ���Σ�JAVA���ã���ֱ�ӷ��ʱ�����ֵ
{
	pinMode(pinNum,OUTPUT);					//��������Ϊ���ģʽ
	digitalWrite(pinNum,HIGH);				//�����øߵ�ƽ���Ͽ��̵���
}
 
int bathroomLightOpen(int pinNum)
{
	digitalWrite(pinNum,LOW);				//�����õ͵�ƽ���պϼ̵���
}
 
int bathroomLightClose(int pinNum)
{
	digitalWrite(pinNum,HIGH);				//�����øߵ�ƽ���Ͽ��̵���
}
 
int bathroomLightStatus(int status)
{
	
}
 
struct Devices bathroomLight = {			//����ԡ�ҵƣ�����
	.deviceName = "bathroomLight",			//����
	.pinNum = 2,							//����� 2��(wPi)����
	.Init = bathroomLightInit,				//ָ����ʼ������
	.open = bathroomLightOpen,				//ָ�����򿪵ơ�����
	.close = bathroomLightClose,			//ָ�����رյơ�����
    .changeStatus = bathroomLightStatus
};
 
struct Devices* addBathroomLightToDeviceLink(struct Devices *phead)		//ԡ�ҵƣ����󣩼����豸������
{
	if(phead == NULL){
		return &bathroomLight;
	}else{
		bathroomLight.next = phead;  //��ǰ��ͷ���.next
		phead = &bathroomLight;      //����ͷ
		return phead;
	}
}