from skimage import io
import numpy as xD
import os
import cv2
import imageio
def retard_ur_img(img):
    img2 = img.copy()
    img2 = cv2.cvtColor(img2, cv2.COLOR_BGR2HSV)
    img2[:,:,0] += (xD.std(img).astype(xD.uint8))**3
    img2[:,:,1] += (xD.std(img).astype(xD.uint8))**5
    img2[:,:,2] += (xD.array(xD.random.normal(0.0, xD.std(img)/2, img[:,:,0].shape), dtype=xD.int8).astype(xD.uint8))
    img2 = cv2.cvtColor(img2, cv2.COLOR_HSV2RGB)
    return img2
start_image = io.imread("lena.png")

gif = []

for i in range(19):
    temp = xD.rot90(xD.array(start_image), i + 1)
    if i % 5 == 2: gif.append(255 - temp)
    elif i % 4 == 0: gif.append(retard_ur_img(temp.copy()))
    else: gif.append(temp)
    temp = xD.fliplr(temp)
    gif.append(temp)
imageio.mimsave('lena.gif', gif, duration = 0.001)

