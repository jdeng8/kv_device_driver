# kv_device_driver

 Implemented a loadable kernel module under Ubuntu Linux. 
 This kernel module will create a pseudo device that maintains a key-value store in kernel and allow different processes to share data through accessing this device. 

How to use it:
In the kernel_module directory, try to "make" with root permission (e.g. "sudo make"). If it success, you will see a "keyvalue.ko" under this directory. You can then type "make" using root permission to install the kernel module and the header into system directories. After you are done with this, you can now "insmod keyvalue.ko" using root. If this success, you can navigate to /dev directory and you should see a "keyvalue" device under this directory! However, at this point, this device doesn't really do anything. It's now your responsibility to endow this device with some features! You may need to unload the device by using "rmmod keyvalue" before you want to apply any change to the kernel module.

In the library directory, we provide an API for the application to interact with the device. You don't need to modify anything in the directory. However, you should read the library code to figure out how the library interact with the device to make things happen. To allow your application using this library, you need to "make all install" to have the library build and install in your system.

Finally, you will see a benchmark directory. In this directory, we provide two files for you to extend and test your kernel module. The benchmark.c file uses keyvalue_set function to update values stored by our kernel module while the validate.c file uses keyvalue_get function to retrieve data and compare if the values is the same as the ones from a log file. You may "make all" in this directory (you don't need root to do this) to see how these files works. You may need to include /usr/local/lib in your library path to avoid runtime errors.

