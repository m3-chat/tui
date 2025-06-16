#!/bin/bash
set -e

REPO="m3-chat/tui"
BINARY_NAME="m3"
INSTALL_DIR="$HOME/.local/bin"

echo "Detecting OS and architecture..."
OS="$(uname | tr '[:upper:]' '[:lower:]')"
ARCH="$(uname -m)"

case "$ARCH" in
  x86_64) ARCH="amd64" ;;
  arm64|aarch64) ARCH="arm64" ;;
  *) echo "Unsupported architecture: $ARCH"; exit 1 ;;
esac

case "$OS" in
  linux) OS="linux" ;;
  darwin) OS="macos" ;;
  *) echo "Unsupported OS: $OS"; exit 1 ;;
esac

ASSET_NAME="${BINARY_NAME}-${OS}-${ARCH}"

echo "Fetching latest release download URL for $ASSET_NAME..."

LATEST_URL=$(curl -s "https://api.github.com/repos/$REPO/releases/latest" \
  | grep "browser_download_url" \
  | grep "$ASSET_NAME" \
  | cut -d '"' -f 4)

if [ -z "$LATEST_URL" ]; then
  echo "Could not find latest release for $ASSET_NAME"
  exit 1
fi

mkdir -p "$INSTALL_DIR"

echo "Downloading $ASSET_NAME to $INSTALL_DIR..."
curl -L "$LATEST_URL" -o "$INSTALL_DIR/$BINARY_NAME"
chmod +x "$INSTALL_DIR/$BINARY_NAME"

echo "Installed to $INSTALL_DIR/$BINARY_NAME"

# Ask user which profile to update
read -rp "What's your shell profile? (e.g. .bashrc, .zshrc) [default: .bashrc]: " PROFILE
PROFILE=${PROFILE:-.bashrc}
PROFILE_PATH="$HOME/$PROFILE"

# Ensure profile file exists
if [ ! -f "$PROFILE_PATH" ]; then
  echo "Profile $PROFILE_PATH does not exist, creating it."
  touch "$PROFILE_PATH"
fi

if ! grep -q "$INSTALL_DIR" <<< "$PATH"; then
  echo "Adding $INSTALL_DIR to PATH in ~/$PROFILE..."
  # Check if export line already exists to avoid duplicates
  if ! grep -q "export PATH=.*$INSTALL_DIR" "$PROFILE_PATH"; then
    echo -e "\n# Added by m3 install script\nexport PATH=\"\$PATH:$INSTALL_DIR\"" >> "$PROFILE_PATH"
    echo "Added PATH export to $PROFILE_PATH"
    echo "Please restart your shell or run: source ~/$PROFILE"
  else
    echo "PATH export for $INSTALL_DIR already present in $PROFILE_PATH"
  fi
else
  echo "PATH already contains $INSTALL_DIR"
fi
