//long.c
#include <ansi.h>
inherit NPC;

int ask_zhou();

void create()
{
        set_name("��������", ( { "luosha wang", "wang" }) );
        set("title", HIR"��ɲ���Ͻ���"NOR);
        set("gender", "����" );
        set("age", 60);
        set("long",
              "���Ǹ���������ʮ�������ɲ��\n"
        );

        set("int", 30);
        set("str", 25);
        set("con", 30);
        set("dex", 25);

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/damage", 1000);

        set("qi",84000);
        set("max_qi", 84000);
        set("jing", 82000);
        set("max_jing", 82000);
        set("neili", 82000);
        set("max_neili", 82000);
        set("jiali", 150);
        set("combat_exp", 9000000);
        set("score", 250000);

    
        set("str", 60);
        set("int", 69);
        set("con", 60);
        set("dex", 68);

        set("qi", 33900);
        set("max_qi", 33900);
        set("jing", 33900);
        set("max_jing", 33900);
        set("neili", 61500);
        set("max_neili", 61500);
        set("jiali", 50);
set("no_get",1);
        set("combat_exp", 8500000);
        set("score", 200000);
        set_skill("force", 570);
        set_skill("unarmed", 500);
        set_skill("dodge", 550);
        set_skill("parry", 550);
        set_skill("hand",570);
        set_skill("staff", 570);
        set_skill("taixuan-gong", 550);
set_skill("huanhe-dao", 550);
set_skill("sata-shenfa", 550);
set_skill("sumi-jian", 580);
set_skill("wuyu-quan", 550);
set_skill("xiuli-qiankun", 550);
set_skill("strike", 550);
set_skill("cuff", 550);
set_skill("unarmed", 550);
set_skill("blade", 550);
set_skill("sword", 550);
set_skill("club", 580);
set_skill("bawang-qiang", 580);
map_skill("sword", "sumi-jian");
//map_skill("blade", "huanhe-dao");
map_skill("strike", "xiuli-qiankun");
map_skill("cuff", "wuyu-quan");
      map_skill("force", "taixuan-gong");
        map_skill("dodge", "sata-shenfa");
        map_skill("parry", "taixuan-gong");
        map_skill("unarmed", "taixuan-gong");
set_skill("club", 580);
set_skill("bawang-qiang", 580);

    	prepare_skill("strike", "xiuli-qiankun");
	prepare_skill("cuff", "wuyu-quan");

        
	set("chat_chance_combat", 90);
       set("chat_msg_combat", ({
                (: perform_action, "sword.dieying" :),
                (: perform_action, "sword.feiwu" :),
                (: perform_action, "sword.jiushi" :),
                (: perform_action, "sword.jiushi" :),                	
                (: perform_action, "sword.ruhe" :),
                (: perform_action, "sword.shenfeng" :),                	
                (: perform_action, "sword.wuyun" :),                	                	                	                	
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.jing" :),
                (: perform_action, "parry.xuan" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.taixuan" :),
                
        }) );


	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 1000);
	set_temp("apply/damage", 600);
        setup();

        carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/taiwan/npc/obj/xifu")->wield();
        add_money("gold",1);
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( environment(ob) != environment() ) return;
	if (userp(ob))
{
	say("��ë��̧�־���һǹ���飡ǹ��һ�Ż��������\n");
	ob->receive_damage("qi",550+random(3000));
	ob->receive_wound("qi",550+random(3000));
kill_ob(ob);
}
}
void die()
{
			int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
message_vision("\n$N�������ɳ�ʵĶ�������....��˵���������۵������ˡ�\n", this_object());

who->add_temp("book771",1);

	::die();
}