// tufei1.c
//by dicky

inherit NPC;

void create()
{
        set_name("����ͷĿ", ({ "tufei tou","bandit","fei" }) );
        set("gender", "����");
        set("age", 30);
        set("long",
                "��һ��������⪬һ�������ɷ��ģ��������������η��\n");
        set("combat_exp", 150000);
        set("shen_type", -1);
        set("attitude", "killer");
        set("apply/attack", 20);
        set("apply/defense", 20);
      	set("chat_chance", 2);
      	set("chat_msg", ({
          "����һ����: ��ɽ���ҿ������������ԣ���Ҫ�Ӵ˹���������·�� !\n",
      }) );

        set("max_sen",1500);
        set("max_qi", 1500);
        set("qi", 1500);

	set("max_jing", 1500);
	set("max_jing", 1500);
	set("neili", 150);
	set("max_neili", 150);
	set("force_factor", 15);

	set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        setup();
        carry_object(__DIR__"obj/hujia")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
        add_money("silver", 40);
}