#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name(HIY"��¶��ʯ"NOR, ({"topaz", "huangshi", "yellow stone" }));
    set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("unit", "��");
                        set("long", "�������֮Ӣ�۳ɵ���ˮʯ����������Ө������ȴ˿˿�����̷���
ϸϸ��ˮ������ʯ�棬�����پۡ�\n");
            set("value", 20000);
                        set("imbue", 1);
                        set("no_drop",1);
                        set("no_give",1);
                        set("no_sell",1);
        }

}  
