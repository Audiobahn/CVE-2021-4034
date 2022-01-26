all:
	gcc -shared -o audiobahn.so -fPIC 🎧-so.c
	gcc 🎧.c -o ab_exploit

clean:
	rm -rf ./GCONV_PATH=. && rm -rf audiobahn && rm ab_exploit && rm audiobahn.so
