// Room: /open/stst/sazai/qianting.c

inherit ROOM;

void create()
{
        set("short", "ǰ��");
        set("long", @LONG
        �������Ұ��կ��ǰ���ˣ�ǰ��װ�޵ļ򵥶����أ�һ��Ŀ��˶�
����ǰ���д���ǰ���Ķ������ʷ���������ɽկ����Ϣ�ң������Ǵ�������
�������䳡��

LONG

        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"lu3",
  "west" : __DIR__"lu4",
  "north" : __DIR__"lu6",
  "east" : __DIR__"lu5",
]));
	set("objects",([
		__DIR__"npc/datoumu":1,
]));

        setup();
        replace_program(ROOM);
}

