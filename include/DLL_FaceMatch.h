/*
 * DLL_FaceMatch.h
 *
 *  Created on: 2015��10��8��
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

#define MAXFACECOUNT		200		//����ͼ�����֧�ּ��������
#define RANKNUM				10		//����ʶ������ǰ��λ����Ϣ
#define MAXIDLEN			100		//���ID����
#define MAXLANDMARKNUM		5		//���landmark��
#define MAXFEALENGTH		2600	//�����������
#define MAXVERLENGTH		30		//�汾����Ϣ����
#define MAXDEVICESCOUNT     50      //֧������豸����
#define BATCHSIZE			10		//���������֧�ֵ�ͼ������
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
#define  SUCCESS							0			//�ɹ�
#define  ERR_UNKNOWNERR						-1			//δ֪����
#define  ERR_VERIFYFAILED					-2	        //��֤licenseʧ��
#define  ERR_INITFAILED						-3  		//��ʼ��ʧ��
#define  ERR_IMGDATAERROR					-4	        //ͼ�����ݴ���
#define  ERR_IMGTYPEERROE					-5			//����������ָ�����Ͳ�һ��
#define  ERR_NOFACE							-6			//δ��⵽����
#define  ERR_FACEDETECTFAILED				-7  		//�������ʧ��
#define  ERR_GETLANDMARKFAILED				-8	        //��������ʧ��
#define  ERR_NORMALIZEFAILED				-9			//��һ��ʧ��
#define  ERR_GETFEATUREFAILED				-10			//��ȡ����ֵʧ��
#define  ERR_SAVEFEATUREFAILED				-11			//��������ֵʧ��
#define  ERR_NOFEATURE4THISID				-12			//�޸�ID��ע������
#define  ERR_DIMUNEQUAL						-13			//����ֵά�Ȳ�һ�£�����ƥ��
#define  ERR_FEATUREISNULL					-14			//����ֵΪ��
#define  ERR_RECOGNITIONFAILED				-15 		//����ʶ��ʧ��
#define  ERR_LOADFEATUREFAILED				-16         //����������ʧ��
#define  ERR_NOTHRESHOLD					-17         //δ������ֵ
#define  ERR_FACEISNOTEXIST					-18         //�޸�����ע����Ϣ  
#define  ERR_PERSONISNOTEXIST				-19         //�޸���ע����Ϣ
#define  ERR_DELETEFILEFAILED				-20         //ɾ���ļ�ʧ��
#define  ERR_INTERFACEISWRONG				-21         //�ӿڵ��ô���
#define  ERR_PARAMERROR						-22         //�����������
#define  ERR_ISNOTFACE						-23         //������ȡ�����㣬������������
#define  ERR_FILEISNOTEXIST					-24         //�ļ������� 
#define  ERR_GETVERSIONFAILED				-25         //��ȡDLL�汾��ʧ�� 
#define  ERR_DIFFERRNTVERSION				-26	        //�汾�Ų�һ��
#define  ERR_FEATUREVERTOOOLD				-27 		//������汾����
#define  ERR_TRAINMATVERTOOOLD				-28         //ѵ������汾����
#define  ERR_FEATUREISTOOSHORT				-29         //�������Ȳ��㣬���ܻ�ȡ�汾��
#define  ERR_INTERFACEDISABLE				-30	        //�ӿڲ�����
#define  ERR_GETPORTFAILD					-31			//��ȡͨ����ʧ��
#define  ERR_PORTERROR						-32 		//�˿ںŴ���
#define  ERR_IDERROR						-33         //ע��ID�ŷǷ�
#define  ERR_IDISTOOLONG					-34	        //ע��ID̫������󳤶�Ϊ100
#define  ERR_JPGDATAERROR					-35			//JPG����Ϊ�ջ򳤶�Ϊ0
#define  ERR_JPGDECODEFAILED				-36			//JPG����ʧ��
#define  ERR_DATAERROR						-37			//JPG����Ϊ�ջ򳤶�Ϊ0
#define  ERR_EXTERROR						-38 		//�����ʽ����
#define  ERR_BUFFOUTOFMEMORY				-39	        //�ⲿ������ڴ治��
#define  ERR_ENCODESCALEERROR				-40			//����ѹ����������
#define  ERR_FEATURELENGTHUNEQUAL			-41			//������������Ȳ�һ��
#define  ERR_GETFEATUREWHFAILED				-42			//��ȡ����������Ϣʧ��
#define  ERR_INPUTFEATURELENGTHERROR		-43			//������������ȴ���
#define  ERR_THEPORTNOTEXIST				-44 		//�ö˿ڲ�����
#define  ERR_DIFFERRNTFEATURETYPE			-45         //�������Ͳ�һ��
#define  ERR_FEATUREERROR					-46         //����ֵ����
#define  ERR_WRITEFEAFILEFAILED				-47	        //���������ļ�����
#define  ERR_FACEDETECTINITFAILED			-48			//��������ʼ��ʧ��
#define  ERR_CONFIGFILENOTEXIST				-49			//�����ļ�������	
#define  ERR_GETISFACEFEAFAILED				-50			//��ȡ����ֵʧ��
#define  ERR_GETFACEDETECTFEAFAILED			-51			//��ȡ����������ֵʧ��
#define  ERR_GETFACEATTRFAILED				-52			//��ȡ��������ʧ��
#define  ERR_GETFACEQUALITYFAILED			-53			//��ȡ��������ʧ��
#define  ERR_GETFACELANDMARKFAILED			-54			//��ȡ����������ʧ��
#define  ERR_THISVERSIONNOTSUPPORT			-55			//�ð汾��֧�ִ˽ӿ�	
#define  ERR_INPUTERROR						-56			//�������	
#define  ERR_CUTMODELERROR					-57			//�ü�ʧ��
#define	 ERR_CONFIGISCPU					-58			//����Ϊ��ʹ��GPU,���ܻ�ȡ/���� �豸��Ϣ
#define	 ERR_GETINSFAILED   				-59			//��ȡʵ��ʧ��
#define  ERR_DEVICEIDERROR					-60			//�豸ID����
#define  ERR_DEVICEFORDIFFPORT				-61			//��ͬ�˿�ʹ����ͬһ��GPU��һ��GPUֻ����һ���˿�ʹ��(CPU�����Կ������Կ�ģʽ�µ�һ���Կ����ܴ�Ӱ�죩
#define  ERR_BATCHSIZEERR					-62			//batchsize ����ȡֵ��Χ1-BATCHSIZE
#define  ERR_IMAGECROPFAILED				-63			//ͼ��ü�����
#define  ERR_RECTTOOSMALL					-64			//��������̫С

#define  ERR_UNAUTHORIZED					-101		//δ��Ȩ
#define  ERR_EXPIRY							-102		//��Ȩ����
#define  ERR_INVALIDTIME					-103		//�Ƿ��޸�ϵͳ����
#define  ERR_PERMISSIONDENIED				-104		//Ȩ�޲���



typedef struct _STRU_Point_T
{
	int x;//����X
	int y;//����Y

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
	int roll;	  //ƽ����ת�Ƕ�z
	int pitch;	  //�����Ƕ�//��X
	int yaw;      //����ƫת�Ƕ�y
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

typedef struct _STRU_Track_T//���׸���
{
	int trackID;//����ID
	int status;//������״̬  1-���� 2-���ٿ�
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
	int nFaceNum;//��������
	wsRect rects[MAXFACECOUNT];//ÿ������������
	wsLabel labels[MAXFACECOUNT];//�����ı�ǩ��Ϣ
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
	_STRU_RectInfo_T GetFrontFace()//ֻ�����������򣬶��������ȱ�ǩ����
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
	_STRU_RectInfo_T GetBestFace(int w, int h)//����
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
	_STRU_RectInfo_T GetMaxFace()//��ȡ�����������
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
	_STRU_RectInfo_T GetMidFace(int img_w, int img_h)//��ȡ���е���������
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
	int nFaceNum;//��������
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
	int nFaceNum;//��������
	wsLandmark landmark[MAXFACECOUNT];//ÿ��������landmark��Ϣ

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
	float confidence;//�������Ŷ�
	float clearness;//������
	float unocclusion;//���ڵ�
	float glasses;//���۾�
	float pokerface;//�޿��ű���
	float illumination;//����

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
	int nFaceNum;//��������
	wsFaceQuality facequality[MAXFACECOUNT];//ÿ��������quality��Ϣ

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
	int occlusion;//0 ���ڵ�  1�ڵ�
	int glasses;//0���۾� 1���۾�
	int age;//���� 
	int gender;//�Ա� 0-�� 1-Ů
	int ethnicity;//���� 0-���� 1-���� 2-������ 3-ӡ�ڰ� 4-����
	int emotion;//���� 0-surprise 1-fear 2-disgust 3-happiness 4-sadness 5-anger 6-neutral
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
	int nFaceNum;//��������
	wsAttr attrs[MAXFACECOUNT]; //ÿ��������������Ϣ

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
	char  sPersonID[MAXIDLEN];	//����
	float   fScore;             //�ȶԷ���
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
	int		nFeaLen;//��������
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
	int		nVerLen;//�汾��Ϣ����
	char	sVer[MAXVERLENGTH];	//�汾��Ϣ����

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
	STRU_Rect_T rect_;                  //��������
	STRU_ScoreInfo_T ScoreInfo[RANKNUM];//��������ǰRANKNUM��ʶ����Ϣ
	int nValid;                    //������Ϣ����Чλ������ScoreInfo������ǰnValidλΪ��Ч���ݣ�
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
	unsigned char* data;	//ͼ������
	int width;              //ͼ����
	int height;             //ͼ��߶�
	int depth;              //λ��
	int channel;            //ͨ����
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
	STRU_ImgData_T img[5];	    //0--��ɫͼ��1--���ͼ��  2--����ͼ�� ����Ԥ��
	STRU_Landmark_T landmark;	//����������(�������ͼ��)
	STRU_FaceQuality_T quality;	    //������Ϣ(���ײ�ɫͼ��)

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
	int		deviceid;//�豸ID
	char	name[256];//�豸����
	long	totalGlobalMem;//�豸�ڴ�
	int		multiProcessorCount;//����������
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
	int nValid;//��Ч�豸����(cpuģʽΪ0)
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
˵����������ʼ��(��License��֤ʧ�ܣ�����Ҫ����GetSN��ȡsn�����ɶ�Ӧ��sLicense��Ȼ�����FR_SetLicense)
���룺	
    �� 
�����
	��
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_Init();

/*
˵���������� �ڳ����˳�ʱʹ��
���룺	
    ��
�����
	��
����ֵ����
*/
EXPORT void FR_UnInit();

/*
˵������ȡ���к�
���룺	
    ��  
�����
	sn
����ֵ����
*/
EXPORT void FR_GetSerialNum(char sn[20]);

/*
˵��������license
���룺	
    sLicense		���֤��Ϣ
�����
	��
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_SetLicense(char *sLicense);

/*
˵����
���룺	
    ��
�����
	nDay			��Ȩʣ������
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_GetOverdueDay(int &nDay);

/*
˵������ȡͨ����
���룺	
	deviceid		�ö˿�ʹ��GPU�豸����ţ�CPUΪ0��GPU ��ΧΪ1��FR_GetDevices�ӿڷ��ص�wsDevices.nValid (wsDevices.nValid Ϊ0����ʾGPU������)
�����
	nPort			��ȡ��ͨ����
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_GetPort(int&nPort,int deviceid=0);

/*
˵�����ͷ�ͨ����
���룺	
	nPort			��Ҫ�ͷŵ�ͨ����
�����
	��
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_FreePort(int nPort);

/*
˵������ȡ�豸��Ϣ
���룺
	  ��
�����
	  devicesinfo	�豸��Ϣ
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_GetDevices(wsDevices&devicesinfo);

/*
˵������ͼ�����ΪRGB�����������е�img.data�����ⲿ�����ڴ棬dll�ڲ���RGB������䵽���ڴ��С�RGB���ݳ���Ϊimg.width*img.height*3�����ڽ���ǰ��֪��ͼ���߾�����ֵ�������ⲿ����ϴ�ռ��ڴ棬ȷ��RGB����������
���룺
	nPort			�˿ں�
	SrcData			������ԭʼͼ������
	nlength			ԭʼͼ�����ݳ���
	nBuffSize		�ⲿ�����������RGB���ݵ��ڴ泤��
�����
	img				RGB����
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_Decode(int nPort,unsigned char*SrcData,int nlength,int nBuffsize,STRU_ImgData_T&img);

/*
˵������RGB����Ϊͼ��
���룺
	nPort			�˿ں�
	img				ͼ��RGB����
	ext				��Ҫ������ļ���ʽ����".jpg",".bmp"��
	nBuffsize		�ⲿ����������ű�������ݵ��ڴ泤��
	nEncodeScale	�����ѹ��������ȡֵΪ(0-100)ֵԽ�󣬱����ͼ������Խ��ͼ������Խ��
�����
	DstData			������ͼ������(�ⲿ�����ڴ棬dll�ڲ���������������䵽���ڴ���)
	nlength			������ͼ�����ݳ���
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_Encode(int nPort,STRU_ImgData_T img,char*ext,unsigned char*DstData,int nBuffsize,int nEncodeScale,int&nlength);

/*
˵�����������
���룺
	nPort			�˿ں�
	img				ͼ������
�����
	rectinfo		���nFaceNum,rects��labels��Ϣ
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_FaceDetect(int nPort,const STRU_ImgData_T&img, STRU_RectInfo_T&rectinfo);

/*
˵������������
���룺
	nPort			�˿ں�
	img				ͼ������
	rectinfo        ����������Ϣ(FR_FaceDetect�ӿڷ��ص�����)
�����
	trackinginfo	����������Ϣ
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_Track(int nPort, const STRU_ImgData_T&img, STRU_TrackingInfo_T& trackinginfo,const STRU_RectInfo_T&rectinfo = STRU_RectInfo_T());

/*
˵�����ж��Ƿ�����ƭ����
���룺
	nPort			�˿ں�
	img				ͼ������
	rectinfo		ͼ���е�����������Ϣ(FR_FaceDetect�ӿڷ��ص�����)
�����
	realfaceinfo	���������Ϣ
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_IsRealFace(int nPort, const STRU_ImgData_T& img, const STRU_RectInfo_T&rectinfo,STRU_RealFaceInfo_T&realfaceinfo);

/*
˵������ȡ��������
���룺
	nPort			�˿ں�
	img				ͼ������
	rectinfo		ͼ���е���������(FR_FaceDetect�ӿڷ��ص�����)
�����
	attrinfo        ͼ���е�����������Ϣ
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_GetFaceAttr(int nPort, const STRU_ImgData_T& img, const STRU_RectInfo_T &rectinfo, wsAttrInfo &attrinfo);
 
/*
˵������������
���룺
	nPort		    �˿ں�
	img				ͼ������
	rectinfo		ͼ���е���������(FR_FaceDetect�ӿڷ��ص�����)
�����
	landmarkinfo	ÿ��������������
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_GetLandmark(int nPort, const STRU_ImgData_T& img, const STRU_RectInfo_T &rectinfo, STRU_LandmarkInfo_T& landmarkinfo);
  
/*
˵���������������
���룺
	nPort		    �˿ں�
	img				ͼ������
	rectinfo		ͼ���е���������
�����
	facequalityinfo	ÿ������������������Ϣ
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_GetFaceQuality(int nPort, const STRU_ImgData_T& img, const STRU_RectInfo_T &rectinfo, STRU_FaceQualityInfo_T& facequalityinfo);

///////////////////////////////////////////////////////////////////////////////////
/*
˵������ȡ����ֵ
���룺
	nPort		    �˿ں�
	mulimg			ͼ������
�����
	feainfo			������Ϣ
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_GetFeature(int nPort,const STRU_MultiTypeImg_T&mulimg,STRU_FeaInfo_T &feainfo);

/*
˵������ȡ����ֵ�汾��
���룺
	feainfo			������Ϣ(FR_GetFeature�ӿڷ��ص�ֵ)
�����
	verinfo			�汾��Ϣ
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_GetFeatureVersion(const STRU_FeaInfo_T&feainfo,STRU_VersionInfo_T&verinfo);
   
/*
˵������ȡ��������
���룺
	feainfo			������Ϣ(FR_GetFeature�ӿڷ��ص�ֵ)
�����
	fFeaVector		��������
	nVectorLength	������������
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_GetFeatureVector(const STRU_FeaInfo_T&feainfo,float*fFeaVector,int& nVectorLength);

/*
˵������������ֵ
���룺
	nPort			�˿ں�
	sPersonID       ע��ID
	feainfo			������Ϣ(FR_GetFeature�ӿڷ��ص�ֵ)
�����
	��
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_PutFeature(int nPort,const char* sPersonID, const STRU_FeaInfo_T&feainfo);

/*
˵��������ע��,���ظ�ע��ͼ������ֵ���ļ���
���룺
	nPort		    �˿ں�
	mulimg			ͼ������
	sPersonID		ע��ID
�����
	sFeaFileName	�����ļ���������ɾ��������
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_Register(int nPort,STRU_MultiTypeImg_T mulimg,const char* sPersonID,char sFeaFileName[_MAX_FNAME]);

/*
˵����������֤
���룺
	nPort		    �˿ں�
	mulimg			ͼ������
	sPersonID		ע����ID
	bMatchAll		��һ�����ж���ע��ͼƬ��false��ʾֻ�Ƚϵ�һ��ע��ͼƬ��true��ʾ������ע��ͼƬ�Ƚ�
�����
	fScore			ʶ�����
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_Match(int nPort,STRU_MultiTypeImg_T mulimg,const char* sPersonID,float &fScore,bool bMatchAll = true);

/*
˵����������֤�������ȶ���������ֵ
���룺
	nPort		    �˿ں�
	feature_src		����1
	feature_dst		����2	
�����
	fScore			ʶ�����
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_Match(int nPort, const STRU_FeaInfo_T&feainfo_src, const STRU_FeaInfo_T&feainfo_dst, float &fScore);

/*
˵����������֤�������ȶ���������ֵ
���룺
	nPort		    �˿ں�
	feature_src		����1
	nFeaLength_src	����1����
	feature_dst		����2
	nFeaLength_dst	����2����
�����
	fScore			ʶ�����
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
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
˵��������ʶ��
���룺
	nPort		    �˿ں�
	mulimg			ͼ������
�����
	Info			ʶ����Ϣ����������ǰRANKNUM�ˣ�
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_FaceRecognition(int nPort,const STRU_MultiTypeImg_T&mulimg,STRU_RecognitionInfo_T&Info);

/*
˵����ɾ��һ��������ע������
���룺
	sFeaFileName       ��������ע����Ϣ��Register�����ֵ��
�����
    ��
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_DeleteFace(const char* sFeaFileName);

/*
˵����ɾ��һ���˵�ע������
���룺
	sPersonID     ע��ID
�����
	��
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_DeletePerson(const char* sPersonID);

/*
˵����ɾ������ע������
���룺
	��
�����
	��
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_DeleteAllPerson();

////////////////////////BATCH BEGIN/////////////////////////////////
/*
˵�����������
���룺
	nPort			�˿ں�
	nBatchSize		��ǰ��Ҫ�����ͼƬ��������С��BATCHSIZE
	imgs			����ͼ������
�����
	rectinfos		����ͼ���������Ϣ
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_FaceDetect(int nPort, int nBatchSize, const STRU_ImgData_T imgs[BATCHSIZE], STRU_RectInfo_T rectinfos[BATCHSIZE]);

/*
˵������������
���룺
	nPort		    �˿ں�
	nBatchSize		��ǰ��Ҫ�����ͼƬ��������С��BATCHSIZE
	imgs			ͼ������
	rectinfos       ͼ���е�������Ϣ(FR_FaceDetect���صĽ��)
�����
	landmarkinfos	����ͼ�����������������Ϣ
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_GetLandmark(int nPort, int nBatchSize, const STRU_ImgData_T imgs[BATCHSIZE], const STRU_RectInfo_T rectinfos[BATCHSIZE], STRU_LandmarkInfo_T landmarkinfos[BATCHSIZE]);

/*
˵���������������
���룺
	nPort		    �˿ں�
	nBatchSize		��ǰ��Ҫ�����ͼƬ��������С��BATCHSIZE
	imgs			ͼ������
	rectinfos       ͼ���е�������Ϣ(FR_FaceDetect���صĽ��)
�����
	facequalityinfosͼ���е�����������Ϣ
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_GetFaceQuality(int nPort, int nBatchSize, const STRU_ImgData_T imgs[BATCHSIZE], const STRU_RectInfo_T rectinfos[BATCHSIZE], STRU_FaceQualityInfo_T facequalityinfos[BATCHSIZE]);

/*
˵�����ж��Ƿ�����ƭ����
���룺
	nPort			�˿ں�
	nBatchSize		��ǰ��Ҫ�����ͼƬ��������С��BATCHSIZE
	imgs			ͼ������
	rectinfos       ͼ���е�������Ϣ(FR_FaceDetect���صĽ��)
�����
	realfaceinfo	��������Ϊ��ʵ�����ĸ�����Ϣ
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_IsRealFace(int nPort,int nBatchSize, const STRU_ImgData_T imgs[BATCHSIZE], const STRU_RectInfo_T rectinfos[BATCHSIZE],STRU_RealFaceInfo_T realfaceinfo[BATCHSIZE]);

/*
˵������ȡ��������
���룺
	nPort				�˿ں�
	nBatchSize			��ǰ��Ҫ�����ͼƬ��������С��BATCHSIZE
	imgs				ͼ������
	rectinfos			ͼ���е�������Ϣ(FR_FaceDetect���صĽ��)
�����
	attrinfos           ͼ���е�����������Ϣ
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_GetFaceAttr(int nPort, int nBatchSize, const STRU_ImgData_T imgs[BATCHSIZE], const STRU_RectInfo_T rectinfos[BATCHSIZE], STRU_AttrInfo_T attrinfos[BATCHSIZE]);

/*
˵������ȡ����ֵ
���룺
	nPort		    �˿ں�
	nBatchSize		��ǰ��Ҫ�����ͼƬ��������С��BATCHSIZE
	imgs			����ͼ��
�����
	feainfos		������Ϣ
����ֵ��0��ʾ�ɹ� С��0��ʾʧ��
*/
EXPORT int FR_GetFeature(int nPort,int nBatchSize, const STRU_MultiTypeImg_T imgs[BATCHSIZE],STRU_FeaInfo_T feainfos[BATCHSIZE]);

////////////////////////BATCH END  /////////////////////////////////
#endif /* DLL_FACEMATCH_H_ */
