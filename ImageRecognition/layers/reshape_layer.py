"""Reshape layer"""
from numpy import *


class ReshapeLayer():
    def __init__(self, input_shape, output_shape):
        """
        Apply the reshape operation to the incoming data
        Args:
                num_input: size of each input sample
                num_output: size of each output sample
        """
        self.input_shape = input_shape
        self.output_shape = output_shape
        self.trainable = False

    def forward(self, Input):
        # TODO: put your code here
        # print("reshape layer forward")
        # print(Input.shape)
        output = Input.reshape(self.output_shape)
        # print(f'output shape : {output.shape}')
        return output

    def backward(self, delta):
        # TODO: put your code here
        # print("reshape layer backward")
        gradient = delta.reshape(self.input_shape)
        # print(f"output shape : {gradient.shape}")
        return gradient


# size1 = (16, 2, 3, 4)
# size2 = (16, 24)
# r = ReshapeLayer(size1, size2)
# x = random.randint(0, 10, size1)
# print(x)
# out = r.forward(x)
# print(out)
# back = r.backward(out)
# print(back)
