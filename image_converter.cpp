#include "image_converter.h"
#include <opencv2/opencv.hpp>
#include <iostream>

void ImageConverter::convertToJpeg(const std::string &src, const std::string &dest) {
    try {
        cv::Mat image = cv::imread(src, cv::IMREAD_UNCHANGED);
        if (!image.empty()) {
            std::vector<int> compression_params = {cv::IMWRITE_JPEG_QUALITY, 95};
            cv::imwrite(dest, image, compression_params);
        } else {
            std::cerr << "Failed to load image: " << src << std::endl;
        }
    } catch (const cv::Exception &e) {
        std::cerr << "Image conversion error: " << e.what() << std::endl;
    }
}
