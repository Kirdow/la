# LA
**LA** is short for Lost Ark. Project name is irrelevant other than being made for Lost Ark. It's a small command line tool I made to make my life easier.

# Okay but what is it for?
I place this as la.exe in my user folder. This allows me to launch it by searching for CMD (Press win and start typing), which opens CMD in user folder, then just enter ``la`` and hit enter to run it. It holds some conversion and lazy utilities that I sometimes need. For these stuff I prefer having a keyboard based tool rather than UI based, thus this project is made.

# Can I use this?
Sure, MIT License for a reason, you're free to do anything with it.

# Can I contribute too?
Go ahead, I might not accept the pull request directly, so your best bet is to use your own fork in the meantime, but if it fits when I check the pull requests, I wouldn't hesitate merging.

# How do I use it?
Currently only supports Windows on x64, but after cloning, run ``.\scripts\Win-GenProjects.bat`` to generate a project for Visual Studio 2019. Then double click la.sln to open the project. Set mode to Dist and x64 and build. Then put the program in your user folder.
Edit the bat file to configure for a different IDE.

# Tools and Libraries used
- Visual Studio 2019
- Premake 5
- C++17

