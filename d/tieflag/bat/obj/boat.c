#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( "����", ({ "boat" }) );
    set("unit", "��");
    set("value",0);
    set("no_get",1);
    set("long","һֻ���ɵķ�������������������sail��\n");
    set_weight(150000);
    
} 
void init()
{
    add_action("do_sail","sail");
} 
int do_sail(string arg)
{
    message_vision(HIY"$N���ڷ���������Ưȥ������\n"NOR,this_player());
    tell_object(this_player(),HIY"���˺ܾã����ڵ��˰��ߡ�\n"NOR);
    this_player()->move("/d/tieflag/bat/fchuan");
//  destruct(this_object());
    return 1;
}      
