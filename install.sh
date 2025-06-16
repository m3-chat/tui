#!/bin/bash

set -e

REPO="m3-chat/tui"
BINARY_NAME="m3"
INSTALL_DIR="$HOME/.local/bin"
ASSET_NAME="m3"

echo "Fetching latest release..."
LATEST_URL=$(curl -s "https://api.github.com/repos/$REPO/releases/latest" \
  | grep "browser_download_url" \
  | grep "$ASSET_NAME" \
  | cut -d '"' -f 4)

if [ -z "$LATEST_URL" ]; then
  echo "𝙭 Failed to find latest release URL for $ASSET_NAME."
  exit 1
fi

mkdir -p "$INSTALL_DIR"

echo "Downloading $ASSET_NAME to $INSTALL_DIR..."
curl -L "$LATEST_URL" -o "$INSTALL_DIR/$BINARY_NAME"

chmod +x "$INSTALL_DIR/$BINARY_NAME"

if ! echo "$PATH" | grep -q "$INSTALL_DIR"; then
  if [ -n "$ZSH_VERSION" ]; then
    PROFILE="$HOME/.zshrc"
  elif [ -n "$BASH_VERSION" ]; then
    PROFILE="$HOME/.bashrc"
  elif [ -f "$HOME/.bashrc" ]; then
    PROFILE="$HOME/.bashrc"
  elif [ -f "$HOME/.zshrc" ]; then
    PROFILE="$HOME/.zshrc"
  else
    PROFILE="$HOME/.profile"
  fi

  echo "Adding $INSTALL_DIR to PATH in $PROFILE..."
  echo "export PATH=\"\$PATH:$INSTALL_DIR\"" >> "$PROFILE"
  echo "✓ Done. Restart your shell or run: source $PROFILE"
else
  echo "✓ Installed $BINARY_NAME at $INSTALL_DIR/$BINARY_NAME"
fi
