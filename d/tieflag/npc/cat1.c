 inherit NPC;
void create()
{
    set_name("��ū", ({ "catty" }) );
        set("race", "Ұ��");
        set("age", 3);
        set("gender", "����");
        set("long", "���������Ĳ�˹è\n");
        set("combat_exp", 10000);
        set("attitude","peaceful");
        set("chat_chance",3);
        set("chat_msg",({
                "��è���ؽ���һ����\n",
                "��è������űߴ��\n",
        }) );
        set("limbs", ({ "ͷ��", "����","β��" }) );
        set("verbs", ({ "bite","claw" }) );
        set_temp("apply/dodge", 200);
        setup();
}   
