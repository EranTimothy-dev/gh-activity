add_executable(gh-activity 
    main.cpp
    cli/cli.cpp
    github/github_api.cpp
    parser/event_parser.cpp
    utils/http.cpp
)

target_link_libraries(gh-activity PRIVATE CLI11::CLI11)
target_link_libraries(gh-activity PRIVATE CURL::libcurl)
# target_link_libraries(gh-activity PRIVATE nlohmann_json::nlohmann_json)
target_include_directories(gh-activity PRIVATE
    ${json_SOURCE_DIR}/include
)

