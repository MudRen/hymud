 inherit NPC;
void create()
{
        set_name("�˻���", ({ "snake" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", "һ����ͨ�Ĳ˻��ߣ������ܳ�����û��ʲô���ԡ�\n"); 
        set("limbs", ({ "ͷ��", "����", "β��", "�ߴ�" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        set_skill("dodge", 10);
        set("combat_exp", 10000);
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: random_move :),
        }) );
        setup();
} 
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
}   
