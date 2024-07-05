// Copyright (C) 2024  ilobilo

export module visualsort:quick;

import terminal;
import std;

namespace utils
{
    void sort(std::vector<std::size_t> &data, std::size_t left, std::size_t right)
    {
        auto partition = [](std::vector<std::size_t> &data, std::size_t left, std::size_t right)
        {
            auto pivot = data.at(left);
            auto i = left - 1;
            auto j = right + 1;

            while (true)
            {
                do {
                    i++;
                } while (data.at(i) < pivot);

                do {
                    j--;
                } while (data.at(j) > pivot);

                if (i >= j)
                    return j;

                std::swap(data.at(i), data.at(j));

                terminal::drawdata(data);
                std::this_thread::sleep_for(terminal::delay);
            }
        };

        if (left < right)
        {
            auto p = partition(data, left, right);
            sort(data, left, p);
            sort(data, p + 1, right);
        }
    };
} // namespace utils

export namespace sorter
{
    // hoare
    void quick(std::vector<std::size_t> &data)
    {
        auto size = data.size();
        if (size <= 1)
            return;

        utils::sort(data, 0, size - 1);
    }
} // namespace sorter
