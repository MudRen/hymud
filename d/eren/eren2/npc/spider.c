#include <ansi.h>
inherit NPC;  
void create()
{
        set_name(HIY"�油"NOR,({"guardian"}));
        set("long", "һ�������С�ĺ����ˣ�����ȫ��һ����������Ľ����·�������ס��һ����Ҳ
������ڵ���ߣ�ֻʣ��һ˫�ڰ׷��������ӣ��ڵĵط����ᣬ�׵ĵط���ѩ��\n");
        set("age",25);
        set("combat_exp", 1000000);
        set("dungeon_npc","eren");
                
        set("max_mana", 800);
        set("mana", 800);
        set("max_neili",1000);
        set("neili",1000);
        set("force_factor",30);
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
        }) );

        set_name("��֩��",({"spiderman"}));
        set("force_factor",40);
        setup();
        carry_object(__DIR__"obj/darkcloth")->wear();
}        
