
inherit NPC;

void create()
{
        set_name("野兔", ({ "ye tu","tu"}) );
        set("race", "野兽");
        set("age", 2);
        set("long", "一只灰色皮毛的野兔，身长逾尺，鼻子一煽一煽的。\n");
                set("weight", 5000);
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 2000);
        set("unarmed",10);
        setup();
}


