import serial
import struct
import time

SERIAL_PORT = '/dev/tty.usbserial-10' # Find port with ls /dev/tty.*
BAUD_RATE = 9600
STRUCT_FORMAT = '<14f'  # Little-endian, 14 floats
STRUCT_SIZE = struct.calcsize(STRUCT_FORMAT)

def read_serial_data(ser: serial.Serial):
    data = ser.read(STRUCT_SIZE)
    if len(data) == STRUCT_SIZE:
        values = struct.unpack(STRUCT_FORMAT, data)
        return values

def save_to_file(filename, values):
    with open(filename, 'a') as f:
        timestamp = time.strftime('%Y-%m-%d %H:%M:%S')
        f.write(f"{timestamp}," + ','.join(map(str, values)) + '\n')

if __name__ == "__main__":
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
    filename = f"{time.strftime('%y%m%d_%H:%M:%S')}.csv"

    try:
        while True:
            values = read_serial_data(ser)
            if values:
                save_to_file(filename, values)
    except KeyboardInterrupt:
        print("Exiting.")
    finally:
        ser.close()
