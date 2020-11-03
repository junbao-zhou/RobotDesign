""" Softmax Cross-Entropy Loss Layer """

import numpy as np

# a small number to prevent dividing by zero, maybe useful for you
EPS = 1e-11


def softmax(input):
    input = input - np.array([np.max(input, axis=1)]).T
    input = np.exp(input)
    sum = input.dot(np.ones([input.shape[1], 1]))
    p = input / sum
    return p


class SoftmaxCrossEntropyLossLayer():
    def __init__(self):
        self.acc = 0.
        self.loss = np.zeros(1, dtype='f')

    def forward(self, logit, gt):
        """
        Inputs: (minibatch)
        - logit: forward results from the last FCLayer, shape(batch_size, 10)
        - gt: the ground truth label, shape(batch_size, 1)
    """

        ############################################################################
        # TODO: Put your code here
        # Calculate the average accuracy and loss over the minibatch, and
        # store in self.acc and self.loss respectively.
        # Only return the self.loss, self.acc will be used in solver.py.
        # print("softmax cross entropy loss forward")

        self.softmax_result = softmax(logit)
        max_pos = np.argmax(self.softmax_result, axis=1)
        gt_max_pos = np.argmax(gt, axis=1)
        # print(gt)
        # print(max_pos)
        correct = (gt_max_pos.flatten() == max_pos)
        # print(correct)
        self.acc = sum(correct) / gt.shape[0]

        self.onehot = gt

        choose = self.softmax_result[np.arange(
            gt_max_pos.shape[0]), gt_max_pos.flatten()]
        log = np.log(choose)
        self.loss = -sum(log) / gt_max_pos.shape[0]
        return self.loss
        ############################################################################

    def backward(self):

        ############################################################################
        # TODO: Put your code here
        # Calculate and return the gradient (have the same shape as logit)
        # print("softmax cross entropy loss backward")
        gradient = (self.softmax_result - self.onehot) / \
            self.softmax_result.shape[0]
        # print(f"output shape : {gradient.shape}")
        return gradient
        ############################################################################


# x = np.random.randint(0, 128, [16, 5])

# label = np.zeros(x.shape)

# label[np.arange(label.shape[0]), np.random.randint(
#     0, label.shape[1], [1, label.shape[0]])] = 1

# # print(label)

# s = SoftmaxCrossEntropyLossLayer()

# s.forward(x, label)
# s.backward()
# print(s.acc)
