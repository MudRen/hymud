 inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("��ʯ", ({ "��ʯ" , "rock","stone"}) );
        set_weight(500);
        set_max_encumbrance(8000000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���龫�µĵ�¥�ݣ���ʯ���οչ⻬��\n");
                set("value", 1);
        }
        
} 
int is_container() { return 1; }      
