# -*- encoding: utf-8 -*-

import numpy as np
import scipy.signal

# if you implement ConvLayer by convolve function, you will use the following code.
from scipy.signal import fftconvolve as convolve


class ConvLayer():
    """
    2D convolutional layer.
    This layer creates a convolution kernel that is convolved with the layer
    input to produce a tensor of outputs.
    Arguments:
            in_channels: Integer, the channels number of input.
            out_channels: Integer, the number of out_channels in the convolution.
            kernel_size: Integer, specifying the height and width of the 2D convolution window (height==width in this case).
            pad: Integer, the size of padding area.
            trainable: Boolean, whether this layer is trainable.
    """

    def __init__(self, in_channels,
                 out_channels,
                 kernel_size,
                 pad=0,
                 trainable=True):
        self.in_channels = in_channels
        self.out_channels = out_channels
        self.kernel_size = kernel_size
        self.pad = pad
        assert pad < kernel_size, "pad should be less than kernel_size"
        self.trainable = trainable

        self.XavierInit()

        self.grad_W = np.zeros_like(self.W)
        self.grad_b = np.zeros_like(self.b)

    def XavierInit(self):
        raw_std = (2 / (self.in_channels + self.out_channels))**0.5
        init_std = raw_std * (2**0.5)

        self.W = np.random.normal(
            0, init_std, (self.out_channels, self.in_channels, self.kernel_size, self.kernel_size))
        self.b = np.random.normal(0, init_std, (self.out_channels,))

    def forward(self, Input):
        '''
        forward method: perform convolution operation on the input.
        Agrs:
                Input: A batch of images, shape-(batch_size, channels, height, width)
        '''
        ############################################################################
        # TODO: Put your code here
        # Apply convolution operation to Input, and return results.
        # Tips: you can use np.pad() to deal with padding.
        # print("conv layer forward")
        self.Input = Input
        # print(f'input shape : {Input.shape}')
        input_after_pad = np.pad(
            Input, ((0,), (0,), (self.pad,), (self.pad,)), mode='constant', constant_values=0)

        input_after_pad_stride = np.lib.stride_tricks.as_strided(input_after_pad, shape=(
            input_after_pad.shape[0], input_after_pad.shape[1], input_after_pad.shape[2]-self.kernel_size+1, input_after_pad.shape[3]-self.kernel_size+1, self.kernel_size, self.kernel_size),
            strides=input_after_pad.strides+(input_after_pad.strides[2], input_after_pad.strides[3]))

        output = np.einsum('bchwij,fcij->bfhw', input_after_pad_stride, self.W)
        output += np.einsum('bfhw,f->bfhw', np.ones(output.shape), self.b)

        # print(f'output shape : {output.shape}')
        return output
        ############################################################################

    def backward(self, delta):
        '''
        backward method: perform back-propagation operation on weights and biases.
        Args:
                delta: Local sensitivity, shape-(batch_size, out_channels, output_height, output_width)
        Return:
                delta of previous layer
        '''
        ############################################################################
        # TODO: Put your code here
        # Calculate self.self.grad_W, self.grad_b, and return the new delta.

        # print("conv layer backward")
        self.grad_W = np.zeros((delta.shape[0],)+self.W.shape)
        input_after_pad = np.pad(
            self.Input, ((0,), (0,), (self.pad,), (self.pad,)), mode='constant', constant_values=0)

        input_after_pad_stride = np.lib.stride_tricks.as_strided(input_after_pad, shape=(
            input_after_pad.shape[0], input_after_pad.shape[1], input_after_pad.shape[2]-delta.shape[2]+1, input_after_pad.shape[3]-delta.shape[3]+1, delta.shape[2], delta.shape[3]),
            strides=input_after_pad.strides+(input_after_pad.strides[2], input_after_pad.strides[3]))

        # for batch in range(self.grad_W.shape[0]):
        #     for filt in range(self.grad_W.shape[1]):
        #         for channel in range(self.grad_W.shape[2]):
        #             self.grad_W[batch, filt, channel] = scipy.signal.correlate2d(
        #                 input_after_pad[batch, channel], delta[batch, filt], 'valid')
        self.grad_W = np.einsum('bchwij,bfij->bfchw',
                                input_after_pad_stride, delta)
        self.grad_W = np.mean(self.grad_W, axis=0)

        # self.grad_b = np.zeros((delta.shape[0],)+self.b.shape)

        # for batch in range(self.grad_W.shape[0]):
        #     for filt in range(self.grad_W.shape[1]):
        #         self.grad_b[batch, filt] = np.sum(
        #             delta[batch, filt, :, :], axis=None)
        # self.grad_b = np.einsum('bfij->bf', delta)
        # self.grad_b = np.mean(self.grad_b, axis=0)
        # # print(self.grad_b.shape)

        grandient_input_pad = np.zeros([self.Input.shape[0], self.Input.shape[1],
                                        self.Input.shape[2] + 2*self.pad,
                                        self.Input.shape[3] + 2*self.pad])
        for batch in range(grandient_input_pad.shape[0]):
            for filt in range(self.out_channels):
                for channel in range(self.in_channels):
                    grandient_input_pad[batch, channel] += scipy.signal.convolve2d(
                        delta[batch, filt], np.rot90(self.W[filt, channel], 0), 'full')

        # rot = np.rot90(self.W, 2, axes=(2, 3))
        # # rot = self.W
        # delta_pad = np.pad(delta, ((0,), (0,), (self.kernel_size-1,),
        #                            (self.kernel_size-1,)), mode='constant', constant_values=0)
        # delta_pad_stride = np.lib.stride_tricks.as_strided(delta_pad, shape=(
        #     delta_pad.shape[0], delta_pad.shape[1], delta_pad.shape[2]-rot.shape[2]+1, delta_pad.shape[3]-rot.shape[3]+1, rot.shape[2], rot.shape[3]),
        #     strides=delta_pad.strides+(delta_pad.strides[2], delta_pad.strides[3]))
        # # print(rot)
        # # print(delta_pad_stride[0])

        # grandient_input_pad = np.einsum(
        #     'bfhwij,fcij->bchw', delta_pad_stride, rot)

        grandient_input = grandient_input_pad[:, :, self.pad:self.pad +
                                              self.Input.shape[2], self.pad:self.pad+self.Input.shape[3]]
        # print(f"output shape : {grandient_input.shape}")
        return grandient_input
        ############################################################################


# layer = ConvLayer(2, 3, 3, 1)

# layer.W = np.array([[[[0, 0, 1],
#                       [0, 1, 0],
#                       [0, 0, 1]],

#                      [[1, 1, 0],
#                       [0, 1, 0],
#                       [0, 0, 1]]],


#                     [[[0, 0, 1],
#                       [0, 1, 0],
#                         [1, 1, 0]],

#                      [[1, 0, 0],
#                         [0, 1, 1],
#                         [0, 0, 1]]],


#                     [[[0, 1, 1],
#                       [1, 1, 1],
#                         [0, 0, 1]],

#                      [[1, 1, 1],
#                         [0, 1, 0],
#                         [1, 0, 1]]]]
#                    )
# layer.b = np.array([1, 0, 0])
# # print(layer.W)
# # print(layer.b)

# Input = np.array([[[[7, 2, 0, 7, 9, 7],
#                     [0, 5, 7, 1, 4, 8],
#                     [7, 2, 3, 7, 5, 3],
#                     [8, 2, 7, 1, 8, 6],
#                     [8, 0, 8, 4, 6, 6]],

#                    [[7, 5, 9, 6, 1, 1],
#                     [9, 9, 8, 6, 6, 7],
#                     [2, 3, 6, 0, 5, 2],
#                     [9, 1, 6, 8, 9, 8],
#                     [5, 6, 5, 8, 3, 6]]],


#                   [[[1, 5, 7, 8, 9, 7],
#                     [2, 1, 6, 2, 1, 0],
#                       [0, 9, 5, 5, 8, 7],
#                       [3, 4, 8, 1, 8, 2],
#                       [4, 2, 8, 6, 6, 2]],

#                    [[6, 9, 0, 6, 2, 6],
#                       [2, 6, 1, 4, 4, 6],
#                       [0, 0, 0, 9, 9, 8],
#                       [1, 1, 2, 6, 9, 1],
#                       [0, 7, 3, 3, 9, 0]]]])

# out = layer.forward(Input)

# print(out[0])

# g = layer.backward(out)
# print(g[0])

# Input = np.random.randint(0, 64, [3, 4, 8, 8])
# print(Input)
# print()
# input_after_pad = np.pad(
#     Input, ((0,), (0,), (2,), (2,)), mode='constant', constant_values=0)
# print(input_after_pad)
# print()


# Input = np.random.randint(0, 10, [3, 5, 6])

# print(Input)

# out = np.random.randint(0, 2, [3, 2, 2])

# print(out)

# Input = np.lib.stride_tricks.as_strided(Input, shape=(
#     Input.shape[0], Input.shape[1]-out.shape[1]+1, Input.shape[2]-out.shape[2]+1, out.shape[1], out.shape[2]), strides=Input.strides+(Input.strides[1], Input.strides[2]))

# # out = np.zeros((6,) + Input.shape)
# # print(Input)


# o = np.einsum('klmij,kij->klm', Input, out)

# print(o)

# input = np.ones([3, 4])
# o = np.random.randint(0, 9, [4])
# print(input)
# print(o)
# print(np.einsum('ki->k', input))
