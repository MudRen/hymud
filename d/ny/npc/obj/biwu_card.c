
// card4.c

inherit ITEM;

void create()
{
    set_name("��������", ({"biwu card","card"}));
           if( clonep() )
                set_default_object(__FILE__);
        else {
	set("long",
     "����������񰢲�������ǩ���ı�������,ֻ��ӵ��������ſ������ɳ������µ�һ�㳡\n");
	set("unit", "��");
	set("weight", 10);
set("no_get",1);
set("no_drop",1);
}
}

