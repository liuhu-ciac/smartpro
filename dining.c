#include "ControlDevice.h"			//�Զ����豸����ļ�
 
int restaurantLightInit(int pinNum)         //C���Ա���Ҫ���Σ�JAVA���ã���ֱ�ӷ��ʱ�����ֵ
{
	pinMode(pinNum,OUTPUT);					//��������Ϊ���ģʽ
	digitalWrite(pinNum,HIGH);				//�����øߵ�ƽ���Ͽ��̵���
}
 
int restaurantLightOpen(int pinNum)
{
	digitalWrite(pinNum,LOW);				//�����õ͵�ƽ���պϼ̵���
}
 
int restaurantLightClose(int pinNum)
{
	digitalWrite(pinNum,HIGH);				//�����øߵ�ƽ���Ͽ��̵���
}
 
int restaurantLightStatus(int status)
{
	
}
 
struct Devices restaurantLight = {			//��������ƣ�����
	.deviceName = "restaurantLight",		//����
	.pinNum = 5,							//����� 13��(wPi)����
	.Init = restaurantLightInit,			//ָ����ʼ������
	.open = restaurantLightOpen,			//ָ�����򿪵ơ�����
	.close = restaurantLightClose,			//ָ�����رյơ�����
    .changeStatus = restaurantLightStatus
};
 
struct Devices* addRestaurantLightToDeviceLink(struct Devices *phead)		//�����ƣ����󣩼����豸������
{
	if(phead == NULL){
		return &restaurantLight;
	}else{
		restaurantLight.next = phead;  //��ǰ��ͷ���.next
		phead = &restaurantLight;      //����ͷ
		return phead;
	}
}