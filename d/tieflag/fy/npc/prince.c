 // Tie @ fy3
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("С����", ({ "prince", "little prince"}) );
        set("gender", "����" );
        set("age", 12);
        set("long", "���ǵ�����ϵ�С���ӣ����ܳ谮��һ��\n");
        set("class","official");
        set("combat_exp", 1500000);
        set("attitude", "friendly");
        set_skill("dodge", 200);
        set_skill("leadership",101);
        set_skill("strategy",100);
        set("intellgent",1);
        set("chat_chance", 1);
        set("chat_msg", ({
                "С�����ſڵ�����"+HIR"��"NOR+"һ�������δ�����"+HIG"��"NOR+"��\n",
        }) );

        setup();
        add_money("silver", 1);
        carry_object(__DIR__"obj/fycloth")->wear();
}        
