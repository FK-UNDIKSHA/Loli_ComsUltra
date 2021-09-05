# Importing Libraries
import serial
import time
arduino = serial.Serial(port='/dev/ttyUSB0', baudrate=9600, timeout=.1)
def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(5) #set to 1 second to avoid latency problem?, simply to wait from arduino response
    data = arduino.readline()
    return data
while True:
    num = input("Arduino Command: ") # Taking input from user
    print("Measuring...")
    value = write_read(num)
    print("Tinggi: ", value.decode(), "CM") # printing the value
