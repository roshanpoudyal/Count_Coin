#include <jni.h>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <android/log.h>
using namespace cv;
using namespace std;

extern "C"
{

JNIEXPORT jstring JNICALL
Java_com_example_roshanpoudyal_count_1coin_coin_1count_findCoins(JNIEnv *env, jobject instance) {

//JNIEXPORT void JNICALL
//Java_com_example_roshanpoudyal_count_1coin_coin_1count_findCoins(JNIEnv *env, jobject instance,
//                                                                 jlong matAddrRgba,
//                                                                 jlong matAddrGray) {
//    Mat mRgba = *(Mat *) matAddrRgba;
//    Mat mGray = *(Mat *) matAddrGray;
//
//    cvtColor(mRgba, mGray, COLOR_BGR2GRAY);
//    return void();

    return env -> NewStringUTF("This is from JNI");
}
}
