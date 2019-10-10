// DriveLabel.cpp : Defines the entry point for the console application.
// some

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <ctime>
#include <iostream>
#include <vector>
#include <cstdarg>
using namespace std;

int writeLog(char *fmt, ...)
{
	int n = 0;
	FILE *fp = NULL;
	va_list args = NULL;
	char sprint_buf[1024] = { 0 };
	if (fopen_s(&fp, "log.txt", "a+") != 0)
		return -1;
	va_start(args, fmt);
	fprintf(fp, "-------------------------\n");
	n = vfprintf(fp, fmt, args);
	fprintf(fp, "\n-------------------------\n");
	va_end(args);
	fclose(fp);
	return n;
}

int readFrame(cv::VideoCapture &cap, cv::Mat &img) {
	assert(cap.isOpened());
	int frames = 0;
	if (cap.grab()) {
		frames += 1;
		if (cap.grab()) {
			frames += 1;
			cap.retrieve(img);
		}
	}
	return frames;
}

// prog.exe rtsp://.... oblique.model [gpuID threshold 10 10 10 10 101 101 101 101]
int main(int argc, char** argv)
{
	if (argc == 1) {
		std::cout << "DriveLabel.exe videostream [left top width height threshold]" << std::endl;
		std::cout << "For example: DriveLabel.exe d:\\sth.mp4" << std::endl;
	}
	cv::Mat img, gray, imgThres, labels, seeLabels, stats, centroids;
	int frame_count = 0, frame_cur = 0, label_num;
	int threshold = 141;
	cv::VideoCapture cap;
	cv::VideoWriter cvw;
	cv::Rect myROI(10, 500, 300, 580);
	if (argc > 6) {
		myROI.x = atol(argv[2]);
		myROI.y = atol(argv[3]);
		myROI.width = atol(argv[4]);
		myROI.height = atol(argv[5]);
		threshold = atol(argv[6]);
	}
	cvw.open("test.mp4", CV_FOURCC('M', 'J', 'P', 'G'), 25, cv::Size(300, 580));
	if (!cap.open(argv[1])) {
		//cout << "video stream failed! please check it!" << endl;
		time_t tm = time(NULL);
		char tmBuf[50];
		ctime_s(tmBuf, 50, &tm);
		writeLog("%s \n %s video stream failed! please check it!", argv[1], tmBuf);
		return -1;
	}
	while (cap.isOpened()) {
		frame_cur = readFrame(cap, img);
		if (frame_cur == 0 || img.empty()) {
			time_t tm = time(NULL);
			char tmBuf[50];
			ctime_s(tmBuf, 50, &tm);
			writeLog("%s \n %s read failed! frames:%d, %d", argv[1], tmBuf, frame_cur, img.empty());
			break;
		}
		clock_t dct = clock();
		img = img(myROI);
		cv::cvtColor(img, gray, CV_BGR2GRAY);
		//gray = gray(myROI);
		cv::threshold(gray, imgThres, threshold, 255, CV_THRESH_BINARY);
		//cv::adaptiveThreshold(gray, imgThres, 255, CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY, 125, 5);
		//label_num = cv::connectedComponents(imgThres, labels);
		label_num = cv::connectedComponentsWithStats(imgThres, labels, stats, centroids);
		//cv::normalize(labels, seeLabels, 0, 255, cv::NORM_MINMAX, CV_8U);
		for (int i = 0; i < label_num; i++) {
			int width = stats.at<int>(i, cv::CC_STAT_WIDTH);
			int height = stats.at<int>(i, cv::CC_STAT_HEIGHT);
			int area = stats.at<int>(i, cv::CC_STAT_AREA);
			if (area > 1000 && area < 3000) {
				double iou = area / (double)(width*height);
				cout << "IOU" << iou << endl;
				double wh = width / (double)(height);
				cout << "W/H" << wh << endl;
				if (iou > 0.5 && wh < 0.5) {
					cout << "(" << stats.at<int>(i, cv::CC_STAT_LEFT) << " x " << stats.at<int>(i, cv::CC_STAT_TOP) << ")(" << width << " x " << height << ")" << endl;
					cv::Rect dect(stats.at<int>(i, cv::CC_STAT_LEFT), stats.at<int>(i, cv::CC_STAT_TOP), width, height);
					cv::rectangle(img, dect, cv::Scalar(255, 255, 255), 3);
					cv::Mat retImg = img(dect);
					char file[256];
					sprintf_s(file, "%d-%d.jpg", frame_count, i);
					cv::imwrite(file, retImg);
				}
			}
		}
		dct = clock() - dct;
		dct = dct * 1000 / CLOCKS_PER_SEC;
		// Print the detection results. 
		cout << "Time: " << dct << "Frame: " << frame_count << " " << "score " << label_num << endl;
		frame_count += frame_cur;
		cvw << img;
		cv::imshow("Img", img);
		//if (cv::waitKey(40) >= 0)
			//break;
		cv::waitKey(40);
	}
	if (cap.isOpened()) {
		cap.release();
	}
	cvw.release();
	return 0;
}


