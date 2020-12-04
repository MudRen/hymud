//dianzhu.c.����
//date:1997.8.27                            
//by dan   

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
 
string ask_for_jiu();    

void create()
{
    set_name(MAG"����"NOR, ({ "dianzhu" }) );
    set("title","�̺�");
    set("gender", "����" );
    set("combat_exp", 100000);
    set("max_qi", 400);
    set("max_sen", 300);

    set_skill("dodge",900);
    set_skill("sword",900);
    set_skill("unarmed",900);
    set("attitude", "friendly");
    set("env/attack", 78); 
	set("vendor_goods", ({
__DIR__"obj/maozhan",
	}));
  

    set("inquiry", ([
                "���Ѿ�" : (: ask_for_jiu :),   
    ]) );    

    set("talk_limit/combat_exp",10000); 
    set_temp("talk_npc_number", 10);
    set("talk_player_number/xingqing_dianzhu",3);
    set("talk_mark/xingqing_first",3); 
    set("talk_msg",({
"���Ｘ��ǰ����������������Ӷ��ջ��ˣ������⼸���ؽ��ġ�\n",
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

string ask_for_jiu()
{       
        return "������Ҳֻ�м�ƿ��,�Ҳ�����������̫��������.\n";
}

int accept_object( object me, object obj)
{
        if ( ( obj->query("id")!="tai a jian" ) )
        {
                command("say ��л���⣬�����ⶫ�����Һ���û��ʲô�á�");
                return 0;
        }
        if ( obj->query("id")=="tai a jian" )
        {
                obj = new(__DIR__"obj/jiu1");
                obj -> move( me );
                message_vision("������$Nһƿ���Ѿơ�\n", me);
                return 1;
        }

}






