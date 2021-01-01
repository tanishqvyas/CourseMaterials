import cv2
import os
import numpy as np




def load_images_from_folder(folder):
    images = []
    for filename in os.listdir(folder):

    	# Reading as grayscale
        img = cv2.imread(os.path.join(folder,filename), 0)
        
        # cv2.imshow("Image", img)
        # cv2.waitKey(0)

        if img is not None:
            images.append(img)
    
    return images



def get_matrix_for_all_images(folder):

	img_list = load_images_from_folder(folder)

	my_matrix = []

	for img in img_list:

		my_matrix.append(img.reshape(-1))

	# Making np array of the list
	my_matrix = np.array(my_matrix)

	# Find the transpose to get image vector in column
	my_matrix = my_matrix.transpose()


	return my_matrix


def display(img):


	image = np.reshape(img, (-1, 128))
	print(image)
	cv2.imshow("Display Window", image)
	cv2.waitKey(0)
	cv2.imwrite("car.png", image)



if __name__ == '__main__':

	IMG_PATH = os.path.join("Images")
	
	my_matrix = get_matrix_for_all_images(IMG_PATH)

	print(my_matrix, "Shape  : ", my_matrix.shape)

	avg_img = np.average(my_matrix.transpose(), axis=0)

	print(avg_img, "shape : ", avg_img.shape)

	display(my_matrix.transpose())




	cv2.waitKey(0)
