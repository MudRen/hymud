inherit ROOM;
void create()
{
    set("short","���ݸ�");
    set("long",@LONG
������������������Ϊ����֮�أ��˿ڳ��ܣ�ũ��һƬ����һƬ�����ǿ���
μˮ���ࡣ�ٸ������񹤴�����ֱ�����ݣ��غ�������������˺�ˮ����������
�Ļĵر�������
    ����Ⱥɽ���֣��򱱵��ƽ��ߣ������м��ż�����ɽ��
LONG);
    set("exits",([
        "east"   : __DIR__"yidao2",
        "west"  : __DIR__"yidao3",
        "northeast"  : __DIR__"shanlu1",
    ]));
        set("objects", ([
                 __DIR__"npc/keshang" : 1,
                ]) );
set("outdoors","xibei");
    setup();
} 

