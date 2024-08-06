#ifndef IMAGE_CONVERTER_H
#define IMAGE_CONVERTER_H

#include <string>

class ImageConverter {
public:
    static void convertToJpeg(const std::string &src, const std::string &dest);
};

#endif // IMAGE_CONVERTER_H
