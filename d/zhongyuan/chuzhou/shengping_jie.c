// ������ƽ�� /d/city/chuzhou/shengping_jie.c
// by lala, 1997-12-04

inherit ROOM;

void create()
{
    set("short", "��ƽ��");
    set("long", @LONG
��ƽ�����Ǹ�������ƽ�ĵط���·���ǳ������ļ�ԺŪ�񷻣���ʱ�д��
���ˡ��������ӽ������Ӱ��ڵĺ����������ɳ�һ���󻶸�Ц���֪�ж���
���ڴ�����������Ѱ�����֡��߸ߵ�Χǽ���棬һ֦�����޵��ӻ�ӭ����չ��
    �ֵ������ǳ�������̾��������У��ֵ�������ǳ����ŵ��ﻪ���ˡ�
LONG
    );
    set("outdoors", "yangzhou");
    set("no_kill",  "yangzhou");
    set("exits", ([
//        "east"      : __DIR__"nongyu_fang",
        "south"     : __DIR__"wuhua_jie",
        "northwest" : __DIR__"nanshi",
    ]));
    set("objects", ([
    ]));
    setup();
}
