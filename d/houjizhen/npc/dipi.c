// dipi.c
// by dicky

inherit NPC;
int ask_jian();

void create()
{
        set_name("��Ʀ", ({"di pi","dipi"}) );
        set("gender", "����" );
        set("age", 20);
        set("long", "����һ���ȵ��������ĵ�Ʀ��\n");

        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set("combat_exp", 750);
        set("shen_type", -1);
        set("str", 25);
        set("dex", 20);
        set("con", 18);
        set("int", 15);
        set("attitude","heroism");
        setup();
        set("chat_chance", 2);

        set("chat_msg", ({
		"��Ʀ���Ժ����ĺ������������ð�������ְ�������\n",
		"��Ʀ����ǽ�ǣ������������������\n",
        }) );

        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("coin",10);
}
