// Room: /d/snow/lane1.c
inherit ROOM;
void create()
{
        set("short", "Ƨ��С��");
        set("long", @LONG
��������Ƨ��С���ת�Ǵ���С����������ͨ��Ϫ�ߣ�������
�Ϳ�������Ϫ��������������������һ���ƾɵĴ�լԺ���ſڵ�һ
������д�������ֺ�������������Ѿ��Ƕ�ԫ����ˣ�С���ϱ�
��һ��С������
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
                "east" : __DIR__"ruin1",
                "west" : __DIR__"epath",
                "north" : __DIR__"lane2",
]));
//        set("objects", ([ /* sizeof() == 1 */
//                "/d/daomeng/npc/daotong" : 1,
//                "/d/daomeng/npc/daoke" : 1,
//        ]));
        set("outdoors", "xueting");
        setup();
        replace_program(ROOM);
}
