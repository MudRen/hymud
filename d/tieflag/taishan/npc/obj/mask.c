#include <ansi.h>
inherit EQUIP;
void create()
{
        set_name(BLK"�ƽ����"NOR, ({ "black mask","mask" }) );
        set_weight(1000);
        set("long","һ�����������ĺ�ɫ��ߣ�����������Զ��������֪������˭�����������ˡ�\n");
        set("unit", "��");
        set("value", 2000);
        set("material", "cloth");
        set("armor_type", "mask");
        set("fakegender", "����");
        set("armor_prop/id", ({"tiansun"}));
        set("armor_prop/name", ({"����"}));
        set("armor_prop/short", ({WHT"���� "NOR+HIY"����"NOR+"(tiansun)"}) );
}
