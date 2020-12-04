 // half_god.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//  
inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int give_reward(object who,mapping quest);
int time_period(int timep, object me);
int wait_period(int timep, object me);
string sysmsg;
void create() {
        set_name(HIY"�������"NOR, ({ "tianji", "Tian ji", "Tian" }) );
        set("gender", "����");
        set("age", 99);
        set("long", "�������������ף��׷�ͯ�ա��ڱ�������������һ��
�����Ϲ٣�С��֮�ϣ�����������а�����¶��ɰ�����������������ͽ�����ޣ�������\n");
        set("attitude", "peaceful");
        set("skill_public",1);
        set("str", 26000);
        set("cor", 30);
        set("int", 24);
        set("cps", 30);
        set("chat_chance", 1);
        set("chat_msg", ({ "������������̳��˼��ڣ�������\n" }));
        set("neili", 80000);
        set("max_jing", 80000);
        set("max_sen", 80000);
        set("max_neili", 80000);
        set("eff_qi", 80000);
        set("max_qi", 80000);
        set("force_factor", 1000);
    set("combat_exp", 100000000);
        set("score", 200000);
        set_skill("unarmed", 320);
        set("pubmaster",1);
        set_skill("force", 300);
        set_skill("iron-cloth", 600);
        set_skill("yiqiforce", 630);
        set_skill("dagger",600);
        set_temp("apply/attack",300);
        set_temp("apply/damage",30000);
   map_skill("iron-cloth", "yiqiforce");
        map_skill("force", "yiqiforce");
        map_skill("unarmed", "yiqiforce"); 

        create_family("��ң��", 1, "��ʦ");
        set("title", "����Ұ��");
        setup(); 
        carry_object(__DIR__"obj/jade-cloth")->wear();
        carry_object(__DIR__"obj/hanyan");
} 
int accept_fight(object me) {
                command("say �����ɹ󣡲�Ҫ��Ѱ��·��");
                return 0;
} 
void attempt_apprentice(object me) {
        switch(random(4)) {
                case 0:
                        message_vision("$N��$nЦ�ʵ���ʲô���Ľ���\n", this_object(),me);
                        break;
                case 1:
                   message_vision("$N��$nЦ�ʵ���ʲô�ǣ��в������Ҳ�������һ�������ȶ�����\n", this_object(),me); 
                        break;
                case 2:
                        message_vision("$N��$nЦ�ʵ��������Σ����Σ���ʲô��\n", this_object(),me);             
                        break;
                case 3:
                        message_vision("$N��$nЦ�ʵ�����ѧ����߾�����ʲô��\n", this_object(),me);
                        break;
        }
} 
void unconcious()
{
        int gin,kee,sen;
        gin =(int)query("max_jing");
        kee =(int)query("max_qi");
        sen =(int)query("max_sen");
        set("eff_qi",kee);set("qi",kee);
        set("eff_jing",gin);set("jing",gin);
        set("eff_sen",sen);set("sen",sen);
        return ; 
} 
void die()
{
        int gin,kee,sen;
        gin =(int)query("max_jing");
        kee =(int)query("max_qi");
        //sen =(int)query("max_sen");
        set("eff_qi",kee);set("qi",kee);
        set("eff_jing",gin);set("jing",gin);
        //set("eff_sen",sen);set("sen",sen);
        return ; 
}   

void punish_betray(object ob)
{
        if( ( ob->query("once_xman")==1) && ( (ob->query("class"))!= "shaolin"))
          {      
                tell_object(ob, YEL"\n������˳�̾:��������֮ͽ������\n"NOR);                  
                message("vision", YEL"������˶�"+ ob->name() +"̾������"+ ob->name() + "�� ��ʦ���Ҵ��������Ż������㲻���ˣ�\n"NOR, environment(ob), ob);
                tell_object(ob, HIW"�������һȭ�������������ϣ�\n"NOR);              
                message("vision", HIW"�������һȭ����"+ ob->name() +"��������ϣ�\n"NOR, environment(ob), ob);
                tell_object(ob, HIR"��ֻ�����ε�ת,ҡҡ�λεص�����ȥ----�ڲ�����ѽ!\n"NOR);
                ob->set("title",HIC"������ͽ"NOR);
                ob->die();
          }
}  

int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timeb"))      
		who->set_temp("learn_timeb", 0);

	if( !ob->query("money_id") )
		return 0;		


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

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}
