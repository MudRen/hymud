//huoji.c.���
//date:1997.8.28
//by dan

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

string ask_for_room();

void create()
{
    set_name(MAG"���"NOR, ({ "huo ji"}) );
    set("title","̩����");
    set("gender", "����" );
    set("age",17);

    set("inquiry", ([
                "����" : (: ask_for_room :),            
    ]) );
	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
	__DIR__"obj/jinchuang_yao",
	}));


    set("talk_limit/combat_exp",10000);
    set_temp("talk_npc_number", 10);
    set("talk_player_number/xingqing_huoji",3); 
    set("talk_mark/xingqing_first",4);
    set("talk_msg",({
" ҩ�̺�����һƬ���档\n",
        }) );

    setup();       
}   
    
void init()
{
    ::init();        
	add_action("do_buy", "buy");
	add_action("do_list", "list");
} 

string ask_for_room()
{      
       object me;
       me = this_player(); 
       tell_object( me, "�������㷭�����ϴ��������滹�ҳ�һ������Ȧ�أ�\n");                                   
       tell_object( me, YEL"��ƴ��㴩��ҩ�̣�����һƬ�����ϡ�\n"NOR);                                                        
       me->move("/d/xibei/xingqing/feixu");    
       return "�������㷭�����ϴ��������滹�ҳ�һ������Ȧ�أ�\n";
}

