inherit NPC;
void create()
{
        set_name("小牦牛", ({ "mao niu","niu" }) );
        set("race", "野兽");
        set("age", 4);
        set("long", "一只披着尺许长毛的小牦牛，正在低头吃草。\n");

        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 30000+random(20000));

        setup();
}


