// Copyright (C) 2024  ilobilo

export module visualsort:merge;

import terminal;
import std;

export namespace sorter
{
    // top-down
    void merge(std::vector<std::size_t> &data)
    {
        if (data.size() <= 1)
            return;

        auto work = data;

        std::size_t begin = 0;
        std::size_t end = data.size();

        auto split_merge = [](this auto &self, auto begin, auto end, auto &b, auto &a)
        {
            if (end - begin <= 1)
                return;

            auto middle = (end + begin) / 2;
            self(begin, middle, a, b);
            self(middle, end, a, b);

            auto merge = [](auto begin, auto middle, auto end, auto &b, auto &a)
            {
                for (auto i = begin, k = begin, j = middle; k < end; k++)
                {
                    if (i < middle && (j >= end || a.at(i) <= a.at(j)))
                    {
                        b.at(k) = a.at(i);
                        i++;
                    }
                    else
                    {
                        b.at(k) = a.at(j);
                        j++;
                    }

                    terminal::drawdata(b);
                    std::this_thread::sleep_for(terminal::delay);
                }
            };
            merge(begin, middle, end, b, a);
        };
        split_merge(begin, end, data, work);
    }
} // namespace sorter
