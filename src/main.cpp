#include <iostream>
#include <CLI/CLI.hpp>

int main(int argc, char** argv) {

    CLI::App app{"A simple CLI application"};

    std::string username;
    int count = 1;

    // positional argument
    app.add_option("-u, --username", username, "Github username");

    // optional argument
    app.add_option("-c,--count", count, "Number of times");

    CLI11_PARSE(app, argc, argv);

    std::cout << "Usermame: " << username << std::endl;
    std::cout << "Count: " << count << std::endl;

    return 0;
}
