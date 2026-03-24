Hi, I'm Vince. This is my first C++ project after taking a class at my university. Please note that as of right now this will only work in the terminal for your IDE or text editor. You can easily make this work for a Linux terminal in general by modifying the path to the JSON file on your system. I plan to keep changing and making improvements for personal use, let me know if you have any suggestions!

Please note that the project prompt from roadmap.sh states to not use external libraries for this, and to use JSON handling native to whatever language was chosen. C++ does not have native support for JSON so I chose to use the most popular library for it instead.

# Project from:
https://roadmap.sh/projects/task-tracker

# Tasky

A command-line task tracker built with C++20. Create, update, delete, and organize tasks with status tracking, all persisted to a local JSON file.

## Getting started

This project includes a dev container configuration. It is not required to open the project folder in the Dev Container to run it however. Just make sure to have
Clang++ with C++20 support and it should run fine after executing the commands below.

## Build

Requires `clang++` with C++20 support and `make`.

```bash
make tasky    # Build the executable (output: bin/tasky)
make tests    # Build the test suite
make clean    # Remove compiled binaries
```

## Usage

```bash
tasky add "Buy groceries"              # Add a new task
tasky update 1 "Buy groceries and cook" # Update a task's description
tasky delete 1                          # Delete a task
tasky mark 1 in-progress               # Mark a task as in-progress
tasky mark 1 done                       # Mark a task as done
tasky list                              # List all tasks
tasky list todo                         # List tasks by status (todo, in-progress, done)
```

### Task statuses

| Status        | Description                  |
|---------------|------------------------------|
| `todo`        | Default status for new tasks |
| `in-progress` | Task is currently being worked on |
| `done`        | Task is complete             |

## Data storage

Tasks are saved to `output/taskfile.json`. Each task stores an ID, description, status, creation time, and last-updated time.

## Project structure

```
src/            # Source files (driver, task, taskmanager, readwrite, taskjson)
includes/       # Headers and nlohmann/json library
tests/          # Unit tests (Catch framework)
bin/            # Compiled binaries
output/         # Task data (JSON)
```
