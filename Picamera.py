import picamera
import RPi.GPIO as gpio
import picamera
import time
gpio.setmode(gpio.BCM)
gpio.setwarnings(False)
led=20
button=21
HIGH=1
LOW=0
gpio.setup(led,gpio.OUT)
gpio.setup(button,gpio.IN)
gpio.output(led,0)
from time import sleep
camera= picamera.PiCamera()
camera.resolution= (1024,768)
camera.brightness= 60
camera.start_preview()
camera.annotate_text='SY Students'
sleep(5)
camera.capture('image.jpeg')
camera.stop_preview()