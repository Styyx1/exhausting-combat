-- include subprojects
includes("lib/commonlibsse", "extern/styyx-utils")

local MOD_NAME = "styyx-stamina-combat"
local MOD_VERSION = "1.1.0"
local MOD_DESC = "Add stamina cost to certain actions."

-- set project constants
set_project(MOD_NAME)
set_version(MOD_VERSION)
set_license("GPL-3.0")
set_languages("c++23")
set_warnings("allextra")

-- xmake rules
add_rules("mode.debug", "mode.releasedbg")
set_defaultmode("releasedbg")

set_config("commonlib_toml", true)
set_config("use-fui", true)

-- define targets
target(MOD_NAME)
    add_deps("styyx-util")
    add_rules("commonlibsse.plugin", {
        name = MOD_NAME,
        author = "styyx",
        description = MOD_DESC
    })

    -- add src files
    add_files("src/**.cpp")
    add_headerfiles("src/**.h")
    add_includedirs("src")
    set_pcxxheader("src/pch.h")
    add_installfiles("res/(**)")