inherit NPC;
inherit F_UNIQUE;
void create()
{
        set_name("ͷ��", ({ "toulang", "lang" }) );
	set("race", "Ұ��");
	set("age", 10);
        set("unique", 2);
        set("long", "����Ⱥ�ӣ���ֻ��ͷ�Ĵ���Ǳ������Ĵ�һ�����ϣ��ͳ��غ��š�\n");
        set("attitude", "aggressive");	
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "ǰצ" }) );
	set("verbs", ({ "bite", "claw" }) );
	set("str",65);
	set("int",65);
	set("per",65);
	set("tol",65);
	set("con",65);
	set("dex",65);
        set("max_qi", 39950);
        set("max_jing", 39950);
        set("max_neili", 39900);
        set("eff_jingli", 39900);
	set("combat_exp", 9195000);
        set("chat_chance", 10);
	set("chat_msg", ({
                "ͷ�ǵ�˫Ŀ�ںڰ������ź�⣬������ע�������һ��һ����\n",
		(: random_move :),
                "ͷ�Ƿ���һ���ƽУ�������ʱ��Ҫ��������\n",
	}) );


	set_skill("parry", 250 + random(250));
	set_skill("dodge", 250 + random(250));
	set_skill("unarmed", 250 + random(250));
	set_skill("puyaogedou", 250 + random(520));
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
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/damage", 3000);
	set_temp("apply/armor", 3000);        
        set("senlin", 1);
	setup();
}

	
void unconcious()
{
    die();
}
void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;
      


        me->set_temp("killltl",1);

    message_vision("$N��ҵĺ��˼���, �ڵ��ϴ��˼��������������ˡ�\n", this_object());
	ob = new("/d/hj/obj/langpi");
	ob->move(environment(this_object()));

              ::die();
        return;
}