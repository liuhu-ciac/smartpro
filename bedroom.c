#include "ControlDevice.h"
 
int bedroomLightInit(int pinNum)            //C���Ա���Ҫ���Σ�JAVA���ã���ֱ�ӷ��ʱ�����ֵ
{
	pinMode(pinNum,OUTPUT);					//��������Ϊ���ģʽ
	digitalWrite(pinNum,HIGH);				//�����øߵ�ƽ���Ͽ��̵���
}
 
int bedroomLightOpen(int pinNum)
{
	digitalWrite(pinNum,LOW);				//�����õ͵�ƽ���պϼ̵���
}
 
int bedroomLightClose(int pinNum)
{
	digitalWrite(pinNum,HIGH);				//�����øߵ�ƽ���Ͽ��̵���
}
 
int bedroomLightStatus(int status)
{
	
}
 
struct Devices bedroomLight = {			//�������ҵƣ�����
	.deviceName = "bedroomLight",		//����
	.pinNum = 7,						//����� 8��(wPi)����
	.Init = bedroomLightInit,			//ָ����ʼ������
	.open = bedroomLightOpen,			//ָ�����򿪵ơ�����
	.close = bedroomLightClose,			//ָ�����رյơ�����
    .changeStatus = bedroomLightStatus
};
 
struct Devices* addBedroomLightToDeviceLink(struct Devices *phead)		//���ҵƣ����󣩼����豸������
{
	if(phead == NULL){
		return &bedroomLight;
	}else{
		bedroomLight.next = phead;  //��ǰ��ͷ���.next
		phead = &bedroomLight;      //����ͷ
		return phead;
	}
}