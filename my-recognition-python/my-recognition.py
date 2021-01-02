#!/usr/bin/python3

import jetson.inference
import jetson.utils

import argparse

#usage: my-recognition.py [-h] [--network NETWORK] filename

parser = argparse.ArgumentParser()
parser.add_argument("filename", type=str, help="filename of image to process")
parser.add_argument("--network", type=str, default="googlenet", help="model to use, can be: googlenet, resnet-18, ect., see --help for others")
opt = parser.parse_args()

#load the image and specify the model to be used
img = jetson.utils.loadImage(opt.filename)

net = jetson.inference.imageNet(opt.network)

#Classify() index and floating-point returns are assigned, respectively
class_idx, confidence = net.Classify(img)

#Using the returned index, find the appropriate class desc
class_desc = net.GetClassDesc(class_idx)

print("Image is recognized as '{:s}' (class #{:d}) with {:f}% confidence".format(class_desc, class_idx, confidence*100))



