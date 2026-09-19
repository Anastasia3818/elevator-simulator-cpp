#include <iostream>
#include "Building.h"
#include "Utils.h"

// Количество шагов симуляции
const int SIMULATION_STEPS = 20;

// Задержка между шагами, миллисекунды
const int STEP_DELAY_MS = 1000;

int main()
{
    setlocale(LC_ALL, "RU");

    // Создание здания с тремя лифтами
    Building building(3);

    // Начальные вызовы лифтов
    building.callElevator(7, Direction::UP);
    building.callElevator(2, Direction::DOWN);
    building.callElevator(10, Direction::DOWN);

    // Основной цикл симуляции: 20 шагов по 1 секунде
    for (int step = 0; step < SIMULATION_STEPS; step++)
    {
        building.printStatus();   // Вывод состояния здания
        building.stepSimulation(); // Один шаг симуляции
        delay(STEP_DELAY_MS);      // Пауза между шагами
    }

    return 0;
}
