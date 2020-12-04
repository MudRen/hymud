// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;

#include <ansi.h>

int wieldblade();
void create()
{
    set_name("������", ({ "killer", "xiao qiuyu"}) );
    set("title",  HIC"�ϳ�����"NOR);
    set("gender", "����" );
    set("class","shenshui");
    set("reward_npc", 1);
    set("difficulty", 10);
    
    set("age", 35);
    set("per", 15);
    set("agi", 300);
    set("str", 50);
    set("int",30);
    set("ill_boss",5);
    //set("attitude","friendly");
    set("max_neili", 3000);
    set("neili", 3000);
    set("atman", 5400);
    set("max_atman", 5400); 
    set("mana", 5000);
    set("max_mana", 5000);
    
    set("long", "
һ������˹�ģ�������������������һ�Űװ׾��������ϣ����Ǵ���΢Ц��\n");

    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: perform_action, "dodge.lianhuanbu" :),
//                (: wieldblade  :),
        (: perform_action, "sword.shuanglengcanxia" :),
             }) );
    set("combat_exp", 5000000);
    set("chat_chance", 1);
    set("chat_msg", ({
                "�����곤̾��������������ɷ�ˣ�����ÿ��ɱ��ʱ������������Ҫ����ġ���\n",
            }) ); 

 set("qi", 39800);
	set("max_qi", 39800);
	set("jing", 38600);
	set("max_jing", 38600);
	set("neili", 54400);
	set("max_neili", 54400);
	set("jiali", 200);

	set("combat_exp", 15050000);
	set("score", 200000);

	set("fengset",1);
	set_skill("cuff", 250);
	set_skill("force", 280);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 380);
	set_skill("strike", 250);
	set_skill("kuangfeng-jian", 380);
	set_skill("zixia-shengong", 380);
	set_skill("zixia-shengong", 380);
	set_skill("ziyunyin", 380);
	set_skill("zhengqijue", 380);
	set_skill("fanliangyi-dao", 380);
	set_skill("huashan-sword", 380);
	set_skill("hunyuan-zhang", 380);
	set_skill("lonely-sword", 380);
	set_skill("feiyan-huixiang",380);
	set_skill("literate", 200);
        set_skill("zhengqijue",380);
        set_skill("hunyuan-zhang", 380);
        set_skill("poyu-quan", 380);        
        set_skill("huashan-neigong", 380);        
        set_skill("chongling-jian", 380);
        set("fengset",1);
	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");

	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.wanjian" :),
		(: perform_action, "sword.jiushi" :),
		(: perform_action, "sword.pozhao" :),
		(: perform_action, "sword.poqi" :),
		(: perform_action, "sword.pozhang" :),
		(: perform_action, "sword.pojian" :),
		(: perform_action, "sword.podao" :),
		(: perform_action, "sword.zongjue" :),
	}) ); 
    set_temp("apply/dodge", 100);
        set_temp("apply/parry", 100); 

   setup();
   carry_object("/clone/weapon/gangjian")->wield();
   carry_object(__DIR__"obj/raincoat")->wear();
 
} 
