// �������˽� /d/city/chuzhou/yanxing_jie.c
// by lala, 1997-12-04

inherit ROOM;

void create()
{
    set("short", "���˽�");
    set("long", @LONG
���˽ֲ��������ֵ�����ô���֣������ĵģ�����û����������ż������ͨ
��Ҳ�Ǽ���ææ��������ͣ����ԭ���ݸ����ž����������ϣ���Ҷ���Ը������
������Ĺ���������������������ͺ��������߶��ˡ��������ﻹ��������ʤ��
���ġ���·�ϵ������Ǻ�κ������
LONG
    );
    set("outdoors", "yangzhou");
    set("no_kill",  "yangzhou");
    set("exits", ([
//        "north"     : __DIR__"yamen",
        "east"      : __DIR__"dong_men",
        "south"     : __DIR__"hanxin_ci",
        "west"      : __DIR__"dongshi",
    ]));
    set("objects", ([
    ]));
    setup();
}
