inherit ITEM;

void create()
{
        set_name("����Կ��", ({ "yao shi", "shi" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��С��Կ�ס�\n");
                set("value", 100);
        }
}

