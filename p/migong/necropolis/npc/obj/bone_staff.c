 // staff.c
#include <weapon.h>
inherit STAFF; 
void create() {
        set_name("����", ({ "bone staff" }) );
        set_weight(2000);
        set("maze_item",1); 
        set("no_put",1);
        if(clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����֪��ʲô�Ĺ�ͷ���ɵķ��ȡ�");
                set("value", 300);
                set("material", "wood");
                set("wield_msg", "$N��$n�������������С�\n");
                set("unwield_msg", "$N�ɿ������е�$n��\n");
        }
        ::init_staff(30);
}
