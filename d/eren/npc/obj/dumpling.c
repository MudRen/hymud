 inherit ITEM;
inherit F_FOOD; 
void create()
{
        set_name("ˮ������", ({ "dumpling" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��СС��Ŵ�װ��ӣ���֥������ӡ�\n");
                set("unit", "��");
                set("value", 2000);
                set("food_remaining", 3);
                set("food_supply", 300);
        }
        
}       
