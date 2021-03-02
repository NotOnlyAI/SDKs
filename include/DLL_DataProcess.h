#ifndef DLL_DATAPROCESS_H_
#define DLL_DATAPROCESS_H_

#include <string.h>
#include <vector>
#ifndef EXPORT
#ifdef _MSC_VER
#define EXPORT  __declspec(dllexport)
#else
#define EXPORT
#endif
#endif/*EXPORT*/

#ifndef _MAX_FNAME
#define _MAX_FNAME 256
#endif

#ifdef _MSC_VER
#ifndef _USRDLL
#ifdef _DEBUG
#pragma  comment(lib, "DataProcess.lib")
#else
#pragma  comment(lib, "DataProcess.lib")
#endif
#endif
#endif
using namespace std;
#ifndef FLOATZERO
#define FLOATZERO
#define FloatMinErrorValue    0.000001f // 1e-6
#define IsZero_All(x,y,z)    ((fabsf(x) < FloatMinErrorValue && fabsf(y) < FloatMinErrorValue && fabsf(z) < FloatMinErrorValue) ? TRUE : FALSE)
#define IsZeroExist(x,y,z)   ((fabsf(x) < FloatMinErrorValue || fabsf(y) < FloatMinErrorValue || fabsf(z) < FloatMinErrorValue) ? TRUE : FALSE)
#endif

struct PointsCloud
{
	float* data;//点云数据
	int PointsCount;//点个数
	float landmark[15];//五点的 xyz
	PointsCloud():data(0), PointsCount(0)
	{
		memset(landmark, 0, 15*sizeof(float));
	}
	PointsCloud(float* data_, int* landmark_)
	{
		data = data_;
		memcpy(landmark, landmark_, 15 * sizeof(float));
	}
	PointsCloud& operator =(const PointsCloud&other)
	{
		data = other.data;
		memcpy(landmark, other.landmark, 15 * sizeof(float));
		return *this;
	}
};

typedef struct _STRU_ImgData_T
{
	unsigned char* data;	//图像数据
	int width;              //图像宽度
	int height;             //图像高度
	int depth;              //位深
	int channel;            //通道数
	_STRU_ImgData_T():data(NULL),width(0),height(0),depth(0),channel(0){}
	_STRU_ImgData_T(unsigned char* indata,int inwidth,int inheight,int indepth,int inchannel)
	{
		data	= indata;
		width	= inwidth;
		height	= inheight;
		depth	= indepth;
		channel = inchannel;
	}
	_STRU_ImgData_T& operator =(const _STRU_ImgData_T&other)
	{
		data	= other.data;
		width	= other.width;
		height	= other.height;
		depth	= other.depth;
		channel = other.channel;
		return *this;
	}
}STRU_ImgData_T,zsImg,wsImg;


#ifndef RELEASE_POINT
#define RELEASE_POINT
#define RELEASEPOINT(p) if(p!=NULL){delete p;p = NULL;}
#define RELEASEPOINTEX(p) if(p!=NULL){delete []p;p = NULL;}
#endif



#define D_SUCCESS			0		//成功
#define D_UNAUTHORIZED		-1		//未授权
#define D_DATAERR			-2		//传入数据错误
#define D_INDEXERR			-3		//计算index错误
#define D_POINTNULL			-4		//未找到合适的点
#define D_NOTENOUGHPOINT    -5		//有效点太少

/*
说明：
输入：
pointCloud				点云数据
points					五点坐标，总长度为10， 排列顺序为左眼(x,y)、右眼、鼻尖、左嘴角、右嘴角
w						与点云对应的二维图像宽度
h						与点云对应的二维图像高度
maxradiu				查找半径,若对应三维点云为0，则查找周围radiu半径内的点.超出该半径仍未找到，则返回错误
num						用来求中值的点云个数
输出：
landmark				查找到的最佳五点，外部分配内存，总长度为15，排列为左眼(x,y,z)、右眼、鼻尖、左嘴角、右嘴角
返回值：>=0表示成功 <0表示失败
*/
EXPORT int FindBestPoints(float*pointCloud, int *points, int w, int h, float*landmark, int maxradiu = 20, int num = 25);


/*
说明：
输入：	
    pc				点云数据 
	dstimg			处理好的深度图像(需外部分配内存，默认300x300)
输出：
	无
返回值：=0表示成功 <0表示失败
*/
EXPORT int DataProcess_fullface(PointsCloud*pc, _STRU_ImgData_T&dstimg, char*savedir = NULL, const vector<vector<float>> &v = vector<vector<float>>());

/*
说明：
输入：
pc				点云数据
dstimg			处理好的深度图像(需外部分配内存，默认300x300)
输出：
无
返回值：=0表示成功 <0表示失败
*/
EXPORT int DataProcess_eye(PointsCloud*pc, _STRU_ImgData_T&dstimg, char*savedir = NULL, const vector<vector<float>> &v = vector<vector<float>>());

/*
说明：
输入：
pc				点云数据
bmpdata			多角度投影图像(需外部分配内存,默认为(angle_end-angle_begin)/angle_step*(112*3*140*3+54))
angle_begin		旋转起始角度
angle_end		旋转终止角度
angle_step		旋转角度步长
输出：
bmplen			输出的每张bmp图片的长度
piccount		输出的图像数量
返回值：=0表示成功 <0表示失败
*/
EXPORT int DataProcess(PointsCloud*pc,unsigned char*bmpdata,int&bmplen,int &piccount,float angle_begin=-30.0f,float angle_end=30.0f,float angle_step=3.f);

#endif /* DLL_DATAPROCESS_H_ */
