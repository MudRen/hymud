// gongweishi.c

inherit NPC;

void create()
{
	set_name("�ʹ���ʿ", ({ "wei shi", "shi" }));
	set("gender", "����");
	set("age", random(10) + 20);
	set("str", 25);
	set("dex", 16);
	set("long", "���ǻʹ��Ĵ�����ʿ�������ּף���ִ������\n");
	set("combat_exp", 90000);
	set("shen_type", 1);
	set("attitude", "peaceful");

set("max_qi", 12000);
	set("eff_qi", 12000);
	set("qi", 12000);
	set("max_jing", 8000);
	set("jing", 8000);
	set("neili", 20000);
	set("max_neili", 20000);
	set("jiali", 60);

	set_temp("apply/attack",  100);
	set_temp("apply/defense", 100);

 set("combat_exp", 1400000+random(2000000));
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.leitingpili" :),
                (: perform_action, "sword.kuang" :),
                (: random_move :),
        }) );
        set("chat_chance", 60);
        set("chat_msg", ({
                (: random_move :),
        }) );

        set_skill("unarmed", 180+random(180));
        set_skill("sword", 180+random(180));
        set_skill("parry", 180+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-jian", 280+random(380));
        
        map_skill("sword", "kuang-jian");
        map_skill("parry", "kuang-jian");
        set_temp("apply/attack", 120);
        set_temp("apply/defense",150);
        set_temp("apply/armor", 350);
        set_temp("apply/damage", 320);
	set("jiali", 10);

	setup();
	carry_object("/d/city/npc/obj/tiejia")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

