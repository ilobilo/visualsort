// Copyright (C) 2024  ilobilo

export module visualsort:bubble;

import terminal;
import std;

export namespace sorter
{
    void bubble(std::vector<std::size_t> &data)
    {
        auto n = data.size();
        if (n <= 1)
            return;

        while (n > 1)
        {
            std::size_t newn = 0;
            for (std::size_t i = 1; i <= n - 1; i++)
            {
                if (data.at(i - 1) > data.at(i))
                {
                    std::swap(data.at(i - 1), data.at(i));
                    newn = i;

                    terminal::drawdata(data);
                    std::this_thread::sleep_for(terminal::delay);
                }
            }
            n = newn;
        }
    }
} // namespace sorter
