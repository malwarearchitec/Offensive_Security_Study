# DIA_00 - Razonamiento ofensivo (compuertas logicas)

Notas del angulo ofensivo del dia de intake, organizadas al formato del entregable. Solo contiene lo que se razono en clase. Lo que quedo pendiente se marca como tal, no se rellena.

### XOR en el mundo ofensivo

XOR aparece en shellcode, en ofuscacion de malware, en criptografia, en checksums y en trucos de ensamblador. La propiedad que lo hace tan util del lado ofensivo es la reversibilidad.

Si se cifra un dato haciendo `cifrado = texto xor clave`, entonces la misma operacion con la misma clave decodifica: `texto = cifrado xor clave`. Esa reversibilidad es la base matematica de la ofuscacion mas comun del malware. XOR trabaja bit a bit.

Ejemplo de la reversibilidad con una clave que si cambia los bits (clave distinta de 0), A = 1 y clave = 1:

```text
cifrar:    1 xor 1 = 0     (el cifrado es 0, distinto del original)
descifrar: 0 xor 1 = 1     (se recupera A)
```

La clave nunca se pone en 0, porque `x xor 0 = x` no cifraria nada. El 0 tiene que venir del dato, no de la clave.

### El patron xor eax, eax

La segunda propiedad, `A xor A = 0`, es la razon de un patron muy usado en cada desensamblado:

```asm
xor eax, eax   ; pone el registro eax en 0, porque eax xor eax = 0
```

Se usa este patron en lugar de `mov eax, 0` porque ocupa menos bytes y no introduce bytes nulos. Esto es critico para shellcode: un byte nulo `\0` rompe una cadena, y si el shellcode es un exploit basado en cadena, con un byte nulo se rompe. Cuando aparece `xor eax, eax` en el desensamblado, no es una operacion de cifrado, es poner el registro en cero.

### Decodificado a mano (Fase 4)

Buffer cifrado con XOR de un byte, clave `0x2A`. Recuperar el texto plano a mano.

```text
0x62 xor 0x2A:
  0110 0010
  0010 1010
  ---------
  0100 1000 = 0x48 = 'H'

0x63 xor 0x2A:
  0110 0011
  0010 1010
  ---------
  0100 1001 = 0x49 = 'I'
```

La palabra oculta es HI. Este es el mismo patron que corre un decodificador de cadenas de malware, byte por byte, justo antes de usar la cadena.

### Debug en papel: por que bits & ~bits siempre da 0 (Fase 4)

```c
resultado = bits & ~bits;   // siempre da 0
```

Un bit y su inverso siempre son distintos. AND de un bit con su propio inverso siempre da 0, para cualquier bit. Por eso la expresion completa siempre da 0.

```text
bit | ~bit | bit & ~bit
 0  |  1   |    0
 1  |  0   |    0
```

Para invertir un solo bit no se usa esto, se usa `bit ^ 1` (XOR con 1 voltea el bit), o para un bit en una posicion, `(bits >> i) & 1` para extraerlo.

### Fase 4.5 - Rompe el codigo (parcial)

Pregunta 1, que asumio el desarrollador de la funcion `tiene_permiso`: asumio que la mascara viene de codigo confiable y que tiene un solo bit encendido, el permiso que se quiere comprobar.

Preguntas 2, 3 y 4: PENDIENTES. Falta razonar que pasa si el atacante controla la mascara, cual violacion da control en vez de solo un fallo, y para que serviria en una operacion real. Cerrar antes de dar por completo el DIA_00.

_END OF DOCUMENTS_
