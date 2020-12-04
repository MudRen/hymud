inherit NPC;
void create()
{
    set_name("�����", ({ "huilang", "lang" }) );
    set("race", "Ұ��");
    set("age", 10);
    set("long", "һͷ�ߴ�Ķ���, �������, ¶����ɭɭ�������\n");
    set("attitude", "aggressive");
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );
	set("str",65);
	set("int",65);
	set("per",65);
	set("tol",65);
	set("con",65);
	set("dex",65);
        set("max_qi", 3000);
        set("max_jing", 2000);
        set("eff_jingli", 2000);
	set("combat_exp", 300000);
	set("chat_chance", 5);
	set("chat_msg", ({
                "����~~~~������Ƿ���һ���ƽС�\n",
                "����Ƿ���һ���ƽУ�������ʱ��Ҫ��������\n",
	}) );
	

	set_skill("parry", 120 + random(250));
	set_skill("dodge", 150 + random(250));
	set_skill("unarmed", 150 + random(250));
	set_skill("puyaogedou", 150 + random(220));
	map_skill("unarmed", "puyaogedou");
	map_skill("parry", "puyaogedou");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.pfm1" :),                
                (: perform_action, "unarmed.pfm2" :),                
                (: perform_action, "unarmed.pfm3" :),                
                (: perform_action, "unarmed.pfm4" :),                
                (: perform_action, "unarmed.pfm5" :),                
                (: perform_action, "unarmed.pfm6" :),                
        }) );

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 100);
	set_temp("apply/armor", 400);
        set("senlin", 1);
	setup();
}
