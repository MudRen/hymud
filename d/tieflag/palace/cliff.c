 inherit ROOM;
void create()
{
        set("short", "Σ��");
        set("long", @LONG
����·�������Ӳݾ��������ǡ����ܶ���һ�˶�ߵľ�������ֻ��𯹾
���ؽ������ھ����Ŀ�϶��������ȥ���������ܣ��㷢����վ��Σ��֮�ϡ�
���¿�����Լ�ɼ�һ̶��ˮ�����Թ⡣
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"keng",
]));
        set("objects", ([
        __DIR__"npc/yellowman" : 2,
                        ]) ); 
        set("outdoors", "palace"); 
        set("coor/x",220);
        set("coor/y",-30);
        set("coor/z",20);
        set("coor/x",220);
        set("coor/y",-30);
        set("coor/z",20);
        setup();
}