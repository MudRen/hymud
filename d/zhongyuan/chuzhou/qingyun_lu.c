// ��������· /d/city/chuzhou/qingyun_lu.c
// by lala, 1997-12-03

inherit ROOM;

void create()
{
    set("short", "����·");
    set("long", @LONG
����·�ǳ��ݳǶ�����һ����̫��ĵ�·������˼����ȡƽ�����ƵĿڲɣ�
����˵�ڳǱ��ϵĵ�·Ӧ�����˼�������Ȼ������ȴ����������������������ʮ
�ֵ����֡�ԭ��������·���Ǻպ����������幬����˵����ĵ�ʿ������׼����
���﹩��������༫�����飬���������ǧ�����������������������㣬���ʼ�
�����ӡ�������������Ϊ��ʢ�����еĵ�ʿҲ������⡣��·��������һ
�Ҿ���꣬���С��������ݡ����в���������ʿ����������
LONG
    );
    set("outdoors", "yangzhou");
    set("no_kill",  "yangzhou");
    set("exits", ([
        "east"      : __DIR__"shangqinggong",
        "northwest" : __DIR__"qiruishuwu",
        "southwest" : __DIR__"beishi",
    ]));
    set("objects", ([
        __DIR__"npc/jinxiangke" :   2 + random(3),
    ]));
    setup();
}
        