// xuantian.c �����챦����

#include <ansi.h>
#include <weapon.h>

inherit ITEM;

void init();
int do_read(string arg);

void create()
{
        set_name(HIR"�����챦����"NOR, ({"xuantian baojian","book","shu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	set("long","һ����װ�úܾ������飬����û��һ�����֣�����������\n");
        set("material", "paper");
        set("value", 100);   
	set("no_sell",1);
        }
}

