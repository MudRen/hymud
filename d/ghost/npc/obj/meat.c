 inherit F_FOOD;
inherit ITEM; 
void create()
{
        set_name("һ�����", ({ "meat", "��"}) );
        set_weight(400500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ����⡣\n");
                set("unit", "��");
                set("value", 30);
                set("food_remaining", 10);
                set("food_supply", 100);
        }
        
} 
int finish_eat()
{
        set_name("������", ({ "big pot" }) );
        set_weight(50);
        set("long", "һֻ��������\n");
        return 1;
}  
