## Легкий уровень ситуации

* Действия:
```
    explore: Studies the environment
    try_door: Checks the door (handle, lock)
    yell: Screaming, calling for help
    wait: Awaiting
    think: He's considering his options
    interact: Trying to use improvised means
    panic: Panics or does meaningless actions
```
* Правила
```
    0 4 5 good        // Исследование + размышление + взаимодействие => успех
    2 2 6 bad         // Два крика + паника => провал
    1 3 3 bad         // Дверь + два ожидания => неудача
    0 2 5 good        // Исследование + крик + взаимодействие => успех
    6 6 bad           // Два панических действия => провал
```

* Баланс
```
     Root Reward Probabilities
      Good   Neutral       Bad
      0.10      0.55      0.35
```

* Сценарии прохождения
```
    "Старается": осматривается → думает → пробует открыть окно → good

    "Не старается": кричит → ждёт → снова кричит → паникует → bad
```
