//guan1.c.文思院官员
//date:1997.8.27
//by dan      

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;    

string ask_for_bi();

void create()
{
    set_name(RED"官员"NOR, ({ "guanyuan" }) );
    set("title","大夏文思院");
    set("gender", "男性" );
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
                "承天璧" : (: ask_for_bi :),            
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
"我生性爱喝几杯，据说有一种葡萄酒很好，可惜无口福啊！！ \n",
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
        return "这关系到皇家秘密，可不可以随便乱说。\n";
}


int accept_object( object me, object obj)
{
        if ( ( obj->query("id")!="putao jiu" ) )
        {
                command("say 多谢美意，不过这东西对我好象没有什么用。");
                return 0;
        }
        if ( obj->query("id")=="putao jiu" )
        {
                message_vision("$N幸喜若狂，说：“给我的？太高兴了!\n"
                               "我告诉你一个秘密，你别告诉别人。\n"
              YEL "我大夏开国皇帝元昊和大臣妻没藏氏私会，后没藏氏出家，等\n"
               "其子谅柞继承皇位，没藏氏为皇太后，为祈其子寿福齐天，建\n"
               "承天寺，并用美玉制承天璧置于寺内。\n"NOR,
                               this_object(), me);
            me->set_temp("dan_xingqing_first",1);
            
            return 1;

        }

}






