 // mei_po.c
#include <ansi.h> 
inherit NPC; 
string marry();
string unmarry(); 
void create()
{
    set_name("ý��", ({ "mei po" }) );
    set("title", "ԧ��ͤ");
    set("gender", "Ů��" );
    set("age", 43);
    set("long",
        "һλ�����ܸɵ���ý��\n");
    set("combat_exp", 10000);
    set("attitude", "friendly");
    set("inquiry", ([
        "��Լ" : "�ǰ�... ����Ϳ��Ե޽�ͽ����Լ",
        "marry" : "�ǰ�... ����Ϳ��Ե޽�ͽ����Լ",
     ]));
    set_skill("literate", 70);
    set_skill("dodge", 500);
    set_skill("unarmed", 300);
    setup();
    carry_object("/clone/misc/cloth")->wear(); 
//    add_money("gold", 1);
} 
