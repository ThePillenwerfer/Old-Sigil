# Old-Sigil
Version 0.9.13 of Sigil Built on Debian 12 Bookworm.

This was the last version of Sigil to have Book View.  Old binaries can still be found but I couldn't get them to work on Debian Bookworm and neither could I get the code from Sigil's repository to build.  This version uses code from the Debian Buster repository.

One slight change was required as detailed in [changes.md](https://github.com/ThePillenwerfer/Old-Sigil/blob/main/changes.md)

Under **Releases** are two `.deb` packages.  Download both and install [`sigil-data_bookworm_all.deb`](https://github.com/ThePillenwerfer/Old-Sigil/releases/download/0.9.13/sigil-data_0.9.13_bookworm_all.deb)before [`sigil_0.9.13_bookworm_amd64.deb`](https://github.com/ThePillenwerfer/Old-Sigil/releases/download/0.9.13/sigil_0.9.13_bookworm_amd64.deb).  If you wish to switch to this version from a newer one that newer one needs to be removed first.  It may be possible to have both but if so I don't know, or care, how.

# Disclaimer
I did this for my own use but am happy to share it with anybody else on the basis that it may not work.  In theory it should work on other Debian-based Linuxes such as Ubuntu but this hasn't been tested.  It should be further noted that it is in no way endorsed by or connected to the people behind Sigil, Debian or anything else.

# Building
If the supplied debs don't work or you wish to build it yourself for some other reason this is what worked for me.

Download or clone this repository and extract the files to a directory.

Install Sigil's build dependencies and the things you need to build anything with:—

`sudo apt install build-essential fakeroot devscripts cmake debhelper-compat dh-python libhunspell-dev libjs-jquery libjs-jquery-scrollto libminizip-dev libpcre3-dev libqt5svg5-dev libqt5webkit5-dev libqt5xmlpatterns5-dev pkg-config python3-dev qtbase5-dev qttools5-dev qttools5-dev-tools zlib1g-dev`

Note: `sudo apt build-dep sigil` installs dependencies for current version and misses some that this version needs.

`cd` into the directory you put the source files in and run:—

`debuild -b -uc -us`

Go and have a cup of tea or something while it (hopefully) builds and creates the .deb files. If all has gone well the last thing on the screen will be "Finished running lintian."

The debs will be one directory up, ie if you put the files in `~/temp/sigil` they'll be in `~/temp`. Again `sigil-data_0.9.13+dfsg-1_all.deb` needs to be installed before `sigil_0.9.13+dfsg-1_amd64.deb`. `sigil-dbgsym_0.9.13+dfsg-1_amd64.deb` is not needed.
