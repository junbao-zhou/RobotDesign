""" ReLU Layer """

import numpy as np


class ReLULayer():
    def __init__(self):
        """
        Applies the rectified linear unit function element-wise: relu(x) = max(x, 0)
        """
        self.trainable = False  # no parameters

    def forward(self, Input):

        ############################################################################
        # TODO: Put your code here
        # Apply ReLU activation function to Input, and return results.
        # print("relu layer forward")
        self.Input = Input
        # print(f'output shape : {Input.shape}')
        return np.maximum(Input, 0)
        ############################################################################

    def backward(self, delta):

        ############################################################################
        # TODO: Put your code here
        # Calculate the gradient using the later layer's gradient: delta
        # print("relu layer backward")

        gradient = (self.Input > 0) * 1 * delta
        # print(f"output shape : {gradient.shape}")
        return gradient
        ############################################################################


# input = np.random.randint(-10, 12, [3, 4])

# print(input)

# print(np.maximum(input, 0))

# print((input > 0) * 1)
