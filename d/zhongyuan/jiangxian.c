// jiangxian.c
inherit ROOM;

void create()
{   
    set("short","���");
    set("long",@LONG
�������ַ������������պհ˰���������¡������󣬳��������ĵܷܵ���
��һ���ط����ųơ����������������������������������ｨ����վ��������
���ۿ�ȥ�������������������������˼ң����ݲ�ԫ��ȴ���ﻹ��ʲô�ǳصĺ�
����
LONG );
    set("exits",([
        "south" : __DIR__"xiaxian",
        "north" : __DIR__"xinjiang"  ]) );
    set("outdoors","zhongyuan");
    setup();
}
