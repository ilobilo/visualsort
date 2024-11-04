-- Copyright (C) 2024  ilobilo

set_project("VisualSort")
set_version("v0.1")

set_license("GPL-3.0")

add_rules("mode.debug", "mode.release")
set_policy("run.autobuild", true)

add_requires("ncursesw")

target("visualsort")
    set_kind("binary")

    set_toolchains("clang")
    set_runtimes("c++_shared")

    add_packages("ncursesw")

    add_files("source/**.cpp")
    add_files("source/**.cppm")

    set_policy("build.c++.modules", true)
    set_policy("build.c++.modules.std", true)

    set_languages("c++23")

    set_warnings("all", "error")
    set_optimize("fastest")
