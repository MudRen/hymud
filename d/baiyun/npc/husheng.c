#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("����", ({ "husheng" }) );
        set("long","һ���ֳ���������������ͣ¶���п��Ц�ݡ�\n");
        set("attitude", "heroism");
        set("str", 10);
        set("per", 10);
        set("cps", 20); 
        set("combat_exp", 5000); 
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 100+random(100)); 
        set("chat_chance", 1);
        set("chat_msg", ({
        "����ͻȻ�����һЦ��\n",
        }) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
}      
