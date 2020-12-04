 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("������", ({ "master yin", "master","yin" }) );
    set("long",
        "���Ƴ�����ߵĹ٣����������ϵ�Ȩ��\n");
    set("nickname", RED"һƷ�ղ�"NOR);
    set("attitude", "heroism");
        set("chat_chance", 1);
        set("chat_msg", ({
                "�������������ϵ���͸��ҵ��з����������ˡ�����\n",
                "������ҡҡͷ�������������ˣ�û�������ѧ��������\n",
        }) );
    // Make this before create_family will prevent generation in title
    set("rank_nogen",1); 
    create_family("��͢",6,"��Ա");
    set("student_title","��Ա");
    set("ranks",({ "��Ʒ֥���","��Ʒ��","��Ʒ��","��Ʒ��","��Ʒ��",
                       "��Ʒ��","һƷ��","�ղ��","����ͳ��",
                       "������ͳ��","��Զ����","�����󽫾�" }));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 }));    
    
    set("vendetta_mark", "authority");
    set("str", 27);
    set("cor", 26);
    set("cps", 25);
    set("agi",25);
    set("int",30);
    set("max_qi",37000);
    set("max_jing",35000);
    set("max_sen",5000);
    set("pubmaster",1);
        set("age",55);
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.yuhuan" :),
            }) );
    set("combat_exp", 90000000);
    set_temp("apply/damage",500);
    set_skill("unarmed", 220);
    set_skill("sword",100);
    set_skill("force",80);
    set_skill("parry", 120);
    set_skill("dodge", 90);
    set_skill("changquan",500);
    set_skill("feixian-steps",260);
    set_skill("feixian-sword",280);
    set_skill("jingyiforce",550);
    set_skill("move", 100);
    set_skill("literate",90);
    set_skill("leadership",500);
    set_skill("strategy",500);
    map_skill("unarmed","changquan");
    map_skill("dodge","feixian-steps");
    map_skill("force","jingyiforce");
    map_skill("sword","feixian-sword"); 
    
    setup();
    if(random(2)) set("env/no_teach",1);
    carry_object(__DIR__"obj/guanfu")->wear();
} 

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}

int accept_object(object who, object ob)
{
	
		int i;

	if (!(int)who->query_temp("learn_timeb"))      
		who->set_temp("learn_timeb", 0);


	if( ob->query("money_id") )
{
	if(who->query_skill("unarmed",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("unarmed",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("unarmed",1)<100)
				i=ob->value() / 100;
			else
				i=ob->value() / 100;
		}
	}
	who->add_temp("learn_timeb",i);
command("say ��Ȼ�������ѧ�ҵ��书���Ҿͳ�ȫ��ȫ��ɡ�");
	return 1;
}	
        if( ob->query("shangfang") ){
                this_object()->delete("env/no_teach");
        if(who->query_temp("marks/sword_gotit")) {
        //give reward
        command("nod");
        command("say ������ǰ�����һ����æ���Ǹ������и����ε��ˡ�\n");
        command("say ���ٰ��Ҳ����˭ɱ�˵��������䵱�ɵ������ţ�\n");
         if(!who->query("m_success/�з�����")) {
                who->set("m_success/�з�����",1);
                who->add("score",1000);
         }
        } else {
        //punish
        command("ah");
        command("say �󵨣�����͵�Ϸ�ı���\n");
        kill_ob(who);
        }
        return 1;
        }
        return 0;
}
