 inherit ITEM;
void create()
{
        set_name("���˶�" , ({ "niren" , "toy"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���������ɵĲ�ɫ���˶�\n");
                set("value", 1000);
        }
        setup();
}      
