#include <weapon.h>

inherit ITEM;

void create()
{
        set_name("Ǭ����", ({"qiankun gong", "qiankungong", "bow", "gong", "qiankun"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "Ǭ�������ǳ��ƹ��ܱ�������֮����������ύ\n��׿ͱ��ɶ����뾩�ǣ�Ҳ��������ˡ�\n");
                set("unit", "��");
		set("value", 3000);
                set("wield_msg", "$Nץ��һ��$n���������е�������\n");
                set("material", "steel");
                set("anqi/allow", 1);
                set("anqi/max", 9);
                set("anqi/now", 0);
        }

//init_bow(1);
        setup();

}
