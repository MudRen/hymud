
inherit NPC;

void create()
{
        set_name("С����", ({ "bai tu","tu"}) );
        set("race", "Ұ��");
        set("age", 2);
        set("long", "һֻëɫѩ�׵�С���ӣ���ֻ�۾�����,����һɿһɿ��\n"
                    "�ÿɰ��ϣ�\n");

        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 800);
        setup();
}


