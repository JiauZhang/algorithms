#-*- coding: UTF-8 -*-  
 
import imageio
 
def merge_gif(image_list, gif_name):
 
    frames = []
    for image_name in image_list:
        frames.append(imageio.imread(image_name))
    # Save them as frames into a gif 
    imageio.mimsave(gif_name, frames, 'GIF', duration = 0.1)
 
    return
 
def main():
    image_list = ['cube-0.png', 'cube-2.png', 'cube-4.png', 
                  'cube-6.png', 'cube-8.png', 'cube-10.png']
    gif_name = 'created_gif.gif'
    merge_gif(image_list, gif_name)

 
if __name__ == "__main__":
    main()
