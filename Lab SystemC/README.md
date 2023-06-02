# Lab System C

## Setup :

### Installation :

```bash
# Download packages
wget http://www.accellera.org/images/downloads/standards/systemc/systemc-2.3.3.gz
# Unpack the packages
tar -xzf systemc-2.3.3.gz
sudo mkdir /usr/local/systemc-2.3.3/
cd systemc-2.3.3 && mkdir objdir && cd objdir
# Installation
sudo ../configure --prefix=/usr/local/systemc-2.3.3/
sudo make -j$(nproc)
sudo make install
```

### Visual Studio Code

```bash
# Add to include path
/usr/local/systemc-2.3.3/
/usr/local/systemc-2.3.3/include
```