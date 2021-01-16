#include <jetson-inference/imageNet.h>
#include <jetson-utils/loadImage.h>

//Parse and retrieve image filename from array of command line args
//If less than two args, print usage message

int main(int argc, char**argv){
	if(argc<2){
		printf("my-recognition: expected image filename as argument\n");
		printf("example usage: ./my-recognition my_image.jpg\n");
		return 0;
	}

	const char* imgFilename = argv[1];


//Step 2: load image(s) from disk
	uchar3* imgPtr = NULL;
	int imgWidth = 0;
	int imgHeight = 0;

//load image from disk as unsigned char3 RGB; char3 reads in three unsigned chars as x,y,z
//Each pixel = 24 bits
//Pixel type can be changed around as well: uchar4, float3, float4 all possible; bit depth changes

	if (!loadImage(imgFilename, &imgPtr, &imgWidth, &imgHeight)){
		printf("failed to load image '%s'\n", imgFilename);
		return 0;
	}

//Step 3: load img recognition network w/ TensorRT
//ResNet-18 also usable, replace in the field where GOOGLENET is entered
	imageNet* net = imageNet::Create(imageNet::GOOGLENET);
	if (!net){
		printf("failed to load image recognition network\n");
		return 0;
	}

//Step 4: classifying image using desired recognition network
	float confidence = 0.0;
	const int classIndex = net->Classify(imgPtr, imgWidth, imgHeight, &confidence);

//Step 5: Printing results
	if(classIndex >= 0){
		const char* classDescrip = net->GetClassDesc(classIndex);
		printf("image is recognized as '%s' (class #%i) with %f%% confidence\n",
		classDescrip, classIndex, confidence * 100.0f);
	}
	else{
		printf("failed to classify image\n");
	}

//Step 6: free used memory and end program 
	delete net;
	return 0;
}
	



