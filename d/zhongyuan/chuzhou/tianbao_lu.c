// �����챦· /d/city/chuzhou/tianbao_lu.c
// by lala, 1997-12-03

inherit ROOM;

void create()
{
    set("short", "�챦·");
    set("long", @LONG
�챦·�ǳ��ݱ����ڵ�һ����֣��򱱿��Գ��ǣ������ǳ�����������ʤ��
������ͨ������������Զ��������������ÿ�궼�в�����ǰ���۹⡣���������
�˶������ˣ����Ƕ���ʤ������Ȥ�����Ǹ���Ȥ�����챦·���ı��У������Ǳ�
�������ֵ��ĸ��г�֮һ����Χ�кܶ���̡�
LONG
    );
    set("outdoors", "yangzhou");
    set("no_kill",  "yangzhou");
    set("exits", ([
        "north"     : __DIR__"bei_men",
        "east"      : __DIR__"beishi",
        "northwest" : __DIR__"wentongta",
    ]));
    set("objects", ([
    ]));
    setup();
}
