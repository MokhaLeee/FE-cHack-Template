
# Mokha's FE8U-CHAX-template

A simple example to build GBA FE8U hacks (in C) based on [Proj.decomp](https://github.com/FireEmblemUniverse/fireemblem8u.git).

## how2 (for windows user)

- Clone repo with command `git clone --recursive https://github.com/MokhaLeee/FE-cHack-Template.git` or update submodules with `git submodule update --init --recursive` after cloning, or just download each submodule inside `Tools/` folder.

- have [devkitARM](https://devkitpro.org/wiki/Getting_Started) installed, and the `DEVKITARM` env variable set.

- have [python 3](https://www.python.org/) installed and in your path. (the makefile *should* be able to find the correct python executable name. See [`tooks.mk`](./tooks.mk)).

- Download [EventAssembler release](https://github.com/StanHash/EventAssembler/releases/tag/1.0), and unzip which in `Tools` folder.

- Put `Fire Emblem 8: Scared Stones`(sha1: c25b145e37456171ada4b0d440bf88a19f4d509f) clean rom named `FE8U.gba` in directory.
- Open `Msys2` (which will be installed on DevkitPRO installation), or `Windows terminal` and get into current folder, type command `make` or `make hack` to build rom `HACK.gba`

- Further more, you can `make clean` to clean build outputs.

For more details, you can see tips on [StanH's CHAX](https://github.com/StanHash/FE-CHAX.git):

**Note**

Since I may update the repository of C-Lib from time to time, so I suggest you update each submodels any time you want to use this template through commands:
```
git submodule sync
git submodule update --init
```

## Wizardry Construction

- Create C file in `Wizardry/` folder and add command `#include "gbafe.h"` on head of which,

- Copy source code inside `src` folder of [Proj.Decomp of FireEmblem8u](https://github.com/FireEmblemUniverse/fireemblem8u/tree/master/src) 

- Include `*.lyn.event` file inside `_WizardryMain.event`
- Return root folder, open Msys2 or Windows Terminal or some thing, `make hack`. 

You can get more info in [readme file of C-Lib](https://github.com/MokhaLeee/FE-CLib-Mokha.git).

## Tips

- **Q:** ERROR with `switch` statement when assembling C, where EA would told me `Undefined identifier: _LP___gnu_thumb1_case_uqi`

	**A:** Change optimize-options of gcc from `Os` to `O1` or `O2` inside `make_wizardry.mk`.

- **Q:** ERROR: `ModuleNotFoundError: No module named 'six'`

	**A:** You need to install some modules for using TMX2EA. Make sure Python3 installed and get into FE-PyTools/TMX2EA folder, then, 
	
	```pip install -r requirements.txt```
	
	Just follow to [Tools/PyTools/TMS2EA/SETUP.md](https://github.com/StanHash/tmx2ea/blob/c77111a9c7a13208a2afb0984b253fa84df79479/SETUP.md).

- **_Never_ use spaces in filenames/paths.** This breaks `make` horribly. This is one of the main reason I had to modify most of circles tools for them to work with this setup.

## Big thankies

- StanH: `GBAFE-CHAX` constructor, genius, cool guy.
- circleseverywhere: Most tools in the `Tools/py` folder are based off his work. `_FE8EssentialFixes.event` is his composition (I think). Also lots of cool hax to base off mine. Also the original `MAKE HACK.cmd`. Also cool guy.
- Colorz: Maintains EA and implemented a lot of useful stuff. Also made `ParseFile` and `PortraitFormatter`, both of which are used here. Also useful hax. Also *Everything Assembler*. Also cool guy.
- Tequila: the Teq Doq is the best thing ever (I probably never would have gotten that far if not for that). Also lots of hax. Also cool guy. :duck:
- Teraspark, Leonarth, Kirb, Tiki/laqieer, ...: Cool and useful hax. Cool guys.
- Alusq: Demo/Test map. Cool guy.
- Nintenlord: He made the original EA. I never knew him but I assume he also was a cool guy.
- Zane: Doesn't have much to do with this but I love his work. Cool guy.
- Arch, Camdar: They prevent FEU from dying horribly (or at least from doing so for extented amounts of time). Cool guys.
- all of FEU: Cool guys.
