set -e
mkdir -p build
cd build
cmake ..
make
cd ..
mkdir -p build-ui/
~/Qt5.6.*/5.6*/gcc*/bin/qmake -o build-ui/
cd build-ui
make
cd ..
