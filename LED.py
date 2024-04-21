import RPi.GPIO as GPIO
import time
LED1=14
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
for i in range(10):
    GPIO.setup(LED1,GPIO.OUT)
    GPIO.output(LED1,True)
    time.sleep(1)
    GPIO.output(LED1,False)
    time.sleep(1)
GPIO.cleanup