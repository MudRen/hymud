 // teacher.c
inherit NPC; 
void create()
{
        int i,amun;
        string *order = ({"κ", "��"});
        string *orderr = ({"����", "����"});
        set_name( order[random(2)] + orderr[random(2)], ({ "kid", "small kid" }) );
        set("title", "��֪Сͯ");
        set("gender", "����" );
        set("age", random(5)+4);
        set("int", 26);
        set("long",
                "����С���ܺ��۸���\n");
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :)
        }) ); 
        set("attitude", "peaceful");
        set("combat_exp", random(200));
        set_skill("unarmed", 1+random(10));
        set_skill("taiji-quan", 110+random(510));
        map_skill("unarmed", "taiji-quan");
        setup();
}   
