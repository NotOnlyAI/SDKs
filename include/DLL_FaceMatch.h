/*
 * DLL_FaceMatch.h
 *
 *  Created on: 2015年10月8日
 *      Author: zy
 */

#ifndef DLL_FACEMATCH_H_
#define DLL_FACEMATCH_H_

#include <string.h>

#ifndef EXPORT
#ifdef _MSC_VER
#define EXPORT __declspec(dllexport)
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
#pragma  comment(lib, "FaceMatchd.lib")
#else
#pragma  comment(lib, "FaceMatch.lib")
#endif
#endif
#endif

#define MAXFACECOUNT		200		//单张图像最大支持检测人脸数
#define RANKNUM				10		//返回识别排名前几位的信息
#define MAXIDLEN			100		//最大ID长度
#define MAXLANDMARKNUM		5		//最大landmark数
#define MAXFEALENGTH		2600	//最大特征长度
#define MAXVERLENGTH		30		//版本号信息长度
#define MAXDEVICESCOUNT     50      //支持最大设备数量
#define BATCHSIZE			10		//批处理最大支持的图像张数
#define RELEASEPOINT(p) if(p!=NULL){delete p;p = NULL;}
#define RELEASEPOINTEX(p) if(p!=NULL){delete []p;p = NULL;}
enum IMGDataType
{
	DT_GRAY = 0,//color or gray
	DT_DEPTH,   //depth
	DT_IR,		 //ir
	DT_EXT1,		
	DT_EXT2,
};


//ERRORINFO
#define  SUCCESS							0			//成功
#define  ERR_UNKNOWNERR						-1			//未知错误
#define  ERR_VERIFYFAILED					-2	        //验证license失败
#define  ERR_INITFAILED						-3  		//初始化失败
#define  ERR_IMGDATAERROR					-4	        //图像数据错误
#define  ERR_IMGTYPEERROE					-5			//数据类型与指定类型不一致
#define  ERR_NOFACE							-6			//未检测到人脸
#define  ERR_FACEDETECTFAILED				-7  		//人脸检测失败
#define  ERR_GETLANDMARKFAILED				-8	        //特征点检测失败
#define  ERR_NORMALIZEFAILED				-9			//归一化失败
#define  ERR_GETFEATUREFAILED				-10			//提取特征值失败
#define  ERR_SAVEFEATUREFAILED				-11			//保存特征值失败
#define  ERR_NOFEATURE4THISID				-12			//无该ID的注册数据
#define  ERR_DIMUNEQUAL						-13			//特征值维度不一致，不能匹配
#define  ERR_FEATUREISNULL					-14			//特征值为空
#define  ERR_RECOGNITIONFAILED				-15 		//人脸识别失败
#define  ERR_LOADFEATUREFAILED				-16         //加载特征库失败
#define  ERR_NOTHRESHOLD					-17         //未设置阈值
#define  ERR_FACEISNOTEXIST					-18         //无该人脸注册信息  
#define  ERR_PERSONISNOTEXIST				-19         //无该人注册信息
#define  ERR_DELETEFILEFAILED				-20         //删除文件失败
#define  ERR_INTERFACEISWRONG				-21         //接口调用错误
#define  ERR_PARAMERROR						-22         //传入参数错误
#define  ERR_ISNOTFACE						-23         //不能提取特征点，该区域不是人脸
#define  ERR_FILEISNOTEXIST					-24         //文件不存在 
#define  ERR_GETVERSIONFAILED				-25         //获取DLL版本号失败 
#define  ERR_DIFFERRNTVERSION				-26	        //版本号不一致
#define  ERR_FEATUREVERTOOOLD				-27 		//特征库版本过旧
#define  ERR_TRAINMATVERTOOOLD				-28         //训练矩阵版本过旧
#define  ERR_FEATUREISTOOSHORT				-29         //特征长度不足，不能获取版本号
#define  ERR_INTERFACEDISABLE				-30	        //接口不可用
#define  ERR_GETPORTFAILD					-31			//获取通道号失败
#define  ERR_PORTERROR						-32 		//端口号错误
#define  ERR_IDERROR						-33         //注册ID号非法
#define  ERR_IDISTOOLONG					-34	        //注册ID太长，最大长度为100
#define  ERR_JPGDATAERROR					-35			//JPG数据为空或长度为0
#define  ERR_JPGDECODEFAILED				-36			//JPG解码失败
#define  ERR_DATAERROR						-37			//JPG数据为空或长度为0
#define  ERR_EXTERROR						-38 		//编码格式错误
#define  ERR_BUFFOUTOFMEMORY				-39	        //外部分配的内存不足
#define  ERR_ENCODESCALEERROR				-40			//编码压缩比例错误
#define  ERR_FEATURELENGTHUNEQUAL			-41			//输入的特征长度不一致
#define  ERR_GETFEATUREWHFAILED				-42			//获取特征长度信息失败
#define  ERR_INPUTFEATURELENGTHERROR		-43			//输入的特征长度错误
#define  ERR_THEPORTNOTEXIST				-44 		//该端口不存在
#define  ERR_DIFFERRNTFEATURETYPE			-45         //特征类型不一致
#define  ERR_FEATUREERROR					-46         //特征值错误
#define  ERR_WRITEFEAFILEFAILED				-47	        //保存特征文件错误
#define  ERR_FACEDETECTINITFAILED			-48			//人脸检测初始化失败
#define  ERR_CONFIGFILENOTEXIST				-49			//配置文件不存在	
#define  ERR_GETISFACEFEAFAILED				-50			//提取特征值失败
#define  ERR_GETFACEDETECTFEAFAILED			-51			//提取人脸框特征值失败
#define  ERR_GETFACEATTRFAILED				-52			//提取人脸属性失败
#define  ERR_GETFACEQUALITYFAILED			-53			//提取人脸质量失败
#define  ERR_GETFACELANDMARKFAILED			-54			//提取人脸特征点失败
#define  ERR_THISVERSIONNOTSUPPORT			-55			//该版本不支持此接口	
#define  ERR_INPUTERROR						-56			//输入错误	
#define  ERR_CUTMODELERROR					-57			//裁剪失败
#define	 ERR_CONFIGISCPU					-58			//配置为不使用GPU,不能获取/设置 设备信息
#define	 ERR_GETINSFAILED   				-59			//获取实例失败
#define  ERR_DEVICEIDERROR					-60			//设备ID错误
#define  ERR_DEVICEFORDIFFPORT				-61			//不同端口使用了同一块GPU，一块GPU只能由一个端口使用(CPU、单显卡、多显卡模式下第一张显卡不受此影响）
#define  ERR_BATCHSIZEERR					-62			//batchsize 错误，取值范围1-BATCHSIZE
#define  ERR_IMAGECROPFAILED				-63			//图像裁剪错误
#define  ERR_RECTTOOSMALL					-64			//人脸区域太小

#define  ERR_UNAUTHORIZED					-101		//未授权
#define  ERR_EXPIRY							-102		//授权逾期
#define  ERR_INVALIDTIME					-103		//非法修改系统日期
#define  ERR_PERMISSIONDENIED				-104		//权限不足



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

typedef struct _STRU_Pose_T
{
	int roll;	  //平面旋转角度z
	int pitch;	  //俯仰角度//绕X
	int yaw;      //左右偏转角度y
	_STRU_Pose_T():pitch(0),roll(0),yaw(0){}
	_STRU_Pose_T(int inroll,int inpitch,int inyaw):pitch(inpitch),roll(inroll),yaw(inyaw){}
	_STRU_Pose_T& operator =(const _STRU_Pose_T&other)
	{
		pitch = other.pitch;
		roll  = other.roll;
		yaw   = other.yaw;
		return*this;
	}
	_STRU_Pose_T(const _STRU_Pose_T&other)
	{
		pitch = other.pitch;
		roll = other.roll;
		yaw = other.yaw;
	}
}STRU_Pose_T,wsPose;

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
	int label;//标签 0-正脸，1-侧脸，2-后脑，3-非活体 
	float score;//得分

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

typedef struct _STRU_Track_T//配套跟踪
{
	int trackID;//跟踪ID
	int status;//人脸框状态  1-检测框 2-跟踪框
	_STRU_Track_T() :trackID(0), status(0) {}
	_STRU_Track_T(int intrackID, int instatus):trackID(intrackID),status(instatus){}
	_STRU_Track_T& operator =(const _STRU_Track_T&other)
	{
		trackID = other.trackID;
		status = other.status;
		return*this;
	}
	_STRU_Track_T(const _STRU_Track_T&other)
	{
		trackID = other.trackID;
		status = other.status;
	}
}STRU_Track_T, wsTrack;

typedef struct _STRU_RectInfo_T
{
	int nFaceNum;//人脸个数
	wsRect rects[MAXFACECOUNT];//每张人脸的区域
	wsLabel labels[MAXFACECOUNT];//人脸的标签信息
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
	_STRU_RectInfo_T GetFrontFace()//只保留正脸区域，丢弃侧脸等标签数据
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
	_STRU_RectInfo_T GetBestFace(int w, int h)//保留
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
	_STRU_RectInfo_T GetMaxFace()//获取面积最大的人脸
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
	_STRU_RectInfo_T GetMidFace(int img_w, int img_h)//获取居中的人脸区域
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

typedef struct _STRU_TrackingInfo_T
{
	int nFaceNum;//人脸个数
	wsRect rects[MAXFACECOUNT];
	wsTrack tracks[MAXFACECOUNT];

	_STRU_TrackingInfo_T() :nFaceNum(0) {}
	_STRU_TrackingInfo_T& operator =(const _STRU_TrackingInfo_T&other)
	{
		nFaceNum = other.nFaceNum;
		for (int i = 0;i < nFaceNum;i++)
		{
			rects[i] = other.rects[i];
			tracks[i] = other.tracks[i];
		}
		return*this;
	}
	_STRU_TrackingInfo_T(const _STRU_TrackingInfo_T&other)
	{
		nFaceNum = other.nFaceNum;
		for (int i = 0;i < nFaceNum;i++)
		{
			rects[i] = other.rects[i];
			tracks[i] = other.tracks[i];
		}
	}
}STRU_TrackingInfo_T, wsTrackingInfo;

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

typedef struct _STRU_FaceQuality_T
{
	STRU_Landmark_T landmark;
	STRU_Rect_T rect;
	STRU_Pose_T pose;
	float confidence;//人脸置信度
	float clearness;//清晰度
	float unocclusion;//无遮挡
	float glasses;//戴眼镜
	float pokerface;//无夸张表情
	float illumination;//光照

	_STRU_FaceQuality_T() :confidence(0.0), clearness(0.0), unocclusion(0.0), glasses(0.0), pokerface(0.0) {}
	_STRU_FaceQuality_T& operator =(const _STRU_FaceQuality_T&other)
	{
		landmark = other.landmark;
		rect = other.rect;
		pose = other.pose;
		confidence = other.confidence;
		clearness = other.clearness;
		unocclusion = other.unocclusion;
		glasses = other.glasses;
		pokerface = other.pokerface;
		illumination = other.illumination;
		return*this;
	}
	_STRU_FaceQuality_T(const _STRU_FaceQuality_T&other)
	{
		landmark = other.landmark;
		rect = other.rect;
		pose = other.pose;
		confidence = other.confidence;
		clearness = other.clearness;
		unocclusion = other.unocclusion;
		glasses = other.glasses;
		pokerface = other.pokerface;
		illumination = other.illumination;
	}
	bool GetFaceQuality(float th_pitch = 15.0, float th_roll = 30.0,float th_yaw = 50.0,
		float th_confidence		= 0.5,
		float th_clearness		= 0.5,
		float th_unocclusion	= 0.5,
		float th_pokerface		= 0.5,
		float th_illumination	= 0.5)
	{
		return !(
			pose.pitch > th_pitch || pose.roll > th_roll || pose.yaw > th_yaw ||
			pose.pitch < -th_pitch || pose.roll < -th_roll || pose.yaw < -th_yaw||
			confidence < th_confidence || clearness < th_clearness || unocclusion < th_unocclusion || pokerface < th_pokerface || illumination<th_illumination);
	}

}STRU_FaceQuality_T, wsFaceQuality;

typedef struct _STRU_FaceQualityInfo_T
{
	int nFaceNum;//人脸个数
	wsFaceQuality facequality[MAXFACECOUNT];//每张人脸的quality信息

	_STRU_FaceQualityInfo_T() :nFaceNum(-1) {}
	_STRU_FaceQualityInfo_T& operator =(const _STRU_FaceQualityInfo_T&other)
	{
		nFaceNum = other.nFaceNum;
		for (int i = 0;i < nFaceNum;i++)
			facequality[i] = other.facequality[i];
		return*this;
	}
	_STRU_FaceQualityInfo_T(const _STRU_FaceQualityInfo_T&other)
	{
		nFaceNum = other.nFaceNum;
		for (int i = 0;i < nFaceNum;i++)
			facequality[i] = other.facequality[i];
	}
}STRU_FaceQualityInfo_T, wsFaceQualityInfo;

typedef struct _STRU_RealFaceInfo_T
{
	int nFaceNum;
	float score[MAXFACECOUNT];
	_STRU_RealFaceInfo_T():nFaceNum(0){ memset(score, 0, sizeof(float)*MAXFACECOUNT); }
	_STRU_RealFaceInfo_T& operator =(const _STRU_RealFaceInfo_T&other)
	{
		nFaceNum = other.nFaceNum;
		for (int i = 0;i < nFaceNum;i++)
			score[i] = other.score[i];
		return*this;
	}
	_STRU_RealFaceInfo_T(const _STRU_RealFaceInfo_T&other)
	{
		nFaceNum = other.nFaceNum;
		for (int i = 0;i < nFaceNum;i++)
			score[i] = other.score[i];
	}
}STRU_RealFaceInfo_T, wsRealFaceInfo;

typedef struct _STRU_Attr_T
{
	wsPose pose;
	int occlusion;//0 无遮挡  1遮挡
	int glasses;//0无眼镜 1戴眼镜
	int age;//年龄 
	int gender;//性别 0-男 1-女
	int ethnicity;//种族 0-白人 1-黑人 2-亚洲人 3-印第安 4-其他
	int emotion;//表情 0-surprise 1-fear 2-disgust 3-happiness 4-sadness 5-anger 6-neutral
	_STRU_Attr_T() :occlusion(-1),glasses(-1),age(-1),gender(-1),ethnicity(-1), emotion(-1){}
	_STRU_Attr_T(wsPose inpose, int inocclusion, int inglasses, int inage, int ingender, int inethnicity, int inemotion)
		:pose(inpose), occlusion(inocclusion), glasses(inglasses), age(inage), gender(ingender), ethnicity(inethnicity), emotion(inemotion) {}
	_STRU_Attr_T& operator =(const _STRU_Attr_T&other)
	{
		pose		= other.pose;
		occlusion	= other.occlusion;
		glasses		= other.glasses;
		age			= other.age;
		gender		= other.gender;
		ethnicity	= other.ethnicity;
		emotion		= other.emotion;
		return*this;
	}
	_STRU_Attr_T(const _STRU_Attr_T&other)
	{
		pose = other.pose;
		occlusion = other.occlusion;
		glasses = other.glasses;
		age = other.age;
		gender = other.gender;
		ethnicity = other.ethnicity;
		emotion = other.emotion;
	}
}STRU_Attr_T, wsAttr;

typedef struct _STRU_AttrInfo_T
{
	int nFaceNum;//人脸个数
	wsAttr attrs[MAXFACECOUNT]; //每个人脸的属性信息

	_STRU_AttrInfo_T() :nFaceNum(-1) {}
	_STRU_AttrInfo_T& operator =(const _STRU_AttrInfo_T&other)
	{
		nFaceNum = other.nFaceNum;
		for (int i = 0;i < nFaceNum;i++)
			attrs[i] = other.attrs[i];
		return*this;
	}
	_STRU_AttrInfo_T(const _STRU_AttrInfo_T&other)
	{
		nFaceNum = other.nFaceNum;
		for (int i = 0;i < nFaceNum;i++)
			attrs[i] = other.attrs[i];
	}
}STRU_AttrInfo_T, wsAttrInfo;

typedef struct _STRU_ScoreInfo_T
{
	char  sPersonID[MAXIDLEN];	//工号
	float   fScore;             //比对分数
	_STRU_ScoreInfo_T():fScore(0.0)
	{
		memset(sPersonID,0,sizeof(char)*MAXIDLEN);
	}
	_STRU_ScoreInfo_T& operator =(const _STRU_ScoreInfo_T&other)
	{
		memcpy(sPersonID,other.sPersonID,sizeof(char)*MAXIDLEN);
		fScore = other.fScore;
		return*this;
	}
	_STRU_ScoreInfo_T(const _STRU_ScoreInfo_T&other)
	{
		memcpy(sPersonID, other.sPersonID, sizeof(char)*MAXIDLEN);
		fScore = other.fScore;
	}
}STRU_ScoreInfo_T,wsScoreInfo;

typedef struct _STRU_FeaInfo_T
{
	int		nFeaLen;//特征长度
	char	sFea[MAXFEALENGTH];	

	_STRU_FeaInfo_T() :nFeaLen(0)
	{
		memset(sFea, 0, sizeof(char)*MAXFEALENGTH);
	}
	_STRU_FeaInfo_T& operator =(const _STRU_FeaInfo_T&other)
	{
		nFeaLen = other.nFeaLen;
		memcpy(sFea, other.sFea, nFeaLen);
		return*this;
	}
	_STRU_FeaInfo_T(const _STRU_FeaInfo_T&other)
	{
		nFeaLen = other.nFeaLen;
		memcpy(sFea, other.sFea, nFeaLen);
	}
	_STRU_FeaInfo_T(const char* insFea , int innFeaLen)
	{
		nFeaLen = innFeaLen;
		memcpy(sFea, insFea, innFeaLen);
	}
}STRU_FeaInfo_T, wsFeaInfo;

typedef struct _STRU_VersionInfo_T
{
	int		nVerLen;//版本信息长度
	char	sVer[MAXVERLENGTH];	//版本信息长度

	_STRU_VersionInfo_T() :nVerLen(0)
	{
		memset(sVer, 0, sizeof(char)*MAXVERLENGTH);
	}
	_STRU_VersionInfo_T& operator =(const _STRU_VersionInfo_T&other)
	{
		memcpy(sVer, other.sVer, sizeof(char)*MAXVERLENGTH);
		nVerLen = other.nVerLen;
		return*this;
	}
	_STRU_VersionInfo_T(const _STRU_VersionInfo_T&other)
	{
		memcpy(sVer, other.sVer, sizeof(char)*MAXVERLENGTH);
		nVerLen = other.nVerLen;
	}
}STRU_VersionInfo_T, wsVerInfo;

typedef struct _STRU_RecognitionInfo_T
{
	STRU_Rect_T rect_;                  //人脸区域
	STRU_ScoreInfo_T ScoreInfo[RANKNUM];//返回排名前RANKNUM的识别信息
	int nValid;                    //返回信息中有效位数（即ScoreInfo数组中前nValid位为有效数据）
	_STRU_RecognitionInfo_T():nValid(0){}
	_STRU_RecognitionInfo_T& operator =(const _STRU_RecognitionInfo_T&other)
	{
		rect_ = other.rect_;
		for (int i = 0;i < RANKNUM;i++)
			ScoreInfo[i] = other.ScoreInfo[i];
		return*this;
	}
	_STRU_RecognitionInfo_T(const _STRU_RecognitionInfo_T&other)
	{
		rect_ = other.rect_;
		for (int i = 0;i < RANKNUM;i++)
			ScoreInfo[i] = other.ScoreInfo[i];
	}
}STRU_RecognitionInfo_T,wsInfo;

typedef struct _STRU_RecognitionResult_T
{
	STRU_RecognitionInfo_T RecognitionInfo[MAXFACECOUNT];
	int nValid;
	_STRU_RecognitionResult_T():nValid(0){}
	_STRU_RecognitionResult_T& operator =(const _STRU_RecognitionResult_T&other)
	{
		for (int i = 0;i < MAXFACECOUNT;i++)
			RecognitionInfo[i] = other.RecognitionInfo[i];
		nValid = other.nValid;
		return*this;
	}
	_STRU_RecognitionResult_T(const _STRU_RecognitionResult_T&other)
	{
		for (int i = 0;i < MAXFACECOUNT;i++)
			RecognitionInfo[i] = other.RecognitionInfo[i];
		nValid = other.nValid;
	}
}STRU_RecognitionResult_T,wsResult;

typedef struct _STRU_ImgData_T
{
	unsigned char* data;	//图像数据
	int width;              //图像宽度
	int height;             //图像高度
	int depth;              //位深
	int channel;            //通道数
	_STRU_ImgData_T():data(NULL),width(0),height(0),depth(0),channel(0){}
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

typedef struct _STRU_MultiTypeImg_T
{
	STRU_ImgData_T img[5];	    //0--彩色图像，1--深度图像  2--红外图像 其余预留
	STRU_Landmark_T landmark;	//特征点坐标(配套深度图像)
	STRU_FaceQuality_T quality;	    //人脸信息(配套彩色图像)

	_STRU_MultiTypeImg_T(){}
	_STRU_MultiTypeImg_T& operator =(const _STRU_MultiTypeImg_T&other)
	{
		for (int i = 0; i < 5; i++)
			img[i] = other.img[i];
		landmark = other.landmark;
		quality = other.quality;
		return*this;
	}
	_STRU_MultiTypeImg_T(const _STRU_MultiTypeImg_T&other)
	{
		for (int i = 0; i < 5; i++)
			img[i] = other.img[i];
		landmark = other.landmark;
		quality = other.quality;
	}
}STRU_MultiTypeImg_T,wsMulImg;

typedef struct _STRU_DeviceProp_T
{
	int		deviceid;//设备ID
	char	name[256];//设备名称
	long	totalGlobalMem;//设备内存
	int		multiProcessorCount;//处理器数量
	_STRU_DeviceProp_T():deviceid(0),totalGlobalMem(0),multiProcessorCount(0){memset(name,0,256);}
	_STRU_DeviceProp_T(int indeviceid,char*inname,long intotalGlobalMem,int inmultiProcessorCount)
		:deviceid(indeviceid),totalGlobalMem(intotalGlobalMem),multiProcessorCount(inmultiProcessorCount)
	{
		memcpy(name,inname,256);
	}
	_STRU_DeviceProp_T& operator =(const _STRU_DeviceProp_T&other)
	{
		deviceid	= other.deviceid;
		totalGlobalMem	= other.totalGlobalMem;
		multiProcessorCount	= other.multiProcessorCount;
		memcpy(name,other.name,256);
		return*this;
	}
	_STRU_DeviceProp_T(const _STRU_DeviceProp_T&other)
	{
		deviceid = other.deviceid;
		totalGlobalMem = other.totalGlobalMem;
		multiProcessorCount = other.multiProcessorCount;
		memcpy(name, other.name, 256);
	}
}STRU_DeviceProp_T,wsDeviceProp;
	
typedef struct _STRU_Devices_T
{
	wsDeviceProp dev[MAXDEVICESCOUNT];
	int nValid;//有效设备数量(cpu模式为0)
    _STRU_Devices_T():nValid(0){}
	_STRU_Devices_T& operator =(const _STRU_Devices_T&other)
	{
		for (int i = 0;i < MAXDEVICESCOUNT;i++)
			dev[i] = other.dev[i];
		nValid = nValid;
		return*this;
	}
	_STRU_Devices_T(const _STRU_Devices_T&other)
	{
		for (int i = 0;i < MAXDEVICESCOUNT;i++)
			dev[i] = other.dev[i];
		nValid = nValid;
	}
}STRU_Devices_T,wsDevices;

/*
说明：环境初始化(若License验证失败，则需要调用GetSN获取sn，生成对应的sLicense，然后调用FR_SetLicense)
输入：	
    无 
输出：
	无
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_Init();

/*
说明：清理环境 在程序退出时使用
输入：	
    无
输出：
	无
返回值：无
*/
EXPORT void FR_UnInit();

/*
说明：获取序列号
输入：	
    无  
输出：
	sn
返回值：无
*/
EXPORT void FR_GetSerialNum(char sn[20]);

/*
说明：设置license
输入：	
    sLicense		许可证信息
输出：
	无
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_SetLicense(char *sLicense);

/*
说明：
输入：	
    无
输出：
	nDay			授权剩余天数
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_GetOverdueDay(int &nDay);

/*
说明：获取通道号
输入：	
	deviceid		该端口使用GPU设备的序号，CPU为0，GPU 范围为1到FR_GetDevices接口返回的wsDevices.nValid (wsDevices.nValid 为0，表示GPU不可用)
输出：
	nPort			获取的通道号
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_GetPort(int&nPort,int deviceid=0);

/*
说明：释放通道号
输入：	
	nPort			需要释放的通道号
输出：
	无
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_FreePort(int nPort);

/*
说明：获取设备信息
输入：
	  无
输出：
	  devicesinfo	设备信息
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_GetDevices(wsDevices&devicesinfo);

/*
说明：将图像解码为RGB（传出参数中的img.data需在外部申请内存，dll内部将RGB数据填充到该内存中。RGB数据长度为img.width*img.height*3，由于解码前不知道图像宽高具体数值，所以外部申请较大空间内存，确保RGB保存完整）
输入：
	nPort			端口号
	SrcData			待解码原始图像数据
	nlength			原始图像数据长度
	nBuffSize		外部分配用来存放RGB数据的内存长度
输出：
	img				RGB数据
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_Decode(int nPort,unsigned char*SrcData,int nlength,int nBuffsize,STRU_ImgData_T&img);

/*
说明：将RGB编码为图像
输入：
	nPort			端口号
	img				图像RGB数据
	ext				需要编码的文件格式（如".jpg",".bmp"）
	nBuffsize		外部分配用来存放编码后数据的内存长度
	nEncodeScale	编码的压缩比例，取值为(0-100)值越大，编码后图像数据越大，图像质量越差
输出：
	DstData			编码后的图像数据(外部申请内存，dll内部将编码后的数据填充到该内存中)
	nlength			编码后的图像数据长度
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_Encode(int nPort,STRU_ImgData_T img,char*ext,unsigned char*DstData,int nBuffsize,int nEncodeScale,int&nlength);

/*
说明：人脸检测
输入：
	nPort			端口号
	img				图像数据
输出：
	rectinfo		填充nFaceNum,rects和labels信息
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_FaceDetect(int nPort,const STRU_ImgData_T&img, STRU_RectInfo_T&rectinfo);

/*
说明：人脸跟踪
输入：
	nPort			端口号
	img				图像数据
	rectinfo        人脸区域信息(FR_FaceDetect接口返回的数据)
输出：
	trackinginfo	人脸跟踪信息
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_Track(int nPort, const STRU_ImgData_T&img, STRU_TrackingInfo_T& trackinginfo,const STRU_RectInfo_T&rectinfo = STRU_RectInfo_T());

/*
说明：判断是否是欺骗数据
输入：
	nPort			端口号
	img				图像数据
	rectinfo		图像中的人脸区域信息(FR_FaceDetect接口返回的数据)
输出：
	realfaceinfo	活体相关信息
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_IsRealFace(int nPort, const STRU_ImgData_T& img, const STRU_RectInfo_T&rectinfo,STRU_RealFaceInfo_T&realfaceinfo);

/*
说明：获取人脸属性
输入：
	nPort			端口号
	img				图像数据
	rectinfo		图像中的人脸区域(FR_FaceDetect接口返回的数据)
输出：
	attrinfo        图像中的人脸属性信息
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_GetFaceAttr(int nPort, const STRU_ImgData_T& img, const STRU_RectInfo_T &rectinfo, wsAttrInfo &attrinfo);
 
/*
说明：特征点检测
输入：
	nPort		    端口号
	img				图像数据
	rectinfo		图像中的人脸区域(FR_FaceDetect接口返回的数据)
输出：
	landmarkinfo	每张人脸的特征点
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_GetLandmark(int nPort, const STRU_ImgData_T& img, const STRU_RectInfo_T &rectinfo, STRU_LandmarkInfo_T& landmarkinfo);
  
/*
说明：人脸质量检测
输入：
	nPort		    端口号
	img				图像数据
	rectinfo		图像中的人脸区域
输出：
	facequalityinfo	每张人脸的人脸质量信息
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_GetFaceQuality(int nPort, const STRU_ImgData_T& img, const STRU_RectInfo_T &rectinfo, STRU_FaceQualityInfo_T& facequalityinfo);

///////////////////////////////////////////////////////////////////////////////////
/*
说明：提取特征值
输入：
	nPort		    端口号
	mulimg			图像数据
输出：
	feainfo			特征信息
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_GetFeature(int nPort,const STRU_MultiTypeImg_T&mulimg,STRU_FeaInfo_T &feainfo);

/*
说明：获取特征值版本号
输入：
	feainfo			特征信息(FR_GetFeature接口返回的值)
输出：
	verinfo			版本信息
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_GetFeatureVersion(const STRU_FeaInfo_T&feainfo,STRU_VersionInfo_T&verinfo);
   
/*
说明：获取特征向量
输入：
	feainfo			特征信息(FR_GetFeature接口返回的值)
输出：
	fFeaVector		特征向量
	nVectorLength	特征向量长度
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_GetFeatureVector(const STRU_FeaInfo_T&feainfo,float*fFeaVector,int& nVectorLength);

/*
说明：导入特征值
输入：
	nPort			端口号
	sPersonID       注册ID
	feainfo			特征信息(FR_GetFeature接口返回的值)
输出：
	无
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_PutFeature(int nPort,const char* sPersonID, const STRU_FeaInfo_T&feainfo);

/*
说明：人脸注册,返回该注册图像特征值的文件名
输入：
	nPort		    端口号
	mulimg			图像数据
	sPersonID		注册ID
输出：
	sFeaFileName	特征文件名（用于删除操作）
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_Register(int nPort,STRU_MultiTypeImg_T mulimg,const char* sPersonID,char sFeaFileName[_MAX_FNAME]);

/*
说明：人脸验证
输入：
	nPort		    端口号
	mulimg			图像数据
	sPersonID		注册人ID
	bMatchAll		若一个人有多张注册图片，false表示只比较第一张注册图片，true表示和所有注册图片比较
输出：
	fScore			识别分数
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_Match(int nPort,STRU_MultiTypeImg_T mulimg,const char* sPersonID,float &fScore,bool bMatchAll = true);

/*
说明：人脸验证，单独比对两个特征值
输入：
	nPort		    端口号
	feature_src		特征1
	feature_dst		特征2	
输出：
	fScore			识别分数
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_Match(int nPort, const STRU_FeaInfo_T&feainfo_src, const STRU_FeaInfo_T&feainfo_dst, float &fScore);

/*
说明：人脸验证，单独比对两个特征值
输入：
	nPort		    端口号
	feature_src		特征1
	nFeaLength_src	特征1长度
	feature_dst		特征2
	nFeaLength_dst	特征2长度
输出：
	fScore			识别分数
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_Match(int nPort,float* feature_src,int nFeaLength_src,float* feature_dst,int nFeaLength_dst, float &fScore);
inline float FeaMatch(float* feature_src,float* feature_dst,int nFeaLength)
{
	float fscore = 0.0;
	for (int j = 0;j < nFeaLength;j++)
	{
		float tempdepthdis = feature_src[j] - feature_dst[j];
		fscore += (tempdepthdis*tempdepthdis);
	}
	return (2-fscore)*50;
}

/*
说明：人脸识别
输入：
	nPort		    端口号
	mulimg			图像数据
输出：
	Info			识别信息（返回排名前RANKNUM人）
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_FaceRecognition(int nPort,const STRU_MultiTypeImg_T&mulimg,STRU_RecognitionInfo_T&Info);

/*
说明：删除一张人脸的注册数据
输入：
	sFeaFileName       该人脸的注册信息（Register的输出值）
输出：
    无
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_DeleteFace(const char* sFeaFileName);

/*
说明：删除一个人的注册数据
输入：
	sPersonID     注册ID
输出：
	无
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_DeletePerson(const char* sPersonID);

/*
说明：删除所有注册数据
输入：
	无
输出：
	无
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_DeleteAllPerson();

////////////////////////BATCH BEGIN/////////////////////////////////
/*
说明：人脸检测
输入：
	nPort			端口号
	nBatchSize		当前需要处理的图片张数，需小于BATCHSIZE
	imgs			多张图像数据
输出：
	rectinfos		多张图像的人脸信息
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_FaceDetect(int nPort, int nBatchSize, const STRU_ImgData_T imgs[BATCHSIZE], STRU_RectInfo_T rectinfos[BATCHSIZE]);

/*
说明：特征点检测
输入：
	nPort		    端口号
	nBatchSize		当前需要处理的图片张数，需小于BATCHSIZE
	imgs			图像数据
	rectinfos       图像中的人脸信息(FR_FaceDetect返回的结果)
输出：
	landmarkinfos	多张图像的人脸的特征点信息
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_GetLandmark(int nPort, int nBatchSize, const STRU_ImgData_T imgs[BATCHSIZE], const STRU_RectInfo_T rectinfos[BATCHSIZE], STRU_LandmarkInfo_T landmarkinfos[BATCHSIZE]);

/*
说明：人脸质量检测
输入：
	nPort		    端口号
	nBatchSize		当前需要处理的图片张数，需小于BATCHSIZE
	imgs			图像数据
	rectinfos       图像中的人脸信息(FR_FaceDetect返回的结果)
输出：
	facequalityinfos图像中的人脸质量信息
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_GetFaceQuality(int nPort, int nBatchSize, const STRU_ImgData_T imgs[BATCHSIZE], const STRU_RectInfo_T rectinfos[BATCHSIZE], STRU_FaceQualityInfo_T facequalityinfos[BATCHSIZE]);

/*
说明：判断是否是欺骗数据
输入：
	nPort			端口号
	nBatchSize		当前需要处理的图片张数，需小于BATCHSIZE
	imgs			图像数据
	rectinfos       图像中的人脸信息(FR_FaceDetect返回的结果)
输出：
	realfaceinfo	人脸区域为真实人脸的概率信息
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_IsRealFace(int nPort,int nBatchSize, const STRU_ImgData_T imgs[BATCHSIZE], const STRU_RectInfo_T rectinfos[BATCHSIZE],STRU_RealFaceInfo_T realfaceinfo[BATCHSIZE]);

/*
说明：获取人脸属性
输入：
	nPort				端口号
	nBatchSize			当前需要处理的图片张数，需小于BATCHSIZE
	imgs				图像数据
	rectinfos			图像中的人脸信息(FR_FaceDetect返回的结果)
输出：
	attrinfos           图像中的人脸属性信息
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_GetFaceAttr(int nPort, int nBatchSize, const STRU_ImgData_T imgs[BATCHSIZE], const STRU_RectInfo_T rectinfos[BATCHSIZE], STRU_AttrInfo_T attrinfos[BATCHSIZE]);

/*
说明：提取特征值
输入：
	nPort		    端口号
	nBatchSize		当前主要处理的图片张数，需小于BATCHSIZE
	imgs			多张图像
输出：
	feainfos		特征信息
返回值：0表示成功 小于0表示失败
*/
EXPORT int FR_GetFeature(int nPort,int nBatchSize, const STRU_MultiTypeImg_T imgs[BATCHSIZE],STRU_FeaInfo_T feainfos[BATCHSIZE]);

////////////////////////BATCH END  /////////////////////////////////
#endif /* DLL_FACEMATCH_H_ */
