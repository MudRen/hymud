// shanlu4
// by dicky

inherit ROOM;

void create()
{
set("short", "ɽ·");
	set("long", @LONG
��������һƬ�����де�С�����ż������һ�����Ұ�޽�����ͷ��
��һЩ��֪����С����������ȥ�����ܴ����ܲ���Ұ���̲��������֣�����
ɽ���ﴵ����������磬������������������һЩ�����Ļ��㣬�����侳��
���ӡ��ľ�֮����Ȼ������
LONG
	);

        set("outdoors", "houjizhen");

	set("exits", ([ /* sizeof() == 1 */
        "southeast" : __DIR__"shanlu2",
        "northdown" : __DIR__"xiaoxi",
        "westup" : __DIR__"shanlu5",
	]));

	set("objects",([
		"/clone/npc/man" : 2,
	]));

	setup();
	replace_program(ROOM);
}


