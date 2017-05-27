# coinCount
Android Application :

#app idea : 
  * Problem definition : It is boring to count the coins by myself.
  * Possible Solution : <br> 
        Develop an application that can : <br>
          > Input _ Take image of coin placed on a (possibly) flat surface like table. <br>
          > Processing _ Search for coins in the image, most probably via image recognition algorithm. <br>
                       _ Sort out how many different types of coins are there and how many of each type are there via. appropriate feature
                          extraction. <br>
          > Output _ Give total count of different types of coin in numbers.
          
          
# Developing native OpenCV project from scratch:
   **Important Note before starting the steps:**
  - _Take attention to the path delimeter symbol "/" or "\" as used in linux and windows respectively while going through the steps for develoment._
  - _For e.g.,_
    - _".../downloads/opencv-android-sdk-v3.0/sdk/..." is a linux path syntax_
    - _whereas "...\downloads\opencv-android-sdk-v3.0\sdk\..." is a windows path syntax._

_Now, the steps to build a native android openCV project from scratch follow the following steps: **Assuming you have Android Studio installed with NDK support. Also have installed the android sdk and ndk**_

1. [Download OpenCV SDK for Android](https://sourceforge.net/projects/opencvlibrary/files/opencv-android/3.2.0/opencv-3.2.0-android-sdk.zip/download) and decompress the zip file.

2. Create New Android Studio project with :
    * Check **Include C++ Support**
    * Choose **Empty Activity**
    * In C++ Support, check **-fexceptions** and **-frtti**

3. Import OpenCV library as module
   * File > New > Import Module...
   * Choose **.../opencv-android-sdk-v3.0/sdk/java** folder.
   * Unckeck **replace jar**, **replace lib**, **create gradle-style** options.
   
4. Make the gradle settings of `OpenCV library module` same as `your project app module`, so as to fit the SDK of your project module app, i.e., edit : `Gradle Scripts > build.gradle (Module: openCVLibrary320)`. This means ** make the contents in the code block below match in `Gradle Scripts > build.gradle (Module: openCVLibrary320)` and `Gradle Scripts > build.gradle (Module: app)`**, `build.gradle` files.
    ```java
        compileSdkVersion 25 
        buildToolsVersion "25.0.2" 
        defaultConfig { 
            minSdkVersion 19
            targetSdkVersion 25
        } 
     ```

5. Add OpenCV module dependency in your app module, goto :
   `File` > `Project structure` > `Module:app (in the left vertical menu)` > `Dependencies tab` > `Add new module dependency - click +       (add) symbol and select Module Dependency option` > `choose OpenCV library module`
   
6. Copy `libs` directory from the path `PATH_TO_YOUR_OPENCV_SDK_DOWNLOAD/sdk/native` to `app/src/main` in your project folder and rename the copied folder to `jniLibs`.

7. Set `build.gradle (Module:app)` script like this:
    * Add `abiFilters` : make sure the code chunk looks exactly like this (this `externalNativeBuild` code block is inside        `defaultConfig` code block):
    ```java
       externalNativeBuild {
        cmake{
          cppFlags "-frtti -fexceptions"
          abiFilters 'x86', 'x86_64', 'armeabi', 'armeabi-v7a', 'arm64-v8a', 'mips', 'mips64'
        }
       } 
    ```
    
    * Set the `sourceSets` source directory location of `jniLibs` to this directory : `app/src/main/jniLibs` (as a result of step 6):
      ```java
      sourceSets{
        main{
            jniLibs.srcDirs = ['src/main/jniLibs']
        }
      }
      ```
     * The `build.gradle (Module:app)` script should look similar to 
       [this](https://github.com/roshanpoudyal/Count_Coin/blob/master/app/build.gradle) now. Some values may vary according to your            project name, activity name, sdk versions used, opencv module version etc. which may be project specific values.
       
8. Configure the `CMakeLists.txt` files in `External Build Files` with:
   * After `cmake_minimum_required(VERSION 3.4.1)` add the following:
     ```
     include_directories(C:/path_to_your_project/opencv-3.2.0-android-sdk/OpenCV-android-sdk/sdk/native/jni/include)
     add_library( lib_opencv SHARED IMPORTED )
     set_target_properties(lib_opencv PROPERTIES IMPORTED_LOCATION                ${CMAKE_CURRENT_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libopencv_java3.so)
     ```
     **Note:** 
       - make sure to correct the path syntax when you are working in linux, since above path syntax is for when working on windows              machine.
       - `lib_opencv` used in above code block will be made significant in the step below.
     
   * At the end of file add `lib_opencv` to `target_link_libraries` and the code block at the end of file looks like:
     ```
     target_link_libraries( # Specifies the target library.
                       native-lib
                       lib_opencv
                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )
     ```
     
9. In the `AndroidManifest.xml` file grant permissions for the app to use `camera`, add the following before `<application>` tag starts:
    ```xml
    <uses-permission android:name="android.permission.CAMERA"/>
    <uses-feature android:name="android.hardware.camera"/>
    <uses-feature android:name="android.hardware.camera.autofocus"/>
    <uses-feature android:name="android.hardware.camera.front"/>
    <uses-feature android:name="android.hardware.camera.front.autofocus"/>
    ```
    * The `AndroidManifest.xml` file looks similar to       [this]https://github.com/roshanpoudyal/Count_Coin/blob/master/app/src/main/AndroidManifest.xml) now.
          
# References :
   * http://opencv.org/ : OpenCV is released under a BSD license and hence it’s free for both academic and commercial use. It has C++, C, Python and Java interfaces and supports Windows, Linux, Mac OS, iOS and Android. OpenCV was designed for computational efficiency and with a strong focus on real-time applications. Written in optimized C/C++, the library can take advantage of multi-core processing. Enabled with OpenCL, it can take advantage of the hardware acceleration of the underlying heterogeneous compute platform.
   Since 2010 OpenCV was ported to the Android environment, it allows to use the full power of the library in mobile applications development. http://opencv.org/platforms/
      
   * [OpenCV programming related books](http://opencv.org/books.html)
   
   * [See this from mit lecture on " Visual Object recognition "]( https://www.youtube.com/watch?v=gvmfbePC2pc&feature=youtu.be&list=PLnvKubj2-I2LhIibS8TOGC42xsD3-liux )
   
   * [Nice tutorial on vision app development](https://www.youtube.com/playlist?list=PL6v5F68v1ZZzTDq8VI9Jcmb0J99WRrYn4")
   
   * [Simple tutorial on beginning , android ndk](https://code.tutsplus.com/tutorials/how-to-get-started-with-androids-native-development-kit--cms-27605)
   
   * [How to create the native OpenCV project from scratch](https://github.com/leadrien/opencv_native_androidstudio/blob/master/README.md#how-to-create-the-native-opencv-project-from-scratch)
