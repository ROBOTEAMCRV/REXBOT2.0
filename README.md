Documento de ingeniería / TEAMROBOCRV

Este repositorio contiene todos los materiales necesarios para crear a "Rexbot", el robot autónomo creado por el equipo "TeamRoboCRV", con el objetivo de participar en la categoría de Futuros Ingenieros en las diferentes etapas de la WRO Venezuela, en su edición 2025.

<img width="1590" height="644" alt="image" src="https://github.com/user-attachments/assets/3cda8af7-7508-41e8-81a8-01996fec2341" />


 TABLA DE CONTENIDO
[Miembros del equipo TEAMROBOCRV]

[Gestión de potencia y sentidos](Gestión_de_potencia_y_sentidos)

[Gestión de movilidad](Gestión_de_movilidad)

[Gestión de obstaculos](Gestión_de_obstaculos)

[Diagrama de cableado](Diagrama_de_cableado)

[Documentacion_del harwdware_y_archivos_CAD](Documentacion_del_harwdware_y_archivos_CAD)

[Ideas y principios](Ideas_y_principios)

[Videos](Videos)

[Fotos del REXBOT2.0](Fotos_del_REXBOT2.0)

[Codigo](Codigo)


MIEMBROS DEL TEAMROBOCRV

-Gianni Marcello Martucci Jerez (alias winni POOH) Esta rellenito de amor

<img width="400" height="600" alt="image" src="https://github.com/user-attachments/assets/1bcc44ed-ea78-4fa7-93d5-581ea6aad23a" />


-Juan Andres Graterol Teran (Wido) El mas rápido en pix pix

<img width="400" height="600" alt="image" src="https://github.com/user-attachments/assets/51b3d7c0-b54a-4267-ae77-e930a64322b0" />

-Dennis Adrian Silva Riera (alias Mate) le la da loquera de repente

<img width="400" height="600" alt="image" src="https://github.com/user-attachments/assets/140671eb-8c9f-4bf1-bf3d-6eb409680a4d" />

Entrenador

-Luis Eduardo Paredes

<img width="400" height="600" alt="image" src="https://github.com/user-attachments/assets/12b81259-f88b-43d7-be25-c19f183fe3eb" />

INTRODUCCIÓN

Nuestro proyecto consiste en la fabricación de un vehículo terrestre automatizado, que navega en un entorno señalizado por obstáculos de colores, tomando diferentes caminos en función  de las características y propiedades de dichos obstáculos. Utilizamos una tecnología basada en Arduino (C++), que posee una programación compuesta por sensores ultrasónicos que envían y reciben pulsos a una distancia preestablecida en el código, los cuales al detectar la proximidad de un objeto, envían una señal a la placa Arduino, que indicará al sistema de movimiento del vehículo hacia donde dirigirse, en sentido horario o antihorario, según lo preestablecido. Por otro lado, también cuenta con un sensor de visión o cámara  HuskyLens (Gravity) para detectar los obstáculos de colores, y evadirlos cuando sea necesario. Dependiendo del color, se desplazará por la derecha o la izquierda del obstáculo, según lo requerido. 

El código fue creado en un equipo portátil bajo sistema operativo Windows 10 y/o GNU-Linux 5.15.0. El software utilizado es Arduino IDE versión 2.3.6, cargado a una placa Arduino Mega, a través de un cable de transmisión de datos. Esta placa está abastecida por 2 baterías de litio  18650 de 3.7 voltios.
DISEÑO MECÁNICO

REXBOT2.0 Es un robot autónomo que está construido de forma original usando diversos equipos de muchas fuentes para poder realizar un robot con un diseño completamente propio en Hardware y Software. Utilizando tanto piezas impresas en 3D (CAD), como piezas de Lego gracias a su fiabilidad en ejecución. Este robot debe su movilidad a su motor DC utilizando una caja de engranajes para mayor eficiencia, conectado a dos ruedas traseras para la tracción, unidas a través de un solo eje. Su Sistema de dirección delantera trabaja a través de un servomotor (servomotor mg996r) que consta de tres pines, positivo, negativo y datos que va a la placa Arduino Mega al pin 3, para controlar sus giros mediante grados siendo así el mas confiable y preciso para dar sus giros.

En este repositorio se pueden encontrar:

Elementos que conforman el robot (placa, sensores, componentes de movilidad y estructura)

Fotos de el robot  (ángulos del robot, el proceso de ensamblado y pruebas grabadas)

Instrucciones dadas al robot y lo que debería hacer (diagramas de flujo y protocódigos) 

Código utilizado y sus actualizaciones (commits)

COMPONENTES ELECTRICOS

Arduino Mega 2560: Es una placa microcontroladora basada en el ATmega2560. Tiene 54 pines de entrada/salida digital y 16 entradas analógicas, un oscilador de cristal de 16 MHz, una conexión USB, una toma de alimentación, una cabecera ICSP y un botón reset. El arduino es la placa que contiene el código para el funcionamiento, encargándose de analizar toda la información obtenida por los sensores para así lograr cumplir con el reto.

![image](https://github.com/user-attachments/assets/f05d233c-e24c-4ff1-8271-7497d4e47e2d)

Puente-H L298: Es un tipo de controlador que permite cambiar la polaridad de un motor de corriente continua, hacia delante y hacia atrás, además de ser la fuente de energía de diversos sensores. El modelo de puente H utilizado es el L298N, que nos permite cambiar la velocidad de los motores en función de la tensión enviada por el Arduino.

![image](https://github.com/user-attachments/assets/f5846276-a2a8-4158-a556-4906391e3481)

Sensor de ultrasonido: Es un sensor que utiliza sonidos ultrasónicos para detectar el tiempo de rebote del sonido de un lado a otro. Utilizando el Arduino Mega 2560 se determina la distancia en base al tiempo que tarda la onda en volver, teniendo así este sensor la función de determinar cuando hay una pared cerca para así realizar el giro correspondiente. El modelo utilizado de este sensor es el HC-sr04.

![image](https://github.com/user-attachments/assets/99265f5b-d808-488d-b19f-be81e736ceaa)

Cámara HuskyLens (Gravity): Es un sensor visual integrado con IA, esta utiliza el chip de AI Kendryte K210, que ofrece un rendimiento excepcional, permitiendo el reconocimiento rápido y preciso de múltiples objetos y rostros. Siendo utilizada para optimizar la detección de objetos y su color (Semáforos).

![image](https://github.com/user-attachments/assets/68c98770-61af-4463-b176-1d61b81999ee)

Servo motor (MG996R): Es un motor eléctrico con sensor de retroalimentación de posición integrado, que permite realizar movimientos angulares perfectos, utilizando una señal que va de 0V a 5V, donde cada valor que pueda tener el voltaje representa un ángulo exacto.

![image](https://github.com/user-attachments/assets/26eff895-ec21-4677-b70d-ead8890a42b2)

Motor DC: Este es una máquina que convierte energía eléctrica  en energía mecánica, provocando un movimiento rotatorio, gracias a la acción de un campo mecánico. 

![image](https://github.com/user-attachments/assets/2fc11936-da36-484e-8391-99f08366bebe)

Gestión de energía:
Conexión eléctrica del sistema de tracción trasera: constituido por dos pilas de 3.7 voltios conectadas en serie para dar 7.4 V, conectadas a su vez al elevador de voltaje (XL6009) para dar 10 V sostenidos al driver L298, en su entrada de 12 voltios, para proporcionar mayor eficiencia al motor DC. Este va conectado de sus pines n1 y n2 a la placa Arduino Mega en sus pines 8 y 7, para cambiar polaridad de energía que defina el giro de las ruedas, si avanza o retrocede. Del L298 van conectados a las salidas del motor DC de 5V.
La placa microcontroladora está alimentada mediante dos baterías 18650 3.7 V en serie conectadas al puerto de 12 voltios corriente directa.
Sistema de Sensores:
El carro cuenta con dos sensores ultrasónicos (HCSR04) que consta de 4 pines, positivo, negativo, trigger y echo, que van conectados a la placa Arduino Mega para dar la función de detección de paredes. Este funciona a través de ondas ultrasónicas que son emitidas y recibidas por el mismo, detectando la proximidad de un objeto, enviando una señal lógica a la placa para ejecutar una acción. Además utiliza un sensor de visión o cámara, HuskyLens (Gravity) para detectar los obstáculos de colores, que consta de cuatro pines positivo, negativo, Tx (transmisión de datos) y Rx (recepción de datos) que van conectados a la placa Arduino Mega a los pines 10 y 12(Rx y Tx).
