 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
��ѨԽ������Խ��խ��������ʮ���ɺ��ѽ��������˵����˿���
��һͨ������֪��Ϊ˭���衣�����ѵ��ˣ���·���ˣ�Ψ�з���ǰ�С�
LONG
        );
        set("exits", ([ 
                "up" : __DIR__"tunnel2",
                "down" : __DIR__"mouseroom4",
        ]));
        set("objects", ([
                __DIR__"npc/rat" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}
