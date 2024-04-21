import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
PIR=21
BUZZ=20
GPIO.setup(PIR,GPIO.IN)
GPIO.setup(BUZZ,GPIO.OUT)
GPIO.setup(BUZZ,GPIO.LOW)
while True:
    if(GPIO.input(PIR)):
        GPIO.output(BUZZ,GPIO.HIGH)
    else:
        GPIO.output(BUZZ,GPIO.LOW)
time.sleep(4)