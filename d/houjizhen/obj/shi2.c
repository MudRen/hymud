// shi2.c
// By dicky

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIC"��"HIM"��"YEL"ʯ"NOR, ({"e luanshi", "e", "luanshi", "stone"}));
        set_weight(10000);
        if (clonep())
               set_default_object(__FILE__);
        else {
               set("long", "����һ��ɫ�ʰ�쵵Ķ���ʯ��\n");
               set("unit", "��");
        }
        setup();
}
