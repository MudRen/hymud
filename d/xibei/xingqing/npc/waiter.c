//waiter.c.店小二
//date:1997.8.28
//by dan

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

int ask_for_bi();


void create()
{
        set_name(MAG"店小二"NOR, ({ "waiter" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long",
                "这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
        set("combat_exp", 5);
        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");

	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
	}));

        set("inquiry", ([
                "承天璧" : (: ask_for_bi :),            
        ]) );
 
        set("talk_limit/combat_exp",10000);  
        set_temp("talk_npc_number", 10);
        set("talk_msg",({
" 据说几十年有一位大夏武士得到一把上古利刃，他后来就住在宣平坊。\n",
        }) );

        setup();
}

void init()
{       
        ::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

int accept_object( object me, object obj)
{
        if ( ( obj->query("id")!="silver"&& obj -> query("id")!= "bi" )|| userp(obj) )
        {
               return 0;
        }

        if ( obj->query("id")=="silver" )
        {
                tell_object( me, YEL"店小二带你进了一间客房。\n"NOR);                                                        
                me->move("/d/xibei/xingqing/sroom");   
                return 1;
        }

        if ( obj->query("id") == "bi" )
        {
                write(YEL"小二把璧一把抢过....\n"NOR);
                destruct( obj );
                return 1;
        }
}

int ask_for_bi()
{
     object me,ob;
     me = this_player();
     ob = this_object();
     if ( me -> query_temp("dan_xingqing_first") )
     {
        write("小二白了你一眼，道 你问这个干什么?\n");
        return 1;
     }
     new(__DIR__"obj/juan")->move(me);
     write("小二悄悄对你说: 你把璧给我我可以告诉你一个极大的秘密\n");
     return 1;
}

