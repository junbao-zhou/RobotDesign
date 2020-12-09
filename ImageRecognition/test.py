from optimizer import SGD
from criterion import SoftmaxCrossEntropyLossLayer
from layers import FCLayer, ReLULayer, ConvLayer, MaxPoolingLayer, ReshapeLayer
from network import Network
from criterion import *

import numpy as np

from PIL import Image


def softmax(input):
    input = input - np.array([np.max(input, axis=1)]).T
    input = np.exp(input)
    sum = input.dot(np.ones([input.shape[1], 1]))
    p = input / sum
    return p


batch_size = 1
channels = 2
learning_rate = 0.008
weight_decay = 0.005

convNet = Network()
# Build ConvNet with ConvLayer and PoolingLayer
with open('params.npy', 'rb') as f:
    conv1 = ConvLayer(in_channels=3, out_channels=8, kernel_size=11)
    conv1.W = np.load(f)
    conv1.b = np.load(f)
    convNet.add(conv1)
    convNet.add(ReLULayer())
    convNet.add(MaxPoolingLayer(kernel_size=10))
    conv2 = ConvLayer(in_channels=8, out_channels=16,
                      kernel_size=6)
    conv2.W = np.load(f)
    conv2.b = np.load(f)
    convNet.add(conv2)
    convNet.add(ReLULayer())
    convNet.add(MaxPoolingLayer(kernel_size=3))
    convNet.add(ReshapeLayer((batch_size, 16, 6, 6), (batch_size, 576)))
    fc1 = FCLayer(576, 64)
    fc1.W = np.load(f)
    fc1.b = np.load(f)
    convNet.add(fc1)
    convNet.add(ReLULayer())
    fc2 = FCLayer(64, 2)
    fc2.W = np.load(f)
    fc2.b = np.load(f)
    convNet.add(fc2)

img = Image.open('./ImageRecognition/trainingset_image/d_f18.jpg')

width, height = (img.size[0], img.size[0]) if img.size[0] < img.size[1] else (
    img.size[1], img.size[1])   # Get dimensions

left = (img.size[0] - width)/2
top = (img.size[1] - height)/2
right = (img.size[0] + width)/2
bottom = (img.size[1] + height)/2
img = img.crop((left,top,right,bottom))
img = img.resize((240, 240))

input = np.rot90(np.rot90(np.array(img), 3, axes=(0, 2)),  axes=(1, 2))
input = np.array([input])
input = input/255
input = (input-0.5) / 0.5

output = convNet.forward(input)
print(output)
output = softmax(output)
print(output)
output = np.argmax(output, axis=1)
print(output)
