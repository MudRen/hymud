// tufei.c
//by dicky

inherit NPC;

void create()
{
        set_name("����", ({ "tufei","bandit","fei" }) );
        set("gender", "����");
        set("age", 30);
        set("long",
                "��һ��������⪬һ�������ɷ��ģ��������������η��\n");
        set("combat_exp", 100000);
        set("shen_type", -1);
        set("attitude", "killer");
        set("apply/attack", 20);
        set("apply/defense", 20);

        set("max_sen",1000);
        set("max_qi", 1000);
        set("qi", 1000);

	set("max_jing", 1000);
	set("max_jing", 1000);
	set("neili", 100);
	set("max_neili", 100);
	set("force_factor", 10);
      	
        set_skill("unarmed", 70);
        set_skill("sword", 70);
        set_skill("parry", 70);
        set_skill("dodge", 70);
        setup();
        carry_object(__DIR__"obj/hujia")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
        add_money("silver", 40);
}