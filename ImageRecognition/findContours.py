import matplotlib.pyplot as plt
import cv2
import sys
import numpy as np


def detect_pokemon(file_path: str):
    image = cv2.imread(file_path)

    y_bound = (int(image.shape[0]*0.5), int(image.shape[0]*0.87))
    x_bound = (int(image.shape[1]*0.2), int(image.shape[1]*0.8))

    crop_img = image[y_bound[0]:y_bound[1], x_bound[0]:x_bound[1], :]

    # cv2.imshow('i', image)

    lower = np.array([12, 140, 50], dtype='uint8')
    upper = np.array([108, 205, 130], dtype='uint8')
    # find the colors within the specified boundaries and apply
    # the mask
    mask = cv2.inRange(crop_img, lower, upper)
    single_color = cv2.bitwise_and(crop_img, crop_img, mask=mask)
    gray = cv2.cvtColor(single_color, cv2.COLOR_BGR2GRAY)
    ret, thresh = cv2.threshold(gray, 3, 255, 0)

    # contours, hierarchy = cv2.findContours(
    #	 thresh, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    # max_cont = np.zeros((1, 1, 2))
    # for cont in contours:
    #	 if cont.shape[0] > max_cont.shape[0]:
    #		 max_cont = cont
    # cv2.drawContours(crop_img, max_cont, -1, (0, 0, 255), 3)

    edges = cv2.Canny(thresh, 50, 150)
    minLineLength = 90
    maxLineGap = 50
    lines = cv2.HoughLinesP(edges, rho=1, theta=np.pi/180, threshold=62,
                            minLineLength=minLineLength, maxLineGap=maxLineGap)

    left_point = (1000, 0)
    right_point = (0, 0)
    for line in lines:
        print(line)
        for x1, y1, x2, y2 in line:
            k = (y2 - y1) / (x2-x1)
            if np.abs(k) > 1:
                continue
            if x1 < left_point[0]:
                left_point = (x1, y1)
            if x2 < left_point[0]:
                left_point = (x2, y2)
            if x1 > right_point[0]:
                right_point = (x1, y1)
            if x2 > right_point[0]:
                right_point = (x2, y2)
            cv2.line(crop_img, (x1, y1), (x2, y2), (0, 0, 255), 2)

    cv2.line(crop_img, left_point, right_point, (255, 0, 0), 2)
    k = (left_point[1] - right_point[1]) / (left_point[0] - right_point[0])
    print(k)
    line_mid = (int(0.5 * (left_point[0] + right_point[0])),
                int(0.5 * (left_point[1] + right_point[1])))
    square_mid = (x_bound[0] + line_mid[0] + int(90 * k),
                  y_bound[0] + line_mid[1] - 90)

    point1 = np.array(square_mid) - 32
    point2 = np.array(square_mid) + 32
    cv2.rectangle(image, tuple(point1), tuple(point2), (255, 0, 0))
    output_img = image[point1[1]:point2[1], point1[0]:point2[0], :]
    # cv2.imwrite(f'{file_path}_.jpg', output_img)

    plt.imshow(cv2.cvtColor(image, cv2.COLOR_BGR2RGB))
    # plt.imshow(thresh)
    # print(max_cont.shape)
    plt.show()


for label in range(0, 1):
    for index in range(27, 28):
        detect_pokemon(f'{sys.path[0]}/trainingset_image/{label}_{index}.jpg')
