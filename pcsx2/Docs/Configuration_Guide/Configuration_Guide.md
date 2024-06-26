<!-- PDF METADATA STARTS ---
title: "PCSX2 - Configuration Guide"
date: "2020"
footer-left: "[Document Source](https://github.com/PCSX2/pcsx2/blob/{LATEST-GIT-TAG}/pcsx2/Docs/Configuration_Guide/Configuration_Guide.md)"
urlcolor: "cyan"
... PDF METADATA ENDS -->

# PCSX2 First Time Setup and Configuration
This guide will walk through the initial setup process of PCSX2 and the basics of configuration.

*Note: While this document is using Windows screenshots, you can still follow this guide for Linux.*

\pagebreak

## First Time Setup
The first time you launch PCSX2, you will be prompted with a First Time Configuration wizard.

### Language Selection
You may choose to change the UI language of PCSX2 here.

![PCSX2_First_Time_Configuration.png](PCSX2_First_Time_Configuration.png)

*Note: Translations may not be accurate or actively maintained by translators. If you find translation issues and want to fix them yourself, please contribute  to  [PCSX2 on crowdin](https://crowdin.com/project/pcsx2-emulator).*

### BIOS Selection
PCSX2 will now ask you to provide your PS2's BIOS dump. Use the "Open Bios Folder" button to open the BIOS folder, and drop your BIOS files inside. Then use the "Refresh List" button to show your BIOS in the list. Click it, then hit Finish.

Advanced users may wish to use a different folder for their BIOS, you can do so by hitting Browse to select a new folder.

![PCSX2_First_Time_Configuration_bios.png](PCSX2_First_Time_Configuration_bios.png)

## Post-Setup Configuration
A large number of games work out-of-the-box on default PCSX2 settings. However, a subset of games require special settings to run, and some games require special settings to be upscaled. This guide will briefly cover some frequent problems and configuration settings to address them.


### General solutions
Want some general ideas to try that are not specific to a game? Here are some more commonly known issues and solutions to try.
*Note: For some of these issues, multiple solutions are given one after the other. Before moving from one solution to the next, **undo the previous solution**. Stacking multiple fixes on top of each other is usually unnecessary and likely to introduce new issues.*

#### Grid-like pattern on screen
Usually this is due to upscaling, which can cause sprites and 2D textures to misalign. Any fixes will be found in the GSdx Advanced Settings and Hacks:
`Settings > Graphics`
First try the two Round Sprite modes, Half and Full. Then try Align Sprite or Merge Sprite. Then try the Half Pixel Offset modes. If all else fails, consider using the Texture Offsets.

#### Ghosting and bloom misalignment
Upscaling can cause some screen elements, usually but not always bloom effects, to misalign. Navigate to the Upscaling fixes:
`Settings > Graphics  > Rendering > Upscaling fixes `
Try the various Half Pixel Offset modes. The further down the list you go, the more aggressive the hack gets. Once you find a mode that properly fixes the ghosting/misalignment, do not push it further. Also note in some games, the further you upscale, the worse the ghosting/misalignment gets. In some of these games, Half Pixel Offset may mitigate the issue, but not be able to fully resolve it.

#### Flickering or improper lightning
Sometimes a game uses blending for lighting effects and needs more accuracy for blending to work correctly. Navigate to the Graphics Settings:
`Settings > Graphics > Rendering`
Increment Blending Accuracy until the problem goes away. Note, higher Blending Accuracy substantially increases performance requirements.

#### Flickering or improperly shaped shadows
This can either be a GS or VU problem so solutions will vary wildly by game.

##### VU
Navigate to the VU settings:
`Settings > Emulation Settings > VUs`
Try different combinations of VU0/VU1 Advanced Recompiler Options. Only change one of them at a time, and keep trying all possible combinations. If none of these work, Restore Defaults and then try changing the Recompiler/Interpreter modes. Only try Interpreter as a last ditch effort.

#### Spikey Polygon Syndrome (SPS)
SPS is the tendency of world geometry or character models to deform into wildly incorrect shapes, usually resulting in the generation of spikes. This is almost always a VU problem. Navigate to the VU settings:
`Settings > Emulation Settings > VUs`
Try different combinations of VU0/VU1 Advanced Recompiler Options. Only change one of them at a time, and keep trying all possible combinations. If none of these work, Restore Defaults and then try changing the Recompiler/Interpreter modes. Only try Interpreter as a last ditch effort.

#### Menu items or text overlays missing
This is usually a VU issue, but can sometimes be an EE issue. Navigate to the VU settings:
`Settings > Emulation Settings > VUs`
Try different combinations of VU0/VU1 Advanced Recompiler Options. Only change one of them at a time, and keep trying all possible combinations. If none of these work, Restore Defaults and then try changing the Recompiler/Interpreter modes. Only try Interpreter as a last ditch effort. If the issue persists, navigate to the EE settings:
`Settings  > Emulation Settings > EE/IOP`
Try different combinations of EE/FPU Advanced Recompiler Options. Only change one of them at a time, and keep trying all possible combinations. If none of these work, Restore Defaults and then try changing the Recompiler/Interpreter modes. Only try Interpreter or Enable EE Cache as a last ditch effort.

#### AI pathfinding/vision and other behaviors, progress flags not triggering, or world objects missing
This is usually an EE issue, but can sometimes be a VU issue. Navigate to the EE settings:
`Settings  > Emulation Settings > EE/IOP`
Try different combinations of EE/FPU Advanced Recompiler Options. Only change one of them at a time, and keep trying all possible combinations. If none of these work, Restore Defaults and then try changing the Recompiler/Interpreter modes. Only try Interpreter or Enable EE Cache as a last ditch effort. If the issue persists, navigate to the VU settings:
`Settings  > Emulation Settings > VUs`
Try different combinations of VU0/VU1 Advanced Recompiler Options. Only change one of them at a time, and keep trying all possible combinations. If none of these work, Restore Defaults and then try changing the Recompiler/Interpreter modes. Only try Interpreter as a last ditch effort.

There are some known issues with specific games that are programming level issues rather than configuration level; please check the [PCSX2 Wiki](https://wiki.pcsx2.net/Main_Page) if these solutions do not help.

