 inherit NPC;
void create()
{
    set_name("��˿ȸ", ({ "sparrow" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("gender", "����");
        set("long", "һֻ�����Ľ�˿ȸ \n");
    set("combat_exp", 1000);
        set("attitude","peaceful");
        set("limbs", ({ "ͷ��", "����","���" }) );
        set("verbs", ({ "bite","claw" }) );
        set_temp("apply/dodge", 100);
            set("chat_chance", 7);
        set("chat_msg", ({
        "С��˿ȸߴߴ�ĽУ� \n",
        "��˿ȸ����������ë�� \n"
        }) );
        setup();
}   
