// Room: /open/stst/sazai/lianwu.c

inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
        ������Ұ��կ�����䳡������ʮ�ֿ����������������ľ׮����
�Ѿ�����������ˣ�ƽʱ���£�կ����ֵ��Ǿ��ڴ����䣬����Ժ�������
���д衣���䳡�ı����ǵ�������·���ϱ��ǳ�կ��·��

LONG

        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"lu2",
  "north" : __DIR__"lu3",
]));
	set("objects",([
		__DIR__"npc/toumu1":1,
		__DIR__"npc/toumu2":1,
]));

        setup();
        replace_program(ROOM);
}

