#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name(HIW"���Ứ"NOR, ({"flower", "puti hua"}) );
        set_weight(20);
        if( clonep() )
          set_default_object(__FILE__);
        else {
            set("unit", "��");
            set("long", "��Ƭ��ɫ�Ļ�������Ž�׵Ļ����Ե���ô�������ˣ����������������͸����\n");
            set("value", 200);
        }
        setup();
}          
