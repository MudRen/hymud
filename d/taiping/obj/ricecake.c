 inherit ITEM;
inherit F_FOOD; 
void create()
{
        set_name("����", ({ "rice" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��������Ĵ��ţ����������ϺƬ��\n");
                set("unit", "��");
                set("value", 15);
                set("food_remaining", 3);
                set("food_supply", 60);
        }
        
} 