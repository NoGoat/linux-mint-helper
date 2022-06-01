mkdir ~/.helper
cp helper ~/.helper
cd ~/.helper
cwd=$(pwd)
sudo ln -s $cwd"/helper" /bin/