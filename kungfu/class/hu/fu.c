// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>;

inherit NPC;
int ask_me();



void create()
{
        set_name("������", ({ "fu kangan", "fu" }));
        set("gender", "����");
        set("nickname", HIR "������˧" NOR);

        set("age", 37);
        set("long", @LONG
���˾���������˧��������
LONG);
        set("attitude", "peaceful");
        set("str", 56);
        set("int", 38);
        set("con", 31);
        set("dex", 10);
    
        set("qi", 26000);
        set("max_qi", 26000);
        set("jing", 26000);
        set("max_jing", 26000);
        set("neili", 26500);
        set("max_neili", 26500);
        set("jiali", 160);
        set("level", 40);
        set("combat_exp", 8000000);
        set("vendetta/authority",1);
        set_skill("force", 290);
        set_skill("lengyue-shengong", 290);
        set_skill("blade", 460);
        set_skill("baisheng-daofa", 460);
        set_skill("hujia-daofa", 290);
        set_skill("zileidao", 290);
        set_skill("dodge", 290);
        set_skill("sixiang-bufa", 290);
        set_skill("parry", 290);
        set_skill("strike", 290);
        set_skill("tianchang-strike", 290);
        set_skill("cuff", 290);
        set_skill("hujia-quan", 290);
        set_skill("throwing", 200);
        set_skill("mantian-xing", 200);
        set_skill("literate", 290);
        set_skill("martial-cognize", 240);

        map_skill("force", "lengyue-shengong");
        map_skill("blade", "zileidao");
        map_skill("dodge", "sixiang-bufa");
        map_skill("parry", "baisheng-daofa");
        map_skill("strike", "tianchang-strike");
        map_skill("cuff", "hujia-quan");
        //map_skill("throwing", "mantian-xing");

        prepare_skill("strike", "tianchang-strike");
        prepare_skill("cuff",   "hujia-quan");

        //create_family("�廢��", 1, "����");
        set("inquiry",([
                "�����˴��" : (: ask_me :),
        ]));


        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "blade.huanying" :),
                 (: perform_action, "blade.posui" :),
                (: perform_action, "blade.tulong" :),                 	
                (: perform_action, "cuff.kuai" :),
                (: perform_action, "strike.huang" :),
                (: perform_action, "dodge.fei" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));
	set_temp("apply/attack",100);
	set_temp("apply/defense",100);
	set_temp("apply/armor",800);
	set_temp("apply/damage",800);        

        //set("master_ob",5);
	setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void die()
{
	object ob,corpse;
	ob=this_object();
	message_vision("$N����һ�� ��ʧ����Զ����\n",ob);
	destruct(ob);
	return;
}

int ask_me()
{
	int i;
        object fang ;
	object who = this_player();
	object where = environment(who);
	
        if( who->is_fighting())
        {
		message_vision("$N��$n˵���� �������˵�ɣ�\n",this_object(),who);
		return 1;	
	}
fang = present("wudang gaoshou",where);
	if(fang)
	{
		fang->kill_ob(who);
		message_vision("$N��$n˵���� ��λ"+ RANK_D->query_respect(who) +"���ȴ���䵱�����Ĵ�ʦ��˵�ɡ�\n",this_object(),who);
		return 1;
	}

 fang = present("shaolin gaoshou",where);
	if(fang)
	{
		fang->kill_ob(who);
		message_vision("$N��$n˵���� ��λ"+ RANK_D->query_respect(who) +"���ȴ�����������Ĵ�ʦ��˵�ɡ�\n",this_object(),who);
		return 1;
	}
 fang = present("feng tiannan",where);
	if(fang)
	{
		fang->kill_ob(who);
		message_vision("$N��$n˵���� ��λ"+ RANK_D->query_respect(who) +"�㾡Ȼ....���ˣ�����ƴ��! \n",this_object(),who);
		return 1;
	}

	
		  	if(((int)who->query("jinyong/book1")!=2))
	{
		message_vision("$N��$n˵���� ����˵ʲô����\n",this_object(),who);
		return 1;	
	}
	
	  	if(((int)who->query("jinyong/book1")>=3))
	{
		message_vision("$N��$n˵���� ����˵ʲô����\n",this_object(),who);
		return 1;	
	}
	command("sight " + who->query("id"));
	message_vision("$N��$n˵���� ���������¶�ˡ�\n",this_object(),who);
	message_vision("$N��$n˵���� ����,���ˡ���֪�����ũ���ܲ��ܵ��֡�\n",this_object(),who);


	
	i = 200+random(800);
	who->set("jinyong/book1",3);
	who->add("combat_exp",i+9880);
	who->add("potential",i*10);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"��Ӯ����"+chinese_number(i+9880)+"�㾭��"+
	           chinese_number(i*10)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
	who->save();
	this_object()->kill_ob(who);
	return 1;
}