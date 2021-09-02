mkdir a
echo hello > a/d
mkdir c
echo hello > c/d
echo hello > d
find . d | xargs grep hello
