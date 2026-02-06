#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

class Task {
private:
    std::string description;
    bool completed;
    static int nextId;
    int id;

public:
    Task(const std::string& desc)
        : description(desc), completed(false), id(nextId++) {}

    int getId() const { return id; }
    const std::string& getDescription() const { return description; }
    bool isCompleted() const { return completed; }
    void markAsCompleted() { completed = true; }
};

int Task::nextId = 1;

class TodoList {
private:
    std::vector<Task> tasks;

    int findTaskIndex(int id) const {
        for (size_t i = 0; i < tasks.size(); ++i) {
            if (tasks[i].getId() == id) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }

public:
    void addTask(const std::string& description) {
        if (description.empty()) {
            std::cout << "Error: La descripcion no puede estar vacia.\n";
            return;
        }
        tasks.emplace_back(description);
        std::cout << "Tarea agregada exitosamente.\n";
    }

    void listTasks() const {
        if (tasks.empty()) {
            std::cout << "No hay tareas en la lista.\n";
            return;
        }

        std::cout << "\n=== LISTA DE TAREAS ===\n";
        std::cout << std::left << std::setw(5) << "ID"
                  << std::setw(12) << "ESTADO"
                  << "DESCRIPCION\n";
        std::cout << std::string(50, '-') << "\n";

        for (const auto& task : tasks) {
            std::cout << std::left << std::setw(5) << task.getId()
                      << std::setw(12) << (task.isCompleted() ? "[COMPLETADA]" : "[PENDIENTE]")
                      << task.getDescription() << "\n";
        }
        std::cout << "\n";
    }

    void completeTask(int id) {
        int index = findTaskIndex(id);
        if (index == -1) {
            std::cout << "Error: No se encontro una tarea con el ID " << id << ".\n";
            return;
        }

        if (tasks[index].isCompleted()) {
            std::cout << "La tarea ya estaba completada.\n";
        } else {
            tasks[index].markAsCompleted();
            std::cout << "Tarea marcada como completada.\n";
        }
    }

    void deleteTask(int id) {
        int index = findTaskIndex(id);
        if (index == -1) {
            std::cout << "Error: No se encontro una tarea con el ID " << id << ".\n";
            return;
        }

        tasks.erase(tasks.begin() + index);
        std::cout << "Tarea eliminada exitosamente.\n";
    }
};

class TodoApp {
private:
    TodoList todoList;
    bool running;

    void clearInputBuffer() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void displayMenu() const {
        std::cout << "\n=== APLICACION TODO ===\n";
        std::cout << "1. Agregar tarea\n";
        std::cout << "2. Listar tareas\n";
        std::cout << "3. Marcar tarea como completada\n";
        std::cout << "4. Eliminar tarea\n";
        std::cout << "5. Salir\n";
        std::cout << "Seleccione una opcion: ";
    }

    void addTask() {
        std::cout << "Ingrese la descripcion de la tarea: ";
        std::string description;
        std::getline(std::cin, description);
        todoList.addTask(description);
    }

    void listTasks() {
        todoList.listTasks();
    }

    void completeTask() {
        std::cout << "Ingrese el ID de la tarea a completar: ";
        int id;
        if (!(std::cin >> id)) {
            std::cout << "Error: ID invalido.\n";
            clearInputBuffer();
            return;
        }
        clearInputBuffer();
        todoList.completeTask(id);
    }

    void deleteTask() {
        std::cout << "Ingrese el ID de la tarea a eliminar: ";
        int id;
        if (!(std::cin >> id)) {
            std::cout << "Error: ID invalido.\n";
            clearInputBuffer();
            return;
        }
        clearInputBuffer();
        todoList.deleteTask(id);
    }

    void processOption(int option) {
        switch (option) {
            case 1:
                addTask();
                break;
            case 2:
                listTasks();
                break;
            case 3:
                completeTask();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                running = false;
                std::cout << "Saliendo de la aplicacion...\n";
                break;
            default:
                std::cout << "Opcion invalida. Intente nuevamente.\n";
        }
    }

public:
    TodoApp() : running(true) {}

    void run() {
        std::cout << "Bienvenido a la aplicacion TODO!\n";

        while (running) {
            displayMenu();
            int option;

            if (!(std::cin >> option)) {
                std::cout << "Error: Opcion invalida.\n";
                clearInputBuffer();
                continue;
            }
            clearInputBuffer();

            processOption(option);
        }
    }
};

int main() {
    TodoApp app;
    app.run();
    return 0;
}
