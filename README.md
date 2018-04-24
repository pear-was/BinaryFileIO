# BinaryFileIO

Reads a binary file and outputs the result in a CDK matrix

##### Table of Contents  
[Notes](#notes)
[Other](#other)

Example output:
```
┌────────────────────────────────────────────────────────────────────────┐
│Binary File Contents                                                    │
│    a                      b                      c                     │
│   ┌─────────────────────┐┌─────────────────────┐┌─────────────────────┐│
│a  │Magic: 0xFEEDFACE    ││Version: 16          ││Records: 4           ││
│   └─────────────────────┘└─────────────────────┘└─────────────────────┘│
│   ┌─────────────────────┐┌─────────────────────┐┌─────────────────────┐│
│b  │strlen: 10           ││Seed Money           ││                     ││
│   └─────────────────────┘└─────────────────────┘└─────────────────────┘│
│   ┌─────────────────────┐┌─────────────────────┐┌─────────────────────┐│
│c  │strlen: 10           ││Leadership           ││                     ││
│   └─────────────────────┘└─────────────────────┘└─────────────────────┘│
│   ┌─────────────────────┐┌─────────────────────┐┌─────────────────────┐│
│d  │strlen: 16           ││Entrepreneurship     ││                     ││
│   └─────────────────────┘└─────────────────────┘└─────────────────────┘│
│   ┌─────────────────────┐┌─────────────────────┐┌─────────────────────┐│
│e  │strlen: 6            ││Skillz               ││                     ││
│   └─────────────────────┘└─────────────────────┘└─────────────────────┘│
└────────────────────────────────────────────────────────────────────────┘
```

## Notes:
The program can accept a binary file as an argument. For example:
```
./Program6 binaryfile.bin
```
If no arguments are given, it will default to *cs3377.bin*

## Other:
Project for CS3377
