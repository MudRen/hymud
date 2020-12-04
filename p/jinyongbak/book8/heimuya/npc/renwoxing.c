// renwoxing.c

#include <ansi.h>

inherit NPC;
int ask_me();

void create()
{
	set_name("������", ({ "ren woxing", "ren","woxing" }));
	set("title", BLU "������̽���"NOR );
	set("long", "ֻ����һ�ų��������ף���ɫѩ�ף����ް��Ѫɫ��üĿ���㣬
������ߣ�һͷ�ڷ���������һϮ������\n");
	set("gender", "����");
	set("class", "scholar");
	set("age", 55);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 70);
	set("per", 27);
	set("int", 70);
	set("con", 70);
	set("dex", 70);
       //create_family("�������",1,"����");	
	set("max_qi", 20000);
	set("max_jing", 20000);
	set("neili", 30000);
	set("max_neili", 30000);
	set("jiali", 400);
	set("combat_exp", 9000000);
	set("score", 390000);

	set_skill("literate", 180);
	set_skill("force", 390);
	set_skill("dodge", 390);
	set_skill("unarmed", 390);
	set_skill("parry", 390);
	set_skill("sword", 390);
	set_skill("changquan", 390);
	set_skill("kuihua-xinfa", 390);
	set_skill("lingxu-bu", 390);
	set_skill("damo-jian", 390);
	set_skill("taiji-jian", 390);
	set_skill("huifeng-jian", 390);
	set_skill("taishan-sword", 390);
	set_skill("hengshan-jian", 390);
	set_skill("hengshan-sword", 390);
	set_skill("huashan-sword", 390);


	set_skill("songshan-jian", 390);
  set_skill("luoyan-jian",500);
  set_skill("shiba-pan",500);
  set_skill("liuhe-dao",500);
  set_skill("hengshan-jian",500);
  
  
  
	map_skill("dodge", "lingxu-bu");
	map_skill("force", "kuihua-xinfa");
	map_skill("unarmed", "changquan");
	map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");
          set_skill("sword", 390);
          set_skill("parry", 390);
        set_skill("literate",200);
          set_skill("dodge", 390);
          set_skill("unarmed", 390);
          set_skill("whip", 390);
          set_skill("force", 390);
         set_skill("tmzhang", 390);
        set_skill("staff", 390);
         set_skill("tmjian", 390);
         set_skill("tmdao", 390);
         set_skill("pmshenfa", 390);
          set_skill("strike",500);
          set_skill("cuff",500);
         set_skill("blade", 390);
         set_skill("tmdafa", 390);
set_skill("tmquan", 390);
        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
        map_skill("strike", "tmzhang");
        map_skill("cuff", "tmquan");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.diansha" :),
                (: perform_action, "sword.xuan" :),
                (: perform_action, "sword.tmbiao" :),
                	(: perform_action, "sword.jianshen" :),
                		(: perform_action, "sword.moshen" :),
                (: perform_action, "blade.moxiao" :),
                (: perform_action, "blade.tiandirenmo" :),
                (: perform_action, "blade.xuan" :),                	
                (: perform_action, "blade.yueshen" :),                	
                (: perform_action, "strike.huashen" :),                
                (: perform_action, "strike.zhen" :),                
                (: perform_action, "strike.tmduan" :),                
                (: perform_action, "cuff.tianmo" :),                
                (: perform_action, "cuff.dimo" :),                
                (: perform_action, "cuff.renmo" :),

        }) );

	set("inquiry", ([
		"����"     : (: ask_me() :),
	]));

	prepare_skill("cuff","tmquan");
	
	prepare_skill("strike","tmzhang");

        set_temp("apply/defense", 200);
        set_temp("apply/armor", 390);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);

 	setup();
	carry_object("/d/wudang/obj/bluecloth")->wear();
if (random(2)==0) 
{
	carry_object("/clone/weapon/changjian")->wield();
}
else
{
carry_object("/clone/weapon/gangdao")->wield();
}
}

int ask_me()
{
	int i;
	object ob = this_object();
	object who = this_player();
	if(objectp(present("dongfang bubai", environment(who))))
	{
		message_vision("$N��$n˵���� ��λ"+ RANK_D->query_respect(who) +"�Ȱ��ҰѶ��������ⲻ�в�Ů������ɱ�ˣ�\n",this_object(),who);
		return 1;
	}	
	
  	if(((int)who->query("jinyong/book8")>=9))
	{
		message_vision("$N��$n˵���� ����˵ʲô����\n",this_object(),who);
		return 1;	
	}
	
	message_vision(HIC "$N˵�� ���������������ܣ���Ҳ�н��죡\n",this_object());
	message_vision(HIC "$N˵�� �ӽ��Ժ��Ҳ���������̵Ľ��������ȵ�һ������������ǿ����������ڧʱ���������������ɣ�\n",this_object(),who);
	i = random(3000);
	who->set("jinyong/book8",9);
	who->add("combat_exp",i+30000);
	who->add("potential",i*24);
	who->add("mpgx",10);
	who->add("expmax",2);
	//command("chat "+this_player()->query("name")+"��ɫ���ˣ������Ƕ�ԡ�");
	tell_object (who,"��Ӯ����"+chinese_number(i+30000)+"�㾭��"+
	           chinese_number(i*24)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
	who->save();

	return 1;
}