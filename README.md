C++ program which reads a file where shapes are described, draws then into an image and saves the image. [More about the assignment](http://elf.cs.pub.ro/poo/arhiva/teme/2017/tema2)

Usage:
```shell
cmake -S . -B build
cd build
make
tema2 <input file> <output file>
```

Dependencies:
- CMake 3.18.3
- OpenCV 4.5.2

Design patterns used:
- Singleton
- Factory
- Visitor
