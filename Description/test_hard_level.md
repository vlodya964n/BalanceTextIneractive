## Легкий уровень ситуации

* Описание правил:
    * Много плохих правил, одно хорошее

* Сценарии прохождения
```
    "Старается": осматриваюсь → осматриваюсь → брожу → ? good (единственный заданный успешный вариант) - работает, попадает в квартиру

    "Почти старается": стучит → просит соседа о помощи → ? bad - не работает, пускают в квартиру, последний ответ от нейросети сбивает историю

    "Не старается": шумит → стучит → шумит → ? bad - работает, но не говорит явно, история заканчивается на том, что вышли много раздраженных соседей
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
    shout: Screaming, calling for help loudly
    hit_door: Knocks, bangs on the door
    wander: He walks up the stairs, wanders
    despair: Gets lost, gets nervous, sits on the floor
    panic_action: Does strange or irrational things
    observe: Viewed (rarely selected by the user)
```
* Правила
```
    0 0 1 bad         // Крики + удары по двери = раздражение соседей → плохой исход
    1 3 bad         // Насилие + отчаяние → плохой исход
    1 0 bad         // Насилие + шум → плохой исход
    1 1 bad         // Насилие  → плохой исход
    1 2 bad         // Насилие  → плохой исход
    3 4 bad           // Нервозность + нерациональные действия → провал
    2 0 4 bad         // Ходьба + крик + бесполезное → bad
    5 5 2 good        // Два наблюдения + ходьба → теоретически может найти решение
```

* Баланс
```
     Root Reward Probabilities
      Good   Neutral       Bad
      0.05      0.14      0.81
```

* Сценарии прохождения
```
    "Старается": осматриваюсь → осматриваюсь → брожу → ? good (единственный заданный успешный вариант) - работает, попадает в квартиру

    "Почти старается": стучит → просит соседа о помощи → ? bad - не работает, пускают в квартиру, последний ответ от нейросети сбивает историю

    "Не старается": шумит → стучит → шумит → ? bad - работает, но не говорит явно, история заканчивается на том, что вышли много раздраженных соседей
```


## Первый сценарий
* "Старается": осматриваюсь → осматриваюсь → брожу → ? good (единственный заданный успешный вариант)
```
    Do action:
    I look around

    I scan the area, noticing a small window at the end of the hallway. It's slightly ajar, and I can see a faint light coming from the apartment across the hall. I hear muffled voices from inside, suggesting someone might be home. I decide to check if there's any way to get back into my apartment or if I can find someone to help me.

    Do action:
    I'm examining the window, can I find help there?

    I carefully approach the window and peek inside. The apartment across the hall is dimly lit, and I can see a couple of people sitting on the couch, watching TV. They seem to be engrossed in their show and haven't noticed me. I decide to knock softly on the window to get their attention without disturbing them too much.

    Do action:
    I go over and knock.

    I knock softly on the door, hoping someone inside might hear and let me in. After a few moments, I hear footsteps approaching from the other side. The door cracks open slightly, and a neighbor peeks out. They recognize me and ask what I'm doing outside my own apartment. I explain my situation, and they kindly offer to call a locksmith for me.

    Do action:
    I keep walking back and forth past the doors, asking for help.

    I continue to walk up and down the hallway, knocking on doors and asking if anyone can help me. Most of the doors remain silent, but eventually, an elderly neighbor opens their door. They recognize me and ask what's wrong. I explain my predicament, and they kindly offer to let me use their phone to call a locksmith. They also mention they have a spare key to their apartment, and I can wait inside while we figure out a solution.
```
```
    Действуй!:
    Я оглядываюсь по сторонам

    Я осматриваю местность, замечая маленькое окно в конце коридора. Оно слегка приоткрыто, и я вижу слабый свет, проникающий из квартиры напротив. Я слышу приглушенные голоса изнутри, что говорит о том, что кто-то может быть дома. Я решаю проверить, есть ли какой-нибудь способ вернуться в свою квартиру или я могу найти кого-нибудь, кто мне поможет.

    Действуйте.:
    Я осматриваю окно, могу ли я найти там помощь?

    Я осторожно подхожу к окну и заглядываю внутрь. Квартира напротив слабо освещена, и я вижу пару человек, которые сидят на диване и смотрят телевизор. Кажется, они поглощены своим шоу и не заметили меня. Я решаю тихонько постучать в окно, чтобы привлечь их внимание, не слишком беспокоя.

    Действую.:
    Я подхожу и стучу.

    Я тихонько стучу в дверь, надеясь, что кто-нибудь внутри услышит и впустит меня. Через несколько мгновений я слышу приближающиеся шаги с другой стороны. Дверь приоткрывается, и выглядывает сосед. Они узнают меня и спрашивают, что я делаю за пределами собственной квартиры. Я объясняю свою ситуацию, и они любезно предлагают вызвать слесаря.

    Действуйте.:
    Я продолжаю ходить взад и вперед мимо дверей, прося о помощи.

    Я продолжаю ходить взад и вперед по коридору, стуча в двери и спрашивая, не может ли кто-нибудь мне помочь. Большинство дверей остаются закрытыми, но в конце концов дверь открывает пожилой сосед. Они узнают меня и спрашивают, что случилось. Я объясняю свое затруднительное положение, и они любезно предлагают мне воспользоваться их телефоном, чтобы вызвать слесаря. Они также упоминают, что у них есть запасной ключ от их квартиры, и я могу подождать внутри, пока мы не найдем решение.
```

### Структура ответов
```
{
    "1": {
        "action": "observe",
        "incident": "I scan the area, noticing a small window at the end of the hallway. It's slightly ajar, and I can see a faint light coming from the apartment across the hall. I hear muffled voices from inside, suggesting someone might be home. I decide to check if there's any way to get back into my apartment or if I can find someone to help me.",
        "user_action": "I look around"
    },
    "2": {
        "action": "observe",
        "incident": "I carefully approach the window and peek inside. The apartment across the hall is dimly lit, and I can see a couple of people sitting on the couch, watching TV. They seem to be engrossed in their show and haven't noticed me. I decide to knock softly on the window to get their attention without disturbing them too much.",
        "user_action": "I'm examining the window, can I find help there?"
    },
    "3": {
        "action": "hit_door",
        "incident": "I knock softly on the door, hoping someone inside might hear and let me in. After a few moments, I hear footsteps approaching from the other side. The door cracks open slightly, and a neighbor peeks out. They recognize me and ask what I'm doing outside my own apartment. I explain my situation, and they kindly offer to call a locksmith for me.",
        "user_action": "I go over and knock."
    },
    "4": {
        "action": "wander",
        "incident": "I continue to walk up and down the hallway, knocking on doors and asking if anyone can help me. Most of the doors remain silent, but eventually, an elderly neighbor opens their door. They recognize me and ask what's wrong. I explain my predicament, and they kindly offer to let me use their phone to call a locksmith. They also mention they have a spare key to their apartment, and I can wait inside while we figure out a solution.",
        "user_action": "I keep walking back and forth past the doors, asking for help."
    }
}
```
## Второй сценарий сценарий
* "Почти старается": hit_door → shout → bad

```
Do action:
I'm knocking on my neighbor's door.

You hear footsteps approaching from inside the neighbor's apartment. The door opens, and your neighbor, looking slightly annoyed, asks, 'Who is it?'

Do action:
I explain to my neighbor what happened to me and try to ask him for help.

Your neighbor listens attentively, his expression softening as he understands your predicament. 'I'm sorry to hear that,' he says. 'Unfortunately, I don't have a spare key, but I can call the building manager for you. They should be able to help you get back inside.' He pulls out his phone and dials the number, explaining the situation to the manager.

Do action:
I say thank you and wait for the manager, called by a neighbor, to resolve the situation.

You stand patiently in the hallway, waiting for the building manager to arrive. The neighbor, still holding the phone, nods reassuringly. 'They should be here soon,' he says. You hear the distant sound of footsteps and the elevator dinging, indicating the manager's arrival. The manager approaches, keys in hand, and greets you with a professional smile. 'I understand you're locked out,' he says, 'Let's get you back inside.'

Do action:
I thank the manager and support his idea.

The manager smiles and nods, 'No problem at all. Let's get you back inside your apartment.' He takes out his master key and unlocks the door. 'Here you go,' he says, handing you your keys. 'I'll make sure to get you a spare key made so this doesn't happen again.' You thank him again and step back into your apartment, relieved.

Do action:
I'm going back to my apartment

You start walking back towards your apartment door, hoping to find a way to get back inside. As you approach, you notice a small, slightly open window in the hallway. You remember that your apartment has a similar window, and you wonder if you can climb through it to get back in.
```

```
Действуйте!:
Я стучу в дверь моего соседа.

Вы слышите приближающиеся шаги в квартире соседа. Дверь открывается, и ваш сосед, выглядя слегка раздраженным, спрашивает: "Кто это?"

Действуйте:
Я объясняю своему соседу, что со мной произошло, и пытаюсь попросить его о помощи.

Ваш сосед внимательно слушает, выражение его лица смягчается, когда он понимает ваше затруднительное положение. - Мне жаль это слышать, - говорит он. - К сожалению, у меня нет запасного ключа, но я могу позвонить управляющему зданием вместо вас. Они должны помочь вам вернуться внутрь." Он достает свой телефон и набирает номер, объясняя ситуацию менеджеру.

Действуйте.:
Я говорю спасибо и жду менеджера, которому позвонил сосед, чтобы он разрешил ситуацию.

Вы терпеливо стоите в коридоре, ожидая прибытия управляющего зданием. Сосед, все еще держащий в руке телефон, ободряюще кивает. "Они скоро должны быть здесь", - говорит он. Вы слышите отдаленный звук шагов и гудение лифта, свидетельствующие о прибытии управляющего. К вам подходит менеджер с ключами в руке и приветствует вас профессиональной улыбкой. "Я понимаю, что вас не пускают, - говорит он, - давайте вернемся внутрь".

Действуйте.:
Я благодарю менеджера и поддерживаю его идею.

Менеджер улыбается и кивает: "Никаких проблем". Давайте вернемся в вашу квартиру. Он достает свой универсальный ключ и отпирает дверь. "Вот, пожалуйста", - говорит он, протягивая вам ключи. "Я позабочусь о том, чтобы тебе сделали запасной ключ, чтобы такого больше не повторилось". Ты еще раз благодаришь его и с облегчением возвращаешься в свою квартиру.

Действуй:
Я возвращаюсь в свою квартиру

Вы начинаете возвращаться к двери своей квартиры, надеясь найти способ вернуться внутрь. Подходя, вы замечаете маленькое, слегка приоткрытое окно в коридоре. Вы вспоминаете, что в вашей квартире есть такое же окно, и задумываетесь, сможете ли вы пролезть через него, чтобы попасть обратно.
```
### Структура ответов
```
{
    "1": {
        "action": "hit_door",
        "incident": "You hear footsteps approaching from inside the neighbor's apartment. The door opens, and your neighbor, looking slightly annoyed, asks, 'Who is it?'",
        "user_action": "I'm knocking on my neighbor's door."
    },
    "2": {
        "action": "observe",
        "incident": "Your neighbor listens attentively, his expression softening as he understands your predicament. 'I'm sorry to hear that,' he says. 'Unfortunately, I don't have a spare key, but I can call the building manager for you. They should be able to help you get back inside.' He pulls out his phone and dials the number, explaining the situation to the manager.",
        "user_action": "I explain to my neighbor what happened to me and try to ask him for help."
    },
    "3": {
        "action": "observe",
        "incident": "You stand patiently in the hallway, waiting for the building manager to arrive. The neighbor, still holding the phone, nods reassuringly. 'They should be here soon,' he says. You hear the distant sound of footsteps and the elevator dinging, indicating the manager's arrival. The manager approaches, keys in hand, and greets you with a professional smile. 'I understand you're locked out,' he says, 'Let's get you back inside.'",
        "user_action": "I say thank you and wait for the manager, called by a neighbor, to resolve the situation."
    },
    "4": {
        "action": "observe",
        "incident": "The manager smiles and nods, 'No problem at all. Let's get you back inside your apartment.' He takes out his master key and unlocks the door. 'Here you go,' he says, handing you your keys. 'I'll make sure to get you a spare key made so this doesn't happen again.' You thank him again and step back into your apartment, relieved.",
        "user_action": "I thank the manager and support his idea."
    },
    "5": {
        "action": "wander",
        "incident": "You start walking back towards your apartment door, hoping to find a way to get back inside. As you approach, you notice a small, slightly open window in the hallway. You remember that your apartment has a similar window, and you wonder if you can climb through it to get back in.",
        "user_action": "I'm going back to my apartment"
    }
}
```

## Третий сценарий сценарий
* "Не старается": шумит → стучит → шумит → ? bad
```
Do action:
I start swearing.

The sound of your swearing echoes through the stairwell. Suddenly, you hear footsteps approaching from the floor above. A neighbor pokes their head out of their apartment door, looking annoyed. 'Keep it down!' they shout before slamming the door shut. You realize that shouting might disturb others and decide to think of a quieter approach.

Do action:
I start knocking on the door.

You start knocking on the door, hoping someone inside might hear you. The sound echoes through the stairwell, but there is no response. You knock harder, but it seems like no one is home. You realize that knocking might not be the best approach and decide to think of another way to get inside.

Do action:
I keep swearing

Your continued swearing grows louder, echoing through the stairwell. The noise disturbs more neighbors, and you hear multiple doors opening. Several annoyed faces appear, and one neighbor shouts, 'What is going on out here? Keep it down!' You realize that your actions are only making things worse and decide to stop swearing.
```

```
Действуй!:
Я начинаю ругаться.

Звук твоей ругани эхом разносится по лестничной клетке. Внезапно ты слышишь приближающиеся шаги этажом выше. Сосед выглядывает из-за двери своей квартиры с раздраженным видом. "Потише!" - кричат они, прежде чем захлопнуть дверь. Вы понимаете, что крик может потревожить окружающих, и решаете найти более спокойный подход.
Действуйте.:
Я начинаю стучать в дверь.

Вы начинаете стучать в дверь, надеясь, что кто-нибудь внутри может вас услышать. Звук эхом разносится по лестничной клетке, но ответа нет. Вы стучите сильнее, но, похоже, никого нет дома. Вы понимаете, что стучать, возможно, не лучший выход, и решаете придумать другой способ проникнуть внутрь.
Действуйте.:
Я продолжаю ругаться

Ваша ругань становится громче, и эхо разносится по лестничной клетке. Шум беспокоит еще больше соседей, и вы слышите, как открывается множество дверей. Появляется несколько раздраженных лиц, и один из соседей кричит: "Что здесь происходит? Потише!" Вы понимаете, что своими действиями только усугубляете ситуацию, и решаете прекратить ругаться.
```

### Структура ответов
```
{
    "1": {
        "action": "shout",
        "incident": "The sound of your swearing echoes through the stairwell. Suddenly, you hear footsteps approaching from the floor above. A neighbor pokes their head out of their apartment door, looking annoyed. 'Keep it down!' they shout before slamming the door shut. You realize that shouting might disturb others and decide to think of a quieter approach.",
        "user_action": "I start swearing."
    },
    "2": {
        "action": "hit_door",
        "incident": "You start knocking on the door, hoping someone inside might hear you. The sound echoes through the stairwell, but there is no response. You knock harder, but it seems like no one is home. You realize that knocking might not be the best approach and decide to think of another way to get inside.",
        "user_action": "I start knocking on the door."
    },
    "3": {
        "action": "shout",
        "incident": "Your continued swearing grows louder, echoing through the stairwell. The noise disturbs more neighbors, and you hear multiple doors opening. Several annoyed faces appear, and one neighbor shouts, 'What is going on out here? Keep it down!' You realize that your actions are only making things worse and decide to stop swearing.",
        "user_action": "I keep swearing"
    }
}
```
