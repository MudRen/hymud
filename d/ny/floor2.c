
inherit ROOM;


void create()
{
		set("coor",({-25,-50,5}));
	set("short", "������ݶ�¥");
		set("long",
"�����Ǵ�����ݶ�¥��������������ŵ�һ��Ũ����̴�㣬¥�µĳ���ͨ������,�������\n"
"�����ͷ��Ƴǵ�ȫ����\n"
);
		set("exits", ([ /* sizeof() == 1 */
                "down" : __DIR__"innerhall",
		]));

		set("item_desc", ([
				"bell": "����Ŷ��\n"
		]) );


		setup();
		set("no_clean_up", 0);

}

