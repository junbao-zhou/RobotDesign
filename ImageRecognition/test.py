from optimizer import SGD
from criterion import SoftmaxCrossEntropyLossLayer
from layers import FCLayer, ReLULayer, ConvLayer, MaxPoolingLayer, ReshapeLayer
from network import Network

import numpy as np

from PIL import Image

batch_size = 1
channels = 2
learning_rate = 0.008
weight_decay = 0.005

convNet = Network()
# Build ConvNet with ConvLayer and PoolingLayer
with open('params.npy', 'rb') as f:
    conv1 = ConvLayer(in_channels=3, out_channels=6, kernel_size=11)
    conv1.W = np.load(f)
    conv1.b = np.load(f)
    convNet.add(conv1)
    convNet.add(ReLULayer())
    convNet.add(MaxPoolingLayer(kernel_size=10))
    conv2 = ConvLayer(in_channels=6, out_channels=12,
                      kernel_size=6)
    conv2.W = np.load(f)
    conv2.b = np.load(f)
    convNet.add(conv2)
    convNet.add(ReLULayer())
    convNet.add(MaxPoolingLayer(kernel_size=3))
    convNet.add(ReshapeLayer((batch_size, 12, 10, 7), (batch_size, 840)))
    fc1 = FCLayer(840, 128)
    fc1.W = np.load(f)
    fc1.b = np.load(f)
    convNet.add(fc1)
    convNet.add(ReLULayer())
    fc2 = FCLayer(128, 2)
    fc2.W = np.load(f)
    fc2.b = np.load(f)
    convNet.add(fc2)

img = Image.open('./ImageRecognition/trainingset_image/d_f1.jpg')
img = img.resize((int(img.size[0]/4), int(img.size[1]/4)))

input = np.rot90(np.rot90(np.array(img), 3, axes=(0, 2)),  axes=(1, 2))
input = np.array([input])
input = input/255
input = (input-0.5) / 0.5

output = convNet.forward(input)
print(output)
