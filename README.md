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

## Preguntas

### Analice la salida respecto a su UI/UX. Que opina del diseno en general? Haga un analisis rapido de heuristicas.

En general esta bien, nada WOW pero cumple con lo que le pedi. En cuanto a las heuristicas:
* Cumple parcialmente la visibilidad del estado del sistema, despues de las acciones se muestra un mensaje, pero faltaria que exista un contador de tareas que siempre este visible.
* En cuanto al control y libertad del usuario, no cumple, porque deberia permitir deshacer acciones.
* Tampoco cumple el principio de prevención de errores, porque solo hay mensajes de error cuando se cometen los errores, no mensajes para prevenirlos.
* No cumple tambien el principio de ayuda para reconocer, diagnosticar y recuperarse de errores, porque los mensajes aunque son claros, no te dan la solucion ni tampoco te dan ejemplos.
* Por ultimo, no cumple el principio de flexibilidad y eficiencia de uso, porque solo hay un menu, no hay atajos para usuarios expertos.

### Analice el codigo generado por la IA. Que errores encuentra? Puede identificar alguna mejora? Cuales? Justifique

Primero el codigo esta todo en un solo archivo, lo mejor seria separar la logica de la parte visual. Ademas, se estan mezclando tareas distintas en un mismo lugar, lo que rompe el principio de responsabilidad unica.

Por otro lado, la generacion de IDs en Task hace que haya un estado global innecesario, es mejor que la clase TodoList se encargue de la generacion de IDs, o mejor aun, que haya un generador externo.

Tambien seria mucho mejor que las funciones devuelvan un resultado en vez de imprimir directamente en la consola, y recien despues se decida que mostrar al usuario. Con eso incluso se puede mejorar la gestion de errores.
