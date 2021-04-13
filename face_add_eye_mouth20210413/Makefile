
#LDFLAGS = -L/usr/lib -lopencv_core -lopencv_highgui
LDFLAGS = -L/home/yc/lib/opencv/ -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_world
LDFLAGS += -L/home/yc/lib -lface_cdzs
#LDFLAGS += -L/home/yc/lib -lSeetaAuthorize
#LDFLAGS += -L/home/yc/lib -lSeetaPoseEstimation600
#LDFLAGS += -L/home/yc/lib -lSeetaQualityAssessor300
#LDFLAGS += -L/home/yc/lib -lSeetaFaceAntiSpoofingX600
#LDFLAGS += -L/home/yc/lib -ltennis
LDFLAGS += -L/usr/lib/aarch64-linux-gnu/ -lMali
#LDFLAGS +=-lGL -lGLU

#demo1:demo1.cpp
#  aarch64-linux-gnu-g++  --std=c++11 -O3  -fPIC  demo1.cpp  -o $@ ${LDFLAGS} -I/home/yc/include

demo1:demo1.cpp
	aarch64-linux-gnu-g++  --std=c++11 -O3  -fPIC  demo1.cpp  -o $@ ${LDFLAGS} -I/home/yc/include

clean:
	rm demo1
 

#demon_RGB_Image:demon_RGB_Image.cpp
#	aarch64-linux-gnu-g++  --std=c++11 -O3  -fPIC  demon_RGB_Image.cpp  -o $@ ${LDFLAGS}
 
#clean:
#	rm demon_RGB_Image
