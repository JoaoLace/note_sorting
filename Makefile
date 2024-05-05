main:
	g++ -std=c++17 -Wall -I/usr/include/opencv4 main.cpp -o main -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs
	./main