 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("ϲ��", ({ "wedding lady" }) );
        set("gender", "Ů��" );
        set("age", 50 );
        set("long",
"һ������ɫ��������ϲ���æµ����ͣ��\n");
        set("combat_exp", 300);
        set("attitude", "friendly");
        set("per",10);
        set("chat_chance", 2);
        set("chat_msg", ({
                "ϲ��С������ظ��׷ɷɾ��Ĵ���š���\n",
        }) );
        set_skill("unarmed",20);
        set_skill("dodge",100);
        setup();
        carry_object(__DIR__"obj/jifu")->wear();
}  
