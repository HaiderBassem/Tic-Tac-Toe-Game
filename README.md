# X-OGame

A Tic-Tac-Toe game built with Qt 6, featuring a GUI and background music.

---

## Requirements

To build and run the project on most Linux distributions, you need:

- C++20 compiler (g++ 10+ or clang++)
- CMake 3.16 or newer
- Qt 6 development libraries (widgets and multimedia)
- Basic build tools (make, gcc, g++)

### On Debian/Ubuntu:

```bash
sudo apt update
sudo apt install build-essential cmake qt6-base-dev qt6-multimedia-dev libqt6multimedia6 qt6-multimedia-plugins
```

### On Fedora:
```bash
sudo dnf install gcc-c++ cmake qt6-qtbase-devel qt6-qtmultimedia-devel
```

### On Arch Linux:

```bash
sudo pacman -S base-devel cmake qt6-base qt6-multimedia
```

### Build and Run

    Open terminal and navigate to the project directory:

```bash
cd ~/Tic-Tac-Toe-Game 

chmod +x build_and_install.sh
./build_and_install.sh
```

Notes

    Ensure music and image files exist in the correct project folders (Music/ and Images/).

    If you face Qt Multimedia related errors, verify the Qt Multimedia packages are installed.

    For other OS (Windows/macOS), prepare Qt environment accordingly.


