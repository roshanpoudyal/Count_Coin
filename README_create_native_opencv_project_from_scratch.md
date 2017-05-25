**Important Note :**
  - _Take attention to the path delimeter symbol "/" or "\" as used in linux and windows respectively while going through the steps for develoment._
  - _For e.g.,_
    - _".../downloads/opencv-android-sdk-v3.0/sdk/..." is a linux path syntax_
    - _whereas "...\downloads\opencv-android-sdk-v3.0\sdk\..." is a windows path syntax._

## Developing native OpenCV project from scratch
_Steps to build a native android openCV project from scratch follow the following steps: **Assuming you have Android Studio installed with NDK support. Also have installed the android sdk and ndk**_

1. [Download OpenCV SDK for Android](https://sourceforge.net/projects/opencvlibrary/files/opencv-android/3.2.0/opencv-3.2.0-android-sdk.zip/download) and decompress the zip file.

2. Create New Android Studio project with :
    * Check **Include C++ Support**
    * Choose **Empty Activity**
    * In C++ Support, check **-fexceptions** and **-frtti**

3. Import OpenCV library as module
   * File > New > Import Module...
   * Choose **.../opencv-android-sdk-v3.0/sdk/java** folder.
   * Unckeck **replace jar**, **replace lib**, **create gradle-style** options.
   
4. Set the OpenCV library module up to fit your SDK, edit : `Gradle Scripts > build.gradle (Module: openCVLibrary320)`
