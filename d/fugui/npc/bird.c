 inherit NPC;
void create()
{
    set_name("Сϲȵ", ({ "bird" }) );
        set("race", "Ұ��");
        set("age", 1);
    set("long", "һֻ�����Ҹ������Сϲȵ��ߴߴ������ͣ�ؽС�\n");
        
        set("limbs", ({ "ͷ��", "����", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) ); 
        set("chat_chance", 1);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "���ҡ�\n",
                "������\n",
        }));
set("attitude", "friendly");
        set("max_jing", 100);
        set("max_qi", 300);
        set("max_jing", 100);
    set("combat_exp", 3000);
    
        set("arrive_msg","���˹���");
        set("leave_msg","�ɿ���");
        set_temp("apply/dodge", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 3); 
        setup();
}    
