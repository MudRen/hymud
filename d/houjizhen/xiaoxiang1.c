// xiaoxiang1.c
// by dicky

inherit ROOM;

void create()
{
        set("short", "С�ﾡͷ");
        set("long", @LONG
������С��ľ�ͷ��һֻ��ľ���ϰ��ż������ƵĶľߣ�����������
Щ����ͷ����������һ�ɼ��㡢����ͺ���������һ���ζ������������
�Ǵ��ڵ�Ʀ����å�ۼ��ĵط���
LONG
        );

        set("outdoors", "houjizhen");

        set("exits", ([ /* sizeof() == 1 */
 	 "southeast" : __DIR__"xiaoxiang",
]));

        set("objects", ([
                __DIR__"npc/liumang": 1,
		__DIR__"npc/dipi": 1, 
	]));

        setup();
        replace_program(ROOM);
}


