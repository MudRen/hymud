 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����ʯ�ң���һ�����������ȡ�����Ķ����ϻ���������ϸ��ȥ��
������ò������ɴŮ�ӻ������֣��������衣����ʯ�ĵ��浹ӳ����Ӱ��
�˴������˶��������ᡣΨһ��ֵ��ǣ�ż�������м�ֻ�����ҡ��
�ڵش���ߴ������������ˡ�
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"smallroom1",
                "west" : __DIR__"smallroom2",
                "north" : __DIR__"mouseroom3",
                "southwest" : __DIR__"mouseroom1",
                ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
} 
