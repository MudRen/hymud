inherit NPC;
void create()
{
        set_name("小山羊", ({ "little goat","goat" }) );
        set("race", "野兽");
        set("age", 3);
        set("long", "一只美丽的小山羊，正在低头吃草。\n");
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 4000+random(2000));
        setup();
}

