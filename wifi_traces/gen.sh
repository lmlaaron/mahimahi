for f in sigcomm08_wl_*.pcap; do
	#tshark -r $f > ${f}.txt
	python gen_trace.py ${f}.txt
done
