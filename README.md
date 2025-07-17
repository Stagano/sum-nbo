[Code]

sum-nbo.cpp

[Process]

$ echo -n -e \\x00\\x00\\x03\\xe8 > thousand.bin

$ echo -n -e \\x00\\x00\\x01\\xf4 > five-hundred.bin

$ echo -n -e \\x00\\x00\\x00\\xc8 > two-hundred.bin

$ ./sum-nbo thousand.bin five-hundred.bin two-hundred.bin


https://github.com/user-attachments/assets/0ccf6340-556c-43f6-8666-492af69b1663

