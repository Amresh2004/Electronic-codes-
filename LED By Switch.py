import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
SWITCH1=21
LED1=14
GPIO.setup(SWITCH1,GPIO.IN,pull_up_down=GPIO.PUD_UP)
GPIO.setup(LED1,GPIO.OUT)
while True:
    new_input_state=GPIO.input(SWITCH1)
    if new_input_state==False:
       GPIO.output(LED1,True)
    else:
       GPIO.output(LED1,False)
GPIO.cleanup()