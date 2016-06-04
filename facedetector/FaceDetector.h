/*
 * FaceDetector.h
 *
 *  Created on: 07/apr/2016
 *      Author: lorenzocioni
 */

#ifndef FACEDETECTOR_FACEDETECTOR_H_
#define FACEDETECTOR_FACEDETECTOR_H_

#include <vector>
#include <iostream>
#include <chrono>
#include <ctime>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "../boosting/features/Data.h"
#include "../boosting/features/HaarFeatures.h"
#include "../boosting/utils/IntegralImage.h"
#include "../boosting/ViolaJones.h"
#include "../boosting/utils/Face.h"
#include "../boosting/utils/Utils.hpp"

using namespace std;
using namespace cv;

class FaceDetector {

private:
	string positivePath;
	string negativePath;
	int detectionWindowSize;
	int scales;
	int stages;
	float delta;
	int numPositives;
	int numNegatives;
	vector<Mat> scaledImages;
	ViolaJones* boost;

public:
	FaceDetector(string trainedCascade, int scales = 12);
	FaceDetector(string positivePath, string negativePath, int stages, int numPositives, int numNegatives, int detectionWindowSize = 24);
	void train();
	vector<Face> detect(Mat img, bool showResults = false, bool showScores = false);
	void displaySelectedFeatures(Mat img);
	~FaceDetector();

};



#endif /* FACEDETECTOR_FACEDETECTOR_H_ */
