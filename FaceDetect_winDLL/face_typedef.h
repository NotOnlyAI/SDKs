#ifndef _FD_FACE_TYPEDEF_H_
#define _FD_FACE_TYPEDEF_H_


#include <stdint.h>
#include <vector>
#include <cmath>
#include <cfloat>
#define TFL_CAPI_EXPORT __attribute__((visibility("default")))

#define MAXFACECOUNT		200		//����ͼ�����֧�ּ��������
#define MAXLANDMARKNUM		5		//最大landmark�?
#define MAXPTS		        98		//最大landmark�?
using namespace std;

typedef struct _STRU_ImgData_T
{
	unsigned char* data;	//ͼ������
	int width;              //ͼ�����?
	int height;             //ͼ��߶�?
	int depth;              //λ��
	int channel;            //ͨ����
	_STRU_ImgData_T():data(nullptr),width(0),height(0),depth(0),channel(0){}
	_STRU_ImgData_T(unsigned char* indata,int inwidth,int inheight,int indepth,int inchannel)
		:data(indata),width(inwidth),height(inheight),depth(indepth),channel(inchannel){}
	_STRU_ImgData_T& operator =(const _STRU_ImgData_T&other)
	{
		data	= other.data;
		width	= other.width;
		height	= other.height;
		depth	= other.depth;
		channel = other.channel;
		return*this;
	}
	_STRU_ImgData_T(const _STRU_ImgData_T&other)
	{
		data = other.data;
		width = other.width;
		height = other.height;
		depth = other.depth;
		channel = other.channel;
	}
}STRU_ImgData_T,wsImg;

typedef struct _STRU_Rect_T
{
	int x;
	int y;
	int width;
	int height;
	_STRU_Rect_T():x(0),y(0),width(0),height(0){}
	_STRU_Rect_T(int inx,int iny,int inwidth,int inheight):x(inx),y(iny),width(inwidth),height(inheight){}
	_STRU_Rect_T& operator =(const _STRU_Rect_T&other)
	{
		x		= other.x;
		y		= other.y;
		width	= other.width;
		height	= other.height;
		return*this;
	}
	_STRU_Rect_T(const _STRU_Rect_T&other)
	{
		x = other.x;
		y = other.y;
		width = other.width;
		height = other.height;
	}
}STRU_Rect_T,wsRect;

typedef struct _STRU_Label_T
{
	int label;//��ǩ 0-������1-������2-���ԣ�3-�ǻ���
	float score;//�÷�

	_STRU_Label_T() :label(0), score(0.0) {}
	_STRU_Label_T(int inlabel, float inscore):label(inlabel),score(inscore){}
	_STRU_Label_T& operator =(const _STRU_Label_T&other)
	{
		label = other.label;
		score = other.score;
		return*this;
	}
	_STRU_Label_T(const _STRU_Label_T&other)
	{
		label = other.label;
		score = other.score;
	}
}STRU_Label_T, wsLabel;

typedef struct _STRU_RectInfo_T
{
	int nFaceNum;//????????
	wsRect rects[MAXFACECOUNT];//?????????????
	wsLabel labels[MAXFACECOUNT];//???????????
	_STRU_RectInfo_T() :nFaceNum(0){}
	_STRU_RectInfo_T& operator =(const _STRU_RectInfo_T&other)
	{
		nFaceNum = other.nFaceNum;
		for (int i = 0;i < nFaceNum;i++)
		{
			rects[i] = other.rects[i];
			labels[i] = other.labels[i];
		}
		return*this;
	}
	_STRU_RectInfo_T(const _STRU_RectInfo_T&other)
	{
		nFaceNum = other.nFaceNum;
		for (int i = 0;i < nFaceNum;i++)
		{
			rects[i] = other.rects[i];
			labels[i] = other.labels[i];
		}
	}
	_STRU_RectInfo_T GetFrontFace()//?????????????????????????????
	{
		_STRU_RectInfo_T temp;
		for (int i = 0;i < nFaceNum;i++)
		{
			if (labels[i].label == 0)
			{
				temp.rects[temp.nFaceNum] = rects[i];
				temp.labels[temp.nFaceNum] = labels[i];
				temp.nFaceNum++;
			}
		}
		return temp;
	}
	_STRU_RectInfo_T GetBestFace(int w, int h)//????
	{
		_STRU_RectInfo_T temp;
		for (int i = 0;i < nFaceNum;i++)
		{
			if (rects[i].width >= w &&rects[i].height >= h)
			{
				temp.rects[temp.nFaceNum] = rects[i];
				temp.labels[temp.nFaceNum] = labels[i];
				temp.nFaceNum++;
			}
		}
		return temp;
	}
	_STRU_RectInfo_T GetMaxFace()//??????????????
	{
		_STRU_RectInfo_T temp;
		int maxarea = 0;
		for (int i = 0;i < nFaceNum;i++)
		{
			int currarea = rects[i].width*rects[i].height;
			if (maxarea < currarea)
			{
				maxarea = currarea;
				temp.nFaceNum = 1;
				temp.rects[0] = rects[i];
				temp.labels[0] = labels[i];
			}
		}
		return temp;
	}
	_STRU_RectInfo_T GetMidFace(int img_w, int img_h)//??????��?????????
	{
		_STRU_RectInfo_T temp;
		int midcoordinate_x = img_w / 2;
		int midcoordinate_y = img_h / 2;
		int mindis = img_w*img_h;
		for (int i = 0;i < nFaceNum;i++)
		{
			int currx = rects[i].x + rects[i].width / 2;
			int curry = rects[i].y + rects[i].height / 2;
			int disx = midcoordinate_x - currx;
			int disy = midcoordinate_y - curry;
			int currdis = disx*disx + disy*disy;
			if (currdis < mindis)
			{
				mindis = currdis;
				temp.nFaceNum = 1;
				temp.rects[0] = rects[i];
				temp.labels[0] = labels[i];
			}
		}
		return temp;
	}
}STRU_RectInfo_T, wsRectInfo;


typedef struct _STRU_Point_T
{
	int x;//坐标X
	int y;//坐标Y

	_STRU_Point_T():x(0),y(0){}
	_STRU_Point_T(int inx, int iny):x(inx), y(iny){}
	_STRU_Point_T& operator =(const _STRU_Point_T&other)
	{
		x = other.x;
		y = other.y;
		return*this;
	}
	_STRU_Point_T(const _STRU_Point_T&other)
	{
		x = other.x;
		y = other.y;
	}
}STRU_Point_T,wsPoint;


typedef struct _STRU_Landmark_T
{
	float score;
	_STRU_Point_T point[MAXLANDMARKNUM];
	_STRU_Landmark_T() :score(0.0) {}
	_STRU_Landmark_T& operator =(const _STRU_Landmark_T&other)
	{
		score = other.score;
		for (int i = 0;i < MAXLANDMARKNUM;i++)
			point[i] = other.point[i];
		return*this;
	}
	_STRU_Landmark_T(const _STRU_Landmark_T&other)
	{
		score = other.score;
		for (int i = 0;i < MAXLANDMARKNUM;i++)
			point[i] = other.point[i];
	}
}STRU_Landmark_T, wsLandmark;


typedef struct _STRU_PTS_T
{
	float score;
	_STRU_Point_T point[MAXPTS];
	_STRU_PTS_T() :score(0.0) {}
	_STRU_PTS_T& operator =(const _STRU_PTS_T&other)
	{
		score = other.score;
		for (int i = 0;i < MAXPTS;i++)
			point[i] = other.point[i];
		return*this;
	}
	_STRU_PTS_T(const _STRU_PTS_T&other)
	{
		score = other.score;
		for (int i = 0;i < MAXPTS;i++)
			point[i] = other.point[i];
	}
}STRU_PTS_T, wsPTS;


typedef struct _STRU_PTSInfo_T
{
	int nFaceNum;//人脸个数
	wsPTS PTS[MAXPTS];//每张人脸的PTS信息

	_STRU_PTSInfo_T() :nFaceNum(-1) {}
	_STRU_PTSInfo_T& operator =(const _STRU_PTSInfo_T&other)
	{
		nFaceNum = other.nFaceNum;
		for (int i = 0;i < nFaceNum;i++)
			PTS[i] = other.PTS[i];
		return*this;
	}
	_STRU_PTSInfo_T(const _STRU_PTSInfo_T&other)
	{
		nFaceNum = other.nFaceNum;
		for (int i = 0;i < nFaceNum;i++)
			PTS[i] = other.PTS[i];
	}
}STRU_PTSInfo_T, wsPTSInfo;

typedef struct _STRU_LandmarkInfo_T
{
	int nFaceNum;//人脸个数
	wsLandmark landmark[MAXFACECOUNT];//每张人脸的landmark信息

	_STRU_LandmarkInfo_T() :nFaceNum(-1) {}
	_STRU_LandmarkInfo_T& operator =(const _STRU_LandmarkInfo_T&other)
	{
		nFaceNum = other.nFaceNum;
		for (int i = 0;i < nFaceNum;i++)
			landmark[i] = other.landmark[i];
		return*this;
	}
	_STRU_LandmarkInfo_T(const _STRU_LandmarkInfo_T&other)
	{
		nFaceNum = other.nFaceNum;
		for (int i = 0;i < nFaceNum;i++)
			landmark[i] = other.landmark[i];
	}
}STRU_LandmarkInfo_T, wsLandmarkInfo;

typedef struct _STRU_FaceQualityResults_T
{
    float border_size;
    float face_size;
    float pose_roll;
    float pose_yaw;
    float pose_pitch;
    float lightness;
    float clarity;
}STRU_FaceQualityResults_T;

typedef struct _STRU_FaceQualityFlagInfo_T
{
	int qualityinfo;   //质量总判断结果  0=LOW；1=MEDIUM ；2=HIGH

	//判断结果详细信息
    int lightnessinfo; //0=LOW；1=MEDIUM ；2=HIGH
    int facesizeinfo;  //0=LOW；1=MEDIUM ；2=HIGH
    int poseinfo;      //0=LOW；1=MEDIUM ；2=HIGH
    int clarityinfo;	//0=LOW；1=MEDIUM ；2=HIGH
    int positioninfo;  //0=LOW；1=MEDIUM ；2=HIGH

}STRU_FaceQualityFlagInfo_T;


typedef struct _STRU_PointF_T
{
	double x;//坐标X
	double y;//坐标Y

	_STRU_PointF_T():x(0),y(0){}
	_STRU_PointF_T(double inx, double iny):x(inx), y(iny){}
	_STRU_PointF_T& operator =(const _STRU_PointF_T&other)
	{
		x = other.x;
		y = other.y;
		return*this;
	}
	_STRU_PointF_T operator+(const _STRU_PointF_T&lhs)
	{
		_STRU_PointF_T result;
		result.x = lhs.x + x;
		result.y = lhs.y + y;
		return result;
 	}
	_STRU_PointF_T operator-(const _STRU_PointF_T&rhs)
	{
		_STRU_PointF_T result;
		result.x = x - rhs.x;
		result.y = y - rhs.y;
		return result;
	}
	_STRU_PointF_T operator*( double rhs)
	{
		_STRU_PointF_T result;
		result.x = x * rhs;
		result.y = y * rhs;
    	return result;
	}
	_STRU_PointF_T operator/(double rhs)
	{
		_STRU_PointF_T result;
		result.x = x / rhs;
		result.y = y / rhs;
		return result;
	}

	double operator^(const _STRU_PointF_T&rhs)
	{
    	double dx = x - rhs.x;
    	double dy = y - rhs.y;
    	return std::sqrt(dx * dx + dy * dy);
	}

	_STRU_PointF_T(const _STRU_PointF_T&other)
	{
		x = other.x;
		y = other.y;
	}
}STRU_PointF_T;


class Line {
public:
    Line() = default;
    Line(double a, double b, double c)
            : a(a), b(b), c(c) {}

    Line(const _STRU_PointF_T &a, const _STRU_PointF_T &b)
	 {
        double x1 = a.x;
        double y1 = a.y;
        double x2 = b.x;
       	double y2 = b.y;
        // for (y2-y1)x-(x2-x1)y-x1(y2-y1)+y1(x2-x1)=0
        this->a = y2 - y1;
        this->b = x1 - x2;
        this->c = y1 * (x2 - x1) - x1 * (y2 - y1);
    }

    double distance(const _STRU_PointF_T &p) const
	{
        return std::fabs(a * p.x + b * p.y + c) / std::sqrt(a * a + b * b);
    }

    double fdistance(const _STRU_PointF_T &p) const
	{
        return (a * p.x + b * p.y + c) / std::sqrt(a * a + b * b);
    }

    static bool near_zero(double f) {
        return f <= DBL_EPSILON && -f <= DBL_EPSILON;
    }

    _STRU_PointF_T projection(const _STRU_PointF_T &p) const {
        if (near_zero(a)) {
            _STRU_PointF_T result;
            result.x = p.x;
            result.y = -c / b;
            return  result;
        }
        if (near_zero(b)) {
            _STRU_PointF_T result;
            result.x = -c / a;
            result.y = p.y;
            return result;
        }
        // y = kx + b  <==>  ax + by + c = 0
        auto k = -a / b;
        _STRU_PointF_T o(0, -c / b);
        _STRU_PointF_T project(0, 0);
        project.x = (float) ((p.x / k + p.y - o.y) / (1 / k + k));
        project.y = (float) (-1 / k * (project.x - p.x) + p.y);
        return project;
    }

    double a = 0;
    double b = 0;
    double c = 0;
};

#endif





