# fba-dummy
Automatic/scripted 2p control for fba (potentially any emulator).

## Why?

Kinda disappointed with the lack of proper training mode tools for 3s on PC. Can't blame anyone honestly, but I figured I'd do something about it. Lua scripts Nica K.O. posted on the Internet (shoutouts to him and the creator of those!) are already a gigantic improvement, but the dummy is standing still. It'd be great to have the same level of control for the dummy as there is in SFV, including recording slots and random selection of those (great for practicing reactions and mixups). Hopefully will get around to making it game-agnostic in the end.

## How?

The project is written in C++ with Qt 5.5 for GUI and utilizes raw input to intercept keys sent to the FBA window. This enables recording the dummy movement with player 1 keys and blocking (/after first hit) without messing with the emulated memory. During initial development I won't be focusing too much on enabling support for adding different emulator backends, but if there will be obvious ways to avoid using fba-specific code, I'll take them.

## Can I help?

Code review would be great, feature requests and bug reports in the issues section even more. If you wish to send in a pull request, go for it, but don't do big, multi-file commits from the very beginning, since I'm pretty harsh on the quality of code I do not maintain.
