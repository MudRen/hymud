//guan1.c.��˼Ժ��Ա
//date:1997.8.27
//by dan      

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;    

string ask_for_bi();

void create()
{
    set_name(RED"��Ա"NOR, ({ "guanyuan" }) );
    set("title","������˼Ժ");
    set("gender", "����" );
    set("combat_exp", 100000);
    set("max_qi", 400);
    set("max_sen", 300);
     set_skill("force", 180+random(180));

        set_skill("unarmed", 180+random(180));
        set_skill("blade", 180+random(180));
        set_skill("parry", 180+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-blade", 180+random(180));
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
        }) );

    set("attitude", "friendly");
    set("env/attack", 78);

    set("inquiry", ([
                "�����" : (: ask_for_bi :),            
    ]) );

	set("vendor_goods", ({
		__DIR__"obj/jinxiangquan",
		__DIR__"obj/zhuguan",
		__DIR__"obj/yin_zanz",
		__DIR__"obj/yu_zhuoz",
	}));
    set("talk_limit/combat_exp",10000); 
    set_temp("talk_npc_number", 10);
    set("talk_msg",({
"�����԰��ȼ�������˵��һ�����Ѿƺܺã���ϧ�޿ڸ������� \n",
        }) );

    setup();
    carry_object(__DIR__"obj/cloth3")->wear();
    carry_object(__DIR__"obj/jian3")->wield();
}

void init()
{
    ::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

string ask_for_bi()
{       
        return "���ϵ���ʼ����ܣ��ɲ����������˵��\n";
}


int accept_object( object me, object obj)
{
        if ( ( obj->query("id")!="putao jiu" ) )
        {
                command("say ��л���⣬�����ⶫ�����Һ���û��ʲô�á�");
                return 0;
        }
        if ( obj->query("id")=="putao jiu" )
        {
                message_vision("$N��ϲ����˵�������ҵģ�̫������!\n"
                               "�Ҹ�����һ�����ܣ������߱��ˡ�\n"
              YEL "�Ҵ��Ŀ����ʵ�Ԫ껺ʹ���û����˽�ᣬ��û���ϳ��ң���\n"
               "���������̳л�λ��û����Ϊ��̫��Ϊ�������ٸ����죬��\n"
               "�����£����������Ƴ�����������ڡ�\n"NOR,
                               this_object(), me);
            me->set_temp("dan_xingqing_first",1);
            
            return 1;

        }

}






