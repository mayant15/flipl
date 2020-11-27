#pragma once

#include "parser.h"

namespace flipl
{
    template <typename T>
    using SRef = std::shared_ptr<T>;

    /**
     * @brief The slot class represents the actual requested instance of the frame.
     */
    struct Slot
    {
        unsigned int start;
        unsigned int end;
        std::string source;

        Slot(unsigned int start_, unsigned int end_, const std::string& source_) : start(start_), end(end_), source(source_) {}
    };

    /**
     * @brief A channel is a collection of slots. Channels can be layered.
     */
    struct Channel
    {
        std::vector<SRef<Slot>> slots;
    };

    /**
     * @brief The timeline class holds multiple channels and GIF metadata.
     */
    class Timeline
    {
    public:
        unsigned int fps;
        std::vector<SRef<Channel>> channels;

    private:
        unsigned int timelineEnd;

    public:
        explicit Timeline(const AST& ast);

        SRef<Slot> GetSlotForFrame(unsigned int frame) const;

        inline unsigned int End() const
        {
            return timelineEnd + 1;
        }
    };
}
