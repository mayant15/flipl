#pragma once

#include <Magick++.h>

namespace flipl
{
    using Frame = Magick::Image;

    class Generator
    {
    private:
        std::vector<Frame> frames;
    public:
        Generator()
        {
#ifdef _WIN32
            // Magick must be initialized on Windows
            Magick::InitializeMagick(MAGICK_DLLS);
#endif
        }

        bool GenerateFrames(const Timeline& timeline)
        {
            unsigned int currentFrame = 0;
            while (currentFrame < timeline.End())
            {
                // TODO: This can run on multiple threads
                for (const auto& channel : timeline.channels)
                {
                    if (auto slot = timeline.GetSlotForFrame(currentFrame))
                    {
                        frames.emplace_back(slot->source);
                        frames.back().animationDelay(100 / timeline.fps);
                    }
                }
                ++currentFrame;
            }

            return true;
        }

        void WriteOut(const std::string& path)
        {
            Magick::writeImages(frames.begin(), frames.end(), path);
        }
    };
}
