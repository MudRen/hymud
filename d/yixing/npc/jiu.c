// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
                 // wine.c ���׾�
#include <ansi.h>
inherit ITEM;
void init()
{
        add_action("do_drink", "drink");
        add_action("do_drink", "he");
}

void create()
{
        set_name(HIC "�����̻��" NOR, ({"xuanbingbihuo jiu", "jiu"}));

        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long", "����һ�����֮���������̻��, ��˵�ܽ�ٶ���\n");
                set("value", 120);
}
}


int do_drink(string arg)
{
        if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
        if(arg=="jiu")
        {
             this_player()->set_temp("nopoison", 1);
             this_player()->set("eff_jing",this_player()->query("max_jing"));
             this_player()->set("jing",this_player()->query("max_jing"));
             this_player()->set("eff_qi",this_player()->query("max_qi"));
             this_player()->set("qi",this_player()->query("max_qi"));
             tell_object(this_player(), HIG "��ֻ��һ�����������ķ�,��ʱ��̨һƬ����,������ˬ��\n" NOR );
             destruct(this_object());
        }
        return 1;
}
             