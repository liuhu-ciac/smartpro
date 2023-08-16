#include "ControlDevice.h"			        //�Զ����豸����ļ�
 
int smokeAlarmInit(int pinNum)              //C���Ա���Ҫ���Σ�JAVA���ã���ֱ�ӷ��ʱ�����ֵ
{
	pinMode(pinNum,INPUT);				    //��������Ϊ����ģʽ
	//digitalWrite(pinNum,HIGH);			//�����øߵ�ƽ���Ͽ��̵���
}
 
int smokeAlarmReadStatus(int pinNum)
{
	return digitalRead(pinNum);
}
 
int smokeAlarmStatus(int status)
{
 
}
 
struct Devices smokeAlarm = {			//������������������
	.deviceName = "smokeAlarm",			//����
	.pinNum = 6,						//����� 6��(wPi)����
	.Init = smokeAlarmInit,				//ָ����ʼ������
    .readStatus = smokeAlarmReadStatus,
    .changeStatus = smokeAlarmStatus
};
 
struct Devices* addSmokeAlarmToDeviceLink(struct Devices *phead)		//�������������󣩼����豸������
{
	if(phead == NULL){
		return &smokeAlarm;
	}else{
		smokeAlarm.next = phead;  //��ǰ��ͷ���.next
		phead = &smokeAlarm;      //����ͷ
		return phead;
	}
}