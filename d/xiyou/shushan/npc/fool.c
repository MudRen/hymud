//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "fool" }));
        set("title", "˼��������");
        set("age", 50);
        set("attitude", "peaceful");
        set("int", 1);
        set("per", 10);
        
        set("max_qi", 2000);
        set("max_jing", 2000);
        set("chat_chance", 20);
        set("chat_msg", ({
                "�����૵����������˼����꣬�����Ҹ���̤���ҽŻ�����̤������أ����ܻش�(answer)���𣿡�\n",
        }));
   add_temp("apply/damage", 20);
   add_temp("apply/armor", 20);
        setup();
}

