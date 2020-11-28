#include "timeline.h"

namespace flipl
{
    Timeline::Timeline(const AST& ast)
    {
        YAML::Node root = ast.root;

        if (!root["timeline"])
        {
            throw std::exception("Input file has no timeline");
        }

        if (!root["timeline"]["channels"] || !root["timeline"]["channels"].IsSequence())
        {
            throw std::exception("Input file has no channels");
        }

        for (const auto& channelNode : root["timeline"]["channels"])
        {
            auto channel = std::make_shared<Channel>();
            channelNode.
            unsigned int maxEnd = 0;
            for (auto slotNode : slotNodes)
            {
                auto start = slotNode["start"].as<unsigned int>();
                auto end = slotNode["end"].as<unsigned int>();
                auto source = ast.fileDir + slotNode["source"].as<std::string>();
                auto slot = std::make_shared<Slot>(start, end, source);
                channel->slots.push_back(slot);

                if (end > maxEnd)
                {
                    maxEnd = end;
                }
            }

            timelineEnd = maxEnd;
            channels.push_back(channel);
        }

        if (auto fps_ = root["timeline"]["fps"])
        {
            fps = fps_.as<unsigned int>();
        }
    }

    SRef<Slot> Timeline::GetSlotForFrame(unsigned int frame) const
    {
        // TODO: This only supports one channel for now
        for (const auto& slot : channels.front()->slots)
        {
            if (slot->start <= frame && slot->end >= frame)
            {
                return slot;
            }
        }
        return nullptr;
    }
}
