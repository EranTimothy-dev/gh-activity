# gh-activity

A modern **C++ CLI and TUI application** that fetches and visualizes GitHub user activity directly in the terminal.

`gh-activity` allows developers to explore GitHub events, statistics, and insights through a fast command-line interface and an interactive terminal dashboard.

---

## Features

- Fetch recent GitHub user activity
- Interactive **Terminal UI dashboard**
- Clean and modular **modern C++ architecture**
- High performance HTTP requests
- JSON parsing and structured event formatting
- CLI command system
- Activity statistics and insights
- Local caching to reduce API calls
- Cross-platform builds
- Automated builds with GitHub Actions

---

<!-- ## Demo -->
<!---->
<!-- ### CLI -->
<!-- ``` -->
<!-- $ gh-activity EranTimothy-dev -->
<!---->
<!-- Recent GitHub Activity for EranTimothy-dev -->
<!---->
<!-- PushEvent          scopesyncbridge          +3 commits -->
<!-- PullRequestEvent   ai-email-client          opened PR #42 -->
<!-- IssueCommentEvent  docker-utils             commented on issue #12 -->
<!-- WatchEvent         openai/openai-python     starred repository -->
<!-- ``` -->
<!---->
<!-- --- -->
<!---->
<!-- ### TUI Dashboard -->
<!-- ``` -->
<!-- GitHub Activity Dashboard -->
<!-- ──────────────────────────────── -->
<!---->
<!-- User: EranTimothy-dev -->
<!---->
<!-- Recent Events -->
<!-- ──────────────────────────────── -->
<!-- PushEvent          scopesyncbridge -->
<!-- PullRequestEvent   ai-email-client -->
<!-- IssueCommentEvent  docker-utils -->
<!---->
<!-- Repositories -->
<!-- ──────────────────────────────── -->
<!-- Most Active Repo: scopesyncbridge -->
<!-- Commits This Week: 12 -->
<!-- Pull Requests Opened: 4 -->
<!-- Issues Commented: 7 -->
<!-- ``` -->
<!---->
<!-- --- -->

## Installation

### Clone the repository
```bash
git clone https://github.com/EranTimothy-dev/gh-activity.git
cd gh-activity
```

---

### Build the project

The project uses **CMake**.
```bash
mkdir build
cd build
cmake ..
make
```

Run:
```bash
./gh-activity
```

---

## Usage

### Basic usage
```
gh-activity <username>
```

Example:
```
gh-activity EranTimothy-dev
```

---

### Commands

| Command                        | Description                           |
| ------------------------------ | ------------------------------------- |
| `gh-activity <username>`       | Show recent GitHub activity           |
| `gh-activity stats <username>` | Display activity statistics           |
| `gh-activity repos <username>` | Show repository insights              |
| `gh-activity tui <username>`   | Launch interactive terminal dashboard |

---

## Project Architecture
```
gh-activity
│
├── src
│   ├── main.cpp
│
│   ├── cli
│   │   └── commands.cpp
│
│   ├── github
│   │   ├── github_client.cpp
│   │   └── github_client.hpp
│
│   ├── parser
│   │   └── event_parser.cpp
│
│   ├── models
│   │   └── event.hpp
│
│   ├── cache
│   │   └── cache_manager.cpp
│
│   └── tui
│       └── dashboard.cpp
│
├── tests
│
├── CMakeLists.txt
└── README.md
```

---

## Tech Stack

| Library       | Purpose                       |
| ------------- | ----------------------------- |
| CLI11         | Command-line argument parsing |
| libcurl       | HTTP requests                 |
| nlohmann/json | JSON parsing                  |
| FTXUI         | Terminal UI                   |
<!-- | GoogleTest    | Unit testing                  | -->
| CMake         | Build system                  |

---

## GitHub API

`gh-activity` uses the GitHub REST API:
```
https://api.github.com/users/{username}/events
```

The tool processes event types such as:

- PushEvent
- PullRequestEvent
- IssuesEvent
- IssueCommentEvent
- WatchEvent
- CreateEvent


<!-- ## Caching -->
<!---->
<!-- To avoid unnecessary API calls, responses are cached locally. -->
<!---->
<!-- Example cache location: -->
<!-- ``` -->
<!-- ~/.gh-activity/cache.json -->
<!-- ``` -->
<!---->
<!-- Cache is refreshed periodically. -->


<!-- ## Testing -->
<!---->
<!-- Unit tests are implemented using **GoogleTest**. -->
<!---->
<!-- Run tests: -->
<!-- ```bash -->
<!-- ctest -->
<!-- ``` -->

---

## CI/CD

This project uses **GitHub Actions** for automated workflows.

Pipeline includes:

- Build verification
- Unit testing
- Cross-platform compilation
- Release artifact generation

Supported platforms:

- Linux
- macOS
- Windows

---

## Future Improvements

Planned enhancements:

- GitHub contribution heatmap
- Interactive filtering in the TUI
- Graph visualizations
- GitHub GraphQL API support
- Plugin architecture
- Package manager distribution

---

## Contributing

Contributions are welcome.

If you'd like to improve the project:

1. Fork the repository
2. Create a feature branch
3. Commit changes
4. Open a pull request

---

## License

This project is licensed under the MIT License.

---

## Author

**Eran Timothy Perera**

GitHub: [https://github.com/EranTimothy-dev](https://github.com/EranTimothy-dev)

---

## Inspiration

The project is inspired by modern terminal tools such as:

- `gh`
- `htop`
- `bat`
- `lazygit`

The goal is to create a fast, developer-friendly GitHub activity explorer directly inside the terminal.
