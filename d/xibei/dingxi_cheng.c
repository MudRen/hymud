inherit ROOM;
void create()
{
    set("short","��������");
    set("long",@LONG
����������פ��������پ����Ǹ�ǽ����һ�������ľ���Ҫ�����Դ�����
�˳ǣ����ģ���ެ���Ӻ����ٸ�����䬣�ẵ������ӡ��Զ�����Ϊ���أ��򱱰�
����鲼��կ���໥��Ӧ��������һ�����������һֱͨ�����ݸ������ߵĵ�·
�𽥱�խ�����߶���ũ�
LONG);
    set("exits",([
        "east"   : __DIR__"yidao9",
        "north"  : __DIR__"tuntian1",
    ]));
        set("objects", ([
                __DIR__"npc/keshang" : 2,
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
                ]) );
 set("outdoors","xibei");
    setup();
}

