cd lib/minilibx
make
apt install libxext-dev -y
apt install libxrandr-dev -y
apt install libx11-dev -y
apt install libbsd-dev -y
apt install libssl-dev -y

mkdir /usr/local/man/man1

cp man/man1/* /usr/local/man/man1/
cp libmlx.a /usr/local/lib/
cp mlx.h /usr/local/include/
