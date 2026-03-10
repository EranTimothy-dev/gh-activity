add_executable(gh-activity 
    main.cpp
    cli/cli.cpp
    cli/cli.hpp
)

target_link_libraries(gh-activity PRIVATE CLI11::CLI11)
