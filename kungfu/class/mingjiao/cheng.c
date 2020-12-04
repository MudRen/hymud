// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// cheng.c ����
#include <ansi.h>;
inherit NPC;

void create()
{
        set_name("����",({"cheng kun","cheng","kun"}));
        set("long", "�����ǳ�����\n");
        set("age", 60);
        set("attitude", "aggressive");
        set("class", "bonze");
        set("str", 27);
        set("int", 28);
        set("con", 27);
        set("dex", 26);        
        set("max_qi", 22500);
        set("max_jing", 21500);
        set("neili", 23000);
        set("max_neili", 23000);
        set("eff_jingli", 32500);
        set("jiali", 50);
        set("level", 20);
        set("combat_exp", 8300000);
        set("shen", -18000);
        set("pubmaster",1);
        set_skill("cuff", 260);
        set_skill("dodge", 260);
        set_skill("parry", 260);
        set_skill("force", 260);
        set_skill("blade", 260);
        set_skill("finger", 260);
        set_skill("shaolin-shenfa", 260);
        set_skill("yijinjing", 280);
        set_skill("jingang-quan", 280);
        set_skill("xiuluo-dao", 260);
        set_skill("huanyin-zhi", 360);
        set_skill("literate", 260);
                
        map_skill("parry", "xiuluo-dao");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("force", "yijinjing");
        map_skill("blade", "xiuluo-dao");
        map_skill("cuff", "jingang-quan");
        map_skill("finger", "huanyin-zhi");
        	prepare_skill("cuff", "jingang-quan");
	prepare_skill("finger", "huanyin-zhi");
        set("chat_chance_combat", 90); 
        set("chat_msg_combat", ({
                (: command("perform finger.huanyin") :),
(: perform_action, "cuff.fumo" :),
	(: perform_action, "cuff.jin" :),
		(: perform_action, "cuff.jingang" :),
			(: perform_action, "cuff.qixing" :),
                (: perform_action, "finger.fuxue" :),
                (: exert_function, "jiuyang" :),
                (: exert_function, "tong" :),
                (: exert_function, "roar" :),		 	
                (: exert_function, "chang" :),		 		
                (: exert_function, "jingang" :),

        }) );
        	create_family("������", 37, "����");
        prepare_skill("finger", "huanyin-zhi");
 	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",3500);
	set_temp("apply/damage",3500);       
        set("master_ob",1);
	setup();
        
        carry_object("/clone/misc/cloth")->wear();
        //carry_object("/clone/weapon/blade")->wield();
}

int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timeb"))      
		who->set_temp("learn_timeb", 0);

	if( !ob->query("money_id") )
		return 0;		


	if(who->query_skill("huanyin-zhi",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("huanyin-zhi",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("huanyin-zhi",1)<100)
				i=ob->value() / 150;
			else
				i=ob->value() / 300;
		}
	}
	who->add_temp("learn_timeb",i);

      message_vision("������$N˵������Ȼ�������ѧ�ҵ��书���Ҿͳ�ȫ��ȫ��ɡ�\n",who);

	return 1;
}

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}

void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
  	
	who->set_temp("book1241",1);
	call_out("leavet",1);
}

void leavet()
{
        object ob = this_object();
 message_vision("$N����������ȥ��\n" NOR,this_object());
        destruct(this_object());
}  