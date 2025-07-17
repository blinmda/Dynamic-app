OBJECTS=png.o pngerror.o pngget.o pngmem.o pngread.o pngpread.o pngrio.o pngrtran.o pngrutil.o pngset.o pngtrans.o pngwio.o pngwrite.o pngwtran.o pngwutil.o

OBJECTS_ZLIB=../zlib/adler32.o ../zlib/crc32.o ../zlib/deflate.o ../zlib/infback.o ../zlib/inffast.o ../zlib/inflate.o ../zlib/inftrees.o ../zlib/trees.o ../zlib/zutil.o ../zlib/compress.o ../zlib/uncompr.o

all: clean static dynamic

clean:
	rm -f *.a
	rm -f *.so
	rm -f *.o

.c.o:
	gcc -pie -fPIE -fno-stack-protector -fno-exceptions -c -fPIC -I../zlib $< -o $@

install: $(OBJECTS)
	
libpng.a: $(OBJECTS)
	ar rcs libpng.a $(OBJECTS)

libpng.so: $(OBJECTS) $(OBJECTS_ZLIB)
	gcc -shared $(OBJECTS) $(OBJECTS_ZLIB) -o libpng.so 
	mv libpng.so ..

static: libpng.a

dynamic: libpng.so

