
// Room: /d/snow/tao.c

inherit ROOM;

void create()
{
        set("short", "����ׯ");
        set("long",
"����һ�����Ժ�������������ò��Ů��������ѧϰ�Ÿ��պ��赸��һλ��Ů���Ů������\n"
"�ڽ������������������赸����������̲�סҲ��ȥ������һ����������\n"
);
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"crossroad",
]));

        set("valid_startroom", 1);
        setup();
        replace_program(ROOM);
}
