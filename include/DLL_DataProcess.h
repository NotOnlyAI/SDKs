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
	float* data;//��������
	int PointsCount;//�����
	float landmark[15];//���� xyz
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
	unsigned char* data;	//ͼ������
	int width;              //ͼ����
	int height;             //ͼ��߶�
	int depth;              //λ��
	int channel;            //ͨ����
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



#define D_SUCCESS			0		//�ɹ�
#define D_UNAUTHORIZED		-1		//δ��Ȩ
#define D_DATAERR			-2		//�������ݴ���
#define D_INDEXERR			-3		//����index����
#define D_POINTNULL			-4		//δ�ҵ����ʵĵ�
#define D_NOTENOUGHPOINT    -5		//��Ч��̫��

/*
˵����
���룺
pointCloud				��������
points					������꣬�ܳ���Ϊ10�� ����˳��Ϊ����(x,y)�����ۡ��Ǽ⡢����ǡ������
w						����ƶ�Ӧ�Ķ�άͼ����
h						����ƶ�Ӧ�Ķ�άͼ��߶�
maxradiu				���Ұ뾶,����Ӧ��ά����Ϊ0���������Χradiu�뾶�ڵĵ�.�����ð뾶��δ�ҵ����򷵻ش���
num						��������ֵ�ĵ��Ƹ���
�����
landmark				���ҵ��������㣬�ⲿ�����ڴ棬�ܳ���Ϊ15������Ϊ����(x,y,z)�����ۡ��Ǽ⡢����ǡ������
����ֵ��>=0��ʾ�ɹ� <0��ʾʧ��
*/
EXPORT int FindBestPoints(float*pointCloud, int *points, int w, int h, float*landmark, int maxradiu = 20, int num = 25);


/*
˵����
���룺	
    pc				�������� 
	dstimg			����õ����ͼ��(���ⲿ�����ڴ棬Ĭ��300x300)
�����
	��
����ֵ��=0��ʾ�ɹ� <0��ʾʧ��
*/
EXPORT int DataProcess_fullface(PointsCloud*pc, _STRU_ImgData_T&dstimg, char*savedir = NULL, const vector<vector<float>> &v = vector<vector<float>>());

/*
˵����
���룺
pc				��������
dstimg			����õ����ͼ��(���ⲿ�����ڴ棬Ĭ��300x300)
�����
��
����ֵ��=0��ʾ�ɹ� <0��ʾʧ��
*/
EXPORT int DataProcess_eye(PointsCloud*pc, _STRU_ImgData_T&dstimg, char*savedir = NULL, const vector<vector<float>> &v = vector<vector<float>>());

/*
˵����
���룺
pc				��������
bmpdata			��Ƕ�ͶӰͼ��(���ⲿ�����ڴ�,Ĭ��Ϊ(angle_end-angle_begin)/angle_step*(112*3*140*3+54))
angle_begin		��ת��ʼ�Ƕ�
angle_end		��ת��ֹ�Ƕ�
angle_step		��ת�ǶȲ���
�����
bmplen			�����ÿ��bmpͼƬ�ĳ���
piccount		�����ͼ������
����ֵ��=0��ʾ�ɹ� <0��ʾʧ��
*/
EXPORT int DataProcess(PointsCloud*pc,unsigned char*bmpdata,int&bmplen,int &piccount,float angle_begin=-30.0f,float angle_end=30.0f,float angle_step=3.f);

#endif /* DLL_DATAPROCESS_H_ */
