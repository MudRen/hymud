//road20.c.���
//date:1997.8.26
//by dan

inherit ROOM;

void create()
{
    set("short","���");
    set("long",@LONG
�����ǻ����̳ɵ�·�棬����ɾ�����ʱ�����˴���߲������. ��Χ����
����, ֻ��һЩ��·����Ϣ������ʵ۳����Ӳ죬���ӳ����������ﾭ������
������Ƕ��Ǻ������ϵ�Ľ�ͨҪ����������Ҫ���̣�����ϸ����ΰ�������
���ӽ����������̵��̲飬�Է���ϸ�����룬ǧ����������ǡ�
LONG);
   
    set("exits",([
        "east"    : __DIR__"bingying5",
        "west"    : __DIR__"bingying6",
        "south"   : __DIR__"door2",
        "north"   : __DIR__"road6",
    ])); 
    set("objects", ([
          __DIR__"npc/bing2" : 2,
    ]) ); 
    set("outdoors","xingqing");
    setup();
}

