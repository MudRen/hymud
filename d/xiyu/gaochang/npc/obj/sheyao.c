/* sheyao.c ӡ����ҩ
 * from XO Lib
 * a obj of gaochang.
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

#include <ansi.h>

inherit ITEM;

void create()
{
    set_name( "ӡ����ҩ" , ({"she yao", "pill", "yao" }));
    set_weight(30);
    if (clonep())
        set_default_object(__FILE__);
    else
    {
        set("long", "����һöӡ�Ȳ�����ҩ��Ч���ر�á�\n");
        set("unit", "ö");
        set("value", 5000);
    }
}


void init()
{
    add_action("do_eat", "eat" );
}

int do_eat( string arg )
{
    object me;
    int condition;
    me = this_player();

    if( !me->can_act() ) return notify_fail("�������޷���ҩ��\n");

    if( arg != "she yao" && arg != "pill" && arg != "yao" )
        return 0;

    if( !condition = me->query_condition("snake_poison") )
    {
        write("��û�б���ҧ�ˣ�����ҩ��û�õġ�\n"); 
        return 1;
    }

    condition -= 10;
    message_vision("$N�ӻ����ͳ�һö��ҩ��������ȥ��\n", me);
    if ( condition <= 0 )
    {
        tell_object( me, CYN"��������ڵĶ��Ժ����Ѿ�������ס�ˡ�\n"NOR );
        me -> clear_condition( "snake_poison" );
    }
    else
    {
        tell_object( me,CYN"��������е��߶��������⡣\n"NOR );
        me -> apply_condition( "snake_poison",condition );
    }
    
    destruct( this_object() );
    return 1;
}


