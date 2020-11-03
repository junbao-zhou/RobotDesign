""" Fully Connected Layer """

import numpy as np


class FCLayer():
    def __init__(self, num_input, num_output, trainable=True):
        """
        Apply a linear transformation to the incoming data: y = Wx + b
        Args:
                num_input: size of each input sample
                num_output: size of each output sample
                actFunction: the name of the activation function such as 'relu', 'sigmoid'
                trainable: whether if this layer is trainable
        """
        self.num_input = num_input
        self.num_output = num_output
        self.trainable = trainable

        self.XavierInit()

    def forward(self, Input):

        ############################################################################
        # TODO: Put your code here
        # Apply linear transformation(Wx+b) to Input, and return results.
        # print("fc layer forward")
        self.Input = Input
        output = self.W.dot(self.Input.T) + np.array([self.b]).T
        output = output.T
        # print(f'output shape : {output.shape}')
        return output
        ############################################################################

    def backward(self, delta):
        # The delta of this layer has been calculated in the later layer.
        ############################################################################
        # TODO: Put your code here
        # Calculate the gradient using the later layer's gradient: delta
        # print("fc layer backward " + self.actFunction)
        self.grad_W = self.Input.T.dot(delta)
        self.grad_b = delta

        # print(self.grad_b.shape)

        # self.grad_W = np.mean(self.grad_W, axis=0)
        self.grad_b = np.mean(self.grad_b, axis=0)

        gradient = delta.dot(self.W.T)
        # print(f"output shape : {gradient.shape}")
        return gradient
        ############################################################################

    def XavierInit(self):
        # Initialize the weigths according to the type of activation function.

        self.W = np.random.normal(
            0, 0.5, (self.num_output, self.num_input))
        self.b = np.random.normal(0, 0.5, (self.num_output))


# f = FCLayer(10, 5)

# x = np.random.randint(0, 10, [1, 10])

# print(x)

# out = f.forward(x)

# f.backward(out)
