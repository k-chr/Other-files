import skimage as sk
import numpy as np
import os
import matplotlib.pyplot as plt
import cv2
import sys as kys
import imageio
from skimage.transform import rescale, resize, downscale_local_mean
import random
def crop(img):
    height, width = img.shape[:2]
    if height == width: return img
    dif = height - width if height > width else width - height
    heh = False if height > width else True
    newImage = img[dif//2:height + dif//2 - dif,:,:] if heh == False else img[:,dif//2:width + dif//2 - dif,:]
    return newImage
def find_nearest(n, p):
    while p%n != 0:
        p= p+1
    return p        
def bake_potato(img):
    img = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
    temp_img = img.copy()
    temp_img[:,:,0] += (np.std(img[:,:,0])**2).astype(np.uint8)
    temp_img[:,:,1] += ((np.std(img[:,:,2]))**2).astype(np.uint8)
    temp_img[:,:,2] = (np.std(img[:,:,2]**900).astype(np.uint8))
    img = cv2.cvtColor(temp_img, cv2.COLOR_HSV2BGR)
    return img
def shuffle_channels(img):
    imgcopy = img.copy()
    choice = np.random.randint(0, 4)
    img[:,:,1] = imgcopy[:,:,choice] if choice < 3 else 0 if choice == 3 else 255 - imgcopy[:,:,choice] 
    choice = np.random.randint(0, 4)
    img[:,:,2] = imgcopy[:,:,choice] if choice < 3 else 0 if choice == 3 else 255 - imgcopy[:,:,choice] 
    choice = np.random.randint(0, 4)
    img[:,:,0] = imgcopy[:,:,choice] if choice < 3 else 0 if choice == 3 else 255 - imgcopy[:,:,choice] 
    return img
image = cv2.imread("lena.png")
new_image = crop(image.copy())
pieces = int(input("input a number: "))
if pieces <= 0 or np.sqrt(pieces) - int(np.sqrt(pieces)) != 0: kys.exit()
yabadabadu = np.sqrt(pieces)
newWH = find_nearest(yabadabadu, new_image.shape[0])
coords_list = []
new_one = rescale(new_image, newWH/new_image.shape[0])
cv2.imshow("$$",new_one)
step = int(newWH/yabadabadu)
gif = []
for i in range(0,new_one.shape[0], step):
    for j in range(0,new_one.shape[1], step):
        coords_list.append(new_one[i:(i + step),j:(j+step),:])
for j in range(15):
    oogaabooga = coords_list.copy()
    np.random.shuffle(oogaabooga)
    for i in range(pieces):
        oogaabooga[i] = np.rot90(oogaabooga[i], k = np.random.randint(0, 3))
    for i in range(pieces):
        imgcopy = oogaabooga[i].copy()
        XD = np.random.randint(0,1)
        oogaabooga[i] = bake_potato(imgcopy) if XD == 1 else shuffle_channels(imgcopy)
    list1 = []
    list2 = []
    for i in range(pieces):
        if  i% yabadabadu == yabadabadu - 1:
            list1.append(oogaabooga[i])
            list2.append(np.hstack(list1))
            list1 = []
        else:
            list1.append(oogaabooga[i])
    out = np.vstack(list2)
    gif.append(out)
    
imageio.mimsave('anel.gif', gif, duration = 0.01)  
