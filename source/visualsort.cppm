// Copyright (C) 2024  ilobilo

export module visualsort;

import :bubble;
import :heap;
import :merge;
import :quick;

import terminal;

import std;

namespace visualsort
{
    void generate(std::vector<std::size_t> &data, std::size_t size)
    {
        static std::random_device rd;
        static std::mt19937 gen { rd() };

        data.resize(size);
        std::iota(data.begin(), data.end(), 1);
        std::ranges::shuffle(data, gen);
    }

    enum algos : std::uint8_t
    {
        first,

        bubble,
        heap,
        merge,
        quick,

        last
    };

    export void run()
    {
        while (true)
        {
            std::println("Please choose a sorting algorithm:");
            std::println("1. Bubble sort");
            std::println("2. Heap sort");
            std::println("3. Merge sort");
            std::println("4. Quick sort");
            std::println("x. Exit");

            algos algo;
            while (true)
            {
                std::print("Input: ");

                std::string value;
                std::getline(std::cin, value);

                if (value.length() == 1 && std::tolower(value.front()) == 'x')
                {
                    algo = algos::last;
                    break;
                }

                bool err = false;
                try {
                    algo = static_cast<algos>(std::stoul(value));
                }
                catch (std::invalid_argument) { err = true; }

                if (!err && algo > algos::first && algo < algos::last)
                    break;

                std::println("Invalid input. please try again.");

            }
            if (algo == algos::last)
                return;

            terminal::init();

            std::vector<std::size_t> data;
            generate(data, terminal::num_columns);

            terminal::drawdata(data);
            std::this_thread::sleep_for(terminal::delay);

            switch (algo)
            {
                case algos::bubble:
                    sorter::bubble(data);
                    break;
                case algos::heap:
                    sorter::heap(data);
                    break;
                case algos::merge:
                    sorter::merge(data);
                    break;
                case algos::quick:
                    sorter::quick(data);
                    break;
                default:
                    std::unreachable();
                    break;
            }

            terminal::drawdata(data);
            terminal::beep();
            std::this_thread::sleep_for(std::chrono::seconds(1));

            terminal::deinit();
        }
    }
} // namespace visualsort