
// ImageAnnotationYolo.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

// TODO: Reference additional headers your program requires here.

#include <iostream>
#include <memory>

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

namespace IANN
{
    enum class IMAGEFILE_COND
    {
        IMAGEFILE_BAD,
        IMAGEFILE_GOOD
    };

    class ImageFile
    {
    public:
        ImageFile() = delete;
        ImageFile(const ImageFile&) = delete;
        ImageFile(const std::string& filename) : mFilename{ filename.c_str() } {};
        const cv::Mat* ReadNextFrame();
        IMAGEFILE_COND OpenImageFile();
        void Close();
        ~ImageFile() { Close(); };
        IMAGEFILE_COND GetIMAGEFILECOND() { return mImagefileCond; }

    protected:
        std::unique_ptr<cv::VideoCapture> mCapture;
        std::unique_ptr<cv::Mat> mFrame;
        std::string mFilename;
        IMAGEFILE_COND mImagefileCond = IMAGEFILE_COND::IMAGEFILE_BAD;
    private:

    };

}