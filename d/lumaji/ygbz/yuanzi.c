inherit ROOM;

void create()
{
        set("short", "����԰");
        set("long", @LONG
�����Ǹ�������������԰,�ֶ��·�����ס������,
����԰���п�ˮ��!�����е�Ź�!

LONG    );

        set("exits", ([
               "north" : "/d/lumaji/pomiao",
                          ]));

        setup();
        replace_program(ROOM);
}

