# Defines a constant that is used later by the spec file.
%define shortname ac

# Name, brief description, and version 
Summary: AtenCalc - Command-line calculator
Name: %{shortname}
Version: 1.0
Release: 1
License: GPL
%define fullname %{name}-%{version}
# norootforbuild

# Define buildroot
BuildRoot: /var/tmp/%{fullname}

# Software group
Group: Productivity/Scientific/Chemistry

# Source tar ball.
Source: %{fullname}.tar.gz

# Location of the project's home page.
URL: http://www.projectaten.net

# Owner of the product.
Vendor: Tristan Youngs

# Packager of the product.
Packager: Tristan Youngs

# Boolean that specifies if you want to automatically determine some
# dependencies.
AutoReq: yes

# Basic package dependencies are listed here. For RedHat-based distros, libqt4 = qt4, and libqt4-devel = qt4-devel
BuildRequires: gcc-c++ readline-devel

# In-depth description.
%description
AtenCalc (ac) is a command-line calculator in the same vein as the Bash Calculator 'bc'. It provides quick and easy computation of simple or complex functions from the command line, and contains C-like flow constructs such as if, for, and while. ac permits user-defined functions, and recognises integer, real, and character string types.

%prep
%setup -q

# For the build, RedHat distros seem to need the path to the Qt4 binaries set explicitly. SuSE is fine.
%build

# Configure
./configure --with-build-dir=$RPM_BUILD_ROOT --with-install-dir=/usr --prefix=$RPM_BUILD_ROOT/usr 

make

%install
make install

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root)
%doc README TODO COPYING ChangeLog
/usr/bin/atc

%changelog
* Tue Mar 22 2011 Tristan Youngs <tris@projectaten.net> 
- initial version.
