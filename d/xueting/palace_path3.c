
inherit ROOM;

void create()
{
        set("short", "��ã����·");
        set("long", @LONG
ɽ�������･�����ߣ���Χ�ľ�����Ũ�����������֡�Ũ����
��ˮ��������͸��������ѣ����������������ܡ��⡭��������
��ͨ�����õ�·������ͨ������֮�ţ�
LONG
        );
        set("exits", ([ 
  "eastup" : __DIR__"palace_path4",
  "westdown" : __DIR__"palace_path2",
]));
        set("outdoors","xueting");

        setup();
        replace_program(ROOM);
}

