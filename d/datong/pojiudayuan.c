// Room: /open/dt/pojiudayuan.c

inherit ROOM;

void create()
{
	set("short", "�ƾɴ�Ժ");
	set("long", @LONG
Ժ������������ϥ�ߵ��Ӳݣ��紵�����Ƶ����÷��������ء�
����������������ֻʣ�����ˣ�һ��һ�εķ������������������
�ƺ��и��������ű������������ţ��ڶ������������������˫
�۾��������㿴���㲻�����˸����£����ǸϽ��뿪��ط��ɡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"huayanlu5",
]));

	setup();
	replace_program(ROOM);
}
