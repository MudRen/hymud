#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIM"����֮��"NOR, ({ "xing" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "stone");
            set("value", 2000);
            set("long", "һö״����ѡ���ֵ���ǵı�ʯ��Ϊ���������֮�\n");
            set("no_sell",1);
            set("thief_obj",1);
          }
        
}     
