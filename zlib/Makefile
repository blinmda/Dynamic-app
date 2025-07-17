OBJECTS=adler32.o compress.o crc32.o deflate.o infback.o inffast.o inflate.o inftrees.o trees.o uncompr.o zutil.o

all: clean static

clean:
	rm -f *.a
	rm -f *.o

.c.o:
	gcc -fno-stack-protector -fno-exceptions -pie -fPIE -c -fPIC $< -o $@

install: $(OBJECTS)
	
zlib.a: $(OBJECTS)
	ar rcs zlib.a $(OBJECTS)

static: zlib.a


