# Importing Libraries
import serial
import time
arduino = serial.Serial(port='/dev/ttyUSB0', baudrate=9600, timeout=.1)

def write_read(x):
    """
    Handle Serial Communication Between Arduino and Python
    """
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(2) #set to 2 second to avoid latency problem?, simply to wait from arduino response
    data = arduino.readline()
    return data

def SendCommand(cmd: str) -> dict:
    """
    Send Command To Arduino Mega Through Serial Communication
    If You Want To Add More Command , Please Refer to the .ino document

    This is only command sender and receiver,
    The rest will handled by the arduino
    """
    value = write_read(cmd).decode('utf-8')
    return {"Command": cmd, "Response": value}

if __name__ == "__main__":
    #DEBUG PURPOSE
    #print(SendCommand("pesan;yuhuu saya ada disini bro"))
    while True:
        #Making General Command
        num = input("Arduino Command: ") # Taking input from user
        print("Waiting...")
        value = write_read(num)
        print(value.decode()) # printing the value
