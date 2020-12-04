// yuanziyi.c Ԭ����

#include <command.h>
#include <ansi.h>

inherit NPC;
int ask_me();
void create()
{
        set_name("Ԭ����", ({ "yuan ziyi","ziyi","yuan"}));
        set("long",
                "���Ƕ�����һ�����ݼ��ߵ�����Ĺ���ͽ�ܡ�\n"
                "һ�����������ס�����һ�������ѡ�\n"
                "��һ·��ȥ��ʦ�����˺ü������š�\n");
        set("gender", "Ů��");
        set("age", 18);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("title", RED"�żҰ�����"HIG"������"NOR);
        set("class", "bonze");

        set("inquiry",([
                "���"    : "�Һͺ����Ͼ�û��Ե�ݵġ�",
                "����"    : "�Ҿ�ϲ�������ţ�",
                "�����˴��" : (: ask_me :),
        ]));
        set("str", 30);
        set("per", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);






	set("max_qi", 8000);
	set("max_jing", 8000);
	set("neili", 8000);
	set("max_neili", 8000);
	set("jiali",100);
	set("jingli", 1500);
	set("max_jingli", 1500);
	set("combat_exp", 3000000);
	set("score", 1000);
	set("book_count", 1);
	set("yao_count", 1);
	
	set_skill("unarmed", 200);
	set_skill("sword", 300);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 300);
	set_skill("strike", 200);
	set_skill("hand", 200);
	set_skill("buddhism", 350);
	set_skill("medicine", 280);
	set_skill("goplaying", 280);
	set_skill("baiyun-xinfa",380);	
	set_skill("hengshan-jian", 280);
	set_skill("chuanyun-shou",280);
	set_skill("tianchang-zhang",280); 
	set_skill("whip",180); 
	set_skill("rousi-whip",180); 
	set_skill("canxin-jian",288); 
	set_skill("lingxu-bu", 280);
	set_skill("literate", 150);
	
	map_skill("force","baiyun-xinfa");
	map_skill("sword", "canxin-jian");
	map_skill("strike","tianchang-zhang");
	map_skill("hand","chuanyun-shou");
	map_skill("parry", "canxin-jian");
	map_skill("dodge", "lingxu-bu");

	prepare_skill("hand", "chuanyun-shou");
	prepare_skill("strike", "tianchang-zhang");
		  set_temp("apply/armor", 200);
		  set_temp("apply/damage", 200);

       set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
(: exert_function, "shield" :),
(: exert_function, "powerup" :),				
		(: perform_action, "sword.riluo" :),
		(: perform_action, "sword.shenfeng" :),	
		(: perform_action, "sword.wanjian" :),
		(: perform_action, "sword.xunlei" :),	
	(: perform_action, "dodge.lingxu" :),			
		(: command("unwield changjian") :),
		(: command("wield changjian") :),
		(: perform_action, "hand.break" :),
		(: perform_action, "strike.diezhang" :),
	}));
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/emei/obj/ycloth.c")->wear();
         carry_object(__DIR__"obj/lingpai.c");
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{       
	if(file_name(environment())=="/d/henshan/chating" && !ob->query("jinyong/book1"))
	{
		command("say ��������������Ϣ�����������");
		command("kick "+ob->query("id"));
		ob->move("/d/henshan/hsroad6");
		return;
	}
}

int ask_me()
{
	int i;

	object who = this_player();
	object where = environment(who);
	

object fang = present("feng tiannan",where);
	if(fang)
	{
		message_vision("$N��$n˵���� ��λ"+ RANK_D->query_respect(who) +"�����ȴ�����ǰ��λ�ɣ�\n",this_object(),who);
		return 1;
	}
	
	
		  	if(((int)who->query("jinyong/book1")!=1))
	{
		message_vision("$N��$n˵���� ����˵ʲô����\n",this_object(),who);
		return 1;	
	}	
	
	  	if(((int)who->query("jinyong/book1")>=2))
	{
		message_vision("$N��$n˵���� ����˵ʲô����\n",this_object(),who);
		return 1;	
	}
	command("bow " + who->query("id"));
	message_vision("$N��$n˵���� лл��������֮����\n",this_object(),who);
	message_vision("$N��$n˵���� �������������������˴��ض��о�����ı��\n",this_object(),who);


	
	i = 100+random(800);
	who->set("jinyong/book1",2);
	who->add("combat_exp",i+8880);
	who->add("potential",i*9);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"��Ӯ����"+chinese_number(i+8880)+"�㾭��"+
	           chinese_number(i*9)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
	who->save();
	//call_out("destroying", 0);                       
	return 1;
}

