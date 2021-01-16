# JetsonNanoProjects

my-recognition-python: First instance of working with the Jetson Nano and image recognition. By default, uses GoogleNet and refers to the ImageNet database to classify arbitrary images specified on the command line. Not exactly a project, but a good starting point for adjusting to the Jetson Nano. 
This script will not work outside of the Jetson Nano.

What I learned:
-Basic operations from the jetson.utils and jetson.inference libraries, with use of functions such as .loadImage() to obtain the arg image, and .imageNet() to obtain the arg network. 

-the imageNet.Classify() function utilizes TensorRT to analyze the provided image, it's just a matter of printing the information that .Classify() is able to retrieve (one way is using  GetClassDesc(index) to obtain the proper classification)

Thoughts/Reflections:
This has led me to speculate on the possibility of creating a program to recognize vehicle models based on photos of them, or maybe even different cartoon characters. I tried to include an image of Spongebob which was classified as a "goblet", most likely because of database restrictions. 

This was my first time writing a program on the Jetson Nano, and I'm looking forward to working on image recognition in the future. I want to look more into making my own DL bot as opposed to working with the pretrained GoogleNet, but I want to read up a bit more on the provided resources before doing so.

==================================================================================================


