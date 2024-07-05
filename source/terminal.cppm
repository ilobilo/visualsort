// Copyright (C) 2024  ilobilo

module;

#include <ncurses.h>

export module terminal;
import std;

namespace terminal
{
    static inline constexpr std::string_view block { "██" };
    static inline constexpr std::string_view spaces { "  " };

    bool colours = false;
    bool just_cleared = true;

    std::size_t width() { return COLS; }
    std::size_t height() { return LINES; }

    export inline constexpr auto delay = std::chrono::milliseconds(50);
    export std::size_t num_columns;

    export void deinit() { endwin(); }

    void refresh() { ::refresh(); }
    void clear() { ::erase(); just_cleared = true; }

    export void drawdata(std::vector<std::size_t> &data)
    {
        auto num = std::min(num_columns, data.size());
        auto xstart = (width() / 2) - ((num * spaces.length()) / 2);

        auto bottom = height() - 1;

        auto is_occupied = [&](std::size_t x, std::size_t y)
        {
            auto chr = (mvinch(y, x) & A_CHARTEXT);
            return chr > 0 && chr != ' ';
        };

        for (std::size_t i = 0; i < num; i++)
        {
            auto val = data.at(i);
            auto ystart = height() - val;

            auto x = xstart + (i * spaces.length());

            auto same_height = [&]()
            {
                return just_cleared || (is_occupied(x, ystart) && (ystart == 0 || !is_occupied(x, ystart - 1)));
            };

            int attr = 1;
            if (height() == val)
                attr = 2;
            else if (!same_height())
                attr = 3;

            if (is_occupied(x, bottom))
            {
                for (std::size_t y = 0; y < ystart; y++)
                    mvprintw(y, x, "%.*s", static_cast<int>(spaces.length()), spaces.data());
            }

            if (colours)
                attron(COLOR_PAIR(attr));

            for (std::size_t y = height() - val; y < height(); y++)
                mvprintw(y, x, "%.*s", static_cast<int>(block.length()), block.data());
        }
        just_cleared = false;
        refresh();
    }

    export void beep()
    {
        ::beep();
    }

    export void init()
    {
        std::locale::global(std::locale(""));

        initscr();

        if ((colours = has_colors()))
        {
            start_color();
            use_default_colors();

            init_pair(1, COLOR_WHITE, -1);
            init_pair(2, COLOR_GREEN, -1);
            init_pair(3, COLOR_RED, -1);
        }

        cbreak();
        noecho();
        curs_set(0);

        clear();
        refresh();

        num_columns = std::min(width() / spaces.length(), height());
    }
} // namespace terminal