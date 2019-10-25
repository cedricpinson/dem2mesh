#include "tinytiffreader.h"
#include <vector>

int main(int argc, char** argv)
{

    const char* filename = argv[1];

    TinyTIFFReaderFile* tiffr = NULL;
    tiffr = TinyTIFFReader_open(filename);
    if (!tiffr) {
        printf("ERROR: can't read file %s\n", filename);
        return 1;
    }

    if (TinyTIFFReader_wasError(tiffr)) {
        printf("ERROR: %s\n", TinyTIFFReader_getLastError(tiffr));
        return 1;
    }

    std::vector<float> buffer;
    uint32_t width = TinyTIFFReader_getWidth(tiffr);
    uint32_t height = TinyTIFFReader_getHeight(tiffr);
    buffer.resize(width * height);

    uint16_t format = TinyTIFFReader_getSampleFormat(tiffr);
    switch (format) {
    case TINYTIFFREADER_SAMPLEFORMAT_FLOAT:
        break;
    case TINYTIFFREADER_SAMPLEFORMAT_INT:
    case TINYTIFFREADER_SAMPLEFORMAT_UINT:
        printf("tiff INT or UINT sample format not supported\n");
        return 1;
        break;
    default:
        printf("unkown tiff sample format, unsupported\n");
        return 1;
    }

    printf("DEM %dx%d\n", width, height);

    TinyTIFFReader_getSampleData(tiffr, &buffer[0], 0);
    TinyTIFFReader_close(tiffr);

    return 0;
}
