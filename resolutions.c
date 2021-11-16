//输入一个字符串，形如
//3072x1728,2720x1536,2560x1600,2560x1440,2304x1728,2048x1536,1920x1200,1920x1080,1440x900,1280x800,1280x720,1024x768,1024x640,800x600,800x500,800x450,640x480,640x400,640x360,480x360,480x300,480x270,320x240,320x200,320x180,240x180,176x144,160x120,160x100,160x90
//这是一个显示器支持的分辨率清单，中间逗号分隔。
//现在输入画面的宽和高，然后在上述清单中挑选一个最接近的分辨率输出
//比如输入2000，1000，输出的分辨率应该是1920x1080，因为其它分辨率的误差更大。
//完成如下程序
// 2021-11-14
#include <stdio.h>
#include <string.h>
#define RESNUM 200
int compare(int x, int y, int const res[][2],int time);
int main()
{

    char ress[2048];
    char *data=ress;
    
    int x, y,offset,time=0;
    
    
    scanf("%s", ress);
    scanf("%d %d", &x, &y);
    int res[RESNUM][2]={0},num=0;
	
    for(int i=0;sscanf(data,"%dx%d,%n",&res[i][0],&res[i][1],&offset)==2;i++){
        data+=offset;
        time++;
   }
    
    num=compare(x,y,res,time);

    // 学习一下 sscanf 可以方便处理 ress 字符串

    printf("选中的分辨率是%dx%d\n", res[num][0],res[num][1]);

    return 0;
}
int compare(int x,int y, int const res[][2],int time){
    int num=0;
    for(int i=0;i<RESNUM;i++){
        if((x-res[i][0])*(x-res[i][0])+(y-res[i][1])*(y-res[i][1]) <= (x-res[num][0])*(x-res[num][0])+(y-res[num][1])*(y-res[num][1])){
            num=i;
        }
    }
    return num;
}
