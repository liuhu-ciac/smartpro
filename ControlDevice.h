#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>					//wiringPi��
 
 
extern char ocrRetBuf[1024];
 
struct Devices                          //�豸��
{
    char deviceName[128];               //�豸��
    int status;                         //״̬
    int pinNum;							//���ź�
 
    int (*Init)(int pinNum);			//����ʼ���豸������ָ��
	int (*open)(int pinNum);			//�����豸������ָ��
	int (*close)(int pinNum);			//���ر��豸������ָ��
    int (*readStatus)(int pinNum);		//����ȡ�豸״̬������ָ��  Ϊ���ֱ�����׼��
	int (*changeStatus)(int status);	//���ı��豸״̬������ָ��
    void (*justDoOnce)();
 
    struct Devices *next;
};

 
struct Devices* addBathroomLightToDeviceLink(struct Devices *phead);		//��ԡ�ҵơ������豸����������
struct Devices* addBedroomLightToDeviceLink(struct Devices *phead);	        //�����ҵơ������豸����������
struct Devices* addRestaurantLightToDeviceLink(struct Devices *phead);		//�������ơ������豸����������
struct Devices* addLivingroomLightToDeviceLink(struct Devices *phead);		//�������ơ������豸����������
struct Devices* addSmokeAlarmToDeviceLink(struct Devices *phead);           //�����������������豸����������
struct Devices* addBuzzerToDeviceLink(struct Devices *phead);		        //���������������豸����������
struct Devices* addSwimpoolLightToDeviceLink(struct Devices *phead);
struct Devices* addLockToDeviceLink(struct Devices *phead);
struct Devices* addCameraToDeviceLink(struct Devices *phead);