#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1)
struct bmp {
    char signature[2];
    int file_size;
    char reserved[12];
    int width;
    int height;
};
#pragma pack(pop) 

int main() {

    void *ptr = malloc(sizeof(struct bmp));
    struct bmp *sptr = (struct bmp*)ptr;

    FILE *fh = fopen("photo.bmp", "rb");

    if(fh != NULL){
        fread(ptr, sizeof(struct bmp), 1, fh);
        fclose(fh);
    }

    printf("signature: %.2s\nfile size: %d bytes\nwidth: %d pixel\nheight: %d pixel\n",
            sptr ->signature, sptr ->file_size, sptr ->width, sptr ->height);
        free(ptr);            

    return 0;
}



