echo "Helper will be installed to $HOME/.helper."
echo "A symlink will be created in /bin."
echo "Options will arrive at a later date."
if [ -d ~/.helper ]; then
    if [ -e ~/.helper/helper ]; then
        rm ~/.helper/helper
    fi
    rmdir ~/.helper
fi
mkdir ~/.helper
cp helper ~/.helper
cd ~/.helper
if [ -e /bin/helper ]; then
    sudo rm /bin/helper
fi
cwd=$(pwd)
sudo ln -s $cwd"/helper" /bin/
