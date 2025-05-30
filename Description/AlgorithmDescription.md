### Общая концепция
* Есть описанная ситуация, в которую попадает пользователь.
* Ситуация развивается в зависимости от дейсствий пользователя в ней и приводит к логичесокму заключению.
* Есть структурированное дерево, где вершины - варианты действий пользователя, каждый уровень дерева - очередное действие пользователя в развивающейся ситуации, на листьях дерева - характеристики концовки ситуации (хорошая, нейтральная, плохая).
* Нейросеть анализирует описанное пользователем действие и относит его к оодному из действий дерева на очередном шаге развития ситуации (то есть на очередном уровне дерева).

### Дерево балансирования
* По заданным заранее параметрам строится дерево балансирования. Каждый узел дерева - одно из заранее определенных действий. Любая послдеовательность действий, которая проходит от корня до листа дерева, приводит к одному из результатов (хорошему, нейтральному или плохому)
#### Параметры построения дерева
* Глубина дерева - максимальная длина последовательности действий, ведущей к листу дерева, описывает продолжительность ситуации.
* Набор действий - обобщенные действия с их описаниями, действия пользователя будут ассоциироваться с одним из этих действий.
    * Пример набора действий
    ```
        exploration: Exploring the environment
        conflict: Clash of interests
        diplomacy: Conducting negotiations
        aggression: Aggressive actions
        gumption: A display of intelligence and resourcefulness
        stupidity: Slowness and useless actions
        active_action: Decisive action to interact with the environment
    ```
* Правила построения дерева - цепочки последовательно идущих действий из набора действий, которые явно приводят к одной из концовок (good или bad)
    * Пример набора правил
    ```
        exploration diplomacy good
        aggression aggression aggression bad
        conflict gumption active_action good
        diplomacy stupidity stupidity bad
    ```

    * Пример набора правил для задания (числа - порядковые номера правил из набора правил, начиная с нуля)
    ```
        0 2 good
        3 3 3 bad
        1 4 6 good
        2 5 5 bad
    ```

    * Правила задают соответсвующую им концовку, если последовательность действий из правила встречается в цепочке действий дерева. При этом действия из правила не обязательно должны идти подряд в цепочке.
        * Примеры:
             ```
                Правило:
                exploration diplomacy good
                Цепочка действий:
                conflict exploration diplomacy -> good
            ```
            ```
                Правило:
                aggression aggression aggression bad
                Цепочка действий:
                aggression exploration aggression gumption aggression -> bad
            ```

#### Способ построения дерева
* Дерево строится в самом начале работы программы, при построении каждая последоваетльность действий в дереве сравнивается с правилами.
* Как только правило встерчается в последовательности действий в дереве - последовательность заканчивается и соответсвующий узел становится листом с результатом правла (good, bad)
* Последоваетльности действий в дереве, которые долшли до уровня глубины дерева и не соответсвуют ни одному правилу помечаются как neut (нейтральные концовки).

#### Проверка баланса дерева
* При построении дерево подсчитывает количество разных исходов и сохраняет в корне.
* У программы есть второй режим работы, в котором она строит дерево и выдает его баланс (показывает соотношение различных исходов с ситуации)
    ```
        Root Reward Probabilities
        Good   Neutral       Bad
        0.31      0.57      0.11
    ```

### Алгоритм работы с программой
1) Описать начальную ситуацию, описать пользователя.
```
    #### Description of the Situation
    A description of the initial scenario. All user actions and generated incidents occur within this context.
    Situation:

    I stepped out into the stairwell from my apartment to throw the trash into the garbage chute.
    The door to my apartment shut behind me, and I’m now locked outside without my keys.
    I’m standing in front of my apartment door and want to get back inside.
```
2) Описать к каким результатам может прийти пользователь (3 результата - хороший, нейтральный, плохой), соотнести результаты с видами концовок.
```
    #### Description of expected endings
    A list of possible global endings for the scenario. Every action and incident should logically bring the user closer to one of them:

    1. "good" - the person successfully gets back into their apartment.

    2. "neutral" - the person fails to enter but nothing bad happens.

    3. "bad" - the person disturbs others or is interrupted during the attempt.
```
3) Описать обобщенные действия пользователя
```
    exploration: Exploring the environment
    conflict: Clash of interests
    diplomacy: Conducting negotiations
    aggression: Aggressive actions
    gumption: A display of intelligence and resourcefulness
    stupidity: Slowness and useless actions
    active_action: Decisive action to interact with the environment
```
4) Описать правила в виде последовательностей действий, отнести к одному из двух вариантов (хорошему или плохому). Правила должны описывать логику действий пользователя в данной ситуации.
* Например, Исследование окружения->Проявление сообразительности->Активное действие = Успех.
* Или Проявление несообразителности->агрессия x2 = Неудача
```
    0 2 good
    3 3 3 bad
    1 4 6 good
    2 5 5 bad
```
3) Запустить программу с режимом вывода соотношения исходов. Отрегулировать Дейсвия и правила, описанные ранее, чтобы поменять соотношение исходов и сложность ситуации. Проверить выводом результатов.
```
    Root Reward Probabilities
    Good   Neutral       Bad
    0.31      0.57      0.11
```
4) Запустить программу в режиме диалога. В этом режиме польователю выдается начальная ситуация и он описывает свои действия на каждом шаге. На каждом шаге:
    * Программа передает всю нужную информацию нейросети:
        1) Описание дерева в виде действий и шансов на различные исходы в каждом дейсвии, сколько действий в игре осталось у пользователя до конца.
        2) Описание начальной ситуации и предыдущих действий пользователя, к каким действиям дерева они относились
        3) Описание текущего действия пользователя.
    * Нейросеть в соответсвии с информацией относит действие пользователя к одному из действий дерева, к какому считает наиболее нужным и генерирует происшествие, которое случилось от действия пользователя.
    * Нейросеть отправляет текущее действие пользователя, к какому действию дерева оно отнесено и результт действия (происшествие)
    ```
        json
        {
        "action": "<selected action class>",
        "user_action": "<human's original action>",
        "incident": "<generated incident based on action>"
        }
    ```


### Пример результата одного диалога
* Входит полледоваетльность действий пользователя, действия дерева, к которым былиотнесены дейсвтвия пользователя, реакция нейросети на действие в виде описания происшествия.
```
    {
        "1": {
            "action": "active_action",
            "incident": "You knock on the door loudly, hoping someone inside might hear you. After a few moments, you hear footsteps approaching from the other side. The door creaks open slightly, and you see your neighbor peeking through the crack.",
            "user_action": "I'm knocking the door"
        },
        "2": {
            "action": "diplomacy",
            "incident": "Your neighbor looks at you, slightly taken aback by your tone. 'I was just coming out to check the mail,' he replies. 'I can let you in, but you should be more careful with your keys.' He unlocks the door and lets you back into your apartment.",
            "user_action": "I tell him: you finally deigned to show up, I came out here without keys, let me in."
        },
        "3": {
            "action": "diplomacy",
            "incident": "Your neighbor, still slightly annoyed, responds, 'Well, you should have thought about that before you locked yourself out. I can let you in, but you need to be more careful in the future.' He unlocks the door and lets you back into your apartment.",
            "user_action": "I say that I will talk to him as I see fit."
        },
        "4": {
            "action": "gumption",
            "incident": "You walk around your neighbor, avoiding any further confrontation. You notice a small window in the stairwell that leads to a narrow ledge outside. You remember that the window in your apartment is slightly open. With a bit of effort, you manage to climb out onto the ledge and carefully make your way back to your apartment window. You slide it open and climb back inside, relieved to be back in your own space.",
            "user_action": "I walk around him in silence and go to my apartment."
        },
        "5": {
            "action": "gumption",
            "incident": "You carefully examine the window, assessing the best way to climb through. You manage to open it wider and, with a bit of struggle, you squeeze through the window and back into your apartment. You're relieved to be back inside, though a bit dusty from the effort.",
            "user_action": "I'm trying to get through the window."
        },
        "6": {
            "action": "stupidity",
            "incident": "You jump up and down in frustration, hoping to somehow magically get back into your apartment. Your neighbor, who was just about to leave, hears the commotion and looks at you with a puzzled expression. 'Are you alright?' he asks, clearly confused by your actions. You realize that jumping isn't helping your situation and decide to think of a more practical solution.",
            "user_action": "I'm jumping"
        },
        "7": {
            "action": "gumption",
            "incident": "You decide to head back to your apartment, thinking about the best way to get inside. As you approach the window, you notice that it's slightly open. With a bit of effort, you manage to climb through the window and back into your apartment, relieved to be back inside.",
            "user_action": "I'm going back to my apartment."
        }
    }
```
