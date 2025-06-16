# M3 Chat, in your terminal!
![Build](https://github.com/m3-chat/tui/actions/workflows/release.yml/badge.svg)
![Release](https://img.shields.io/github/v/release/m3-chat/tui)
![License](https://img.shields.io/github/license/m3-chat/tui)

A simple terminal UI (TUI) client for interacting with the [M3 Chat](https://github.com/m3-chat) API to get streamed AI responses.

## Features

- Select from multiple AI models
- Stream AI responses live in the terminal
- Commands:
  - `/models` — list available models
  - `/clear` — clear the terminal screen
  - `/exit` — quit the program

## Installation

You can install the latest binary easily with the install script:

```bash
curl -fsSL https://raw.githubusercontent.com/m3-chat/tui/main/install.sh | bash
```

The script detects your OS and architecture, downloads the latest release, installs it to `~/.local/bin`, and updates your shell PATH.

## Usage

Run the program with your chosen model:

```bash
m3 <model>
```

Example:

```bash
m3 mistral
```

If you run without a model argument, it lists available models and usage info.

Inside the app, use the commands `/models`, `/clear`, and `/exit`.


## Contributions

Contributions and issues are welcome! Feel free to open a PR or an issue.

