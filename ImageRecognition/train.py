# recognize yellow duck and pikaqiu
from torch.autograd import Variable
import torch.nn.functional as F
import torch.nn as nn
import torch
import torchvision
from torchvision import datasets, transforms
import torch.utils.data as data
import matplotlib.image as pli
import matplotlib.pyplot as plt
import matplotlib as mpl
import numpy as np
from PIL import Image

my_transform = transforms.Compose(
    [transforms.ToTensor(), transforms.Normalize((0.5, 0.5, 0.5), (0.5, 0.5, 0.5))])


class ImageSet(data.Dataset):
    def __init__(self):
        self.length = 64

    def __getitem__(self, index):
        if index % 2 == 0:
            ch = 'd'
            label = 0
        else:
            ch = 'p'
            label = 1
        img = Image.open(f'./ImageRecognition/trainingset_image/d_f5.jpg')
        img = img.resize((int(img.size[0]/4), int(img.size[1]/4)))
        # print(transforms.ToTensor()(img))
        # print(transforms.ToTensor()(img).size())
        # exit(0)
        return my_transform(img), label

    def __len__(self):
        return self.length


train_loader = data.DataLoader(ImageSet(), batch_size=8, shuffle=True)
test_loader = data.DataLoader(ImageSet(), batch_size=1, shuffle=True)


class ConvNet(nn.Module):
    def __init__(self,):
        super(ConvNet, self).__init__()
        self.layer1 = nn.Sequential(
            nn.Conv2d(in_channels=3, out_channels=6, kernel_size=11),
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=10, padding=0)
        )
        self.layer2 = nn.Sequential(
            nn.Conv2d(in_channels=6, out_channels=12,
                      kernel_size=6),
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=3, padding=0)
        )
        self.layer3 = nn.Sequential(
            nn.Linear(in_features=840, out_features=128),
            nn.ReLU(),
            nn.Linear(in_features=128, out_features=2)
        )

    def forward(self, input):
        out = self.layer1(input)
        out = self.layer2(out)
        out = out.reshape(out.size(0), -1)
        out = self.layer3(out)
        return out


convNet = ConvNet()
print(convNet)

loss_func = nn.CrossEntropyLoss()
optimizer = torch.optim.Adam(convNet.parameters(), lr=0.01)


for i, (images, labels) in enumerate(train_loader):
    outputs = convNet.forward(images)
    loss = loss_func(outputs, labels)

    optimizer.zero_grad()
    loss.backward()
    optimizer.step()

    predict = torch.argmax(nn.functional.softmax(outputs, dim=1), dim=1)
    print(f"i = {i},  accuracy = {sum(labels == predict)/labels.size(0)}")

param_list = list(convNet.parameters())

for i, (images, labels) in enumerate(train_loader):
    outputs = convNet.forward(images)
    print(outputs)
    break

with open('params.npy', 'wb') as f:
    for i in param_list:
        print(i.data.numpy().shape)
        np.save(f, i.data.numpy())
