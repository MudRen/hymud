#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( "����", ({ "boat" }) );
    set("unit", "ֻ");
    set("value",0);
    set("no_get",1);
    set("long","���Ƶ����Ϻ�ó���������̴��������˻���ȻҲ���Ժ�����sail��\n");
    set_weight(150000);
    
} 
void init()
{
    add_action("do_sail","sail");
} 
int do_sail(string arg)
{
    message_vision(HIY"$N���ڻ���������ʻȥ������\n\n\n\n\n"NOR,this_player());
    tell_object(this_player(),HIY"���˺ܾã����ڵ��˰��ߡ�\n\n\n\n\n"NOR);
    this_player()->move("/d/baiyun/beach1");
//  destruct(this_object());
    return 1;
}      
