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
        set("str", 200);
        set("int", 128);
        set("con", 127);
        set("dex", 200);        
        set("max_qi", 82500);
        set("max_jing", 81500);
        set("neili", 83000);
        set("max_neili", 83000);
        set("eff_jingli", 82500);
        set("jiali", 50);
        set("level", 20);
        set("combat_exp", 9300000);
        set("shen", -18000);
        set("pubmaster",1);
        set_skill("cuff", 360);
        set_skill("dodge", 360);
        set_skill("parry", 360);
        set_skill("force", 360);
        set_skill("blade", 360);
        set_skill("finger", 360);
        set_skill("shaolin-shenfa", 360);
        set_skill("yijinjing", 380);
        set_skill("jingang-quan", 380);
        set_skill("xiuluo-dao", 360);
        set_skill("huanyin-zhi", 360);
        set_skill("literate", 360);
        set_skill("wuxiang-finger",380);
        set_temp("fanzhen",1);
        set_temp("sl/jiuyang",1);
        set_skill("buddhism",500);
        map_skill("sword", "wuying-jian");        
        map_skill("parry", "jingang-quan");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("force", "yijinjing");
        map_skill("blade", "xiuluo-dao");
        map_skill("cuff", "jingang-quan");
        map_skill("finger", "huanyin-zhi");
        prepare_skill("cuff", "jingang-quan");
	//prepare_skill("finger", "huanyin-zhi");
        set("chat_chance_combat", 90); 
        set("chat_msg_combat", ({
                (: command("perform finger.huanyin") :),
(: perform_action, "cuff.fumo" :),
	(: perform_action, "cuff.jin" :),
		(: perform_action, "cuff.jingang" :),
			(: perform_action, "cuff.qixing" :),
			(: perform_action, "cuff.qixing" :),
			(: perform_action, "cuff.qixing" :),
                (: perform_action, "finger.fuxue" :),
                (: exert_function, "jiuyang" :),
                (: exert_function, "tong" :),
                (: exert_function, "roar" :),		 	
                (: exert_function, "chang" :),		 		
                (: exert_function, "jingang" :),

        }) );
        	create_family("������", 37, "����");
        //prepare_skill("finger", "huanyin-zhi");
 	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
	set_temp("apply/armor",3500);
	set_temp("apply/damage",5500);       
        set("master_ob",1);
	setup();
        
        carry_object("/clone/misc/cloth")->wear();
        //carry_object("/clone/weapon/blade")->wield();
}



void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
  	
  if((int)who->query("jinyong/book12")==7)
{
		i = 2050+random(2000);
		who->set("jinyong/book12",8);
		who->add("combat_exp",i+19000);
		who->add("potential",i*28);
		who->add("mpgx",20);
		who->add("expmax",2);
		tell_object (who,"��Ӯ����"+chinese_number(i+19000)+"�㾭��"+
		           chinese_number(i*28)+"��Ǳ��"+"��ʮ�����ɹ��� ����ɳ����ޣ���\n");
message("channel:chat", HIB"������III����˵"+who->name() + "��������������ǵ���������!"NOR"\n", users());
		who->save();
}
	::die();
}

