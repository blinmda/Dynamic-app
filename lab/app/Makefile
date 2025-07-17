SOURCES_LOADER=../elfloader/elf_loader.c ../elfloader/main.c ../elfloader/wheelc/list.c

all: clean static dynamic blob

clean:
	rm -f *.o

static:
	gcc -c -I../libpng -I../freetype/include Source.c
	gcc Source.o ../libpng/libpng.a ../zlib/zlib.a ../freetype/freetype.a -lm -o ../static
	
dynamic: 
	gcc -I../freetype/include -I../libpng -D_DYNAMIC_ Source.c -lm -ldl -o ../dynamic
	
blob:
	gcc $(SOURCES_LOADER) -lm -o ../blob
	gcc Source.c -I../freetype/include -I../libpng ../freetype/freetype.a  ../libpng/libpng.a ../zlib/zlib.a -nostdlib -pie -fPIE -fPIC -w -e main -D_BLOB_ -o ../blob.bin

