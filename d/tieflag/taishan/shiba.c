 inherit ROOM;
void create()
{
        set("short", "ʮ����");
        set("long", @LONG
��ʯ�ף���������ֵıؾ�֮·����·��խ��ֱ�϶�ȥ���������񴹹�
���ˣ����µ����ӣ��ֺ�������̰���˼�������������Ϸˣ�Ľݾ���
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"nantian",
  "down" : __DIR__"duisong",
]));
        set("outdoors", "taishanfy");
        set("coor/x",320);
        set("coor/y",2390);
        set("coor/z",110);
        setup();
}
