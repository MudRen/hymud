// /d/ygbz/obj/suixin-whip.c
// by yahoo 18:35 99-3-22#include <weapon.h>
#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
        set_name( HIR "���ı�" NOR, ({ "suixin bian", "bian" }) );
        set_weight(10000);
                set("flag",2);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������ͱ���˿�Ƴɵĳ��ޣ��޵�ĩ�Ҳ�����������ݡ�\n");
                set("material", "leather");
                  set("wield_msg", HIR "��Ȼ�Ĵ�����һ����Խ��������һ����ɫ������ƿն�������$N������,����һ�����ޡ�\n" NOR);
                set("unwield_msg", HIR "һ��������������ʧ��$N���е����ı޺�Ȼ�����ˡ�\n" NOR);
        }
    set("no_get",1);
    set("no_give",1);
    set("no_drop",1);
               set("value",10000);
    set("rigidity",1000);
    init_whip(1600);
    setup();
}

