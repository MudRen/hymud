// Room: /d/linzhi/linzhiw.c

inherit ROOM;

void create()
{
	set("short", "��֥����������Ե");
	set("long", @LONG
��������֥���������ߣ��ش���³�ز������α������ɴ���
�򶫾ͽ�����֥�����ˡ�·������һ�����ӡ�
LONG
	);
	set("item_desc",([
          "����":"
                  east         ��һ��
                  northwest    ���� \n", ]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lin68",
//  "southwest" : "/d/path6/qjl01",
  "northwest" : "/d/qingzh/xroad",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3600);
	setup();
	replace_program(ROOM);
}
