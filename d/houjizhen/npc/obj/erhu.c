// erhu.c
// by dicky

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("����", ({"er hu","erhu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѱȽϿ���������������������������(play)����\n");
                set("value", 100);
        }
        setup();
}

void init()
{
        add_action("do_play", "play");
}

int do_play(string arg)
{
        if (!id(arg))
                return notify_fail("��Ҫ����ʲô��\n");
        switch( random(3) ) {
                case 0:
                        message_vision(CYN"$N�������������س�����\n"NOR
CYN"����ңԶ�ĵط�����λ�ù��ÿ�������߹�����ձ������Ҫ����\n"NOR
CYN"�����������\n"NOR, this_player());
                        break;
                case 1:
                        message_vision(CYN"$N������������ֵس�����\n"NOR
CYN"���˲�Ҫ�޸����ˣ�һ��Ҫ�޸��ң�����������ã�������ļ�ױ��\nһ�𵽴��������\n"NOR, this_player());
                        break;
                case 2:
                        message_vision(CYN"$N������������˵س�����\n"NOR
CYN"��ҵĺ��ӣ���������ߣ�û���Ǻ����ѣ�Ҳû�к��̣��ò������ҷݹ�����\n���ڰѻ�ɣ�"NOR
CYN"����ͷ�����ᣬ�������ź���\n"NOR, this_player());
                        break;
        }
        return 1;
}

