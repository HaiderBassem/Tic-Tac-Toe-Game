#!/usr/bin/env bash

# Uninstall script for Tic-Tac-Toe-Game

PROJECT_NAME="Tic-Tac-Toe-Game"
INSTALL_DIR="$HOME/.local/share/$PROJECT_NAME"
LOCAL_DESKTOP="$HOME/.local/share/applications/$PROJECT_NAME.desktop"
ICON_NAME="Tic-Tac-Toe-Game-red.png"
ICON_PATH="$HOME/.local/share/icons/$ICON_NAME"

echo "Uninstalling $PROJECT_NAME..."

# Remove installed files
if [ -d "$INSTALL_DIR" ]; then
  rm -rf "$INSTALL_DIR"
  echo "Removed installed files: $INSTALL_DIR"
else
  echo "No install directory found at $INSTALL_DIR"
fi

# Remove .desktop entry
if [ -f "$LOCAL_DESKTOP" ]; then
  rm "$LOCAL_DESKTOP"
  echo "Removed desktop entry: $LOCAL_DESKTOP"
else
  echo "No desktop entry found at $LOCAL_DESKTOP"
fi

# Remove icon
if [ -f "$ICON_PATH" ]; then
  rm "$ICON_PATH"
  echo "Removed icon: $ICON_PATH"
else
  echo "No icon found at $ICON_PATH"
fi

# Update desktop database
update-desktop-database ~/.local/share/applications/ 2>/dev/null

echo "✅ Uninstall complete. The game is removed from your system."
