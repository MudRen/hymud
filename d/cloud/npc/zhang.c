
// mei_po.c
#include <ansi.h>

inherit NPC;

string marry();
string unmarry();

void create()
{
        set_name("�Ű���", ({ "zhang" }) );
        set("title", "����");
        set("gender", "����" );
        set("age", 43);
        set("long",
                "һλ�����ܸɵĴ����\n");
        set("combat_exp", 300000);
        set("attitude", "friendly");
        set("inquiry", ([
                "��Լ" : "�ǰ�... ����Ϳ��Ե޽�ͽ����Լ",
        ]) );
set("per",30);
set("age",19);
   set("qi",2800);
   set("max_qi",2800);
set("food",250);
set("water",250);
   set("neili",5000);
   set("max_neili",5000);
   set("force_factor",30);

        
        set_skill("literate", 70);
        set_skill("dodge", 300);
        set_skill("unarmed", 200);
        setup();
        add_money("silver", 1);
}

