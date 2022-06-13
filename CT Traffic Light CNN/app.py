import tkinter as tk
from tkinter import filedialog
from ctypes import windll
import cv2
import numpy as np
from PIL import Image, ImageTk


from utils import *


windll.shcore.SetProcessDpiAwareness(1)
IMG_SIZE = 30


root = tk.Tk()


def onClick():
    myLabel = tk.Label(root, text="I was Clicked")
    myLabel.pack()


def UploadAction(event=None):
    filename = filedialog.askopenfilename()
    im = Image.fromarray(process_img(filename)[1])
    img = ImageTk.PhotoImage(image=im)
    panel = tk.Label(root, image=img)
    # panel.create_image(20, 20, anchor="nw", image=img)
    panel.grid(row=1, column=0)
    tk.Label(root, text=str((process_img(filename)[0]))).grid(row=2, column=0)
    root.mainloop()


button1 = tk.Button(
    root, text="Upload File and Run Model", padx=50, pady=30, command=UploadAction
)
# button2 = tk.Button(root, text="Run Model", padx=50, pady=30, command=UploadAction)

button1.grid(row=0, column=0)
# button2.grid(row=1, column=1)

root.mainloop()
