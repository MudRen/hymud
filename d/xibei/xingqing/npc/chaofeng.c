#include <ansi.h>
inherit NPC;  

void create()
{
    set_name(MAG"����"NOR, ({ "chao feng", "feng" }));
    set("age", 59);
    set("gender", "����");
    set("long", "һ������, �������ܾ�����\n");
    set("combat_exp", 80000);
    setup();                                     
    carry_object(__DIR__"obj/cloth3")->wear();
} 

void init()
{
    object ob;
    ::init();
    if( interactive(ob = this_player()) && !this_object()->can_act() ) 
    {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
} 

void greeting(object ob)
{

    if( !ob || environment(ob) != environment() ) return;
    message_vision("����ӭ���������뻻Ǯ���ǵ��\n",ob);
}

