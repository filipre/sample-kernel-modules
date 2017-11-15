# README

Sample Linux Kernel Modules

## How to build

```
make
```

## How to list all modules

```
less /proc/modules
```

## How to start

```
sudo insmod [your module.ko]
```

## How to read logs

```
dmesg
```

or

```
less /var/log/syslog
```

## How to stop

```
sudo rmmod [your module]
```
