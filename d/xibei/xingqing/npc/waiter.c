//waiter.c.��С��
//date:1997.8.28
//by dan

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

int ask_for_bi();


void create()
{
        set_name(MAG"��С��"NOR, ({ "waiter" }) );
        set("gender", "����" );
        set("age", 22);
        set("long",
                "��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
        set("combat_exp", 5);
        set("attitude", "friendly");
        set("rank_info/respect", "С����");

	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
	}));

        set("inquiry", ([
                "�����" : (: ask_for_bi :),            
        ]) );
 
        set("talk_limit/combat_exp",10000);  
        set_temp("talk_npc_number", 10);
        set("talk_msg",({
" ��˵��ʮ����һλ������ʿ�õ�һ���Ϲ����У���������ס����ƽ����\n",
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
                tell_object( me, YEL"��С���������һ��ͷ���\n"NOR);                                                        
                me->move("/d/xibei/xingqing/sroom");   
                return 1;
        }

        if ( obj->query("id") == "bi" )
        {
                write(YEL"С�����һ������....\n"NOR);
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
        write("С��������һ�ۣ��� ���������ʲô?\n");
        return 1;
     }
     new(__DIR__"obj/juan")->move(me);
     write("С�����Ķ���˵: ���赸����ҿ��Ը�����һ�����������\n");
     return 1;
}

