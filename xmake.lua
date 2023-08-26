
add_requires("glfw")
add_requires("tinygltf")

target("argent")
    set_kind("binary")
    set_languages("cxx17")
    add_files("src/**.cpp")
    add_includedirs("src/")