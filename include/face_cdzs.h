#ifndef _FD_FACEIR_GPU_H_
#define _FD_FACEIR_GPU_H_


#include "face_typedef.h"

#ifdef _MSC_VER
#define FACE_CDZS_EXPORT __declspec(dllexport)
#else
#define FACE_CDZS_EXPORT __attribute__ ((visibility("default")))
#endif

#define FACE_CDZS_C_EXPORT extern "C" FACE_CDZS_EXPORT



/*
FR_FaceDetect说明：人脸检测和五点检测
输入：imagedata  输入图片数据;    max_or_mid        0为最大脸,1为中间脸;
输出：rectinfo   人脸区域信息;    landmarkinfo	人脸五点信息;
返回值：0表示成功 小于0表示失败
*/
FACE_CDZS_EXPORT int FR_FaceDetect(const STRU_ImgData_T &imagedata,
                                   STRU_RectInfo_T &rectinfo,
                                   STRU_LandmarkInfo_T &landmarkinfo,
                                   int max_or_mid);


/*
FR_FaceMaskJudge说明：戴口罩判断
输入：imagedata	输入图片数据;  rect   人脸区域;
输出：maskinfo	戴口罩标志字： 0 未戴口罩；1 戴口罩；
返回值：0表示成功 小于0表示失败
*/
FACE_CDZS_EXPORT int FR_FaceMaskJudge(const STRU_ImgData_T &imagedata,const STRU_Rect_T &rect, int &maskinfo);


/*
FR_FaceQualityResults说明：二维人脸图片质量判断
输入：imagedata 输入图片数据;  rect 人脸区域;  landmark  人脸五点;
输出：facequalityresults：结果保存在结构体STRU_FR_FaceQualityResults_T 中；
返回值：0表示成功 -1表示失败
*/
// 质量有一项不合格 即返回结果，不再继续判断其他项；
FACE_CDZS_EXPORT int FR_FaceQualityResults(const STRU_ImgData_T &imagedata,
                    const STRU_Rect_T &rect,
                    const STRU_Landmark_T &landmark,
                    STRU_FaceQualityResults_T &facequalityresults);

/*
FR_FaceAntiSpoof说明：二维人脸真假脸判断
输入：imagedata 输入图片数据;  rect 人脸区域;  landmark  人脸五点;
输出：fakeinfo： fakeinfo=0 真脸  fakeinfo=1 假脸  fakeinfo=2 图片模糊无法判断；
返回值：0表示成功 -1表示失败
*/
// FACE_CDZS_EXPORT int FR_FaceAntiSpoof(const STRU_ImgData_T  &imagedata,
//                                       const STRU_Rect_T     &rect,
//                                       const STRU_Landmark_T &landmark,
//                                       int &fakeinfo);
// #ifdef FACE_CVSHOW
// FACE_CDZS_EXPORT void check_tools(const STRU_ImgData_T &imagedata,const STRU_Rect_T &rect);
// #endif


#endif

