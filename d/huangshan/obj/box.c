#include <ansi.h>
inherit ITEM; 
void create()
{
    set_name("��ʯ��", ({ "box", "stone box"}) );
    set_weight(800);
    set_max_encumbrance(500);
    if (clonep())
        set_default_object(__FILE__);
    else {
                set("unit", "��");
                set("long", "һ������ɫ��Сʯ�С���������Ű�����(open)\n");
                set("value", 20);
        set("prep", "in");
        set("value", 500);
    }
        
} 
int is_container() {return 1;} 
void init()
{
   add_action("do_open","open");
} 
int do_open(string arg)
{
        object me, ob, item;
        
        me = this_player();
        ob = this_object();
    if( !arg || arg != "box" ) {
        return notify_fail("��Ҫ��ʲô��\n");
    }
    if(ob->query_temp("marks/opened")) {
        return notify_fail("ʯ���Ѿ����򿪹��ˡ�\n");
        }
        if(!me->query("����B/��Դ_����") || me->query("stone_mark/gstone")) {
                message_vision("$N���Ŵ�Сʯ�У�С������һ������ʯͷ��˿������\n", me);
                return 1;
        }       
        message_vision("$N������$n�򿪣�����\n", me, ob);
    set("long", "һ����ɫ��Сʯ�У��и��Ѿ������ˡ�\n");
    item = new("/obj/specials/stone/gstone");
        if (objectp(item)){
                message_vision("һ�龧Ө��͸���������$N���С�\n", me);
        item->move(me);
        me->set("stone_mark/gstone", 1);
        me->add("combat_exp", 200);
        ob->set("value", 0);
    }
        ob->set_temp("marks/opened",1);
    return 1;
}       
