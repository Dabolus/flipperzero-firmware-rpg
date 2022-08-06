# Flipper Zero firmware - RPG version

This firmware is a fork of the great [RogueMaster firmware](https://github.com/RogueMaster/flipperzero-firmware-wPlugins)
with a couple of tweaks made by me to give it a more RPG-ish look.

Changes implemented in this firmware:

- XP required for each new level is computed dynamically, currently with a requirement increment of 3 XP for each level.
  This means e.g. lvl1 -> lvl2 = 3 XP, lvl2 -> lvl3 = 6 more XP (9 XP in total), lvl3 -> lvl4 = 9 more XP (18 XP in total), etc.
- Since the thresholds are computed at runtime, the total number of levels is increased to 255 (the maximum value for the uint8 that is
  currently used by the Firmware). Theoretically, we could switch to a uint16 to support a whopping 65535 levels, but considering that
  leveling to level 255 requires around 2.5 years of everyday hardcode usage of the Flipper, I think that's not needed
- The Flipper animations that were for lvl1, lvl2, and lvl3 are now unlocked after a certain number of levels (yep, I took inspiration from Dragonite):
  - Level 1 animations -> Levels 1-29
  - Level 2 animations -> Levels 30-54
  - Level 3 animations -> Levels 55-255
- Flipper passport now also shows the current XP and the total XP required for the next level also in numeric format
- Each butthurt level (i.e. mood) now has a specific description, so the Flipper now has 14 different moods instead of just 3
- Added [Add settings to subghz read functionality to allow setting RSSI threshold (raw only) (By PolymerPrints)](https://github.com/RogueMaster/flipperzero-firmware-wPlugins/pull/184)
- Added [add score functionality for 2048 #186 (By DevMilanIan)](https://github.com/RogueMaster/flipperzero-firmware-wPlugins/pull/186)
- Fix for Keeloq from [Unleashed/Eng1n33r](https://github.com/Eng1n33r/flipperzero-firmware)
- Fix for BadUSB from [Unleashed/Eng1n33r](https://github.com/Eng1n33r/flipperzero-firmware)
- NULL pointer fixes from [Unleashed/Eng1n33r](https://github.com/Eng1n33r/flipperzero-firmware)
- Added [Fix serial no and btn display for princeton encoding on scripts #1545 (By bkerler)](https://github.com/flipperdevices/flipperzero-firmware/pull/1545)
- Added [Change default keyboard to Uppercase #1548 (By DrEverr)](https://github.com/flipperdevices/flipperzero-firmware/pull/1548)

My next goal is to add an achievement system, but it will probably require some time.

For anything else (how to compile the firmware, how to flash it, donations, etc.), please refer to the
RogueMaster and official firmwares. I just added a couple of features I wanted, but all the credits go
to the awesome guys that worked on them.
