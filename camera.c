#include "ControlDevice.h"
#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
 
size_t readData(void *ptr, size_t size, size_t nmemb, void *stream)
{
        strncpy(ocrRetBuf,ptr,1024);
}
 
char* getBase64FromFile(char* filePath)
{
        char* base64Buf = NULL;
        char cmd[256] = {'\0'};
 
        sprintf(cmd,"base64 %s > tmpFile",filePath);     
        system(cmd);
 
        int fd = open("./tmpFile",O_RDWR);
        int fileLen = lseek(fd,0,SEEK_END);        
        lseek(fd,0,SEEK_SET);                      
 
        base64Buf = (char* )malloc(fileLen+8);
        memset(base64Buf,'\0',fileLen+8);
 
        read(fd,base64Buf,fileLen+8);              
        close(fd);
        system("rm -f tmpFile");
 
        return base64Buf;
}
 
char* getFace()
{
	printf("人脸数据采集中...\n");
	system("sudo fswebcam -d /dev/video0 --no-banner -r 1280x720 -S 5 ./image.jpg");
	
	while(access("./image.jpg",F_OK) != 0);
	
	printf("数据采集完毕\n");
	
	char* base64BufFaceRec = getBase64FromFile("./image.jpg");
	system("rm image.jpg");  
	return base64BufFaceRec;  
}
 
void postUrl()       
{
        CURL *curl;
        CURLcode res;
        
        
        char* base64BufPic1 = getFace();       
        char* base64BufPic2 = getBase64FromFile("./Person1.jpg");
        char* key    = "3hBe8BizfCNCHfrpwKYtUZ";
        char* secret = "3d272a6176ea4bf092b4dfe4d103ef4a";
        int   typeId = 21;
        char* format = "xml"; 
        
        int len = strlen(key)+strlen(secret)+strlen(base64BufPic1)+strlen(base64BufPic2)+128;
        char* postString = (char* )malloc(len);
        memset(postString,'\0',len);
	      sprintf(postString,"img1=%s&img2=%s&key=%s&secret=%s&typeId=%d&format=%s",base64BufPic1,base64BufPic2,key,secret,typeId,format);
 
        curl = curl_easy_init();
        if(curl){
                
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postString);
                curl_easy_setopt(curl, CURLOPT_URL, "https://netocr.com/api/faceliu.do");
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,readData); 
                res = curl_easy_perform(curl);
                printf("OK:%d\n",res);
                curl_easy_cleanup(curl);
        }
}

struct Devices camera = {
	.deviceName = "camera",
    .justDoOnce = postUrl
};
 
struct Devices* addCameraToDeviceLink(struct Devices* phead)
{
	if(phead == NULL){
		return &camera;
	}else{
		camera.next = phead; 
		phead = &camera;      
 	 return phead;
	}
}
