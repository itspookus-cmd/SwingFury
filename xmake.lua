-- SwingFury: speeds up the swing of melee attacks, keeps recovery at normal speed.
set_xmakever("2.8.2")

set_project("SwingFury")
set_version("0.1.0")
set_license("mit")
set_languages("c++23")
set_warnings("allextra")
set_encodings("utf-8")

set_allowedarchs("windows|x64")
set_defaultarchs("windows|x64")
set_defaultmode("releasedbg")
add_rules("mode.debug", "mode.releasedbg")

add_requires("commonlibsse-ng")

target("SwingFury")
    add_rules("@commonlibsse-ng/plugin", {
        name = "SwingFury",
        author = "You",
        description = "Faster melee swings with default recovery time"
    })
    add_packages("commonlibsse-ng")
    add_files("src/*.cpp")
    add_includedirs("src")
