// /d/map/zhongyuan/tulu.c

inherit ROOM;

void create()
{
    set("short", "��·");
    set("long", @LONG
һ������·���ѵ���Զ�������ţ�һ�ۿ�������ͷ��·�����߶���ˮ�����
�����������˵��������Ʈ������������ġ������硹������ˮ���ݺᣬ�Ӻ�
�ڶ࣬���������ҫ����ͬ��Ƕ�ڴ���ϵĶд������������������ε�������
��Ʈ�Ŷ����ƣ�Զ�����국������Ӱ���˰�������
LONG
       );
    set("exits", ([ 
        "west"      : __DIR__"chuzhou/dong_men",
        ///"east"      : "/d/place/xkdao/tantu1",
    ]));
    set("outdoors", "zhongyuan");
    setup();
}

