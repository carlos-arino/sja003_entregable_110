# Guía de Prácticas: Simulación ESP32 en la Nube
### Entorno VS Code + PlatformIO + Wokwi

**Departamento de Tecnología**

## Introducción
En este curso utilizaremos un entorno de desarrollo profesional en la nube. No necesitas instalar nada en tu ordenador. Usaremos **GitHub Codespaces** para programar y **Wokwi** para simular el hardware del ESP32.

> [!IMPORTANT]
> **Requisitos Previos**
> * Tener una cuenta de GitHub activa (es gratuita).
> * Enlace al repositorio

---

## Paso 1: Crear tu Proyecto (Copia la Plantilla)
No trabajaremos sobre el código del repositorio, sino sobre tu propia copia.

1. Entra en el enlace del repositorio (arriba).
2. Busca el botón verde **Use this template > Create a new repository**.
3. **Repository name:** Ponle un nombre sin espacios (ej: `Ejercicio1-nombre-apellido`).
4. Deja marcada la opción **Public** y pulsa **Create repository**.



## Paso 2: Arrancar el Ordenador Virtual
Vamos a encender un entorno VS Code en la nube que ya tiene todo instalado.

1. En tu nuevo repositorio, pulsa el botón verde **<> Code**.
2. Ve a la pestaña **Codespaces**.
3. Pulsa el botón verde **Create codespace on main**.
4. **¡PACIENCIA!** Se abrirá una pestaña nueva. La primera vez tarda unos **5-7 minutos** en configurarse.
5. Te pedirá si quieres instalar la extensión PlatformIO. Acepta e instala. Si no lo haces tendrás que hacerlo manualmente.

## Paso 3: Verificación de Instalación (¡IMPORTANTE!)
Antes de seguir, debemos asegurarnos de que el "cerebro" (PlatformIO) se ha instalado bien.

1. Mira la barra lateral izquierda. Debes ver el icono de una **Cabeza de Alien** 👽. 
2. Si te aparece un aviso abajo a la derecha pidiendo **"Reload Now"**, púlsalo.
3. Si no sale el aviso ni el Alien, pulsa <kbd>F5</kbd> en tu navegador para recargar la página y espera 1 minuto más sin tocar nada.

## Paso 4: Activar el Simulador (Licencia Gratis)
Para que Wokwi funcione, necesitas una licencia gratuita.

1. Abre esta web en otra pestaña: [https://wokwi.com/vscode](https://wokwi.com/vscode)
2. Inicia sesión con GitHub y copia el código de licencia que aparece.
3. Vuelve a la pestaña de VS Code (Codespace).
4. Pulsa la tecla <kbd>F1</kbd>. Escribe: `Wokwi: Set License` y pulsa <kbd>Enter</kbd>.
5. Pega el código y pulsa <kbd>Enter</kbd>.

## Paso 5: Compilar y Simular
¡Hora de probar si funciona!

1. En el explorador de archivos (izquierda), abre `src/main.cpp`.
2. Mira la barra inferior de VS Code. Busca el icono de un **Tick** (✓) y púlsalo para compilar. (Si no sale, espera un poco más al paso 3). 
3. En la lista de archivos, haz clic en `diagram.json`.
4. Se abrirá el esquema del ESP32. Pulsa el botón verde **Play** (▶️) encima del dibujo.

> **Resultado esperado:** Deberías ver la pantalla LCD encenderse con el mensaje de bienvenida y el ESP32 conectado mediante I2C.

## Paso 6: ¿Cómo modificar el circuito? (Estrategia Híbrida)

> [!WARNING]
> La extensión gratuita de Wokwi para VS Code permite **simular** pero no **editar** visualmente (no puedes mover cables ni añadir componentes con el ratón).

Si necesitas añadir componentes nuevos (LEDs, botones, sensores) que no están en la plantilla, puedes hacer lo siguiente:

1. Entra en la web [https://wokwi.com](https://wokwi.com) (no hace falta iniciar sesión).
2. Crea un proyecto nuevo de ESP32 y diseña tu circuito visualmente (arrastra componentes y cables).
3. En la web, busca la pestaña `diagram.json` (situada encima del editor de código).
4. Copia todo el texto de ese archivo.
5. Vuelve a tu VS Code, abre tu archivo local `diagram.json`, borra todo su contenido y pega el texto que traes de la web.
6. Al dar al Play, VS Code simulará el nuevo circuito que diseñaste en la web.

## Paso 7: Guardar y Terminar
Si cierras la pestaña sin más, tus cambios no se guardan en la nube.

1. Haz clic en el icono de **Source Control** (izquierda, tercer icono).
2. Escribe un mensaje (ej: "Práctica terminada").
3. Pulsa el botón azul **Commit** y luego **Sync Changes**.
4. Cuando termine de girar, ya puedes cerrar la pestaña.

---

## Solución de Problemas Frecuentes

* **No aparece el Alien (PlatformIO):** Es un error común de carga.
    1. Pulsa <kbd>F1</kbd> y escribe: `Reload Window` (o pulsa <kbd>F5</kbd> en el navegador).
    2. Al recargar, espera 2 minutos sin tocar nada hasta que salga.

* **Veo rayas rojas en el código:** Es normal al principio. PlatformIO está indexando. Pulsa el botón de compilar (✓) y desaparecerán.

* **Me pide licencia al dar al Play:** No has completado el Paso 4. Ve a [wokwi.com/vscode](https://wokwi.com/vscode) y pega el código con <kbd>F1</kbd>.

* **No encuentro el serial Monitor:** Aparece en el panel inferior en la pestaña terminal a la derecha *Wokwi Terminal*

---

# Problema Microcontroladores: Invernadero Inteligente

## Instrucciones de Selección del Problema

Este problema tiene diferentes datos dependiendo del DNI del alumno. Se basa en el valor de las tres últimas cifras del DNI ($c, d, u$).

**Ejemplo:** DNI 20339950R -> **950**. En este caso $c=9, d=5, u=0$.

Se comprueba si las centenas, decenas y unidades son iguales o mayores que 5 para asignar el código binario del problema (0 o 1):

* Si **$c < 5$** -> El primer dígito es **0** (Control de Sombreado - Sensor Analógico).
* Si **$c \ge 5$** -> El primer dígito es **1** (Control de Ventilación - Sensor Digital).
* Si **$d < 5$** -> El segundo dígito es **0** (Motor Paso a Paso).
* Si **$d \ge 5$** -> El segundo dígito es **1** (Motor DC).
* Si **$u < 5$** -> El tercer dígito es **0** (Feedback por Encoder).
* Si **$u \ge 5$** -> El tercer dígito es **1** (Feedback por Potenciómetro).

En el ejemplo anterior (**950**): $c \ge 5$ (1), $d \ge 5$ (1), $u < 5$ (0). Se asignará el **Problema 110**.

La entrega se realiza en el aula virtual con el código del archivo de extensión `.ino`. Este debe incluir el enlace a la simulación realizada en Wokwi.

---

## Problema 110
Se quiere instrumentar el sistema de ventilación de un invernadero. Para ello se dispone de un sensor de temperatura digital **DS18B20**. El programa debe comunicarse a través del bus OneWire para obtener la temperatura en grados Celsius (Rango de trabajo de 0ºC a 50ºC).

Posteriormente, se debe cambiar la orientación de la **compuerta de ventilación** de forma proporcional: 0ºC implica compuerta cerrada (0º) y 50ºC implica compuerta totalmente abierta (90º).

Para lograr este movimiento, la compuerta tiene conectada un **motor de continua** con su driver, controlado mediante señal PWM (velocidad proporcional a la tensión). Para verificar la posición, se dispone de un **encoder absoluto de 4 bits** con codificación Gray conectado al eje.

De forma adicional, el programa debe publicar en el servidor MQTT **broker.emqx.io**:
* Topic: `sja003/invernadero/950/temperatura` con el valor de temperatura actual en ºC.
* Topic: `sja003/invernadero/950/historico` con el array de las medias de las últimas 5 horas. Ejemplo: `"[20, 22, 25, 24, 21]"`.

El número **950** del topic es un ejemplo; debéis sustituirlo por vuestras 3 últimas cifras del DNI.

**Recursos:**
* **Repositorio Base:** [https://github.com/carlos-arino/sja003_entregable_110.git](https://github.com/carlos-arino/sja003_entregable_110.git)
* **Simulador Wokwi:** [https://wokwi.com/projects/384176177078658049](https://wokwi.com/projects/384176177078658049)
