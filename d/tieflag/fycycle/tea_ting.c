 inherit ROOM;
void create()
{
        set("short", "��ͤ");
        set("long", @LONG
����һ����׵Ĳ�ͤ��ר�Ź�·��Ъ���á���ͤ������������ӣ���ֻ���ӡ�����
�Ľ�ʨ�ھֵ��ڳ���������������Ҫ��һ�����������˵��������ʦ�ȿ�ˮ����Ҳ
��Ϊ��ˣ�����Ҳ��ɽ���ٷ�����ϲ����˵ĵط���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "south" : __DIR__"road2",
]));
        set("objects", ([
        __DIR__"npc/xiaofan": 1,
                    ]));
        set("outdoors", "fengyun");
        set("coor/x",-100);
        set("coor/y",110);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
