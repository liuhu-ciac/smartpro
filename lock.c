#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <signal.h>
#include <wiringPi.h>
#include "ControlDevice.h"

static int count = 0;
int angle;
int lockInit(int pinNum)         //C语言必须要传参，JAVA不用，可直接访问变量的值
{
	pinMode(pinNum,OUTPUT);					//配置引脚为输出模式
	digitalWrite(pinNum,HIGH);				//引脚置高电平，断开继电器
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
 
struct Devices lock = {			//定义客厅灯（对象）
	.deviceName = "lock",		//名字
	.pinNum = 10,							//香橙派 16号(wPi)引脚
	.Init = lockInit,			//指定初始化函数
	.open = lockOpen,			//指定“打开灯”函数
	.close = lockClose,			//指定“关闭灯”函数
  .changeStatus = lockStatus
};
 
struct Devices* addLockToDeviceLink(struct Devices *phead)		//客厅灯（对象）加入设备链表函数
{
	if(phead == NULL){
		return &lock;
	}else{
		lock.next = phead;  //以前的头变成.next
		phead = &lock;      //更新头
		return phead;
	}
}
