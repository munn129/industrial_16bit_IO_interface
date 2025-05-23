# industrial_16bit_IO_interface

## Intro
Industrial PCs are equipped with digital IO terminals.  
Since these IOs are based on **8-bit units**, when a **16-bit IO** is supported, one terminal essentially consists of two ports.  
This characteristic often makes function input/output code *not nice* and hard to manage.  

This repository was created to prevent such cases and simplify the IO handling process.

## 16-bit IO Interface
This interface is designed using **`enum`** types.  
Although still under development, the final goal of this repository is to simplify function input/output operations by using **enums** instead of directly passing port numbers and hex values.

### Before
```cpp
NKDIO_PollingReadDiByte(0, &inputBytePort0);
```

### After
```cpp
simpleWrite(Y1_HIGH);
```