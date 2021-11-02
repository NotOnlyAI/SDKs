// FaceDetect_winDLL.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <Windows.h>

#include <opencv2/opencv.hpp>
#include "face_typedef.h"
#include "face_cdzs_win.h"

using namespace std;
int FR_Show_bbox_and_landmark(cv::Mat image, STRU_Rect_T rect, STRU_Landmark_T landmark, STRU_Label_T label, std::string save_path)
{

    cv::Mat image_bbox = image;
    std::string text = std::to_string(label.score);
    int font_face = cv::FONT_HERSHEY_COMPLEX;
    double font_scale = 1;
    int thickness = 1;
    //    int baseline;
    //    cv::Size text_size = cv::getTextSize(text, font_face, font_scale, thickness, &baseline);
        //将文本框居中绘制
    cv::Point origin;
    origin.x = rect.x + 20;
    origin.y = rect.y + 20;
    cv::putText(image, text, origin, font_face, font_scale, cv::Scalar(0, 255, 255), thickness, 8, 0);

    cv::Rect r = cv::Rect(rect.x, rect.y, rect.width, rect.height);

    cv::rectangle(image_bbox, r, cv::Scalar(255, 0, 0), 1, 8, 0);
    cv::Point p1(landmark.point[0].x, landmark.point[0].y);
    cv::Point p2(landmark.point[1].x, landmark.point[1].y);
    cv::Point p3(landmark.point[2].x, landmark.point[2].y);
    cv::Point p4(landmark.point[3].x, landmark.point[3].y);
    cv::Point p5(landmark.point[4].x, landmark.point[4].y);
    cv::circle(image_bbox, p1, 1, cv::Scalar(0, 255, 0), -1); // 画半径为1的圆(画点�?
    cv::circle(image_bbox, p2, 1, cv::Scalar(0, 255, 0), -1);  // 画半径为1的圆(画点�?
    cv::circle(image_bbox, p3, 1, cv::Scalar(0, 255, 0), -1);  // 画半径为1的圆(画点�?
    cv::circle(image_bbox, p4, 1, cv::Scalar(0, 255, 0), -1);  // 画半径为1的圆(画点�?
    cv::circle(image_bbox, p5, 1, cv::Scalar(0, 255, 0), -1);  // 画半径为1的圆(画点�?

    cv::imwrite(save_path, image_bbox);

    return 1;
}

int main()
{
    
    const char* tf_dll_path = "face_cdzs_win_tflite.dll";
    HINSTANCE hDLL;
    hDLL = LoadLibraryA(tf_dll_path);//加载动态链接库DLLTest.dll文件；

    if (hDLL == NULL)
    {
        cout << "载入face_cdzs_win.dll失败" << endl;
        FreeLibrary(hDLL);
        system("pause");
        return -1;
    }

    typedef int(*FR_FaceDetect)(const STRU_ImgData_T& imagedata, STRU_RectInfo_T& rectinfo, STRU_LandmarkInfo_T& landmarkinfo, int max_or_mid);
    FR_FaceDetect funPtr_FR_FaceDetect = (FR_FaceDetect)GetProcAddress(hDLL, "FR_FaceDetect");

    typedef int(*FR_FaceMaskJudge)(const STRU_ImgData_T& imagedata, const STRU_Rect_T& rect, int& maskinfo);
    FR_FaceMaskJudge funPtr_FR_FaceMaskJudge = (FR_FaceMaskJudge)GetProcAddress(hDLL, "FR_FaceMaskJudge");

    cv::Mat image;
    std::string img_path = "test.jpg";
    image = cv::imread(img_path);
    if (!image.data) { 
        cout << "read image fail!" << endl;
        return -1;
    }


    STRU_ImgData_T imagedata;
    STRU_RectInfo_T rectinfo;
    STRU_LandmarkInfo_T landmarkinfo;

    imagedata.data = image.data;
    imagedata.width = image.cols;
    imagedata.height = image.rows;
    imagedata.channel = image.channels();

    funPtr_FR_FaceDetect(imagedata, rectinfo, landmarkinfo, 0);

    for (int i = 0; i < rectinfo.nFaceNum; i++)
    {
        STRU_Rect_T     rect = rectinfo.rects[i];
        STRU_Landmark_T landmark = landmarkinfo.landmark[i];
        STRU_Label_T    label = rectinfo.labels[i];

        std::string save_path = "test_result.jpg";
        FR_Show_bbox_and_landmark(image, rect, landmark, label, save_path);
    }
    std::cout << "Hello World!\n";
    return 1;
}