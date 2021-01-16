# JetsonNanoProjects

my-recognition-python: First instance of working with the Jetson Nano and image recognition. By default, uses GoogleNet and refers to the ImageNet database to classify arbitrary images specified on the command line. Not exactly a project, but a good starting point for adjusting to the Jetson Nano. 
This script will not work outside of the Jetson Nano.

What I learned:
-Basic operations from the jetson.utils and jetson.inference libraries, with use of functions such as .loadImage() to obtain the arg image, and .imageNet() to obtain the arg network. 

-the imageNet.Classify() function utilizes TensorRT to analyze the provided image, it's just a matter of printing the information that .Classify() is able to retrieve (one way is using  GetClassDesc(index) to obtain the proper classification)

Thoughts/Reflections:
This has led me to speculate on the possibility of creating a program to recognize vehicle models based on photos of them, or maybe even different cartoon characters. I tried to include an image of Spongebob which was classified as a "goblet", most likely because of database restrictions. 

This was my first time writing a program on the Jetson Nano, and I'm looking forward to working on image recognition in the future. I want to look more into making my own DL bot as opposed to working with the pretrained GoogleNet, but I want to read up a bit more on the provided resources before doing so.

=========================================================================================

my-recognition.cpp: Slightly modified version of the above program, but still the same concept overall. This was just to adjust to the syntax of C++ since I don't have a lot of experience with it, and also to allow for the usage of the image recognition program on other machines.

What I learned:
-C++ alongside the Jetson libraries can load images into uchar3 RGB formatting. I examined the Image Manipulation with Cuda page and was able to see that many API's will rely on RGB, so it's best to stick with uchar3, uchar4, float3, or float4 in many instances. Furthermore, I looked into the struct of uchar3 to further verify my understanding. The use of uchar makes sense because its a range of 0 to 255, which perfectly captures RGB values, and uchar3 accepts, namely, three such values.

-The CMakeLists.txt file serves as a Makefile to compile the project. Namely, the Jetson packages used are retrieved alongside Cuda and Qt4. I was able to see the Makefile in action, as it was able to determine two small syntax errors in the my-recognition file. I have worked with Makefiles before, but a lot of the operations used in this instance were new to me, such as target_link_libraries (links project to designated library) and find_package(simply retrieve the libraries).

Thoughts/Reflections:
It was good practice working with C++ but I need to practice a bit more with the language before I can confidently use it. I have worked with C and C# so I can't imagine things differing too much, but it is new territory working from an AI lense. Nonetheless, excited to work on some more stuff soon!


