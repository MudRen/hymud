inherit ROOM;
void create()
{
        set("short", "�ٲ���");
        set("long", @long
�ƹ�С��������ɽ������ԶԶ�����Ǻ����ٲ���ɽ�������ٲ��ߣ�·���ƺӣ�
ָ�����еĴ�ׯ���˵�������ɽ���ӵ�ʯ���ϳ�ˢ��һ�޹���������ˮ�������ˣ�
������ע��������ֱ��ӹ������˷���������ŭ������������š�������޺���
�ڣ������������ٲ�����
long
        );
        
        set("exits", ([ 
  "north" :__DIR__"shulin",
  "east" : __DIR__"road1",
//  "southwest" : "/d/chenxiang/road",
]));
        set("outdoors", "shanxi");
                set("no_magic",1);
        set("NONPC",1);

        set("coor/x",-500);
        set("coor/y",-400);
        set("coor/z",100);
        setup();
}

