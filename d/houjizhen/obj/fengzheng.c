// fengzheng.c
// By dicky

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW"�����"NOR, ({"da fengzheng"}));
        set_weight(4000);
        if (clonep())
               set_default_object(__FILE__);
        else {
               set("long", "����һ���ǳ��������ݣ��������������еġ�\n");
               set("unit", "��");
        }
        setup();
}
