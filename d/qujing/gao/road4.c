// gate.c

inherit ROOM;

void create()
{
  set ("short", "��·");
  set ("long", @LONG

��Χ��һƬ���һЩũ��������������ڸ��֣�����һЩ������
�������ˣ��Զ���Ĵ�����Լ�������������ģ�һ������̫ƽ�ľ�
��
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"daotian1",
"south" : __DIR__"daotian2",
"east" : __DIR__"road3",

]));

        set("outdoors", "xy5");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

