# Actividad Final

## Sistemas de Archivos

### Ejercicio 1: Concepto y noción de archivo real y virtual


#### Define el concepto de archivo real y archivo virtual.

1. Archivo real: Un archivo real es un archivo físico que se almacena en un dispositivo de almacenamiento, como un disco duro, SSD, CD, etc. Este archivo tiene una ubicación física y un tamaño determinado. Los sistemas operativos gestionan estos archivos accediendo directamente a los bloques de datos en el dispositivo de almacenamiento.

    Características de un archivo real:

    * Tiene una ubicación física en el sistema de almacenamiento.
    * Su tamaño es determinado por los datos que contiene.
    * El sistema operativo gestiona la creación, lectura, escritura y eliminación de estos archivos, y se puede acceder a ellos directamente desde el sistema de archivos.

2. Archivo virtual: Un archivo virtual no tiene una ubicación física en un dispositivo de almacenamiento, sino que se maneja como una abstracción proporcionada por el sistema operativo o una aplicación. En lugar de representar un conjunto de bloques de datos en un disco físico, un archivo virtual puede representar datos almacenados en memoria, en la nube, o ser simplemente una abstracción que permita manipular información sin tener que tratar con los detalles físicos.

    Características de un archivo virtual:

    * No tiene una representación física en el disco.
    * Puede estar basado en memoria o en recursos temporales.
    * Es accesible de manera similar a los archivos reales, pero su contenido no está necesariamente almacenado en un dispositivo físico permanente.

#### Ejemplos de cómo los sistemas operativos manejan archivos reales y virtuales

1. Archivos reales:


* Acceso directo en el sistema de archivos: Los archivos reales se almacenan en un sistema de archivos (como ext4, NTFS, FAT, etc.). Los sistemas operativos gestionan estos archivos permitiendo la lectura, escritura, eliminación y manipulación de datos. Tiene una ubicación física en el sistema de almacenamiento.
* Ejemplo: En Linux, un archivo de texto almacenado en /home/usuario/documento.txt se puede abrir con un editor de texto, modificar y guardar. El sistema operativo maneja el acceso y almacenamiento en el disco.
    

2. Archivos virtuales:


* Archivos de dispositivo: En sistemas UNIX y Linux, los archivos virtuales pueden representar dispositivos o recursos del sistema. Por ejemplo, el archivo /dev/null es un archivo virtual que actúa como un sumidero de datos. Cualquier cosa escrita en él se descarta.
* Archivos en memoria: Algunos sistemas operativos permiten crear archivos virtuales en memoria, como los archivos temporales o de intercambio, que no están asociados a un dispositivo de almacenamiento físico. Estos archivos pueden ser gestionados como si fueran archivos reales, pero en realidad están siendo manipulados por el sistema operativo en memoria.
* Ejemplo: En Linux, puedes usar tmpfs para crear un sistema de archivos temporal en memoria. Si montas un directorio en tmpfs, los archivos en ese directorio no se almacenan en el disco físico, sino que permanecen en la memoria RAM.
    
#### Caso práctico donde un archivo virtual sea más útil que un archivo real

Caso práctico: Archivos temporales y procesamiento de datos en memoria

Supón que estás desarrollando una aplicación que realiza un procesamiento intensivo de datos, como la compresión o el análisis de grandes archivos de texto. En lugar de escribir los resultados intermedios a un archivo real en disco, podrías utilizar archivos virtuales basados en memoria para almacenar los datos temporalmente mientras se procesan.

* Ventajas de usar archivos virtuales en este caso:

    * Rendimiento: Los archivos virtuales en memoria (por ejemplo, usando tmpfs en Linux) pueden ser mucho más rápidos que los archivos reales porque no requieren acceso a disco, lo que mejora el rendimiento de las operaciones de lectura y escritura.

    * Uso de recursos temporales: No es necesario preocuparnos por el espacio en disco, ya que los archivos virtuales se almacenan en la memoria. Esto es útil para operaciones que requieren grandes cantidades de datos temporales que no necesitan ser guardados permanentemente.

    * Automatización: Los archivos virtuales se pueden generar, modificar y eliminar automáticamente durante la ejecución del proceso sin necesidad de intervención manual o mantenimiento de archivos temporales en el disco.

* Ejemplo de uso: Imagina un programa que realiza análisis de grandes volúmenes de datos en tiempo real (por ejemplo, procesamiento de logs o datos de sensores). En lugar de escribir cada resultado a disco, el programa puede usar un archivo virtual para almacenar los resultados intermedios y liberar recursos rápidamente cuando ya no son necesarios, sin necesidad de manejar archivos físicos.







### Ejercicio 2: Componentes de un sistema de archivos


#### Componentes clave de un sistema de archivos

Un sistema de archivos es responsable de organizar, almacenar y gestionar los archivos en un dispositivo de almacenamiento. Los componentes clave de un sistema de archivos incluyen:

* Metadatos: Son datos que describen los archivos, como el nombre del archivo, el propietario, los permisos de acceso, la fecha de creación, el tamaño, etc. Los metadatos no contienen los datos reales del archivo, sino información sobre cómo acceder a esos datos.

* Tablas de asignación: Son estructuras de datos que mantienen un registro de qué bloques del almacenamiento físico están ocupados por qué archivos. En sistemas de archivos como EXT4 y NTFS, estas tablas gestionan la asignación y liberación de bloques de disco.

* Inodos: En sistemas de archivos como EXT4, los inodos son estructuras que contienen los metadatos de un archivo, como su ubicación en el disco, el tamaño, las fechas de acceso y modificación, y los permisos. No contienen el nombre del archivo, que está almacenado en una tabla separada.

* Directores y archivos: Las estructuras de directorios organizan los archivos en una jerarquía. Cada archivo tiene un nombre y una entrada en un directorio que lo vincula con su inodo (en sistemas como EXT4).

* Bloques de datos: Son las unidades físicas en las que se almacenan los datos reales de un archivo. Dependiendo del sistema de archivos, estos bloques pueden ser de tamaño fijo o variable.

* Superbloques: Un superbloque contiene información crítica sobre el sistema de archivos, como el tipo de sistema de archivos, el tamaño de los bloques, el número de bloques totales y libres, y otros parámetros que permiten al sistema operativo montar y acceder al sistema de archivos correctamente.

####  Cuadro comparativo: Componentes en EXT4 y NTFS

### Cuadro comparativo: Componentes en EXT4 y NTFS

| **Componente**         | **EXT4**                                          | **NTFS**                                        |
|------------------------|--------------------------------------------------|------------------------------------------------|
| **Metadatos**           | Almacena metadatos en inodos, que son estructuras de datos que incluyen permisos, fechas, y ubicación del archivo. | Almacena metadatos en el MFT (Master File Table), que contiene información similar a los inodos. |
| **Tablas de asignación**| Usa tablas de bloques y estructuras como los "block groups" para asignar bloques de datos. | Usa el MFT para almacenar información de los archivos, que incluye la asignación de bloques de datos. |
| **Inodos**              | Los inodos contienen toda la información relevante sobre un archivo, excepto su nombre. | NTFS no utiliza inodos, sino que usa la MFT para almacenar toda la información, incluidas las direcciones de los bloques. |
| **Estructura de Directorios** | Los directorios son archivos especiales que contienen una lista de nombres de archivos junto con sus inodos correspondientes. | Los directorios son gestionados por la MFT, que almacena las ubicaciones de los archivos en su interior. |
| **Bloques de Datos**    | Los bloques de datos son las unidades de almacenamiento en las que se almacenan los datos reales de los archivos. El tamaño de bloque es configurable. | El tamaño de los bloques de datos se define en la configuración del sistema, con un tamaño por defecto de 4 KB. |
| **Superbloques**        | El superbloque contiene la información sobre el sistema de archivos, como el tamaño de los bloques y la cantidad de bloques libres. | En NTFS, la información similar al superbloque está contenida en el MFT y en el boot sector. |
| **Journaling**          | Sí, EXT4 tiene journaling para garantizar la integridad del sistema de archivos. | Sí, NTFS también tiene journaling para proteger la integridad de los datos. |
| **Soporte para Archivos Grandes** | Soporta hasta 16 TiB por archivo. | Soporta hasta 16 TiB por archivo, con una capacidad total de volumen de hasta 256 TiB. |


#### Ventajas y desventajas de EXT4 y NTFS basados en sus componentes

##### EXT4:

Ventajas:

* Rendimiento: EXT4 es muy eficiente en el manejo de archivos pequeños y grandes, y el uso de journaling mejora la fiabilidad al evitar la corrupción de datos.
* Compatibilidad: EXT4 es ampliamente utilizado en sistemas Linux, lo que garantiza una buena integración y soporte.
* Journaling: El sistema de journaling de EXT4 ayuda a proteger la integridad del sistema de archivos ante fallos de energía o caídas del sistema.
* Escalabilidad: EXT4 puede manejar grandes volúmenes de datos (hasta 16 TiB por archivo), y es adecuado para sistemas con grandes necesidades de almacenamiento.


Desventajas:

* Compatibilidad limitada: Aunque existen herramientas para leer EXT4 en sistemas Windows (como ext2fsd), no es tan común como NTFS en plataformas no Linux.
* Complejidad en la recuperación: Aunque EXT4 es robusto, su recuperación de datos puede ser más compleja en comparación con NTFS cuando ocurre un fallo grave del sistema.


##### NTFS:

Ventajas:

* Compatibilidad con Windows: NTFS es el sistema de archivos estándar para los sistemas operativos Windows, por lo que es ideal para entornos en los que se utilizan estas plataformas.
* Journaling: Al igual que EXT4, NTFS también usa journaling, lo que mejora la fiabilidad y la recuperación ante fallos.
* Seguridad avanzada: NTFS permite establecer permisos de archivos muy detallados y ofrece soporte para cifrado (EFS), lo que lo hace más seguro que sistemas de archivos más simples.
* Soporte de archivos grandes: NTFS soporta archivos de hasta 16 TiB, lo que lo hace adecuado para grandes archivos multimedia o bases de datos.


Desventajas:

* Rendimiento en Linux: Aunque NTFS es soportado en Linux a través de herramientas como ntfs-3g, su rendimiento no es tan eficiente como EXT4 en sistemas Linux.
* Espacio de almacenamiento adicional: NTFS tiende a usar más espacio para almacenar metadatos y mantener la integridad del sistema de archivos debido a su estructura de MFT.

### Ejercicio 3: Organización lógica y física de archivos

####  Árbol jerárquico de directorios y subdirectorios
```plaintext
/
├── bin/
│   ├── ls
│   ├── cp
│   └── mv
├── home/
│   ├── usuario/
│   │   ├── documentos/
│   │   │   ├── archivo1.txt
│   │   │   └── archivo2.txt
│   │   ├── música/
│   │   └── videos/
│   └── guest/
├── var/
│   ├── log/
│   └── tmp/
├── etc/
│   ├── fstab
│   └── passwd
└── usr/
    ├── lib/
    └── share/
```

#### Cómo se traduce la dirección lógica a la dirección física en el disco

La dirección lógica es el camino que seguimos dentro del sistema de archivos (por ejemplo, /home/usuario/documentos/archivo1.txt). Esta ruta es abstracta y se refiere a la ubicación del archivo o directorio en el sistema de archivos desde el punto de vista del usuario.

La dirección física es la ubicación real del archivo en el disco. Esta ubicación se corresponde con bloques físicos en el dispositivo de almacenamiento, que son gestionados por el sistema de archivos.

El proceso para traducir la dirección lógica a la física involucra varios pasos:

1. Resolución de la ruta:

    * Cuando un programa o usuario accede a un archivo utilizando una ruta lógica (como /home/usuario/documentos/archivo1.txt), el sistema de archivos comienza a analizar cada componente de la ruta.
    * El sistema de archivos busca en el directorio correspondiente y encuentra la entrada que hace referencia al archivo.
2. Inodos y bloques:

    * En sistemas como EXT4, cada archivo tiene un inodo que contiene información sobre el archivo (como el propietario, permisos, y la ubicación de los bloques de datos).
    * El inodo no contiene los datos del archivo, sino punteros a los bloques de datos en el dispositivo de almacenamiento.
    * Una vez que se encuentra el inodo del archivo, el sistema de archivos traduce la dirección lógica a los punteros de bloques físicos en el disco.
3. Acceso físico:

    * El sistema de archivos accede a los bloques físicos correspondientes en el disco y lee o escribe los datos del archivo.

#### Ejemplo práctico de cómo un archivo se almacena físicamente

Supongamos que tenemos el archivo archivo1.txt en la ruta /home/usuario/documentos/archivo1.txt.

1. Dirección lógica:

    * El usuario proporciona la ruta lógica /home/usuario/documentos/archivo1.txt.
2. Resolución de la ruta:

    * El sistema de archivos busca en la tabla de directorios para encontrar el directorio documentos dentro del directorio usuario en /home.
    * Luego, localiza el archivo archivo1.txt dentro de ese directorio.
3. Inodo:

    * El sistema de archivos encuentra el inodo correspondiente al archivo archivo1.txt.
    * El inodo contiene metadatos, como el tamaño del archivo, las fechas de creación/modificación, los permisos y, crucialmente, los punteros a los bloques de datos.
4. Bloques de datos:

    * El sistema de archivos traduce esos punteros a bloques físicos en el disco.
    * Por ejemplo, el archivo archivo1.txt puede estar almacenado en los bloques 1000, 1001 y 1002 en el disco. El sistema de archivos utiliza estos punteros para acceder a los datos físicos.
5. Acceso físico:

    * Cuando se solicita leer o escribir el archivo, el sistema de archivos accede a los bloques físicos en el disco (por ejemplo, los bloques 1000-1002), recupera o actualiza los datos y luego los presenta al usuario o proceso solicitante.

### Ejercicio 4: Mecanismos de acceso a los archivos

#### Definición de los diferentes mecanismos de acceso a archivos

Los mecanismos de acceso a archivos definen cómo los sistemas operativos o aplicaciones leen y escriben datos en un archivo. Existen tres mecanismos principales:

1. Acceso Secuencial
    * Descripción: En el acceso secuencial, los datos se leen o escriben en el archivo de manera lineal, uno tras otro. Es decir, se procesa todo el contenido del archivo en el orden en que está almacenado, sin saltarse ninguna parte. Este tipo de acceso es el más común para archivos de texto o registros.
    * Ventaja: Es sencillo y eficiente cuando se necesita procesar todo el archivo.
    * Desventaja: No permite acceso rápido a partes específicas del archivo si el tamaño es grande.
2. Acceso Directo (Aleatorio)
    * Descripción: El acceso directo permite leer o escribir en cualquier parte del archivo sin necesidad de recorrerlo secuencialmente. Se puede acceder a un byte o bloque específico directamente, utilizando una posición o índice. Este tipo de acceso es útil para bases de datos, archivos de gran tamaño o cuando se necesita acceso rápido a datos específicos.
    * Ventaja: Acceso rápido a cualquier parte del archivo.
    * Desventaja: Es más complejo de implementar y puede ser ineficiente si se abusa del acceso aleatorio.
3. Acceso Indexado
    * Descripción: En el acceso indexado, el archivo tiene una estructura de índice que mapea claves o identificadores a ubicaciones específicas dentro del archivo. El índice sirve como un "mapa" que permite localizar rápidamente los datos sin necesidad de recorrer todo el archivo.
    * Ventaja: Permite un acceso rápido a los datos sin necesidad de recorrer secuencialmente el archivo.
    * Desventaja: Requiere espacio adicional para almacenar el índice y puede ser más costoso en términos de tiempo para actualizaciones.

#### Pseudocódigo para acceder a un archivo
1. Acceso Secuencial    
```
Abrir archivo en modo de lectura
Mientras no llegues al final del archivo:
    Leer siguiente línea o bloque de datos
    Procesar los datos leídos
Cerrar archivo
```
* Explicación: Este pseudocódigo muestra cómo acceder secuencialmente a un archivo. El archivo se abre en modo lectura, y el sistema lee y procesa los datos uno por uno hasta llegar al final del archivo.

2. Acceso Directo (Aleatorio) mediante su Posición
```
Abrir archivo en modo de lectura/escritura
Posicionarse en la ubicación deseada del archivo (por ejemplo, byte 100)
Leer datos desde esa posición
Escribir datos en esa posición (si es necesario)
Cerrar archivo
```
* Explicación: Este pseudocódigo muestra cómo acceder secuencialmente a un archivo. El archivo se abre en modo lectura, y el sistema lee y procesa los datos uno por uno hasta llegar al final del archivo. 

3. Acceso Indexado

```
Abrir archivo de índice
Buscar clave en el índice
Si la clave existe:
    Obtener la dirección o posición del dato en el archivo
    Abrir archivo de datos
    Leer el dato en la posición obtenida
    Procesar el dato
Cerrar archivo de datos
Cerrar archivo de índice
```

* Explicación: En el acceso indexado, primero se abre el archivo que contiene el índice. Se busca la clave en el índice, y si se encuentra, se obtiene la dirección o posición donde está almacenado el dato en el archivo de datos. Luego se abre el archivo de datos, se lee el dato en la posición obtenida y se procesa.

#### Comparación de las Ventajas de Cada Mecanismo de Acceso a Archivos Según el Caso de Uso

Cada mecanismo de acceso a archivos (secuencial, directo e indexado) tiene ventajas específicas según el tipo de aplicación y el caso de uso. A continuación, se detallan las ventajas de cada mecanismo en diferentes contextos:

1. Acceso secuencial

* Ventajas:
    * Simplicidad: El acceso secuencial es fácil de implementar y utilizar. No requiere estructuras adicionales como índices o punteros.
    * Eficiencia en procesamiento por lotes: Es ideal cuando los datos deben procesarse en su totalidad, como en el caso de archivos de texto, logs o registros.
    * Requiere menos recursos: No necesita estructuras complejas de almacenamiento como índices o punteros, lo que reduce el uso de memoria y espacio.
* Aplicaciones típicas:
    * Archivos de registro (logs) donde se procesa la información en orden cronológico.
    * Bases de datos simples con pequeñas cantidades de datos donde no se requiere acceso rápido.
    * Archivos de texto o grandes archivos de datos en los que se procesan fila por fila.
* Casos de Uso:
    * Generación de informes: Si se generan informes o se procesan registros de manera secuencial, como en archivos de logs o reportes de ventas.
    * Procesamiento de archivos grandes: Cuando se necesita procesar todo el archivo sin preocuparse por saltarse ninguna parte (ej., archivado o copiado de datos).

2. Acceso Directo (Aleatorio)
* Ventajas:
    * Acceso rápido a cualquier parte del archivo: Permite saltar a cualquier posición dentro del archivo sin tener que recorrer todo el archivo, lo que acelera el proceso si se necesita acceder a datos específicos.
    * Eficiencia para archivos grandes: Ideal para bases de datos, archivos de gran tamaño o cuando se necesita acceso frecuente y rápido a diferentes partes del archivo.
    * Flexibilidad: Es posible leer o escribir en cualquier punto del archivo sin depender del orden.
* Casos de Uso:
    * Bases de datos: Cuando se necesita un acceso rápido y aleatorio a registros específicos, como en sistemas de bases de datos que almacenan grandes volúmenes de datos y requieren consultas rápidas.
    * Sistemas de archivos grandes: Cuando se manejan archivos grandes como imágenes, videos o grandes documentos, donde solo se requieren ciertas partes del archivo.
* Aplicaciones Típicas:
    * Bases de datos de clientes o productos: Donde se pueden consultar registros específicos rápidamente (ej., buscar una entrada por ID).
    * Archivos multimedia: Cuando se necesita acceder rápidamente a partes de un archivo de video o imagen sin procesar el contenido secuencialmente.
3. Acceso Indexado
* Ventajas:
    * Acceso eficiente y rápido: El uso de un índice permite localizar rápidamente los datos, sin necesidad de buscar secuencialmente en el archivo completo, lo que mejora la velocidad de búsqueda en archivos grandes.
    * Optimización de búsquedas: Permite realizar búsquedas basadas en claves específicas sin tener que recorrer todo el archivo, lo cual es fundamental cuando el archivo contiene grandes cantidades de datos.
    * Reducción de la duplicación de datos: El índice puede hacer referencia a las ubicaciones sin necesidad de duplicar la información en el archivo.
    * Facilidad para actualizaciones y eliminaciones: Facilita la modificación o eliminación de elementos sin tener que reorganizar todo el archivo.
* Casos de Uso:
    * Sistemas de bases de datos complejas: Donde se requiere una búsqueda rápida y eficiente de registros utilizando claves o índices.
    * Archivos de datos estructurados: En archivos que almacenan datos organizados, como tablas, registros o listas, donde los elementos pueden ser localizados a través de un índice.
* Aplicaciones Típicas:
    * Sistemas de archivos de bases de datos: Como sistemas de bases de datos relacionales (por ejemplo, MySQL, PostgreSQL), donde los índices mejoran el rendimiento de las consultas.
    * Sistemas de almacenamiento de documentos: Donde se necesitan búsquedas rápidas de documentos usando palabras clave o identificadores únicos.

| **Mecanismo**          | **Ventajas**                                                                                                                                  | **Casos de Uso**                                                                                                                                                     |
|------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Acceso Secuencial**   | - Fácil de implementar y usar. <br> - Eficiente para procesamiento por lotes. <br> - Requiere menos recursos (sin índices ni estructuras). | - Archivos de texto o logs. <br> - Archivos donde se procesan todo el contenido (por ejemplo, análisis de registros). <br> - Sistemas con recursos limitados. |
| **Acceso Directo**      | - Acceso rápido a cualquier parte del archivo. <br> - Eficiente para archivos grandes o acceso frecuente a partes específicas.               | - Bases de datos donde se necesita acceso rápido. <br> - Archivos grandes como videos, imágenes, grandes documentos.                                               |
| **Acceso Indexado**     | - Búsquedas rápidas y eficientes con índices. <br> - Optimiza la búsqueda y acceso a datos específicos. <br> - Reduce la duplicación de datos. | - Bases de datos complejas (ej., SQL). <br> - Archivos de datos estructurados donde se necesita localizar información rápida y eficiente (ej., bibliotecas).       |

### Ejercicio 5: Modelo jerárquico y mecanismos de recuperación en caso de falla

#### Modelo Jerárquico del Sistema de Archivos
```
/ (raíz)
├── /home
│   ├── /home/usuario1
│   │   ├── /home/usuario1/documentos
│   │   ├── /home/usuario1/imagenes
│   │   └── /home/usuario1/videos
│   ├── /home/usuario2
│   │   ├── /home/usuario2/documentos
│   │   ├── /home/usuario2/imagenes
│   │   └── /home/usuario2/videos
│   └── /home/usuario3
│       ├── /home/usuario3/documentos
│       ├── /home/usuario3/imagenes
│       └── /home/usuario3/videos
├── /etc
│   ├── /etc/nginx
│   ├── /etc/apache2
│   └── /etc/ssh
└── /var
    ├── /var/log
    ├── /var/www
    └── /var/tmp
```
#### Simulación de Falla

Escenario de Falla:

El directorio /home/usuario2/documentos se corrompe o elimina accidentalmente.

Pasos para Recuperar los Datos:

1. Verificacion inicial:

* Comprueba que el directorio está dañado o eliminado:
```bash
ls /home/usuario2
```

* Si el directorio no aparece, confirma la falla.


2. Restauracion desde respaldo

* Si cuentas con un sistema de respaldo, restaura el directorio desde ahí.
* Ejemplo con rsync
```bash
rsync -av /backup/home/usuario2/documentos/ /home/usuario2/documentos/
```
3. Verificacion del respaldo

* Verifica que los archivos recuperados sean funcionales.

#### Herramientas y Técnicas de Respaldo

##### 1. Copias de Seguridad Programadas
* Automatiza respaldos regulares con cron y herramientas como rsync o tar.
* Ejemplo de tarea programada con cron:
```bash
0 2 * * * rsync -av /home /backup/home
```

##### 2. Respaldo Incremental
* Realiza copias solo de los cambios desde el último respaldo, ahorrando espacio.
* Usa herramientas como rsnapshot o BorgBackup.

##### 3. Copias de Seguridad en la Nube
* Almacena datos en servicios como Amazon S3, Google Drive o Dropbox.
* Usa herramientas como rclone para sincronización.

##### 4. Imagenes de sistema
* Realiza copias completas del sistema con herramientas como Clonezilla.

##### 5. Política de Retención
* Mantén múltiples versiones de respaldos para proteger contra errores humanos.

## Poteccion y Seguridad

### Ejercicio 1: Concepto y objetivos de protección y seguridad

#### Definición de Protección y Seguridad en Sistemas Operativos
* Protección:

    * Se refiere a los mecanismos diseñados para controlar el acceso a los recursos de un sistema operativo, como archivos, memoria, CPU y dispositivos de entrada/salida.
    * Garantiza que los usuarios y procesos solo accedan a los recursos de manera autorizada.
    * Ejemplo: Las listas de control de acceso (ACL), que determinan quién puede leer, escribir o ejecutar un archivo.
* Seguridad:
    * Es un concepto más amplio que incluye no solo la protección de los recursos internos, sino también la defensa contra amenazas externas, como malware, hackers y errores humanos.
    * Enfocada en mantener la confidencialidad, integridad y disponibilidad de los datos y recursos del sistema.
    * Ejemplo: El uso de firewalls para proteger una red contra accesos no autorizados.

#### Objetivos Principales de Protección y Seguridad
1. Confidencialidad:

    * Asegura que la información solo sea accesible para usuarios o procesos autorizados.
    * Ejemplo: Utilizar cifrado para proteger archivos almacenados.
2. Integridad:

    * Garantiza que los datos no sean alterados sin autorización, ya sea accidental o intencionalmente.
    * Ejemplo: Implementar sumas de verificación (hashing) para verificar la integridad de archivos.
3. Disponibilidad:

    * Asegura que los recursos y servicios del sistema estén disponibles para los usuarios autorizados cuando los necesiten.
    * Ejemplo: Configurar sistemas de redundancia como RAID para prevenir interrupciones.
4. Autenticación:

    * Verifica la identidad de los usuarios o procesos antes de otorgarles acceso.
    * Ejemplo: Utilizar contraseñas, autenticación biométrica o tokens de seguridad.
5. Control de Acceso:

    * Define qué usuarios o procesos pueden realizar operaciones específicas en recursos del sistema.
    * Ejemplo: Los permisos de archivo en Linux (lectura, escritura y ejecución).
6. Auditoría y Registro:

    * Mantiene un registro de todas las acciones realizadas en el sistema para detectar y responder a incidentes de seguridad.
    * Ejemplo: El registro de eventos del sistema operativo.

#### Ejemplos practicos
1. Confidencialidad:

    * Los permisos de archivo en Linux permiten definir quién puede leer (r), escribir (w) o ejecutar (x) un archivo:
    ```chmod 640 archivo.txt```
    * Esto da acceso de lectura y escritura al propietario, solo lectura al grupo, y ningún acceso a otros.

2. Integridad:

    * El comando sha256sum se utiliza para generar y verificar el hash de un archivo, asegurando que no haya sido modificado:
    ```sha256sum archivo.txt```
3. Disponibilidad:
    * El sistema utiliza redundancia mediante un RAID configurado para asegurar que los datos estén disponibles incluso si un disco falla.

* Escenario Práctico:
* Un servidor web aloja una aplicación que debe ser protegida contra accesos no autorizados.
    * Confidencialidad: Solo los administradores tienen acceso SSH al servidor mediante claves públicas y privadas.
    * Integridad: Los archivos de configuración del servidor están protegidos con permisos restringidos y se realizan auditorías regulares.
    * Disponibilidad: El servidor utiliza balanceo de carga y discos RAID para mantener la aplicación en funcionamiento en caso de fallas de hardware.

### Ejercicio 2: Clasificación aplicada a la seguridad

#### Clasificaciones Comunes de la Seguridad
##### 1. Seguridad Física:

* Se enfoca en proteger el hardware y los componentes físicos del sistema operativo contra daños, robos o accesos no autorizados.
* Contribución:
    * Previene la manipulación directa de servidores, estaciones de trabajo y dispositivos de almacenamiento.
    * Es la primera línea de defensa para garantizar la seguridad del sistema operativo.
* Ejemplos Prácticos:
    * Cerraduras y acceso controlado: Uso de credenciales biométricas o tarjetas para acceder a centros de datos.
    * UPS y sistemas de respaldo de energía: Previenen interrupciones de energía que podrían dañar el hardware.
    * Cámaras de seguridad: Monitorean accesos no autorizados.
##### 2. Seguridad Lógica:

* Protege los datos, software y procesos del sistema operativo mediante restricciones de acceso, cifrado y autenticación.
* Contribución:
    * Evita accesos no autorizados al sistema operativo y los datos que administra.
    * Garantiza la confidencialidad, integridad y disponibilidad.
* Ejemplos Prácticos:
    * Autenticación: Uso de contraseñas fuertes, autenticación de dos factores (2FA).
    * Cifrado: Protección de datos en disco mediante LUKS (Linux Unified Key Setup).
    * Permisos de archivos: Control de acceso en sistemas como Linux (chmod) y Windows (ACLs).
##### 3. Seguridad de Red:

* Protege las comunicaciones y conexiones del sistema operativo contra amenazas externas.
* Contribución:
    * Evita que actores maliciosos accedan al sistema operativo a través de la red.
    * Protege los datos en tránsito entre sistemas.
* Ejemplos Prácticos:
    * Firewalls: Configuración de iptables en Linux o Firewall de Windows para bloquear tráfico no autorizado.
    * VPNs: Uso de redes privadas virtuales para comunicaciones seguras.
    * IDS/IPS: Sistemas de detección o prevención de intrusiones como Snort o Suricata.

#### Ejemplo Práctico de Seguridad Aplicada
* Escenario: Una empresa almacena datos sensibles en un servidor Linux conectado a una red corporativa.

##### 1. Seguridad Física:

* El servidor se encuentra en una sala con acceso restringido mediante una cerradura con autenticación biométrica.
* Un sistema de alimentación ininterrumpida (UPS) protege contra cortes de energía.
##### 2. Seguridad Lógica:

* Los usuarios acceden al servidor mediante autenticación SSH utilizando claves públicas y privadas.
* Los datos almacenados en el servidor están cifrados con LUKS para evitar lecturas no autorizadas en caso de robo del disco.
##### 3. Seguridad de Red:

* El servidor está protegido por un firewall configurado con ufw, permitiendo solo conexiones SSH desde IPs específicas.
* Las conexiones remotas se realizan mediante una VPN corporativa que asegura la confidencialidad de los datos en tránsito.


Con estas clasificaciones y medidas, la empresa garantiza la protección del sistema operativo y los datos contra amenazas internas y externas.

### Ejercicio 3: Funciones del sistema de protección

#### Cómo un Sistema de Protección Controla el Acceso a los Recursos
Un sistema de protección garantiza que los recursos de un sistema operativo, como archivos, procesos, memoria y dispositivos, sean accesibles únicamente por usuarios y procesos autorizados. Para lograrlo, utiliza:

* Definición de políticas de acceso:

    * Especifica quién tiene permiso para acceder a un recurso y qué tipo de acceso está permitido (lectura, escritura, ejecución, etc.).
* Mecanismos de control de acceso:

    * Implementa estas políticas mediante listas de control de acceso (ACL), permisos de usuario y grupos.
* Restricciones basadas en el contexto:

    * Controla el acceso según factores como la hora, ubicación, o identidad del usuario.

#### Funciones Principales de un Sistema de Protección
* Autenticación:

    * Verifica la identidad del usuario o proceso antes de permitir el acceso al sistema.
    * Ejemplo: Uso de contraseñas, autenticación multifactor (MFA) o tarjetas inteligentes.
* Autorización:

    * Determina si un usuario autenticado tiene permiso para realizar una acción específica en un recurso.
    * Ejemplo: Un usuario puede leer un archivo pero no editarlo o eliminarlo.
* Auditoría:

    * Registra todas las acciones realizadas en el sistema, como accesos exitosos, intentos fallidos o modificaciones de recursos.
    * Ejemplo: Un registro en el archivo de auditoría que indica cuándo un usuario accedió a un archivo.

#### Caso Práctico
Escenario: Una empresa utiliza un servidor compartido por varios departamentos (Administración, Recursos Humanos y Finanzas), cada uno con archivos sensibles. El sistema operativo implementa un sistema de protección para gestionar el acceso.

* Autenticación:

    * Los empleados inician sesión en el servidor utilizando sus credenciales únicas.
    * Se utiliza autenticación multifactor (MFA) para agregar una capa adicional de seguridad.
        ```bash
        login: maria_admin
        Password: ******
        MFA Token: ******
        ```
* Autorización:

    * Las políticas de acceso están configuradas para garantizar que solo los empleados de Recursos Humanos puedan acceder a los archivos relacionados con nóminas:
        * Archivos de Recursos Humanos: Acceso completo (rwx) para el grupo HR.
        * Archivos de Finanzas: Solo lectura (r--) para usuarios del grupo Admin.
        ```bash
        chmod 770 /srv/HR_data
        chmod 740 /srv/Finance_data
        ```

* Auditoría:

    * El sistema registra todas las actividades de acceso en un archivo de auditoría. Por ejemplo:
        * Éxito: María accedió al archivo ```/srv/HR_data/empleados.txt``` a las 10:45.
        * Fallo: Juan intentó acceder al archivo ```/srv/Finance_data/balance.xlsx``` a las 11:05
        ```bash
        tail /var/log/security_audit.log
        ```

### Ejercicio 4: Implantación de matrices de acceso

#### Diseño de una Matriz de Acceso

Supongamos un sistema con los siguientes usuarios y recursos:

* Usuarios:

    * Alice
    * Bob
    * Charlie
* Recursos:

    * Archivo1
    * Archivo2
    * Impresora
    * BaseDatos

La matriz de acceso define los permisos de cada usuario sobre los recursos, como lectura (R), escritura (W), ejecución (X) o sin acceso (-).


| Usuario  | Archivo1 | Archivo2 | Impresora | BaseDatos |
|----------|----------|----------|-----------|-----------|
| Alice    | R, W     | R        | -         | R         |
| Bob      | R        | R, W     | X         | -         |
| Charlie  | -        | -        | X         | R, W      |

#### Uso de la Matriz de Acceso para Controlar el Acceso

La matriz de acceso es una representación lógica de los permisos en un sistema operativo. Cada celda de la matriz define las operaciones permitidas para un usuario sobre un recurso específico.

Cuando un usuario solicita acceso a un recurso, el sistema:

1. Identifica al usuario:

    * Utiliza métodos de autenticación para verificar la identidad del usuario.
2. Consulta la matriz de acceso:

    * Busca la celda correspondiente al usuario y el recurso solicitado.
3. Permite o niega el acceso:

    * Si el permiso solicitado está en la celda, el acceso es permitido.
    * Si no, el acceso es denegado y se registra un evento de auditoría.

#### Escenario Simulado
Escenario:

* Acción: Charlie intenta escribir en Archivo1.
* Matriz: Charlie no tiene permisos sobre Archivo1.
1. Proceso:

* El sistema verifica la identidad de Charlie mediante autenticación.

2. Consulta la matriz de acceso:

* Charlie no tiene permisos para Archivo1 (celda = -).
3. Resultado:

* El sistema deniega el acceso y registra el intento en el archivo de auditoría.

### Ejercicio 5: Protección basada en el lenguaje

#### Concepto de protección basada en el lenguaje
La protección basada en el lenguaje se refiere a los mecanismos de seguridad que se implementan directamente en el diseño y funcionalidad de un lenguaje de programación. Estos mecanismos buscan prevenir errores y accesos no autorizados a recursos como memoria, datos o procesos.

Los lenguajes modernos, como Java y Rust, incorporan características que garantizan:

* Gestión segura de la memoria.
* Control de acceso a recursos.
* Prevención de vulnerabilidades comunes como desbordamientos de búfer o referencias nulas.

#### Ejemplo de protección en lenguajes
##### Java
En Java, la seguridad es garantizada por características como:

* Control de punteros:
Java no permite a los desarrolladores manipular directamente punteros, eliminando riesgos de corrupción de memoria.
* Gestión automática de memoria (Garbage Collector):
Libera memoria no utilizada automáticamente, evitando fugas de memoria.
* Verificación de bytecode:
Antes de ejecutar un programa, el intérprete de Java verifica el bytecode para asegurarse de que no haya operaciones inseguras.

##### Rust
Rust utiliza un modelo más avanzado de seguridad de memoria, basado en:

* Propiedad de memoria:
Cada valor en Rust tiene un único propietario, garantizando que no haya referencias inválidas.
* Comprobación en tiempo de compilación:
Rust asegura que no haya condiciones de carrera o accesos indebidos antes de que el programa se compile.
* Reglas de préstamos (Borrowing):
Rust controla cómo se comparten y mutan los datos entre múltiples partes del programa.

#### Comparación: Protección basada en el lenguaje vs. Protección en sistemas operativos

| Característica                    | Protección basada en el lenguaje                  | Protección en sistemas operativos          |
|-----------------------------------|--------------------------------------------------|--------------------------------------------|
| **Nivel de operación**            | En tiempo de compilación y ejecución del programa | En tiempo de ejecución del sistema         |
| **Objetivo principal**            | Prevenir errores de desarrollo y vulnerabilidades | Garantizar aislamiento y seguridad global  |
| **Eficiencia**                    | Alta para programas bien escritos                | Alta, pero con mayor sobrecarga            |
| **Escalabilidad**                 | Limitada al ámbito del programa                  | Aplicable a todo el entorno del sistema    |
| **Ejemplo de herramienta**        | Rust, Java                                       | SELinux, AppArmor                          |

### Ejercicio 6: Validación y amenazas al sistema

#### Amenazas comunes a un sistema operativo
* Malware:

    * Incluye virus, gusanos, troyanos y ransomware. Estos programas maliciosos pueden destruir datos, capturar información sensible, o tomar el control del sistema.
    * Ejemplo: Un troyano disfrazado de software legítimo que roba datos del usuario.
* Ataques de fuerza bruta:

    * Consisten en intentar todas las combinaciones posibles de contraseñas para acceder a un sistema.
    * Ejemplo: Ataques a servidores SSH con contraseñas débiles.
* Inyección de código:

    * Se produce cuando un atacante introduce código malicioso en una aplicación para ejecutarlo en el sistema.
    * Ejemplo: Inyección SQL para obtener acceso no autorizado a bases de datos.

#### Mecanismos de validación
* Autenticación multifactor (MFA):

    * Requiere más de un método de validación para acceder al sistema, como:
        * Contraseña (algo que sabes).
        * Token o dispositivo móvil (algo que tienes).
        * Huella digital o reconocimiento facial (algo que eres).
* Control de integridad:

    * Utiliza herramientas para comprobar que los archivos y sistemas no han sido alterados.
    * Ejemplo: Hashes criptográficos (SHA-256) para verificar la integridad de archivos críticos.
* Roles y permisos:

    * Se asignan permisos según el principio de menor privilegio, asegurando que los usuarios solo tengan acceso a los recursos necesarios.

### Esquema de validación para un sistema operativo con múltiples usuarios
#### Esquema propuesto:

* Requisitos de autenticación:

    * MFA obligatorio para todos los usuarios.
    * Contraseñas robustas con políticas de renovación cada 90 días.
* Roles de usuario:

    * Administrador: Acceso completo al sistema operativo.
    * Usuario estándar: Acceso limitado a aplicaciones y archivos personales.
    * Invitado: Acceso temporal con permisos mínimos.
* Mecanismos adicionales:

    * Monitoreo continuo de intentos de acceso fallidos (bloqueo tras 3 intentos).
    * Auditoría de accesos para rastrear actividades sospechosas.
* Flujo de validación:

1. El usuario ingresa su nombre de usuario y contraseña.
2. El sistema envía un código de verificación al dispositivo registrado del usuario (MFA).
3. Una vez autenticado, el sistema valida el rol del usuario y asigna permisos apropiados.
4. Todas las actividades del usuario se registran para auditoría futura.

### Ejercicio 7: Cifrado

#### Conceptos de cifrado
* Cifrado simétrico:

    * Utiliza la misma clave para cifrar y descifrar la información.
    * Es eficiente y rápido, pero requiere compartir la clave de manera segura.
    * Ejemplo: Algoritmos como AES (Advanced Encryption Standard) se utilizan para cifrar discos completos en sistemas operativos (BitLocker en Windows, LUKS en Linux).
* Cifrado asimétrico:

    * Utiliza un par de claves: una pública para cifrar y una privada para descifrar.
    * Es ideal para comunicaciones seguras y no requiere compartir la clave privada.
    * Ejemplo: Los certificados SSL/TLS para proteger conexiones en sistemas operativos y aplicaciones web.

#### Ejemplo práctico

##### Cifrado simétrico:

Aplicación: Cifrado de un archivo utilizando ```openssl``` en Linux.
```bash
# Cifrar un archivo (archivo.txt) con AES-256 y una clave
openssl enc -aes-256-cbc -salt -in archivo.txt -out archivo_cifrado.txt -k "clave_secreta"

# Descifrar el archivo
openssl enc -aes-256-cbc -d -in archivo_cifrado.txt -out archivo_descifrado.txt -k "clave_secreta"
```
Explicación:
* El archivo archivo.txt es cifrado usando la clave "clave_secreta".
* Para descifrar, se usa la misma clave, obteniendo nuevamente el contenido original.

##### Cifrado asimétrico:

Aplicación: Uso de claves públicas y privadas con ```openssl```.
```bash
# Generar claves pública y privada
openssl genpkey -algorithm RSA -out clave_privada.pem -pkeyopt rsa_keygen_bits:2048
openssl rsa -in clave_privada.pem -pubout -out clave_publica.pem

# Cifrar un archivo (archivo.txt) usando la clave pública
openssl rsautl -encrypt -inkey clave_publica.pem -pubin -in archivo.txt -out archivo_cifrado.txt

# Descifrar el archivo con la clave privada
openssl rsautl -decrypt -inkey clave_privada.pem -in archivo_cifrado.txt -out archivo_descifrado.txt
```
Explicación:
* La clave pública se usa para cifrar el archivo, asegurando que solo quien posea la clave privada pueda descifrarlo.

#### Simulación del proceso

Archivo inicial: 
```
Este es un archivo confidencial.
```

##### Proceso con cifrado simétrico:

###### 1. Cifrado:
Comando: ```openssl enc -aes-256-cbc -salt -in archivo.txt -out archivo_cifrado.txt -k "clave_secreta"```

Archivo cifrado:
```bash
Salted__ÿÈßÓ$À... 
```
###### 2. Desifrado:
Comando: ```openssl enc -aes-256-cbc -d -in archivo_cifrado.txt -out archivo_descifrado.txt -k "clave_secreta"```

Archivo descifrado:
```
Este es un archivo confidencial.
```

##### Proceso con cifrado asimétrico:

###### 1. Cifrado:
Comando: ```openssl rsautl -encrypt -inkey clave_publica.pem -pubin -in archivo.txt -out archivo_cifrado.txt```

Archivo cifrado:
```bash
ÀkÑ¢¼...
```
###### 2. Desifrado:
Comando: ```openssl rsautl -decrypt -inkey clave_privada.pem -in archivo_cifrado.txt -out archivo_descifrado.txt"```

Archivo descifrado:
```
Este es un archivo confidencial.
```




