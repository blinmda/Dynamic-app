#define _CRT_SECURE_NO_WARNINGS

#include "ft2build.h"
#include FT_FREETYPE_H
#include FT_GLYPH_H

#include "png.h"
#include <stdint.h>
#include <time.h>

#ifdef _DYNAMIC_
#include <dlfcn.h>
#endif 

#ifdef _DYNAMIC_
	int (*so_FT_Init_FreeType)(FT_Library*);
	int (*so_FT_New_Face)(FT_Library, const char*, FT_Long, FT_Face*);
	int (*so_FT_Set_Pixel_Sizes)(FT_Face, FT_UInt, FT_UInt);
	int (*so_FT_Load_Char)(FT_Face, FT_ULong, FT_Int32);
	int (*so_FT_Get_Char_Index)(FT_Face face, FT_ULong charcode);
	int (*so_FT_Get_Glyph)(FT_GlyphSlot slot, FT_Glyph* aglyph);
	int (*so_FT_Done_Glyph)(FT_Glyph glyph);
	int (*so_FT_Done_Face)(FT_Face face);
	int (*so_FT_Done_FreeType)(FT_Library library);
	int (*so_FT_Get_Kerning)(FT_Face face, FT_UInt left_glyph, FT_UInt right_glyph, FT_UInt kern_mode, FT_Vector* akerning);

	void* (*so_png_create_write_struct)(const char*, void*, void*, void*);
	void* (*so_png_create_info_struct)(void*);
	void (*so_png_init_io)(void*, void*);
	void (*so_png_set_IHDR)(void*, void*, unsigned int, unsigned int, int, int, int, int, int);
	void (*so_png_set_text)(void*, png_infop, png_textp, int);
	void (*so_png_write_end)(void*, void*);
	void (*so_png_write_row)(png_structp png_ptr, png_bytep row);
	void (*so_png_free_data)(png_structp png_ptr, png_infop info_ptr, png_uint_32 free_me, int num);
	void (*so_png_destroy_write_struct)(void*, void*);
	void (*so_png_write_info)(png_structp png_ptr, png_infop info_ptr);

	#define FT_Init_FreeType so_FT_Init_FreeType
	#define FT_New_Face so_FT_New_Face
	#define FT_Set_Pixel_Sizes so_FT_Set_Pixel_Sizes
	#define FT_Load_Char so_FT_Load_Char
	#define FT_Get_Char_Index so_FT_Get_Char_Index
	#define FT_Get_Glyph so_FT_Get_Glyph
	#define FT_Done_Glyph so_FT_Done_Glyph
	#define FT_Done_Face so_FT_Done_Face
	#define FT_Done_FreeType so_FT_Done_FreeType
	#define FT_Get_Kerning so_FT_Get_Kerning

	#define png_write_info so_png_write_info
	#define png_create_write_struct so_png_create_write_struct
	#define png_create_info_struct so_png_create_info_struct
	#define png_init_io so_png_init_io
	#define png_set_IHDR so_png_set_IHDR
	#define png_set_text so_png_set_text
	#define png_write_end so_png_write_end
	#define png_write_row so_png_write_row
	#define png_free_data so_png_free_data
	#define png_destroy_write_struct so_png_destroy_write_struct

#endif

#ifdef _BLOB_
#include <sys/stat.h>
FILE* stderr;
	void** glob_functions;
	clock_t clock(void) 
	{
	    return ((clock_t(*)(void))glob_functions[0])();
	}

	int puts(const char* str) 
	{
	    return ((int (*)(const char*))glob_functions[1])(str);
	}

	size_t strlen(const char* str) 
	{
	    return ((size_t(*)(const char*))glob_functions[2])(str);
	}

	char* strrchr(const char* str, int ch) 
	{
	    return ((char* (*)(const char*, int))glob_functions[3])(str, ch);
	}

	char* strstr(const char* str1, const char* str2) 
	{
	    return ((char* (*)(const char*, const char*))glob_functions[4])(str1, str2);
	}

	char* getenv(const char* name) 
	{
	    return ((char* (*)(const char*))glob_functions[5])(name);
	}

	int strncmp(const char* str1, const char* str2, size_t count) 
	{
	    return ((int (*)(const char*, const char*, size_t))glob_functions[6])(str1, str2, count);
	}

	void* memchr(const void* buffer, int ch, size_t count) 
	{
	    return ((void* (*)(const void*, int, size_t))glob_functions[7])(buffer, ch, count);
	}

	int strcmp(const char* str1, const char* str2) 
	{
	    return ((int (*)(const char*, const char*))glob_functions[8])(str1, str2);
	}

	void* memset(void* buf, int ch, size_t count) 
	{
	    return ((void* (*)(void*, int, size_t))glob_functions[9])(buf, ch, count);
	}

	char* strncpy(char* dest, const char* source, size_t count) 
	{
	    return ((char* (*)(char*, const char*, size_t))glob_functions[10])(dest, source, count);
	}

	void* mmap(void* start, size_t length, int prot, int flags, int fd, off_t offset) 
	{
	    return ((char* (*)(void*, size_t, int, int, int, off_t))glob_functions[11])(start, length, prot, flags, fd, offset);
	}

	void* realloc(void* ptr, size_t newsize) 
	{
	    return ((void* (*)(void*, size_t))glob_functions[12])(ptr, newsize);
	}

	void* memmove(void* dest, const void* source, size_t count) 
	{
	    return ((void* (*)(void*, const void*, size_t))glob_functions[13])(dest, source, count);
	}

	double frexp(double num, int* exp) 
	{
	    return ((double (*)(double, int*))glob_functions[14])(num, exp);
	}

	double modf(double num, double* i) 
	{
	    return ((double (*)(double, double*))glob_functions[15])(num, i);
	}

	double pow(double base, double exp) 
	{
	    return ((double (*)(double, double))glob_functions[16])(base, exp);
	}

	int fputc(int ch, FILE* stream) 
	{
	    return ((int (*)(int, FILE*))glob_functions[17])(ch, stream);
	}

	int memcmp(const void* buf1, const void* buf2, size_t count) 
	{
	    return ((int (*)(const void*, const void*, size_t))glob_functions[18])(buf1, buf2, count);
	}

	size_t fread(void* buf, size_t size, size_t count, FILE* stream) 
	{
	    return ((size_t(*)(void*, size_t, size_t, FILE*))glob_functions[19])(buf, size, count, stream);
	}

	struct tm* gmtime(const time_t* time) 
	{
	    return ((struct tm* (*)(const time_t*))glob_functions[20])(time);
	}

	FILE* fopen(const char* fname, const char* mode) 
	{
	    return ((FILE * (*)(const char*, const char*))glob_functions[21])(fname, mode);
	}

	int munmap(void* start, size_t length) 
	{
	    return ((int (*)(void*, size_t))glob_functions[22])(start, length);
	}

	void free(void* ptr) 
	{
	    return ((void (*)(void*))glob_functions[23])(ptr);
	}

	size_t fwrite(const void* buf, size_t size, size_t count, FILE* stream) 
	{
	    return ((size_t(*)(const void*, size_t, size_t, FILE*))glob_functions[24])(buf, size, count, stream);
	}

	int fflush(FILE* stream) 
	{
	    return ((int (*)(FILE*))glob_functions[25])(stream);
	}

	void* memcpy(void* dest, const void* source, size_t count) 
	{
	    return ((void* (*)(void*, const void*, size_t))glob_functions[26])(dest, source, count);
	}

	void* malloc(size_t size) 
	{
	    return ((void* (*)(size_t))glob_functions[27])(size);
	}

	int fclose(FILE* fp) 
	{
	    return ((int (*)(FILE*))glob_functions[28])(fp);
	}

	int ferror(FILE* stream) 
	{
	    return ((int(*)(FILE*))glob_functions[29])(stream);
	}

	ssize_t read(int fd, void* buf, size_t count) 
	{
	    return ((ssize_t(*)(int, void*, size_t))glob_functions[30])(fd, buf, count);
	}

	long int strtol(const char* str, char** endptr, int base) 
	{
	    return ((long int (*)(const char*, char**, int))glob_functions[31])(str, endptr, base);
	}

	int _setjmp(jmp_buf env)
	{
	    return ((int (*)(jmp_buf env))glob_functions[32])(env);
	}

	void abort() 
	{
	    ((void (*)())glob_functions[33])();
	}

	double strtod(const char* str, char** endptr) 
	{
	    return ((double (*)(const char*, char**))glob_functions[34])(str, endptr);
	}

	int remove(const char* pathname) 
	{
	    return ((int (*)(const char*))glob_functions[35])(pathname);
	}

	int open(const char* pathname, int flags) 
	{
	    return ((int (*)(const char*, int))glob_functions[36])(pathname, flags);
	}

	int* __errno_location(void) 
	{
	    return ((int* (*)())glob_functions[37])();
	}

	void qsort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*)) 
	{
	    return ((void (*)(void*, size_t, size_t, int (*)(const void*, const void*)))glob_functions[38])(base, num, size, compar);
	}

	int close(int fd) 
	{
	    return ((int (*)(int))glob_functions[39])(fd);
	}

	int __fxstat(int ver, int fildes, struct stat* sta) 
	{
	    return ((int (*)(int, int, struct stat*))glob_functions[40])(ver, fildes, sta);
	}

	char* strcpy(char* destination, const char* source) 
	{
	    return ((char* (*)(char*, const char*))glob_functions[41])(destination, source);
	}

	char* strerror(int errnum) 
	{
	    return ((char* (*)(int))glob_functions[42])(errnum);
	}

	char* stpcpy(char* dest, const char* src) 
	{
	    return ((char* (*)(char*, const char*))glob_functions[43])(dest, src);
	}
	
	int printf(const char* fmt, ...)
	{
	    return ((int (*)(const char*, ...))glob_functions[44])(fmt);
	}	
	
	void exit(int status) 
	{
	    ((void (*)(int))glob_functions[45])(status); 
	}
	
	void* calloc(size_t number, size_t size) 
	{
	    return ((void* (*)(size_t, size_t))glob_functions[46])(number, size);
	}
	
	int sprintf(char *buf, const char *format, ...)
	{
	    return ((int (*)(char*, const char*, ...))glob_functions[47])(buf, format);
	}
	
	char * strcat( char * destptr, const char * srcptr )
	{
	    return ((char* (*)(char*, const char*))glob_functions[48])(destptr, srcptr);
	}
	
	void longjmp(jmp_buf environment, int val)
	{
	    ((void (*)(jmp_buf, int))glob_functions[49])(environment, val); 
	}
	
	int fseek( FILE * filestream, long int offset, int origin )
	{
	    return ((int (*)(FILE *, long int, int))glob_functions[50])(filestream, offset, origin);
	}
	
	long int ftell( FILE * filestream )
	{
	    return ((long int (*)(FILE *))glob_functions[51])(filestream);
	}
	
	int __fprintf_chk(FILE* stream, int flag, const char* format, ...)
	{
	    return ((int (*)(FILE *, int, const char*, ...))glob_functions[52])(stream, flag, format);
	}
	
	void __longjmp_chk() 
	{
	    ((void (*)())glob_functions[53])();
	}
	
	void* __memcpy_chk(void* dest, const void* src, size_t len, size_t destlen) 
	{
	     return ((void* (*)(void*, const void*, size_t, size_t))glob_functions[54])(dest, src, len, destlen);
	}
	
	double atof( const char * string )
	{
	    return ((double (*)(const char*))glob_functions[55])(string);
	}
	
	int fprintf( FILE * stream, const char * format, ... )
	{
	    return ((int (*)(FILE *, const char*, ...))glob_functions[56])(stream, format);
	}
	
	double floor(double num)
	{
	    return ((double (*)(double num))glob_functions[57])(num);
	}
#endif


void error(char* error_description) {
    printf("Error: %s\n", error_description);
    exit(-1);
}

FT_Pos getKerning(FT_Face face, uint32_t leftCharcode, uint32_t rightCharcode) 
{
    FT_UInt leftIndex = FT_Get_Char_Index(face, leftCharcode);
    FT_UInt rightIndex = FT_Get_Char_Index(face, rightCharcode);

    if (leftIndex == 0 || rightIndex == 0)
        error("Undefined character code");

    FT_Vector delta;
    if (FT_Get_Kerning(face, leftIndex, rightIndex, FT_KERNING_DEFAULT, &delta) != 0) 
        error("FT_Get_Kerning.");

    return delta.x;
}

int* getSize(FT_Face face, int* height, int* width, const char* text) {
    int prevChar = 0, i = 0;
    int pos = 0;
    int* positions = calloc(strlen(text), sizeof(int));
    FT_BitmapGlyph bitmapGlyph = 0;
    for (i = 0; i < strlen(text); ++i)
    {
        FT_Load_Char(face, text[i], FT_LOAD_RENDER);
        FT_Glyph glyph = 0;
        FT_Get_Glyph(face->glyph, &glyph);

        if (!glyph)
        {
            continue;
        }

        if (prevChar) 
        {
            pos += getKerning(face, prevChar, text[i]);
        }
        prevChar = text[i];
        positions[i] = pos;

        bitmapGlyph = (FT_BitmapGlyph)glyph; 
        pos += glyph->advance.x >> 10;

        if (*height == 0 || bitmapGlyph->bitmap.rows > *height) {
            *height = bitmapGlyph->bitmap.rows;
        }
    }
    
    if (bitmapGlyph && i)
    	*width = (positions[i-1] >> 6) + bitmapGlyph->left + bitmapGlyph->bitmap.width;
    	
    return positions;
}

void write_png_file(const char* file_name, int width, int height, unsigned char* image_data) {
    FILE* fp = fopen(file_name, "wb");
    if (!fp) {
        printf("File %s could not be opened for writing\n", file_name);
        return;
    }

    png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, 0, 0, 0);
    png_infop info_ptr = png_create_info_struct(png_ptr);
    png_init_io(png_ptr, fp);

    png_set_IHDR(
        png_ptr,
        info_ptr,
        width,
        height,
        8,
        PNG_COLOR_TYPE_RGBA,
        PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_BASE,
        PNG_FILTER_TYPE_BASE);
    png_write_info(png_ptr, info_ptr);

    for (int y = 0; y < height; y++) {
        png_write_row(png_ptr, &image_data[y * width * 4]);
    }

    png_write_end(png_ptr, 0);

    png_free_data(png_ptr, info_ptr, PNG_FREE_ALL, -1);
    png_destroy_write_struct(&png_ptr, &info_ptr);
    fclose(fp);
}

void draw_text(const char* font_file, const char* output_file, const char* text) {
    FT_Library ftLibrary = 0; 
    FT_Init_FreeType(&ftLibrary);
    FT_Face ftFace = 0; 
    if (FT_New_Face(ftLibrary, font_file, 0, &ftFace) != 0 ){
        error("FT_New_Face.");
    }
    FT_Set_Pixel_Sizes(ftFace, 100, 100);

    int StringLen = strlen(text);
    int imageWidth = 0, imageHeight = 0;

    int* positions = calloc(StringLen, sizeof(int));
    positions = getSize(ftFace, &imageHeight, &imageWidth, text);
    
    unsigned char* image = calloc(imageWidth * imageHeight * 4, sizeof(unsigned char));
    memset(image, 255, imageWidth * imageHeight * 4 * sizeof(unsigned char));
    
    int prevChar = 0;

    for (int i = 0; i < StringLen; ++i)
    {
        FT_Load_Char(ftFace, text[i], FT_LOAD_RENDER);

        FT_Glyph glyph = 0;
        FT_Get_Glyph(ftFace->glyph, &glyph);
        if (!glyph)
        {
            continue;
        }
        FT_BitmapGlyph bitmapGlyph = (FT_BitmapGlyph)glyph;
        FT_Bitmap bitmap = bitmapGlyph->bitmap;

        for (int y = 0; y < bitmapGlyph->bitmap.rows; ++y)
        {
            for (int x = 0; x < bitmapGlyph->bitmap.width; ++x)
            {
                uint8_t  pixel = bitmap.buffer[x + y * bitmap.pitch];
                int dstX = (positions[i] >> 6) + bitmapGlyph->left + x;
                int pixel_index = dstX + y * imageWidth;

                if (pixel != 0)
                {
                    image[pixel_index * 4 + 0] = 0;
                    image[pixel_index * 4 + 1] = 0;
                }
            }
        }
    }

    write_png_file(output_file, imageWidth, imageHeight, image);

    FT_Done_Face(ftFace);
    ftFace = 0;

    FT_Done_FreeType(ftLibrary);
    ftLibrary = 0;
}

#ifdef _BLOB_
// for BLOB
int main(int argc, char* argv[], void** functions) 
{
    // all functions to use
    glob_functions = functions;

#else

int main(int argc, char* argv[])
{
    clock_t time_start = clock();

    if (argc < 4)
        error("Not enough arguments.");
    
    printf("loading...\n");
    
    #ifdef _DYNAMIC_
	void *ft_handle = NULL, *png_handle = NULL;
	png_handle = dlopen("./libpng.so", RTLD_LAZY);
	ft_handle = dlopen("./freetype.so", RTLD_LAZY);
	
	if (!ft_handle || !png_handle) 
	{
		error("dlopen.");
    	}
	
    	so_FT_Init_FreeType = dlsym(ft_handle, "FT_Init_FreeType");
    	so_FT_New_Face = dlsym(ft_handle, "FT_New_Face");
    	so_FT_Set_Pixel_Sizes = dlsym(ft_handle, "FT_Set_Pixel_Sizes");
    	so_FT_Load_Char = dlsym(ft_handle, "FT_Load_Char");
    	so_FT_Get_Char_Index = dlsym(ft_handle, "FT_Get_Char_Index");
    	so_FT_Get_Glyph = dlsym(ft_handle, "FT_Get_Glyph");
    	so_FT_Done_Glyph = dlsym(ft_handle, "FT_Done_Glyph");
    	so_FT_Done_Face = dlsym(ft_handle, "FT_Done_Face");
    	so_FT_Done_FreeType = dlsym(ft_handle, "FT_Done_FreeType");
    	so_FT_Get_Kerning = dlsym(ft_handle, "FT_Get_Kerning");

    	so_png_create_write_struct = dlsym(png_handle, "png_create_write_struct");
    	so_png_create_info_struct = dlsym(png_handle, "png_create_info_struct");
    	so_png_init_io = dlsym(png_handle, "png_init_io");
    	so_png_set_IHDR = dlsym(png_handle, "png_set_IHDR");
    	so_png_write_end = dlsym(png_handle, "png_write_end");
    	so_png_write_row = dlsym(png_handle, "png_write_row");
    	so_png_free_data = dlsym(png_handle, "png_free_data");
    	so_png_destroy_write_struct = dlsym(png_handle, "png_destroy_write_struct");
    	so_png_write_info = dlsym(png_handle, "png_write_info");
    #endif

    clock_t load_end = clock() - time_start;
    printf("load: %.1f ms\n", (double)load_end*1000 / (CLOCKS_PER_SEC));
#endif 

    printf("creating...\n");
    draw_text(argv[1], argv[2], argv[3]);

#ifndef _BLOB_
    clock_t time_end = clock() - time_start;
    printf("work: %.1f ms\n", (double)time_end*1000 / (CLOCKS_PER_SEC));
#endif

    #ifdef _DYNAMIC_
	dlclose(ft_handle);
	dlclose(png_handle);
    #endif
    
    return 0;
}


