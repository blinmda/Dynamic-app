all: clean static dynamic

OBJECTS=ftsystem.o ftinit.o ftdebug.o ftbase.o ftbitmap.o ftglyph.o bdf.o smooth.o autofit.o truetype.o type1.o cff.o type1cid.o pfr.o type42.o pcf.o sfnt.o winfnt.o psaux.o psnames.o pshinter.o raster.o ftlzw.o ftgzip.o
FLAGS= -DFT2_BUILD_LIBRARY -fno-stack-protector -fno-exceptions -pie -fPIE -fPIC

install:
	gcc -c -Iinclude $(FLAGS) src/base/ftsystem.c -o ftsystem.o
	gcc -c -Iinclude $(FLAGS) src/base/ftinit.c -o ftinit.o
	gcc -c -Iinclude $(FLAGS) src/base/ftdebug.c -o ftdebug.o
	gcc -c -Iinclude $(FLAGS) src/base/ftbase.c -o ftbase.o
	gcc -c -Iinclude $(FLAGS) src/base/ftbitmap.c -o ftbitmap.o
	gcc -c -Iinclude $(FLAGS) src/base/ftglyph.c -o ftglyph.o
	gcc -c -Iinclude $(FLAGS) src/bdf/bdf.c -o bdf.o
	gcc -c -Iinclude $(FLAGS) src/truetype/truetype.c -o truetype.o
	gcc -c -Iinclude $(FLAGS) src/type1/type1.c  -o type1.o
	gcc -c -Iinclude $(FLAGS) src/cff/cff.c  -o cff.o
	gcc -c -Iinclude $(FLAGS) src/cid/type1cid.c -o type1cid.o
	gcc -c -Iinclude $(FLAGS) src/pfr/pfr.c -o pfr.o
	gcc -c -Iinclude $(FLAGS) src/type42/type42.c -o type42.o
	gcc -c -Iinclude $(FLAGS) src/lzw/ftlzw.c -o ftlzw.o
	gcc -c -Iinclude $(FLAGS) src/gzip/ftgzip.c -o ftgzip.o
	gcc -c -Iinclude $(FLAGS) src/pcf/pcf.c -o pcf.o
	gcc -c -Iinclude $(FLAGS) src/sfnt/sfnt.c -o sfnt.o
	gcc -c -Iinclude $(FLAGS) src/winfonts/winfnt.c -o winfnt.o
	gcc -c -Iinclude $(FLAGS) src/psaux/psaux.c -o psaux.o
	gcc -c -Iinclude $(FLAGS) src/psnames/psnames.c -o psnames.o
	gcc -c -Iinclude $(FLAGS) src/pshinter/pshinter.c -o pshinter.o
	gcc -c -Iinclude $(FLAGS) src/raster/raster.c -o raster.o
	gcc -c -Iinclude $(FLAGS) src/smooth/smooth.c  -o smooth.o
	gcc -c -Iinclude $(FLAGS) src/autofit/autofit.c -o autofit.o

freetype.a: install
	ar cr freetype.a $(OBJECTS)
	
freetype.so: install
	gcc -shared ${OBJECTS} -o freetype.so
	mv freetype.so ..
	
static: freetype.a

dynamic: freetype.so

clean:
	rm -f *.a
	rm -f *.so
	rm -f *.o


