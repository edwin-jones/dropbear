# Drop Bear
What if it was the 80s and you wanted to make a game boy game? 
This project is a sample of how to make your own game boy games for yourself.

## Development
_Note, the tools below are either cross platform or built for Windows specifically. 
You can run these Windows tools via [Wine](https://www.winehq.org/) on Linux._

### Requirements
* [GBDK](https://github.com/gbdk-2020/gbdk-2020) - make sure the `GBDKDIR` environment variable is set!
* [VSCode](https://code.visualstudio.com/) - for writing and editing c code.
* [Make](https://en.wikipedia.org/wiki/Make_(software)) - for building c code. There is a [GnuWin32](http://gnuwin32.sourceforge.net/packages/make.htm) version for windows.
* [BGB](https://bgb.bircd.org/) - for emulation, debugging and viewing video ram contents.
* [GBTD](https://www.devrs.com/gb/hmgd/gbtd.html) - to edit tiles.
* [GBMB](https://www.devrs.com/gb/hmgd/gbmb.html) - to edit backgrounds etc.
* [GBTDG](https://github.com/chrisantonellis/gbtdg) - for importing image files into game boy tiles.

### Workflow
The current plan is to use [github flow](https://guides.github.com/introduction/flow/) and do work in branches
to avoid stomping over the main branch if and when multiple changes come in to the same files. PRs
aren't required at this point.

### Style guide
There aren't any hard and fast rules here but it's probably best to be idiomatic and roughly follow GBDK standards as follows:

* This is project is designed to work across different platforms so lower case file names are preferred.
* For function names, `snake_case` is preferred. 
* Use `ALL_CAPS` for macros.
* Use GBDK types for variables such as `UINT8` instead of int etc.
* Use normal c types in data files to avoid needed to import GBDK headers. `UINT8` would be just `unsigned char` etc.
* Use macros over consts where you can, again for consistency with the library.
* Use Allman style braces. (This is a divergence from the GBDK style)

### Compiling
You can compile the project using the `make` command.
You can find more about the compiler (lcc) and its options [here.](http://gbdk.sourceforge.net/tools.html)

## Credits/Inspiration/Guidance
* [MVG](https://www.youtube.com/watch?v=FzPTK91EJY8) and his handy GB coding quickstart.
* [Dr Ludos](https://www.gamasutra.com/blogs/DoctorLudos/20171207/311143/Making_a_Game_Boy_game_in_2017_A_quotSheep_It_Upquot_PostMortem_part_12.php) with his GB game making guide.
* [Dan Cox](https://videlais.com/2016/07/03/programming-game-boy-games-using-gbdk-part-1-configuring-programming-and-compiling/) with his GBDK guide.
* The GB dev community in general for countless amazing tools like GBDK, sprite editors etc.
* [Whoever made this handy youtube video on game boy SFX](https://www.youtube.com/watch?v=n2zl_iMR4jk)
