import tkinter as tk
from tkinter import filedialog
from ctypes import windll
import cv2
import numpy as np
from PIL import Image, ImageTk


windll.shcore.SetProcessDpiAwareness(1)
IMG_SIZE = 30


root = tk.Tk()


def process_img(img_path):
    img_array = cv2.imread(img_path)
    img_array = cv2.resize(img_array, (IMG_SIZE, IMG_SIZE))
    img_array = cv2.cvtColor(img_array, cv2.COLOR_BGR2RGB)
    img_array = np.array(img_array)
    return img_array


def onClick():
    myLabel = Label(root, text="I was Clicked")
    myLabel.pack()


def UploadAction(event=None):
    filename = filedialog.askopenfilename()
    img = ImageTk.PhotoImage(image=Image.fromarray(process_img(filename)))
    canvas = tk.Canvas(root, width=300, height=300)
    canvas.create_image(20, 20, anchor="nw", image=img)
    canvas.grid(row=0, column=1)


button1 = tk.Button(root, text="Upload File", padx=50, pady=30, command=UploadAction)
button2 = tk.Button(root, text="Run Model", padx=50, pady=30, command=UploadAction)

button1.grid(row=0, column=0)
button2.grid(row=1, column=1)

root.mainloop()
