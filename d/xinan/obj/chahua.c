// chahua.c

inherit ITEM;

string *flower_name = ({
    "��ʮ��ѧʿ��",
    "���������ѡ�",
    "������������",
    "������ץ������",
    "�����ۡ�",
    "������ߡ�",
});



void create()
{
	set_name(flower_name[random(sizeof(flower_name))], ({ "cha hua", "flower" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������ġ�ʮ��ѧʿ����\n");
		set("unit", "��");
		set("value", 2000);
        set("cant_sell","������ε�Ц��Ц����С�Ĳ����������������⼸�����ӣ��͹ټ�Ц�ˡ�����\n");
		set("material", "plant");
	}
	setup();
}

