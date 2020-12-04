 inherit NPC;
void use_poison(); 
void create()
{
        set_name("�����", ({ "bad frog" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", "һֻ�綾�ĵ����\n"); 
        set("limbs", ({ "ͷ��", "����", "����", "ǰ��" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        set_skill("dodge", 200);
        set("combat_exp", random(999999));
        set("bellicosity", 300 );
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        setup();
}
void use_poison()
{
        object *enemy, ob;
        string msg; 
        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))]; 
        tell_object(ob,
"���������һ�飬�����Ѿ�����ղ�����ˡ�\n");
                ob->receive_wound("qi",40);
                ob->apply_condition("unknown_poison", 
                (int)this_player()->query_condition("unknown_poison")
                + random(3)+3);
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
}     
