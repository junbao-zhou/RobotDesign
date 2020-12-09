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
        self.length = 512

    def __getitem__(self, index):
        if index % 2 == 0:
            ch = 'd'
            label = 0
        else:
            ch = 'p'
            label = 1
        index = int(index / 2)
        img = Image.open(
            f'./ImageRecognition/trainingset_image/{ch}_f{index % 4 + 1}.jpg')

        # print(img.size)
        # img.show()
        # print(aaa)
        width, height = (img.size[0], img.size[0]) if img.size[0] < img.size[1] else (
            img.size[1], img.size[1])   # Get dimensions

        left = (img.size[0] - width)/2
        top = (img.size[1] - height)/2
        right = (img.size[0] + width)/2
        bottom = (img.size[1] + height)/2
        img = img.crop((left, top, right, bottom))
        # img.show()
        # print(aaa)
        img = img.resize((240, 240))
        # print(transforms.ToTensor()(img))
        # print(transforms.ToTensor()(img).size())
        # exit(0)
        return my_transform(img), label

    def __len__(self):
        return self.length


train_loader = data.DataLoader(ImageSet(), batch_size=32, shuffle=True)
test_loader = data.DataLoader(ImageSet(), batch_size=1, shuffle=True)


class ConvNet(nn.Module):
    def __init__(self,):
        super(ConvNet, self).__init__()
        self.layer1 = nn.Sequential(
            # 240
            nn.Conv2d(in_channels=3, out_channels=8, kernel_size=11),
            # 230
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=10, padding=0)
            # 23
        )
        self.layer2 = nn.Sequential(
            # 23
            nn.Conv2d(in_channels=8, out_channels=16,
                      kernel_size=6),
            # 18
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=3, padding=0)
            # 6
        )
        self.layer3 = nn.Sequential(
            nn.Linear(in_features=576, out_features=64),
            nn.ReLU(),
            nn.Linear(in_features=64, out_features=2)
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
