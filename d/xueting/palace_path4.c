
inherit ROOM;

void create()
{
        set("short", "�ƺ�����");
        set("long", @LONG
�ƣ������ڽ��£����ˣ�������ˮ����������һ������֮
�����ƺ���Ư�����ֲ�����ˮ�������Ǵ����ߡ����ߣ����ճ�֮�ߣ�
�����š��ճ�԰����
LONG
        );
        set("exits", ([ 
  "eastup" : __DIR__"palace_gate",
  "westdown" : __DIR__"palace_path3",
]));
        set("outdoors","xueting");

        setup();
        replace_program(ROOM);
}

