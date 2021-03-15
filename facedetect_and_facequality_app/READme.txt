1:程序运行前，将图片路径写到images.txt;

2:人脸检测结果保存在results_facedetect.txt;
 格式为：score x1 y1 w h p1x p1y p2x p2y p3x p3y p4x p4y p5x p5y maskinfo

3：人脸质量判断结果保存在results_facequality.txt
格式为：距离边界位置  人脸大小 滚转角度 偏航角度 倾斜角度 亮度 清晰度

4：配置1文件app_config.ini 中
Facequality为-1，不进行质量判断，Facequality为1，进行质量判断；
Show=1，保存结果在mask和nomask文件夹中，Show=-1不保存结果。

5：配置文件中facedetect_models/config.ini ，可进行人脸检测阈值设置；

6：人脸质量判断 建议通行阈值为：
距离边界位置border_size>=30
人脸大小>=250
滚转角度<=15
偏航角度<=30
倾斜角度<=30
亮度最低值>=60
亮度最高值<=180
清晰度>=0.5

