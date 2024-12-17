# ACTIVIDADES  Dispositivos de entrada y salida en Linux

## Actividad 1: Listar dispositivos conectados

#### Observaciones de los comandos

1. lsblk:

* Muestra información sobre los dispositivos de bloque conectados al sistema, como discos duros, SSD, particiones, y unidades extraíbles.

* La salida incluye columnas como el nombre del dispositivo, su tamaño, tipo (partición o disco), y puntos de montaje.

2. lsusb: 
* Lista todos los dispositivos conectados a los puertos USB.
* La salida incluye la identificación del fabricante y del producto, junto con detalles como el número de bus USB.

3. lspci: 
* Muestra todos los dispositivos conectados al bus PCI.
* Esto incluye tarjetas gráficas, tarjetas de red, controladores USB, y otros dispositivos internos.

4. dmesg | grep usb:
* Filtra los mensajes del kernel relacionados con dispositivos USB.
* Proporciona información detallada sobre eventos y estados de los dispositivos USB, como conexiones, desconexiones o errores.

### Respuesta a las preguntas

#### ¿Qué tipos de dispositivos se muestran en la salida de lsblk?

* Dispositivos de almacenamiento: discos duros (HDD), discos de estado sólido (SSD), unidades flash USB.

* Particiones: divisiones lógicas de los discos.
Puntos de montaje: directorios del sistema donde se acceden las particiones o dispositivos.

#### ¿Cuál es la diferencia entre lsusb y lspci?

* lsusb:
Lista dispositivos conectados a los puertos USB externos.
Incluye dispositivos periféricos como teclados, ratones, cámaras web, discos USB.

* lspci:
Lista dispositivos conectados al bus PCI, que suelen ser internos.
Incluye hardware como tarjetas gráficas, tarjetas de sonido, controladores de red o controladores USB.

#### ¿Qué información adicional proporciona dmesg | grep usb?

* Eventos del sistema relacionados con USB:

* Conexión y desconexión de dispositivos USB.

* Mensajes de error o advertencia relacionados con dispositivos USB.

* Configuración del kernel para dispositivos USB, como la asignación de controladores o recursos.

* Información sobre el estado del dispositivo, como fallos o reinicios.







## Actividad 2: Verificar dispositivos de almacenamiento

### Respuesta a las preguntas

#### ¿Qué dispositivos de almacenamiento están conectados a su sistema?

/dev/sda (40 GiB, disco virtual).

#### ¿Qué particiones están montadas actualmente?

/dev/sda1 montada en / con 40 GiB de espacio.

#### ¿Qué tipo de sistemas de archivos se usan en las particiones?

/dev/sda1 utiliza el sistema de archivos ext4.


## Actividad 3: Explorar dispositivos de entrada

### Respuesta a las preguntas

#### ¿Qué eventos genera cada dispositivo al interactuar con ellos?

* Teclado: Genera eventos EV_KEY cuando se presionan o liberan teclas.
* Mouse: Genera eventos EV_REL para movimientos y EV_KEY para clics de botones.
* Controladores USB adicionales: Generan eventos como EV_KEY (botones) o EV_ABS (movimientos analógicos).

#### ¿Cómo se identifican los dispositivos en /proc/bus/input/devices?

A través de los siguientes campos:
* N: → Nombre del dispositivo.
* H: → Handlers, como event0, event1.
* I: → Información del bus, vendor, y product ID.
* B: → Capacidades del dispositivo (EV, KEY, REL, etc.).

## Actividad 4: Examinar dispositivos de salida
###  Respuesta a las preguntas

#### ¿Qué salidas de video están disponibles en su sistema?

* Salida de video: Virtual-1.
* Resoluciones disponibles:
* 1920x1080 (actual)
* 1280x1024
* 1024x768
* 800x600
* 640x480

#### ¿Qué dispositivos de sonido se detectaron?
* Tarjeta de sonido: HDA Intel PCH
* Dispositivo: ALC892 Analog (Card 0, Device 0).

#### ¿Qué procesos están usando la tarjeta de sonido?
* Proceso en uso: pulseaudio
* PID: 1234
* Archivo de control: /dev/snd/controlC0.

## Actividad 5: Crear un script de resumen
### Respuesta a las preguntas

#### ¿Qué ventajas tiene usar un script para recopilar esta información?

* Automatización:
Permite ejecutar múltiples comandos de forma automática, ahorrando tiempo y evitando errores manuales al recopilar información.

* Reproducibilidad:
El script se puede reutilizar en diferentes sistemas o situaciones, asegurando que siempre se recopile la misma información.

* Centralización de la información:
Toda la salida se puede redirigir a un archivo, facilitando el análisis posterior o la entrega de reportes.

* Personalización:
Es fácil agregar o modificar comandos según las necesidades específicas del usuario o del sistema.

* Documentación:
Proporciona un registro claro de los comandos utilizados, lo que puede ser útil para fines de diagnóstico o auditorías.
#### ¿Qué cambios realizaría para personalizar el script?
1. Agregar fecha y hora al archivo de salida:
Para identificar cuándo se generó el reporte.
```bash
echo "Reporte generado el: $(date)" > "$OUTPUT_FILE"
```

2. Incluir más información del sistema:

* Versión del sistema operativo (lsb_release -a o cat /etc/os-release).
* Estado de la memoria y CPU (free -h y top -n 1 -b | head -n 10).
* Uso del disco (df -h).


3. Elegir archivo de salida dinámicamente:
Permitir que el usuario especifique un nombre para el archivo al ejecutar el script:
```bash
OUTPUT_FILE="${1:-resumendispositivos.txt}" 
```

4. Verificar dependencias:
Asegurarse de que los comandos requeridos están disponibles antes de ejecutarlos:
```bash
if ! command -v lsblk &> /dev/null; then
    echo "El comando lsblk no está disponible. Instálelo antes de continuar."
fi
```

## Actividad 6: Reflexión y discusión

### Respuesta a las preguntas

#### ¿Qué comando encontró más útil y por qué?

El comando lsblk fue muy útil porque permite ver rápidamente los discos y particiones conectados, junto con sus puntos de montaje. Es fácil de interpretar y esencial para trabajar con almacenamiento.

#### ¿Qué tan importante es conocer los dispositivos conectados al sistema?
Es muy importante porque ayuda a resolver problemas, configurar periféricos y asegurar que el sistema esté funcionando correctamente. También es útil para detectar dispositivos no autorizados o mal configurados.
#### ¿Cómo podrían estos conocimientos aplicarse en la administración de sistemas?
Se aplican al diagnosticar problemas de hardware, automatizar reportes con scripts y configurar correctamente dispositivos como discos o monitores. También son útiles en servidores para gestionar recursos y planificar actualizaciones.