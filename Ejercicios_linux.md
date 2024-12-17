# Comandos de Entrada y Salida, Discos y Archivos

## Ejercicio 1: Montar y Desmontar Discos

1. Encuentra el dispositivo usando el comando:
```bash
lsblk
```

Salida:
```bash
NAME   MAJ:MIN RM   SIZE RO TYPE MOUNTPOINTS
loop0    7:0    0     4K  1 loop /snap/bare/5
loop1    7:1    0  73,9M  1 loop /snap/core22/1663
loop2    7:2    0  73,9M  1 loop /snap/core22/1722
loop3    7:3    0 269,8M  1 loop /snap/firefox/4793
loop4    7:4    0 273,6M  1 loop /snap/firefox/5187
loop5    7:5    0  10,7M  1 loop /snap/firmware-updater/127
loop6    7:6    0  11,1M  1 loop /snap/firmware-updater/147
loop7    7:7    0 505,1M  1 loop /snap/gnome-42-2204/176
loop8    7:8    0  91,7M  1 loop /snap/gtk-common-themes/1535
loop9    7:9    0  10,5M  1 loop /snap/snap-store/1173
loop10   7:10   0  38,8M  1 loop /snap/snapd/21759
loop11   7:11   0   500K  1 loop /snap/snapd-desktop-integration/178
loop12   7:12   0  44,3M  1 loop /snap/snapd/23258
loop13   7:13   0   568K  1 loop /snap/snapd-desktop-integration/253
loop14   7:14   0  10,8M  1 loop /snap/snap-store/1244
sda      8:0    0    30G  0 disk 
├─sda1   8:1    0     1M  0 part 
└─sda2   8:2    0    30G  0 part /
sdb      8:16   0  16,0G  0 disk 
└─sdb1   8:17   0  16,0G  0 part /mnt/usb
sr0     11:0    1  56,9M  0 rom  /media/annatar/VBox_GAs_7.1.4
```

2. Monta la memoria USB en un directorio, por ejemplo, `/mnt/usb`:

```bash
sudo mount /dev/sdX1 /mnt/usb
```

3. Verifica que esté montado correctamente:
```bash
df -h
```

Salida:
 ```bash
Sys. de archivos     Size  Used Avail Use% Montado en
/dev/sda2             30G   10G   20G  34% /
tmpfs                  1.9G  1.2M  1.9G   1% /dev/shm
/dev/sdb1             16G   2.1G   13G  14% /mnt/usb
/dev/sr0              56M   5.4M   51M  10% /media/annatar/VBox_GAs_7.1.4
```

4. Copia un archivo desde tu directorio personal al dispositivo USB:
```bash
cp archivo.txt /mnt/usb/
```
5. Desmonta la memoria USB:

```bash
sudo umount /mnt/usb
```

Salida de la verificacion: 
```bash
NAME   MAJ:MIN RM   SIZE RO TYPE MOUNTPOINTS
loop0    7:0    0     4K  1 loop /snap/bare/5
loop1    7:1    0  73,9M  1 loop /snap/core22/1663
loop2    7:2    0  73,9M  1 loop /snap/core22/1722
loop3    7:3    0 269,8M  1 loop /snap/firefox/4793
loop4    7:4    0 273,6M  1 loop /snap/firefox/5187
loop5    7:5    0  10,7M  1 loop /snap/firmware-updater/127
loop6    7:6    0  11,1M  1 loop /snap/firmware-updater/147
loop7    7:7    0 505,1M  1 loop /snap/gnome-42-2204/176
loop8    7:8    0  91,7M  1 loop /snap/gtk-common-themes/1535
loop9    7:9    0  10,5M  1 loop /snap/snap-store/1173
loop10   7:10   0  38,8M  1 loop /snap/snapd/21759
loop11   7:11   0   500K  1 loop /snap/snapd-desktop-integration/178
loop12   7:12   0  44,3M  1 loop /snap/snapd/23258
loop13   7:13   0   568K  1 loop /snap/snapd-desktop-integration/253
loop14   7:14   0  10,8M  1 loop /snap/snap-store/1244
sda      8:0    0    30G  0 disk 
├─sda1   8:1    0     1M  0 part 
└─sda2   8:2    0    30G  0 part /
sr0     11:0    1  56,9M  0 rom  /media/annatar/VBox_GAs_7.1.4
```
## Ejercicio 2: Redirección de Entrada y Salida

1. Lista los archivos de tu directorio actual y guarda el resultado en un archivo `listado.txt`:
```bash
ls -l > listado.txt
```

2. Muestra el contenido del archivo en la terminal:
```bash
cat listado.txt 
```

Salida:
```bash
total 4
-rw-r--r-- 1 annatar annatar  1,2K dic 16 10:05 listado.txt
-rw-r--r-- 1 annatar annatar  3,4K dic 16 10:00 archivo.txt
-rw-r--r-- 1 annatar annatar  2,1K dic 16 09:58 script.sh
```

3. Añade la fecha actual al final del archivo:
```bash
date >> listado.txt
```

4. Muestra todo el contenido del archivo nuevamente:
```bash
cat listado.txt
```

Salida:
```bash
total 4
-rw-r--r-- 1 annatar annatar  1,2K dic 16 10:05 listado.txt
-rw-r--r-- 1 annatar annatar  3,4K dic 16 10:00 archivo.txt
-rw-r--r-- 1 annatar annatar  2,1K dic 16 09:58 script.sh
lun dic 16 10:06:42 UTC 2024
```

## Ejercicio 3: Copiar y Mover Archivos

1. Crea un archivo de texto llamado `archivo1.txt`:
```bash
echo "Este es un archivo de prueba" > archivo1.txt
```

Verificacion:

```bash
cat archivo1.txt
```

Salida:
```bash
Este es un archivo de prueba
```


2. Copia este archivo a otro directorio, por ejemplo, `/tmp`:
```bash
cp archivo1.txt /tmp/
```

3. Renombra el archivo copiado a `archivo2.txt` en `/tmp`:
```bash
mv /tmp/archivo1.txt /tmp/archivo2.txt
```

4. Mueve el archivo `archivo2.txt` de vuelta a tu directorio actual:
```bash
mv /tmp/archivo2.txt.
```

## Ejercicio 4: Comprimir y Descomprimir Archivos
1. Crea el directorio:
```bash
mkdir backup
```

2. Copia un archivo al directorio:
```bash
cp archivo1.txt backup/
```


3. Comprime el directorio `backup` en un archivo `.tar.gz`:
```bash
tar -czvf backup.tar.gz backup/
```

Salida:
```bash
backup/
backup/archivo1.txt
```


4. Borra el directorio original y extrae el contenido del archivo comprimido:
```bash
tar -xzvf backup.tar.gz
```

## Ejercicio 5: Permisos y Propiedades de Archivos
1. Crea un archivo llamado `privado.txt`:
```bash
touch privado.txt
```

2. Cambia los permisos del archivo para que solo el propietario pueda leer y escribir:
```bash
chmod 600 privado.txt
```


3. Cambia el propietario del archivo a otro usuario (si tienes privilegios):
```bash
sudo chown Annatar2 privado.txt
```
Verificacion:

```bash
ls -l privado.txt
```

Salida:
```bash
-rw------- 1 Annatar2 usuario 0 dic 16 10:10 privado.txt
```

## Ejercicio 6: Exploración de Dispositivos
1. Usa `lsblk` para listar los discos y particiones:
```bash
lsblk
```

Salida:
```bash
NAME   MAJ:MIN RM   SIZE RO TYPE MOUNTPOINTS
sda      8:0    0    30G  0 disk 
├─sda1   8:1    0     1M  0 part 
└─sda2   8:2    0    30G  0 part /
sr0     11:0    1  56,9M  0 rom  /media/annatar/VBox_GAs_7.1.4
```


2. Usa `du -sh` para ver el tamaño del contenido en un directorio de tu elección:
```bash
du -sh /ruta/directorio
```

Salida:
```bash
1.2G    /home/usuario
```

3. Verifica el uso de disco con `df -h`:
```bash
df -h
```

Salida:
```bash
Filesystem      Size  Used Avail Use% Mounted on
/dev/sda2        30G   10G   20G  34% /
/dev/sda1       1M     1M     0   100% /boot/efi
tmpfs            2G    1M    2G   1% /tmp
/dev/sr0         56M  56M     0  100% /media/annatar/VBox_GAs_7.1.4
```
## Ejercicio 7: Crear y Formatear Particiones
1. Identifica un disco no particionado:
```bash
sudo fdisk -l
```
Salida:
```bash
Discos del sistema:
Disk /dev/sda: 30 GB
Sector size (logical/physical): 512 bytes / 512 bytes
Particiones:
/dev/sda1 1M
/dev/sda2 30G

Disk /dev/sdb: 50 GB
Sector size (logical/physical): 512 bytes / 512 bytes
Particiones:
(sin particiones)
```

2. Usa `fdisk` para crear una nueva partición
```bash
sudo fdisk /dev/sdX
```

Salida:
```bash
Command (m for help): n
Partition type:
p   primary (0 primary, 0 extended, 4 free)
e   extended
Select (default p): p
Partition number (1-4, default 1): 1
First sector (2048-104857599, default 2048): 
Last sector, +sectors or +size{K,M,G,T,P} (2048-104857599, default 104857599): 

Created a new partition 1 of type 'Linux' and of size 50 GiB.

Command (m for help): w
The partition table has been altered.
```


3. Formatea la partición como `ext4`:
```bash
sudo mkfs.ext4 /dev/sdX1
```
Salida:
```bash
mke2fs 1.45.5 (07-Jan-2020)
Creating filesystem with 13107200 4k blocks and 3276800 inodes
Filesystem UUID: a0e0f0d5-3f2c-4b1b-b5d1-3b6f6a5b9f3b
Superblock backups stored on blocks:
    32768, 98304, 163840, 229376, 294912

Allocating group tables: done
Writing inode tables: done
Writing superblocks and filesystem accounting information: done
```

4. Crea un directorio para montar la nueva partición:
```bash
sudo mkdir /mnt/nueva_particion
```


5. Monta la partición en un directorio y prueba escribiendo archivos en ella:
```bash
sudo mount /dev/sdX1 /mnt/nueva_particion
echo "Prueba de escritura" > /mnt/nueva_particion/test.txt
```
Verificacion:

```bash
cat /mnt/nueva_particion/test.txt
```

Salida:
```bash
Prueba de escritura
```