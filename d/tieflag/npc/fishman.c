#include <ansi.h>
inherit NPC;  
void create()
{
        set_name("���", ({ "fishman" }) );
        set("gender", "����");
        set("age", 52);
                set("long",
                "����һ��������˪�������\n");
                set("combat_exp", 5);
                set("attitude", "friendly");
        setup();
        carry_object("/clone/misc/cloth")->wear();
}       
