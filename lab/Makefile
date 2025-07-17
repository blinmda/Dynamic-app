all: clean static dynamic blob

clean:
	make -C freetype clean
	make -C zlib clean
	make -C libpng clean
	make -C app clean
	rm -f static
	rm -f dynamic
	rm -f blob
	rm -f *.bin
	rm -f *.so
	rm -f *.png

static: 
	@echo "[*] Building static..."
	make -C zlib static
	make -C libpng static
	make -C freetype static
	make -C app static
	
dynamic:
	@echo "[*] Building dynamic..."
	make -C libpng dynamic
	make -C freetype dynamic
	make -C app dynamic
	
blob:
	echo "[*] Building blob..."
	make -C zlib static
	make -C libpng static
	make -C freetype static
	make -C app blob

