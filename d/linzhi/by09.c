// Room: /d/linzhi/by09.c

inherit ROOM;

void create()
{
	set("short", "��С·");
	set("long", @LONG
�������򱱵�һ��С·��·��ӿ����ݣ���̫���ߡ���һ��
С�ģ��ŲȽ���һ��ˮ�ݣ��㼱æ�ѽ����˻�����С��������һ
�䡣ǰ����һ��ɽ�ȡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"by08",
  "north" : __DIR__"by10",
]));
        set("outdoors", "linzhi");
//        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
