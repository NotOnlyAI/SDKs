#include <opencv2/opencv.hpp>
#include "face_cdzs.h"
#include "face_cdzs_temp.h"
#include <fstream>
#include <time.h>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <string>


using namespace std;
vector<string> spilt(string s,char ch)
{
    s.push_back(ch);
    int start = 0,end = 0,size = s.size();
    vector<string> vs;

    for(int i = 0;i < size;i++)
    {
        if(s[i]==ch)
        {
            end = i;
            string temp = s.substr(start,end-start);
            start = i+1;
            vs.push_back(temp);
        }
    }
    return vs;
}
int FR_Show_PTS(cv::Mat image,STRU_PTS_T pts,std::string save_path)
{

    for(int i=0;i<98;i++)
    {
        cv::Point p1(pts.point[i].x , pts.point[i].y);
        // std::cout << i <<"  x: "<< pts.point[i].x << "   y: "<< pts.point[i].y <<std::endl;
        cv::circle(image, p1, 1, cv::Scalar(0, 255, 0), -1); // 画半径为1的圆(画点�?
    }
    cv::imwrite(save_path,image);
    return 1;
}

int FR_Show_bbox_and_landmark(cv::Mat image,STRU_Rect_T rect,STRU_Landmark_T landmark,STRU_Label_T label,std::string save_path)
{

    cv::Mat image_bbox=image;
    std::string text =std::to_string(label.score);
    int font_face = cv::FONT_HERSHEY_COMPLEX;
    double font_scale = 1;
    int thickness = 1;
//    int baseline;
//    cv::Size text_size = cv::getTextSize(text, font_face, font_scale, thickness, &baseline);
    //将文本框居中绘制
    cv::Point origin;
    origin.x = rect.x+20;
    origin.y = rect.y+20;
    cv::putText(image, text, origin, font_face, font_scale, cv::Scalar(0, 255, 255), thickness, 8, 0);

    cv::Rect r = cv::Rect(rect.x, rect.y, rect.width, rect.height);

    cv::rectangle(image_bbox, r, cv::Scalar(255, 0, 0), 1, 8, 0);
    cv::Point p1(landmark.point[0].x , landmark.point[0].y);
    cv::Point p2(landmark.point[1].x , landmark.point[1].y);
    cv::Point p3(landmark.point[2].x , landmark.point[2].y);
    cv::Point p4(landmark.point[3].x , landmark.point[3].y);
    cv::Point p5(landmark.point[4].x , landmark.point[4].y);
    cv::circle(image_bbox, p1, 1, cv::Scalar(0, 255, 0), -1); // 画半径为1的圆(画点�?
    cv::circle(image_bbox, p2, 1, cv::Scalar(0, 255, 0), -1);  // 画半径为1的圆(画点�?
    cv::circle(image_bbox, p3, 1, cv::Scalar(0, 255, 0), -1);  // 画半径为1的圆(画点�?
    cv::circle(image_bbox, p4, 1, cv::Scalar(0, 255, 0), -1);  // 画半径为1的圆(画点�?
    cv::circle(image_bbox, p5, 1, cv:: Scalar(0, 255, 0), -1);  // 画半径为1的圆(画点�?

    cv::imwrite(save_path,image_bbox);

    return 1;
}

int FR_Show_bboxes_and_landmarks(cv::Mat image,STRU_RectInfo_T rectinfo,STRU_LandmarkInfo_T landmarkinfo,std::string save_path)
{
    cv::Mat image_bbox=image;
    for(int i=0;i<rectinfo.nFaceNum;i++)
    {
        std::string text =std::to_string(rectinfo.labels[i].score);
        int font_face = cv::FONT_HERSHEY_COMPLEX;
        double font_scale = 1;
        int thickness = 1;
//        int baseline;
//        cv::Size text_size = cv::getTextSize(text, font_face, font_scale, thickness, &baseline);
        //将文本框居中绘制
        cv::Point origin;
        origin.x = rectinfo.rects[i].x+20;
        origin.y = rectinfo.rects[i].y+20;
        cv::putText(image, text, origin, font_face, font_scale, cv::Scalar(0, 255, 255), thickness, 8, 0);

        cv::Rect r = cv::Rect(rectinfo.rects[i].x, rectinfo.rects[i].y, rectinfo.rects[i].width, rectinfo.rects[i].height);

        cv::rectangle(image_bbox, r, cv::Scalar(255, 0, 0), 1, 8, 0);
        cv::Point p1(landmarkinfo.landmark[i].point[0].x , landmarkinfo.landmark[i].point[0].y);
        cv::Point p2(landmarkinfo.landmark[i].point[1].x , landmarkinfo.landmark[i].point[1].y);
        cv::Point p3(landmarkinfo.landmark[i].point[2].x , landmarkinfo.landmark[i].point[2].y);
        cv::Point p4(landmarkinfo.landmark[i].point[3].x , landmarkinfo.landmark[i].point[3].y);
        cv::Point p5(landmarkinfo.landmark[i].point[4].x , landmarkinfo.landmark[i].point[4].y);
        cv::circle(image_bbox, p1, 1, cv::Scalar(0, 255, 0), -1); // 画半径为1的圆(画点�?
        cv::circle(image_bbox, p2, 1, cv::Scalar(0, 255, 0), -1);  // 画半径为1的圆(画点�?
        cv::circle(image_bbox, p3, 1, cv::Scalar(0, 255, 0), -1);  // 画半径为1的圆(画点�?
        cv::circle(image_bbox, p4, 1, cv::Scalar(0, 255, 0), -1);  // 画半径为1的圆(画点�?
        cv::circle(image_bbox, p5, 1, cv:: Scalar(0, 255, 0), -1);  // 画半径为1的圆(画点�?
    }
    cv::imwrite(save_path,image_bbox);

    return 1;
}

int FR_ImageProc_FaceDetect_Resize(cv::Mat image,cv::Mat& image_resize,STRU_ImgData_T &image_resize_data)
{   
	cv::Mat image_c;

	if(image.channels() ==1)
	{
		cv::cvtColor(image, image_c, cv::COLOR_GRAY2BGR);
	}
	else if(image.channels() ==4)
	{
		cv::cvtColor(image, image_c, cv::COLOR_RGBA2BGR);
	}
	else
	{
		image_c=image;
	}
		 	
	int neww,newh;
	if(image.cols>image.rows)
	{
		neww = 180;
		newh = 120;
	}
	else
	{
		neww = 120;
		newh = 180;
	}
	cv::resize(image_c,image_resize,cv::Size(neww, newh));

	image_resize_data.data=image_resize.ptr<unsigned char>(0); 
	image_resize_data.height=image_resize.rows;
	image_resize_data.width=image_resize.cols;
	image_resize_data.channel=image_resize.channels();
	return 0;
}


int main()
{


    for(int ii=0;ii<1;ii++)
    {
        std::cout << ii << std:: endl;
        ifstream fin( "images_xinandaxue_add.txt");
        std::string image_name;
        int n=0;
        double all_time=0;
        // fin>>image_name;
        while(fin>>image_name)
        {
            n=n+1;


            std::string img_path="./images_xinandaxue_add/"+image_name;
            std::cout <<n<< " Read from file: " << img_path <<std:: endl;
            // std::cout << " Read from file: " << img_path <<std:: endl;

            cv::Mat image;
            image= cv::imread(img_path);
            if (!image.data){ continue;}
            
            clock_t start;
            start = clock();

            STRU_ImgData_T imagedata(image.data,image.cols,image.rows,0,image.channels());
            STRU_RectInfo_T rectinfo;
            STRU_LandmarkInfo_T landmarkinfo;
            FR_FaceDetect(imagedata, rectinfo,landmarkinfo, 0);
            
 
            std::string base_dir ="";
            std::string save_path;

            
            for(int i=0;i<rectinfo.nFaceNum;i++)
            {
                STRU_Rect_T     rect=rectinfo.rects[i];
                STRU_Landmark_T landmark=landmarkinfo.landmark[i];
                STRU_Label_T    label=rectinfo.labels[i];

                int real_info;
                FR_FaceAntiSpoof(imagedata,rect,landmark,real_info);
                if (real_info==1)
                {
                    save_path = base_dir+"results_real/" + image_name;
                    FR_Show_bbox_and_landmark(image, rect, landmark, label, save_path);
                    std::cout << " Save image: " << save_path <<std:: endl;
                }
                else
                {
                    save_path = base_dir+"results_fake/" + image_name;
                    FR_Show_bbox_and_landmark(image, rect, landmark, label, save_path);
                    std::cout << " Save image: " << save_path <<std:: endl;
                }

                
            }

            if (rectinfo.nFaceNum<1){
                save_path= base_dir+"NOFACE/"+image_name;
                std::cout << n<<"NOFACE"<<save_path<< std::endl;
                cv::imwrite(save_path,image);
                }

            clock_t finish;
            finish = clock();
            all_time=double(finish - start)/1000.0;
            std::cout << "aver time:  "<<all_time <<"ms"<<std::endl;
        }
        fin.close();
    }
    return 0;

}
