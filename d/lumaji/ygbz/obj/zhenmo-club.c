// zhenmo-club.c     by yahoo 2002-3-17
#include <weapon.h>
inherit CLUB;
#include <ansi.h>

void create()
{
        set_name(HIY"��ħ��"NOR, ({ "zhenmo bang", "club", "bang" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIY"��˵���������������˼������,���˵�֮,����Ϊһ��ɱ��������\n"NOR);
                set("value", 0);
                set("material", "steel");
                set("wield_msg", HIY"$N�ӱ���γ�һ�������������ħ�������Ϊ֮ʧɫ��\n"NOR);
                set("unwield_msg", HIY"$N��������ħ�����±��ڱ���\n");
        }
      init_club(1600);
    set("no_give",1);
    set("no_get",1);
        setup();
}

