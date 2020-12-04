#include <ansi.h>
inherit NPC;


int ask_me();
void create()
{
        set_name("������", ({ "cheng lingsu", "cheng" }));
        set("gender", "Ů��");
        set("age", 24);
        set("long", @long
������ȥ˫ü��������֪����ʲô���£�������òƽƽ���������ڡ�
�����С�����Ŵֲ�������
long);
        set("title", HIG"ҩ���ȴ���"NOR); 
        set("attitude", "peaceful");
        set("str", 22);
        set("int", 35);
        set("con", 31);
        set("dex", 27);
        set("per", 25);
        set("chat_chance", 10);
        set("chat_msg", ({
                "�����ذ�����̾�˿�����\n",
        }));

        set("qi", 15900);
        set("max_qi", 15900);
        set("jing", 9900);
        set("max_jing", 9900);
        set("neili", 9900);
        set("max_neili", 9900);
        //set("jiali", 40);
        set("combat_exp", 900000);
     
        set_skill("force", 150);
        set_skill("poison", 370);
        //set_skill("dispel-poison", 270);
	set_skill("miaoshouhuichun", 370);
	//set_skill("yaowang-miaoshu", 270);

set_skill("cuff", 300);
set_skill("cuff", 300);
set_skill("lingshe-quan", 180);
set_skill("zhaosheshu", 180);
set_skill("yangsheshu", 180);
	set_skill("sword", 280);
	set_skill("force", 250);
	set_skill("unarmed", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("strike",220);
	set_skill("hand",320);
	
	set_skill("staff", 250);
	set_skill("hamagong", 180);
	set_skill("chanchu-bufa", 180);
	set_skill("shexing-diaoshou", 180);
	set_skill("lingshe-zhangfa", 180);
	set_skill("hamashengong", 180);
	set_skill("xiyu-tiezheng", 180);
set_skill("shentuo-zhang", 282);
set_skill("martial-cognize", 180);

	map_skill("strike", "hamagong");
	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("unarmed", "shexing-diaoshou");
	map_skill("hand", "xiyu-tiezheng");
	map_skill("parry", "hamagong");
	map_skill("staff", "lingshe-zhangfa");
	prepare_skill("strike", "hamagong");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({

                (: perform_action, "staff.saoluoye" :),
                (: perform_action, "staff.shewu" :),
                (: perform_action, "staff.shoot" :),
                (: perform_action, "staff.saoluoye" :),
         
             
        }) );
        set("inquiry",([
                "���ĺ���" : (: ask_me :), 
                "���":     "��...��...\n",
                "Ԭ����":   "��...��������ʲô��\n"
        ]));

        setup();
        	carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/clone/misc/cloth")->wear();
}


int ask_me()
{
	int i;
        object fang;
	object who = this_player();
	object where = environment(who);
	
		  	if(((int)who->query("jinyong/book1")!=4))
	{
		message_vision("$N��$n˵���� ����˵ʲô����\n",this_object(),who);
		return 1;	
	}
	
	  	if(((int)who->query("jinyong/book1")>=5))
	{
		message_vision("$N��$n˵���� ����˵ʲô����\n",this_object(),who);
		return 1;	
	}
	
        if( who->is_fighting())
        {
		message_vision("$N��$n˵���� �������˵�ɣ�\n",this_object(),who);
		return 1;	
	}
	
	
        fang = present("jiang tieshan",where);
	if(fang)
	{
		who->start_busy(3);
		message_vision("$N��$n˵���� ��λ"+ RANK_D->query_respect(who) +"�Ȱ���ս���Ҵ�ʦ�ְɡ�\n",this_object(),who);
		return 1;
	}

        fang = present("xue que",where);
	if(fang)
	{
		who->start_busy(3);
		message_vision("$N��$n˵���� ��λ"+ RANK_D->query_respect(who) +"�Ȱ���ս���Ҷ�ʦ��ɡ�\n",this_object(),who);
		return 1;
	}


 
		  	if((!(int)who->query_temp("killyao2")))
	{
		message_vision("$N��$n˵���� ����ҶԸ����Ҷ�ʦ������?\n",this_object(),who);
		return 1;	
	}
	
		  	if((!(int)who->query_temp("killyao1")))
	{
		message_vision("$N��$n˵���� ����ҶԸ����Ҵ�ʦ������?\n",this_object(),who);
		return 1;	
	}


	command("bow " + who->query("id"));
	message_vision("$N��$n˵���� ��л ������ȡ�\n",this_object(),who);
	message_vision("$N��$n˵���� �����ȥ��������ⶾ��\n",this_object(),who);


	
	i = 400+random(800);
	who->set("jinyong/book1",5);
	who->add("combat_exp",i+10880);
	who->add("potential",i*12);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"��Ӯ����"+chinese_number(i+10880)+"�㾭��"+
	           chinese_number(i*12)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
	who->save();
	call_out("destroying", 0); 
	//this_object()->kill_ob(who);
	return 1;
}

void destroying()
{   
object ob=this_object();
   message_vision(HIM"$N˵�������������ʧ������......\n"NOR,ob);
destruct(this_object());
   return;      
}