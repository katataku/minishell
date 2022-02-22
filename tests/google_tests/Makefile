test:
	cd build && cmake ../ && make && ./main

ltest:
	cd build && cmake ../ && make && leaks --atExit -- ./main
