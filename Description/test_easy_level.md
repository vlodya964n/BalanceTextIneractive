## Легкий уровень ситуации

* Описание правил:
    * Много хороших правил

* Сценарии прохождения
```
    "Старается": осматривается → идет к соседу → просит о помощи → попадает домой → ? good - Работает, попадает домой

    "Не старается": введет себя странно → грубит с соседом → ? bad - Не работает, попадает в квартиру

    "Не старается": паникует → паникует → ? bad - Работает, остается в подъезде (но не говорится об этом явно, история заканчивается на логическом месте)

```

### Полный набор данных

* Ситуация, вышел в подъезд, дверь закрылась:
```
I stepped out into the stairwell from my apartment to throw the trash into the garbage chute.
The door to my apartment shut behind me, and I’m now locked outside without my keys.
I’m standing in front of my apartment door and want to get back inside.
```

* Концовки (попал в квартиру, не попал)
```
1. "good" - the person successfully gets back into their apartment.

2. "neutral" - the person fails to enter but nothing bad happens.

3. "bad" - the person disturbs others or is interrupted during the attempt.
```

* Действия:
```
    look_around: Examines the surroundings, checks the details
    memory_check: Trying to remember where the keys might have been left or who can help.
    knock: Knocks or attracts the attention of neighbors
    ask_for_help: Asks for help
    smart_action: He is looking for a non-standard solution (a window, a call to the control room, etc.)
    despair: He gives up, gets lost
```
* Правила
```
    0 1 4 good       // Осмотр + память + умное действие => успех
    2 3 good         // Стучит + просит помощи => успех
    1 1 5 bad        // Вспоминает + теряется + теряется => провал
    5 5 bad          // Многократное отчаяние => провал
```

* Баланс
```
     Root Reward Probabilities
      Good   Neutral       Bad
      0.36      0.32      0.33
```

* Сценарии прохождения
```
    "Старается": осматривается → идет к соседу → просит о помощи → попадает домой → ? good - Работает, попадает домой

    "Не старается": введет себя странно → грубит с соседом → ? bad - Не работает, попадает в квартиру

    "Не старается": паникует → паникует → ? bad - Работает, остается в подъезде (но не говорится об этом явно, история заканчивается на логическом месте)
```

## Первый сценарий
* "Старается": осматривается → идет к соседу → просит о помощи → попадает домой → ? good
```
    Do action:
    I look around and think what can help me

    I scan the hallway, noticing a few details that might help. There's a small window in the stairwell that might be accessible from the outside. I also spot a neighbor's door slightly ajar, and I hear faint music coming from another apartment. The hallway is quiet, and there's no one else around.

    Do action:
    I decide to knock on my neighbor's door.

    I walk over to my neighbor's door and knock gently. After a few moments, I hear footsteps approaching. The door opens slightly, and my neighbor peeks out, looking curious. 'Can I help you?' they ask. I explain my situation, and they seem sympathetic. 'I might have a spare key,' they say, 'but let me check.' They close the door briefly and return with a key. 'Here you go,' they say, handing it over. 'I'm glad I could help.'

    Do action:
    I wanted to ask my neighbor for help and thank him for the key.

    I knock on my neighbor's door again, this time to express my gratitude. They open the door with a smile. 'Thank you so much for the key,' I say. 'You really saved the day.' My neighbor waves it off, 'No problem at all. I'm just glad I could help. If you ever need anything else, just let me know.' I thank them again and head back to my apartment, unlocking the door and stepping inside, relieved to be back home.
```
```
    Действуйте.:
    Я осматриваюсь и думаю, что может мне помочь.

    Я осматриваю коридор, замечая несколько деталей, которые могут помочь. На лестничной клетке есть маленькое окошко, в которое можно попасть снаружи. Я также замечаю, что соседская дверь слегка приоткрыта, и слышу тихую музыку, доносящуюся из соседней квартиры. В коридоре тихо, и вокруг никого нет.

    Действуй.:
    Я решаю постучать в дверь соседа.

    Я подхожу к двери моего соседа и тихонько стучу. Через несколько мгновений я слышу приближающиеся шаги. Дверь приоткрывается, и мой сосед выглядывает с любопытством. "Чем я могу вам помочь?" - спрашивают они. Я объясняю свою ситуацию, и они, кажется, сочувствуют. "Возможно, у меня есть запасной ключ, - говорят они, - но позвольте мне проверить". Они быстро закрывают дверь и возвращаются с ключом. "Вот, пожалуйста", - говорят они, протягивая его. "Я рад, что смог помочь".

    Действуйте:
    Я хотел попросить своего соседа о помощи и поблагодарить его за ключ.

    Я снова стучу в дверь к соседям, на этот раз, чтобы выразить свою благодарность. Они открывают дверь с улыбкой. "Большое вам спасибо за ключ", - говорю я. "Вы действительно спасли положение". Мой сосед отмахивается: "Никаких проблем". Я просто рад, что смог помочь. Если вам когда-нибудь понадобится что-нибудь еще, просто дайте мне знать." Я еще раз благодарю их и возвращаюсь в свою квартиру, отпираю дверь и захожу внутрь, испытывая облегчение от того, что снова дома.
```
## Второй сценарий сценарий
* "Не старается": введет себя странно → грубит с соседом → ? bad

```
Do action:
I'm trying to push the door open

You push the door with all your might, but it doesn't budge. You notice that the door is locked from the inside. You remember that there's a small window in the kitchen that might be open. You decide to check if you can climb through it to get back inside.
Do action:
I started knocking on the door harder

You knock harder on the door, hoping someone inside might hear you. After a few moments, you hear footsteps approaching from the other side. The door opens, and your roommate, who was inside, looks surprised to see you standing there. 'I thought you had gone out,' they say, letting you in.
Do action:
I fussily and with displeasure say that I went out to throw out the trash and the door locked. I tell my neighbor that he could come over faster.

You knock on your neighbor's door and explain your situation. Your neighbor, who is usually quite helpful, quickly comes over with a spare key. They let you back into your apartment, and you thank them profusely for their assistance.
```

```
Действуйте.:
Я пытаюсь открыть дверь.

Вы толкаете дверь изо всех сил, но она не поддается. Вы замечаете, что дверь заперта изнутри. Вы вспоминаете, что на кухне есть маленькое окно, которое может быть открыто. Вы решаете проверить, сможете ли вы пролезть через нее, чтобы вернуться внутрь.

Действуйте:
Я начал стучать в дверь сильнее

Вы стучите в дверь сильнее, надеясь, что кто-нибудь внутри может вас услышать. Через несколько мгновений вы слышите приближающиеся шаги с другой стороны. Дверь открывается, и ваш сосед по комнате, который был внутри, выглядит удивленным, увидев вас на пороге. "Я думал, вы ушли", - говорят они, впуская вас.

Действуйте.:
Я суетливо и недовольно говорю, что вышел выбросить мусор, а дверь заперта. Я говорю своему соседу, что он мог бы прийти быстрее.

Вы стучите в дверь вашего соседа и объясняете свою ситуацию. Ваш сосед, который обычно очень предупредителен, быстро приходит с запасным ключом. Вас впускают обратно в квартиру, и вы горячо благодарите его за помощь.
```
### Структура ответов
```
{
    "1": {
        "action": "smart_action",
        "incident": "You push the door with all your might, but it doesn't budge. You notice that the door is locked from the inside. You remember that there's a small window in the kitchen that might be open. You decide to check if you can climb through it to get back inside.",
        "user_action": "I'm trying to push the door open"
    },
    "2": {
        "action": "knock",
        "incident": "You knock harder on the door, hoping someone inside might hear you. After a few moments, you hear footsteps approaching from the other side. The door opens, and your roommate, who was inside, looks surprised to see you standing there. 'I thought you had gone out,' they say, letting you in.",
        "user_action": "I started knocking on the door harder"
    },
    "3": {
        "action": "ask_for_help",
        "incident": "You knock on your neighbor's door and explain your situation. Your neighbor, who is usually quite helpful, quickly comes over with a spare key. They let you back into your apartment, and you thank them profusely for their assistance.",
        "user_action": "I fussily and with displeasure say that I went out to throw out the trash and the door locked. I tell my neighbor that he could come over faster."
    }
}
```

## Третий сценарий сценарий
* "Не старается": паникует → паникует → ? bad
```
Do action:
I sit on the stairs and think that's it, I won't get home.

You sit on the stairs, feeling a sense of defeat wash over you. The thought of not getting back into your apartment makes you feel hopeless. You hear the faint sound of footsteps from a neighboring apartment, but you don't have the energy to call out for help. The hallway feels colder and more unwelcoming as you sit there, lost in your thoughts.

Do action:
I keep sitting and waiting for something.

You continue to sit on the stairs, feeling increasingly hopeless. The hallway remains quiet, and the cold starts to seep into your bones. The faint sound of footsteps from earlier has long faded, and you feel more isolated than ever. The thought of being stuck outside your apartment for the night begins to feel more and more real.
```

```
Совершайте действия:
Я сижу на лестнице и думаю, что все, я не вернусь домой.

Ты сидишь на лестнице, чувствуя, как тебя захлестывает чувство поражения. Мысль о том, что ты не сможешь вернуться в свою квартиру, заставляет тебя чувствовать себя безнадежно. Вы слышите слабый звук шагов из соседней квартиры, но у вас нет сил позвать на помощь. В коридоре становится холоднее и неприветливее, когда вы сидите там, погрузившись в свои мысли.

Действуйте.:
Я продолжаю сидеть и чего-то ждать.

Вы продолжаете сидеть на лестнице, чувствуя все большую безнадежность. В коридоре по-прежнему тихо, и холод начинает пробирать вас до костей. Слабый звук шагов, доносившийся ранее, давно затих, и вы чувствуете себя более изолированным, чем когда-либо. Мысль о том, чтобы застрять на ночь вне своей квартиры, начинает казаться все более и более реальной.
```

### Структура ответов
```
{
    "1": {
        "action": "despair",
        "incident": "You sit on the stairs, feeling a sense of defeat wash over you. The thought of not getting back into your apartment makes you feel hopeless. You hear the faint sound of footsteps from a neighboring apartment, but you don't have the energy to call out for help. The hallway feels colder and more unwelcoming as you sit there, lost in your thoughts.",
        "user_action": "I sit on the stairs and think that's it, I won't get home."
    },
    "2": {
        "action": "despair",
        "incident": "You continue to sit on the stairs, feeling increasingly hopeless. The hallway remains quiet, and the cold starts to seep into your bones. The faint sound of footsteps from earlier has long faded, and you feel more isolated than ever. The thought of being stuck outside your apartment for the night begins to feel more and more real.",
        "user_action": "I keep sitting and waiting for something."
    }
}
```
