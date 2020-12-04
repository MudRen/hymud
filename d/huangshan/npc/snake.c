 inherit NPC;
void use_poison(); 
void create()
{
        set_name("��Ҷ��", ({ "big snake" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", "һ���綾��ȫ�������ӵ���\n");
        set("limbs", ({ "ͷ��", "����", "β��", "�ߴ�" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        
        set("max_qi",2400);
        set("max_jing",1800);
        set("max_jing",1800);
        
        set("combat_exp", 1200000);
        set("bellicosity", 300 );
        set_skill("dodge", 200);
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        setup();
    if (!random(2)) carry_object("/d/shanliu/npc/obj/zhuyeshedan");
}
void use_poison()
{
        object *enemy, ob;
        string msg; 
        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))]; 
        tell_object(ob,
"��������Ͼ�ʹ������һ��������������ӡ�ۡ�\n");
                ob->receive_wound("qi",40);
                ob->apply_condition("snake_poison", 
                (int)this_player()->query_condition("snake_poison")
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
