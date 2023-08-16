#include "ControlDevice.h"			//自定义设备类的文件
 
int swimpoolLightInit(int pinNum)         //C语言必须要传参，JAVA不用，可直接访问变量的值
{
	pinMode(pinNum,OUTPUT);					//配置引脚为输出模式
	digitalWrite(pinNum,HIGH);				//引脚置高电平，断开继电器
}
 
int swimpoolLightOpen(int pinNum)
{
	digitalWrite(pinNum,LOW);				//引脚置低电平，闭合继电器
}
 
int swimpoolLightClose(int pinNum)
{
	digitalWrite(pinNum,HIGH);				//引脚置高电平，断开继电器
}
 
int swimpoolLightStatus(int status)
{
	
}
 
struct Devices swimpoolLight = {			//定义客厅灯（对象）
	.deviceName = "swimpoolLight",		//名字
	.pinNum = 9,							//香橙派 16号(wPi)引脚
	.Init = swimpoolLightInit,			//指定初始化函数
	.open = swimpoolLightOpen,			//指定“打开灯”函数
	.close = swimpoolLightClose,			//指定“关闭灯”函数
    .changeStatus = swimpoolLightStatus
};
 
struct Devices* addSwimpoolLightToDeviceLink(struct Devices *phead)		//客厅灯（对象）加入设备链表函数
{
	if(phead == NULL){
		return &swimpoolLight;
	}else{
		swimpoolLight.next = phead;  //以前的头变成.next
		phead = &swimpoolLight;      //更新头
		return phead;
	}
}