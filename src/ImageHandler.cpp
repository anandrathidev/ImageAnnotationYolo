
#include <memory>
#include "ImageHandler.h"
#include "App.h"

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
// #include <opencv2/highgui/highgui.hpp>

namespace IANN
{
    void ImageFile::Close() 
    {
        if (mCapture.get())
        {
            mCapture->release();
        }
    };

    void ImageFile::OpenImageFile(const std::string& filename)
    {
        mCapture.reset(new cv::VideoCapture{ filename });
        mFrame.reset(new cv::Mat);
        if (!mCapture->isOpened())
        {
            throw "Error when reading video";
        }
    }

    const cv::Mat* ImageFile::ReadNextFrame()
    {
        if (mCapture.get())
        {
            if (!mCapture->isOpened())
            {
                throw "Error when reading video";
            }

            *mCapture >> *mFrame;

            if (mFrame->empty())
            {
                return nullptr;
            }
            return mFrame.get();
        }
        throw "Error stream not open";
    }
}