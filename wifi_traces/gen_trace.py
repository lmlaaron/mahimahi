import sys
import numbers
import decimal

#f = open(os.argv[1],'r')

with open(sys.argv[1]) as f:
	uplink_filename = sys.argv[1] + ".uplink"
	downlink_filename = sys.argv[1] + ".downlink"
	uf = open(uplink_filename, 'w')
	df = open(downlink_filename, 'w')
	for line in f:
		lineArray = line.split()
		
		if len(lineArray) < 5:
			continue
		
		index = lineArray[0]
		timestamp = lineArray[1] # in millisecond
		try:
			timestamp = int(float(timestamp)*1000)
		except:
			continue

		timestamp = str(timestamp)
		sender_ip = lineArray[2]
		sender_ip_array = sender_ip.split(".")
		receiver_ip = lineArray[4]
		if (len(sender_ip_array) == 4) & (sender_ip_array[0] == "26"):
			#print(index, timestamp, sender_ip, receiver_ip)	
			uf.write(timestamp)
			uf.write("\n")
		else:
			df.write(timestamp)
			df.write("\n")
		
