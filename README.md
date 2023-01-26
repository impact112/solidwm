# SolidWM

SolidWM is a fast and fully featured dynamic window manager.

# Features
* Bar with complete functionality (systray,hiding windows,transparency)
* Signal interface for external scripting
* Dynamic window layouts with advanced management
* Xresources compatibility
* GLava compatibility
* Profile functionality
* Restart functionality
* High degree of compatibility with graphical programs and toolkits

# Requirements
In order to build SolidWM you need:
* Xorg libraries:
    * libX11
    * xcb
    * Xinerama
* pango (emoji functionality requires libxft-bgra)
* Imlib2

# Installation

Edit config.mk to suit your system.

Run the following command to build and install SolidWM:

    make clean install

# Running SolidWM

Add the following line to your .xinitrc to start SolidWM using startx:

    exec solidwm

xsession files are installed for XDG compliant display managers such as lightdm or GDM.

In order to connect SolidWM to a specific display, make sure that
the DISPLAY environment variable is set correctly, e.g.:

    DISPLAY=:1 exec solidwm

# Configuration

SolidWM aims to be entirely configurable without rebuilding it.

SolidWM can be configured through xresources and its signal interface.

An external keybinding daemon is suggested for lauching external programs.

## The signal interface

The solidwmc script serves as a wrapper for the signal interface.

To set the bar status text run the following command:

	solidwmc status "your status text here"

## The hooking system

By default SolidWM will create a directory in ```~/.config``` from which it will execute certain files at runtime in certain moments. These files can be scripts, symlinks and any kind of executable.

SolidWM defaults to ```~/.config/solidwm``` for the profile directory path and ```default``` for the profile name.

SolidWM will run the following hooks in the profile directory:
* setup -> after SolidWM passes all sanity checks
* startup -> after SolidWM is fully initialised
* exit -> when SolidWM receives the quit signal

Note: These scripts are not forked, errors in the scripts may cause SolidWM to not start or exit properly!

Additionally SolidWM can run hooks when a keybinding is detected via the externalhook function, e.g.:

	{ MODKEY, XK_d, externalhook, {.v = "launcher"} }

This will run ~/.config/solidwm/default/launcher when MODKEY+d is pressed.

Note: External hooks are forked as processes.

Consult the ```examples``` directory for more information.

# Credits

* The original DWM devs
* The DWM patch devs
* [bakkeby](https://github.com/bakkeby) for the flexipatch line of programs and patches
* [explosion-mental](https://github.com/explosion-mental) for the NetWMWindowTypeDesktop fuctionality required by glava
