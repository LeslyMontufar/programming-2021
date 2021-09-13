clc;
clear;

% Binariza 
[filename, pathname] = uigetfile({'*.jpg';'*.png';'*.ico'},'Select an image');
path = strcat(pathname, filename);
im = imread(path);

im_gray = rgb2gray(im);
new_im = 255*(im_gray>210);

figure();
subplot(131); imshow(im);
subplot(132); imshow(im_gray);
subplot(133); imshow(new_im);

% name = input('Image name: ','s');
% imwrite(new_im, [name '.png']);
