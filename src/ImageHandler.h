
// ImageAnnotationYolo.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

// TODO: Reference additional headers your program requires here.

#include <iostream>
#include <memory>

namespace cv
{
    class VideoCapture;
    class Mat;
}

namespace IANN
{
    class ImageFile
    {
    public:
        ImageFile() = delete;
        ImageFile(std::string& filename): mFilename{ filename } {};
        cv::Mat* ReadNextFrame();
        void OpenImageFile(const std::string& filename);
        void Close();
        ~ImageFile() { Close(); };

    protected:
        std::unique_ptr<cv::VideoCapture> mCapture;
        std::unique_ptr<cv::Mat> mFrame;
        std::string mFilename;
    private:

    };

}