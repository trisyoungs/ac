#!/bin/bash

# Prep AppDir tree for `ac`
APPNAME="AtenCalc"
APPVERSION="0.4.1"
APPDIR=${APPNAME}-${APPVERSION}.AppDir
BINARIES="src/ac"
DESKTOP="ci/appimage/com.projectaten.${APPNAME}.desktop"
META="ci/appimage/com.projectaten.${APPNAME}.appdata.xml"
ICONDIR="extra/"

# Enable erroring and verbosity
set -ev

# Create basic AppDir structure
rm -rf ${APPDIR}
mkdir -p ${APPDIR}/usr/bin
mkdir -p ${APPDIR}/usr/lib
mkdir -p ${APPDIR}/usr/share/applications
mkdir -p ${APPDIR}/usr/share/metainfo
mkdir -p ${APPDIR}/usr/share/icons/hicolor

# Copy in binaries
for b in $BINARIES
do
	if [ ! -e $b ]
	then
		echo "Error: Binary '$b' not found."
		exit 1
	fi
	cp $b ${APPDIR}/usr/bin
done

# Copy desktop file
if [ ! -e $DESKTOP ]
then
	echo "Error: Desktop file '$DESKTOP' does not exist."
	exit 1
fi
cp $DESKTOP ${APPDIR}/usr/share/applications

# Copy metainfo file
if [ ! -e $META ]
then
	echo "Error: Metainfo file '$META' does not exist."
	exit 1
fi
cp $META ${APPDIR}/usr/share/metainfo

# Search for and copy icons
for i in 64 128 256 512
do 
	icon=${ICONDIR}/icon-${i}x${i}.png
	if [ -e "${icon}" ]
	then
		mkdir -p ${APPDIR}/usr/share/icons/hicolor/${i}x${i}
		cp ${icon} ${APPDIR}/usr/share/icons/hicolor/${i}x${i}/${APPNAME}.png
	fi
done

# Retrieve linuxdeployqt
wget -q https://github.com/probonopd/linuxdeployqt/releases/download/continuous/linuxdeployqt-continuous-x86_64.AppImage -O linuxdeployqt
chmod u+x ./linuxdeployqt

# Run on the target binary
export VERSION=${APPVERSION}
./linuxdeployqt ${APPDIR}/usr/share/applications/*.desktop -appimage

