// Room: /d/linzhi/lin05.c

inherit ROOM;

void create()
{
	set("short", "�һ�������");
	set("long", @LONG
���ߵ��һ������ڣ�������ȥ�ͽ����һ��������ﳤ������
Ȼ��Ұ��������ÿ�����ʱ���ܶ��˶��������ժ���ӡ���˵ζ
���ر�ĺá�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  //"eastup" : __DIR__"lin04",
  "west" : __DIR__"lin06/entry",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
