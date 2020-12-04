//long.c

#include <ansi.h>

inherit NPC;

int ask_zhou();
void create()
{
        set_name("��Ԫ��", ({ "huo yunlong", "yunlong" }));
set("long", "���Ǹ�������ԭ����ʦ������ʮ������û��ȥ��������������ʲô������\n" );
        set("title", "��ԭ��ʦ��ͷ");
        set("gender", "����");
        set("age", 75);
 
        set("shen_type",1);
        set("attitude", "peaceful");

        set("str", 60);
        set("int", 69);
        set("con", 60);
        set("dex", 68);

        set("qi", 53900);
        set("max_qi", 53900);
        set("jing", 53900);
        set("max_jing", 53900);
        set("neili", 61500);
        set("max_neili", 61500);
        set("jiali", 50);

        set("combat_exp", 9500000);
        set("score", 200000);
        set_skill("force", 370);
        set_skill("unarmed", 300);
        set_skill("dodge", 350);
        set_skill("parry", 350);
        set_skill("hand",370);
        set_skill("staff", 370);
        set_skill("taixuan-gong", 350);
set_skill("huanhe-dao", 350);
set_skill("sata-shenfa", 350);
set_skill("sumi-jian", 380);
set_skill("wuyu-quan", 550);
set_skill("xiuli-qiankun", 350);
set_skill("strike", 250);
set_skill("cuff", 250);
set_skill("unarmed", 250);
set_skill("blade", 350);
set_skill("sword", 350);
set_skill("club", 320);
set_skill("bawang-qiang", 320);
map_skill("sword", "sumi-jian");
//map_skill("blade", "huanhe-dao");
map_skill("strike", "xiuli-qiankun");
map_skill("cuff", "wuyu-quan");
      map_skill("force", "taixuan-gong");
        map_skill("dodge", "sata-shenfa");
        map_skill("parry", "taixuan-gong");
        map_skill("unarmed", "taixuan-gong");
set_skill("club", 320);
set_skill("bawang-qiang", 320);

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
        carry_object("/clone/weapon/gangjian")->wield();
        add_money("gold",5);
}



void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	
  	if (!who) return;
  	if(((int)who->query("jinyong/book6")>=4))
	{
//::die();	
	}
        else if(who) {
        	message_vision("$N˵������ҿ� ������ ......��\n" NOR,this_object());
		i = 200+random(5000);
		who->set("jinyong/book6",4);
		who->add("combat_exp",i+15000);
		who->add("potential",i*15);
		who->add("mpgx",10);
		who->add("expmax",2);
		tell_object (who,"��Ӯ����"+chinese_number(i+15000)+"�㾭��"+
		           chinese_number(i*15)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
		who->save();
        }
	::die();
}
