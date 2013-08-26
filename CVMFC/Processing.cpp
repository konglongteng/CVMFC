//  Processing.cpp
//    2010.8.23

#include "stdafx.h"

//---------------------------------------------------------

LPBITMAPINFO CtreateMapInfo(IplImage* workImg,int flag)
{                                           //  建立位图信息
    BITMAPINFOHEADER BIH={40,1,1,1,8,0,0,0,0,0,0};
	LPBITMAPINFO lpBmi;
	int      wid,hei,bits,colors,i;
  
 	wid =workImg->width;
	hei =workImg->height;
	bits=workImg->depth*workImg->nChannels;

	if (bits>8) colors=0;
	else colors=1<<bits;

	lpBmi=(LPBITMAPINFO) malloc(40+4*colors);
	BIH.biWidth   =wid;
	BIH.biHeight  =hei;
	BIH.biBitCount=(BYTE) bits;
  	memcpy(lpBmi,&BIH,40);                  //  复制位图信息头

	if (bits==8) {                          //  256 色位图
		if (flag==1) {                      //  设置灰阶调色板
			for (i=0;i<256;i++) {
				VgaColorTab[i].rgbRed=VgaColorTab[i].rgbGreen=
						VgaColorTab[i].rgbBlue=(BYTE) i;
			}
			memcpy(lpBmi->bmiColors,VgaColorTab,1024);
		}
		else if (flag==2) {                 //  设置默认调色板
			memcpy(lpBmi->bmiColors,VgaDefPal,1024);
		}
		else if (flag==3) {                 //  设置自定义调色板
			memcpy(lpBmi->bmiColors,VgaColorTab,1024);
		}
	}
	return(lpBmi);
}

int  imageType(IplImage* p) 
{
  	int	 i,j,k,bpl,n,pg[256];
	BYTE *buf;
  
	k=p->nChannels;
	if (k==1) {                             //  检查二值图像
        for (i=0;i<256;i++) pg[i]=0;
		buf=(BYTE*)p->imageData;
		bpl=p->widthStep;
        for (i=0;i<p->height;i++) {
			for (j=0;j<p->width;j++) pg[buf[j]]++;
			buf+=bpl;
		}
        for (i=0,n=0;i<256;i++) {
			if (pg[i]) n++;
		}
        if (n==2) k=-1;                     //  二值图像
    }
  	return(k);
}

int  imageClone(IplImage* pi,IplImage** ppo)  //  复制 IplImage 位图
{
	if (*ppo) {
		cvReleaseImage(ppo);                //  释放原来位图
	}
 	(*ppo) = cvCloneImage(pi);              //  复制新位图
	return(1);
}

int  imageReplace(IplImage* pi,IplImage** ppo)  //  位图替换
{
	if (*ppo) 
		cvReleaseImage(ppo);                //  释放原来位图
 	(*ppo) = pi;                            //  位图换名
	return(1);
}

//---------------------------------------------------------
//  VGA 256色默认调色板数据

RGBQUAD VgaDefPal[256] = {
    {0x00,0x00,0x00,0x00},{0xa8,0x00,0x00,0x00},{0x00,0xa8,0x00,0x00},{0xa8,0xa8,0x00,0x00},
    {0x00,0x00,0xa8,0x00},{0xa8,0x00,0xa8,0x00},{0x00,0x54,0xa8,0x00},{0xa8,0xa8,0xa8,0x00},
    {0x54,0x54,0x54,0x00},{0xfc,0x54,0x54,0x00},{0x54,0xfc,0x54,0x00},{0xfc,0xfc,0x54,0x00},
    {0x54,0x54,0xfc,0x00},{0xfc,0x54,0xfc,0x00},{0x54,0xfc,0xfc,0x00},{0xfc,0xfc,0xfc,0x00},
    {0x00,0x00,0x00,0x00},{0x14,0x14,0x14,0x00},{0x20,0x20,0x20,0x00},{0x2c,0x2c,0x2c,0x00},
    {0x38,0x38,0x38,0x00},{0x44,0x44,0x44,0x00},{0x50,0x50,0x50,0x00},{0x60,0x60,0x60,0x00},
    {0x70,0x70,0x70,0x00},{0x80,0x80,0x80,0x00},{0x90,0x90,0x90,0x00},{0xa0,0xa0,0xa0,0x00},
    {0xb4,0xb4,0xb4,0x00},{0xc8,0xc8,0xc8,0x00},{0xe0,0xe0,0xe0,0x00},{0xfc,0xfc,0xfc,0x00},
    {0xfc,0x00,0x00,0x00},{0xfc,0x00,0x40,0x00},{0xfc,0x00,0x7c,0x00},{0xfc,0x00,0xbc,0x00},
    {0xfc,0x00,0xfc,0x00},{0xbc,0x00,0xfc,0x00},{0x7c,0x00,0xfc,0x00},{0x40,0x00,0xfc,0x00},
    {0x00,0x00,0xfc,0x00},{0x00,0x40,0xfc,0x00},{0x00,0x7c,0xfc,0x00},{0x00,0xbc,0xfc,0x00},
    {0x00,0xfc,0xfc,0x00},{0x00,0xfc,0xbc,0x00},{0x00,0xfc,0x7c,0x00},{0x00,0xfc,0x40,0x00},
    {0x00,0xfc,0x00,0x00},{0x40,0xfc,0x00,0x00},{0x7c,0xfc,0x00,0x00},{0xbc,0xfc,0x00,0x00},
    {0xfc,0xfc,0x00,0x00},{0xfc,0xbc,0x00,0x00},{0xfc,0x7c,0x00,0x00},{0xfc,0x40,0x00,0x00},
    {0xfc,0x7c,0x7c,0x00},{0xfc,0x7c,0x9c,0x00},{0xfc,0x7c,0xbc,0x00},{0xfc,0x7c,0xdc,0x00},
    {0xfc,0x7c,0xfc,0x00},{0xdc,0x7c,0xfc,0x00},{0xbc,0x7c,0xfc,0x00},{0x9c,0x7c,0xfc,0x00},
    {0x7c,0x7c,0xfc,0x00},{0x7c,0x9c,0xfc,0x00},{0x7c,0xbc,0xfc,0x00},{0x7c,0xdc,0xfc,0x00},
    {0x7c,0xfc,0xfc,0x00},{0x7c,0xfc,0xdc,0x00},{0x7c,0xfc,0xbc,0x00},{0x7c,0xfc,0x9c,0x00},
    {0x7c,0xfc,0x7c,0x00},{0x9c,0xfc,0x7c,0x00},{0xbc,0xfc,0x7c,0x00},{0xdc,0xfc,0x7c,0x00},
    {0xfc,0xfc,0x7c,0x00},{0xfc,0xdc,0x7c,0x00},{0xfc,0xbc,0x7c,0x00},{0xfc,0x9c,0x7c,0x00},
    {0xfc,0xb4,0xb4,0x00},{0xfc,0xb4,0xc4,0x00},{0xfc,0xb4,0xd8,0x00},{0xfc,0xb4,0xe8,0x00},
    {0xfc,0xb4,0xfc,0x00},{0xe8,0xb4,0xfc,0x00},{0xd8,0xb4,0xfc,0x00},{0xc4,0xb4,0xfc,0x00},
    {0xb4,0xb4,0xfc,0x00},{0xb4,0xc4,0xfc,0x00},{0xb4,0xd8,0xfc,0x00},{0xb4,0xe8,0xfc,0x00},
    {0xb4,0xfc,0xfc,0x00},{0xb4,0xfc,0xe8,0x00},{0xb4,0xfc,0xd8,0x00},{0xb4,0xfc,0xc4,0x00},
    {0xb4,0xfc,0xb4,0x00},{0xc4,0xfc,0xb4,0x00},{0xd8,0xfc,0xb4,0x00},{0xe8,0xfc,0xb4,0x00},
    {0xfc,0xfc,0xb4,0x00},{0xfc,0xe8,0xb4,0x00},{0xfc,0xd8,0xb4,0x00},{0xfc,0xc4,0xb4,0x00},
    {0x70,0x00,0x00,0x00},{0x70,0x00,0x1c,0x00},{0x70,0x00,0x38,0x00},{0x70,0x00,0x54,0x00},
    {0x70,0x00,0x70,0x00},{0x54,0x00,0x70,0x00},{0x38,0x00,0x70,0x00},{0x1c,0x00,0x70,0x00},
    {0x00,0x00,0x70,0x00},{0x00,0x1c,0x70,0x00},{0x00,0x38,0x70,0x00},{0x00,0x54,0x70,0x00},
    {0x00,0x70,0x70,0x00},{0x00,0x70,0x54,0x00},{0x00,0x70,0x38,0x00},{0x00,0x70,0x1c,0x00},
    {0x00,0x70,0x00,0x00},{0x1c,0x70,0x00,0x00},{0x38,0x70,0x00,0x00},{0x54,0x70,0x00,0x00},
    {0x70,0x70,0x00,0x00},{0x70,0x54,0x00,0x00},{0x70,0x38,0x00,0x00},{0x70,0x1c,0x00,0x00},
    {0x70,0x38,0x38,0x00},{0x70,0x38,0x44,0x00},{0x70,0x38,0x54,0x00},{0x70,0x38,0x60,0x00},
    {0x70,0x38,0x70,0x00},{0x60,0x38,0x70,0x00},{0x54,0x38,0x70,0x00},{0x44,0x38,0x70,0x00},
    {0x38,0x38,0x70,0x00},{0x38,0x44,0x70,0x00},{0x38,0x54,0x70,0x00},{0x38,0x60,0x70,0x00},
    {0x38,0x70,0x70,0x00},{0x38,0x70,0x60,0x00},{0x38,0x70,0x54,0x00},{0x38,0x70,0x44,0x00},
    {0x38,0x70,0x38,0x00},{0x44,0x70,0x38,0x00},{0x54,0x70,0x38,0x00},{0x60,0x70,0x38,0x00},
    {0x70,0x70,0x38,0x00},{0x70,0x60,0x38,0x00},{0x70,0x54,0x38,0x00},{0x70,0x44,0x38,0x00},
    {0x70,0x50,0x50,0x00},{0x70,0x50,0x58,0x00},{0x70,0x50,0x60,0x00},{0x70,0x50,0x68,0x00},
    {0x70,0x50,0x70,0x00},{0x68,0x50,0x70,0x00},{0x60,0x50,0x70,0x00},{0x58,0x50,0x70,0x00},
    {0x50,0x50,0x70,0x00},{0x50,0x58,0x70,0x00},{0x50,0x60,0x70,0x00},{0x50,0x68,0x70,0x00},
    {0x50,0x70,0x70,0x00},{0x50,0x70,0x68,0x00},{0x50,0x70,0x60,0x00},{0x50,0x70,0x58,0x00},
    {0x50,0x70,0x50,0x00},{0x58,0x70,0x50,0x00},{0x60,0x70,0x50,0x00},{0x68,0x70,0x50,0x00},
    {0x70,0x70,0x50,0x00},{0x70,0x68,0x50,0x00},{0x70,0x60,0x50,0x00},{0x70,0x58,0x50,0x00},
    {0x40,0x00,0x00,0x00},{0x40,0x00,0x10,0x00},{0x40,0x00,0x20,0x00},{0x40,0x00,0x30,0x00},
    {0x40,0x00,0x40,0x00},{0x30,0x00,0x40,0x00},{0x20,0x00,0x40,0x00},{0x10,0x00,0x40,0x00},
    {0x00,0x00,0x40,0x00},{0x00,0x10,0x40,0x00},{0x00,0x20,0x40,0x00},{0x00,0x30,0x40,0x00},
    {0x00,0x40,0x40,0x00},{0x00,0x40,0x30,0x00},{0x00,0x40,0x20,0x00},{0x00,0x40,0x10,0x00},
    {0x00,0x40,0x00,0x00},{0x10,0x40,0x00,0x00},{0x20,0x40,0x00,0x00},{0x30,0x40,0x00,0x00},
    {0x40,0x40,0x00,0x00},{0x40,0x30,0x00,0x00},{0x40,0x20,0x00,0x00},{0x40,0x10,0x00,0x00},
    {0x40,0x20,0x20,0x00},{0x40,0x20,0x28,0x00},{0x40,0x20,0x30,0x00},{0x40,0x20,0x38,0x00},
    {0x40,0x20,0x40,0x00},{0x38,0x20,0x40,0x00},{0x30,0x20,0x40,0x00},{0x28,0x20,0x40,0x00},
    {0x20,0x20,0x40,0x00},{0x20,0x28,0x40,0x00},{0x20,0x30,0x40,0x00},{0x20,0x38,0x40,0x00},
    {0x20,0x40,0x40,0x00},{0x20,0x40,0x38,0x00},{0x20,0x40,0x30,0x00},{0x20,0x40,0x28,0x00},
    {0x20,0x40,0x20,0x00},{0x28,0x40,0x20,0x00},{0x30,0x40,0x20,0x00},{0x38,0x40,0x20,0x00},
    {0x40,0x40,0x20,0x00},{0x40,0x38,0x20,0x00},{0x40,0x30,0x20,0x00},{0x40,0x28,0x20,0x00},
    {0x40,0x2c,0x2c,0x00},{0x40,0x2c,0x30,0x00},{0x40,0x2c,0x34,0x00},{0x40,0x2c,0x3c,0x00},
    {0x40,0x2c,0x40,0x00},{0x3c,0x2c,0x40,0x00},{0x34,0x2c,0x40,0x00},{0x30,0x2c,0x40,0x00},
    {0x2c,0x2c,0x40,0x00},{0x2c,0x30,0x40,0x00},{0x2c,0x34,0x40,0x00},{0x2c,0x3c,0x40,0x00},
    {0x2c,0x40,0x40,0x00},{0x2c,0x40,0x3c,0x00},{0x2c,0x40,0x34,0x00},{0x2c,0x40,0x30,0x00},
    {0x2c,0x40,0x2c,0x00},{0x30,0x40,0x2c,0x00},{0x34,0x40,0x2c,0x00},{0x3c,0x40,0x2c,0x00},
    {0x40,0x40,0x2c,0x00},{0x40,0x3c,0x2c,0x00},{0x40,0x34,0x2c,0x00},{0x40,0x30,0x2c,0x00},
    {0xa8,0xa8,0xa8,0x00},{0x54,0xfc,0xfc,0x00},{0xfc,0x54,0xfc,0x00},{0xfc,0xfc,0x54,0x00},
    {0xfc,0x54,0x54,0x00},{0x54,0xfc,0x54,0x00},{0x54,0x54,0xfc,0x00},{0xfc,0xfc,0xfc,0x00}  
};
RGBQUAD  VgaColorTab[256];
 
//---------------------------------------------------------
//  常规图像处理

void ImageDwindle(IplImage *pi,IplImage *po,int n,int nCnls)   
{                                           //  图像整数倍缩小
	int  i,j,k,bpl,bplt;
	char *buf,*buft;

	bpl=pi->widthStep;     bplt=po->widthStep;
	buf=pi->imageData;     buft=po->imageData;
	for (i=0;i<pi->height;i+=n) {
		for (j=0,k=0;j<pi->width*nCnls;k+=nCnls,j+=n*nCnls)
			memcpy(&buft[k],&buf[j],nCnls);   //  复制一个像素
		buf+=n*bpl;     buft+=bplt;
	}

}

int  NextColor(int start,int k,int step)    //  下一彩色号
{
	k++;                                    //  修改颜色号
	if (k==7) k+=2;                         //  跳过默认调色板7、8号颜色
	else if (k==15) k+=17;                  //  跳过默认调色板15~31号颜色
	if (k>32) k+=step-1;  
	if (k>247) k=start;                     //  超过默认调色板248号颜色，从头开始
	return(k);
}
  
void Histog(BYTE *buf,int *pg,int Dx,int Dy)
{                                          //  统计直方图                              
  int  i;
 
  for (i=0;i<256;i++)  pg[i]=0;
  for (i=0;i<Dx*Dy;i++) pg[buf[i]]++;
}

int  BasicGlobalThreshold(int *pg,int start,int end)
{                                           //  基本全局阈值法
   int  i,t,t1,t2,k1,k2;
   double u,u1,u2;
  
   t=0;     u=0;
   for (i=start;i<end;i++) {
      t+=pg[i];		
	  u+=i*pg[i];
   }
   k2=(int) (u/t);                          //  计算此范围灰度的平均值

   do {
      k1=k2;
      t1=0;     u1=0;
      for (i=start;i<=k1;i++) {             //  计算低灰度组的累加和
	     t1+=pg[i];	
		 u1+=i*pg[i];
      }
      t2=t-t1;
      u2=u-u1;
      if (t1) u1=u1/t1;                     //  计算低灰度组的平均值
      else u1=0;
      if (t2) u2=u2/t2;                     //  计算高灰度组的平均值
      else u2=0;
	  k2=(int) ((u1+u2)/2);                 //  得到新的阈值估计值
   }
   while(k1!=k2);                           //  数据未稳定，继续

   return(k1);                              //  返回阈值
}

void Thresholding(BYTE *buf,int Dx,int Dy,int thre,int m)
{                                           //  实现灰度变换
  BYTE **list;
  int  i,j,T_gray[256];
  
  list=(BYTE**) malloc(Dy*sizeof(BYTE*));   //  申请二维输入数组
  for(i=0;i<Dy;i++) list[i]=buf+i*Dx;

  for (i=0;i<thre;i++)   T_gray[i]=0;       //  低于阈值改黑色
  for (i=thre;i<256;i++) T_gray[i]=m;       //  高于、等于阈值改白色

  for (i=0;i<Dy;i++) {                                 
    for (j=0;j<Dx;j++) {
       list[i][j]=(BYTE) T_gray[list[i][j]];      
    }
  }

  free(list);  
}

void GrayColorTransfor(RGBQUAD *pal) 
{
	int     i,j;
  
	for (i=0,j=0;i<64;i++,j+=4) {           //  按变换曲线送各单元颜色分量
		pal[i].rgbRed  =0;
		pal[i].rgbGreen=(BYTE) j;
		pal[i].rgbBlue =255;
	}
	for (i=64,j=0;i<128;i++,j+=4) {         //  按变换曲线送各单元颜色分量
		pal[i].rgbRed  =0;
		pal[i].rgbGreen=255;
		pal[i].rgbBlue =(BYTE) (255-j);
	}
	for (i=128,j=0;i<192;i++,j+=4) {        //  按变换曲线送各单元颜色分量
		pal[i].rgbRed  =(BYTE) j;
		pal[i].rgbGreen=255;
		pal[i].rgbBlue =0;
	}
	for (i=192,j=0;i<256;i++,j+=4) {        //  按变换曲线送各单元颜色分量
		pal[i].rgbRed  =255;
		pal[i].rgbGreen=(BYTE) (255-j);
		pal[i].rgbBlue =0;
	}
}

 