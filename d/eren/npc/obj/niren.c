 inherit ITEM;
void create()
{
        set_name("С����" , ({ "small toy" , "toy"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��������ɵ�С�ˡ�\n");
                set("value", 1000);
        }
        
}       
