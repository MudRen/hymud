 inherit NPC;
void create()
{
    set_name("Сè��", ({ "catty" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("gender", "����");
        set("long", "һֻСС�ģ�èͷè�Ե�С��è\n");
        set("combat_exp", 1000);
        set("attitude","peaceful");
        set("limbs", ({ "ͷ��", "����","β��" }) );
        set("verbs", ({ "bite","claw" }) );
        set_temp("apply/dodge", 100);
        set("chat_chance", 7);
        set("chat_msg", ({
        (: random_move :)
        }) );
        set("arrive_msg", "���˹���");
        set("leave_msg", "����������һ����������");
        setup();
}  
