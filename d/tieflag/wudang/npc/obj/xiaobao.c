 // dumpling.c
inherit ITEM;
inherit F_FOOD; 
void create()
{
        set_name("�pŢ�]", ({ "jibao" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@Ţ���Q�Q�B�����˪��p�]�l�C\n");
                set("unit", "Ţ");
                set("value", 90);
                set("food_remaining", 3);
                set("food_supply", 60);
        }
        setup();
}       
