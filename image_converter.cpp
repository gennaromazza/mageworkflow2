// image_converter.cpp
#include "image_converter.h"
#include <opencv2/opencv.hpp> // Assicurati di includere OpenCV

void ImageConverter::convert(const std::string& inputPath, const std::string& outputPath) {
    cv::Mat image = cv::imread(inputPath, cv::IMREAD_COLOR); // Leggi l'immagine
    if (image.empty()) {
        throw std::runtime_error("Errore: impossibile leggere l'immagine da " + inputPath);
    }

    cv::imwrite(outputPath, image); // Scrivi l'immagine
}

