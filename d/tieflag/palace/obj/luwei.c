 inherit ITEM;
void create()
{
        set_name("«έ", ({ "luwei", "«έ" }) );
        set_weight(10);
        set("no_show", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���пյ�«έ��\n");
        }
} 
