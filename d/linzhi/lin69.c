// Room: /d/linzhi/lin69.c

inherit ROOM;

void create()
{
	set("short", "��ԭ�ӵ�");
	set("long", @LONG
���ߵ��һ������ڣ�����ȥ�ͽ����һ��������ﳤ������
Ȼ��Ұ��������ÿ�����ʱ���ܶ��˶��������ժ���ӡ���˵ζ
���ر�ĺá�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lin48",

]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
