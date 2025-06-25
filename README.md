<p align="center">
  <img src="https://github.com/user-attachments/assets/24574b06-4077-4205-b5ed-11bbfce41c9c">
</p>

<p align="center">
  M3 Chat. In your terminal.
</p>

<p align="center"><img src="https://github.com/m3chat/tui/actions/workflows/release.yml/badge.svg" alt="Build">
<img src="https://img.shields.io/github/v/release/m3chat/tui" alt="Release">
<img src="https://img.shields.io/github/license/m3chat/tui" alt="License"></p>

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
curl -fsSL https://raw.githubusercontent.com/m3chat/tui/refs/heads/main/install-m3.sh | bash
```

## Uninstalling

To uninstall the installed version of `m3chat-tui`/`m3` run this command:

```sh
rm -rf ~/.local/bin/m3
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
