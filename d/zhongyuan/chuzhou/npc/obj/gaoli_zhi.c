// ����ֽ /d/city/chuzhou/npc/obj/gaoli_zhi.c
// by lala, 1997-12-13

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name( RED"����"WHT"ֽ"NOR, ({"gaoli zhi", "zhi", "corean paper", "paper" }));
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", @LONG
��˵����ֽ�����칤���Ǵ��й�����ȥ�ģ����Ǹ����˼��ԸĽ�������ĸ���ֽ
�����ǳ��ĺã��ִ����й������й���ʿ����Ƿǳ�ϲ������ֽ����������ֽ��
�۸�Ҳ�ǳ��İ���
LONG
    );
                set("unit", "��");
                set("value", 1000);
                set("material", "paper");
        }
        setup();
}
