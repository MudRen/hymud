#include <weapon.h>
inherit SWORD;
#include <ansi.h>

void create()
{
        set_name(YEL"����ħ��"NOR, ({ "kaitian mojian", "mojian", "jian" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIY"�����Ϲ�ʱ������ʹ�õ�ħ��,��˵�̲��˾޴��ħ����\n"NOR);
               set("value", 0);
                set("material", "steel");
                set("wield_msg", HIW""BLK "$N���һ��ɢ������������ı�����ɲ�Ǽ䣬������Ҳֹͣ��������\n"NOR);
                set("unwield_msg", HIW""BLK "$N�������������У��������ڿ�ʼ�����ˡ�\n"NOR);
        }
        init_sword(1600);
    set("no_get",1);
    set("no_give",1);
        setup();
}

