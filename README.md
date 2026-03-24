# Tasky

A command-line task tracker built with C++20. Create, update, delete, and organize tasks with status tracking, all persisted to a local JSON file.

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
