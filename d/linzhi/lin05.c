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
  "eastup" : __DIR__"lin04",
  "west" : __DIR__"lin06",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
