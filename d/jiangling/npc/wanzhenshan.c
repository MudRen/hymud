//Edited by fandog, 02/15/2000
#include <ansi.h>
inherit NPC;

void create ()
{
	set_name("����ɽ", ({"wan zhenshan","wan"}));
	set("nickname", HIR"������"NOR);
	set("long", "
һλ���ο�������ߣ��������壬���ĳ��ȣ�˿����������̬֮��\n");
	set("gender", "����");
	set("age", 50);
	set("combat_exp", 10000000);
	set("str", 125);
	set("int", 125);
	set("con", 125);
	set("dex", 125);
	set("per", 125);
	set_skill("force", 320);
	set_skill("dodge", 320);
	set_skill("sword", 320);
	set_skill("parry", 320);
	set_skill("feixian-steps", 320);
	set("max_qi",30000);
	set("max_jing",30000);
	set("max_neili",30000);
	set("qi",30000);
	set("jing",30000);
	set("neili",30000);

	set_skill("liancheng-jian", 320);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.ci" :),
                (: perform_action, "sword.erguang" :),
                (: perform_action, "sword.gan" :),
                (: perform_action, "sword.qian" :),
                (: perform_action, "sword.qu" :),
                (: perform_action, "sword.zhai" :),
                (: perform_action, "sword.zhu" :),
        
        }) );
	set_temp("apply/attack",190);
	set_temp("apply/defense",190);
	set_temp("apply/armor",2500);
	set_temp("apply/damage",2500);
	map_skill("dodge", "feixian-steps");
	map_skill("parry", "liancheng-jian");
	map_skill("sword", "liancheng-jian");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}



void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;
              //me->add("score",1);        
        message_vision(RED"$Nһ��ŭ�𣬻�����Ѫֱ����������ȥ!\n"NOR,ob,me);
        


        me->set_temp("killlc1",1);


              ::die();
        return;
}