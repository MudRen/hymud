#include <ansi.h>
inherit ITEM; 
void apply(string confirm, object me);
void create()
{
    set_name(HIW "�����" NOR,({"taoqing-wine"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "wood");
                set("long", "�����黨����������ơ�������ţ���ȴ���ˡ�\n");
                }
} 
void init()
{
        if(this_player()==environment())
        add_action("do_drink","drink");
} 
int do_drink(string arg)
{
        object me, obj;
        me = this_player();
        if (!arg)
                return notify_fail("��Ҫ��ʲô��\n");
		if (arg != "taoqing-wine")
                return notify_fail("��Ҫ��ʲô��\n");
        if (query("used")) 
                return notify_fail(this_object()->name()+"�Ѿ����ȹ��ˡ�\n");     
		if (!me->query("marry"))
				return notify_fail("�㲢û�л�Լ�����´˾ƶ���û�����塣\n");
        write(HIR"\n���´˾�֮�˽��밮����ͬİ·�����Ƿ�ͬ�⣿(yes/no)\n"NOR);
        input_to( (: apply :), me);
        return 1;
}

void apply(string confirm, object me)
{
        if (! (confirm == "yes" || confirm == "YES")) 
                write("�����һ���亹�����գ�\n");
        else    {
		message_vision(HIW"$Nһ�����������������һ������......\n"NOR,me);
        write(WHT"\n��ͻȻ���þ������¶����Ρ����̡��糾������ȥ�ˡ���\n\n"NOR);
        set("used",1);
        me->delete("marry");
        me->add("divorced",1);
        }
}

