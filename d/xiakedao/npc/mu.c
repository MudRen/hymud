//mu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_zhou();

void create()
{
        set_name("ľ����", ({ "mu", "wood" }));
        set("long", "������������֮ɫ������͵��������ųơ�Ҷ����¶����\n"
                   +"ֻ��������ϡϡ���䣬أ�Ժڶ���٣���һ����ȴ�������ơ�\n"
                   +"����������ʵ����͡�\n"
                   );
        set("title", "���͵���");
        set("gender", "����");
        set("age", 75);
        set("nickname", HIB "Ҷ����¶" NOR);
        set("shen_type",1);
        set("attitude", "peaceful");

        set("str", 60);
        set("int", 69);
        set("con", 60);
        set("dex", 68);

        set("qi", 33900);
        set("max_qi", 33900);
        set("jing", 33900);
        set("max_jing", 33900);
        set("neili", 61500);
        set("max_neili", 61500);
        set("jiali", 50);

        set("combat_exp", 8500000);
        set("score", 200000);
        set_skill("force", 370);
        set_skill("unarmed", 300);
        set_skill("dodge", 350);
        set_skill("parry", 350);
        set_skill("hand",370);
        set_skill("staff", 370);
        set_skill("taixuan-gong", 350);

set_skill("huanhe-dao", 380);
set_skill("sata-shenfa", 350);
set_skill("sumi-jian", 350);
set_skill("wuyu-quan", 350);
set_skill("xiuli-qiankun", 350);
set_skill("strike", 250);
set_skill("cuff", 250);
set_skill("unarmed", 250);
set_skill("blade", 350);
set_skill("sword", 350);
set_skill("club", 380);
set_skill("bawang-qiang", 380);
//map_skill("sword", "sumi-jian");
map_skill("blade", "huanhe-dao");
map_skill("strike", "xiuli-qiankun");
map_skill("cuff", "wuyu-quan");
      map_skill("force", "taixuan-gong");
        map_skill("dodge", "sata-shenfa");
        map_skill("parry", "taixuan-gong");
        map_skill("unarmed", "taixuan-gong");
    	prepare_skill("strike", "xiuli-qiankun");
	prepare_skill("cuff", "wuyu-quan");

        
	set("chat_chance_combat", 90);
       set("chat_msg_combat", ({
                (: perform_action, "blade.huan" :),
                	(: perform_action, "blade.kuang" :),
                		(: perform_action, "blade.leitingpili" :),
                			(: perform_action, "blade.shiwanshenmo" :),
                				(: perform_action, "blade.tiandirenmo" :),
                					(: perform_action, "blade.xueyu" :),
                						(: perform_action, "blade.baoxue" :),
                						(: perform_action, "blade.baoxue" :),                							
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
        create_family("���͵�",1, "����");
        set("chat_chance", 3);
        set("chat_msg", ({
            "ľ������Ȼһ���Դ���˵����������Ǻö����ۣ�\n",
            "ľ����˵������ô��ô���Ӣ��Ҳ��������̫�����ء�\n",
        }) );
        set("inquiry", ([
            "������" : (: ask_zhou :),
            "���͵�" :  "\n��������Һ����ֵ������з��ֵġ�\n",
        ]));
        setup();
        carry_object(__DIR__"longdao")->wield();
        add_money("gold",3);
}

void attempt_apprentice(object ob)
{
  if((int)ob->query_skill("taixuan-gong",1)<100)
        {
          message_vision("ľ��������$N��ͷ��΢΢ҡ��ҡͷ��\n",ob);
	return ;
         }

        message_vision("ľ��������$N��ͷ��΢΢���˵�ͷ��\n",ob);
        command("recruit " + ob->query("id"));
        return;
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
        if(ob->query_skill("literate",1)>50)
              say ("ľ����������ҡ��ҡͷ��˵��������̫�ࡣ\n");
        return;
}

int ask_zhou()
{
        say(
"\nľ��������˵�����Ǳ������еĶ���������Ҫ��һζ'�ϳ����Ǹ��Ĳ�'���ɣ�\n"
"Ҫ������Ч�������������ֲ�ÿʮ��ſ�һ�λ������������������\n"
"һ���˺��ѵõ��ģ�С�ֵ���Ҫ��Ҫ�����Ե���ˣ�\n");
        return 1;
}

int accept_object(object who, object ob)
{
        object obn;

        if (  ob->query("id") != "shane bu" && ob->query("id") != "fuxin cao")
        {
                message_vision("\nľ����ҡͷ�����ⲻ������Ҫ��ѽ��\n",who);
                return 0;
        }
        if ( ob->query("id") == "shane bu" )
        {
                if (random((int)who->query("kar")) <=25 )
                {
                        message_vision("ľ����ҡͷ�����ҿ�С�ֵܽ����ڴ���Ե��\n",who);
                        return 1;
                }
                else
                {
                        remove_call_out("destroy");
                        call_out("destroy", 1, who, ob);

                        if(query_temp("cao"))
                        {
                                message_vision("\nľ�����������Ʒ��񲾣���ϲ������ϲ��λС�ֵ���!\n",who);
                                obn=new("/d/xiakedao/obj/zhou");
                                obn->move(who);
                                delete_temp("bu");
                                delete_temp("cao");
                                return 1;
                        }
                        else if(query_temp("bu"))
                        {
                                message_vision("\nľ�����������Ʒ��񲾣���$Nҡͷ�������Ʒ��������ˡ�\n",who);
                                return 0;
                        }
                        else
                        {
                                message("vision","ľ�����������Ʒ��񲾣���ϲ��������ֻ��Ĳ��ˡ�\n",environment(who));
                                set_temp("bu",1);
                                return 1;
                        }
                }
        }
        if ( ob->query("id") == "fuxin cao")
        {
                if (random((int)who->query("kar")) <=25 )
                {
                        message_vision("ľ����ҡͷ�����ҿ�С�ֵܽ����ڴ���Ե��\n",who);
                        return 1;
                }
                else
                {
                        remove_call_out("destroy");
                        call_out("destroy", 1, who, ob);

                        if(query_temp("bu"))
                        {
                                message_vision("\nľ�������Ǹ��Ĳݣ���ϲ������ϲ��λС�ֵ���!\n",who);
                                obn=new("/d/xiakedao/obj/zhou");
                                obn->move(who);
                                delete_temp("cao");
                                delete_temp("bu");
                                return 1;
                        }
                        else if(query_temp("cao"))
                        {
                                message_vision("\nľ�������Ǹ��Ĳݣ���$Nҡͷ�������Ĳ����Ѿ����ˡ�\n",who);
                                return 0;
                        }
                        else
                        {
                                message("vision","ľ�����������Ĳݣ���ϲ��������ֻ�����Ʒ����ˡ�\n",environment(who));
                                set_temp("cao",1);
                                return 1;
                        }
                }
        }
        return 1;
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


who->set_temp("book1152",1);
		
		

		
		
	::die();

}  