//Cracked by Roath
inherit NPC;

void create()
{
        set_name("������", ({ "qixiu shou", "shou" }) );
        set("race", "Ұ��");
        set("age", 50);
        set("long", "һֻ������������������ͻ���һ˫�۾�����ݺݵص����㡣\n");
        set("attitude", "aggressive");
        set("bellicosity", 8000);
        set("str", 30);
        set("cor", 30);
 	set("per", 10);
        set("max_qi", 15000);
        set("max_jing", 15000);
	set("neili", 20000);
	set("max_neili", 10000);
	set("force_factor", 80);
	set("neili", 20000);
	set("max_neili", 10000);
	set("mana_factor", 80);

	set_skill("unarmed", 2000);
	set_skill("dodge", 2000);
	set_skill("parry", 2000);

        set("limbs", ({ "ͷ��", "����", "ǰ��", "���"}) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 800000);
  set("combat_exp", 8500000);

  set_skill("unarmed", 900+random(900));

       set_skill("dragon", 900+random(900));

      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");

    prepare_skill("unarmed", "dragon");
 set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
    (: perform_action, "unarmed.penhuo" :),
    	(: perform_action, "unarmed.yaoyao" :),           
    (: perform_action, "unarmed.tuwu" :),

 }) );
        set_temp("apply/damage", 2500);
        set_temp("apply/armor", 900);

        setup();
}

