// Copyright (C) 2024  ilobilo

export module visualsort:heap;

import terminal;
import std;

export namespace sorter
{
    void heap(std::vector<std::size_t> &data)
    {
        auto size = data.size();
        if (size <= 1)
            return;

        auto start = std::floor(size / 2);
        auto end = size;

        auto left_child = [](auto i) { return 2 * i + 1; };

        while (end > 1)
        {
            if (start <= 0)
            {
                end--;
                std::swap(data.at(end), data.front());

                terminal::drawdata(data);
                std::this_thread::sleep_for(terminal::delay);
            }
            else start--;

            auto root = start;
            while (left_child(root) < end)
            {
                auto child = left_child(root);
                if (child + 1 < end && data.at(child) < data.at(child + 1))
                    child++;

                if (data.at(root) < data.at(child))
                {
                    std::swap(data.at(root), data.at(child));
                    root = child;

                    terminal::drawdata(data);
                    std::this_thread::sleep_for(terminal::delay);
                }
                else break;
            }
        }
    }
} // namespace sorter
