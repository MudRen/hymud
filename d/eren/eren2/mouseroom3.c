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
                "east" : __DIR__"treasureroom1",
                "west" : __DIR__"treasureroom2",
                "north" : __DIR__"mouseroom4",
                "south" : __DIR__"mouseroom2",
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
