inherit ITEM;
inherit F_FOOD;


void create()
{
        set_name("�ر�", ({"su bing","bing"}));
        set_weight(150);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��������ر���\n");
                set("unit", "��");
                set("value", 4);//�ܱ��ˣ�������ʳ�ﶼӦ�úܱ��ˣ�.
		set("food_remaining", 10);
		set("food_supply", 60);
        }
}
