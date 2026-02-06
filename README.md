# Gestión de Tareas

## Prompt

Desarrolla una aplicación de lista de tareas (TODO) en línea de comandos (CLI) usando `C++` y únicamente la librería estándar, con entrada y salida simple mediante `std::cin` y `std::cout`.

La aplicación debe permitir:

* Añadir tareas.
* Listarlas.
* Marcarlas como completadas.
* Eliminarlas.

**Restricciones:**

* Mantener toda la información únicamente en memoria (RAM).
* Código estructurado, modular y legible.
* Aplicar buenas prácticas (encapsulación, manejo de errores y *const-correctness*).
* **Sin** incluir documentación ni comentarios.

---

## Respuesta de la IA

Perfecto. He desarrollado completamente la aplicación de lista de tareas CLI en C++ según tus especificaciones.

### ✅ Características implementadas

#### Estructura del código

* Clase `Task`: representa una tarea individual con ID único, descripción y estado de completado.
* Clase `TodoList`: gestiona la colección de tareas y operaciones CRUD.
* Clase `TodoApp`: maneja la interfaz de usuario y el flujo de la aplicación.

#### Funcionalidades

* **Agregar tareas**: validación de descripción no vacía.
* **Listar tareas**: muestra ID, estado (PENDIENTE/COMPLETADA) y descripción en formato tabular.
* **Marcar como completada**: cambia el estado de una tarea específica por ID.
* **Eliminar tareas**: elimina una tarea por su ID.
* **Salir**: opción para cerrar la aplicación.

#### Buenas prácticas aplicadas

* Encapsulación: miembros privados con getters públicos.
* Const-correctness: métodos que no modifican el estado marcados como `const`.
* Manejo de errores: validación de entrada, IDs inexistentes y descripciones vacías.
