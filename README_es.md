# 🧪 Tester para get_next_line

---
Este es un **conjunto de pruebas robusto y en constante crecimiento** diseñado para verificar la precisión, la gestión de memoria y el comportamiento de tu implementación de la función `get_next_line` para la lectura de líneas desde un descriptor de archivo.

---

## 🎯 Cobertura de Pruebas

El objetivo de este *suite* de pruebas es asegurar que tu `get_next_line` sea **100% funcional** y cumpla con todos los requisitos del proyecto, incluyendo los valores de retorno correctos, la gestión de memoria y el comportamiento bajo diversas condiciones de archivo.

### 1. Funcionalidad Central

Los siguientes escenarios se prueban exhaustivamente:

* **Archivos Estándar:** Lectura de archivos de texto comunes.
* **Longitudes de Línea Variables:** Archivos que contienen líneas cortas, largas y extremadamente largas.
* **Tamaño del Buffer ($BUFFER\_SIZE$):** Pruebas con diferentes valores de $BUFFER\_SIZE$ (pequeño, grande, 1, y el tamaño del archivo).
* **Múltiples Descriptores de Archivo:** Lectura simultánea de varios descriptores de archivo abiertos.
* **Finales de Línea:** Manejo correcto de líneas que terminan con `\n`, líneas sin `\n` y archivos vacíos.

### 2. Casos Límite y Manejo de Errores

Se evalúan situaciones críticas para asegurar la robustez:
* **Descriptores de Archivo Inválidos:** Pasar descriptores de archivo inexistentes o cerrados (p. ej., -1, 42).
* **Lectura desde Entrada Estándar (FD 0):** Asegurar que la función funciona de forma interactiva.
* **Archivos Binarios:** Comprobación del comportamiento correcto al leer datos que no son de texto.
* **Fugas de Memoria (Memory Leaks):** Comprobaciones rigurosas para confirmar que no se pierde memoria durante la ejecución, especialmente cuando se llama a `get_next_line` repetidamente o cuando encuentra un error.

---

## ⚙️ Uso e Integración

### 1. Requisitos

Asegúrate de que tu función `get_next_line` y cualquier función auxiliar necesaria estén compiladas. Su prototipo debe estar disponible en un archivo de cabecera llamado **`get_next_line.h`**. Ambos archivos deben estar ubicados en el **directorio raíz** de este repositorio de pruebas.

### 2. Compilación

Compila todos tus archivos fuente junto con el *main* de prueba que desees ejecutar:

```bash
cc (todos los archivos que necesites).c main_que_quieras_usar.c -o test_runner
```
---

### 3. Ejecución de la Suite

Después de compilar, ejecuta el programa de tests generado:

```bash
./test_runner test_file1 test_file2 test_file3
```
**⚠️ Sustituye** `test_file1` `test_file2` `test_file3` por el nombre de los archivos de prueba que desees ejecutar (ej: `2_long_lines` `nothing` `no_new_line`).

---

## 🤝 Contribuciones (Reporting Issues)

¡Las contribuciones son bienvenidas y son cruciales para mejorar la calidad de esta suite de tests!

Si encuentras cualquier problema, por favor, **abre un *issue*** en este repositorio.

---

### ¿Cómo contribuir?

1.  **Reportar un Issue:** Abre una nueva pestaña de *Issues* en GitHub y describe el error encontrado, incluyendo el **caso de prueba exacto** que está fallando o que falta.
2.  **Enviar un Pull Request (Opcional):** Si has creado un nuevo test para solucionar el problema, puedes enviar directamente un *Pull Request* para que lo revisemos e integremos.

**Tu colaboración asegura que esta suite de tests sea lo más robusta y completa posible para toda la comunidad.**
