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
  "eastdown" : __DIR__"huanghe1",
  "west" : __DIR__"road",
]));
        set("outdoors", "shanxi");
        set("coor/x",-490);
        set("coor/y",-400);
        set("coor/z",100);
        setup();
}
