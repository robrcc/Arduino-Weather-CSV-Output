# Requires PySerial
import serial

port = "COM3" # Replace with your COM# or /dev/tty.* port
speed = 9600

# Reading should be in the format: 28.04,30.43,959.99,453.17,235.27
# temperature, humidity, pressure, altitude, gas resistance

def process_reading(reading_raw):
	# split into list of values
	reading = reading_raw.split(",")
	# use however needed. remember to convert values to floats as needed.
	print(reading)
	
	
def main():
	try:
		print("Ctrl-C to exit.")
		
		ser = serial.Serial(port, speed)

		while True:
			reading_raw = ser.readline().decode().strip()		
			process_reading(reading_raw)

	except KeyboardInterrupt:
		print("Exiting...")
	
main()