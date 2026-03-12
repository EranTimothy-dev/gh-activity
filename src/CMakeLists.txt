add_executable(gh-activity 
    main.cpp
    cli/cli.cpp
    github/github_api.cpp
    parser/event_parser.cpp
    parser/repo_parser.cpp
    utils/http.cpp
    utils/formatter.cpp
    tui/dashboard.cpp
)

target_link_libraries(gh-activity 
    PRIVATE CLI11::CLI11
    PRIVATE CURL::libcurl
    PRIVATE nlohmann_json::nlohmann_json
    PRIVATE ftxui::screen
    PRIVATE ftxui::dom
    PRIVATE ftxui::component
)
# target_link_libraries(gh-activity PRIVATE CURL::libcurl)
# target_link_libraries(gh-activity PRIVATE nlohmann_json::nlohmann_json)
# target_include_directories(gh-activity PRIVATE
#     ${json_SOURCE_DIR}/include
# )

