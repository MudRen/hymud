
inherit ROOM;

void create()
{
        set("short", "�ճ�԰");
        set("long", @LONG
���ţ�ֻ��������䣬����Ͳ�����������������������
ϸ�������������Ϳ�Σ�һɫˮĥȺǽ����ʯ̨�ף������
��������������ѩ�׷�ǽ�����滢Ƥʯ��������
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"palace_front",
  "westdown" : __DIR__"palace_path4",
]));
        set("outdoors","xueting");

        setup();
        replace_program(ROOM);
}

