#!/usr/bin/env bash

set -e

# 1) Setup paths and names
PROJECT_NAME="Tic-Tac-Toe-Game" # Correct executable name from build
BUILD_DIR="build"
INSTALL_DIR="$HOME/.local/share/$PROJECT_NAME"
DESKTOP_FILE="$HOME/.local/share/applications/$PROJECT_NAME.desktop"
ICON_NAME="Tic-Tac-Toe-Game-red"
ICON_SRC="Images/${ICON_NAME}.png"
ICON_DEST="$HOME/.local/share/icons/${ICON_NAME}.png"

# 2) Clean build directory and build the project
rm -rf "$BUILD_DIR"
mkdir "$BUILD_DIR"
cd "$BUILD_DIR"
cmake ..
make -j$(nproc)

# 3) Create install directory and copy files
mkdir -p "$INSTALL_DIR"
cp "$PROJECT_NAME" "$INSTALL_DIR/"
cp -r ../Images "$INSTALL_DIR/"
cp -r ../Music "$INSTALL_DIR/"

# 4) Copy icon to system icons directory
mkdir -p "$(dirname "$ICON_DEST")"
cp "../$ICON_SRC" "$ICON_DEST"

# 5) Create .desktop file for launcher integration
cat >"$DESKTOP_FILE" <<EOF
[Desktop Entry]
Version=1.0
Type=Application
Name=Tic Tac Toe Game
Exec=$INSTALL_DIR/$PROJECT_NAME
Icon=$ICON_DEST
Terminal=false
Categories=Game;
EOF

# 6) Set executable permissions
chmod +x "$INSTALL_DIR/$PROJECT_NAME"
chmod +x "$DESKTOP_FILE"

echo "✅ Application is installed and available in the application launcher!"
