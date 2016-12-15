# kv_device_driver

 Implemented a loadable kernel module under Ubuntu Linux. Achieved concurrency and fast searching by hash table and lock.
 This kernel module will create a pseudo device that maintains a key-value store in kernel and allow different processes to share data through accessing this device. 

How to use:
In the kernel_module directory, try to "make" with root permission (e.g. "sudo make"). If it success, you will see a "keyvalue.ko" under this directory. Then type "make" using root permission to install the kernel module and the header into system directories. After this is done, type "insmod keyvalue.ko" using root. If this success, you can navigate to /dev directory and you should see a "keyvalue" device under this directory! To unmount the device, using "rmmod"command.

In the library directory, an API for the application to interact with the device is provided. To allow application using this library, type "make all install" to have the library build and install in system. Include /usr/local/lib in your library path to avoid runtime errors.

In the benchmark directory provide two files to extend and test the kernel module.

